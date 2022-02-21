//
// Created by bytedance on 2021/9/28.
//

#ifndef WORK_ALGORITHM_H
#define WORK_ALGORITHM_H

#include <vector>
#include <string>

// Dynamic 动态规划
class Dynamic {
public:
    Dynamic() {};

    // 最长递增子序列个数
    // https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
    int LongestIncreasingSubsequence(const std::vector<int> &input);

    // 最大连续子序列和
    // https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
    int MaxSumSubsequence(const std::vector<int> &input);

    // 最长回文子串
    // https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
    // 存储状态容器二维数组，对角线为true，状态转移方程：dp[i][j] = dp[i-1][j+1]，注意边界情况
    std::string MaxLengthPalindromeSubsequence(const std::string &input);

    // 爬楼梯，一次只能爬1阶或者2阶, 状态转移方程：f(x) = f(x-1) + f(x-2)，最后一步只能走一步或者两步
    int ClimbStairs(int steps);
};

// 八皇后问题
class Queen {
public:
    Queen(int size) : size_(size) {
        std::vector<std::vector<int>> board(size, std::vector<int>(size, 0));
        board_ = board;
    };

    void Run(int start);
private:
    bool Check(int row, int column);

private:
    int size_;
    std::vector<std::vector<int>> board_;
};

// 接雨水问题
int MaxWater(const std::vector<int> &arr);

#endif //WORK_ALGORITHM_H
