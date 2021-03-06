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

function [ hc ] = allchild (h)

  old_hideflag = get (0, "ShowHiddenHandles");
  set (0, "ShowHiddenHandles", "on");

  unwind_protect

    if (length (h) == 1)
      hc = get (h, "Children");
    else
      hc = cell (1, length (h));
      idx = 1;
      for hh = h
        hc{idx++} = get (hh, "Children");
      endfor
    endif

  unwind_protect_cleanup

    set (0, "ShowHiddenHandles", old_hideflag);

  end_unwind_protect

endfunction
