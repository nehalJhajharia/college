declare -i count=0
echo "Enter path"
read i
if [ -d $i ]
then 
	for j in `find $i/* -type f -executable `
	do 
		(( count++ ))
	done
fi
echo "Number of executable files is $count"
