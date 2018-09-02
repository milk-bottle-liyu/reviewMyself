class Solution {
public:
    string getPermutation(int n, int k) {
        	string rc;
	rc.resize(n);
	long long jc[50];
	jc[0] = 1;
	for (int i = 1; i <= n; i++)
		jc[i] = jc[i - 1] * i;
	char left[10];
	for (int i = 1; i <= n; i++)
		left[i] = '0' + i;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = (k - 1) / jc[n - i - 1]+1;
		rc[i] = left[tmp];
		k = (k - 1) % jc[n - i - 1]+1;
		for (int j = tmp; j < (n - i ); j++)
			left[j] = left[j + 1];
	}

	return rc;
    }
};
