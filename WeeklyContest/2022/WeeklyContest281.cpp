/*
 * @Author: Radon
 * @Date: 2022-02-20 10:30:18
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-20 11:40:31
 * @Description: Hi, say something
 */
#include "../../headers/List.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; i++) {
            int j = i, temp = 0;
            while (j) {
                temp += j % 10;
                j /= 10;
            }
            if (temp % 2 == 0)
                res++;
        }
        return res;
    }

    ListNode *mergeNodes(ListNode *head) {
        ListNode *p = head->next;
        while (p) {
            if (p->next->val != 0) {
                p->val += p->next->val;
                p->next = p->next->next;
            } else {
                p->next = p->next->next;
                p = p->next;
            }
        }
        return head->next;
    }

    string repeatLimitedString(string s, int repeatLimit) {
        typedef pair<char, int> pci;
        map<char, int> mp;

        for (auto c : s) {
            mp[c]++;
        }

        vector<pci> vec(mp.begin(), mp.end());
        int n = vec.size();
        sort(vec.begin(), vec.end(), greater<pci>());

        s.clear();
        int repeatTimes = 0;
        char ch = 0;
        while (true) {
            int i = 0;
            while (i < n && vec[i].second == 0) {
                i++;
            }
            while (i < n && (vec[i].first == ch && repeatTimes == repeatLimit || vec[i].second == 0)) {
                i++;
                repeatTimes = 0;
            }
            if (i >= n)
                break;
            if (vec[i].first != ch)
                repeatTimes = 0;
            ch = vec[i].first;
            s += vec[i].first;
            vec[i].second--;
            repeatTimes++;
        }
        return s;
    }

    long long coutPairs(vector<int> &nums, int k) {
        long long n = nums.size(), cnt = 0;
        long long res = 0;
        for (auto num : nums) {
            if (num % k == 0)
                cnt++;
        }
        while (cnt) {
            n--;
            res += (long long)n;
            cnt--;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    sol.coutPairs(nums, k);
    return 0;
}