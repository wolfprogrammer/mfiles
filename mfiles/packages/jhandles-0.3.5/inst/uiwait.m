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

function uiwait (fig)

  if (ishandle (fig) && strcmp (get (fig, "type"), "figure"))
    try
      set (fig, "__wait__", "on");
    catch
      addprop (fig, "__wait__", "radio", "on|off", "on");
    end
    waitfor (fig, "__wait__", "off");
  else
    print_usage ();
  endif

endfunction
