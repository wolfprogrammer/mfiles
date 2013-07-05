augroup encrypted
au!
autocmd BufReadPre,FileReadPre *.gpg,*.asc set viminfo=
autocmd BufReadPre,FileReadPre *.gpg,*.asc set noswapfile
autocmd BufReadPre,FileReadPre *.gpg set bin
autocmd BufReadPre,FileReadPre *.gpg,*.asc let ch_save = &ch|set ch=2

autocmd BufReadPost,FileReadPost *.gpg,*.asc '[,']!sh -c 'gpg --decrypt 2> /dev/
null'
autocmd BufReadPost,FileReadPost *.gpg set nobin
autocmd BufReadPost,FileReadPost *.gpg,*.asc let &ch = ch_save|unlet ch_save
autocmd BufReadPost,FileReadPost *.gpg,*.asc execute ":doautocmd BufReadPost " .
 expand("%:r")

autocmd BufWritePre,FileWritePre *.gpg '[,']!sh -c 'gpg --default-recipient-self
 -e 2>/dev/null'
autocmd BufWritePre,FileWritePre *.asc '[,']!sh -c 'gpg --default-recipient-self
 -e -a 2>/dev/null'

autocmd BufWritePost,FileWritePost *.gpg,*.asc u
augroup END