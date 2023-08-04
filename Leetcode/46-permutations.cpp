#include <bits/stdc.h>
using namespace std;

// approach 1 : swap method

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> ans;
		helper(0, nums, ans);
		return ans;

	}

private:
	void helper(int ind, vector<int>& nums, vector<vector<int>>& ans) {
		if (ind == nums.size()) {
			ans.push_back(nums);
			return;
		}

		for (int i = ind; i < nums.size(); i++) {
			swap(nums[ind], nums[i]);
			helper(ind + 1, nums, ans);
			swap(nums[ind], nums[i]);
		}
	}
};

// approach 2 : extra space
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> temp;
		vector<int> picked(nums.size(), -1);

		helper(nums, temp, picked, result);

		return result;

	}

private:
	void helper(vector<int>& nums, vector<int>& temp, vector<int>& picked, vector<vector<int>>& result) {

		if (temp.size() == nums.size()) {
			result.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (picked[i] == -1) {
				picked[i] = 1;
				temp.push_back(nums[i]);
				helper(nums, temp, picked, result);
				picked[i] = -1;
				temp.pop_back();
			}
		}

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