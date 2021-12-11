/*
 * @Author: Radon
 * @Date: 2021-11-27 22:26:11
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-27 23:53:47
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
     * @description: Accept
     * @param {vector<string> &words1, vector<string>} &words2
     * @return {*}
     */
    int countWords(vector<string> &words1, vector<string> &words2) {
        unordered_map<string, int> word1Map, word2Map;
        for (string word : words1)
            word1Map[word]++;
        for (string word : words2)
            word2Map[word]++;

        int result = 0;
        for (unordered_map<string, int>::iterator it = word1Map.begin(); it != word1Map.end(); it++) {
            if (it->second == 1 && word2Map[it->first] == 1)
                result++;
        }
        return result;
    }

    /**
     * @description: Accept
     * @param {string} street
     * @return {*}
     */
    int minimumBuckets(string street) {
        int n = street.length();
        vector<int> HLocs;
        for (int i = 0; i < n; i++)
            if (street[i] == 'H')
                HLocs.emplace_back(i);

        int m = HLocs.size();
        if (m == n)
            return -1;
        if (!m)
            return 0;
        if (street.find("HHH") != string::npos)
            return -1;
        if (m == 1 && n > m)
            return 1;
        if (street[0] == 'H' && street[1] == 'H' || street[n - 1] == 'H' && street[n - 2] == 'H')
            return -1;

        int result = 0;
        for (int i = 1; i < m; i++) {
            if (HLocs[i] - HLocs[i - 1] == 1 && (HLocs[i] == 1 || HLocs[i] == n - 1))
                return -1;
            if (HLocs[i] - HLocs[i - 1] == 2) {
                result++;
                if (i + 2 == m)
                    return result + 1;
                i++;
            } else {
                result++;
            }
            if (i == m - 1)
                result++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string street = ".H..H.HH";
    cout << s.minimumBuckets(street) << endl;
    return 0;
}