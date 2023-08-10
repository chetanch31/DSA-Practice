#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {

		vector<vector<string>> ans;
		vector<string> temp;

		helper(0, s, temp, ans);

		return ans;
	}

private:

	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--]) return false;
		}
		return true;
	}

	void helper(int ind, string s, vector<string>& temp, vector<vector<string>>& ans) {
		if (ind == s.size()) {
			ans.push_back(temp);
			return;
		}
		for (int i = ind; i < s.size(); ++i) {
			if (isPalindrome(s, ind, i)) {
				temp.push_back(s.substr(ind, i - ind + 1));
				helper(i + 1, s, temp, ans);
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