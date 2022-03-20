//����һ:����������� 
//ʱ�����64%,�ռ����26% 
class Solution{
public:
	int minDistinct(string word1, string word2)
	{
		//���Ȼ�ȡ�����ַ����������������
		//���������ַ����ĳ��ȼ�ȥ������������еĳ���
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
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //��Ȼ�������������,ȡ�ı�Ȼ�����ֵ 
			}
		}
		int maxLength = dp[m][n]; //�õ�����������еĳ���
		int res = (m - maxLength) + (n - maxLength);
		return res; 
	}
};

//������:��̬�滮
//ʱ�����96%,�ռ����57% 
public:
	int minDistinct(string word1, string word2)
	{
		int m = word1.length();
		int n = word2.length();
		//dp[i][j]��ʾword1��ǰi���ַ���word2��ǰj���ַ�������ɾ������ 
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
		
		//��ʼ��dp����
		//��i=0ʱ,word1Ϊ���ַ���,word2����ɾ�������ַ�
		for(int j=0; j<=n; j++)
			dp[0][j] = j;
		//��j=0ʱ,word2Ϊ���ַ���,word1����ɾ�������ַ�
		for(int i=0; i<=m; i++)
			dp[i][0] = i; 
			
		//ά��dp����
		for(int i=1; i<=m; i++)
		{
			for(int j=1; j<=n; j++)
			{
				//��������ַ����,�Ͳ���Ҫɾ�� 
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				//��������ַ�����,Ҫôɾ��word1[i-1],Ҫôɾ��word2[j-1]
				else
					dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1); //��Ȼ������ɾ������,ȡ�ı�Ȼ����Сֵ 
			}
		} 
		return dp[m][n];
	}
};

 
