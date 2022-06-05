/*
 * @Author: Radon
 * @Date: 2022-05-28 22:28:21
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-28 23:31:28
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../headers/BinaryTree.h"
#include "../../headers/List.h"

using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        int n = num.length();
        unordered_map<int, int> ump;

        for (auto &&c : num) {
            int tmp = c - '0';
            ump[tmp]++;
        }

        for (int i = 0; i < num.length(); i++) {
            if (ump[i] != num[i] - '0')
                return false;
        }
        return true;
    }

    string largestWordCount(vector<string> &messages, vector<string> &senders) {
        unordered_map<string, int> ump;
        int n = messages.size();

        for (int i = 0; i < n; i++) {
            string sender = senders[i];
            int words = 1;
            for (auto &&c : messages[i])
                if (c == ' ')
                    words++;

            ump[sender] += words;
        }

        int maxMsg = INT_MIN;
        string res;
        for (auto psi : ump) {
            if (psi.second > maxMsg) {
                maxMsg = psi.second;
                res = psi.first;
            } else if (psi.second == maxMsg)
                res = max(res, psi.first);
        }

        return res;
    }

    long long maximumImportance(int n, vector<vector<int>> &roads) {
        vector<long long> weight(n + 1);
        unordered_map<int, int> degreeMap;
        priority_queue<pair<int, int>> pq;

        for (auto &&road : roads) {
            degreeMap[road[0]]++;
            degreeMap[road[1]]++;
        }

        for (auto &&pii : degreeMap) {
            int degree = pii.second, node = pii.first;
            pq.emplace(degree, node);
        }

        while (!pq.empty()) {
            int degree = pq.top().first, node = pq.top().second;
            pq.pop();

            weight[node] = n--;
        }

        long long res = 0;
        for (auto &&road : roads) {
            res += weight[road[0]] + weight[road[1]];
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    int n = 5;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    sol.maximumImportance(n, roads);
    return 0;
}