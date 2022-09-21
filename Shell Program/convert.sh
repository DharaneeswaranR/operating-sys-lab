for i in *
do
    echo Before
    echo $i
    j=`echo $i | tr "[a-z]" "[A-Z]"`
    echo After
    echo $j
done