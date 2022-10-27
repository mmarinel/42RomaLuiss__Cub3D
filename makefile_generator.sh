#! /bin/bash

#	author:			mmarinel
#	date:			25/10/2022
#	organisation:	42RomaLuiss

if [[ $# -ne 0 ]]
then
	echo "illegal number of arguments (0 expected)" >&2;
	exit 1;
fi

RM="rm -rf"
MAKEFILE_OPS_BEGIN=$(grep -n -m1 CC Makefile | awk -F ":" '{ print $1 }')

MAKEFILE=Makefile;
BACKUP_FILE="$MAKEFILE".copy;

# initialized with headers at the root of src subfolder
INCLUDES=$(find ./src/*.h -name "*.h" | sed 's/\.h/\.h\\/g')
# initialized with srcs at the root of src subfolder
SRC_NOPREFIX=$(find ./src/*.c -name "*.c" | sed 's/\.c/\.c\\/g')
# penultimate cmd removes ./ at the beginning of each file
SRC_SUBDIRS=$(find ./src/* -type d -not -path "*/.*" | sed 's/\.\///')
# taking all project specific (no library) srcs
for dir in $SRC_SUBDIRS
	do
		# if a Makefile is present, it means the sources in this library refer to an external library
		if [[ ! -f "$dir"/Makefile ]]
		then
			# we need a redirection to stderr in the case this folder does not contain srcs per se, but just subfolders of srcs
			SRC_NOPREFIX+=" "$(find ./"$dir"/*.c -name "*c" 2>/dev/null | sed 's/\.c/\.c\\/g')
			INCLUDES+=" "$(find ./"$dir"/*.h -name "*h" 2>/dev/null | sed 's/\.h/\.h\\/g')
		fi
	done

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
put "INCLUDES=\\" $INCLUDES $BACKUP_FILE
put "SRC_NOPREFIX=\\" $SRC_NOPREFIX $BACKUP_FILE
awk "NR >= $MAKEFILE_OPS_BEGIN { print }" < $MAKEFILE >> $BACKUP_FILE

mv $BACKUP_FILE $MAKEFILE
$RM $BACKUP_FILE