#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int count = 0;
		unordered_map<int, int> occ;

		for (auto elem : nums) {
			if (occ.find(elem) != occ.end()) {
				count += occ[elem];
			}
			occ[elem]++;
		}

		return count;
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