" local syntax file - set colors on a per-machine basis:
" vim: tw=0 ts=4 sw=4
" Vim color file
" Maintainer:	Steven Vertigan <steven@vertigan.wattle.id.au>
" Last Change:	2001 Sep 10
" Revision #4: Support for new "Underline" group. Removed superfluous html
"              formatting.

set background=dark
hi clear
if exists("syntax_on")
  syntax reset
endif
let g:colors_name = "gray"
hi Normal			guifg=gray			guibg=black	
hi Normal			ctermfg=gray		ctermbg=black
hi NonText			guifg=lightMagenta		ctermfg=lightMagenta
hi comment			guifg=darkGreen			gui=bold	
hi comment			ctermfg=darkGreen		ctermbg=black
hi constant			guifg=white			ctermfg=white
hi identifier		guifg=gray			ctermfg=gray
hi statement		guifg=white		gui=none					ctermfg=white
hi preproc			guifg=green			ctermfg=green
hi type				guifg=white		ctermfg=white
hi special			guifg=yellow		ctermfg=yellow
hi Underlined		guifg=cyan 			ctermfg=cyan
hi Underlined		gui=underline		cterm=underline

hi ErrorMsg			guifg=darkBlue		guibg=darkBlue	
hi ErrorMsg			ctermfg=yellow			ctermbg=yellow
hi WarningMsg		guifg=cyan			guibg=darkBlue				gui=bold	
hi WarningMsg		ctermfg=cyan
hi ModeMsg			guifg=yellow		gui=NONE
hi ModeMsg			ctermfg=yellow
hi MoreMsg			guifg=yellow		gui=NONE
hi MoreMsg			ctermfg=yellow
hi Error			guifg=black			guibg=red				gui=underline
hi Error			ctermfg=black		ctermbg=red

hi Todo				guifg=black			guibg=darkYellow
hi Todo				ctermfg=black		ctermbg=darkYellow
hi Cursor			guifg=black			guibg=white
hi Cursor			ctermfg=black		ctermbg=white
hi Search			guifg=black			guibg=darkYellow
hi Search			ctermfg=black		ctermbg=darkYellow
hi IncSearch		guifg=black			guibg=darkYellow
hi IncSearch		ctermfg=black		ctermbg=darkYellow
hi LineNr			guifg=lightMagenta			ctermfg=lightMagenta
hi title			guifg=white			gui=bold					cterm=bold

hi StatusLineNC		gui=NONE			guifg=black					guibg=blue
hi StatusLineNC		ctermfg=black  		ctermbg=blue
hi StatusLine		gui=bold			guifg=cyan					guibg=blue
hi StatusLine		ctermfg=cyan   		ctermbg=blue

hi label			guifg=yellow		ctermfg=yellow
hi operator			guifg=darkYellow		gui=bold					ctermfg=darkYellow
hi clear Visual
hi Visual			term=reverse 
hi Visual 			ctermfg=white		ctermbg=darkBlue
hi Visual			guifg=white			guibg=darkBlue

hi DiffChange		guibg=darkGreen		guifg=black
hi DiffChange		ctermbg=darkGreen	ctermfg=black
hi DiffText			guibg=lightGreen		guifg=black
hi DiffText			ctermbg=lightGreen	ctermfg=black
hi DiffAdd			guibg=blue		guifg=black
hi DiffAdd			ctermbg=blue		ctermfg=black
hi DiffDelete  		guibg=cyan			guifg=black	
hi DiffDelete		ctermbg=cyan		ctermfg=black

hi Folded			guibg=yellow		guifg=black	
hi Folded			ctermbg=yellow		ctermfg=black
hi FoldColumn		guibg=gray		guifg=black
hi FoldColumn		ctermbg=gray		ctermfg=black
hi cIf0				guifg=gray			ctermfg=gray
