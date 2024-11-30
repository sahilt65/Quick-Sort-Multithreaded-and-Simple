
#ifndef PARALLELQUICKSORT_H
#define PARALLELQUICKSORT_H

#include <vector>
#include <thread>

class ParalleQuickSort {
    private:
    std::vector<int> *nums;

    public:
    ParalleQuickSort(std::vector<int> *nums);
    ~ParalleQuickSort();
    void sort();
    int partition(int left, int right);
    void recursiveQuickSort(int left, int right);
};

#endif