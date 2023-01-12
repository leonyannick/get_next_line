#!/bin/zsh
dir=./files/
for file in `ls $dir`
do
 if [ -f $dir/$file ];then
  make test
  echo "diff "$file
  ./a.out $dir$file | diff $dir$file -
  echo "\n"
 fi
done
