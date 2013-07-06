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

function [ h ] = __bar3__ (from, orient, varargin)

  newplot ();

  [xx, yy, w, c, mode, ax] = parseInputArgs(from, varargin{:});
  tmp = makeBar3D (from, ax, xx, yy, w, mode, c, orient);
  if (nargout > 0)
    h = tmp;
  endif

endfunction

function [ h ] = makeBar3D (from, ax, xx, yy, w, mode, c, orient)

  if (length (xx) > 1)
    dx = min (diff (xx));
  else
    dx = 1;
  endif

  m = length (xx);
  nr = size (yy, 2);
  h = [];

  idx1 = 2;
  idx2 = 3;
  if (orient)
    [idx1, idx2] = swap (idx1, idx2);
  endif

  ff_unit = [1, 2, 3, 4; ...
             5, 6, 7, 8; ...
             2, 6, 7, 3; ...
             1, 5, 8, 4; ...
             1, 2, 6, 5; ...
             4, 3, 7, 8];
  M = (0:m-1)*8;
  M = repmat (M, 6, 1);
  M = repmat (M(:), 1, 4);
  ff = repmat (ff_unit, m, 1) + M;

  if (strcmp (mode, "detached"))
    bw = w*dx;
    xx = repmat (xx, 4, 1);
    for k = 1:nr
      vv = zeros (8*m, 3);
	  fvc = ones(8*m, 1)*k;
      Y = repmat (yy(:, k), 4, 1);
      vv([1:8:end, 2:8:end, 3:8:end, 4:8:end], 1) = k-bw/2;
      vv([5:8:end, 6:8:end, 7:8:end, 8:8:end], 1) = k+bw/2;
      vv([1:8:end, 4:8:end, 5:8:end, 8:8:end], idx1) = xx-bw/2;
      vv([2:8:end, 3:8:end, 6:8:end, 7:8:end], idx1) = xx+bw/2;
      vv([1:8:end, 2:8:end, 5:8:end, 6:8:end], idx2) = 0;
      vv([3:8:end, 4:8:end, 7:8:end, 8:8:end], idx2) = Y;
      hp = patch (ax, "Faces", ff, "Vertices", vv, "FaceVertexCData", fvc, "FaceColor", c);
	  h = [h hp];
    endfor
  elseif (strcmp (mode, "stacked"))
    bw = w*dx;
    xx = repmat (xx, 4, 1);
    bv = zeros(4*m, 1);
    for k = 1:nr
      vv = zeros(8*m, 3);
      fvc = ones(8*m, 1)*k;
      Y = repmat (yy(:, k), 4, 1);
      vv([1:8:end, 2:8:end, 3:8:end, 4:8:end], 1) = 1-bw/2;
      vv([5:8:end, 6:8:end, 7:8:end, 8:8:end], 1) = 1+bw/2;
      vv([1:8:end, 4:8:end, 5:8:end, 8:8:end], idx1) = xx-bw/2;
      vv([2:8:end, 3:8:end, 6:8:end, 7:8:end], idx1) = xx+bw/2;
      vv([1:8:end, 2:8:end, 5:8:end, 6:8:end], idx2) = bv;
      vv([3:8:end, 4:8:end, 7:8:end, 8:8:end], idx2) = bv+Y;
      bv = bv+Y;
      hp = patch (ax, "Faces", ff, "Vertices", vv, "FaceVertexCData", fvc, "FaceColor", c);
	  h = [h hp];
    endfor
  elseif (strcmp (mode, "grouped"))
    if (nr == 1)
      bw = gw = w*dx;
      bo = zeros (1, nr);
    else
      gw = 0.8*dx;
      bw = (gw/nr)*w;
      bo = -gw/2+(gw/nr)*([0:nr-1]+0.5)
    endif
    xx = repmat (xx, 4, 1);
    for k = 1:nr
      vv = zeros(8*m, 3);
      fvc = ones(8*m, 1)*k;
      Y = repmat (yy(:, k), 4, 1);
      vv([1:8:end, 2:8:end, 3:8:end, 4:8:end], 1) = 1-bw/2;
      vv([5:8:end, 6:8:end, 7:8:end, 8:8:end], 1) = 1+bw/2;
      vv([1:8:end, 4:8:end, 5:8:end, 8:8:end], idx1) = xx+bo(k)-bw/2;
      vv([2:8:end, 3:8:end, 6:8:end, 7:8:end], idx1) = xx+bo(k)+bw/2;
      vv([1:8:end, 2:8:end, 5:8:end, 6:8:end], idx2) = 0;
      vv([3:8:end, 4:8:end, 7:8:end, 8:8:end], idx2) = Y;
      hp = patch (ax, "Faces", ff, "Vertices", vv, "FaceVertexCData", fvc, "FaceColor", c);
	  h = [h hp];
    endfor
  else
    error ("%s: invalid bar mode", from);
  endif

  if (! ishold ())
    axes (ax);
    view (3);
    dy = diff (get (ax, "YLim"));
    dz = diff (get (ax, "ZLim"));
    if (orient)
      set (ax, "dataaspectratio", [1, (dy/dz)/0.6, 1], "ydir", "reverse");
    else
      set (ax, "dataaspectratio", [1, 1, (dz/dy)/0.6], "ydir", "reverse");
    endif
    grid on;
    axis labelyz;
	box off;
  endif

