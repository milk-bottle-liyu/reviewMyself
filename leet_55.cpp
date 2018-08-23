static const auto speedup = [](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxDis = 0;
		for (unsigned i = 0; i < nums.size(); i++)
		{
			if (maxDis >= i)
			{
				maxDis = maxDis > (i + nums[i]) ? maxDis : (i + nums[i]);
			}
			else
			{
				break;
			}
		}
		return (maxDis >= nums.size() - 1);
	}
};
