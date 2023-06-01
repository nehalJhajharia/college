echo "Enter file path"
read path
echo "Enter word"
read word
sed -ie "/$word/d" $path