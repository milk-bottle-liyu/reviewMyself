class Solution {
public:
    
    void solve4(vector<int> & nums, int count, int start, int left,vector<int> &oneSolution, vector<vector<int>> &rc)
{
	if (count == 4)
	{
		if (left==0)
			rc.push_back(oneSolution);
		return;
	}
	for (unsigned i = start; i < nums.size(); i++)
	{
        if (i > start && nums[i] == nums[i - 1])
			continue;

			left -= nums[i];
			oneSolution.push_back(nums[i]);
			solve4(nums, count + 1, i + 1, left, oneSolution, rc);
			oneSolution.pop_back();
			left += nums[i];

	}
}
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> rc;
	if (nums.size() == 0)
		return rc;
	sort(nums.begin(), nums.end());
	vector<int> oneSolution;
	solve4(nums, 0, 0, target,oneSolution, rc);

	return rc;
}
    
};
