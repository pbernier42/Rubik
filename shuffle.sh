if [ $1 ]; then
	side_list=(F R U B L D)
	modifier_list=(2 \')
	last=$(echo $(($1-1)))
	for (( count=0; count < $1; count++ )); do
		side=${side_list[$((RANDOM*6/32767))]}
		mod_random=$((RANDOM*3/32767))
		[ "$mod_random" -ne "$(echo $((3)))" ] && modifier=${modifier_list[$mod_random]} || modifier=""
		printf $side$modifier
		[ "$count" -eq "$last" ] && printf '\n' || printf ' '
	done
fi
