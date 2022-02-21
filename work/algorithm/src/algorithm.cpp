//
// Created by bytedance on 2021/9/28.
//
#include <iostream>
#include "../include/algorithm.h"

//Dynamic dynamic = Dynamic();
//std::vector<int> data{1, 5, 8, 3, 4, 9};
//std::cout << dynamic.LongestIncreasingSubsequence(data);
//std::vector<int> data1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
//std::cout << dynamic.MaxSumSubsequence(data1) << std::endl;
//std::cout << dynamic.MaxLengthPalindromeSubsequence("abbba") << std::endl;
//std::cout << dynamic.ClimbStairs(5) << std::endl;

int Dynamic::LongestIncreasingSubsequence(const std::vector<int> &input) {
    int size = input.size();
    std::vector<int> temp(size, 1);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (input[i] > input[j]) {
                temp[i] = std::max(temp[i], temp[j] + 1);
            }
        }
    }
    return *std::max_element(temp.begin(), temp.end());
}

int Dynamic::MaxSumSubsequence(const std::vector<int> &input) {
    if (input.size() == 1) {
        return input[0];
    }
    int pre = 0, count = input[0];
    for (const auto item : input) {
        pre = std::max(pre + item, item);
        count = std::max(pre, count);
    }
    return count;
}

// a 本身也是回文
// abba
// 搜索顺序如下，步长逐步增加
// ab bb ba
// abb bba
// abba
std::string Dynamic::MaxLengthPalindromeSubsequence(const std::string &input) {
    int size = input.size();
    if (size < 2) {
        return input;
    }
    int length = 1;
    int start = 0;
    std::vector<std::vector<bool>> dp(size, std::vector<bool>(size, false));
    for (int i = 0; i < size; ++i) {
        dp[i][i] = true;
    }
    // j 定义的是检测的步长
    for (int j = 1; j < size; ++j) {
        // i 定义的是起始位置
        for (int i = 0; i < size; ++i) {
            int right = i + j;
            if (right >= size) {
                break;
            }
            if (input[i] != input[right]) {
                dp[i][right] = false;
            } else {
                // right - i <= 2 防止 aba的情况
                if (right - i <= 2) {
                    dp[i][right] = true;
                } else {
                    dp[i][right] = dp[i + 1][right - 1];
                }
            }
            if (dp[i][right] && right - i + 1 > length) {
                start = i;
                length = right - i + 1;
            }
        }
    }
    return input.substr(start, start + length);
}

int Dynamic::ClimbStairs(int steps) {
    if (steps <= 2) {
        return steps;
    }
    std::vector<int> dp(steps, 1);
    dp[1] = 2;
    for (int i = 2; i < steps; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[steps - 1];
}

void Queen::Run(int start) {
    if (start == size_) {
        for (const auto &item : board_) {
            for (const auto &item_child : item) {
                std::cout << item_child;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < size_; ++i) {
        if (Check(start, i)) {
            board_[start][i] = 1;
            Run(start + 1);
            board_[start][i] = 0;
        }
    }
}

bool Queen::Check(int row, int column) {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (board_[i][j] == 1) {
                if (i == row || j == column) {
                    return false;
                }
                if (abs(row - i) == abs(column - j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

// 接雨水问题
// 采用双指针方法
// https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f?tpId=117&&tqId=37802&rp=1&ru=/ta/job-code-high&qru=/ta/job-code-high/question-ranking
int MaxWater(const std::vector<int> &arr) {
    int left = 0, right = int(arr.size()) - 1, bucket_height = 0;
    int water = 0;
    while (left < right) {
        int min_height = std::min(arr[left], arr[right]);
        bucket_height = bucket_height < min_height ? min_height : bucket_height;
        water += arr[left] < arr[right] ? (bucket_height - arr[left++]) : (bucket_height - arr[right--]);
    }
    return water;
}
