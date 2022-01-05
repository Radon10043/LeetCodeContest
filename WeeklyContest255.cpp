/*
 * @Author: Radon
 * @Date: 2021-12-09 16:28:27
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-13 09:50:15
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findGCD(vector<int> &nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());

        int result = 1;
        for (int i = 1; i <= minNum; i++) {
            if (maxNum % i == 0 && minNum % i == 0)
                result = i;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}