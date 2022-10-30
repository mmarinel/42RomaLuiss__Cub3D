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
INCLUDES=$(find ./*.h -name "*.h" | sed 's/\.h/\.h\\/g')
# initialized with srcs at the root of src subfolder
SRC_NOPREFIX=$(find ./*.c -name "*.c" | sed 's/\.c/\.c\\/g')
# penultimate cmd removes ./ at the beginning of each file
SRC_SUBDIRS=$(find ./* -type d -not -path "*/.*" | sed 's/\.\///')
# taking all project specific (no library) srcs
for dir in $SRC_SUBDIRS
	do
		# if a Makefile is present, it means the sources in this library refer to an external library
		if [[ ! -f "$dir"/Makefile ]]
		then
			# we need a redirection to stderr in the case this folder does not contain srcs per se, but just subfolders of srcs
			SRC_NOPREFIX+=" "$(find ./"$dir"/*.c -name "*c" 2>/dev/null | sed 's/\.c/\.c\\/g')
			INCLUDES+=" "$(find ./"$dir"/*.h -name "*h" 2>/dev/null | sed 's/\.h/\.h\\/g')
		else
			#there must be sources if there is a Makefile....so no redirection of stderr to /dev/null here...
			###		take only the first occurrence of the word 'NAME', split it on the '=',
			###		remove the lib part and the extension (.a) part, and finally remove any space
			LIBS_FLAGS+="-L./"$dir" -l"$(cat ./$dir/Makefile | grep -m1 "NAME" | awk -F "=" '{ print $2}' | sed 's/lib//' | sed 's/\.a//g' | sed 's/ //g')" "
			USR_LIBS+="$dir""\ "
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
put "INCLUDES=\\" $INCLUDES $BACKUP_FILE
put "SRC_NOPREFIX=\\" $SRC_NOPREFIX $BACKUP_FILE

put "USR_LIBS=\\" $USR_LIBS $BACKUP_FILE
echo 'SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")' >> $BACKUP_FILE && echo >> $BACKUP_FILE
echo "LIBS_FLAGS="$LIBS_FLAGS >> $BACKUP_FILE && echo >> $BACKUP_FILE

#		copying Makefile operations to backup file
awk "NR >= $MAKEFILE_OPS_BEGIN { print }" < $MAKEFILE >> $BACKUP_FILE

mv $BACKUP_FILE $MAKEFILE
$RM $BACKUP_FILE