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

function [ h ] = __area__ (ax, X, Y, bv, varargin)

  h = [];

  YY = cumsum (Y, 2);

  for k = 1:size (Y,2)
    # create group object
    hh = hggroup (ax);
	addprop (hh, "BaseValue", "double", bv);
    addprop (hh, "XData", "doublearray", X(:,k));
    addprop (hh, "YData", "doublearray", Y(:,k));
	addprop (hh, "FaceColor", "colorradio", "flat|interp|none", "flat");
	addprop (hh, "EdgeColor", "colorradio", "flat|interp|none", "k");
    addprop (hh, "CDataMapping", "radio", "scaled|direct", "scaled", "hidden");
	addprop (hh, "AreaGroup", "handle", "hidden");
	addprop (hh, "LineStyle", "linestyle", "-");
	addprop (hh, "LineWidth", "double", 0.5);
    set (hh, "CLimInclude", true);
	set (hh, varargin{:});
	addlistener (hh, {"FaceColor", "EdgeColor", "LineStyle", "LineWidth"}, @updatePatchColor);
    addlistener (hh, {"XData", "YData", "BaseValue"}, @updatePatchData);
    addlistener (hh, "ObjectDeleted", @memberDeleted);
	hh_v = get (hh);
    # create patch object
    if (k == 1)
      vv = [X(1,k) bv 0; X(:,k) Y(:,k) zeros(size(Y,1),1); X(end,k) bv 0];
      fv = [1:size(vv,1)];
    else
      vv = [X(end:-1:1,k-1) YY(end:-1:1,k-1) zeros(size(Y,1),1); X(:,k) YY(:,k) zeros(size(Y,1),1)];
      fv = [1:size(vv,1)];
    endif
    fvc = k * ones (size (vv,1), 1);
    hp = patch (hh, "Faces", fv, "Vertices", vv, "FaceVertexCData", fvc, ...
      "FaceColor", hh_v.facecolor, "EdgeColor", hh_v.edgecolor, "LineStyle", hh_v.linestyle, ...
      "LineWidth", hh_v.linewidth, "__Index__", k-1);
    h = [h hh];
  endfor

  if (! isempty (h))
    set (h, "AreaGroup", h);
  endif

endfunction

function memberDeleted (h)

  hlist = get (h, "AreaGroup");
  hlist(find (hlist == h)) = [];
  if (! isempty (hlist))
    set (hlist, "AreaGroup", hlist);
  endif

endfunction

function updatePatchColor (h)

  hv = get (h);
  set (hv.children(1), "FaceColor", hv.facecolor, ...
                       "EdgeColor", hv.edgecolor, ...
					   "LineStyle", hv.linestyle, ...
					   "LineWidth", hv.linewidth);

endfunction

function updatePatchData (h)

  hlist = get (h, "AreaGroup");
  bv = get (h, "BaseValue");
  YY = [];
  for hh = hlist(:)'
    x = get (hh, "XData");
    y = get (hh, "YData");
    hp = get (hh, "Children");
    x = x(:); y = y(:);
    if (isempty (YY))
      vv = [x(1) bv 0; x y zeros(length(y), 1); x(end) bv 0];
      YY = y;
    else
      vv = [x(end:-1:1) YY(end:-1:1) zeros(length(y), 1); x y+YY zeros(length (y), 1)];
      YY += y;
    endif
    fv = [1:size(vv,1)];
	if (! isempty (hp))
      # hp may be empty if the child patch object has
      # been deleted explicitely
      set (hp(1), "Faces", fv, "Vertices", vv);
    endif
  endfor

endfunction
