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

function [ p, args ] = __get_parent_arg__ (p, args)

  idx = find (strcmp (args, "Parent"));
  if (isempty (idx))
    idx = find (strcmp (args, "parent"));
  endif

  if (! isempty (idx) && length (args) > idx(1))
    p = args{idx(1)+1};
    args(idx(1):idx(1)+1) = [];
  elseif (length (args) > 0 && ishandle (args{1}))
    p = args{1};
    args(1) = [];
  endif

endfunction
