//ʱ�����97%,�ռ����30% 
class Solution{
public:
	int findLengthOfLCIS(vector<int>& nums)
	{
		//ֻ��Ҫһ��dp����
		//��nums[i]==nums[i-1]ʱ,dp[i]=dp[i-1]+1
		//��nums[i]!=nums[i-1]ʱ,dp[i]=1
		//��󷵻�ֵΪdp�е����ֵ
		int n=nums.size();
		vector<int> dp(n);
		dp[0]=1;
		
		for(int i=1;i<n;i++)
		{
			if(nums[i]>nums[i-1])
				dp[i]=dp[i-1]+1;
			else
				dp[i]=1;
		} 
		
		int Max=dp[0];
		for(int i=1;i<n;i++)
		{
			if(Max<dp[i])
				Max=dp[i];
		}
		return Max;
	}
};

//ʱ�����97%,�ռ����92% 
//����ʹ��һ����������¼���� 
class Solution{
public:
	int findLengthOfLCIS(vector<int>& nums)
	{
		int n=nums.size();
		int maxLen=1;
		int curLen=1;
		for(int i=1;i<n;i++)
		{
			if(nums[i]>nums[i-1])
			{
				curLen++;
				if(curLen>maxLen)
					maxLen=curLen;
			}
			else
			{
				curLen=1;
			}	
		}
		return maxLen;
	}
};
