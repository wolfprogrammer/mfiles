## Copyright (C) 2006 Michel D. Schmid
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

## -*- texinfo -*-
## @deftypefn {Function File} {@var{h} =} stem (@var{x}, @var{y}, @var{linespec})
## Plot a stem graph and return the handles of the line and marker
## objects used to draw the stems.  The default color is @code{"r"}
## (red). The default line style is @code{"-"} and the default marker is
## @code{"o"}.
##
## For example,
## @example
## x = 1:10;
## stem (x);
## @end example
## @noindent
## plots 10 stems with heights from 1 to 10;
##
## @example
## x = 1:10;
## y = ones (1, length (x))*2.*x;
## stem (x, y);
## @end example
## @noindent
## plots 10 stems with heights from 2 to 20;
## 
## @example
## x = 1:10;
## y = ones (size (x))*2.*x;
## h = stem (x, y, "b");
## @end example
## @noindent
## plots 10 bars with heights from 2 to 20
## (the color is blue, and @var{h} is a 2-by-10 array of handles in
## which the first row holds the line handles and the 
## the second row holds the marker handles);
##
## @example
## x = 1:10;
## y = ones (size (x))*2.*x;
## h = stem (x, y, "-.k");
## @end example
## @noindent
## plots 10 stems with heights from 2 to 20
## (the color is black, line style is @code{"-."}, and @var{h} is a 2-by-10
## array of handles in which the first row holds the line handles and
## the second rows holds the marker handles);
##
## @example
## x = 1:10;
## y = ones (size (x))*2.*x;
## h = stem (x, y, "-.k.");
## @end example
## @noindent
## plots 10 stems with heights from 2 to 20
## (the color is black, line style is @code{"-."} and the marker style
## is @code{"."}, and @var{h} is a 2-by-10 array of handles in which the
## first row holds the line handles and the second row holds the marker
## handles);
##
## @example
## x = 1:10;
## y = ones (size (x))*2.*x;
## h = stem (x, y, "fill");
## @end example
## @noindent
## plots 10 stems with heights from 2 to 20
## (the color is rgb-triple defined, the line style is @code{"-"},
## the marker style is @code{"o"}, and @var{h} is a 2-by-10 array of
## handles in which the first row holds the line handles and the second
## row holds the marker handles).
##
## Color definitions with rgb-triples are not valid!
##
## @seealso{bar, barh, plot}
## @end deftypefn

## Author: Michel D. Schmid <michaelschmid@users.sourceforge.net>
## Adapted-by: jwe
## Adapted-by: Michael Goffioul <michael.goffioul@gmail.com>

function h = stem (varargin)

  if (nargin < 1 || nargin > 5)
    print_usage ();
  endif

  [ax, x, y, z, dofill, lc, ls, mc, ms] = __parse_stem_args__ ("stem", 0, varargin{:});
  if (isempty (ax))
	ax = gca ();
  else
    axes (ax);
  endif

  newplot ();

  if (isvector (y))
    y = y(:);
  endif
  if (isvector (x))
    x = repmat (x(:), 1, columns (y));
  endif
  n = columns (y);

  tmp = zeros (1, n);
  for k = 1:n
    tmp(k) = __jhandles_go_stemseries (ax, x(:,k), y(:,k), [], dofill, lc, ls, mc, ms);
  endfor

  if (nargout > 0)
    h = tmp;
  endif

endfunction
