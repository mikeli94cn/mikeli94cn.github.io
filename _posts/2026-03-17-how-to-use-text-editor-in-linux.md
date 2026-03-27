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


## emacs
