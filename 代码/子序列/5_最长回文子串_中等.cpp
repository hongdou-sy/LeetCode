//思路一:中心扩展 
//时间击败82%,空间击败97% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		//枚举每一个中心字符
		//记录每一个最长回文子串的左右边界
		//记录最长回文子串的长度
		int n=s.length(); //n为字符串s的长度 
		int maxLen=1; //maxLen记录目前为止的最长子串的长度
		int maxL,maxR; //记录目前为止最长子串的左右边界 
		
		//枚举所有可能的中心字符 
		for(int i=0;i<2*n-1;i++)
		{
			//记录左右边界 
			int L=i/2; 
			int R=i/2+i%2;
			if(s[L]!=s[R]) continue;
			
			while(s[L]==s[R]) 
			{
				if(L-1>=0 && R+1<n && s[L-1]==s[R+1])
				{
					L--;
					R++;
				}
				else
				{
					break;
				}
			}
			int len=R-L+1; //记录该回文子串的长度 
			if(len>maxLen)
			{
				maxLen=len;
				maxL=L;
				maxR=R; 
			} 
		} 
		return s.substr(maxL,maxLen);
	}
};

//思路一:中心扩展(官方代码)
//官方代码添加了一个函数,专门用来判断固定中心字符的情况下获取的最长回文子串
//时间击败82%,空间击败87% 
class Solution{
public:
	//在固定中心字符的情况下,返回最长回文子串的左右边界 
	pair<int,int> expandAroundCenter(const string& s,int L,int R)
	{
		while(L>=0&&R<s.length() && s[L]==s[R])
		{
			L--;
			R++;
		}
		return {L+1,R-1};
	}
	
	string longestPalindrome(string s)
	{
		int maxL=0,maxR=0; //记录最长子字符串的左右边界
		//枚举所有可能的中心字符 
		for(int i=0;i<2*s.length()-1;i++)
		{
			int L=i/2;
			int R=i/2+i%2;
			//使用auto来接收返回的pair类型 
			auto [left,right]=expandAroundCenter(s,L,R);
			if(right-left>maxR-maxL)
			{
				maxR=right;
				maxL=left;
			} 
		}
		return s.substr(maxL,maxR-maxL+1);
	}
};

//解法二:动态规划算法
//动态规划算法的关键是要先确定好状态转移方程,将大问题转换成较小的问题
//时间击败43%,空间击败75% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		int n=s.length();
		//考虑特殊情况 
		if(n==1)
		{
			return s;
		}
		
		
		//使用二维数组dp记录子问题,即dp[i][j]表示子串s[i]~s[j]是否为回文串,若是,dp[i][j]=1
		bool dp[n][n]; 
		//还可以使用vector存储dp数组,后续代码不变
//		vector<vector<int> > dp(n,vector<int>(n)); //初始化vector容器,长度为n,并且每个元素也初始化为长度为n的vector容器 
		int maxLen=1; //maxLen记录目前为止的最长回文子串的长度
		int maxL=0; //maxL记录目前为止最长回文子串的左边界
		//通过maxLen和maxL可以直接算出最长回文子串的右边界
		
		//先对dp数组进行初始化,每个字符自身也是一个回文串
		for(int i=0;i<n;i++)
		{
			dp[i][i]=true;
		} 
		
		//从长度为2的子串开始判断
		//如果s[i]==s[j]&&dp[i+1][j-1]==true,则dp[i][j]=true(注意考虑长度为2的情况) 
		//固定长度 
		for(int L=2;L<=n;L++)
		{
			//固定左端点,左端点的限制条件较宽松 
			for(int i=0;i<n;i++)
			{
				int j=i+L-1; //计算出右端点
				//限制右端点溢出 
				if(j>=n)
				{
					break;
				}
				
				//接着判断dp[i][j]
				//结合状态转移方程来判断 
				//注意:dp[i+1][j-1]必然是已经判断好了的,因为其长度L是上上一轮已经计算过的 
				if(s[i]!=s[j])
				{
					dp[i][j]=false;
				}
				else
				{ 
					//子串长度为2的话,只有一个计算条件:s[i]==s[j] 
					if(L<3)
						dp[i][j]=true;
					//子串长度大于2,有两个计算条件:s[i]==s[j]&&dp[i][j]=dp[i+1][j-1] 
					else
						dp[i][j]=dp[i+1][j-1];
				}
				
				//更新maxLen和maxL
				if(dp[i][j] && L>maxLen)
				{
					maxLen=L;
					maxL=i;
				} 
			}
		} 
		return s.substr(maxL,maxLen);
	}
};

