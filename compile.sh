#!/bin/bash

if [[ $# == 0 ]]; then

 echo "Compile All."
 for file in `find . -name "*.c"`
 do
   gcc $file -o ${file%.*}
 done

else
 for file in "$@"
 do
  file="hw${file}.c"
  if [[ -f "$file" ]]; then
   echo "Compiling file: $file"
   gcc $file -o ${file%.*}
  else
   echo "$file not exists."
  fi
 done
fi
