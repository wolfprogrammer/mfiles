



"""""""""""""""""""""""""""""""""""""""""""""""""
"		GENERAL
"

set history=1000

filetype plugin on
filetype indent on


"
set autoread

let mapleader = ","

" Fast saving
nmap <leader>w :w!<CR>
nmap <leader>ew :wq!<CR>


set wildmenu

set cmdheight=2

set showcmd " Show command



set ignorecase
set smartcase
set hlsearch  " Destaca termo buscado "
set incsearch " Busca incremental"


set showmatch

set ai  " Auto ident
set si  " Smart ident
set wrap "Wrap lines

set nocompatible
set ttyfast
set autowrite " Automatic save before :next :make ...

" Insere data ao se apertar F5
nmap <F5> :r !date<CR>

set title "Dá um nome ao terminal"

set virtualedit=all
