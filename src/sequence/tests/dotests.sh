#!/bin/sh

out=blablalalalal
good=../goodout

for i in good*; do 
  ../sequence < $i >> $out
done 
diff $out $good
rm $out
