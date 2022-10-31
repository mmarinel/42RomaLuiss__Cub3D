#! /bin/bash

#	author:			mmarinel
#	date:			25/10/2022
#	organisation:	42RomaLuiss

if [[ $# -ne 0 ]]
then
	echo "illegal number of arguments (0 expected)" >&2;
	exit 1;
fi

#	This function puts a series of strings in a file.
#
#	usage:	put("Hello", "42RomaLuiss", filetto.txt)
#			put("Hello", "People", "Of the Earth", filetto.txt)
#			...
put () {
	# get last argument passed to function (which should be the file name)
	for file_name in $@; do :; done;

	for string in $@
		do
			if [[ "$string" = "$file_name" ]]
			then
				echo >> $file_name;
			else
				echo $string >> $file_name;
			fi
		done
}

RM="rm -rf"
MAKEFILE_OPS_BEGIN=$(grep -n -m1 CC Makefile | awk -F ":" '{ print $1 }')

MAKEFILE=Makefile;
BACKUP_FILE="$MAKEFILE".copy;

# initialized with headers at the root of src subfolder. (last command adds a line break (\) at the end of each name)
INCLUDES=$(find ./src/*.h -name "*.h" 2>/dev/null | sed 's/\.h/\.h\\/g')
# initialized with srcs at the root of src subfolder. (last command adds a line break (\) at the end of each name)
SRC_NOPREFIX=$(find ./src/*.c -name "*.c" | sed 's/\.c/\.c\\/g')
# all the folders and subfolders of user defined libraries included in this project
# find all those subfolders of src where a Makefile is present at the root. Then take this folder as well as all subfolders (except hidden ones),
# remove the './' at the beginning, and separate each name with a new line
USR_LIBS_DIRS=$( find $(find ./src -name "Makefile" | sed 's/\/Makefile//') -type d -not -path "*/.*"  | sed 's/\.\///' | sed 's/ /\\n/')
# all of the subfolders of the src folder which are not part of a user library. (last cmd removes ./ at the beginning of each file)
SRC_SUBDIRS=$(find ./src/* -type d -not -path "*/.*" | sed 's/\.\///')
put $USR_LIBS_DIRS .usr_libs_dirs
put $SRC_SUBDIRS .src_subdirs
sort -o .usr_libs_dirs .usr_libs_dirs
sort -o .src_subdirs .src_subdirs
SRC_SUBDIRS=$(comm -23 .src_subdirs .usr_libs_dirs)
$RM .src_subdirs .usr_libs_dirs

# taking all project specific (no library) srcs
for dir in $SRC_SUBDIRS
	do
			# we need a redirection to stderr in the case this folder does not contain srcs per se, but just subfolders of srcs
			SRC_NOPREFIX+=" "$(find ./"$dir"/*.c -name "*c" 2>/dev/null | sed 's/\.c/\.c\\/g')
			INCLUDES+=" "$(find ./"$dir"/*.h -name "*h" 2>/dev/null | sed 's/\.h/\.h\\/g')
	done


# taking all user library srcs
for dir in $USR_LIBS_DIRS
	do
		if [[ -f "$dir"/Makefile ]]
		then
			###		take only the first occurrence of the word 'NAME' inside the found Makefile,
			###		split it on the '=', remove the 'lib' prefix and the extension (.a) part,
			###		...and finally remove any space (that may be at the beginning of the name string)
			LIBS_FLAGS+="-L./"$dir" -l"$(cat ./$dir/Makefile | grep -m1 "NAME" | awk -F "=" '{ print $2}' | sed 's/lib//' | sed 's/\.a//g' | sed 's/ //g')" "
			USR_LIBS+="$dir""\ "
		fi
	done

echo $LIBS_FLAGS $USR_LIBS
echo "............................................."
put $SRC_NOPREFIX .bo
cat .bo
rm -rf .bo