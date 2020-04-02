#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack {
public:
    MinStack() {}
    void push(int x) {
        _s.push(x);
        if (_minS.empty() || _minS.top() >= x)
            _minS.push(x);
    }
    void pop() {
        if (_s.empty()) return;
        if (_s.top() == _minS.top()) 
            _minS.pop();
        _s.pop();
    }
    int top() {
        return _s.top();
    }
    int getMin() {
        if (_minS.empty()) return -1;
        return _minS.top();
    }
private:
    stack<int> _minS;
    stack<int> _s;
};
class MaxStack {
public:
    MaxStack() { }
    void push(int x) {
        _s.push(x);
        if (_maxS.empty() || _maxS.top() <= x)
            _maxS.push(x);
    }
    void pop() {
        if (_s.empty()) return;
        if (_s.top() == _maxS.top()) 
            _maxS.pop();
        _s.pop();
    }
    int top() {
        return _s.top();
    }
    int getMax() {
        if (_maxS.empty()) return -1;
        return _maxS.top();
    }
private:
    stack<int> _maxS;
    stack<int> _s;
};
MinStack* createMinStack(vector<int>& nums, int i) {
    MinStack * minS = new MinStack();
    for (int j = i; j >= 0; j--) {
        minS->push(nums[j]);
    }
    return minS;
}
MaxStack* createMaxStack(vector<int>& nums, int i) {
    MaxStack* maxS = new MaxStack();
    for (int j = i; j >= 0; j--) {
        maxS->push(nums[j]);
    }
    return maxS;
}
int main () {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int ret = 0;
    for (int i = nums.size() - 1; i > 0; i--) {
        MinStack *mins = createMinStack(nums, i);
        MaxStack *maxs = createMaxStack(nums, i);
        for (int j = 0; j < i; j++) {
            int max_num = maxs->getMax(), min_num = mins->getMin();
            ret ^= (max_num ^ min_num);
            mins->pop();
            maxs->pop();
        }
    }
    cout << ret << endl;
    return 0;
}
