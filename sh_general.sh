#!/bin/bash
rm tags
rm cscope.* 

ctags -R .
find ./ -iname "*.cpp" > cscope.files
find ./ -iname [ch] >> cscope.files

cscope -Rkbqi cscope.files

