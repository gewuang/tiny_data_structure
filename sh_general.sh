#!/bin/bash
rm tags
rm cscope.* 

ctags -R .
find ./ -iname "*.*" > cscope.files

cscope -Rkbqi cscope.files

