//
// Created by bytedance on 2021/10/2.
//

#include "list.h"

//SingleListNode *node5 = new SingleListNode(5, nullptr);
//SingleListNode *node4 = new SingleListNode(4, node5);
//SingleListNode *node3 = new SingleListNode(3, node4);
//SingleListNode *node2 = new SingleListNode(2, node3);
//SingleListNode *node1 = new SingleListNode(1, node2);
//List list = List();
//auto node = list.ReverseSingleList(node1);
//while (node){
//std::cout << node->data << std::endl;
//node = node->nextPtr;
//}
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
SingleListNode *List::ReverseSingleList(SingleListNode *node) {
    if (node == nullptr) {
        return node;
    }
    SingleListNode *prePtr = nullptr;
    while (node) {
        SingleListNode *tempPtr = node->nextPtr;
        node->nextPtr = prePtr;
        prePtr = node;
        node = tempPtr;
    }
    return prePtr;
}

//TwoWayListNode *node1, *node2, *node3, *node4, *node5;
//node5 = new TwoWayListNode(5);
//node4 = new TwoWayListNode(4);
//node3 = new TwoWayListNode(3);
//node2 = new TwoWayListNode(2);
//node1 = new TwoWayListNode(1);
//node5->SetNextPtr(nullptr);
//node5->SetPrePtr(node4);
//
//node4->SetNextPtr(node5);
//node4->SetPrePtr(node3);
//
//node3->SetNextPtr(node4);
//node3->SetPrePtr(node2);
//
//node2->SetNextPtr(node3);
//node2->SetPrePtr(node1);
//
//node1->SetNextPtr(node2);
//node1->SetPrePtr(nullptr);
//List list = List();
//auto node = list.ReverseTwoWayList(node1);
//while (node) {
//std::cout << node->data << std::endl;
//node = node->nextPtr;
//}
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
TwoWayListNode *List::ReverseTwoWayList(TwoWayListNode *node) {
    if (node == nullptr) {
        return node;
    }
    TwoWayListNode *prePtr = nullptr;
    TwoWayListNode *nextPtr = nullptr;
    while (true) {
        prePtr = node->nextPtr;
        nextPtr = node->prePtr;
        node->nextPtr = nextPtr;
        node->prePtr = prePtr;
        if (!prePtr) {
            break;
        }
        node = prePtr;
    }
    return node;
}

//SingleListNode *node5 = new SingleListNode(5);
//SingleListNode *node4 = new SingleListNode(4, node5);
//SingleListNode *node3 = new SingleListNode(3, node4);
//SingleListNode *node2 = new SingleListNode(2, node3);
//SingleListNode *node1 = new SingleListNode(1, node2);
//node5->SetNextPtr(node3);
//List list = List();
//auto have = list.IsHaveRing(node1);
//std::cout << have << std::endl;
//delete node1;
//delete node2;
//delete node3;
//delete node4;
//delete node5;
bool List::IsHaveRing(SingleListNode *node) {
    if (node == nullptr) {
        return false;
    }
    SingleListNode *fastPtr = node;
    SingleListNode *slowPtr = node;
    while (fastPtr != nullptr && fastPtr->nextPtr != nullptr) {
        fastPtr = fastPtr->nextPtr->nextPtr;
        slowPtr = slowPtr->nextPtr;
        if (fastPtr == slowPtr) {
            return true;
        }
    }
    return false;
}

SingleListNode *List::GetLastIndexNode(SingleListNode *node, int k) {
    if (node == nullptr) {
        return nullptr;
    }
    SingleListNode *fastPtr = node;
    SingleListNode *slowPtr = node;
    for (int i = 0; i < k; ++i) {
        if (fastPtr == nullptr) {
            return nullptr;
        }
        fastPtr = fastPtr->nextPtr;
    }
    while (fastPtr) {
        slowPtr = slowPtr->nextPtr;
        fastPtr = fastPtr->nextPtr;
    }
    return slowPtr;
}
