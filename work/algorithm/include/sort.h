//
// Created by bytedance on 2021/10/9.
//

#ifndef WORK_SORT_H
#define WORK_SORT_H
#include <vector>

class Sort {
public:
    Sort(){};
public:
    // BubbleSort 冒泡排序
    void BubbleSort(std::vector<int> &input);
    // MergeSort 归并排序
    void MergeSort(std::vector<int> &input, int start, int end);
    // QuickSort 快速排序
    void QuickSort(std::vector<int> &input, int start, int end);
    // HeapSort 堆排序
    void HeapSort(std::vector<int> &input);
private:
    void Merge(std::vector<int> &input, int start, int mid, int end);
    int QuickSortChild(std::vector<int> &input, int start, int end);
    void Heapify(std::vector<int> &input, int start, int end);
};


#endif //WORK_SORT_H
