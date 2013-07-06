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

function [ h ] = __jhandles_go_surface (ax, varargin)

  x = [];
  y = [];
  z = [];
  others = {};
  args = varargin;

  for k = 1:2:length (args)
    switch args{k}
      case "xdata"
        x = args{k+1};
      case "ydata"
        y = args{k+1};
      case "zdata"
        z = args{k+1};
      otherwise
        others{end+1} = args{k};
        others{end+1} = args{k+1};
    endswitch
  endfor

  if (isvector (x) && isvector (y))
    [x,y] = meshgrid (x, y);
  endif

  j1 = java_convert_matrix (1);
  j2 = java_unsigned_conversion (1);

  unwind_protect
    ax_obj = __get_object__ (ax);
    surf_obj = java_new ("org.octave.graphics.SurfaceObject", ax_obj, ...
      x, y, z);
  unwind_protect_cleanup
    java_convert_matrix (j1);
    java_unsigned_conversion (j2);
  end_unwind_protect

  tmp = surf_obj.getHandle ();
  
  if (length (others) > 0)
    set (tmp, others{:});
  else
    __request_drawnow__;
  endif

  surf_obj.validate ();

  if (nargout > 0)
    h = tmp;
  endif

endfunction
