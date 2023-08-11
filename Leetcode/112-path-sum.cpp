#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root) return false;

		targetSum -= root->val;
		if (targetSum == 0 and !root->left and !root->right) return true;

		bool left = hasPathSum(root->left, targetSum);
		bool right = hasPathSum(root->right, targetSum);

		return left or right;
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