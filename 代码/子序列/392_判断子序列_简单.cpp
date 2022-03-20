//ʱ�����100%,�ռ����66% 
class Solution{
public:
	bool isSubsequence(string s, string t)
	{
		//ʹ��˫ָ��
		int m = s.size();
		int n = t.size();
		int p1 = 0, p2 = 0; //p1����s,p2����t 
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
		//д��һ: 
//		if(p1!=m) //���p2�Ѿ�������t��,p1��û�б�����s,˵��s����t��������
//			return false;
//		return true;
		//д����:
//		return p1!=m ? false:true; 
		//д����: 
		return p1 == m;
	}
};

class Solution{
public:
	bool isSubsequence(string s, string t)
	{
		int m = s.size();
		int n = t.size();
		//��ά������dp
		vector<vector<int> > dp(n+1,vector<int>(26));
		
		//�Ӻ���ǰ����t,ά������dp 
		for(int i=0; i<26; i++)
			dp[n][i]=-1;
			
		for(int i=n-1; i>=0; i--)
		{
			for(int j=0; j<26; j++)
			{
				if(t[i]=='a'+j)
					dp[i][j] = i; //��t[i]��ʼ�ַ�j��һ�γ��ֵ�λ�þ���t[i] 
				else
					dp[i][j]=dp[i+1][j]; //��t[i]��ʼ�ַ�j��һ�γ��ֵ�λ��Ҳ�Ǵ�t[i+1]��ʼ�ַ�j��һ�γ��ֵ�λ�� 
			}
		} 
		
		//��ʼ����dp�����ж�s�Ƿ�Ϊt��������
		int pos=0; //pos��ʾtƥ�䵽��λ��,�жϴ�t[pos]��ʼ����s[i]��һ�γ��ֵ�λ�� 
		for(int i=0; i<m; i++)
		{
			if(dp[pos][s[i]-'a'] == -1) //��t[pos]��ʼ���󲻴����ַ�s[i]
				return false;
			else
				//��t[pos]��ʼ��������ַ�s[i],pos��Ծ��s[i]��һ�γ��ֵ�λ��,�������ƥ��
				//+1��Ϊ�˷�ֹ�ظ�ƥ��,���s������������������ͬ���ַ�,�����������1,�ͻ�һֱƥ��t[pos]���λ�õ���ĸ,�����жϴ��� 
				pos = dp[pos][s[i]-'a'] + 1;
				 
		} 
		return true;
	}
};
