#include <bits/stdc.h>
using namespace std;

// Implements merge sort
// Time complexity - O(nlogn)
// Space complexity - O(N)

void merge(vector<int> &arr, int low, int mid, int high) {
	vector <int> temp;

	int left = low, right = mid + 1;

	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left++]);
		}
		else {
			temp.push_back(arr[right++]);
		}
	}

	while (left <= mid) {
		temp.push_back(arr[left++]);
	}

	while (right <= high) {
		temp.push_back(arr[right++]);
	}

	for (int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}
}

void mergeSort(vector<int> &arr, int low, int high) {
	if (low >= high) return;

	int mid = (low + high) / 2;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);

	merge(arr, low, mid, high);
}

void sorting(vector<int> &arr) {
	int n = arr.size();
	int low = 0, high = n - 1;

	mergeSort(arr, low, high);
}

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

	sorting(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}