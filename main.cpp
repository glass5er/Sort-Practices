#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include "sort.h"

using std::string;
using std::vector;

const int NO_SORT = -1;

int
readData(const char *fileName, vector<int> &array, ArrayInfo &arrInfo)
{
  FILE *fp = fopen(fileName, "rt");
  if(fp == NULL) {
    printf("File Open Error : %s\n", fileName);
    return -1;
  }
  int arrNum(0), startNum(0), rangeNum(0);
  fscanf(fp, "%d %d %d", &arrNum, &startNum, &rangeNum);
  arrInfo.startNum = startNum;
  arrInfo.rangeNum = rangeNum;

  array.clear();
  int arrBuf;
  for(int i=0; i<arrNum; i++) {
    fscanf(fp, "%d", &arrBuf);
    array.push_back(arrBuf);
  }
  fclose(fp);
  return 0;
}

int main(int argc, char *argv[])
{
  string fileSrc;
  int testMode(0);

  ArrayInfo arrInfo;
  vector<int> dataArray;

  for(int i=0; i<argc; i++) {
    if(strcmp(argv[i], "-i") == 0)    { fileSrc = argv[i+1]; }
    if(strcmp(argv[i], "-mode") == 0) { testMode = atoi(argv[i+1]); }
  }

  if(readData(fileSrc.c_str(), dataArray, arrInfo) < 0) { return -1; }

  if(testMode == NO_SORT) {
    //  Input Data Through  //
  }else {
    //  Sort //
    Sorter::sort(dataArray, arrInfo, testMode);
  }
  //  put array data  //
  int arrNum = dataArray.size();
  printf("%d %d %d\n", arrNum, arrInfo.startNum, arrInfo.rangeNum);
  for(int i=0; i<arrNum; i++) {
    printf("%d\n", dataArray[i]);
  }
  return 0;
}
