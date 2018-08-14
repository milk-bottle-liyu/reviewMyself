class Solution {
public:
    void solution(vector<vector<int>> & rc, vector<int> & count,vector<int> & candidate,int start, int left)
{
	for (unsigned i = start; i < candidate.size(); i++)
	{
		if (left > candidate[i])
		{
			left -= candidate[i];
			count.push_back(candidate[i]);
			solution(rc, count, candidate, i, left);
			left += candidate[i];
			count.pop_back();
		}
		else if (left == candidate[i])
		{
			rc.push_back(count);
			rc[rc.size() - 1].push_back(candidate[i]);
			break;
		}
		else
			break;
	}
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     	vector<vector<int>> rc;
	if (candidates.size() == 0) return rc;
	sort(candidates.begin(), candidates.end());
	vector<int> count;
	solution(rc, count, candidates,0, target);

	return rc;   
    }
};
