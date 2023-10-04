#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool winnerOfGame(string colors) {

		int count = 1;
		int alice = 0, bob = 0;

		for (int i = 1; i < colors.size(); i++) {
			if (colors[i] == colors[i - 1]) {
				count++;
				if (count >= 3) {
					if (colors[i - 1] == 'A') alice++;
					else bob++;
				}
			}

			else count = 1;
		}

		return alice > bob;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	string colors;
	cin >> colors;

	Solution solution;

	bool result = solution.winnerOfGame(colors);

	cout << result;
}
