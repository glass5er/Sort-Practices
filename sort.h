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
  static void bubbleSort(std::vector<int> &array);
  static void bucketSort(std::vector<int> &array, ArrayInfo arrInfo);
  static void radixSort(std::vector<int> &array, ArrayInfo arrInfo);
  static void heapSort(std::vector<int> &array);
  static void mergeSort(std::vector<int> &array);
  static void quickSort(std::vector<int> &array);
  static int calcPivot(std::vector<int> &array);
};
