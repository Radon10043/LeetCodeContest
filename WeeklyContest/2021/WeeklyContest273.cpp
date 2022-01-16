/*
 * @Author: Radon
 * @Date: 2021-12-26 10:35:21
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-26 11:09:36
 * @Description: Hi, say something
 */
#include "headers/BinaryTree.h"
#include "headers/List.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num % 10 || num == 0)
            return true;
        return false;
    }

    vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
        int m = s.length();
        vector<int> result;
        for (int i = 0; i < m; i++) {
            int step = 0;
            vector<int> pos = startPos;
            for (int j = i; j < m; j++) {
                switch (s[j]) {
                case 'U':
                    pos[0]--;
                    break;
                case 'D':
                    pos[0]++;
                    break;
                case 'L':
                    pos[1]--;
                    break;
                case 'R':
                    pos[1]++;
                    break;
                }
                if (pos[0] >= 0 && pos[0] < n && pos[1] >= 0 && pos[1] < n)
                    step++;
                else
                    break;
            }
            result.emplace_back(step);
        }
        return result;
    }

    vector<long long> getDistances(vector<int> &arr) {
        unordered_map<int, vector<int>> umap;
        vector<long long> result;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            umap[arr[i]].emplace_back(i);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto data : umap[arr[i]]) {
                if (data > i)
                    sum += data - i;
                else if (data < i) {
                    sum += i - data;
                }
            }
            result.emplace_back(sum);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> arr = {2, 1, 3, 1, 2, 3, 3};
    s.getDistances(arr);
    return 0;
}