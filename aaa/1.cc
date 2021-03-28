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
int bestMethod(vector<int>& finance_product_capacity, vector<int>& benifit, int n, int M) {
    vector<int> max_benifit(M + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int cur_c = benifit[i]; cur_c <= M; cur_c++) {
            max_benifit[cur_c] = max(max_benifit[cur_c], max_benifit[cur_c - finance_product_capacity[i]] + benifit[i]);
        }
    }
}