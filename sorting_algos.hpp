#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#include <vector>
// namespace N
// {
    int bubbleSort(std::vector<int> &arr, int n);
    int selectionSort(std::vector<int> &arr, int n);
    int mergeSort(std::vector<int> &arr, int left, int right);
    int merge(std::vector<int> &arr, int left, int middle, int right);
    int insertSort(std::vector<int> &arr, int n);
    int quickSort(std::vector<int> &arr, int low, int high);
    void swap(int* a, int* b);
    int partition(std::vector<int> &arr, int low, int high);
    int radixSort(std::vector<int> &arr, int n);
    int getMax(std::vector<int> &arr, int n);
// }

#endif
