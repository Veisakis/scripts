set nocompatible
set number relativenumber
set backspace=indent,eol,start

filetype plugin on
syntax on

autocmd FileType tex inoremap ;l {\latintext{}}<Esc>1hi
autocmd FileType tex inoremap ;b {\textbf{}}<Esc>1hi
autocmd FileType tex inoremap ;i {\textit{}}<Esc>1hi
autocmd FileType tex inoremap ;u {\underline{}}<Esc>1hi

