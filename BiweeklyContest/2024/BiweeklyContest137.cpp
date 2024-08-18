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

using namespace std;

class Solution {
public:
    vector<int> resultsArray1(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n - k + 1; i++) {
            int mx = nums[i];
            bool flag = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    flag = false;
                    break;
                } else {
                    mx = nums[j];
                }
            }
            if (flag)
                res.push_back(mx);
            else
                res.push_back(-1);
        }

        return res;
    }

    vector<int> resultsArray2(vector<int>& nums, int k) {
        int n = nums.size();
        int tmp = 0;
        vector<int> starts;
        vector<int> res;

        starts.emplace_back(tmp);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                tmp = i;
            }
            starts.emplace_back(tmp);
        }

        for (int i = 0; i < n - k + 1; i++) {
            if (starts[i + k - 1] <= i) {
                res.emplace_back(nums[i + k - 1]);
            } else {
                res.emplace_back(-1);
            }
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    cout << "Hello!" << endl;
    return 0;
}