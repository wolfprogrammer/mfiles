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

function [ h ] = __jhandles_go_text (ax, dummy1, txt, dummy2, pos, varargin)

  ax_obj = __get_object__ (ax);
  txt_obj = java_new ("org.octave.graphics.TextObject", ax_obj, txt, pos);
  h = txt_obj.getHandle ();

  if (length (varargin) > 0)
    set (h, varargin{:});
  endif

  txt_obj.validate ();

endfunction
