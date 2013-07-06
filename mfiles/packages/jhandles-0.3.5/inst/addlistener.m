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

function addlistener (h, pname, fun, hh)

  if (nargin < 4)
    hh = [];
  elseif (!ishandle (hh))
    error ("invalid parent handle");
  endif

  if (ishandle (h))
    if (ischar (pname) || iscellstr (pname))
      if (ischar (pname))
        pname = {pname};
      endif
      if (ischar (fun) || isa (fun, "function_handle") ||
        (iscell (fun) && length (fun) > 0 && isa (fun{1}, "function_handle")))
        __jhandles_add_listener (h, pname, fun, hh);
      else
        error ("invalid listener type, must be a string or function handle");
      endif
    else
      error ("invalid property name");
    endif
  else
    error ("invalid handle");
  endif

endfunction
