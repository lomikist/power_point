let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Desktop/repos/power_point
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 ~/Desktop/repos/power_point/CLI/inc/parser.hpp
badd +1 ~/Desktop/repos/power_point/CLI/src/factory/add_shape_command.cpp
badd +5 ~/Desktop/repos/power_point/controller/inc/controller.hpp
badd +8 ~/Desktop/repos/power_point/cli/src/parser.cpp
badd +2 ~/Desktop/repos/power_point/cli/inc/parser.hpp
badd +1 ~/Desktop/repos/power_point/CMakeLists.txt
badd +1 ~/Desktop/repos/power_point/model/inc/model.hpp
badd +1 ~/Desktop/repos/power_point/model/inc/factory/circle_shape.hpp
badd +7 ~/Desktop/repos/power_point/model/inc/factory/shape_factory.hpp
badd +2 ~/Desktop/repos/power_point/model/inc/factory/shape.hpp
badd +1 ~/Desktop/repos/power_point/model/inc/factory/rect_shape.hpp
argglobal
%argdel
edit ~/Desktop/repos/power_point/model/inc/factory/shape_factory.hpp
argglobal
balt ~/Desktop/repos/power_point/model/inc/factory/circle_shape.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 7 - ((6 * winheight(0) + 17) / 35)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 7
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
