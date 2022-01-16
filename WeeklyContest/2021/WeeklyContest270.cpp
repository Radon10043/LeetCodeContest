/*
 * @Author: Radon
 * @Date: 2021-12-05 10:31:17
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-05 13:04:30
 * @Description: Hi, say something
 */
#include "headers/BinaryTree.h"
#include "headers/List.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {vector<int>} &digits
     * @return {*}
     */
    vector<int> findEvenNumbers(vector<int> &digits) {
        int n = digits.size();
        unordered_set<int> uset;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!digits[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == j || k == i)
                        continue;
                    int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                    if (num % 2 == 0)
                        uset.insert(num);
                }
            }
        }
        result.assign(uset.begin(), uset.end());
        sort(result.begin(), result.end());
        return result;
    }

    /**
     * @description: 两次遍历, Ac
     * @param {ListNode} *head
     * @return {*}
     */
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *p = head;
        int n = 0;
        while (p) {
            n++;
            p = p->next;
        }
        if (n == 1)
            return nullptr;

        int delIdx = n / 2, i = 0;
        p = head;
        while (p) {
            if (i + 1 < delIdx) {
                i++;
                p = p->next;
            } else {
                p->next = p->next->next;
                break;
            }
        }
        return head;
    }

    string startWay, destWay, way;

    /**
     * @description: DFS获得路径
     * @param {TreeNode} *root
     * @param {int} startValue
     * @param {int} destValue
     * @return {*}
     */
    void dfs(TreeNode *root, int startValue, int destValue) {
        if (root->val == startValue)
            startWay = way;
        if (root->val == destValue)
            destWay = way;
        if (startWay != "" && destWay != "")
            return;

        // if (root->left)  //这种写法会超时
        //     dfs(root->left, startValue, destValue, way + 'L');
        if (root->left) {
            way += "L";
            dfs(root->left, startValue, destValue);
            way.pop_back();
        }
        if (root->right) {
            way += "R";
            dfs(root->right, startValue, destValue);
            way.pop_back();
        }
    }

    /**
     * @description: 比对路径并进行替换
     * @param {TreeNode} *root
     * @param {int} startValue
     * @param {int} destValue
     * @return {*}
     */
    string getDirections(TreeNode *root, int startValue, int destValue) {
        dfs(root, startValue, destValue);
        int startWayLen = startWay.length(), destWayLen = destWay.length();
        int i = 0;
        string result;

        for (; i < startWayLen && i < destWayLen; i++) { //找到startWay和destWay中不同走法的下标
            if (startWay[i] != destWay[i])
                break;
        }
        result.append(startWayLen - i, 'U');
        result += destWay.substr(i);
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> vals = {5, 1, 2, 3, null, 6, 4};
    TreeNode *root = new TreeNode();
    createTree(root, vals, 0);

    s.getDirections(root, 5, 6);

    return 0;
}