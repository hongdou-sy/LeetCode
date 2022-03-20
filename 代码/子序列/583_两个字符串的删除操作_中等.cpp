//方法一:最长公共子序列 
//时间击败64%,空间击败26% 
class Solution{
public:
	int minDistinct(string word1, string word2)
	{
		//首先获取两个字符串的最长公共子序列
		//再用两个字符串的长度减去该最长公共子序列的长度
		int m = word1.length();
		int n = word2.length();
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
		
		for(int i=1; i<=m; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //既然是最长公共子序列,取的必然是最大值 
			}
		}
		int maxLength = dp[m][n]; //得到最长公共子序列的长度
		int res = (m - maxLength) + (n - maxLength);
		return res; 
	}
};

//方法二:动态规划
//时间击败96%,空间击败57% 
public:
	int minDistinct(string word1, string word2)
	{
		int m = word1.length();
		int n = word2.length();
		//dp[i][j]表示word1的前i个字符和word2的前j个字符的最少删除次数 
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
		
		//初始化dp数组
		//当i=0时,word1为空字符串,word2必须删除所有字符
		for(int j=0; j<=n; j++)
			dp[0][j] = j;
		//当j=0时,word2为空字符串,word1必须删除所有字符
		for(int i=0; i<=m; i++)
			dp[i][0] = i; 
			
		//维护dp数组
		for(int i=1; i<=m; i++)
		{
			for(int j=1; j<=n; j++)
			{
				//如果两个字符相等,就不需要删除 
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				//如果两个字符不等,要么删除word1[i-1],要么删除word2[j-1]
				else
					dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1); //既然是最少删除次数,取的必然是最小值 
			}
		} 
		return dp[m][n];
	}
};

 
