#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
	vector<vector<int>> map;
	MyHashMap() {}

	void put(int key, int value) {
		for (int i = 0; i < map.size(); i++) {
			if (map[i][0] == key) {
				map[i][1] = value;
				return;
			}
		}
		map.push_back({key, value});
	}

	int get(int key) {
		for (int i = 0; i < map.size(); i++) {
			if (map[i][0] == key) return map[i][1];
		}
		return -1;
	}

	void remove(int key) {
		for (int i = 0; i < map.size(); i++) {
			if (map[i][0] == key) {
				map.erase(map.begin() + i);
				return;
			}
		}
	}
};

int main() {
	MyHashMap hashMap;
	vector<string> operations = {"MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"};
	vector<vector<int>> values = {{}, {1, 1}, {2, 2}, {1}, {3}, {2, 1}, {2}, {2}, {2}};

	vector<int> result;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == "MyHashMap") {
			hashMap = MyHashMap();
			result.push_back(-1);  // Append null for constructor call.
		} else if (operations[i] == "put") {
			hashMap.put(values[i][0], values[i][1]);
			result.push_back(-1);  // Append null for put operation.
		} else if (operations[i] == "get") {
			result.push_back(hashMap.get(values[i][0]));
		} else if (operations[i] == "remove") {
			hashMap.remove(values[i][0]);
			result.push_back(-1);  // Append null for remove operation.
		}
	}

	// Print the output
	cout << "[";
	for (int i = 0; i < result.size(); i++) {
		cout << (i > 0 ? ", " : "") << result[i];
	}
	cout << "]" << endl;
}
