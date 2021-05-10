#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include "sorting_algos.hpp"

using namespace std;

void generateArray(vector<int> &arr)
{
    srand (time(NULL));
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = (rand() % 50 + 1);
    }
    
}

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
}

void cleanPrint(vector<int> &arr)
{
    for (int i = 0; i<arr.size(); i++)
    {
        cout<<arr[i];
        if(i!= arr.size()-1)
            cout<<", ";
    }
    cout<<endl<<endl;
}

void printOptions()
{
    cout<<"Enter the sorting algorithm to be used. (enter the number)"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Selection Sort"<<endl;
    cout<<"3. Merge Sort"<<endl;
    cout<<"4. Insert Sort"<<endl;
    cout<<"5. Quick Sort"<<endl;
    cout<<"6. Radix Sort"<<endl;
    cout<<"----------------------------------------------------------"<<endl<<endl;
}

int main()
{
    cout<<"Hello. Input size of array you would like to generate:";
    int arr_size = 0;
    cin>>arr_size;
    vector<int> arr;
    if(arr_size!= -1)
    {
        while(arr_size<2)
        {
            cout<<"Invalid array size: "<<arr_size<<endl; 
            cin>>arr_size;
        }
        // cout<<"Array size: "<<arr_size<<endl;
        arr = vector<int>(arr_size);
        generateArray(arr);
    }
    else
    {
        arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //sorted
        // arr = {10,9,8,7,6,5,4,3,2,1}; //reverse sorted
        arr_size = 10;
    }
    cout<<endl<<"The generated array:"<<endl;
    cleanPrint(arr);

    
    
    int algo = 0;
    bool valid = false;
    vector<int> sortarr;
    while(!valid)
    {
        printOptions();
        cin>>algo;
        valid = !valid;
        
        switch (algo)
        {
        case -1:
            return 0;
        case 1:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Bubble sort Selected. Total number of swaps:"<<bubbleSort(sortarr, arr_size)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break;
        case 2:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Selection sort Selected. Total number of swaps:"<<selectionSort(sortarr, 0)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break;
        case 3:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Merge sort Selected. Total number of swaps:"<<mergeSort(sortarr, 0, arr_size-1)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break;    
        case 4:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Insert sort Selected. Total number of swaps:"<<insertSort(sortarr, arr_size)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break; 
        case 5:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Quick sort Selected. Total number of swaps:"<<quickSort(sortarr, 0, arr_size-1)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break;  
        case 6:
            sortarr = arr;
            cout<<"Orginal array:"<<endl;
            printArray(sortarr);
            cout<<"Radix sort Selected. Total number of swaps:"<<radixSort(sortarr, arr_size)<<". Sorted array:"<<endl<<endl;
            printArray(sortarr);
            valid = !valid;
            break;  
        default:
            cout<<"Number not recognized, try again."<<endl<<endl;
            valid = !valid;
            break;
        }
    }    

    return 0;
}