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
INCLUDES_ALL=$(find ./src/*.h -name "*.h" 2>/dev/null | sed 's/\.h/\.h\\/g')" "
INCLUDES_ALL+=$(find . -name "*.h" | grep "module" | sed 's/\.h/\.h\\/g')
# initialized with srcs at the root of src subfolder. (last command adds a line break (\) at the end of each name)
SRC_NOPREFIX_ALL=$(find ./src/*.c -name "*.c" | sed 's/\.c/\.c\\/g')
# all the folders and subfolders of user defined libraries included in this project
# find all those subfolders of src where a Makefile is present at the root. Then take this folder as well as all subfolders (except hidden ones),
# remove the './' at the beginning, and separate each name with a new line
USR_LIBS_DIRS=$(find $(find ./src -name "Makefile" | sed 's/\/Makefile//') -type d -not -path "*/.*" 2>/dev/null | sed 's/\.\///' | sed 's/ /\\n/')
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
			SRC_NOPREFIX_ALL+=" "$(find ./"$dir"/*.c -name "*c" 2>/dev/null | sed 's/\.c/\.c\\/g')
			INCLUDES_ALL+=" "$(find ./"$dir"/*.h -name "*h" 2>/dev/null | sed 's/\.h/\.h\\/g')
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

#TODO per aggiornare l'header:           date +%F | sed 's/-/\//g'
#TODO 43 max len of file name
#TODO 9 max len of user name $USER
# HEADER_CHARS_PER_LINE=80
# for (( i=1; i<=$N; i++ ))
# 	do
# 		for (( j=1; j<=$N; j++ ))
# 			do
# 				if [[ $i = 4 ]]
# 			done
# 	done
# making Makefile
echo "# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    header.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earendil <earendil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:06:19 by earendil          #+#    #+#              #
#    Updated: 2022/10/25 19:06:21 by earendil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
" > $BACKUP_FILE

echo $INCLUDES_ALL | tr -s '[:blank:]' '\n' > includes_backup_file
echo $SRC_NOPREFIX_ALL | tr -s '[:blank:]' '\n' > srcs_backup_file

SRC_NOPREFIX=$(cat srcs_backup_file | grep -v "_bonus.c")
SRC_NOPREFIX_BONUS=$SRC_NOPREFIX_ALL

INCLUDES=$(cat includes_backup_file | grep -v "_bonus.h")
INCLUDES_BONUS=$INCLUDES_ALL

put "INCLUDES=\\" $INCLUDES $BACKUP_FILE
put "SRC_NOPREFIX=\\" $SRC_NOPREFIX $BACKUP_FILE
put "INCLUDES_BONUS=\\" $INCLUDES_BONUS $BACKUP_FILE
put "SRC_NOPREFIX_BONUS=\\" $SRC_NOPREFIX_BONUS $BACKUP_FILE

put "USR_LIBS=\\" $USR_LIBS $BACKUP_FILE
echo 'SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")' >> $BACKUP_FILE && echo >> $BACKUP_FILE
echo "LIBS_FLAGS="$LIBS_FLAGS >> $BACKUP_FILE && echo >> $BACKUP_FILE

#		copying Makefile operations to backup file
awk "NR >= $MAKEFILE_OPS_BEGIN { print }" < $MAKEFILE >> $BACKUP_FILE

mv $BACKUP_FILE $MAKEFILE
$RM $BACKUP_FILE
$RM includes_backup_file
$RM srcs_backup_file