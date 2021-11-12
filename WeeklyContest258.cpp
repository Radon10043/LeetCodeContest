/*
 * @Author: Radon
 * @Date: 2021-11-05 16:53:58
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-05 17:16:34
 * @Description: Hi, say something
 */
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-10

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, n = word.size();
        for (; i < n; i++) {
            if (word[i] == ch)
                break;
        }

        if (i < n)
            reverse(word.begin(), word.begin() + i + 1);
        return word;
    }

    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        unordered_map<double, long long> umap;
        for (vector<int> r : rectangles) {
            umap[(double)r[0] / (double)r[1]]++;
        }

        long long result = 0;
        for (unordered_map<double, long long>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->second > 1)
                result += it->second * (it->second - 1) / 2;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> rectangles = {{4,5},{7,8}};
    s.interchangeableRectangles(rectangles);
    return 0;
}