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

function __jhandles_add_listener (h, pname, fun, hh)

  source = __get_object__ (h);
  if (! isempty (hh))
    parent = __get_object__ (hh);
  else
    parent = [];
  endif

  # TODO
  #   - support object listeners
  #   - fun as "string"
  java_new ("org.octave.graphics.OctaveSink", fun, source, pname, parent);

endfunction