endfunction

function [xx, yy, w, c, mode, ax] = parseInputArgs(from, varargin)

  xx = [];
  yy = [];
  w = 0.8;
  c = "flat";
  mode = "detached";
  ax = gca ();
  idx = 1;
  nargs = length (varargin);

  if (ishandle (varargin{idx}))
    ax = varargin{idx};
    idx = idx+1;
  endif

  if (nargs >= idx+1 && isnumeric (varargin{idx}) && isnumeric (varargin{idx+1}) && ! isscalar (varargin{idx+1}))
    xx = varargin{idx};
    yy = varargin{idx+1};
    if (! isvector (xx) || ! ismatrix (yy) || (isvector (yy) && length (xx) != length (yy)) ||
      (! isvector (yy) && length (xx) != size (yy, 1)))
      error ("%s: invalid input arguments - X/Y sizes do not match", from);
    endif
    idx = idx+2;
  elseif (nargs >= idx && isnumeric (varargin{idx}))
    yy = varargin{idx};
    if (! ismatrix (yy))
      error ("%s: invalid input arguments - expected matrix input", from);
    endif
    if (isvector (yy))
      xx = 1:length (yy);
    else
      xx = 1:size (yy, 1);
    endif
    idx = idx+1;
  else
    error ("%s: invalid input arguments - expected matrix input", from);
  endif

  [xx, k] = sort (xx);
  if (isvector (yy))
    yy = yy(k);
  else
    yy = yy(k, :);
  endif

  xx = xx(:);
  if (isvector (yy))
    yy = yy(:);
  endif

  for k = idx:length (varargin)
    if (isnumeric (varargin{k}) && isscalar (varargin{k}))
      w = varargin{k};
    elseif (ischar (varargin{k}))
      if (strcmp (varargin{k}, "grouped") || strcmp (varargin{k}, "stacked") || strcmp (varargin{k}, "detached"))
        mode = varargin{k};
      elseif (length (varargin{k}) == 1)
        c = decodeColor (from, varargin{k});
      else
        error ("%s: unexpected argument", from);
      endif
    else
      error ("%s: unexpected argument", from);
    endif
  endfor

endfunction

function [ c ] = decodeColor (from, s)

  persistent cmap;

  if (isempty (cmap))
    cmap = [1, 0, 0; ...
            0, 1, 0; ...
            0, 0, 1; ...
            1, 0, 1; ...
            1, 1, 0; ...
            0, 1, 1; ...
            0, 0, 0; ...
            1, 1, 1];
  endif

  idx = [];
  if (ischar (s) && length (s) == 1 && ! isempty (idx = findstr ("rgbmyckw", s)))
    c = cmap(idx, :);
  else
    error ("%s: invalid color specification", from);
  endif

endfunction
