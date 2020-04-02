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
        void pop() {
            if (_s.empty()) return;
            if (_s.top() == _minS.top()) _minS.pop();
            _s.pop();
        }
        int top() {return _s.pop();}
        int getMin() {
            if (_minS.empty()) return -1;
            return _minS.top();
        }
    private:
        stack<int> _minS;
        stack<int> _s;
};

class Maxstack{
    public:
        Maxstack() {}
        void push(int x) {
            _s.push(x);
            if (_maxS.empty() || _maxS.top() <= x) {
                _maxS.push(x);
            }
        }
        void pop() {
            if (_s.empty()) return;
            if (_s.top() == _maxS.top()) _maxS.pop();
            _s.pop();
        }
        int top() {return _s.pop();}
        int getMax() {
            if (_maxS.empty()) return -1;
            return _maxS.top();
        }
    private:
        stack<int> _maxS;
        stack<int> _s;
};
MaxStack* creatMaxStack(vector<int>& nums, int i) {
    MaxStack* maxS = new MaxStack();
    for (int j = i; j >= 0; --j) {
        maxS->push(nums[j]);
    }
    return maxS;
}

MinStack* creatMinStack(vector<int>& nums, int i) {
    MinStack* minS = new MaxStack();
    for (int j = i; j >= 0; --j) {
        minS->push(nums[j]);
    }
    return minS;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int ret = 0;
    for (int i = nums.size()- 1; i > 0; --i) {
        MinStack *mins = creatMinStack(nums, i);
        MaxStack *maxs = creatMaxStack(nums, i);
        for (int j = 0; j < i; ++j) {
            int max_num = maxs->getMax(), min_num = mins->getMin();
            ret ^= (max_num ^ min_num);
            mins.pop(); maxs->pop();
        }

    }
    cuot << ret << endl;
    return 0;
}