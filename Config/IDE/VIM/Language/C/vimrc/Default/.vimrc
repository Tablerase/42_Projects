"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""               
"                                                                         "
"                                                                         "
"        ▒█░░▒█ ▀█▀ ▒█▀▄▀█     ▒█▀▀█ ▒█▀▀▀█ ▒█▄░▒█ ▒█▀▀▀ ▀█▀ ▒█▀▀█        "
"        ░▒█▒█░ ▒█░ ▒█▒█▒█     ▒█░░░ ▒█░░▒█ ▒█▒█▒█ ▒█▀▀▀ ▒█░ ▒█░▄▄        "
"        ░░▀▄▀░ ▄█▄ ▒█░░▒█     ▒█▄▄█ ▒█▄▄▄█ ▒█░░▀█ ▒█░░░ ▄█▄ ▒█▄▄█        "
"                                                                         "
"                                                                         "
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
Plug 'neoclide/coc.nvim', {'branch': 'release'} " autocomplete
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
set autoindent
" use intelligent indentation for C
set smartindent
" configure tabwidth and insert spaces instead of tabs
set tabstop=4        " tab width is 4 spaces
set shiftwidth=4     " indent also with 4 spaces
set expandtab        " expand tabs to spaces
" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
set textwidth=120
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

" AUTO COMPLETE / Intellisense ---------------------------------------------{{{
"
" https://github.com/neoclide/coc.nvim
" May need for Vim (not Neovim) since coc.nvim calculates byte offset by count
" utf-8 byte sequence (already on)
" set encoding=utf-8
" Some servers have issues with backup files, see #649
set nobackup
set nowritebackup

" Having longer updatetime (default is 4000 ms = 4s) leads to noticeable
" delays and poor user experience
set updatetime=300

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved
set signcolumn=yes

" Use tab for trigger completion with characters ahead and navigate
" NOTE: There's always complete item selected by default, you may want to enable
" no select by `"suggest.noselect": true` in your configuration file
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

" Make <CR> to accept selected completion item or notify coc.nvim to format
" <C-g>u breaks current undo, please make your own choice
inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" Use <c-space> to trigger completion
if has('nvim')
  inoremap <silent><expr> <c-space> coc#refresh()
else
  inoremap <silent><expr> <c-@> coc#refresh()
endif

" Use `[g` and `]g` to navigate diagnostics
" Use `:CocDiagnostics` to get all diagnostics of current buffer in location list
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" GoTo code navigation
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

" Use K to show documentation in preview window
nnoremap <silent> K :call ShowDocumentation()<CR>

function! ShowDocumentation()
  if CocAction('hasProvider', 'hover')
    call CocActionAsync('doHover')
  else
    call feedkeys('K', 'in')
  endif
endfunction

" Highlight the symbol and its references when holding the cursor
autocmd CursorHold * silent call CocActionAsync('highlight')

" Symbol renaming
nmap <leader>rn <Plug>(coc-rename)

" Formatting selected code
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)

augroup mygroup
  autocmd!
  " Setup formatexpr specified filetype(s)
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  " Update signature help on jump placeholder
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" Applying code actions to the selected code block
" Example: `<leader>aap` for current paragraph
xmap <leader>a  <Plug>(coc-codeaction-selected)
nmap <leader>a  <Plug>(coc-codeaction-selected)

" Remap keys for applying code actions at the cursor position
nmap <leader>ac  <Plug>(coc-codeaction-cursor)
" Remap keys for apply code actions affect whole buffer
nmap <leader>as  <Plug>(coc-codeaction-source)
" Apply the most preferred quickfix action to fix diagnostic on the current line
nmap <leader>qf  <Plug>(coc-fix-current)

" Remap keys for applying refactor code actions
nmap <silent> <leader>re <Plug>(coc-codeaction-refactor)
xmap <silent> <leader>r  <Plug>(coc-codeaction-refactor-selected)
nmap <silent> <leader>r  <Plug>(coc-codeaction-refactor-selected)

" Run the Code Lens action on the current line
nmap <leader>cl  <Plug>(coc-codelens-action)

" Map function and class text objects
" NOTE: Requires 'textDocument.documentSymbol' support from the language server
xmap if <Plug>(coc-funcobj-i)
omap if <Plug>(coc-funcobj-i)
xmap af <Plug>(coc-funcobj-a)
omap af <Plug>(coc-funcobj-a)
xmap ic <Plug>(coc-classobj-i)
omap ic <Plug>(coc-classobj-i)
xmap ac <Plug>(coc-classobj-a)
omap ac <Plug>(coc-classobj-a)

" Remap <C-f> and <C-b> to scroll float windows/popups
if has('nvim-0.4.0') || has('patch-8.2.0750')
  nnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  nnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
  inoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(1)\<cr>" : "\<Right>"
  inoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(0)\<cr>" : "\<Left>"
  vnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  vnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
endif

" Use CTRL-S for selections ranges
" Requires 'textDocument/selectionRange' support of language server
nmap <silent> <C-s> <Plug>(coc-range-select)
xmap <silent> <C-s> <Plug>(coc-range-select)

" Add `:Format` command to format current buffer
command! -nargs=0 Format :call CocActionAsync('format')

" Add `:Fold` command to fold current buffer
command! -nargs=? Fold :call     CocAction('fold', <f-args>)

" Add `:OR` command for organize imports of the current buffer
command! -nargs=0 OR   :call     CocActionAsync('runCommand', 'editor.action.organizeImport')

" Add (Neo)Vim's native statusline support
" NOTE: Please see `:h coc-status` for integrations with external plugins that
" provide custom statusline: lightline.vim, vim-airline
set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}

" Mappings for CoCList
" Show all diagnostics
nnoremap <silent><nowait> <space>a  :<C-u>CocList diagnostics<cr>
" Manage extensions
nnoremap <silent><nowait> <space>e  :<C-u>CocList extensions<cr>
" Show commands
nnoremap <silent><nowait> <space>c  :<C-u>CocList commands<cr>
" Find symbol of current document
nnoremap <silent><nowait> <space>o  :<C-u>CocList outline<cr>
" Search workspace symbols
nnoremap <silent><nowait> <space>s  :<C-u>CocList -I symbols<cr>
" Do default action for next item
nnoremap <silent><nowait> <space>j  :<C-u>CocNext<CR>
" Do default action for previous item
nnoremap <silent><nowait> <space>k  :<C-u>CocPrev<CR>
" Resume latest coc list
nnoremap <silent><nowait> <space>p  :<C-u>CocListResume<CR>
"}}}

