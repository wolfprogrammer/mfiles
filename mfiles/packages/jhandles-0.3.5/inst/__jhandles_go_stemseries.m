## Copyright (C) 2007 Michael Goffioul
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; If not, see <http://www.gnu.org/licenses/>.

function h = __jhandles_go_stemseries (ax, x, y, z, dofill, lc, ls, mc, ms)

  # Create the group object
  h = hggroup (ax);
  if (isempty (z))
    hb = __jhandles_get_baseline (ax, 0);
    bv = get (hb, "BaseValue");
  else
    hb = [];
    bv = 0;
  endif
  addprop (h, "BaseLine", "handle", hb, "readonly");
  addprop (h, "BaseValue", "double", bv);
  addprop (h, "Color", "colorradio", "", lc);
  addprop (h, "LineStyle", "linestyle", ls);
  addprop (h, "LineWidth", "double", 0.5);
  addprop (h, "Marker", "marker", ms);
  addprop (h, "MarkerSize", "double", 6);
  addprop (h, "ShowBaseLine", "radio", "on|off", "on");
  addprop (h, "XData", "doublearray", x);
  addprop (h, "YData", "doublearray", y);
  addprop (h, "ZData", "doublearray", z);
  set (h, "LegendInclude", 1);
  if (! isempty (z))
    set (h, "ZLimInclude", 1);
  endif

  # Create the children line objects
  n = length (x);
  if (isempty (z))
    xx = [x(:)'; x(:)'; NaN(1,n)];
    yy = [bv*ones(1,n); y(:)'; NaN(1,n)];
    hl = __line__ (h, xx(:)', yy(:)', "LineStyle", ls, "Color", lc, "LineWidth", 0.5);
    hm = __line__ (h, x(:)', y(:)', "LineStyle", "none", "Color", mc, ...
                      "Marker", ms, "MarkerSize", 6, "LineWidth", 0.5);
  else
    xx = [x(:)'; x(:)'; NaN(1,n)];
    yy = [y(:)'; y(:)'; NaN(1,n)];
    zz = [bv*ones(1,n); z(:)'; NaN(1,n)];
    hl = __line__ (h, xx(:)', yy(:)', zz(:)', "LineStyle", ls, "Color", lc, "LineWidth", 0.5);
    hm = __line__ (h, x(:)', y(:)', z(:)', "LineStyle", "none", "Color", mc, ...
                      "Marker", ms, "MarkerSize", 6, "LineWidth", 0.5);
  endif

  addlistener (h, "BaseValue", @updateBaseValue);
  if (isempty(z))
    addlistener (h, {"XData", "YData"}, @updateStemData);
  else
    addlistener (h, {"XData", "YData", "ZData"}, @updateStemData);
  endif
  addlistener (h, {"LineStyle", "LineWidth", "Color", "Marker", "MarkerSize"}, @updateLineData);
  if (! isempty (hb))
    addlistener (hb, "BaseValue", {@updateBaseLineBaseValue, h}, h);
    addlistener (hb, "Visible", {@updateBaseLineVisible, h}, h);
  endif
  addlistener (h, "ShowBaseLine", @updateShowBaseLine);

endfunction

function updateStemData (h, evt)
  x = get (h, "XData");
  y = get (h, "YData");
  z = get (h, "ZData");
  ch = get (h, "Children");
  bv = get (h, "BaseValue");

  x = x(:); y = y(:); z = z(:);

  if (isempty (z))
    n = min ([length(x), length(y)]);
    xx = [x(1:n)'; x(1:n)'; NaN(1,n)];
    yy = [bv*ones(1,n); y(1:n)'; NaN(1,n)];
    set (ch(1), "XData", xx(:)', "YData", yy(:)');
    set (ch(2), "XData", x(1:n), "YData", y(1:n));
  else
    n = min ([length(x), length(y), length(z)]);
    xx = [x(1:n)'; x(1:n)'; NaN(1,n)];
    yy = [y(1:n)'; y(1:n)'; NaN(1,n)];
    zz = [bv*ones(1,n); z(1:n)'; NaN(1,n)];
    set (ch(1), "XData", xx(:)', "YData", yy(:)', "ZData", zz(:)');
    set (ch(2), "XData", x(:)', "YData", y(:)', "ZData", z(:)');
  endif
endfunction

function updateBaseValue (h, evt)
  bv = get (h, "BaseValue");
  hb = get (h, "BaseLine");
  if (ishandle (hb))
    set (hb, "BaseValue", bv);
  endif
  updateStemData (h, evt);
endfunction

function updateLineData (h, evt, hl)
  hv = get (h);
  set (hv.children(1), ...
       "Color", hv.color, ...
       "LineStyle", hv.linestyle, ...
       "LineWidth", hv.linewidth);
  set (hv.children(2), ...
       "Color", hv.color, ...
       "Marker", hv.marker, ...
       "MarkerSize", hv.markersize, ...
       "LineWidth", hv.linewidth);
endfunction

function updateBaseLineBaseValue (h, evt, h2)
  set (h2, "BaseValue", get (h, "BaseValue"));
endfunction

function updateShowBaseLine (h, evt)
  hb = get (h, "BaseLine");
  if (ishandle (hb))
    set (hb, "Visible", get (h, "ShowBaseLine"));
  endif
endfunction

function updateBaseLineVisible (hb, evt, h)
  set (h, "ShowBaseLine", get (hb, "Visible"));
endfunction