//解法二:动态规划算法(常规思路) 
//动态规划算法的关键是要先确定好状态转移方程,将大问题转换成较小的问题
//时间击败52%,空间击败72% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		int n=s.length();
		//考虑特殊情况 
		if(n==1)
		{
			return s;
		}
		
		
		//使用二维数组dp记录子问题,即dp[i][j]表示子串s[i]~s[j]是否为回文串,若是,dp[i][j]=1
		bool dp[n][n]; 
		//还可以使用vector存储dp数组,后续代码不变
//		vector<vector<int> > dp(n,vector<int>(n)); //初始化vector容器,长度为n,并且每个元素也初始化为长度为n的vector容器 
		int maxLen=1; //maxLen记录目前为止的最长回文子串的长度
		int maxL=0; //maxL记录目前为止最长回文子串的左边界
		//通过maxLen和maxL可以直接算出最长回文子串的右边界
		
		//先对dp数组进行初始化,每个字符自身也是一个回文串
		for(int i=0;i<n;i++)
		{
			dp[i][i]=true;
		} 
		
		//如果s[i]==s[j]&&dp[i+1][j-1]==true,则dp[i][j]=true(注意考虑长度为2的情况) 
		//固定右边界 
		//右边界为0就不需要判断了,左边界肯定也为0,就是已经初始化的结果dp[0][0]=1 
		for(int j=1;j<n;j++)
		{
			//枚举左边界
			for(int i=0;i<j;i++) //左边界不可能超过右边界,因此j<i 
			{
				if(s[i]!=s[j])
				{
					dp[i][j]=false;
				}
				else
				{
					if(j-i+1<3) //长度如果为2
					{
						dp[i][j]=true;
					} 
					else
					{
						dp[i][j]=dp[i+1][j-1];
					}
				}
				
				//更新maxLen和maxL
				if(dp[i][j] && j-i+1>maxLen)
				{
					maxLen=j-i+1;
					maxL=i;
				} 
			} 
		} 
		return s.substr(maxL,maxLen);
	}
};

//时间击败99%,空间击败74% 
class Solution{
public:
	//中心扩散函数,返回该函数的回文半径
	int expandAroundCenter(const string& s,int L,int R)
	{
		while(L>=0 && R<s.size() && s[L]==s[R])
		{
			L--;
			R++;
		}
		return (R-L)/2;
	} 
	
	
	string longestPalindrome(string s)
	{
		//1.预处理原字符串
		string st="#";
		for(int i=0;i<s.size();i++)
		{
			st+=s[i];
			st+='#';
		} 
		
		//2.初始化变量
		int maxRight=-1;
		int center=-1;
		int dp[2*s.size()+1];
		int maxLen=1;
		int maxL=0;
		
		//3.开始遍历字符串st
		for(int i=0;i<st.size();i++) 
		{
			//分支一:i>maxRight,直接中心扩散,得到当前循环变量i的回文半径 
			if(i>maxRight) 
			{
				dp[i]=expandAroundCenter(st,i,i);
			} 
			//分支二:i<=maxRight,综合三种情况,得到当前循环变量i的回文半径 
			else
			{
				int mirror=2*center-i; //找到i关于center的对称点
				dp[i]=min(dp[mirror],maxRight-i);
				
				//然后尝试中心扩散
				int R=i+dp[i];
				int L=i-dp[i];
				dp[i]=expandAroundCenter(st,L,R);
				
			}
			
			//更新maxRight和center
			if(i+dp[i]-1>maxRight)
			{
				maxRight=i+dp[i]-1;
				center=i;
			} 
			
			//更新maxLen和maxL
			if(2*dp[i]-1>maxLen)
			{
				maxLen=2*dp[i]-1;
				maxL=i-(dp[i]-1);
			}
		}
		
		string ans;
		for(int i=maxL;i<maxL+maxLen;i++)
		{
			if(st[i]!='#')
				ans+=st[i];
		}
		return ans;
	}
};


 
