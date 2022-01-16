/*
 * @Author: Radon
 * @Date: 2021-10-31 10:38:25
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-31 14:59:26
 * @Description: Hi, say something
 */
#include "..\..\headers\List.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {vector<int>} &nums
     * @return {*}
     */
    int smallestEqual(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }

    /**
     * @description: Accept
     * @param {ListNode} *head
     * @return {*}
     */
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> vals;
        int n = 0;
        while (head) {
            vals.emplace_back(head->val);
            n++;
            head = head->next;
        }

        if (n < 3)
            return {-1, -1};
        int first = -1, prev = -1, cur = -1, last = -1, minDistance = n;
        for (int i = 1; i < n - 1; i++) {
            if (vals[i] > vals[i + 1] && vals[i] > vals[i - 1] || vals[i] < vals[i + 1] && vals[i] < vals[i - 1]) { //临界点
                last = i;
                if (first == -1) {
                    first = i;
                    prev = i;
                } else {
                    cur = i;
                    minDistance = min(minDistance, cur - prev);
                    prev = cur;
                }
            }
        }
        if (cur == -1)
            return {-1, -1};
        return {minDistance, last - first};
    }

    /**
     * @description: BFS+HashSet, 比赛结束后Accept
     * @param {vector<int>} &nums
     * @param {int} start
     * @param {int} goal
     * @return {*}
     */
    int minimumOperations(vector<int> &nums, int start, int goal) {
        typedef pair<int, int> pii;
        queue<pii> q;
        unordered_set<int> checked;
        q.push(pii(start, 0));

        while (!q.empty()) {
            pii temp = q.front();
            q.pop();
            for (int num : nums) {
                if ((temp.first + num == goal) || (temp.first - num == goal) || ((temp.first ^ num) == goal))
                    return temp.second + 1;
                if (temp.first + num >= 0 && temp.first + num <= 1000 && checked.insert(temp.first + num).second)
                    q.push(pii(temp.first + num, temp.second + 1));
                if (temp.first - num >= 0 && temp.first - num <= 1000 && checked.insert(temp.first - num).second)
                    q.push(pii(temp.first - num, temp.second + 1));
                if ((temp.first ^ num) >= 0 && (temp.first ^ num) <= 1000 && checked.insert(temp.first ^ num).second)
                    q.push(pii(temp.first ^ num, temp.second + 1));
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 3};
    cout << s.minimumOperations(nums, 6, 4) << endl;
    return 0;
}