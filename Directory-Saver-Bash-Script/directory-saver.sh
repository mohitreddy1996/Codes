#!/bin/bash
dir_found=false
current_file_name="$1"
while IFS='' read -r line || [ -n "$line" ] && [ $dir_found == false ]; do
	directories=$(echo $line | tr "::" "\n")
	counter=0
	for addr in $directories
	do
		if [ "$counter" -eq 0 ]; then
			competition=`echo "$addr" | tr -d '/'` 
			counter=$[$counter + 1]
			dir_found=true
		else
			filename=`echo "$addr"`
			counter=$[$counter + 1]
		fi
	done
done < $current_file_name
if [ $dir_found == true ]; then
	echo $filename $competition
	directory_file_name=$competition"/"$filename
	if [ -f $directory_file_name ]; then
		echo "filename already exists!"
		`rm $directory_file_name`
	fi
	`cat $current_file_name >> $directory_file_name`
fi