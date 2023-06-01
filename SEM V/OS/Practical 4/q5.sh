for i in $@
do
    if [ -d $i ]
    then
        echo "In directory $i"
        cd $i
        for d in *
        do
            if [ -d $d ]
            then
                echo -n "$d : "
                ls $d -A | wc -l
            fi
        done
        cd ..
    else
        echo "$i is not a directory"
    fi
    echo
done