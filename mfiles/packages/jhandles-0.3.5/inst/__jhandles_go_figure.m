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

function [ f ] = __jhandles_go_figure (fnum, varargin)

  root = __get_object__ (0);
  if (isempty (fnum) || isnan (fnum))
    f_obj = root.createNewFigure();
  else
    f_obj = root.createNewFigure(fnum);
  endif

  if (! isempty (f_obj))
    f = f_obj.getHandle ();
    if (length (varargin) > 0)
      set (f, varargin{:});
    endif
    f_obj.validate ();
	f = f_obj.getHandle ();
  else
    f = [];
  endif

endfunction
