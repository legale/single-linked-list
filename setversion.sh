#!/bin/bash
# version changing script
NAME=single-linked-list
VERSION=0.1.1

FROM="$NAME v[0-9]{1,2}.[0-9]{1,2}.[0-9]{1,2}"
TO="$NAME v$VERSION"

sed -ri "s#$FROM#$TO#" *.c
sed -ri "s#$FROM#$TO#" *.h
sed -ri "s#$FROM#$TO#" README.md
echo $VERSION