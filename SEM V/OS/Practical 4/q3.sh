echo "Enter file1 path"
read file1
echo "Enter file2 path"
read file2

if cmp $file1 $file2
then
   echo "The files match so deleting $file2"
   rm $file2
else
   echo "The files are different"
fi
