//�ⷨһ����������չ�㷨
//�տ�ʼ���˫ָ���㷨�����������м�ۼ�
//������չ�������м���������ɢ
//ʱ�����100%,�ռ����99% 
class Solution{
public:
	int countSubstring(string s)
	{
		//�����Ӵ���Ȼ�����м�Ϊ�Գ������߶ԳƵ�
		//ע��:s[0]��s[s.length()-1]�������һ�������Ӵ�
		int len=s.length();
		if(len==1) return 1; //����ַ�����ֻ��һ���ַ�,��ֻ��������һ�������Ӵ� 
		int cnt=2; //�����ֹһ���ַ�,��ʼʱ������β���������Ӵ� 
		
		//���ж�ż�����ַ�,�����������ַ�
		if(s[0]==s[1])
			cnt++;
		if(len>=3 && s[len-1]==s[len-2]) //len>=3�Ƿ�ֹ����һ���ظ� 
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
			cnt++; //ö�ٵ�ÿһ���ַ�,������Ϊһ�������Ӵ� 
			for(int j=i-1,k=i+1; j>=0&&k<len; j--,k++)
			{
				//���ж��������ַ�,������һ���ַ� 
				//���м���������չ,ÿ��һ�ԶԳ��ַ�,cnt++ 
				if(s[j]==s[k]) 
					cnt++; 
				//һ����һ�Բ���,�������ַ�s[i]�����л����Ӵ���,������һ��ö�� 
				else
					break;
			}
		}
		return cnt;
	}
};

//�ⷨһ����������չ�㷨(�ٷ�����)
//ʱ�����82%
//�ռ����71% 
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

//�ⷨ��:��̬�滮
//ʱ�����20%,�ռ����8% 
class Solution{
public:
	int countSubstring(string s)
	{
		//ʹ��dp��ά����洢������Ľ��
		//�̶�����L,ö����߽�i
		int n=s.size();
		//����dp��̬����,һ��n��Ԫ��,ÿ��Ԫ�ض�����ʼ��Ϊ��һ����̬����(һ��n��Ԫ��,ÿ��Ԫ�ض�����ʼ��Ϊ0) 
		vector<vector<int> > dp(n,vector<int>(n,0));
		if(n==1)
			return 1;
		
		//��ʼ��dp����
		for(int i=0;i<n;i++)
		{
			dp[i][i]=1;
		} 
		
		int cnt=s.size(); //cnt��ʼ��Ϊ����Ϊ1�Ļ��Ĵ��ĸ��� 
		//�ȹ̶�����,�ٹ̶���߽�
		for(int L=2;L<=n;L++)
		{
			//��߽����ƽϿ��� 
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

//�ⷨ��:Manacher�㷨
//ʱ�����100%,�ռ����62% 
class Solution{
public:
	//������ɢ���������İ뾶 
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
		//Ԥ�����ַ���s
		int n=s.size();
		string st="#";
		for(int i=0;i<n;i++)
		{
			st+=s[i];
			st+='#';
		}
		
		//��ʼ������ 
		vector<int> dp(2*n+1,1); //dp����洢ÿ��Ԫ�ض�Ӧ�������İ뾶
		int maxRight=-1; //maxRightΪ���һ��Ĵ����Ҷ˵� 
		int center=-1; //centerΪmaxRight��Ӧ�Ļ������� 
		int cnt=0; //cnt��ʾ���յĻ��Ĵ����� 
		
		for(int i=0;i<2*n+1;i++)
		{
			//��֧һ:���i>maxRight,����������չ
			if(i>maxRight)
			{
				dp[i]=expandAroundCenter(st,i,i);
			}
			//��֧��:���i<=maxRight,�ۺ������������
			else
			{
				int mirror=2*center-i; //mirror��ʾi����center�ĶԳƵ�
				dp[i]=min(maxRight-i,dp[mirror]);
				
				//����������ɢ 
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
			 
			//�ۼӻ��Ĵ�����
			cnt+=dp[i]/2; 
		}
		return cnt;
	}
};
