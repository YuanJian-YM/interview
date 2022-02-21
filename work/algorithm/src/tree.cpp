//
// Created by bytedance on 2021/10/10.
//
#include <stack>
#include <queue>
#include "tree.h"

// 根左右

//TreeNode *node6 = new TreeNode(6);
//TreeNode *node5 = new TreeNode(5);
//TreeNode *node4 = new TreeNode(4);
//TreeNode *node2 = new TreeNode(2, node4, node5);
//TreeNode *node3 = new TreeNode(3, nullptr, node6);
//TreeNode *node1 = new TreeNode(1, node2, node3);
//auto result = Tree::PreOrder(node1);
//for(auto item : result){
//std::cout << item << std::endl;
//}
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
//delete node6;
std::vector<int> Tree::PreOrder(TreeNode *node) {
    std::vector<int> result;
    if (node == nullptr) {
        return result;
    }
    std::stack<TreeNode *> nodes;
    TreeNode *temp = node;
    while (temp || !nodes.empty()) {
        if (temp) {
            nodes.push(temp);
            result.push_back(temp->data);
            temp = temp->leftNode;
        } else {
            TreeNode *lastNode = nodes.top();
            if (lastNode->rightNode) {
                temp = lastNode->rightNode;
            }
            nodes.pop();
        }
    }
    return result;
}

// 左根右
std::vector<int> Tree::MiddleOrder(TreeNode *node) {
    std::vector<int> result;
    if (node == nullptr) {
        return result;
    }
    std::stack<TreeNode *> nodes;
    TreeNode *temp = node;
    while (temp || !nodes.empty()) {
        if (temp) {
            nodes.push(temp);
            temp = temp->leftNode;
        } else {
            auto lastNode = nodes.top();
            result.push_back(lastNode->data);
            if (lastNode->rightNode) {
                temp = lastNode->rightNode;
            }
            nodes.pop();
        }
    }
    return result;
}

// 后序遍历根节点存储在栈中，必须分清返回根节点时，是从左子树返回的，还从右子树返回的，增加辅助指针visit，其指向最近访问过的节点
// 左右根
std::vector<int> Tree::PostOrder(TreeNode *node) {
    std::vector<int> result;
    if (node == nullptr) {
        return result;
    }
    TreeNode *temp = node, *visit = nullptr;
    std::stack<TreeNode *> nodes;
    while (temp || !nodes.empty()) {
        if (temp) {
            nodes.push(temp);
            temp = temp->leftNode;
        } else {
            auto lastNode = nodes.top();
            if (lastNode->rightNode && lastNode->rightNode != visit) {
                temp = lastNode->rightNode;
            } else {
                nodes.pop();
                result.push_back(lastNode->data);
                visit = lastNode;
            }
        }
    }
    return result;
}

std::vector<int> Tree::LevelOrder(TreeNode *node) {
    std::vector<int> result;
    if (node == nullptr) {
        return result;
    }
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    while (!nodes.empty()) {
        auto temp = nodes.front();
        result.push_back(temp->data);
        nodes.pop();
        if (temp->leftNode) {
            nodes.push(temp->leftNode);
        }
        if (temp->rightNode) {
            nodes.push(temp->rightNode);
        }
    }
    return result;
}

void Tree::PreOrderRecursive(TreeNode *node, std::vector<int> &output) {
    if (node == nullptr) {
        return;
    }
    output.push_back(node->data);
    PreOrderRecursive(node->leftNode, output);
    PreOrderRecursive(node->rightNode, output);
}

void Tree::MiddleOrderRecursive(TreeNode *node, std::vector<int> &output) {
    if (node == nullptr) {
        return;
    }
    MiddleOrderRecursive(node->leftNode, output);
    output.push_back(node->data);
    MiddleOrderRecursive(node->rightNode, output);
}

//TreeNode *node6 = new TreeNode(6);
//TreeNode *node5 = new TreeNode(5);
//TreeNode *node4 = new TreeNode(4);
//TreeNode *node2 = new TreeNode(2, node4, node5);
//TreeNode *node3 = new TreeNode(3, nullptr, node6);
//TreeNode *node1 = new TreeNode(1, node2, node3);
//std::vector<int> result;
//Tree::PostOrderRecursive(node1, result);
//for(auto item : result){
//std::cout << item << std::endl;
//}
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
//delete node6;
void Tree::PostOrderRecursive(TreeNode *node, std::vector<int> &output) {
    if (node == nullptr) {
        return;
    }
    PostOrderRecursive(node->leftNode, output);
    PostOrderRecursive(node->rightNode, output);
    output.push_back(node->data);
}

