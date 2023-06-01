echo "Enter Input extension for files"
read ext
for f in *.${ext}
do 
	echo "Enter the prefix to be appended(press enter for $(date +%F))"
	read pre
	
	echo "Old name=$f"
	if [ -z ${pre} ]
	then 
		echo "New name=$(date +%F)-$f"
		mv $f "$(date +%F)-$f"
	else
		echo "New name=$pre-$f"
		mv $f "$pre-$f"
	fi
done
