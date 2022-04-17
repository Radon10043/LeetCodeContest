/*
 * @Author: Radon
 * @Date: 2022-04-16 14:59:31
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-17 10:33:48
 * @Description: Hi, say something
 */
#include "../../headers/BinaryTree.h"
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
    /* 1 */
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (auto op : operations) {
            int cnt = gem[op[0]] / 2;
            gem[op[0]] -= cnt;
            gem[op[1]] += cnt;
        }

        int maxGem = *max_element(gem.begin(), gem.end());
        int minGem = *min_element(gem.begin(), gem.end());
        return maxGem - minGem;
    }

    /* 2 */

    int res2 = 0;

    void backtrack(int delic, int stom, int idx, vector<int> materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        if (stom >= limit)
            res2 = max(res2, delic);
        if (!materials[0] && !materials[1] && !materials[2] && !materials[3] && !materials[4])
            return;
        for (int i = idx; i < cookbooks.size(); i++) {
            if (materials[0] >= cookbooks[i][0] && materials[1] >= cookbooks[i][1] && materials[2] >= cookbooks[i][2] && materials[3] >= cookbooks[i][3] &&
                materials[4] >= cookbooks[i][4]) {
                vector<int> nMaterials = materials;
                nMaterials[0] -= cookbooks[i][0];
                nMaterials[1] -= cookbooks[i][1];
                nMaterials[2] -= cookbooks[i][2];
                nMaterials[3] -= cookbooks[i][3];
                nMaterials[4] -= cookbooks[i][4];
                backtrack(delic + attribute[i][0], stom + attribute[i][1], i + 1, nMaterials, cookbooks, attribute, limit);
            }
        }
    }

    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        int delic = 0, stom = 0, idx = 0;
        backtrack(delic, stom, idx, materials, cookbooks, attribute, limit);
        return res2 == 0 ? -1 : res2;
    }

    /* 3 */
    int getNumber(TreeNode *root, vector<vector<int>> &ops) {
        vector<int> nodes, red;

        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (root->left)
                dfs(root->left);
            nodes.emplace_back(root->val);
            if (root->right)
                dfs(root->right);
        };

        dfs(root);

        for (auto op : ops) {
            int left = lower_bound(nodes.begin(), nodes.end(), op[1]) - nodes.begin();
            int right = lower_bound(nodes.begin(), nodes.end(), op[2]) - nodes.begin();

            if (!op[0]) { // 染蓝
                set_difference(red.begin(), red.end(), nodes.begin() + left, nodes.begin() + right, red.begin());
            } else if (op[0]) { // 染红
                set_union(red.begin(), red.end(), nodes.begin() + left, nodes.begin() + right, red.begin());
            }
        }

        return red.size();
    }
};

int main(int argc, char **argv) {
    Solution sol;
    TreeNode* root = new TreeNode();
    vector<int> nodes = {1,null,2,null,3,null,4,null,5};
    createTree(root, nodes, 0);
    vector<vector<int>> ops = {{1,2,4},{1,1,3},{0,3,5}};
    sol.getNumber(root, ops);
    return 0;
}