# Config [<img src="https://github.com/vim/vim/raw/master/runtime/vimlogo.gif" height="70" alt="vim-plug" align="right">](https://www.vim.org)

In this repository you can share ready to use vim config or nvim config (but if you use nvim, i suggest [nvchad](https://github.com/NvChad/NvChad) - best autoinstall config i have found)

- if possible with auto installation of everything needed to run the config (plugins and sometimes even programs if you go crazy🤓)

## Requierements of `.vimrc`

- Your `.vimrc` files should be commented
- All the config has to be installed automaticaly (only with .vimrc)
  - Even if it add loading time (You can add comment to tell user where to delete, if they want to gain loading speed)
- If you can't install all via `.vimrc` add a `README.md` to explain step by step your setup

## Schema

Try to maintain a config structured between each categories

- Here is an [example](https://github.com/Tablerase/VIM-config/blob/main/vimrc/language/C/.vimrc) :

```vim
" PLUGINS ---------------------------------------------------------------- {{{
call plug#begin('~/.vim/bundle')

" ↓↓↓ Insert your plugins below ↓↓↓

  Plug 'itchyny/lightline.vim' " status bar
  Plug 'catppuccin/vim', { 'as': 'catppuccin' } "color scheme recommended ♥

" ↑↑↑ Insert your plugins above ↑↑↑

call plug#end()
" }}}

" SYNTHAX ---------------------------------------------------------------- {{{

" turn line numbers on
set number

" }}}
```

## Plugins integrations 🧩

[<img src="https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.png" height="30" alt="vim-plug" align="center">](https://github.com/junegunn/vim-plug/tree/master)

- To maintain consistency, use vim plug to auto install plugins inside your vim instance
  - Code to auto install vim-plug inside `.vimrc` :

```vim
  " Install vim-plug if not found
  if empty(glob('~/.vim/autoload/plug.vim'))
    silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
      \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  endif
  " Run PlugInstall if there are missing plugins
  autocmd VimEnter * if len(filter(values(g:plugs), '!isdirectory(v:val.dir)'))
    \| PlugInstall --sync | source $MYVIMRC
  \| endif
```

The plugin directory will be as follows:

- Vim (Linux/macOS): `'~/.vim/bundle'`
- Vim (Windows): `'~/vimfiles/bundle'`
- Neovim (Linux/macOS/Windows): `stdpath('data') . '/bundle'`

You can specify a custom plugin directory by passing it as the argument

- e.g. `call plug#begin('~/.vim/bundle')`
- Avoid using standard Vim directory names like 'plugin'

```vim
  " Exemple For Mac/Linux users
  call plug#begin('~/.vim/bundle')

  " Exemples of plugins to autoinstall
  Plug 'itchyny/lightline.vim'
  Plug 'catppuccin/vim', { 'as': 'catppuccin' } "color scheme recommended ♥
  
  " Initialize plugin system
  " - Automatically executes `filetype plugin indent on` and `syntax enable`.
  call plug#end()
```

## Color Scheme 🎨

I recommend using `Catppuccin` because it has great integrations and updates 

[<img src="https://raw.githubusercontent.com/catppuccin/catppuccin/main/assets/logos/exports/1544x1544_circle.png" height="100" alt="catppuccin" align="right">](https://github.com/catppuccin/vim)
Catppuccin is a community-driven pastel theme that aims to be the middle ground between low and high contrast themes. It consists of 4 soothing warm flavors with 26 eye-candy colors each, perfect for coding, designing, and much more!

<details>
<summary>🌻 Latte</summary>
  <p>In VIM <br/>
    <code>:colorscheme catppuccin_latte</code>
  </p><img src="./Media/colorscheme/catppuccin/latte.svg" alt=latte height="100" align="center">
  <p>
    In .vimrc <br/>
    <code>colorscheme catppuccin_latte</code>
  </p> 
</details>
<details>
<summary>🪴 Frappé</summary>
  <p>In VIM <br/>
    <code>:colorscheme catppuccin_frappe</code>
  </p><img src="./Media/colorscheme/catppuccin/frappe.svg" alt=latte height="100" align="center">
  <p>
    In .vimrc <br/>
    <code>colorscheme catppuccin_frappe</code>
  </p>
</details>
<details>
<summary>🌺 Macchiato</summary>
  <p>In VIM <br/>
    <code>:colorscheme catppuccin_macchiato</code>
  </p><img src="./Media/colorscheme/catppuccin/macchiato.svg" alt=latte height="100" align="center">
  <p>
    In .vimrc <br/>
    <code>colorscheme catppuccin_macchiato</code>
  </p>
</details>
<details>
<summary>🌿 Mocha</summary><p>In VIM <br/>
    <code>:colorscheme catppuccin_mocha</code>
  </p><img src="./Media/colorscheme/catppuccin/mocha.svg" alt=latte height="100" align="center">
  <p>
    In .vimrc <br/>
    <code>colorscheme catppuccin_mocha</code>
  </p>
</details>

Optimize color displayed:

```vim
  " activate True Color - need for some color scheme
  set termguicolors
```

<p align="center"><a href="https://choosealicense.com/licenses/wtfpl/"><img src="https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=WTFPL&logoColor=d9e0ee&colorA=363a4f&colorB=EFF1F3"/></a></p>
