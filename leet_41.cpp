class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int tmp;
    for (unsigned i=0;i<nums.size();i++)
    {
        if (nums[i]<=0 || nums[i]>nums.size() )
            nums[i]=-1;
        while (nums[i]!=i+1 && nums[i]>0)
        {
            tmp=nums[i];
            nums[i]=nums[tmp-1];
            nums[tmp-1]=tmp;
            if (nums[i]==tmp||nums[i]>nums.size()||nums[i]<=0)
                nums[i]=-1;
        }
    }
    int rc=0;
    for (rc=0;rc<nums.size();rc++)
    {
        if (nums[rc]==-1)
            break;
    }
    return rc+1;
    }
};
