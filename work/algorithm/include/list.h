//
// Created by bytedance on 2021/10/2.
//

#ifndef WORK_LIST_H
#define WORK_LIST_H

struct SingleListNode {
    int data;
    SingleListNode *nextPtr;

    SingleListNode(int data, SingleListNode *nextPtr) : data(data), nextPtr(nextPtr) {};

    SingleListNode(int data) : data(data), nextPtr(nullptr) {};

    void SetNextPtr(SingleListNode *nextPtr) {
        this->nextPtr = nextPtr;
    }
};

struct TwoWayListNode {
    int data;
    TwoWayListNode *nextPtr;
    TwoWayListNode *prePtr;

    TwoWayListNode(int data, TwoWayListNode *prePtr, TwoWayListNode *nextPtr) : data(data), prePtr(prePtr),
                                                                                nextPtr(nextPtr) {};

    TwoWayListNode(int data) : data(data), prePtr(nullptr),
                               nextPtr(nullptr) {};

    void SetNextPtr(TwoWayListNode *nextPtr) {
        this->nextPtr = nextPtr;
    }

    void SetPrePtr(TwoWayListNode *prePtr) {
        this->prePtr = prePtr;
    }
};

class List {
public:
    List() {};
public:
    // 反转单向链表
    SingleListNode *ReverseSingleList(SingleListNode *node);

    // 反转双向链表
    TwoWayListNode *ReverseTwoWayList(TwoWayListNode *node);

    // 单向链表是否有环,快慢指针
    bool IsHaveRing(SingleListNode *node);

    // 链表是否相交 https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/solution/dai-ma-sui-xiang-lu-dai-ni-gao-ding-lian-5ykc/
    // 给定一个链表，删除链表的倒数第 N 个节点，并且返回链表的头结点。使用双指针,
    // https://github.com/0voice/interview_internal_reference/blob/master/01.%E9%98%BF%E9%87%8C%E7%AF%87/1.3.2%20%E7%BB%99%E5%AE%9A%E4%B8%80%E4%B8%AA%E9%93%BE%E8%A1%A8%EF%BC%8C%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9%EF%BC%8C%E5%B9%B6%E4%B8%94%E8%BF%94%E5%9B%9E%E9%93%BE%E8%A1%A8%E7%9A%84%E5%A4%B4%E7%BB%93%E7%82%B9.md
    // GetLastIndexNode 获取倒数第k个节点，双指针
    SingleListNode *GetLastIndexNode(SingleListNode *node, int k);
};


#endif //WORK_LIST_H
