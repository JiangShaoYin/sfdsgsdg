#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> costs;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        costs.push_back(tmp);
    }
    int ret = 0, i = 0, start = 0, flag = false;
    while (capacity >= 0) {
        if (capacity - costs[i] >= 0) {
          ret++;
          capacity -= costs[i];
          flag = false;
        } else {
          flag = true;
          costs.erase(costs.begin() + i);
        }
        if (flag) start++;
        else start = 0;
        if (start >= costs.size()) break;
        if (!flag)
          i = (i + 1) % (costs.size());
        else i = i % costs.size();
    }
    cout << ret << endl;
    return 0;
}
