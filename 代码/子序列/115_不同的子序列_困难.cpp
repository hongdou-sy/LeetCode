//����һ:�ݹ�(δ���仯,��ʱ) 
class Solution{
public:
	int helper(string s, int i, string t, int j) //i��ʾȡs[i]ǰ��������,j��ʾȡt[j]ǰ��������� 
	{
		//�ݹ��������
		//����������������˳���ܵ���,��Ϊj<0�������� i<0 && j<0 ����� 
		if(j < 0) //��tΪ�մ�ʱ,t���κ��ַ���(�����մ�)���Ӵ� 
			return 1;
		if(i < 0) //��sΪ�մ�ʱ,t�����ǲ��ǿմ�,���޷�����ƥ���� 
			return 0;
		
		//�ݹ鹫ʽ 
		if(s[i] == t[j])
			return helper(s, i-1, t, j-1) + helper(s, i-1, t, j);
		else
			return helper(s, i-1, t, j);
	}
	
	int numDistinct(string s,string t)
	{
		int m = s.size();
		int n = t.size();
		return helper(s, m-1, t, n-1);
	}
};

//������:�ݹ�(���仯)
class Solution{
private:
	//�������仯����memo
	//memo[i][j]��ʾs[i]ǰ��������к�t[j]ǰ��������е�ƥ���� 
	vector<vector<int> > memo;  //��ά����memo�ľ����С�ں��溯������resize���� 
public:
	int numDistinct(string s, string t)
	{
		//��ȫ������memo���д�С����,��ȫ����ʼ��Ϊ-1 
		int m = s.size();
		int n = t.size();
		memo.resize(m, vector<int>(n, -1));
		return helper(s, m-1, t, n-1);
	}
	
	//һ��Ҫע����仯�ݹ�����ģ�� 
	//ע�����ﴫ�ݵ�s��tһ��Ҫ������,����ʹȫ��������ͨ����,Ҳû��AC 
	int helper(string& s, int i, string& t, int j)
	{
		//�ݹ��������
		if(j < 0)
			return 1;
		if(i < 0)
			return 0;
		
		//���memo��������ǰ������Ľ�,ֱ����������
		//���û����һ��Ļ�,����memo�����û��û���� 
		if(memo[i][j] != -1)
			return memo[i][j]; 
		
		//�ݹ鹫ʽ
		if(s[i] == t[j])
			memo[i][j] = helper(s, i-1, t, j-1)+helper(s, i-1, t, j);
		else
			memo[i][j] = helper(s, i-1, t, j);
		return memo[i][j]; 
	} 
};

//������:��̬�滮
//ʱ�����33%,�ռ����46% 
class Solution{
public:
	int numDistinct(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//ҪACֻ�ܽ�int���͸ĳ�unsigned long long,����ᳬʱ 
		vector<vector<unsigned long long> > dp(m+1, vector<unsigned long long>(n+1, 0));
		
		//��jΪ0ʱ,��tΪ�մ�ʱ,����s[i]��Ϊ1
		for(int i=0; i<=m; i++)
			dp[i][0] = 1;
		
		for(int i=1; i<=m; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		} 
		return dp[m][n];
	}
}; 

//�������Ż�:��̬�滮�ռ��Ż�(��718����ͬ,�������ù�������) 
//ʱ�����74%,�ռ����91% 
class Solution{
public:
	int numDistinct(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//���Ƿ���dp�����ÿһ���仯��Ԫ�ؼ��������������Ͻ��й� 
		vector<unsigned long long> dp(n+1, 0);
		dp[0] = 1; //��tΪ���ַ���ʱ,��ȻΪs���Ӵ�,ƥ����Ϊ1 
		
		//�ڱ���t�ַ���ʱ,Ҫ�Ӻ���ǰ����,���������ظ����� 
		for(int i=1; i<=m; i++)
		{
			for(int j=n; j>0; j--)
			{
				if(s[i-1] == t[j-1])
					dp[j] = dp[j] + dp[j-1];
			}
		}
		
		return dp[n];
	}
}; 
 
