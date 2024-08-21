
#!/usr/bin/bash

check_path(){
	local path=$1

	if [ -z "$path" ]; then
		echo "No path provided"
		exit 1
	fi

	if [ -e "$path" ]; then
		if [ -d "$path" ]; then
			cd "$path"
			mkdir src bin include images
			ls -la
		elif [ -f "$path" ]; then
			echo "It is a file"
		fi
	else
		echo "Path does not exist"
	fi
}


if [ $# -eq 0 ]; then 
	echo "usage: $0 <path>"
	exit 1
fi

check_path "$1"
