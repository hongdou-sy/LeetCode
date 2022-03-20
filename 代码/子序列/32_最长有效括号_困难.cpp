class Solution{
public:
	int longestValidParentheses(string s)
	{
		//栈
		//遇到左括号,将其放入栈中
		//遇到右括号,看栈中是否还有元素与之匹配
		//边匹配边更新maxLen
		int n = s.size();
		stack<char> st;
		
		int maxLen = 0;
		int curLen = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '(') //如果是左括号
				st.push(s[i]);
			else //如果是右括号 
			{
				//若栈中已经没有左括号与之匹配了,说明该右括号是多余的 
				if(st.empty())
				{
					curLen = 0;
				}
				//若栈中还有左括号与之匹配
				else if(st.top() == '(')
				{
					st.pop();
					curLen += 2; //当前的括号对+1,子串长度+2 
					maxLen = max(maxLen, curLen);
				}
			}
		} 
		
		//如果一直到遍历完毕,栈中还有左括号,说明栈中的左括号是多余的
		//但栈中剩余的左括号不影响结果,因此不考虑
		return maxLen; 
	}
};

//暴力解法
class Solution{
public:
	bool isValid(string s, int left, int right)
	{
		stack<int> st;
		for(int i=left; i<=right; i++)
		{
			if(s[i] == '(')
				st.push(s[i]);
			else if(s[i] == ')')
			{
				if(st.empty()) //没有左括号与之匹配了
					return false;
				else if(st.top() == '(') //还有左括号与之匹配
					st.pop(); 
			}
		}
		if(st.empty() == false) //若栈中还有左括号剩余
			return false;
		return true; 
	}
	
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//从最大偶数长度开始 
		int len = n%2==0 ? n:n-1;
		int maxLen = 0;
		
		int left,right; //判断区间[left,right]是否是有效匹配串 
		for(; len>=0; len-=2)
		{
			for(int i=0; i<=n-len; i++)
			{
				left = i;
				right = i+len-1;
				//如果[left,right]是有效匹配串,更新maxLen 
				if(isValid(s, left, right) && len>maxLen)
					return maxLen = max(maxLen, len);
			}
		}
		return maxLen;
	}
}; 

//方法二:栈
//时间击败69%,空间击败73% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		//栈底元素表示分隔符,从这个分隔符开始当前有效子串长度归0
		//注意:入栈的是索引! 
		int n = s.size();
		stack<int> st;
		st.push(-1); //先将栈底元素初始化为-1
		
		int len = 0; //len表示当前有效匹配串的长度
		int maxLen = 0; //maxLen记录最长有效匹配串的长度 
		
		for(int i=0; i<n; i++)
		{
			//将左括号入栈 
			if(s[i] == '(')
			{
				st.push(i);
			}
			//遇到右括号,先弹栈 
			else if(s[i] == ')')
			{
				st.pop();
				//若栈变为空,说明当前右括号多余,将其放入栈底,作为分隔符
				if(st.empty())
				{
					st.push(i);
				}
				len = i - st.top();
				maxLen = max(maxLen, len);
			}
		} 
		return maxLen;
	}
}; 

//方法三——栈
//关键:如何获取以s[i]结尾的有效匹配串的长度 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		stack<int> st;
		int start = 0; //start记录当前以s[i]结尾的有效匹配串的第一个元素下标,方便计算总长len 
		int maxLen = 0;
		
		for(int i=0;i <n; i++)
		{
			//遇到左括号,入栈 
			if(s[i] == '(')
				st.push(i);
			//遇到右括号 
			else
			{
				//若当前栈为空,说明此时的右括号没法匹配,只能从其后一个字符重新开始 
				if(st.empty()) 
					start = i+1; 
				//若当前栈不为空,匹配当前右括号
				//同时更新目前为止的最长匹配串长度 
				else
				{
					st.pop();
					if(st.empty())
						//如果栈此时为空,我们无法获取st.top(),只能利用start计算【以s[i]结尾的有效匹配串的长度】 
						maxLen = max(maxLen, i-start+1);
					else
						//如果栈此时不为空,我们直接利用st.top(),得到【以s[i]结尾的有效匹配串的长度】 
						maxLen = max(maxLen, i-st.top());
				} 
			}
		}
		return maxLen; 
	}
}; 

//方法四:动态规划
//时间击败69%,空间击败27% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//dp[i]表示以s[i]结尾的有效匹配串的长度 
		vector<int> dp(n, 0);
		
		//dp[0]和dp[1]需要初始化 
		dp[0] = 0; //以s[0]结尾的有效匹配串的长度必然是0 
		if(s[0] == '(' && s[1] == ')')
			dp[1] = 2;
		
		for(int i = 2; i < n; i++)
		{
			//以左括号结尾的有效匹配串的长度必然为0,不考虑s[i]=='('的情况 
			//如果s[i]是右括号,并且s[i-1]是左括号,前i个字符就是'......()',有效匹配串长度+2 
			if(s[i] == ')')
			{
				if(s[i - 1] == '(')
					dp[i] = dp[i - 2] + 2;
				//如果s[i]是右括号,并且s[i-1]也是右括号,前i个字符就是'......))',就需要利用s[i-1]的dp[i-1]进行状态转移 
				else
				{
					//考虑以s[i-1]结尾的有效匹配串的前一个元素s[i-dp[i-1]-1]是否能够和当前右括号s[i]匹配 
					if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') //能匹配 
					{
						if(i - dp[i - 1] - 2 >= 0) //如果前面还有s[i-dp[i-1]-2],那还需要加上它的有效匹配串的长度 
							dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
						else //如果前面没有s[i-dp[i-1]-2]了,即i-dp[i-1]-2<0,直接+2即可 
							dp[i] = dp[i - 1] + 2;
					}
					//不匹配就不用考虑了,dp[i]必然为0 
				}
			}
		}
		
		//对于dp数组,找到其最大值
		int maxLen = 0;
		for(int i = 0; i < n; i++)
		{
			maxLen = max(maxLen, dp[i]);
		}
		
		return maxLen; 
	}
}; 

//方法四:动态规划(更简洁代码)
//时间击败69%,空间击败62% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//dp[i]表示以s[i]结尾的有效匹配串的长度 
		vector<int> dp(n, 0);
		
		int maxLen = 0;
		for(int i = 1; i < n; i++)
		{
			if(s[i] == ')')
			{
				if(s[i - 1] == '(')
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				else if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] -2] : 0);
				maxLen = max(maxLen, dp[i]);
			}
		}
		return maxLen;
	}
}; 

//方法五:正向逆向结合
//时间击败100%,空间击败84% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		//设置两个计时器 
		int left = 0; //左括号出现的次数 
		int right = 0; //右括号出现的次数
		int len = 0; //len记录当前有效匹配串的长度
		int maxLen = 0; 
		
		//先从左往右正向遍历
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '(')
				left++;
			else
				right++;
			
			//出现了有效匹配串 
			if(left == right)
			{
				len = left + right;
				maxLen = max(maxLen, len);
			}
			//若右括号开始多于左括号,重新找下一个有效匹配串 
			else if(right > left)
			{
				left = 0;
				right = 0;
			}
		} 
		
		left = 0;
		right = 0;
		//从右往左反向遍历
		for(int i = n - 1; i >= 0; i--)
		{
			if(s[i] == '(')
				left++;
			else
				right++;
			
			if(left == right)
			{
				len = left + right;
				maxLen = max(maxLen, len);
			}
			//若左括号多于右括号,重新找下一个有效匹配串 
			else if(left > right)
			{
				left = 0;
				right = 0;
			}
		} 
		
		return maxLen;
	}
}; 
