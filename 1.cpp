#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int cnt = 0;
    while (left <= right) {
        if (nums[right] - nums[left] <= x) break;
        cnt++;
        if (left + 1 < right && nums[right] - nums[left+1] >= nums[right-1] - nums[left])
            right--;
        else left++;
    }
    cout << cnt << endl;
    return 0;
}