//TreeNode *node5 = new TreeNode(3);
//TreeNode *node4 = new TreeNode(3);
//TreeNode *node2 = new TreeNode(2, node4, nullptr);
//TreeNode *node3 = new TreeNode(2, nullptr, node5);
//TreeNode *node1 = new TreeNode(1, node2, node3);
//std::cout << Tree::IsSymmetry(node1);
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
bool Tree::IsSymmetry(TreeNode *node) {
    if (node == nullptr) {
        return true;
    }
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    nodes.push(node);
    while (!nodes.empty()) {
        auto left = nodes.front();
        nodes.pop();
        auto right = nodes.front();
        nodes.pop();
        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->data != right->data) return false;
        nodes.push(left->leftNode);
        nodes.push(right->rightNode);

        nodes.push(left->rightNode);
        nodes.push(right->leftNode);
    }
    return true;
}

// MaxDeep 利用层序遍历，广度优先
int Tree::MaxDeep(TreeNode *node) {
    if (node == nullptr)
        return 0;
    int deep = 0;
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        while (levelSize > 0) {
            auto temp = nodes.front();
            nodes.pop();
            if (temp->leftNode) {
                nodes.push(temp->leftNode);
            }
            if (temp->rightNode) {
                nodes.push(temp->rightNode);
            }
            --levelSize;
        }
        ++deep;
    }
    return deep;
}

int Tree::MinDeep(TreeNode *node) {
    if (node == nullptr)
        return 0;
    int deep = 1;
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    while (!nodes.empty()) {
        int levelSize = nodes.size();
        while (levelSize > 0) {
            auto temp = nodes.front();
            nodes.pop();
            if (!temp->leftNode && !temp->rightNode) {
                return deep;
            }
            if (temp->leftNode) {
                nodes.push(temp->leftNode);
            }
            if (temp->rightNode) {
                nodes.push(temp->rightNode);
            }
            --levelSize;
        }
        ++deep;
    }
    return --deep;
}

//TreeNode *node5 = new TreeNode(5);
//TreeNode *node4 = new TreeNode(4);
//TreeNode *node2 = new TreeNode(3, node4, nullptr);
//TreeNode *node3 = new TreeNode(2, nullptr, node5);
//TreeNode *node1 = new TreeNode(1, node2, node3);
//Tree::FlipTree(node1);
//auto result = Tree::LevelOrder(node1);
//for(auto item : result){
//std::cout << item << std::endl;
//}
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;

// 利用层序遍历不断翻转
void Tree::FlipTree(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    while (!nodes.empty()) {
        auto temp = nodes.front();
        nodes.pop();
        std::swap(temp->leftNode, temp->rightNode);
        if (temp->leftNode) {
            nodes.push(temp->leftNode);
        }
        if (temp->rightNode) {
            nodes.push(temp->rightNode);
        }
    }
}

bool IsSubTree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot2 == nullptr) return true;
    if (pRoot1 == nullptr || !pRoot2) return false;
    if (pRoot1->data != pRoot2->data) return false;
    return IsSubTree(pRoot1->leftNode, pRoot2->leftNode) && IsSubTree(pRoot1->rightNode, pRoot2->rightNode);
}

bool Tree::HasSubTree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (!pRoot1 && !pRoot2) return true;
    if (!pRoot1 || !pRoot2) return false;
    std::queue<TreeNode *> dp;
    dp.push(pRoot1);
    while (!dp.empty()) {
        auto temp = dp.front();
        dp.pop();
        if (temp->data == pRoot2->data) {
            if (IsSubTree(temp, pRoot2)) return true;
        }
        if (temp->leftNode) {
            dp.push(temp->leftNode);
        }
        if (temp->rightNode) {
            dp.push(temp->rightNode);
        }
    }
    return false;
}

TreeNode *Tree::Convert(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *temp = root, *pre = nullptr, *head = nullptr;
    std::stack<TreeNode *> dp;
    while (!dp.empty() || temp) {
        if (temp) {
            dp.push(temp);
            temp = temp->leftNode;
        } else {
            auto cur = dp.top();
            if (pre) {
                pre->rightNode = cur;
            }
            cur->leftNode = pre;
            pre = cur;
            if (!head) {
                head = cur;
            }
            if (cur->rightNode) {
                temp = cur->rightNode;
            }
            dp.pop();
        }
    }
    return head;
}


TreeNode *Tree::SortedArrayToBST(std::vector<int> &nums) {
    return builder(nums, 0, nums.size() - 1);
}

TreeNode *Tree::builder(std::vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->leftNode = builder(nums, left, mid - 1);
    root->rightNode = builder(nums, mid + 1, right);
    return root;
}
