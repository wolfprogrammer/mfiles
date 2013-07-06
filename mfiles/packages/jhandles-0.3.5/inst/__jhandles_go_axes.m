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

function [ h ] = __jhandles_go_axes (fig, varargin)

  fig_obj = __get_object__ (fig);
  ax_obj = java_new ("org.octave.graphics.AxesObject", fig_obj, 0);
  h = ax_obj.getHandle ();

  if (length (varargin) > 0)
    set (h, varargin{:});
    if (any (strcmpi (varargin(1:2:end), "position")))
      set(h, "activepositionproperty", "position");
    endif
  endif

  ax_obj.validate ();

endfunction
