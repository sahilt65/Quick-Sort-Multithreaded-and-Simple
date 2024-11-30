#include <iostream>
#include <chrono>
#include "sorting/quick_sort.hpp"
#include "sorting/parallel_quick_sort.hpp"

// #include "sorting/parallelMergeSort.hpp"

int main(int argc, char *argv[]){
    const int SIZE = 100000000;

    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);


    for(int i = 0; i<SIZE; i++){
        nums[i] = rand() % SIZE;
        nums1[i] = nums[i];

    }

    QuickSort* quickSort = new QuickSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    quickSort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quickSortDuration = end - start;
    std::cout << "Normal Quick Sort time taken: " << quickSortDuration.count() << " seconds" << std::endl;

    delete quickSort;



    //Paralle Quick Sort
    ParalleQuickSort* paralleQuickSort = new ParalleQuickSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    paralleQuickSort->sort();
    end = std::chrono::high_resolution_clock::now();
    quickSortDuration = end - start;
    std::cout << "Multithreaded Quick Sort time taken: " << quickSortDuration.count() << " seconds" << std::endl;

    delete paralleQuickSort;
}