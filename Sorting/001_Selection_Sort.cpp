/*
   Selection sort is another simple sorting algorithm that sorts an array by repeatedly finding the 
   minimum element from the unsorted part of the array and placing it at the beginning.
   The algorithm divides the array into two parts: the sorted part and the unsorted part. 
   Initially, the sorted part is empty, and the unsorted part consists of the entire array.

The basic idea of the selection sort algorithm is as follows:

Start with the first element as the minimum (assuming it's the smallest).
Iterate through the unsorted part of the array to find the minimum element.
Swap the minimum element with the first element of the unsorted part.
Move the boundary between the sorted and unsorted parts one element to the right.
Repeat the above steps until the entire array is sorted.
  */


#include<vector>
using namespace std;
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }
}
