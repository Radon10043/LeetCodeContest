/*
 * @Author: Radon
 * @Date: 2021-12-19 10:34:53
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-19 11:58:13
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
    string firstPalindrome(vector<string> &words) {
        for (string word : words) {
            string temp = word;
            reverse(temp.begin(), temp.end());
            if (temp == word)
                return word;
        }
        return "";
    }

    string addSpaces(string s, vector<int> &spaces) {
        int n = spaces.size();
        int len = s.length() + n;
        s.append(n, ' ');

        int j = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (n - j < 0)
                break;
            if (i - n + j == spaces[n - j]) {
                s[i] = ' ';
                j++;
            } else
                s[i] = s[i - n + j - 1];
        }
        return s;
    }

    long long getDescentPeriods(vector<int> &prices) {
        int n = prices.size();
        long long result = n;
        long long i = 0, j = 0;
        while (j < n) {
            if (j == n - 1) {
                if (i != j)
                    result += (j - i + 1) * (j - i) / 2;
                break;
            }

            if (prices[j + 1] - prices[j] == -1)
                j++;
            else {
                result += (j - i + 1) * (j - i) / 2;
                j++;
                i = j;
            }
        }
        return result;
    }

    int kIncreasing(vector<int> &arr, int k) {
        int n = arr.size();
        int result = 0;
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> prices = {4, 3, 2, 1};
    s.getDescentPeriods(prices);
    return 0;
}