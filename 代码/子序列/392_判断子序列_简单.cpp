//时间击败100%,空间击败66% 
class Solution{
public:
	bool isSubsequence(string s, string t)
	{
		//使用双指针
		int m = s.size();
		int n = t.size();
		int p1 = 0, p2 = 0; //p1遍历s,p2遍历t 
		while(p1<m && p2<n)
		{
			if(s[p1] == t[p2])
			{
				p1++;
				p2++;
			}
			else
			{
				p2++;
			}
		}
		//写法一: 
//		if(p1!=m) //如果p2已经遍历完t了,p1还没有遍历完s,说明s不是t的子序列
//			return false;
//		return true;
		//写法二:
//		return p1!=m ? false:true; 
		//写法三: 
		return p1 == m;
	}
};

class Solution{
public:
	bool isSubsequence(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//先维护数组dp
		vector<vector<int> > dp(n+1,vector<int>(26));
		
		//从后往前遍历t,维护数组dp 
		for(int i=0; i<26; i++)
			dp[n][i]=-1;
			
		for(int i=n-1; i>=0; i--)
		{
			for(int j=0; j<26; j++)
			{
				if(t[i]=='a'+j)
					dp[i][j] = i; //从t[i]开始字符j第一次出现的位置就是t[i] 
				else
					dp[i][j]=dp[i+1][j]; //从t[i]开始字符j第一次出现的位置也是从t[i+1]开始字符j第一次出现的位置 
			}
		} 
		
		//开始利用dp数组判断s是否为t的子序列
		int pos=0; //pos表示t匹配到的位置,判断从t[pos]开始往后s[i]第一次出现的位置 
		for(int i=0; i<m; i++)
		{
			if(dp[pos][s[i]-'a'] == -1) //从t[pos]开始往后不存在字符s[i]
				return false;
			else
				//若t[pos]开始往后存在字符s[i],pos跳跃到s[i]第一次出现的位置,继续向后匹配
				//+1是为了防止重复匹配,如果s中连续两个以上是相同的字符,这里如果不加1,就会一直匹配t[pos]这个位置的字母,导致判断错误 
				pos = dp[pos][s[i]-'a'] + 1;
				 
		} 
		return true;
	}
};
