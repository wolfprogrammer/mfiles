"""""""""""""""""""""""""""""""""""""""""""""""""
"		GENERAL
	"
"------------------- KEY MAPS --------------------"

syntax on
filetype plugin on



set wildchar=<Tab> wildmenu wildmode=full
set wildcharm=<C-Z>



nnoremap <F11> :make! <CR>



let mapleader = ","
nmap ;; :
nmap <silent> <C-n> :silent :nohlsearch<CR> " Apaga resultado da busca
" Close the current buffer
 map <leader>bd :bd<cr>
"
" " Close all the buffers
 map <leader>ba :1,300 bd!<cr>  

" Smart way to move btw. windows
map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l 

set pastetoggle=<F2> 

" Fast saving
nmap <leader>w :w!<CR>
nmap <leader>ew :wq!<CR>
" Fast saving
map <leader>eee :e! ~/.vimrc<cr> 

" Copy use Ctrl + V
nmap <C-V> "+gP  

imap <C-V> <ESC><C-V>a 
vmap <C-C> "+y

map <C-Left> <Esc>:tabprev<CR>
map <C-Right> <Esc>:tabnext<CR>
map <C-Up> <Esc>:tabnew <CR>
map <C-F9> :q <CR>

map <F9>: !make clean && make <cr>

" ------------------ SETTINGS ------------------"

set history=1000

filetype plugin on
filetype indent on


set bg=dark
set t_Co=256
" color wombat256
" desert256
"color relaxedgreen




set path+=~/mcu/include
set path+=/usr/local/share/sdcc/include/pic16
set path+=/usr/local/share/sdcc/non-free/include

set shortmess=atI




"
set autoread



"
" " When vimrc is edited, reload it

 autocmd! bufwritepost vimrc source ~/.vim_runtime/vimrc
"

set wildmenu

set cmdheight=2

set showcmd " Show command



set ignorecase
set smartcase
set hlsearch  " Destaca termo buscado "
set incsearch " Busca incremental"
set smartindent

set ruler

set showmatch

set ai  " Auto ident
set si  " Smart ident
set wrap "Wrap lines

set nocompatible
set ttyfast
set autowrite " Automatic save before :next :make ...

" Insere data ao se apertar F5

set title "Dá um nome ao terminal"

set virtualedit=all






set autochdir " always switch to the current file directory
"set backspace=indent,eol,start " make backspace a more flexible

"set backup " make backup files
"set backupdir=~/.vim/backup " where to put backup files
set nobackup
set noswapfile
set hidden



set clipboard+=unnamed " share windows clipboard
set directory=~/.vim/tmp " directory to place swap files in
set fileformats=unix,dos,mac " support all three, in this order
set wildignore=*.dll,*.o,*.obj,*.bak,*.exe,*.pyc,*.jpg,*.gif,*.png
set wildmode=list:longest " turn on wild mode huge list

"set cursorline

" Execute file being edited with <Shift> + e:
 "map <buffer> <S-e> :w<CR>:!/usr/bin/env python % <CR>
  map ;e :exe ":!python " . getreg("%") . "" <CR>

  set makeef=error.err
  set nu		" Line numbers

  set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=\%02.2B]\ [POS=%04l,%04v][%p%%]\ [LEN=%L]

  set nowrap	" Sem quebra linhas
  

  
  " -------------------  MENUS -----------------------"




 "nmap <F5> :!python % <CR>

"  Executa script do octave
"

amenu RUN.ipython :!ipython %<cr>
amenu RUN.python :!python %<cr>
amenu RUN.octave :!octave %<cr>
amenu RUN.c :!tcc %<cr>


"--------- Menu de utilidades ------------"
"
amenu Utilities.List_Tags : TlistToggle <cr>
amenu Utilities.Generate_tags : !ctags -R * <cr>
amenu Utilities.ProjectExplorer :Project <cr>
amenu Utilities.FileExplorer :NERDTreeToggle <cr>
amenu Utilities.Error_List :copen <cr>
"" GIT
amenu Utilities.Git.CommitAll : !git commit -a -m " "
amenu Utilities.Git.Log : !git log  <cr>
amenu Utilities.Git.LogAll : !git log  --oneline --abbrev-commit --all --graph --decorate --color  <cr>
amenu Utilities.Git.ShowFiles : !git ls-files -t  <cr>
amenu Utilities.Git.Status : !git status  <cr>
amenu Utilities.Git.ListBranches : !git branch  <cr>
amenu Utilities.Git.Init : !git init && git add . && git commit -m "First backup" <cr>
amenu Utilities.Git.Reset : !git reset --hard <cr>
amenu Utilities.Terminal : !lxterminal & <cr><cr><cr>     "Open terminal in the file directory
amenu Utilities.BrowserFiles : !pcmanfm & <cr><cr><cr>     "Open terminal in the file directory
amenu Utilities.Notes :  e ~/.vim/notes <cr> 




" -----------Menu de templates-------------"
"
amenu Templates.sdcc.main_sdcc : r~/.vim/template/main.c  <cr>
amenu Templates.sdcc.Function_Header : r~/.vim/template/function-header.c  <cr>
amenu Templates.sdcc.FuzyBits : r~/.vim/template/fuzybits.c  <cr>
amenu Templates.sdcc.Header_file : r~/.vim/template/header.h  <cr>
amenu Templates.sdcc.Bitfield : r~/.vim/template/bitfield  <cr>
amenu Templates.sdcc.Inline_Assembly : r~/.vim/template/ASM  <cr>
amenu Templates.sdcc.Function_Assembly : r~/.vim/template/functionASM  <cr>
amenu Templates.sdcc.End_Of_File : r~/.vim/template/EOF.c  <cr>
amenu Templates.sdcc.Makefile : r~/.vim/template/Makefile.c  <cr>

amenu icon=/home/caio/.vim/addtab.png  ToolBar.Foo :tabnew <cr>
amenu icon=/home/caio/.vim/mcu.png  ToolBar.Foo2 :!make burn <cr>
amenu icon=/home/caio/.vim/matlab.png  ToolBar.Foo3 : !lxterminal -e "octave --persist --silent %" & <cr><cr>






" have a small-ish yet readable font:
set guifont=Andale\ Mono\ 10

" have error messages red on white
" readable in the above font):
highlight ErrorMsg guibg=White guifg=Red


source ~/.vim/plugin/cscope_maps.vim
colorscheme candycode


"-------  KEYWORDS HIGH LIGHT ----------------------"
syn keyword   cTodo  FIXME TODO  README


let tlist_r_settings = 'forth;d:definitons'
