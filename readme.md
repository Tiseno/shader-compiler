# shader-compiler

Compiles glsl shaders and reports errors. Uses glew and glfw as that is what I was using at the moment of writing this. Performs a bunch of unnecessary stuff before actually compiling the shaders.

# Usage

Install glew and glfw.

```
make
./shader-compiler.out example-shaders/a.frag
```

This was created for nvim and neomake.

## Filetype

To detect shaders we need to declare a new filetype for vim.

Create the file `~/.config/nvim/filetype.vim` with the following content:

```
if exists("did_load_filetypes")
  finish
endif
augroup filetypedetect
  au! BufRead,BufNewFile *.frag     setfiletype shader
  au! BufRead,BufNewFile *.vert     setfiletype shader
  au! BufRead,BufNewFile *.fragment setfiletype shader
  au! BufRead,BufNewFile *.vertex   setfiletype shader
augroup END
```

This will set the filetype to 'shader' when loading these file endings.

## Neomake

In your vimrc or equivalent:

```
"shader here can be an arbitrary filetype name
"shadercompiler is an arbitrary name linking the filetype to the job
let g:neomake_shader_shadercompiler_maker = {
    \ 'exe': '<path_to_the_built_shader_compiler_binary>/shader-compiler.out',
    \ 'args': [],
    \ 'errorformat': '%f 0:%l(%c): %trror: %m',
    \ }
let g:neomake_shader_enabled_makers = ['shadercompiler']
```

# Disclaimer

I don't really know what i'm doing.

For more info `:help new-filetype`, `:help neomake-configuration`, and `:help errorformat`.

