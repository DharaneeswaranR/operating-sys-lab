echo 1.Add 2.Sub 3.Mul 4.Div
echo Oppr
read o
echo Enter a
read a
echo Enter b
read b
case $o in
"1")echo "$a + $b = `expr $a + $b`";;
"2")echo "$a - $b = `expr $a - $b`";;
"3")echo "$a * $b = `expr $a \* $b`";;
"4")echo "$a / $b = `expr $a / $b`";;
esac