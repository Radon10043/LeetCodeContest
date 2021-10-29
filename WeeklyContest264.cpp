/*
 * @Author: Radon
 * @Date: 2021-10-24 10:37:03
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-27 16:44:35
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
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
    bool isWord(string word) {
        int n = word.length();
        string subWord[2];
        bool meetConn = false;
        if (!n)
            return false;
        if (word[0] == '-' || word[n - 1] == '-')
            return false;
        if (count(word.begin(), word.end(), '-') > 1)
            return false;

        for (int i = 0; i < n; i++) {
            if (word[i] >= '0' && word[i] <= '9')
                return false;
            if (!(word[i] >= 'a' && word[i] <= 'z' || word[i] == '-') && i != n - 1)
                return false;
            if (word[i] == '-') {
                meetConn = true;
                continue;
            }
            if (!meetConn)
                subWord[0] += word[i];
            else
                subWord[1] += word[i];
        }
        if (meetConn && !(isWord(subWord[0]) && isWord(subWord[1])))
            return false;
        return true;
    }

    int countValidWords(string sentence) {
        string word;
        int result = 0;
        for (char c : sentence) {
            if (c != ' ') {
                word += c;
            } else if (word.length() > 0) {
                if (isWord(word)) {
                    // cout << word << endl;
                    result++;
                }
                word.clear();
            }
        }
        if (isWord(word)) {
            // cout << word << endl;
            result++;
        }
        return result;
    }

    bool isBeautiful(int n) {
        unordered_map<int, int> umap;
        while (n) {
            if (umap.find(n % 10) == umap.end())
                umap[n % 10] = 1;
            else
                umap[n % 10]++;
            n /= 10;
        }
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->first != it->second)
                return false;
        }
        return true;
    }

    void getBeautifulNumbers() {
        set<int> beauNums;
        for (int i = 1; i <= 1224444; i++) {
            if (isBeautiful(i))
                beauNums.insert(i);
        }
        for (set<int>::iterator it = beauNums.begin(); it != beauNums.end(); it++) {
            cout << *it << ",";
        }
        cout << endl;
    }

    int nextBeautifulNumber(int n) {
        vector<int> beauNums = {1,      22,     122,    212,    221,    333,    1333,   3133,   3313,   3331,   4444,   14444,  22333,  23233,  23323,  23332,
                                32233,  32323,  32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,  122333, 123233, 123323, 123332, 132233,
                                132323, 132332, 133223, 133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331, 224444, 231233,
                                231323, 231332, 232133, 232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442, 312233,
                                312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312,
                                323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444, 424244, 424424,
                                424442, 442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444};
        int result;
        for (int num : beauNums) {
            result = num;
            if (num > n)
                break;
        }
        return result;
    }

    /**
     * @description: 2021年10月25日
     * @param {int} target
     * @return {*}
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(); // m行, n列
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> stk;
        unordered_map<int, int> umap;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums2[i] > stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                umap[nums2[i]] = -1;
            } else {
                umap[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        for (int &data : nums1) {
            data = umap[data];
        }
        return nums1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}