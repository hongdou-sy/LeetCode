//动态规划:两个字符串进行匹配,使用的dp数组必然是二维数组 
//时间击败74%,空间击败73% 
class Solution{
public:
	int longestCommonSubsequence(string text1,string text2)
	{
		int m=text1.length();
		int n=text2.length();
		//定义二维dp数组,dp[i][j]表示text1长度为i的前缀与text2长度为j的前缀的最长公共子序列的长度 
		vector<vector<int> > dp(m+1,vector<int>(n+1)); 
		
		//初始化dp数组 
		for(int i=0;i<=m;i++)
		{
			dp[i][0]=0; //text2的空子串与text1长度为i的前缀子串的最长公共子序列的长度必然是0 
		}
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=0; //text1的空子串与text2长度为i的前缀子串的最长公共子序列的长度必然是0
		}
		
		//维护dp数组
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//如果text1的第i个元素==text2的第j个元素 
				if(text1[i-1]==text2[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				//如果text1的第i个元素!=text2的第j个元素
                else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				} 
			}
		}
		return dp[m][n];
	}
};
