#!/bin/bash

find . -name Makefile | while read mk
do
	name_line=$(grep -E '^\s*NAME\s*=' "$mk")
	if [ -z "$name_line" ]; then
		echo "[DEBUG] No NAME line in $mk" >&2
		continue
	fi

	name=$(echo "$name_line" | cut -d= -f2- | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
	if [ -z "$name" ]; then
		echo "[DEBUG] NAME is empty in $mk" >&2
		continue
	fi

	echo "$(dirname "$mk")/$name" | sed 's|^\./||'
done
