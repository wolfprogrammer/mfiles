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

function [ h ] = __jhandles_go_line (ax, varargin)

  j1 = java_convert_matrix (1);
  j2 = java_unsigned_conversion (1);

  unwind_protect
    obj = java_new ("org.octave.graphics.LineObject", __get_object__ (ax));
  unwind_protect_cleanup
    java_convert_matrix (j1);
    java_unsigned_conversion (j2);
  end_unwind_protect

  h = obj.getHandle ();

  if (length (varargin) > 0)
    set(h, varargin{:});
  else
    __request_drawnow__;
  endif
  obj.validate ();

endfunction
