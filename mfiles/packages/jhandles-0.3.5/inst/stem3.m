## Copyright (C) 2006 Michael Goffioul
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

function h = stem3 (varargin)

  if (nargin < 1 || nargin > 6)
    print_usage ();
  endif

  [ax, x, y, z, dofill, lc, ls, mc, ms] = __parse_stem_args__ ("stem3", 1, varargin{:});
  if (isempty (ax))
    ax = gca ();
  else
    axes (ax);
  endif

  newplot ();

  tmp = __jhandles_go_stemseries (ax, x, y, z, dofill, lc, ls, mc, ms);
  
  if (! strcmp (get (ax, "nextplot"), "add"))
    set(ax, "view", [-37.5, 30], "box", "off", "xgrid", "on", "ygrid", "on", "zgrid", "on");
  endif

  if (nargout > 0)
    h = tmp;
  endif

endfunction
