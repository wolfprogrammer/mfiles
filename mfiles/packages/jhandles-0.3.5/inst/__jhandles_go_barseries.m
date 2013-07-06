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

function [ h ] = __jhandles_go_barseries (ax, xx, yy, width, mode, color, orient)

  xx = xx(:);
  if (isvector (yy))
    yy = yy(:);
  endif

  h = [];
  for k = 1:size (yy, 2)
    obj = java_new ("org.octave.graphics.BarseriesObject", __get_object__ (ax), xx, yy(:,k), orient);
    obj.validate ();
    h = [h obj.getHandle()];
    set (h(end), "barwidth", width, "barlayout", mode, "facecolor", color);
  endfor

  set(h, "bargroup", h);
  __get_object__ (h(1)).updateBars ();

endfunction
