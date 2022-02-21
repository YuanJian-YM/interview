//
// Created by bytedance on 2021/10/9.
//

#include "sort.h"

//Sort sort = Sort();
//std::vector<int> data{2, 4, 1, 6, 8, 4};
//sort.BubbleSort(data);
//for (auto item : data) {
//std::cout << item << std::endl;
//}
void Sort::BubbleSort(std::vector<int> &input) {
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j], input[j + 1]);
            }
        }
    }
}

//Sort sort = Sort();
//std::vector<int> data{2, 4, 1, 3, 6, 1, 8, 9};
//sort.MergeSort(data, 0, int(data.size() - 1));
//for (auto item : data) {
//std::cout << item << std::endl;
//}
void Sort::MergeSort(std::vector<int> &input, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(input, start, mid);
    MergeSort(input, mid + 1, end);
    Merge(input, start, mid, end);
}

void Sort::Merge(std::vector<int> &input, int start, int mid, int end) {
    std::vector<int> temp;
    temp.reserve(end - start + 1);
    int i = start, j = mid + 1;
    while (i < mid + 1 && j <= end) {
        if (input[i] < input[j]) {
            temp.push_back(input[i++]);
        } else {
            temp.push_back(input[j++]);
        }
    }
    while (i < mid + 1) {
        temp.push_back(input[i++]);
    }
    while (j <= end) {
        temp.push_back(input[j++]);
    }
    for (auto item : temp) {
        input[start++] = item;
    }
}

void Sort::QuickSort(std::vector<int> &input, int start, int end) {
    if (start >= end) {
        return;
    }
    int benchmark = QuickSortChild(input, start, end);
    QuickSort(input, start, benchmark - 1);
    QuickSort(input, benchmark + 1, end);
}

// 因为要移动左右下标，必须在相等时也要移动，否则死循环，导致非稳定排序

//Sort sort = Sort();
//std::vector<int> data{2, 4, 1, 3, 6, 1, 8, 9};
//sort.QuickSort(data, 0, int(data.size() - 1));
//for (auto item : data) {
//std::cout << item << std::endl;
//}
int Sort::QuickSortChild(std::vector<int> &input, int start, int end) {
    int benchmark = input[start];
    while (start < end) {
        while (start < end && input[end] >= benchmark) {
            --end;
        }
        input[start] = input[end];
        while (start < end && input[start] <= benchmark) {
            ++start;
        }
        input[end] = input[start];
    }
    input[start] = benchmark;
    return start;
}

//Sort sort = Sort();
//std::vector<int> data{2, 4, 1, 3, 6, 1, 8, 9, 2};
//sort.HeapSort(data);
//for (auto item : data) {
//std::cout << item << std::endl;
//}
void Sort::HeapSort(std::vector<int> &input) {
    int size = input.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        Heapify(input, i, size);
    }
    for (int i = size - 1; i >= 0; --i) {
        std::swap(input[i], input[0]);
        Heapify(input, 0, i);
    }
}

void Sort::Heapify(std::vector<int> &input, int start, int end) {
    int dad = start;
    int son = start * 2 + 1;
    while (son < end) {
        if (son < end && son + 1 < end && input[son + 1] > input[son]) {
            ++son;
        }
        if (input[son] > input[dad]) {
            std::swap(input[son], input[dad]);
            dad = son;
            son = 2 * dad + 1;
        } else {
            return;
        }
    }
}
