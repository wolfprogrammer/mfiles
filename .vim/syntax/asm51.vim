" Vim syntax file
" Language:     8051 Assembler (Intel core microcontroller)
" Maintainer:   Aleksandar Veselinovic <aleksa@cs.cmu.com>
" Last Change:  2003 May 11
" URL:		http://galeb.etf.bg.ac.yu/~alexa/vim/syntax/pic.vim
" Revision:     1.01

" For version 5.x: Clear all syntax items
" For version 6.x: Quit when a syntax file was already loaded
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

syn case match
syn keyword picTodo NOTE TODO XXX contained

syn case ignore

syn match picIdentifier "[a-z_$][a-z0-9_$]*"
syn match picLabel      "^[A-Z_$][A-Z0-9_$]*"
syn match picLabel      "^[A-Z_$][A-Z0-9_$]*:"me=e-1

syn match picASCII      "A\='.'"
syn match picBinary     "B'[0-1]\+'"
syn match picDecimal    "D'\d\+'"
syn match picDecimal    "\d\+"
syn match picHexadecimal "#\x\+"
syn match picHexadecimal "[0-9]*h"
syn match picOctal      "O'[0-7]\o*'"


syn match picComment    ";.*" contains=picTodo

syn region picString    start=+"+ end=+"+


" Registros do 8051
syn keyword picRegister		ACC A B SP PSW SP TH0 TL0 TH1 TL1 TMOD TCON 
syn keyword picRegister		SBUF SCON DPTR DPTL DPTH IP IE PCON 


" Register --- bits

" STATUS
syn keyword picRegisterPart     IRP RP1 RP0 TO PD Z DC C

" PORTA
syn keyword picRegisterPart     T0CKI
syn match   picRegisterPart     "P[0-4]"

" PORTB
syn keyword picRegisterPart     INT
syn match   picRegisterPart     "R[0-7]"
syn match   picRegisterPart     "@R[0-7]"

" INTCON
syn keyword picRegisterPart     IE EEIE T0IE INTE RBIE T0IF INTF RBIF

" OPTION
syn keyword picRegisterPart     RBPU INTEDG T0CS T0SE PSA PS2 PS1 PS0

" EECON2
syn keyword picRegisterPart     EEIF WRERR WREN WR RD

" INTCON
syn keyword picRegisterPart     GIE EEIE T0IE INTE RBIE T0IF INTF RBIF


" OpCodes...
syn keyword picOpcode  ADD AND CLR JMP LJMP CALL LCALL MOV MOVC MOVX SJMP 
syn keyword picOpcode  INC DEC MUL DIV 
syn keyword picOpcode  BCF BSF BTFSC BTFSS
syn keyword picOpcode  ADDLW ANDLW CALL CLRWDT GOTO IORLW MOVLW RETFIE
syn keyword picOpcode  RET RETI SETB CLR JNB POP PUSH
syn keyword picOpcode  GOTO


" Directives
syn keyword picDirective ORG 
syn keyword picDirective EQU DATA DB DE DT DW ELSE END ENDC
syn keyword picDirective ENDIF ENDM ENDW EQU ERROR ERRORLEVEL EXITM EXPAND
syn match picDirective   "#\=UNDEFINE"
syn match picDirective   "#\=INCLUDE"
syn match picDirective   "#\=DEFINE"


" Define the default highlighting.
" For version 5.7 and earlier: only when not done already
" For version 5.8 and later: only when an item doesn't have highlighting yet
if version >= 508 || !exists("did_pic16f84_syntax_inits")
  if version < 508
    let did_pic16f84_syntax_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  HiLink picTodo		Todo
  HiLink picComment		Comment
  HiLink picDirective		Statement
  HiLink picLabel		Label
  HiLink picString		String

 "HiLink picOpcode		Keyword
 "HiLink picRegister		Structure
 "HiLink picRegisterPart	Special

  HiLink picASCII		String
  HiLink picBinary		Number
  HiLink picDecimal		Number
  HiLink picHexadecimal		Number
  HiLink picOctal		Number
  HiLink picIdentifier		Identifier
  HiLink picOpcode		Opcode

  delcommand HiLink
endif

let b:current_syntax = "asm51"

highlight Comment ctermfg=green  cterm=italic
highlight Number ctermfg=red
highlight String ctermfg=red
highlight Constant ctermfg=darkblue cterm=bold
highlight Type  ctermfg=red cterm=bold
highlight Identifier ctermfg=white
highlight Opcode ctermfg=lightblue cterm=bold
highlight picRegister ctermfg=green cterm=bold
highlight picRegisterPart ctermfg=green cterm=bold
" vim: ts=8
