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

function [ h ] = __jhandles_go_patch (ax, varargin)

  [ax, args] = __get_parent_arg__ (ax, varargin);
  ax_obj = __get_object__ (ax);

  p_obj = java_new ("org.octave.graphics.PatchObject", ax_obj);
  tmp = p_obj.getHandle ();
  if (length (args) >= 0)
    set (tmp, args{:});
  else
    __request_drawnow__;
  endif
  p_obj.validate ();

  if (nargout > 0)
    h = tmp;
  endif

endfunction
