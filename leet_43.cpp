class Solution {
public:
    string multiply(string num1, string num2) {
    	int * rc[11];
	for (int i = 0; i < 10; i++)
	{
		rc[i] = (int*)malloc(sizeof(int) * 200);
		memset(rc[i], 0, sizeof(int) * 200);
	}
	rc[10] = (int*)malloc(sizeof(int) * 400);
	memset(rc[10], 0, sizeof(int) * 400);

	//*0
	rc[0][0] = 1;
	//*1...*9
	for (unsigned i = 0; i < num1.length(); i++)
	{
		rc[1][num1.length() - i] = num1[i] - '0';
	}
	rc[1][0] = num1.length();
	for (unsigned k = 2; k <= 9; k++)
	{
		for (unsigned i=1;i<=num1.length();i++)
			if (k*rc[1][i] + rc[k][i] > 9)
			{
				rc[k][i + 1] = (k*rc[1][i] + rc[k][i]) / 10;
				rc[k][i] = (k*rc[1][i] + rc[k][i]) % 10;
			}
			else
			{
				rc[k][i] = k * rc[1][i] + rc[k][i];
			}
		rc[k][0] = num1.length();
		if (rc[k][num1.length() + 1] > 0)
			rc[k][0]++;
	}
	
	int tmp,offset;
	for (int i = num2.length() - 1; i >= 0; i--)
	{
		tmp = num2[i] - '0';
		offset= num2.length()-i;
		for (unsigned k = 1; k <= rc[tmp][0]; k++)
		{
			rc[10][k + offset - 1] = rc[10][k + offset - 1] + rc[tmp][k];
		}
	}
	int idx = num1.length()+num2.length()+2;
	for (int i = 1; i <= idx; i++)
		if (rc[10][i] > 9)
		{
			rc[10][i + 1] += rc[10][i] / 10;
			rc[10][i] %= 10;
		}
	while (rc[10][idx] == 0 && idx>1)
		idx--;
	string rcstr;
	rcstr.resize(idx);
	for (unsigned i = idx; i >=1; i--)
	{
		rcstr[idx-i] =  '0' + rc[10][i];
	}
	for (unsigned i = 0; i <= 10; i++)
		free(rc[i]);

	return rcstr;
    }
};
