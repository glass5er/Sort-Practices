#!/bin/bash

APPROOT=$(cd $(dirname $0); pwd)


test_func() {
  REFERENCE="$APPROOT/reference.txt"
  QUERY="$APPROOT/result.txt"

  BINARY="$APPROOT/../bin_sort"
  SCRIPT="$APPROOT/genvect.rb"
  INPUT="$APPROOT/../dataset$1.csv"

  dataNum=$2
  startNum=$3
  rangeNum=$4

  ruby $SCRIPT \
    --dataNum $dataNum \
    --startNum $startNum \
    --rangenum $rangeNum \
    --fileVect $REFERENCE
  $BINARY -i $REFERENCE -mode -1 > $QUERY

  ##  compare query with reference  ##
  diff -q $REFERENCE $QUERY
  if [ $? -eq 0 ]; then
    echo "Test $1 PASS"
  else
    echo "Test $1 !!!NG!!!"
    exit
  fi
  rm $REFERENCE $QUERY
}

for testNo in $(seq -f "%02g" 1 3); do
  test_func $testNo 500 1 10000
done
