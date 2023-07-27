#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<vector<int>> ans;
		vector<int> temp;

		helper(0, target, candidates, ans, temp);

		return ans;

	}
private:
	void helper(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp) {

		if (ind == candidates.size()) {
			if (target == 0) ans.push_back(temp);

			return;
		}

		if (candidates[ind] <= target) {
			temp.push_back(candidates[ind]);
			helper(ind, target - candidates[ind], candidates, ans, temp);
			temp.pop_back();
		}

		helper(ind + 1, target, candidates, ans, temp);

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

	// printing
	Solution sol;
	vector<vector<int>> result = sol.combinationSum(arr, target);


	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}

		cout << endl;
	}
}