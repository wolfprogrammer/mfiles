## Copyright (C) Michael Goffioul
##
## This program is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This software is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this software; see the file COPYING.  If not, see
## <http://www.gnu.org/licenses/>.

function [ ax, x, y, z, dofill, lc, ls, mc, ms ] = __parse_stem_args__ (name, is3D, varargin)

  args = varargin;
  ax = [];
  x = y = z = [];
  dofill = 0;
  [lc, ls, mc, ms] = set_default_values ();

  # check for parent axes
  if (ishandle (args{1}))
    if (strcmp (get (args{1}, "type"), "axes"))
      ax = args{1};
      args(1) = [];
    else
      error ("%s: invalid stemseries parent, it must be an axes object", name);
    endif
  endif

  # check X/Y/Z arguments
  if (length (args) > 0 && ismatrix (args{1}))
    if (is3D)
      if (length (args) > 2 && ismatrix (args{2}) && ismatrix (args{3}))
        x = args{1};
        y = args{2};
        z = args{3};
        args([1:3]) = [];
      else
        z = args{1};
        args(1) = [];
        if (isvector (z))
          x = 1:length(z);
          y = ones (size (z));
        else
          x = 1:columns(z);
          y = 1:rows(z);
          [x, y] = meshgrid (x, y);
        endif
      endif
    else
      if (length (args) > 1 && ismatrix (args{2}))
        x = args{1};
        y = args{2};
        args([1,2]) = [];
      else
        y = args{1};
        args(1) = [];
        if (isvector (y))
          x = 1:length(y);
        else
          x = 1:rows(y);
        endif
      endif
    endif
  else
    error ("%s: missing stem data", name);
  endif

  if (is3D)
    x = x(:)';
    y = y(:)';
    z = z(:)';
  endif

  # the remaining arguments can be "fill" or LineSpec
  if (length (args) > 0)
    if (iscellstr (args))
      idx = find (strcmp (args, "fill"));
      if (! isempty (idx))
        dofill = 1;
        args(idx) = [];
      endif
      if (length (args) == 1)
        [lc, ls, mc, ms] = stem_line_spec (name, args{1});
      elseif (length (args) > 0)
        error ("%s: too many arguments given");
      endif
    else
      error ("%s: invalid arguments, it must be \"fill\" or a line specification");
    endif
  endif

  # final step
  if (isempty (mc))
    mc = lc;
  endif

endfunction

function [lc, ls, mc, ms] = stem_line_spec (name, str)
  if (! ischar (str))
    error ("stem:stem_line_spec: wrong argument type, must be \"fill\" or a string of specifiers");
  endif
  [lc, ls, mc, ms] = set_default_values ();
  ## Parse the line specifier string.
  cur_props = __pltopt__ (name, str, false);
  for i = 1:length(cur_props)
    if (isfield (cur_props(i), "markeredgecolor"))
      mc = cur_props(i).markeredgecolor;
    endif
    if (isfield (cur_props(i), "color") && ! isempty (cur_props(i).color)); # means line color
      lc = cur_props(i).color;
    endif
    if (isfield (cur_props(i), "linestyle"))
      ls = cur_props(i).linestyle;
    endif
    if (isfield (cur_props(i), "marker") && ! strcmp (cur_props(i).marker, "none"))
      ms = cur_props(i).marker;
    endif
  endfor
endfunction

function [lc, ls, mc, ms] = set_default_values ()
  ## set default values
  mc = [];
  lc = [1, 0, 0];
  ls = "-";
  ms = "o";
endfunction
