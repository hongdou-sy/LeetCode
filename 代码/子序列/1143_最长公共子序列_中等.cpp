//��̬�滮:�����ַ�������ƥ��,ʹ�õ�dp�����Ȼ�Ƕ�ά���� 
//ʱ�����74%,�ռ����73% 
class Solution{
public:
	int longestCommonSubsequence(string text1,string text2)
	{
		int m=text1.length();
		int n=text2.length();
		//�����άdp����,dp[i][j]��ʾtext1����Ϊi��ǰ׺��text2����Ϊj��ǰ׺������������еĳ��� 
		vector<vector<int> > dp(m+1,vector<int>(n+1)); 
		
		//��ʼ��dp���� 
		for(int i=0;i<=m;i++)
		{
			dp[i][0]=0; //text2�Ŀ��Ӵ���text1����Ϊi��ǰ׺�Ӵ�������������еĳ��ȱ�Ȼ��0 
		}
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=0; //text1�Ŀ��Ӵ���text2����Ϊi��ǰ׺�Ӵ�������������еĳ��ȱ�Ȼ��0
		}
		
		//ά��dp����
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//���text1�ĵ�i��Ԫ��==text2�ĵ�j��Ԫ�� 
				if(text1[i-1]==text2[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				//���text1�ĵ�i��Ԫ��!=text2�ĵ�j��Ԫ��
                else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				} 
			}
		}
		return dp[m][n];
	}
};
