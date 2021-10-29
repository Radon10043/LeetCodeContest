/*
 * @Author: Radon
 * @Date: 2021-09-24 11:21:30
 * @LastEditors: Radon
 * @LastEditTime: 2021-09-24 12:27:19
 * @Description: Hi, say something
 */
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node();
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node::Node() {
    this->val = 0;
    this->prev = nullptr;
    this->next = nullptr;
    this->child = nullptr;
}

/**
 * @description: 返回链表起始位置
 * @param {vector<int>} nums
 * @return {*}
 */
Node *createMultiDoubleList(vector<int> nums) {
    static Node head;
    Node *ptr = &head;
    Node *start = ptr;
    int n = nums.size();
    if (!n)
        return nullptr;

    for (int i = 0; i < n; i++) {
        if (i && nums[i] && !nums[i - 1]) {
            ptr = start;
            ptr->child = new Node();
            ptr->child->val = nums[i];
            ptr->child->next = new Node();
            ptr->child->next->prev = ptr->child;
            ptr = ptr->child->next;
            start = ptr->prev;
        } else if (!nums[i] && !nums[i - 1]) {
            start = start->next;
        } else if (nums[i]) {
            ptr->val = nums[i];
            if (i + 1 != n && nums[i + 1]) {
                ptr->next = new Node();
                ptr->next->prev = ptr;
            }
            ptr = ptr->next;
        }
    }

    return &head;
}