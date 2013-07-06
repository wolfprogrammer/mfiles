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

function [ h ] = uicontrol (varargin)

  parent = [];

  if (length (varargin) > 0)
    if (! ischar (varargin{1}))
      if (ishandle (varargin{1}))
        parent = varargin{1};
        varargin(1) = [];
      else
        error ("invalid parent, it must be a valid handle");
      endif
    endif
	idx = find (strcmpi ("parent", varargin(1:2:end)), 1, "first");
    if (! isempty (idx) && length (varargin) >= 2*idx)
      parent = varargin{2*idx};
	  varargin([2*idx-1, 2*idx]) = [];
    endif
  endif

  if (mod (length (varargin), 2) == 0)
    if (isempty (parent))
      parent = gcf ();
    endif
    tmp = __jhandles_go_uicontrol (parent, varargin{:});
    if (nargout > 0)
      h = tmp;
    endif
  else
    error ("invalid number of arguments, it must be a property/value list");
  endif

endfunction
