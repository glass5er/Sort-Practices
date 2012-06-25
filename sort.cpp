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
  return;
}

void
Sorter::swap(int &a, int &b)
{
  int swapTmp = a;
  a = b;
  b = swapTmp;
  return;
}

void
Sorter::bubbleSort(vector<int> &array)
{
  int arrNum = array.size();
  for(int i=0; i<arrNum; i++) {
    for(int j=arrNum-1; j>i; j--) {
      if(array[j] < array[j-1]) {
        swap(array[j], array[j-1]);
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
  vector<int> heap(0);
  const int arrNum = array.size();
  for(int i=0; i<arrNum; i++) {
    insertHeap(heap, array[i]);
  }
  array.clear();
  for(int i=0; i<arrNum; i++) {
    array.push_back(determineHeap(heap));
  }
  return;
}
void
Sorter::insertHeap(vector<int> &heap, int key)
{
  heap.push_back(key);
  int child(heap.size());
  int parent(child/2);
  //  regenerate heap  //
  while(child > 1 && heap[child-1] < heap[parent-1]){
    swap(heap[child-1], heap[parent-1]);
    child = parent;
    parent = child/2;
  }
  return;
}
int
Sorter::determineHeap(vector<int> &heap)
{
  int root(heap[0]);
  heap[0] = heap.at((int)heap.size()-1);
  heap.pop_back();
  //  regenerate heap  //
  int parent(1);
  int child(parent * 2);
  int heapNum = heap.size();
  while(child <= heapNum) {
    if(child + 1 <= heapNum && heap[child-1] > heap[child]) child++;
    if(heap[parent-1] > heap[child-1]){
      swap(heap[parent-1], heap[child-1]);
    }
    parent = child;
    child = parent*2;
  }
  return root;
}

void
Sorter::mergeSort(vector<int> &array)
{
  const int arrNum = array.size();
  if(arrNum > 1) {
    int mid = arrNum / 2;
    vector<int> subArrayL(0), subArrayR(0);
    for(int i=0; i<mid; i++) {
      subArrayL.push_back(array[i]);
    }
    for(int i=mid; i<arrNum; i++) {
      subArrayR.push_back(array[i]);
    }
    mergeSort(subArrayL);
    mergeSort(subArrayR);
    mergeSubArray(subArrayL, subArrayR, array);
  }
  return;
}

void
Sorter::mergeSubArray(const vector<int> &subArrayL, const vector<int> &subArrayR, vector<int> &array)
{
  int l(0), r(0);
  int numL = subArrayL.size();
  int numR = subArrayR.size();
  array.clear();
  while(l < numL || r < numR){
    if(r >= numR || (l < numL && subArrayL[l]<subArrayR[r])){
      array.push_back(subArrayL[l]);
      l++;
    }
    else{
      array.push_back(subArrayR[r]);
      r++;
    }
  }
  return;
}

void
Sorter::quickSort(vector<int> &array)
{
  quickSort(array, 0, (int)array.size()-1);
  return;
}
void
Sorter::quickSort(vector<int> &array, int left, int right)
{
  if(left == right) return;
  int pivot = calcPivot(array, left, right);
  if(pivot != INVALID_PIVOT) {
    int part = calcPartition(array, left, right, pivot);
    quickSort(array, left, part-1);
    quickSort(array, part, right);
  }
  return;
}

int
Sorter::calcPivot(const vector<int> &array, int left, int right)
{
  int candidate = left + 1;
  while(candidate <= right && array[left] == array[candidate]) {
    candidate++;
  }
  if(candidate > right) {
    return INVALID_PIVOT;
  }
  return (array[left] > array[candidate]) ? array[left] : array[candidate];
}

int
Sorter::calcPartition(vector<int> &array, int left, int right, int pivot)
{
  int candL(left), candR(right);
  while(candL <= candR) {
    //  search from left/right  //
    while (candL <= right && array[candL] < pivot) {
      candL++;
    }
    while (candR >= left && array[candR] >= pivot) {
      candR--;
    }
    if(candL > candR) break;
    //  swap  //
    int swapTmp = array[candL];
    array[candL] = array[candR];
    array[candR] = swapTmp;
    //  next  //
    candL++;
    candR--;
  }
  return candL;
}
