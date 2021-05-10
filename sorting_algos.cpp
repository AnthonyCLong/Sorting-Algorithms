#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include "sorting_algos.hpp"
#include <queue>

using namespace std;

int bubbleSort(vector<int> &arr, int n)
{
    int count=0;
    bool swapped = false;
    if(n==1)
        return 0;
    int i1 = 0, i2 = 1,temp;
    while(i1 <n-1)
    {
        if (arr[i1]>arr[i2])
        {    
            swapped = true;
            temp = arr[i1];
            arr[i1] = arr[i2];
            arr[i2] = temp;
            count++;
        }
        i1 = i2++;
    }
    if (swapped)
        count += bubbleSort(arr,n-1);
    return count;
}

int selectionSort(vector<int> &arr, int n)
{
    int count = 0;
    if(arr.size()-n == 1)
        return 0;
    int swap = n, check = swap + 1, temp;
    while(check < arr.size())
    {
        if (arr[check]<arr[swap])
        {    
          swap = check;
        }
        check++;
    }
    if (swap != n)
        {
            temp = arr[n];
            arr[n] = arr[swap];
            arr[swap] = temp;
            count++;
        }
    count += selectionSort(arr, n+1);
    return count;
}

int merge(vector<int> &arr, int left, int middle, int right)
{
    int left_size = middle - left + 1;
    int right_size = right - middle;

    int left_array[left_size], right_array[right_size];

    for (int i = 0; i < left_size; i++)
        left_array[i] = arr[left+i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < left_size && j < right_size)
    {
        if(left_array[i]<=right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    
    while (i < left_size)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < right_size)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    
}

int mergeSort(vector<int> &arr, int left, int right)
{
    int count = 0; 
    if (left>=right)
        return 0;
    int middle = left + (right-left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
    return count;
}
//we split log n times/ then, for each split we merge n elements. n* log n complexity.
int insertSort(vector<int> &arr, int n)
{
    int j, insert, count = 0;
    for (int i = 0; i < n; i++)
    {
        insert = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > insert)
            {
                arr[j+1] = arr[j--];
                count++;
            }
        arr[j+1] = insert;
    }
    return count;
}
void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;

    for (int j = low; j <= high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[low]);
    return (i);
}

int quickSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int split = partition(arr, low, high);

        quickSort(arr, low, split-1);
        quickSort(arr, split+1, high);
    }
    return count; 
}

int getMax(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int radixSort(vector<int> &arr, int n)
{
    vector<queue<int>> queues = vector<queue<int>>(10);

    int max = getMax(arr, n);

    for (int cycle = 1; max/cycle > 0; cycle *= 10)
    {
        for (int i = 0; i < n; i++)
        {
            queues[(arr[i] / cycle) % 10].push(arr[i]);
        }
        int k = 0;
        for(int i = 0; i < 10; i++)
        {
            while(!queues[i].empty())
            {
                arr[k] = queues[i].front();
                k++;
                queues[i].pop();
            }
        }
    }
    return 0;
}