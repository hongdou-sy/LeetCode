//就是求两个数组的最长公共子序列 
//时间击败87%,空间击败10% 
class Solution{
public:
	int maxUncrossedLines(vector<int>& nums1,vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		//创建m+1行n+1列dp数组,这里所有元素都默认初始化为0,就不用再初始化dp数组了 
		vector<vector<int> > dp(m+1,vector<int>(n+1));
		
		for(int i=1;i<m+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				if(nums1[i-1]==nums2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		return dp[m][n];
	}
};
