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

function ret = mat2java (M)

  if (! isempty (M) && isnumeric (M))
	switch length (size (M))
      case 2
        if (size (M, 1) == 1 || size (M, 2) == 1)
          ret = M;
        else
          s = size (M);
          ret = javaArray (java_get ("java.lang.Double", "TYPE"), s);
          for k = 1:s(1)
            ret(k) = M(k,:);
          endfor
        endif
      otherwise
        s = size (M);
        ret = javaArray (java_get ("java.lang.Double", "TYPE"), s);
        ind = cell (1, length (s));
        [ind{2:end}] = deal (':');
        for k = 1:s(1)
          ind{1} = k;
          ret(k) = mat2java (squeeze (subsref (M, struct('type', '()', 'subs', {ind}))));
        endfor
    endswitch
  else
    ret = M;
  endif

endfunction
