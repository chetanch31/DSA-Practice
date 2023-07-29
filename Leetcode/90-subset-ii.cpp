class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(0, nums, ans, temp);
        return ans;
    }

private:
    void helper(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        ans.push_back(temp);

        for (int i = ind; i < nums.size(); i++) {
            if (i != ind and nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            helper(i + 1, nums, ans, temp);
            temp.pop_back();
        }
    }

};