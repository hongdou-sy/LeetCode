//解法一——中心扩展算法
//刚开始想的双指针算法是由两边向中间聚集
//中心扩展则是由中间向两边扩散
//时间击败100%,空间击败99% 
class Solution{
public:
	int countSubstring(string s)
	{
		//回文子串必然是以中间为对称轴两边对称的
		//注意:s[0]和s[s.length()-1]本身就是一个回文子串
		int len=s.length();
		if(len==1) return 1; //如果字符串中只有一个字符,就只有其自身一个回文子串 
		int cnt=2; //如果不止一个字符,初始时就有首尾两个回文子串 
		
		//先判断偶数个字符,中心是两个字符
		if(s[0]==s[1])
			cnt++;
		if(len>=3 && s[len-1]==s[len-2]) //len>=3是防止和上一步重复 
			cnt++;
		for(int i=1;i<len-2;i++)
		{
			if(s[i]==s[i+1])
			{
				cnt++;
				for(int j=i-1,k=i+2; j>=0&&k<len; j--,k++)
				{
					if(s[j]==s[k])
						cnt++;
					else
						break;
				}
			}
		}
		
		for(int i=1;i<len-1;i++)
		{
			cnt++; //枚举的每一个字符,本身都作为一个回文子串 
			for(int j=i-1,k=i+1; j>=0&&k<len; j--,k++)
			{
				//再判断奇数个字符,中心是一个字符 
				//从中间向两边扩展,每多一对对称字符,cnt++ 
				if(s[j]==s[k]) 
					cnt++; 
				//一旦有一对不等,该中心字符s[i]不再有回文子串了,继续下一次枚举 
				else
					break;
			}
		}
		return cnt;
	}
};

//解法一——中心扩展算法(官方代码)
//时间击败82%
//空间击败71% 
class Solution{
public:
	int countSubstring(string s)
	{
		int cnt=0;
		int len=s.length();
		for(int i=0;i<2*len-1;i++)
		{
			int L=i/2;
			int R=i/2+i%2;
			
			while(L>=0&&R<len && s[L]==s[R])
			{
				cnt++;
				L--;
				R++;
			}
		}
		return cnt;
	}
};

//解法二:动态规划
//时间击败20%,空间击败8% 
class Solution{
public:
	int countSubstring(string s)
	{
		//使用dp二维数组存储子问题的结果
		//固定长度L,枚举左边界i
		int n=s.size();
		//定义dp动态数组,一共n个元素,每个元素都被初始化为另一个动态数组(一共n个元素,每个元素都被初始化为0) 
		vector<vector<int> > dp(n,vector<int>(n,0));
		if(n==1)
			return 1;
		
		//初始化dp数组
		for(int i=0;i<n;i++)
		{
			dp[i][i]=1;
		} 
		
		int cnt=s.size(); //cnt初始化为长度为1的回文串的个数 
		//先固定长度,再固定左边界
		for(int L=2;L<=n;L++)
		{
			//左边界限制较宽松 
			for(int i=0;i<n;i++)
			{
				int j=i+L-1;
				if(j>=n) break;
				
				if(s[i]==s[j])
				{
					if(j-i<2)
					{
						dp[i][j]=1;
						cnt++;
					}
					else 
					{
						dp[i][j]=dp[i+1][j-1];
						if(dp[i+1][j-1])
							cnt++;
					}
				}
				else
				{
					dp[i][j]=false;
				}
			}
		} 
		return cnt;
	}
};

//解法三:Manacher算法
//时间击败100%,空间击败62% 
class Solution{
public:
	//中心扩散返回最大回文半径 
	int expandAroundCenter(const string& s,int L,int R)
	{
		while(L>=0 && R<s.size() && s[L]==s[R])
		{
			L--;
			R++;
		}
		return (R-L)/2;
	}
	
	int countSubstrings(string s)
	{
		//预处理字符串s
		int n=s.size();
		string st="#";
		for(int i=0;i<n;i++)
		{
			st+=s[i];
			st+='#';
		}
		
		//初始化变量 
		vector<int> dp(2*n+1,1); //dp数组存储每个元素对应的最大回文半径
		int maxRight=-1; //maxRight为最右回文串的右端点 
		int center=-1; //center为maxRight对应的回文中心 
		int cnt=0; //cnt表示最终的回文串个数 
		
		for(int i=0;i<2*n+1;i++)
		{
			//分支一:如果i>maxRight,立马中心扩展
			if(i>maxRight)
			{
				dp[i]=expandAroundCenter(st,i,i);
			}
			//分支二:如果i<=maxRight,综合三种情况分析
			else
			{
				int mirror=2*center-i; //mirror表示i关于center的对称点
				dp[i]=min(maxRight-i,dp[mirror]);
				
				//尝试中心扩散 
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
			 
			//累加回文串个数
			cnt+=dp[i]/2; 
		}
		return cnt;
	}
};
