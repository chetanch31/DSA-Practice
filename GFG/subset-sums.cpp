// question link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sums;
        helper(0, 0, arr, sums);

        return sums;
    }

private:
    void helper(int ind, int sum, vector<int>& arr, vector<int>& sums) {
        if (ind == arr.size()) {
            sums.push_back(sum);
            return;
        }

        helper(ind + 1, sum + arr[ind], arr, sums);
        helper(ind + 1, sum, arr, sums);

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0 ; i < N ; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends