/*
 * @Author: Radon
 * @Date: 2022-06-05 10:27:38
 * @LastEditors: Radon
 * @LastEditTime: 2022-06-05 11:41:52
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
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../headers/BinaryTree.h"
#include "../../headers/List.h"

using namespace std;

class Solution {
public:
    int minMaxGame(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];

        while (true) {
            int n = nums.size();
            vector<int> newNums(n / 2);
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0)
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = newNums;

            if (nums.size() == 1)
                break;
        }
        return nums[0];
    }

    int partitionArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 1;
        for (int i = 0, start = nums[0]; i < nums.size(); i++) {
            if (nums[i] - start > k) {
                res++;
                start = nums[i];
            }
        }

        return res;
    }

    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
        unordered_map<int, int> ump;

        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]] = i;
        }

        for (auto &&op : operations) {
            int idx = ump[op[0]];
            nums[idx] = op[1];
            ump.erase(op[0]);
            ump[op[1]] = idx;
        }

        return nums;
    }
};

class TextEditor {
private:
    stack<char> left, right;

public:
    TextEditor() {}

    void addText(string text) {
        for (auto &&c : text) {
            left.push(c);
        }
    }

    int deleteText(int k) {
        int cnt = 0;
        while (!left.empty() && k--) {
            left.pop();
            cnt++;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        string res;
        while (!left.empty() && k--) {
            char c = left.top();
            left.pop();
            right.push(c);
        }

        auto copy = left;
        for (int i = 0; i < 10 && !copy.empty(); i++) {
            res += copy.top();
            copy.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }

    string cursorRight(int k) {
        string res;
        while (!right.empty() && k--) {
            char c = right.top();
            right.pop();
            left.push(c);
        }

        auto copy=left;
        for (int i = 0; i < 10 && !copy.empty(); i++) {
            res += copy.top();
            copy.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}