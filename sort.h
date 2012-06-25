#include <vector>

typedef struct ArrayInfo
{
  int startNum;
  int rangeNum;
} ArrayInfo;

class Sorter
{
public:
  static void sort(std::vector<int> &array, ArrayInfo arrInfo, int mode=0);
protected:
  //  common.swap  //
  static void swap(int &a, int &b);
  //  bubble sort  //
  static void bubbleSort(std::vector<int> &array);
  //  bucket sort  //
  static void bucketSort(std::vector<int> &array, ArrayInfo arrInfo);
  static void radixSort(std::vector<int> &array, ArrayInfo arrInfo);
  //  heap sort  //
  static void heapSort(std::vector<int> &array);
  static void insertHeap(std::vector<int> &array, int key);
  static int  shiftHeap(std::vector<int> &array);
  //  merge sort  //
  static void mergeSort(std::vector<int> &array);
  static void mergeSubArray(const std::vector<int> &subArrayL,
      const std::vector<int> &subArrayR,
      std::vector<int> &array);
  //  quick sort  //
  static void quickSort(std::vector<int> &array);
  static void quickSort(std::vector<int> &array, int left, int right);
  enum { INVALID_PIVOT = -1 };
  static int calcPivot(const std::vector<int> &array, int left, int right);
  static int calcPartition(std::vector<int> &array, int left, int right, int pivot);
};
