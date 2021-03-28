#include <string>
#include <sstream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <stack>
#include <set>
#include "unordered_set"
#include "queue"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <numeric>
#include <unordered_map>
using namespace std;

// 2
int bestMethod(vector<int>& cash_needed4product, vector<int>& benifit, int n, int M) {
    vector<int> max_benifit(M + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int cash = cash_needed4product[i]; cash <= M; cash++) {
            max_benifit[cash] = max(max_benifit[cash], max_benifit[cash - cash_needed4product[i]] + benifit[i]);
        }
    }
    return max_benifit[M];
}

// 3
TreeNode* CommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return p_q_ancestor_or_p_q(root, p, q);
}
TreeNode* p_q_ancestor_or_p_q(TreeNode* root, TreeNode* p, TreeNode* q) {
    
}
