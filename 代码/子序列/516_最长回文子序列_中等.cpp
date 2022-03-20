//��̬�滮
//ʱ�����31%,�ռ����80% 
class Solution{
public:
	int longestPalindromeSubseq(string s)
	{
		int n=s.size();
		vector<vector<int> > dp(n,vector<int>(n));
		
		//��ʼ��dp����
		for(int i=0;i<n;i++)
		{
			dp[i][i]=1;
		} 
		
		//��s[i]==s[j],dp[i][j]=dp[i+1][j-1],��˱����������,����������д
		for(int j=1;j<n;j++)
		{
			for(int i=j-1;i>=0;i--)
			{
				if(s[i]==s[j])
				{
					if(j-i<2)
					{
						dp[i][j]=2; 
					}
					else
					{
						dp[i][j]=dp[i+1][j-1]+2;
					}
				}
				else
				{
					dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
				}
			}
		} 
		return dp[0][n-1];
	}
}; 
