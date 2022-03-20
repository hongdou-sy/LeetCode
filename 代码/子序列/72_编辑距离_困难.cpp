//方法一:动态规划(自底向上) 
//时间击败72%,空间击败29% 
class Solution{
public:
	int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		vector<vector<int> > dp(m+1, vector<int>(n+1));
		
		//初始化dp数组
		for(int i=0; i<=m; i++)
		{
			dp[i][0] = i;
		} 
		for(int j=0; j<=n; j++)
		{
			dp[0][j] = j;
		}
		
		//维护dp数组
		for(int i=1; i<=m; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(word1[i-1] == word2[j-1])
					dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1]);
				else
					dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
			}
		 } 
		 return dp[m][n];
	}
};

//方法二:递归(自上而下) 
//未添加记忆化代码:超时 
class Solution{
public:
	int helper(string word1, int i, string word2, int j)
	{
		//递归边界
		if(i == 0)
			return j;
		if(j == 0)
			return i;
		if(word1[i-1] == word2[j-1])
			return min(min(helper(word1, i - 1, word2, j) + 1, helper(word1, i, word2, j - 1) + 1), helper(word1, i - 1, word2, j - 1));
		else
			return min(min(helper(word1, i - 1, word2, j) + 1, helper(word1, i, word2, j - 1) + 1), helper(word1, i - 1, word2, j - 1) + 1); 
	}
	
	int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		int ans = helper(word1, m, word2, n);
		return ans;
	}
}; 

//方法二:递归
//添加记忆化代码
//时间击败5%,空间击败5% 
class Solution{
private:
	vector<vector<int> > dp; 
public:
	int helper(string word1, int i, string word2, int j)
	{
		//递归边界
		if(i == 0)
			return j;
		if(j == 0)
			return i;
			
		if(dp[i][j] != -1)
			return dp[i][j];
		
		if(word1[i-1] == word2[j-1])
			dp[i][j] = min(min(helper(word1, i - 1, word2, j) + 1, helper(word1, i, word2, j - 1) + 1), helper(word1, i - 1, word2, j - 1));
		else
			dp[i][j] = min(min(helper(word1, i - 1, word2, j) + 1, helper(word1, i, word2, j - 1) + 1), helper(word1, i - 1, word2, j - 1) + 1); 
		return dp[i][j];	
	}
	
	int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		dp.resize(m + 1, vector<int>(n + 1, -1));
		int ans = helper(word1, m, word2, n);
		return ans;
	}
}; 
