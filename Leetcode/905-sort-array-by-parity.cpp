#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int fast = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 == 0) {
				swap(nums[i], nums[fast++]);
			}
		}

		return nums;
	}
};

int main() {

#ifndef ONLINE_JUDGE

	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

#endif

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}