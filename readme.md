# shader-compiler

Compiles glsl shaders and reports errors. Uses glew and glfw as that is what I was using at the moment of writing this. Performs a bunch of unnecessary stuff before actually compiling the shaders.

# Usage

Install glew and glfw, on ubuntu
```
sudo apt install libglfw3-dev libglew-dev
```
then
```
make
```
and then you can run it
```
./shader-compiler.out example-shaders/a.frag
```

This was created for nvim and neomake.

## Filetype

If you are using some other plugin for shaders/syntax, check if it sets the filetype to something else by going to a shader file and rrunning `:set filetype`. If it says something unrelated to shaders, like 'config', you need to set your own filetype, otherwise you can skip this step and use the filetype name to set up our neomake maker. 'tikhomirov/vim-glsl' will set the filetype to 'glsl' which is fine.

Otherwise create the file `~/.config/nvim/filetype.vim` with the following content:

```
if exists("did_load_filetypes")
  finish
endif
augroup filetypedetect
  au! BufRead,BufNewFile *.vert     setfiletype glsl
  au! BufRead,BufNewFile *.tesc     setfiletype glsl
  au! BufRead,BufNewFile *.tese     setfiletype glsl
  au! BufRead,BufNewFile *.geom     setfiletype glsl
  au! BufRead,BufNewFile *.frag     setfiletype glsl
  au! BufRead,BufNewFile *.comp     setfiletype glsl
augroup END
```

This will set the filetype to 'glsl' when loading these file endings.

## Neomake

In your vimrc or equivalent specify a neomake maker with the path to the shader-compiler:

```
"glsl here can be an arbitrary filetype name
"shadercompiler is an arbitrary name linking the filetype to the job
let g:neomake_glsl_shadercompiler_maker = {
    \ 'exe': '<path_to_the_built_shader_compiler_binary>/shader-compiler.out',
    \ 'args': [],
    \ 'errorformat': '%f 0:%l(%c): %trror: %m',
    \ }
let g:neomake_glsl_enabled_makers = ['shadercompiler']
```

# Disclaimer

I don't really know what I'm doing.

For more info `:help new-filetype`, `:help neomake-configuration`, and `:help errorformat`.

