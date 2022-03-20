//时间击败97%,空间击败30% 
class Solution{
public:
	int findLengthOfLCIS(vector<int>& nums)
	{
		//只需要一个dp数组
		//当nums[i]==nums[i-1]时,dp[i]=dp[i-1]+1
		//当nums[i]!=nums[i-1]时,dp[i]=1
		//最后返回值为dp中的最大值
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

//时间击败97%,空间击败92% 
//仅仅使用一个常量来记录长度 
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
