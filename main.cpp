#include <cstdio>
#include <vector>
#include "sort.h"

using std::vector;


void readData(vector<int> &arr, ArrayInfo &arrInfo)
{
  int arrNum(0), startNum(0), rangeNum(0);
  scanf("%d %d %d", &arrNum, &startNum, &rangeNum);
  arrInfo.startNum = startNum;
  arrInfo.rangeNum = rangeNum;

  arr.clear();
  int arrBuf;
  for(int i=0; i<arrNum; i++) {
    scanf("%d", &arrBuf);
    arr.push_back(arrBuf);
  }
  return;
}

int main()
{
  ArrayInfo arrInfo;
  vector<int> dataArray;
  bool testMode(false);

  readData(dataArray, arrInfo);

  if(testMode) {
    //  Input Data Through  //
  }else {
    //  Sort //
    Sorter::sort(dataArray, arrInfo, 3);
  }
  //  put array data  //
  int arrNum = dataArray.size();
  printf("%d %d %d\n", arrNum, arrInfo.startNum, arrInfo.rangeNum);
  for(int i=0; i<arrNum; i++) {
    printf("%d\n", dataArray[i]);
  }
  return 0;
}
