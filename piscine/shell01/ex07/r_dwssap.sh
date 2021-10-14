cat /etc/passwd | grep -v '^#' | cut -d ':' -f1 | awk 'NR%2==0' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed -e 's/$/,/' -e '$s/,$/./' | xargs | tr -d '\n'
