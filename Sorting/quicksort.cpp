#include <bits/stdc.h>
using namespace std;

// Implements quick sort
// Time complexity - O(nlogn)
// Space complexity - O(1)

int createPart(vector<int> &arr, int low, int high) {
	int pivot = arr[low];
	int i = low, j = high;

	while (i < j) {
		while (arr[i] <= pivot and i <= high - 1) {i++;}

		while (arr[j] > pivot and j >= low + 1) {j--;}

		if (i < j) swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);
	return j;
}

void quicksort(vector<int> &arr, int low, int high) {

	if (low < high) {
		int part = createPart(arr, low, high);
		quicksort(arr, low, part - 1);
		quicksort(arr, part + 1, high);
	}

}

void sorting(vector<int> &arr) {
	quicksort(arr, 0, arr.size() - 1);
	return;
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