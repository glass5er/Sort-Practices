#!/bin/bash

APPROOT=$(cd $(dirname $0); pwd)

test_func() {
  REFERENCE="$APPROOT/reference.txt"
  QUERY="$APPROOT/result.txt"

  BINARY="$APPROOT/../bin_sort"
  SCRIPT="$APPROOT/genvect.rb"

  testNo=$1
  testPattern=$2
  dataNum=$3
  startNum=$4
  rangeNum=$5

  ruby $SCRIPT \
    --dataNum $dataNum \
    --startNum $startNum \
    --rangenum $rangeNum \
    --fileOut $REFERENCE \
    --sortEnable
  $BINARY -i $REFERENCE -mode $testNo > $QUERY

  ##  compare query with reference  ##
  diff -q $REFERENCE $QUERY
  if [ $? -eq 0 ]; then
    echo "Test ${testNo}-${testPattern} PASS"
  else
    echo "Test ${testNo}-${testPattern} !!!NG!!!"
    exit
  fi
  rm $REFERENCE $QUERY
}

for testNo in $(seq -f "%02g" 1 6); do
  startTime=$(ruby -e "puts Time.now.instance_eval { '%s%03d' % [strftime('%Y%m%d%H%M%S'), (usec / 1000.0).round] }")
  test_func ${testNo} A 15  1 10
  test_func ${testNo} B 100 10 1000
  test_func ${testNo} C 50000 77 77777
  endTime=$(ruby -e "puts Time.now.instance_eval { '%s%03d' % [strftime('%Y%m%d%H%M%S'), (usec / 1000.0).round] }")
  elapsedTime=$(($endTime - $startTime))
  if [ $elapsedTime -lt 0 ]; then elapsedTime=$(expr $elapsedTime + 1000000); fi
  echo "Elapsed Time : $elapsedTime ms"
done
