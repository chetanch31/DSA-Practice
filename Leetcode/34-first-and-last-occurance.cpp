#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		int start = -1, end = -1;

		while (low < high) {
			int mid = (low + high) / 2;

			if (nums[mid] == target) {
				start = mid;
				end = mid;
				while (start >= 0 && nums[start] == target) {
					start--;
				}
				while (end < nums.size() && nums[end] == target) {
					end++;
				}
				start++;
				end--;
				break;
			}

			if (nums[mid] < target) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		return {start, end};
	}
};

int main() {

#ifndef ONLINE_JUDGE

	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

#endif

	int target;
	cin >> target;

	int n;
	cin >> n;


	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Solution sol;
	vector<int> out = sol.searchRange(arr, target);

	cout << out[0] << " " << out[1] << endl;
}