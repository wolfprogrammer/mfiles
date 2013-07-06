%   		search.m
%
%   Author: Caio Rodrigues
%   Email:  caiorss.rodrigues@gmail.com
%
%


function [LST] = search(STR)
%
%  Look for a given string in % the specified 
%  directorys in all m-files
%
%  usage: search('string')
%
%  ** Works only for octave in UNIX envinronment
% 

% Current directory
dir0= pwd               ;

% User directory 
dir1= '/home/caio/mfiles';

% Octave directory
dir2='/usr/share/octave/3.2.4/m' ;


cmd=sprintf('find %s %s %s -name "*.m" -exec grep -l "%s" {} \\;',dir0,dir1,dir2,STR) ;
LST=system(cmd) ;



endfunction
