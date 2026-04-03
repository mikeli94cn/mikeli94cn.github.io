# how to use text editor in linux
## vim
### how to copy from vim to linux clipboard

### how to paste from linux clipboard to vim

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

### how to install vim-plug


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

### how to configure coc-nvim for java



### how to configure coc-nvim for c/c++

### how to use fzf.vim

### vim text manipulate stratey
vim select lines match patterns

Vim doesn't have a single command to "highlight" non-contiguous lines in Visual mode, but you can "select" them for an operation: 

Delete all lines matching "pattern":

:g/pattern/d

Keep only lines matching "pattern" (delete everything else):

:v/pattern/d or :g!/pattern/d


pattern match date time

This is the most common format for logs and databases. 

Standard (grep -E): [0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}

Vim (Search): /\d\{4}-\d\{2}-\d\{2} \d\{2}:\d\{2}:\d\{2}

## emacs

## miscellecious
how to search text in multiple files in linux
Searching for text in multiple files is a standard task in Linux, primarily handled by the grep command or faster modern alternatives like ripgrep. [1, 2, 3] 
## 1. Using grep (The Standard Way)
The grep utility is pre-installed on almost every Linux system. [4, 5] 

* Search in current directory (no subfolders):

grep "search_term" *

* Search recursively (including subfolders):

grep -r "search_term" /path/to/directory

* Search only specific file types (e.g., .txt files):

grep -r --include="*.txt" "search_term" .

[2, 6, 7, 8, 9] 

Essential Flags:

* -i: Case-insensitive search (matches "Error", "error", and "ERROR").
* -n: Show the line number where the match was found.
* -l: Only list the names of files that contain the text.
* -w: Match only whole words (won't match "rooted" if you search for "root"). [2, 4, 6, 10, 11, 12] 

## 2. Using ripgrep (The Faster Way) [2, 13] 
ripgrep (command rg) is a modern, much faster alternative. It automatically respects your .gitignore and skips hidden files by default. [2, 14, 15, 16] 

* Recursive search (default behavior):

rg "search_term"

* Search specific file types:

rg -t py "search_term"  # Only search Python files

[2, 17, 18] 

## 3. Combining find and grep (For Advanced Filtering) [19, 20] 
If you need to filter files by properties like size or modification date before searching the text inside them, use find. [21] 

* Search only in files larger than 1MB:

find . -type f -size +1M -exec grep -l "search_term" {} +

* Search only in files modified in the last 7 days:

find . -type f -mtime -7 -exec grep "search_term" {} +

[2, 22, 23] 
