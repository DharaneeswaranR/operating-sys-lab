echo 1.Add 2.Sub 3.Mul 4.Div
echo "Enter the operator"
read o
echo "Enter the operands"
read a
read b
case $o in
"1")echo "$a + $b = `expr $a + $b`";;
"2")echo "$a - $b = `expr $a - $b`";;
"3")echo "$a * $b = `expr $a \* $b`";;
"4")echo "$a / $b = `expr $a / $b`";;
* ) echo " Inavlid Operation"
esac