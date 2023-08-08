#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> ans;
		vector<string> temp(n, string(n, '.'));
		helper(0, n, temp, ans);
		return ans;

	}

private:

	bool possible(int row, int col, int n, vector<string>& temp) {

		int r = row, c = col;

		// check upper diagonal
		while (row >= 0 and col >= 0) {
			if (temp[row--][col--] == 'Q') return false;
		}

		row = r;
		col = c;

		//check right
		while (col >= 0) {
			if (temp[row][col--] == 'Q') return false;
		}

		row = r;
		col = c;


		// check lower diagonal
		while (row<n and col >= 0) {
			if (temp[row++][col--] == 'Q') return false;
		}

		return true;
	}

	void helper(int col, int n, vector<string>& temp, vector<vector<string>>& ans) {
		if (col == n) {
			ans.push_back(temp);
			return;
		}

		for (int row = 0; row < n; row++) {
			if (possible(row, col, n, temp)) {
				temp[row][col] = 'Q';
				helper(col + 1, n, temp, ans);
				temp[row][col] = '.';
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

	Solution sol;
	vector<vector<string>> output = sol.solveNQueens(n);

	for (const auto& solution : output) {
		cout << "[";
		for (int i = 0; i < n; i++) {
			cout << "\"" << solution[i] << "\"";
			if (i != n - 1) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}

	return 0;
}
