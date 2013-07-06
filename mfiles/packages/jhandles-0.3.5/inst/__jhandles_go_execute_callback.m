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

function __jhandles_go_execute_callback (h, name, param)

  j1 = java_convert_matrix (1);
  j2 = java_unsigned_conversion (1);

  unwind_protect
    obj = __get_object__ (h);
    prop = obj.getProperty (name);
    if (nargin == 3)
      args = javaArray ("java.lang.Object", 3);
      args(1) = h;
      args(2) = [];
      args(3) = param;
    else
      args = javaArray ("java.lang.Object", 2);
      args(1) = h;
      args(2) = [];
    endif
    prop.execute (args);
  unwind_protect_cleanup
    java_convert_matrix (j1);
    java_unsigned_conversion (j2);
  end_unwind_protect

  java_invoke ("org.octave.graphics.HandleObject", "shutdown");

endfunction
