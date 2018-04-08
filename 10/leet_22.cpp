class Solution {
public:
    char *rc;
    vector<string> hh;
    int l;
    void build(int depth,int flag,int left)
    {
        if (depth==l*2 && left==0)
        {
            rc[l*2]='\0';
            hh.push_back(rc);
        }
        else
        {
            if (left>0)
            {
                rc[depth]='(';
                build(depth+1,flag+1,left-1);
            }
            if (flag>0)
            {
                rc[depth]=')';
                build(depth+1,flag-1,left);
            }
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        l=n;
        rc=(char*)malloc(n+1);
        build(0,0,n);
        return hh;
    }
};