#!/bin/bash

# Home dir used with Android Studio
storage="sgoinfre"
usage="goinfre"

folders=(
	".android"
	"Android"
	".gradle"
)

display_help() {
	echo "Android Studio at 42 School requieres too much space to be installed so here is"
	echo "a script to setup symbolic link of Android Studio default install locations"
	echo "to location defined in script. You should store your folders at the end of your working session."
	echo 
	echo "Usage: $0 [option...] {init|save}"
	echo
	echo "-h/--help	Display this msg"
	echo "--init		Setup android studio in $usage and exit"
	echo "--save		Move android studio needed files into $storage"
	echo "				made with <3 by Tablerase"
	exit 1
}

init() {
	echo "======= Initialising Android Studio within $usage ======="
	echo "======= Checking in $storage android studio saved data... ======="
	for folder in "${folders[@]}"; do
		if [ -d "$HOME/$storage/$folder" ]; then
			echo "$HOME/$storage/$folder found"
		else
			echo "$HOME/$storage/$folder not found"
			mkdir -p $HOME/$storage/$folder
			if [ $? -eq 0 ]; then
				echo "$HOME/$storage/$folder created"
			else
				echo "Failed to create $HOME/$storage/$folder"
				exit 1
			fi
		fi
	done

	echo "======= Setting up symbolink links... ======="
	for folder in "${folders[@]}"; do
		if [ -L "$HOME/$folder" ]; then
			target=$(readlink "$HOME/$folder")
			echo "$folder symbolic link found pointing to: $target"
			if [ $target == "$HOME/$usage/$folder" ]; then
				echo "symbolic link valid"
				continue
			else
				echo "symbolic link invalid"
				rm $HOME/$folder
				if [ $? -ne 0 ]; then
					echo "Failed to remove invalid link $HOME/$folder -> $target"
					exit 1
				fi
			fi
		fi

		echo "$folder symbolic link not found or misconfigured"
		ln -s $HOME/$usage/$folder $HOME/$folder
		if [ $? -eq 0 ]; then
			echo "$folder symbolic link created"
		else
			echo "$folder symbolic link failed to be created"
			exit 1
		fi
	done

	echo "======= Moving saved data into $usage... ======="
	for folder in "${folders[@]}"; do
		cp -r $HOME/$storage/$folder $HOME/$usage/$folder
		if [ $? -eq 0 ]; then
			echo "$folder moved successfully"
		else
			echo "$folder failed to move"
			exit 1
		fi
	done
}

save() {
	echo "======= Saving Android Studio files into $storage... ======="
	for folder in "${folders[@]}"; do
		cp -r $HOME/$usage/$folder $HOME/$storage/$folder
		if [ $? -eq 0 ]; then
			echo "$folder stored successfully"
		else
			echo "$folder failed to be stored"
			exit 1
		fi
	done
}

wip() {
	echo "Test..."
}

if [ $# -eq 0 ]; then
	display_help
fi

while [[ $# -gt 0 ]];do
	key="$1"
	case $key in
		--test)
			wip	
			;;
		--help)
			display_help
			;;
		--init)
			init
			shift
			;;
		--save)
			save
			shift
			;;
		*)
			echo "Unknown option $key"
			shift
			;;

	esac
	shift
done

