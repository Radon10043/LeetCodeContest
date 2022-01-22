/*
 * @Author: Radon
 * @Date: 2022-01-08 22:42:04
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-22 22:35:01
 * @Description: Hi, say something
 */
#include "../../headers/List.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * @brief Ac
     *
     * @param title
     * @return string
     */
    string capitalizeTitle(string title) {
        int n = title.length();
        int begin = 0, end = 0;
        for (int i = 0; i <= n; i++) {
            if (title[i] == ' ' || i == n) {
                end = i;
                for (int j = begin; j < end; j++) {
                    title[j] = tolower(title[j]);
                }
                if (end - begin > 1) {
                    title[begin] = toupper(title[begin]);
                }
                begin = i + 1;
            }
        }
        return title;
    }

    /**
     * @brief Ac
     *
     * @param head
     * @return int
     */
    int pairSum(ListNode *head) {
        vector<int> vals;
        ListNode *p = head;
        int n = 0, res = 0;
        while (p) {
            vals.emplace_back(p->val);
            n++;
            p = p->next;
        }

        for (int i = 0; i <= n / 2 - 1; i++) {
            res = max(res, vals[i] + vals[n - 1 - i]);
        }
        return res;
    }

    int longestPalindrome(vector<string> &words) {
        map<string, int> umap;
        int res = 0;
        for (string word : words) {
            umap[word]++;
        }

        bool addOneSameWord = false;
        int maxSameWordCnt = 0;
        for (map<string, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            char c1 = it->first[0], c2 = it->first[1];
            string origin(it->first), change(it->first);
            change[0] = c2;
            change[1] = c1;
            if (c1 != c2)
                res += 4 * min(umap[origin], umap[change]);
            else {
                maxSameWordCnt = max(maxSameWordCnt, umap[origin]);
                if (umap[origin] == 1 && !addOneSameWord) {
                    res += 2;
                    addOneSameWord = true;
                } else {
                    res += umap[origin] / 2 * 4;
                }
            }
            umap[origin] = umap[change] = 0;
        }
        // res = maxSameWordCnt == 1 || !maxSameWordCnt ? res : res - 2 * (maxSameWordCnt - 1) + maxSameWordCnt * 2;
        if (maxSameWordCnt % 2 && maxSameWordCnt > 1) {
            res = res - 2 * (maxSameWordCnt - 1) + maxSameWordCnt * 2;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<string> words = {"nn", "nn", "hg", "gn", "nn", "hh", "gh", "nn", "nh", "nh"};
    sol.longestPalindrome(words);
    return 0;
}
