//方法一:递归(未记忆化,超时) 
class Solution{
public:
	int helper(string s, int i, string t, int j) //i表示取s[i]前的子序列,j表示取t[j]前面的子序列 
	{
		//递归结束条件
		//下面两个结束条件顺序不能调换,因为j<0还包括了 i<0 && j<0 的情况 
		if(j < 0) //当t为空串时,t是任何字符串(包括空串)的子串 
			return 1;
		if(i < 0) //当s为空串时,t不论是不是空串,都无法进行匹配了 
			return 0;
		
		//递归公式 
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

//方法二:递归(记忆化)
class Solution{
private:
	//创建记忆化数组memo
	//memo[i][j]表示s[i]前面的子序列和t[j]前面的子序列的匹配数 
	vector<vector<int> > memo;  //二维数组memo的具体大小在后面函数中用resize更新 
public:
	int numDistinct(string s, string t)
	{
		//对全局数组memo进行大小更新,并全部初始化为-1 
		int m = s.size();
		int n = t.size();
		memo.resize(m, vector<int>(n, -1));
		return helper(s, m-1, t, n-1);
	}
	
	//一定要注意记忆化递归代码的模板 
	//注意这里传递的s和t一定要加引用,否则即使全部用例都通过了,也没法AC 
	int helper(string& s, int i, string& t, int j)
	{
		//递归结束条件
		if(j < 0)
			return 1;
		if(i < 0)
			return 0;
		
		//如果memo中遇到当前子问题的解,直接拿来返回
		//如果没有这一句的话,加了memo数组和没加没区别 
		if(memo[i][j] != -1)
			return memo[i][j]; 
		
		//递归公式
		if(s[i] == t[j])
			memo[i][j] = helper(s, i-1, t, j-1)+helper(s, i-1, t, j);
		else
			memo[i][j] = helper(s, i-1, t, j);
		return memo[i][j]; 
	} 
};

//方法三:动态规划
//时间击败33%,空间击败46% 
class Solution{
public:
	int numDistinct(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//要AC只能将int类型改成unsigned long long,否则会超时 
		vector<vector<unsigned long long> > dp(m+1, vector<unsigned long long>(n+1, 0));
		
		//当j为0时,即t为空串时,所有s[i]均为1
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

//方法三优化:动态规划空间优化(与718题相同,都是利用滚动数组) 
//时间击败74%,空间击败91% 
class Solution{
public:
	int numDistinct(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//我们发现dp数组的每一个变化的元素几乎都仅与其左上角有关 
		vector<unsigned long long> dp(n+1, 0);
		dp[0] = 1; //当t为空字符串时,必然为s的子串,匹配数为1 
		
		//在遍历t字符串时,要从后向前遍历,这样避免重复覆盖 
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
 
