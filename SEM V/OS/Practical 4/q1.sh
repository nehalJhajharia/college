#!/bin/bash

echo "Enter file path"
read path
echo "Enter starting line"
read start
echo "Enter ending line"
read end
sed -n $start,$end\p $path