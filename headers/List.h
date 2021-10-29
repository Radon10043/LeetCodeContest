/*
 * @Author: Radon
 * @Date: 2021-07-27 20:36:22
 * @LastEditors: Radon
 * @LastEditTime: 2021-09-22 09:44:00
 * @Description: 单链表头文件
 */
#pragma once

#include <vector>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode* next) : val(x), next(next){}
}ListNode;

//创建链表，返回值是头节点
ListNode* createList(vector<int> vals) {
	ListNode* head = new ListNode();
	ListNode* node = head;
	int n = vals.size();
	for (int i = 0; i < n; i++) {
		node->val = vals[i];
		if (i == n - 1)
			break;
		node->next = new ListNode();
		node = node->next;
	}
	return head;
}