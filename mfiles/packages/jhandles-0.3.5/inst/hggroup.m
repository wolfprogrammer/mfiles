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

function h = hggroup (ax)

  if (nargin == 0)
    ax = gca ();
  else
    if (ishandle (ax))
      typ = get (ax, "type");
      if (! strcmp (typ, "axes") && !  strcmp (typ, "hggroup"))
        error ("parent of hggroup must be an axes or hggroup object");
      endif
    else
      error ("parent of hggroup must be a valid handle object");
    endif
  endif

  h = __jhandles_go_hggroup (ax);

endfunction
