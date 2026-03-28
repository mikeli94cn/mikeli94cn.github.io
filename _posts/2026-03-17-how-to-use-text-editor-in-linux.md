# how to use text editor in linux
## vim
### remove YouCompleteMe
To remove **YouCompleteMe** from your Vim setup, the steps depend on how you installed it (most likely via **vim-plug** or **Vundle**).

---

 ✅ Step 1: Remove from `.vimrc`

Open your config:

```bash
vim ~/.vimrc
```

Find and **delete or comment out** the line:

or (Vundle):

```vim
Plugin 'ycm-core/YouCompleteMe'
```

---

 ✅ Step 2: Remove plugin files


 If using Vundle:

```bash
rm -rf ~/.vim/bundle/YouCompleteMe
```

---

 ✅ Step 3: Remove compiled files (important ⚠️)

YouCompleteMe installs compiled binaries. Clean them:

```bash
rm -rf ~/.vim/bundle/YouCompleteMe
```

---

 ✅ Step 4: Optional cleanup (recommended)

Remove extra config (if you added any):

```vim
" Delete lines like:
let g:ycm_*
```

---

 ✅ Step 5: Restart Vim

```bash
vim
```

---

 👍 Quick Summary

| Step | Action                            |
| ---- | --------------------------------- |
| 1    | Remove from `.vimrc`              |
| 2    | Run `:PlugClean` or delete folder |
| 3    | Remove compiled files             |
| 4    | Restart Vim                       |

---
### how to remove vundle
To remove **Vundle** from Ubuntu (or any Linux), you just need to clean up your Vim config and delete its files.

---

✅ Step 1: Remove Vundle from `.vimrc`

Open your config:

```bash
vim ~/.vimrc
```

Delete or comment out these lines:

```vim
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" Plugin lines...

call vundle#end()
filetype plugin indent on
```

👉 Also remove any `Plugin '...'` lines

---

✅ Step 2: Delete Vundle directory

```bash
rm -rf ~/.vim/bundle/Vundle.vim
```

---

✅ Step 3: Remove all Vundle-installed plugins (optional)

If you want a clean slate:

```bash
rm -rf ~/.vim/bundle
```

---



👍 Quick Summary

| Step | Action                     |
| ---- | -------------------------- |
| 1    | Edit `.vimrc`              |
| 2    | Delete `Vundle.vim` folder |
| 3    | Remove plugins (optional)  |
| 4    | Restart Vim                |

---
## how to install coc-nvim
To install **coc.nvim** (Conquer of Completion) in Vim, follow these steps carefully. It provides modern IDE-like features such as auto-completion, linting, and language support.

---

 ✅ Step 0: Install Node.js (required ⚠️)

`coc.nvim` depends on Node.js.

```bash
sudo apt update
sudo apt install nodejs npm
```

Check:

```bash
node -v
npm -v
```

---

 ✅ Step 1: Install via vim-plug (recommended)

If you’re using **vim-plug**, open your config:

```bash
vim ~/.vimrc
```

Add:

```vim
call plug#begin('~/.vim/plugged')

Plug 'neoclide/coc.nvim', {'branch': 'release'}

call plug#end()
```

---

 ✅ Step 2: Install the plugin

Open Vim and run:

```vim
:PlugInstall
```

---

 ✅ Step 3: Basic configuration (important)

Add this to your `.vimrc`:

```vim
" Better completion behavior
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ "\<TAB>"

inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

" Use Enter to confirm completion
inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<CR>"
```

---

 ✅ Step 4: Install language extensions

Inside Vim:

```vim
:CocInstall coc-json coc-tsserver coc-clangd coc-pyright
```

👉 Examples:

* `coc-clangd` → C/C++
* `coc-pyright` → Python
* `coc-tsserver` → JavaScript/TypeScript

---

 ✅ Step 5: Verify installation

Open a code file and:

* Start typing → auto-completion should appear
* Run:

```vim
:CocInfo
```

---

 ✅ Optional: Useful commands

| Command               | Description        |
| --------------------- | ------------------ |
| `:CocInstall`         | install extensions |
| `:CocUpdate`          | update coc.nvim    |
| `:CocList extensions` | list installed     |
| `gd`                  | go to definition   |
| `K`                   | show documentation |

---


 👍 Summary

1. Install Node.js
2. Add plugin via vim-plug
3. Run `:PlugInstall`
4. Install extensions
5. Enjoy IDE features 🎉


## emacs
