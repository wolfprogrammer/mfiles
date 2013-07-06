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

function tmp = __bars__ (h, vertical, x, y, xb, yb, width, group, have_color_spec, base_value, varargin)

  ycols = columns (y);
  ny = rows (y);
  newargs = varargin;
  if (group)
    layout = "grouped";
    width = width*ycols*ycols;
  else
    layout = "stacked";
  endif
  width = width + 10*eps;
  if (vertical)
    hmode = "off";
  else
    hmode = "on";
  endif
  tmp = [];

  for i = 1 : ycols
    # group object creation and initialization
    bs = hggroup (h);
    addprop (bs, "CDataMapping", "radio", "scaled|direct", "scaled", "hidden");
    set (bs, "CLimInclude", "on");
    # low-level patch object creation
    if (vertical)
      if (have_color_spec)
        p = patch (bs, xb(:,:,i), yb(:,:,i), newargs {:}, "parent", bs);
      else
        p = patch (bs, xb(:,:,i), yb(:,:,i), "cdata", i * ones(1, ny), "facecolor", "flat", newargs {:}, "parent", bs);
      endif
    else
      if (have_color_spec)
        p = patch (bs, yb(:,:,i), xb(:,:,i), newargs {:}, "parent", bs);
      else
        p = patch (bs, yb(:,:,i), xb(:,:,i), "cdata", i * ones(1, ny) , "facecolor", "flat", newargs {:}, "parent", bs);
      endif
    endif
    # high-level properties creation
    pp = get (p);
    addprop (bs, "XData", "doublearray", x);
    addprop (bs, "YData", "doublearray", y(:,i));
    addprop (bs, "BarWidth", "double", width);
    addprop (bs, "BarLayout", "radio", "grouped|stacked", layout);
    addprop (bs, "EdgeColor", "colorradio", "flat|interp|none", get (p, "EdgeColor"));
    addprop (bs, "FaceColor", "colorradio", "flat|interp|none", get (p, "FaceColor"));
    addprop (bs, "BarGroup", "handle", "hidden");
    addprop (bs, "Horizontal", "radio", "on|off", hmode);
    addlistener (bs, {"BarWidth", "BarLayout", "Horizontal"}, @updateGroup);
    addlistener (bs, {"XData", "YData", "BarWidth", "BarLayout", "Horizontal"}, @updateData);
    addlistener (bs, {"EdgeColor", "FaceColor"}, @updateColors);
    # store handle
    tmp = [tmp, bs];
  endfor

  if (! isempty (tmp))
    set (tmp, "BarGroup", tmp);
  endif

endfunction

function updateData (h)

  hlist = get (h, "BarGroup");
  x = get (h, "XData");
  y = [];
  for hh = hlist(:)'
    ytmp = get (hh, "YData");
    y = [y ytmp(:)];
  endfor
  x = x(:);

  [xb, yb] = bar (x, y, get (h, "BarWidth"), get (h, "BarLayout"));
  ny = columns (y);
  vert = strcmp (get (h, "Horizontal"), "off");

  for i = 1:ny
    hp = get (hlist(i), "Children");
    if (vert)
      set (hp, "XData", xb(:,:,i), "YData", yb(:,:,i));
    else
      set (hp, "XData", yb(:,:,i), "YData", xb(:,:,i));
    endif
  endfor

endfunction

function updateColors (h)

  hp = get (h, "Children");
  set (hp, "EdgeColor", get (h, "EdgeColor"), ...
           "FaceColor", get (h, "FaceColor"));

endfunction

function updateGroup (h)

  hlist = get (h, "BarGroup");
  args = { "BarWidth", get(h, "BarWidth"), ...
           "BarLayout", get(h, "BarLayout"), ...
           "Horizontal", get(h, "Horizontal") };
  for hh = hlist(:)'
    if (hh != h)
      reset_property (hh, args{:});
    endif
  endfor

endfunction
