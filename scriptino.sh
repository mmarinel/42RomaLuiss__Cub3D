

# penultimate cmd removes ./ at the beginning of each file
SRC_NOPREFIX=$(find . -name "*.c" -print | sed 's/\.\///' | sed 's/\.c/\.c\\/g')
# penultimate cmd removes ./ at the beginning of each file
SRC_SUBDIRS=$(find ./src/* -type d -not -path "*/.*" | sed 's/\.\///')

SRC=$(find ./src/*.c -name "*.c")

for dir in $SRC_SUBDIRS
	do
		if [[ -f "$dir"/Makefile ]]
		then
			echo "found Makefile in "$dir;
			SRSC_IGNORES+=$(find $dir -name "*c")
		else
			SRC+=" "$(find $dir/*.c -name "*c" 2>/dev/null)
		fi
	done

# newline_separated=${SRC_NOPREFIX// /$'\n'}

# echo $newline_separated
echo $SRC_NOPREFIX > fil1
echo $SRC_IGNORES > fil2

# sort -o fil1 fil1
# sort -o fil2 fil2

# echo "ignored src "$SRSC_IGNORES
# echo "no prefix src "$SRC_NOPREFIX
echo "real sources "$SRC