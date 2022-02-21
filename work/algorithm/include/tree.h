//
// Created by bytedance on 2021/10/10.
//

#ifndef WORK_TREE_H
#define WORK_TREE_H

#include <vector>

struct TreeNode {
    int data;
    TreeNode *leftNode, *rightNode;

    explicit TreeNode(int data) : data(data), leftNode(nullptr), rightNode(nullptr) {};

    TreeNode(int data, TreeNode *left, TreeNode *right) : data(data), leftNode(left), rightNode(right) {};
};

class Tree {
public:
    Tree() {};
public:
    // PreOrder 前序遍历
    static std::vector<int> PreOrder(TreeNode *node);

    // MiddleOrder 中序遍历
    static std::vector<int> MiddleOrder(TreeNode *node);

    // PostOrder 后序遍历
    static std::vector<int> PostOrder(TreeNode *node);

    // LevelOrder 层序遍历
    static std::vector<int> LevelOrder(TreeNode *node);

    //
    static void PreOrderRecursive(TreeNode *node, std::vector<int> &output);

    static void MiddleOrderRecursive(TreeNode *node, std::vector<int> &output);

    static void PostOrderRecursive(TreeNode *node, std::vector<int> &output);

    // 是否为对称二叉树 https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
    static bool IsSymmetry(TreeNode *node);

    // 二叉树的最大深度 https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/
    static int MaxDeep(TreeNode *node);

    // 二叉树的最小深度 https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-de-zui-xiao-shen-du-by-leetcode-solutio/
    static int MinDeep(TreeNode *node);

    // FlipTree 翻转二叉树 https://leetcode-cn.com/problems/invert-binary-tree/
    static void FlipTree(TreeNode *node);

    // 判断B 是否为 A的字树
    static bool HasSubTree(TreeNode *pRoot1, TreeNode *pRoot2);

    // 二叉排序树转换成双向链表
    // https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=23253&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    static TreeNode* Convert(TreeNode *root);

    // 将有序数组转换为二叉搜索树
    // 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
    //高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树
    // https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
    // https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/jiang-you-xu-shu-zu-zhuan-huan-wei-er-cha-sou-s-33/
    static TreeNode* SortedArrayToBST(std::vector<int>& nums);
    static TreeNode* builder(std::vector<int>& nums, int left, int right);
};


#endif //WORK_TREE_H
