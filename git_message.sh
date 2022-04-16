#!/bin/bash

git status
echo ">> git status before add"

git add .
echo ">> after git add"

git status
echo ">> git status after add"

COMMIT_MESSAGE=${1}
git commit -m "${COMMIT_MESSAGE}"
echo ">> success commit"

git push
echo ">> success push"
