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

function h = __jhandles_get_baseline (ax, bv)

  h = [];
  for hh = get (ax, "children")
    if (strcmp (get (hh, "type"), "line") && isprop (hh, "BaseValue"))
      h = hh;
      break;
    endif
  endfor

  if (isempty (h))
    h = __line__ (ax, get (ax, "XLim"), [bv bv], "Color", "k", "XLimInclude", 0, "LegendInclude", 0);
    addprop (h, "BaseValue", "double", bv);
    addlistener (ax, "XLim", {@updateXLim, h}, h);
    addlistener (h, "BaseValue", @updateBaseValue);
  endif

endfunction

function updateXLim (ax, evt, h)
  set (h, "XData", get (ax, "XLim"));
endfunction

function updateBaseValue (h, evt)
  bv = get (h, "BaseValue");
  set (h, "YData", [bv bv]);
endfunction
