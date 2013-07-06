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

function [ varargout ] = __jhandles_get (h, property)

  j1 = java_convert_matrix (1);
  j2 = java_unsigned_conversion (1);

  unwind_protect
    handle = __get_object__ (h);
    if (! isempty (handle))
      if (nargin == 2)
        varargout{1} = java2mat (handle.get (property));
      elseif (nargout > 0)
        names = char (handle.getNames ());
        ret = struct([]);
        for k = 1:length (names)
          ret.(tolower(names{k})) = java2mat (handle.get (names{k}));
        endfor
        varargout{1} = ret;
      else
        handle.show ();
      endif
    else
      error ("invalid handle");
    endif
  unwind_protect_cleanup
    java_convert_matrix (j1);
    java_unsigned_conversion (j2);
  end_unwind_protect

endfunction
