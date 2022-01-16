/*
 * @Author: Radon
 * @Date: 2021-11-07 10:27:29
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-07 11:56:24
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: 暴力解
     * @param {string} word
     * @return {*}
     */
    int countVowelSubstrings(string word) {
        int n = word.size();
        if (n < 5)
            return 0;

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 4; j < n; j++) {
                unordered_set<char> vowelUSet;
                bool isAllVowel = true;
                for (int k = i; k <= j; k++) {
                    if (word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u') {
                        vowelUSet.insert(word[k]);
                    } else {
                        isAllVowel = false;
                        break;
                    }
                }
                if (isAllVowel && vowelUSet.size() == 5) {
                    result++;
                }
            }
        }
        return result;
    }

    /**
     * @description: dp
     * @param {string} word
     * @return {*}
     */
    long long countVowels(string word) {
        long long result = 0;
        int n = word.size();
        vector<long long> dp(n, 0);
        unordered_set<char> vowelUSet = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = find(vowelUSet.begin(), vowelUSet.end(), word[i]) != vowelUSet.end() ? 1 : 0;
            else {
                if (find(vowelUSet.begin(), vowelUSet.end(), word[i]) != vowelUSet.end())
                    dp[i] = dp[i - 1] + i + 1;
                else
                    dp[i] = dp[i - 1];
            }
            result += dp[i];
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    s.countVowelSubstrings("cuaieuouac");
    return 0;
}