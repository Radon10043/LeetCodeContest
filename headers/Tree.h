/*
 * @Author: Radon
 * @Date: 2021-11-21 11:53:08
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-21 11:53:51
 * @Description: Hi, say something
 */
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};