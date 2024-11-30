#include "quick_sort.hpp"
#include <bits/stdc++.h>

QuickSort::QuickSort(std::vector<int> *nums){
    this -> nums = nums;
}

QuickSort::~QuickSort(){}

int QuickSort::partition(int low, int high){
    int pivot = (*nums)[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if ((*nums)[j] < pivot) {
            i++;
            std::swap((*nums)[i], (*nums)[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    std::swap((*nums)[i + 1], (*nums)[high]);  
    return i + 1;
}

void QuickSort::recursiveQuickSort(int low, int high){
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition( low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        recursiveQuickSort(low, pi - 1);
        recursiveQuickSort( pi + 1, high);
    }
}

void QuickSort::sort(){
    if((*nums).size() == 0) exit(1);
    recursiveQuickSort(0, (*nums).size() - 1);
}