//��̬�滮 
//ʱ�����100%,�ռ����44% 
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int> > dp(m, vector<int>(n));
		//��ʼ��dp����
		for(int i = 0; i < m; i++)
		{
			dp[i][0] = 1;
		}
		for(int j = 0; j < n; j++)
		{
			dp[0][j] = 1;
		}
		
		//ά��dp����
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		} 
		
		return dp[m - 1][n - 1];
	}
};

//��̬�滮:�Ż��ռ�
//ʹ�ù�������
//ʱ�����100%,�ռ����76% 
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		vector<int> dp(n);
		//��ʼ��dp����
		for(int i = 0; i < n; i++)
		{
			dp[i] = 1;
		} 
		//ά��dp����
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++) //���������jӦ�ôӺ���ǰ���� 
			{
				dp[j] = dp[j] + dp[j - 1];
			}
		} 
		
		return dp[n - 1];
	}
}; 

//�ݹ�
//ʱ�����100%,�ռ����29% 
class Solution{
private:
	vector<vector<int> > dp;
public:
	int helper(int i, int j)
	{
		if(i == 0 || j == 0)
			return 1;
		
		if(dp[i][j] != 0)
			return dp[i][j];
		
		return dp[i][j] = helper(i - 1, j) + helper(i, j - 1);
	}
	
	int uniquePaths(int m, int n)
	{
		dp.resize(m, vector<int>(n));
		return helper(m - 1, n - 1);
	}
}; 

//�������
//ʱ�����100%,�ռ����76% 
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		long long ans = 1;
		for(int x = n, y = 1; y < m; x++, y++)
		{
			ans = ans * x / y;
		}
		return ans;
	}
}; 
