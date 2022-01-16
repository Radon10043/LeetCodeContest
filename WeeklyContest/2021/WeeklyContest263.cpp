/*
 * @Author: Radon
 * @Date: 2021-10-10 10:36:04
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-17 11:59:39
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1, cur = 0;
        s += " ";
        for (char c : s) {
            if (c >= '0' && c <= '9')
                cur = cur * 10 + c - '0';
            if (c == ' ' && cur) {
                if (cur > prev) {
                    prev = cur;
                    cur = 0;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    int result = 0;
    void backtrack(vector<int> nums, int now, int start, int n, int maxNum) {
        if (now == maxNum)
            result++;
        for (int i = start; i < n; i++) {
            backtrack(nums, now | nums[i], i + 1, n, maxNum);
        }
    }

    int countMaxOrSubsets(vector<int> &nums) {
        int n = nums.size();
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            maxNum |= nums[i];
        }
        backtrack(nums, 0, 0, n, maxNum);
        return result;
    }

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
        queue<int> q;
        unordered_set<int> timeSet;
        int timeSetSize = 0, secondMinTime = 0, cnt = 0;
        int node;
        q.push(1);
        while (timeSetSize < 2) {
            node = q.front();
            q.pop();
            cnt++;
            for (vector<int> e : edges) {
                int idx = -1;
                if (e[0] == node)
                    idx = 1;
                else if (e[1] == node)
                    idx = 0;
                if (idx != -1) {
                    q.push(e[idx]);
                    if (e[idx] == n) {
                        if (timeSet.insert(cnt).second) {
                            timeSetSize++;
                            secondMinTime = cnt;
                        }
                    }
                }
            }
        }
        // cnt = secondMinTime;
        // secondMinTime = 0;
        // for (int i = 0; i < cnt; i++) {
        //     secondMinTime += time;
        //     if (secondMinTime / change % 2)
        //         secondMinTime += secondMinTime % change;
        // }
        return secondMinTime;
    }
};

class Bank {
private:
    vector<long long> balance;
    int n;

public:
    Bank(vector<long long> &balance) {
        this->balance = balance;
        this->n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 <= n && account2 <= n && balance[account1 - 1] >= money) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (account <= n) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (account <= n && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    cout << s.secondMinimum(5, edges, 3, 5) << endl;
    return 0;
}