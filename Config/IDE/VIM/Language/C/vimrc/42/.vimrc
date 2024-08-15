"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""               
"                                                                         "
"                                                                         "
"        ▒█░░▒█ ▀█▀ ▒█▀▄▀█     ▒█▀▀█ ▒█▀▀▀█ ▒█▄░▒█ ▒█▀▀▀ ▀█▀ ▒█▀▀█        "
"        ░▒█▒█░ ▒█░ ▒█▒█▒█     ▒█░░░ ▒█░░▒█ ▒█▒█▒█ ▒█▀▀▀ ▒█░ ▒█░▄▄        "
"        ░░▀▄▀░ ▄█▄ ▒█░░▒█     ▒█▄▄█ ▒█▄▄▄█ ▒█░░▀█ ▒█░░░ ▄█▄ ▒█▄▄█        "
"                                                                         "
"                                                         by tablerase    "
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


" PLUGINS -----------------------------------------------------------------{{{
"
" Install vim-plug if not found
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
endif
" Run PlugInstall if there are missing plugins
autocmd VimEnter * if len(filter(values(g:plugs), '!isdirectory(v:val.dir)'))
  \| PlugInstall --sync | source $MYVIMRC
\| endif
" The plugin directory will be as follows:
"   - Vim (Linux/macOS): '~/.vim/bundle'
"   - Vim (Windows): '~/vimfiles/bundle'
"   - Neovim (Linux/macOS/Windows): stdpath('data') . '/bundle'
" You can specify a custom plugin directory by passing it as the argument
"   - e.g. `call plug#begin('~/.vim/bundle')`
"   - Avoid using standard Vim directory names like 'plugin'

" For Mac/Linux users
call plug#begin('~/.vim/bundle')

" ↓↓↓ Insert your plugins below ↓↓↓
Plug 'itchyny/lightline.vim' " status bar
Plug 'catppuccin/vim', { 'as': 'catppuccin' } "color scheme recommended ♥
"Plug 'neoclide/coc.nvim', {'branch': 'release'} " autocomplete
Plug 'dense-analysis/ale' " syntax checking and semantic errors
Plug 'preservim/nerdtree' " file system explorer for the Vim

" Initialize plugin system
" Automatically executes `filetype plugin indent on` and `syntax enable`.
call plug#end()
" You can revert the settings after the call like so:
"   filetype indent off   Disable file-type-specific indentation
"   syntax off            Disable syntax highlighting
"}}}

" PROGRAMS -----------------------------------------------------------------{{{
" -- Linux version
" Clang - compiler
" if !executable('clang')
"    " Install clang if not already there
"    silent !sudo apt-get install clang
" endif
" GDB - debugger
" if !executable('gdb')
"    " Install gdb if not already there
"    silent !sudo apt-get install gdb
" endif
" Valgrind - memcheck
" if !executable('valgrind')
"    " Install valgrind if not already there
"    silent !sudo apt-get install valgrind
" endif
"}}}

" COLORS -------------------------------------------------------------------{{{
"
" color schemes choice:
colorscheme catppuccin_mocha
" activate True Color - need for some color scheme
set termguicolors
"}}}

" STATUS BAR ---------------------------------------------------------------{{{
"
" color integrations with plugins
let g:lightline = {
      \ 'colorscheme': 'catppuccin_mocha',
      \ 'active': {
      \   'right': [ [ 'lineinfo' ],
      \              [ 'percent' ],
      \              [ 'fileformat', 'fileencoding', 'filetype', 'charvaluehex', 'charvalueascii' ] ]
      \ },
      \ 'component': {
      \   'charvaluehex': '0x%B',
      \   'charvalueascii': '%b'
      \ },
      \ }
"Always display status bar, use it if colorful mode display with linestatus plugin doesnt work"
set laststatus=2
"}}}

