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

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> costs;
    for (int i = 0; i < n; ++i) {
        int tem;
        cin >> tem;
        costs.push_back(tem);
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
        if (!flag) i = (i + 1) % (costs.size());
        else 
            i = i % costs.size();
    }
    cout << ret  << endl;
    return 0;
}


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
using LL = long long;
int main() {
    LL n, capacity;
    cin >> n >> capacity;
    vector<int> costs;
    for (int i = 0; i < n; ++i) {
        int tem;
        cin >> tem;
        costs.push_back(tem);
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
        if (flag)
            start++;
        else
            start = 0;
        if (start >= costs.size()) break;
        if (!flag)
            i = (i + 1) % (costs.size());
        else 
            i = i % costs.size();
    }
    cout << ret  << endl;
    return 0;
}



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
using LL = long long;
int main() {
    LL n, capacity;
    cin >> n >> capacity;
    vector<int> costs;
    for (int i = 0; i < n; ++i) {
        int tem;
        cin >> tem;
        costs.push_back(tem);
    }
    int ret = 0, i = 0, circle_start = 0, loop_circle = false;
    while (capacity >= 0) {
        if (capacity - costs[i] >= 0) {
            ret++;
            capacity -= costs[i];
            loop_circle = false;
            circle_start = 0;
        } else {
            loop_circle = true;
            circle_start++;
        }
        i = (i + 1) % n;
        if (circle_start > n) break; 

    }
    cout << ret  << endl;
    return 0;
}



class Minstack{
    public:
        MinStack() {}
        void push(int x) {
            _s.push(x);
            if (_minS.empty() || _minS.top() >= x) {
                _minS.push(x);
            }
        }
        void 
    private:
        stack<int> _minS;
        stack<int> _s;
};