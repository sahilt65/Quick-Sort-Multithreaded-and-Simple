#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

class QuickSort {
    private:
    std::vector<int> *nums;

    public:
    QuickSort(std::vector<int> *nums);
    ~QuickSort();
    void sort();
    int partition(int left, int right);
    void recursiveQuickSort(int left, int right);
};

#endif