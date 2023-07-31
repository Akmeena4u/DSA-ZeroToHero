/*
   Insertion sort is another simple sorting algorithm that works by building a sorted portion of the array and 
   iteratively inserting unsorted elements into their correct positions within the sorted part.
   It is similar to how we arrange a deck of playing cards in our hands.

The basic idea of the insertion sort algorithm is as follows:

Start with the first element; consider it as a sorted part of the array.
Take the next unsorted element and insert it into its correct position within the sorted part by comparing it with the elements in the sorted part from right to left.
Repeat step 2 for all the remaining unsorted elements until the entire array is sorted.


  */



#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}
