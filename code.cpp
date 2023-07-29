#include <bits/stdc.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp;

		helper(0, nums, ans, temp);
		return ans;

	}
private:
	void helper(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int> temp) {

		if (ind == nums.size()) {
			ans.push_back(temp);
			return;
		}

		temp.push_back(nums[ind]);
		helper(ind + 1, nums, ans, temp);
		temp.pop_back();
		helper(ind + 1, nums, ans, temp);
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