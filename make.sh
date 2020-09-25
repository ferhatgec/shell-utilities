#!/bin/sh

# Build latest example.

# Change dir.
cd example

# Change directory with latest folder.
cd `ls -t1 | head -n 1`


# Build and run it.
sh make.sh && ./shell
