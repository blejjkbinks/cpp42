#!/bin/bash

find . -type f -name Makefile | while read makefile; do
	dirname=$(dirname "$makefile")
	echo "Running fclean in: $dirname"
	make -C "$dirname" fclean
done