" SYNTAX -------------------------------------------------------------------{{{
"
" turn line numbers on
set number
" highlight matching braces
set showmatch
" intelligent comments
set comments=sl:/*,mb:\ *,elx:\ */
" disable vi compatibility (emulation of old bugs)
set nocompatible
" use indentation of previous line
"set autoindent
" use intelligent indentation for C
"set smartindent
" configure tabwidth and insert spaces instead of tabs
"set tabstop=4        " tab width is 4 spaces
"set shiftwidth=4     " indent also with 4 spaces
"set expandtab        " expand tabs to spaces
" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
set textwidth=80
" turn syntax highlighting on
set t_Co=256
" Hide mode info - mode information in status line
set noshowmode
"}}}

" CURSOR -------------------------------------------------------------------{{{
"
" Highlights the current line
set cursorline
" Highlight cursor line underneath the cursor vertically.
set cursorcolumn
"}}}

" SPLIT -------------------------------------------------------------------{{{
" You can split a window into sections by typing `:split` or `:vsplit`.
" Display cursorline and cursorcolumn ONLY in active window.
augroup cursor_off
    autocmd!
    autocmd WinLeave * set nocursorline nocursorcolumn
    autocmd WinEnter * set cursorline cursorcolumn
augroup END
"}}}

" FOLD --------------------------------------------------------------{{{
"
" set foldmethod=indent - Folds code based on indentation
" set foldlevel=1 - Sets the initial fold level to 1
" Enable the marker method of folding.
" augroup filetype_vim
"    autocmd!
"    autocmd FileType vim setlocal foldmethod=marker
" augroup END
"}}}

" HISTORY ------------------------------------------------------------------{{{
"
" Set the commands to save in history default number is 20.
set history=1000
"}}}

" MOUSE --------------------------------------------------------------------{{{
"
" Enables the use of the mouse in all modes: visual, normal, insert, and command line1. This means that you can use the mouse to select text, scroll through files, resize windows, and more.
set mouse=a
"}}}

" SEARCH -------------------------------------------------------------------{{{
"
" Makes search case-insensitive
" set ignorecase
" Makes search case-sensitive if the search term contains uppercase letters
" set smartcase
"}}}

" set UTF-8 encoding -------------------------------------------------------{{{
set enc=utf-8
set fenc=utf-8
set termencoding=utf-8
"}}}

" Enhanced KEYBOARD MAPPINGS -----------------------------------------------{{{
"
" in normal mode F2 will save the file
nmap <F2> :w<CR>
" in insert mode F2 will exit insert, save, enters insert again
imap <F2> <ESC>:w<CR>i
" switch between header/source with F4
map <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>
" recreate tags file with F5
map <F5> :!ctags -R –c++-kinds=+p –fields=+iaS –extra=+q .<CR>
" map <F6> with a custom command:
map <F6> <CR>
" build using makeprg with <F7>
map <F7> :make<CR>
" build using makeprg with <S-F7>
map <S-F7> :make clean all<CR>
" goto definition with F12
map <F12> <C-]>
"}}}

" AUTO MAIN in C -----------------------------------------------------------{{{
" 
" Auto add a main
function! InsertMainTest()
    " Check if the current file is a C file
    if &filetype == 'c'
        " Insert the #include line
        call append(0, "#include <stdio.h>")
	call append(1, "#include <string.h>")
	call append(2, "")
        " Insert the main function
        call append(3, "int	main(void)") 
	call append(4, " {")
        call append(5, "	char	test[] = \"ZAFDFADSF\";")
        call append(6, "	char	test2[] = \"AFDA\";")
        call append(7, "	char	test3[] = \"\";")
        call append(8, "")
        call append(9, "	printf(\"\\e[0;32mTEST:\\e[0m %s | \", test);")
        call append(10, "	printf(\"\\n\\e[0;32mTEST:\\e[0m %s | \", test2);")
        call append(11, "	printf(\"\\n\\e[0;32mTEST:\\e[0m %s | \", test3);")
        call append(12, "")
        call append(13, "	return 0;")
        call append(14, "}")
    endif
endfunction

function! InsertMain()
    " Check if the current file is a C file
    if &filetype == 'c'
        " Insert the main function
        call append(0, "int main() {")
        call append(1, "    // Your code here")
        call append(2, "    return 0;")
        call append(3, "}")
    endif
endfunction

autocmd BufNewFile *.c call InsertMain()
autocmd BufNewFile *.cpp call InsertMain()
"
"
"}}}
