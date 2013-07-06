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

function [ h ] = legend (varargin)

  ca = [];
  names = {};
  is_cell_str = false;

  for k = 1:length (varargin)
    if (iscellstr (varargin{k}))
      names = varargin{k};
      is_cell_str = true;
    elseif (ischar (varargin{k}))
      if (is_cell_str)
        error ("cannot mix strings and cell array of strings as arguments");
      else
        names{end+1} = varargin{k};
      endif
    elseif (isnumeric (varargin{k}) && ishandle (varargin{k}) && k == 1)
      ca = varargin{k};
    endif
  endfor

  if (isempty (ca))
    ca = gca;
  endif

  if (length (names) == 0)
    legend_obj = __get_object__ (ca).getLegend ();
  elseif (length (names) == 1 &&
      any (strcmp (names{1}, {"hide", "show", "boxoff", "boxon", "off"})))
    ax_obj = __get_object__ (ca);
    legend_obj = ax_obj.getLegend ();
    op = names{1};
    if (! isempty (legend_obj))
      hl = legend_obj.getHandle ();
      if (strcmp (op, "off"))
        ax_obj.makeLegend ([]);
      elseif (strcmp (op, "boxoff"))
        set (hl, "visible", "off");
      elseif (strcmp (op, "boxon"))
        set (hl, "visible", "on");
      elseif (strcmp (op, "hide"))
        set (hl, "visible", "off");
        set (get (hl, "children"), "visible", "off");
      elseif (strcmp (op, "show"))
        set (hl, "visible", "on");
        set (get (hl, "children"), "visible", "on");
      endif
    else
      if (strcmp (op, "show"))
        hh = get (ca, "children");
        for k = 1:length(hh)
          names{k} = ["data ", num2str(k)];
        endfor
        legend_obj = ax_obj.makeLegend (names);
      endif
    endif
  else
    legend_obj = __get_object__ (ca).makeLegend (names);
  endif

  if (nargout > 0)
    if (! isempty (legend_obj))
      h = legend_obj.getHandle ();
    else
      h = [];
    endif
  endif

  __request_drawnow__;

endfunction
