#include "sort.h"
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using std::vector;
using std::list;

void
Sorter::sort(vector<int> &array, ArrayInfo arrInfo, int mode)
{
  switch(mode) {
  case 1:
    bubbleSort(array);
    break;
  case 2:
    bucketSort(array, arrInfo);
    break;
  case 3:
    radixSort(array, arrInfo);
    break;
  case 4:
    heapSort(array);
    break;
  case 5:
    mergeSort(array);
    break;
  case 0:
  default:
    quickSort(array);
    break;
  }
}

void
Sorter::bubbleSort(vector<int> &array)
{
  int arrNum = array.size();
  int swapTmp;
  for(int i=0; i<arrNum; i++) {
    for(int j=arrNum-1; j>i; j--) {
      if(array[j] < array[j-1]) {
        swapTmp = array[j];
        array[j] = array[j-1];
        array[j-1] = swapTmp;
      }
    }
  }
  return;
}

void
Sorter::bucketSort(vector<int> &array, ArrayInfo arrInfo)
{
  vector<int> bucket(arrInfo.rangeNum, 0);
  int arrNum = array.size();
  for(int i=0; i<arrNum; i++) {
    bucket.at(array[i] - arrInfo.startNum) += 1;
  }
  //  push sorted data  //
  array.clear();
  for(int b=0; b<arrInfo.rangeNum; b++) {
    for(int t=0; t<bucket[b]; t++) {
      array.push_back(b + arrInfo.startNum);
    }
  }
  return;
}
void
Sorter::radixSort(vector<int> &array, ArrayInfo arrInfo)
{
  const int arrNum = array.size();
  const int radix(16);
  int digitNum(0);
  int range = arrInfo.rangeNum;
  while(range > 0) {
    digitNum++;
    range /= radix;
  }
  vector<int> binCounts(radix, 0);
  vector< list<int> > buckets(radix);
  //  set to buckets first  //
  for(int i=0; i<arrNum; i++) {
    int index = array[i] % radix;
    buckets.at(index).push_back(array[i]);
  }
  //  backet sort loop  //
  for(int d=1; d<digitNum; d++) {
    for(int b=0; b<radix; b++) {
      binCounts.at(b) = buckets.at(b).size();
    }
    for(int b=0; b<radix; b++) {
      while(binCounts.at(b) > 0) {
        int targetVal = buckets.at(b).front();
        buckets.at(b).pop_front();
        int index = (targetVal / (int)pow(radix, d)) % radix;
        buckets.at(index).push_back(targetVal);
        binCounts.at(b) -= 1;
      }
    }
  }
  //  push sorted data  //
  array.clear();
  for(int b=0; b<radix; b++) {
    while(buckets.at(b).size() > 0) {
      array.push_back(buckets.at(b).front());
      buckets.at(b).pop_front();
    }
  }
  return;
}
void
Sorter::heapSort(vector<int> &array)
{
  return;
}
void
Sorter::mergeSort(vector<int> &array)
{
  return;
}
void
Sorter::quickSort(vector<int> &array)
{
  return;
}
