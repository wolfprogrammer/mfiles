## Copyright (C) 2012 caio
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
## along with Octave; see the file COPYING.  If not, see
## <http://www.gnu.org/licenses/>.

## help2

## Author: caio <caio@ghost1>
## Created: 2012-10-21

function [] = help2 (mode=1)

printf("Ajuda do OCTAVE\n");

printf("Comados mais utéis:\n\n");


if (mode==1)
	system("less /home/caio/mfiles/helptext.txt")
else
 	fid=fopen('helptext.txt','r');
	line=fgets(fid);
 
	while ~feof(fid)
		line=fgetl(fid);
		disp(line);
	end

	fclose(fid);
endif
