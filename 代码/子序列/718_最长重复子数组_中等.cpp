//��̬�滮 
//���´��������ڲ����������� 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		vector<vector<int> > dp(m+1,vector<int>(n+1)); //�½�һ��m+1��n+1�еĶ�̬����
		
		for(int i=1;i<m+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				if(nums1[i-1]==nums2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		} 
		
		return dp[m][n];
	}
};

//��̬�滮:���ڱ�������������� 
//ʱ�����76%,�ռ����16% 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		vector<vector<int> > dp(m+1,vector<int>(n+1));
		
		int maxSum=0;
		for(int i=1;i<m+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				if(nums1[i-1]==nums2[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					maxSum=max(maxSum,dp[i][j]);
				}
			}
		}
		return maxSum;
	}
};

//��̬�滮�Ż�:���ù������� 
//ʱ�����76%,�ռ����88% 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		vector<int> dp(n+1);
		int maxLen=0;
		
		for(int i=1;i<m+1;i++)
		{
			for(int j=n;j>0;j--)
			{
				if(nums1[i-1]==nums2[j-1])
					dp[j]=dp[j-1]+1;
				else
					dp[j]=0;
				maxLen=max(maxLen,dp[j]);
			}
		}
		return maxLen;
	}
};


//�������� 
//ʱ�����88%,�ռ����93% 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		//���ֽϳ�����ͽ϶�����,����������� 
		if(nums1.size()<=nums2.size())
			return findMax(nums1,nums2);
		else
			return findMax(nums2,nums1);
	}
	
	//���������ҵ���ظ������� 
	int findMax(vector<int>& nums1,vector<int>& nums2)
	{
		int Max = 0;
		int m = nums1.size();
		int n = nums2.size();
		//�������Ѿ�Ĭ������nums1�ĳ���С������nums2�ĳ���
		//��ʼλ��: nums2���ұ߽簤��nums1����߽�,nums2�������һ��� 
		
		//��һ�׶�: nums2�������һ���,�������غϲ��ֳ���len��1��ʼ��������
		//�غϲ���: num1����±�Ϊ0;nums2����±�Ϊn-len,�غϲ��ֳ���Ϊlen 
		for(int len=1; len<=m; len++) //len��ʾ����׶����ߵ��غϳ��� 
		{
			Max = max(Max, maxLen(nums1,0,nums2,n-len,len));
		}
		//�ڶ��׶�: nums2�������һ���,nums1��ȫ������nums2��Χ��,����������غϲ��ֳ��Ȳ���,�غϲ��ֳ���ʼ��Ϊnums1�ĳ���m
		//�غϲ���: nums1����±�Ϊ0;nums2�ʼ�غ�ʱ����±�Ϊn-m,���nums2������±꿪ʼ�ݼ� 
		for(int i=n-m; i>=0; i--) //i��ʾ����nums2������±� 
		{
			Max=max(Max, maxLen(nums1,0,nums2,i,m));
		}
		//�����׶�: nums2�������һ���,�������غϲ��ֳ��ȵݼ�,�غϲ��ֳ��ȴ�nums1�ĳ���m��ʼ�ݼ�
		//�غϲ���: nums1����±�Ϊj,j���ε���;nums2������±�Ϊ0 
		for(int j=1; j<m; j++) //j��ʾ����nums1������±� 
		{
			Max=max(Max, maxLen(nums1,j,nums2,0,m-j));
		}
		return Max;
	}
	
	//num1�д��±�i��ʼ,nums2�д��±�j��ʼ,�غϲ��ֳ���Ϊlen,�����غϲ��ֵ������������ĳ��� 
	int maxLen(vector<int>& nums1, int i, vector<int>& nums2, int j, int len)
	{
		int count=0;
		int Max=0;
		for(int k=0; k<len; k++)
		{
			if(nums1[i+k] == nums2[j+k])
			{
				count++;
				Max = max(Max,count);//����ĿǰΪֹ�Ĺ�������������ֵ 
			}
			//�����ǰ����������,�����������鲻������
			//��¼��ǰ�����ֵ,ͬʱ��count���� 
			else if(nums1[i+k]!=nums2[j+k] && count>0)
			{
				Max = max(Max,count);
				count = 0;
			}
		}
		return Max;
	}
};











