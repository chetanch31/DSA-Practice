#include <bits/stdc.h>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		helper(board);
	}

private:
	bool ifPossible(int row, int col, char c, vector<vector<char>>& board) {

		for (int i = 0; i < 9; i++) {

			if (board[row][i] == c) return false;
			if (board[i][col] == c) return false;
			if (board[3 * (row / 3) + i / 3 ][3 * (col / 3) + i % 3] == c) return false;

		}
		return true;
	}

	bool helper(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {

				if (board[i][j] == '.') {

					for (char c = '1'; c <= '9'; c++) {
						if (ifPossible(i, j, c, board)) {
							board[i][j] = c;

							if (helper(board) == true) return true;
							else board[i][j] = '.';
						}
					}

					return false;

				}

			}
		}

		return true;
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