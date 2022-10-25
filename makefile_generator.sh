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

# last cmd adds a '\' (i.e.: line break) at the end of each obj file name
INCLUDES=$(find . -name "*.h" -print | sed 's/\.h/\.h\\/g');
# penultimate cmd removes ./ at the beginning of each file
OBJS_NOPREFIX=$(find . -name "*.c" -print | sed 's/\.c/\.o/g' | sed 's/\.\///' | sed 's/\.c/\.c\\/g')

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
put "OBJS_NOPREFIX=\\" $OBJS_NOPREFIX $BACKUP_FILE
awk "NR >= $MAKEFILE_OPS_BEGIN { print }" < $MAKEFILE >> $BACKUP_FILE

mv $BACKUP_FILE $MAKEFILE
$RM $BACKUP_FILE