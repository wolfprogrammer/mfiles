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

function [ h ] = uipanel (varargin)

  parent = [];
  n = nargin;

  if (n > 0)
    if (ishandle (varargin{1}))
      parent = varargin{1};
      varargin(1) = [];
      n--;
    endif
	if (mod (n, 2) == 0)
      if (n > 0)
        idx = find (strcmpi ({varargin{1:2:end}}, "parent"));
        if (! isempty (idx))
          idx = 2*(idx-1)+1;
          parent = varargin{idx+1};
          varargin([idx, idx+1]) = [];
        endif
      endif
    else
      print_usage ();
    endif
  endif

  if (isempty (parent))
    parent = gcf ();
  endif

  if (ishandle (parent))
    type = lower (get (parent, "type"));
    switch type
      case {"figure", "uipanel", "uibuttongroup"}
        tmp = __jhandles_go_uipanel (parent, varargin{:});
        if (nargout > 0)
          h = tmp;
        endif
      otherwise
        error ("invalid parent specified, it must be a figure, uipanel or uibuttongroup object");
    endswitch
  else
    error ("invalid parent specified, it must be a valid handle object");
  endif

endfunction
