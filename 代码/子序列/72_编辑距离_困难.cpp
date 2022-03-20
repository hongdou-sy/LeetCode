//����һ:��̬�滮(�Ե�����) 
//ʱ�����72%,�ռ����29% 
class Solution{
public:
	int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		vector<vector<int> > dp(m+1, vector<int>(n+1));
		
		//��ʼ��dp����
		for(int i=0; i<=m; i++)
		{
			dp[i][0] = i;
		} 
		for(int j=0; j<=n; j++)
		{
			dp[0][j] = j;
		}
		
		//ά��dp����
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

//������:�ݹ�(���϶���) 
//δ��Ӽ��仯����:��ʱ 
class Solution{
public:
	int helper(string word1, int i, string word2, int j)
	{
		//�ݹ�߽�
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

//������:�ݹ�
//��Ӽ��仯����
//ʱ�����5%,�ռ����5% 
class Solution{
private:
	vector<vector<int> > dp; 
public:
	int helper(string word1, int i, string word2, int j)
	{
		//�ݹ�߽�
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
