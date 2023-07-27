#include <bits/stdc.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		helper(0, target, candidates, ans, temp);

		return ans;
	}
private:
	void helper(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp) {
		if (target == 0) {
			ans.push_back(temp);
			return;
		}

		for (int i = ind; i < candidates.size(); i++) {

			if (i > ind and candidates[i] == candidates[i - 1]) continue;
			if (candidates[i] > target) break;

			temp.push_back(candidates[i]);
			helper(i + 1, target - candidates[i], candidates, ans, temp);
			temp.pop_back();

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