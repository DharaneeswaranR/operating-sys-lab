echo Enter limit
read n
echo pattern
for((i=1; j<=$n; i++))
do
    for((j=1; j<=i; j++))
    do
        echo -n " S "
    done
    echo ""
done