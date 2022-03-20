//˼·һ:������չ 
//ʱ�����82%,�ռ����97% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		//ö��ÿһ�������ַ�
		//��¼ÿһ��������Ӵ������ұ߽�
		//��¼������Ӵ��ĳ���
		int n=s.length(); //nΪ�ַ���s�ĳ��� 
		int maxLen=1; //maxLen��¼ĿǰΪֹ����Ӵ��ĳ���
		int maxL,maxR; //��¼ĿǰΪֹ��Ӵ������ұ߽� 
		
		//ö�����п��ܵ������ַ� 
		for(int i=0;i<2*n-1;i++)
		{
			//��¼���ұ߽� 
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
			int len=R-L+1; //��¼�û����Ӵ��ĳ��� 
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

//˼·һ:������չ(�ٷ�����)
//�ٷ����������һ������,ר�������жϹ̶������ַ�������»�ȡ��������Ӵ�
//ʱ�����82%,�ռ����87% 
class Solution{
public:
	//�ڹ̶������ַ��������,����������Ӵ������ұ߽� 
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
		int maxL=0,maxR=0; //��¼����ַ��������ұ߽�
		//ö�����п��ܵ������ַ� 
		for(int i=0;i<2*s.length()-1;i++)
		{
			int L=i/2;
			int R=i/2+i%2;
			//ʹ��auto�����շ��ص�pair���� 
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

//�ⷨ��:��̬�滮�㷨
//��̬�滮�㷨�Ĺؼ���Ҫ��ȷ����״̬ת�Ʒ���,��������ת���ɽ�С������
//ʱ�����43%,�ռ����75% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		int n=s.length();
		//����������� 
		if(n==1)
		{
			return s;
		}
		
		
		//ʹ�ö�ά����dp��¼������,��dp[i][j]��ʾ�Ӵ�s[i]~s[j]�Ƿ�Ϊ���Ĵ�,����,dp[i][j]=1
		bool dp[n][n]; 
		//������ʹ��vector�洢dp����,�������벻��
//		vector<vector<int> > dp(n,vector<int>(n)); //��ʼ��vector����,����Ϊn,����ÿ��Ԫ��Ҳ��ʼ��Ϊ����Ϊn��vector���� 
		int maxLen=1; //maxLen��¼ĿǰΪֹ��������Ӵ��ĳ���
		int maxL=0; //maxL��¼ĿǰΪֹ������Ӵ�����߽�
		//ͨ��maxLen��maxL����ֱ�����������Ӵ����ұ߽�
		
		//�ȶ�dp������г�ʼ��,ÿ���ַ�����Ҳ��һ�����Ĵ�
		for(int i=0;i<n;i++)
		{
			dp[i][i]=true;
		} 
		
		//�ӳ���Ϊ2���Ӵ���ʼ�ж�
		//���s[i]==s[j]&&dp[i+1][j-1]==true,��dp[i][j]=true(ע�⿼�ǳ���Ϊ2�����) 
		//�̶����� 
		for(int L=2;L<=n;L++)
		{
			//�̶���˵�,��˵�����������Ͽ��� 
			for(int i=0;i<n;i++)
			{
				int j=i+L-1; //������Ҷ˵�
				//�����Ҷ˵���� 
				if(j>=n)
				{
					break;
				}
				
				//�����ж�dp[i][j]
				//���״̬ת�Ʒ������ж� 
				//ע��:dp[i+1][j-1]��Ȼ���Ѿ��жϺ��˵�,��Ϊ�䳤��L������һ���Ѿ�������� 
				if(s[i]!=s[j])
				{
					dp[i][j]=false;
				}
				else
				{ 
					//�Ӵ�����Ϊ2�Ļ�,ֻ��һ����������:s[i]==s[j] 
					if(L<3)
						dp[i][j]=true;
					//�Ӵ����ȴ���2,��������������:s[i]==s[j]&&dp[i][j]=dp[i+1][j-1] 
					else
						dp[i][j]=dp[i+1][j-1];
				}
				
				//����maxLen��maxL
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

//�ⷨ��:��̬�滮�㷨(����˼·) 
//��̬�滮�㷨�Ĺؼ���Ҫ��ȷ����״̬ת�Ʒ���,��������ת���ɽ�С������
//ʱ�����52%,�ռ����72% 
class Solution{
public:
	string longestPalindrome(string s)
	{
		int n=s.length();
		//����������� 
		if(n==1)
		{
			return s;
		}
		
		
		//ʹ�ö�ά����dp��¼������,��dp[i][j]��ʾ�Ӵ�s[i]~s[j]�Ƿ�Ϊ���Ĵ�,����,dp[i][j]=1
		bool dp[n][n]; 
		//������ʹ��vector�洢dp����,�������벻��
//		vector<vector<int> > dp(n,vector<int>(n)); //��ʼ��vector����,����Ϊn,����ÿ��Ԫ��Ҳ��ʼ��Ϊ����Ϊn��vector���� 
		int maxLen=1; //maxLen��¼ĿǰΪֹ��������Ӵ��ĳ���
		int maxL=0; //maxL��¼ĿǰΪֹ������Ӵ�����߽�
		//ͨ��maxLen��maxL����ֱ�����������Ӵ����ұ߽�
		
		//�ȶ�dp������г�ʼ��,ÿ���ַ�����Ҳ��һ�����Ĵ�
		for(int i=0;i<n;i++)
		{
			dp[i][i]=true;
		} 
		
		//���s[i]==s[j]&&dp[i+1][j-1]==true,��dp[i][j]=true(ע�⿼�ǳ���Ϊ2�����) 
		//�̶��ұ߽� 
		//�ұ߽�Ϊ0�Ͳ���Ҫ�ж���,��߽�϶�ҲΪ0,�����Ѿ���ʼ���Ľ��dp[0][0]=1 
		for(int j=1;j<n;j++)
		{
			//ö����߽�
			for(int i=0;i<j;i++) //��߽粻���ܳ����ұ߽�,���j<i 
			{
				if(s[i]!=s[j])
				{
					dp[i][j]=false;
				}
				else
				{
					if(j-i+1<3) //�������Ϊ2
					{
						dp[i][j]=true;
					} 
					else
					{
						dp[i][j]=dp[i+1][j-1];
					}
				}
				
				//����maxLen��maxL
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

//ʱ�����99%,�ռ����74% 
class Solution{
public:
	//������ɢ����,���ظú����Ļ��İ뾶
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
		//1.Ԥ����ԭ�ַ���
		string st="#";
		for(int i=0;i<s.size();i++)
		{
			st+=s[i];
			st+='#';
		} 
		
		//2.��ʼ������
		int maxRight=-1;
		int center=-1;
		int dp[2*s.size()+1];
		int maxLen=1;
		int maxL=0;
		
		//3.��ʼ�����ַ���st
		for(int i=0;i<st.size();i++) 
		{
			//��֧һ:i>maxRight,ֱ��������ɢ,�õ���ǰѭ������i�Ļ��İ뾶 
			if(i>maxRight) 
			{
				dp[i]=expandAroundCenter(st,i,i);
			} 
			//��֧��:i<=maxRight,�ۺ��������,�õ���ǰѭ������i�Ļ��İ뾶 
			else
			{
				int mirror=2*center-i; //�ҵ�i����center�ĶԳƵ�
				dp[i]=min(dp[mirror],maxRight-i);
				
				//Ȼ����������ɢ
				int R=i+dp[i];
				int L=i-dp[i];
				dp[i]=expandAroundCenter(st,L,R);
				
			}
			
			//����maxRight��center
			if(i+dp[i]-1>maxRight)
			{
				maxRight=i+dp[i]-1;
				center=i;
			} 
			
			//����maxLen��maxL
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


 
