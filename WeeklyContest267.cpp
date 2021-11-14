/*
 * @Author: Radon
 * @Date: 2021-11-14 10:36:04
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-14 11:54:44
 * @Description: Hi, say something
 */
#include "headers\List.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {vector<int>} &tickets
     * @param {int} k
     * @return {*}
     */
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int n = tickets.size(), result = 0;
        while (true) {
            for (int i = 0; i < n; i++) {
                if (tickets[i]) {
                    tickets[i]--;
                    result++;
                }
                if (!tickets[k])
                    goto bought;
            }
        }
    bought:
        return result;
    }

    /**
     * @description: Accept, 转为数组后反转再赋值给list...
     * @param {ListNode} *head
     * @return {*}
     */
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        vector<int> listVec;
        while (p) {
            listVec.emplace_back(p->val);
            p = p->next;
            len++;
        }

        int i = 1;
        for (; (i * i - i) / 2 + i < len; i++) {
            if (i % 2 == 0)
                reverse(listVec.begin() + (i * i - i) / 2, listVec.begin() + (i * i - i) / 2 + i);
        }
        if ((i * i - i) / 2 + i != len - 1 && (len - (i * i - i) / 2) % 2 == 0)
            reverse(listVec.begin() + (i * i - i) / 2, listVec.end());

        p = head;
        for (int val : listVec) {
            p->val = val;
            p = p->next;
        }
        return head;
    }

    /**
     * @description: Accept, 遍历数组后去掉后方的所有空格
     * @param {string} encodedText
     * @param {int} rows
     * @return {*}
     */
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int columns = n / rows;
        string result;
        if (n < 1)
            return encodedText;

        for (int i = 0; i < columns; i++) {
            result += encodedText[i];
            for (int j = 0; j < rows; j++) {
                if (i + (j + 1) * columns + j + 1 < n)
                    result += encodedText[i + (j + 1) * columns + j + 1];
            }
        }
        int endIdx = result.length() - 1;
        while (result[endIdx] == ' ')
            endIdx--;
        result.erase(result.begin() + endIdx + 1, result.end());
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    s.decodeCiphertext("ch   ie   pr", 3);
    return 0;
}