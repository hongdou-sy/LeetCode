//动态规划 
//时间击败100%,空间击败44% 
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int> > dp(m, vector<int>(n));
		//初始化dp数组
		for(int i = 0; i < m; i++)
		{
			dp[i][0] = 1;
		}
		for(int j = 0; j < n; j++)
		{
			dp[0][j] = 1;
		}
		
		//维护dp数组
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

//动态规划:优化空间
//使用滚动数组
//时间击败100%,空间击败76% 
class Solution{
public:
	int uniquePaths(int m, int n)
	{
		vector<int> dp(n);
		//初始化dp数组
		for(int i = 0; i < n; i++)
		{
			dp[i] = 1;
		} 
		//维护dp数组
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++) //滚动数组的j应该从后往前遍历 
			{
				dp[j] = dp[j] + dp[j - 1];
			}
		} 
		
		return dp[n - 1];
	}
}; 

//递归
//时间击败100%,空间击败29% 
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

//排列组合
//时间击败100%,空间击败76% 
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
