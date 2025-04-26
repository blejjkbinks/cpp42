#!/bin/bash

echo -n > making

find . -type f -name Makefile | while read makefile; do
	dirname=$(dirname "$makefile")
	echo "Running fclean in: $dirname"
	if ! make -C "$dirname" re; then
		echo "$dirname" >> making
	fi
	make -C "$dirname" fclean
done
