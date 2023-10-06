#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> ans;

		int elem1 = INT_MIN, elem2 = INT_MIN;
		int count1 = 0, count2 = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (count1 == 0 and elem2 != nums[i]) {
				count1++;
				elem1 = nums[i];
			}

			else if (count2 == 0 and elem1 != nums[i]) {
				count2++;
				elem2 = nums[i];
			}

			else if (nums[i] == elem1) count1++;

			else if (nums[i] == elem2) count2++;

			else {
				count1--;
				count2--;
			}

		}

		count1 = 0;
		count2 = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == elem1) count1++;
			if (nums[i] == elem2) count2++;
		}

		int thresh = nums.size() / 3;
		if (count1 > thresh) ans.push_back(elem1);
		if (count2 > thresh) ans.push_back(elem2);

		return ans;
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