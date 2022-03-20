class Solution{
public:
	int longestValidParentheses(string s)
	{
		//ջ
		//����������,�������ջ��
		//����������,��ջ���Ƿ���Ԫ����֮ƥ��
		//��ƥ��߸���maxLen
		int n = s.size();
		stack<char> st;
		
		int maxLen = 0;
		int curLen = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '(') //�����������
				st.push(s[i]);
			else //����������� 
			{
				//��ջ���Ѿ�û����������֮ƥ����,˵�����������Ƕ���� 
				if(st.empty())
				{
					curLen = 0;
				}
				//��ջ�л�����������֮ƥ��
				else if(st.top() == '(')
				{
					st.pop();
					curLen += 2; //��ǰ�����Ŷ�+1,�Ӵ�����+2 
					maxLen = max(maxLen, curLen);
				}
			}
		} 
		
		//���һֱ���������,ջ�л���������,˵��ջ�е��������Ƕ����
		//��ջ��ʣ��������Ų�Ӱ����,��˲�����
		return maxLen; 
	}
};

//�����ⷨ
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
				if(st.empty()) //û����������֮ƥ����
					return false;
				else if(st.top() == '(') //������������֮ƥ��
					st.pop(); 
			}
		}
		if(st.empty() == false) //��ջ�л���������ʣ��
			return false;
		return true; 
	}
	
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//�����ż�����ȿ�ʼ 
		int len = n%2==0 ? n:n-1;
		int maxLen = 0;
		
		int left,right; //�ж�����[left,right]�Ƿ�����Чƥ�䴮 
		for(; len>=0; len-=2)
		{
			for(int i=0; i<=n-len; i++)
			{
				left = i;
				right = i+len-1;
				//���[left,right]����Чƥ�䴮,����maxLen 
				if(isValid(s, left, right) && len>maxLen)
					return maxLen = max(maxLen, len);
			}
		}
		return maxLen;
	}
}; 

//������:ջ
//ʱ�����69%,�ռ����73% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		//ջ��Ԫ�ر�ʾ�ָ���,������ָ�����ʼ��ǰ��Ч�Ӵ����ȹ�0
		//ע��:��ջ��������! 
		int n = s.size();
		stack<int> st;
		st.push(-1); //�Ƚ�ջ��Ԫ�س�ʼ��Ϊ-1
		
		int len = 0; //len��ʾ��ǰ��Чƥ�䴮�ĳ���
		int maxLen = 0; //maxLen��¼���Чƥ�䴮�ĳ��� 
		
		for(int i=0; i<n; i++)
		{
			//����������ջ 
			if(s[i] == '(')
			{
				st.push(i);
			}
			//����������,�ȵ�ջ 
			else if(s[i] == ')')
			{
				st.pop();
				//��ջ��Ϊ��,˵����ǰ�����Ŷ���,�������ջ��,��Ϊ�ָ���
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

//����������ջ
//�ؼ�:��λ�ȡ��s[i]��β����Чƥ�䴮�ĳ��� 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		stack<int> st;
		int start = 0; //start��¼��ǰ��s[i]��β����Чƥ�䴮�ĵ�һ��Ԫ���±�,��������ܳ�len 
		int maxLen = 0;
		
		for(int i=0;i <n; i++)
		{
			//����������,��ջ 
			if(s[i] == '(')
				st.push(i);
			//���������� 
			else
			{
				//����ǰջΪ��,˵����ʱ��������û��ƥ��,ֻ�ܴ����һ���ַ����¿�ʼ 
				if(st.empty()) 
					start = i+1; 
				//����ǰջ��Ϊ��,ƥ�䵱ǰ������
				//ͬʱ����ĿǰΪֹ���ƥ�䴮���� 
				else
				{
					st.pop();
					if(st.empty())
						//���ջ��ʱΪ��,�����޷���ȡst.top(),ֻ������start���㡾��s[i]��β����Чƥ�䴮�ĳ��ȡ� 
						maxLen = max(maxLen, i-start+1);
					else
						//���ջ��ʱ��Ϊ��,����ֱ������st.top(),�õ�����s[i]��β����Чƥ�䴮�ĳ��ȡ� 
						maxLen = max(maxLen, i-st.top());
				} 
			}
		}
		return maxLen; 
	}
}; 

//������:��̬�滮
//ʱ�����69%,�ռ����27% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//dp[i]��ʾ��s[i]��β����Чƥ�䴮�ĳ��� 
		vector<int> dp(n, 0);
		
		//dp[0]��dp[1]��Ҫ��ʼ�� 
		dp[0] = 0; //��s[0]��β����Чƥ�䴮�ĳ��ȱ�Ȼ��0 
		if(s[0] == '(' && s[1] == ')')
			dp[1] = 2;
		
		for(int i = 2; i < n; i++)
		{
			//�������Ž�β����Чƥ�䴮�ĳ��ȱ�ȻΪ0,������s[i]=='('����� 
			//���s[i]��������,����s[i-1]��������,ǰi���ַ�����'......()',��Чƥ�䴮����+2 
			if(s[i] == ')')
			{
				if(s[i - 1] == '(')
					dp[i] = dp[i - 2] + 2;
				//���s[i]��������,����s[i-1]Ҳ��������,ǰi���ַ�����'......))',����Ҫ����s[i-1]��dp[i-1]����״̬ת�� 
				else
				{
					//������s[i-1]��β����Чƥ�䴮��ǰһ��Ԫ��s[i-dp[i-1]-1]�Ƿ��ܹ��͵�ǰ������s[i]ƥ�� 
					if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') //��ƥ�� 
					{
						if(i - dp[i - 1] - 2 >= 0) //���ǰ�滹��s[i-dp[i-1]-2],�ǻ���Ҫ����������Чƥ�䴮�ĳ��� 
							dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
						else //���ǰ��û��s[i-dp[i-1]-2]��,��i-dp[i-1]-2<0,ֱ��+2���� 
							dp[i] = dp[i - 1] + 2;
					}
					//��ƥ��Ͳ��ÿ�����,dp[i]��ȻΪ0 
				}
			}
		}
		
		//����dp����,�ҵ������ֵ
		int maxLen = 0;
		for(int i = 0; i < n; i++)
		{
			maxLen = max(maxLen, dp[i]);
		}
		
		return maxLen; 
	}
}; 

//������:��̬�滮(��������)
//ʱ�����69%,�ռ����62% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		if(n < 2)
			return 0;
		//dp[i]��ʾ��s[i]��β����Чƥ�䴮�ĳ��� 
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

//������:����������
//ʱ�����100%,�ռ����84% 
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.size();
		//����������ʱ�� 
		int left = 0; //�����ų��ֵĴ��� 
		int right = 0; //�����ų��ֵĴ���
		int len = 0; //len��¼��ǰ��Чƥ�䴮�ĳ���
		int maxLen = 0; 
		
		//�ȴ��������������
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '(')
				left++;
			else
				right++;
			
			//��������Чƥ�䴮 
			if(left == right)
			{
				len = left + right;
				maxLen = max(maxLen, len);
			}
			//�������ſ�ʼ����������,��������һ����Чƥ�䴮 
			else if(right > left)
			{
				left = 0;
				right = 0;
			}
		} 
		
		left = 0;
		right = 0;
		//�������������
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
			//�������Ŷ���������,��������һ����Чƥ�䴮 
			else if(left > right)
			{
				left = 0;
				right = 0;
			}
		} 
		
		return maxLen;
	}
}; 
