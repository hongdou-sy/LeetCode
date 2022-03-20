//时间击败41%,空间击败21%
//时间复杂度O(n),空间复杂度O(n) 
class Solution{
public:
	int maxSubArray(vector<int>& nums)
	{
		//使用数组dp,dp[i]表示以nums[i]结尾的最大和
		//dp[i-1]+nums[i]与nums[i]进行比较
		//如果dp[i-1]+nums[i]>=nums[i],dp[i]=dp[i-1]+nums[i]
		//如果dp[i-1]+nums[i]<nums[i],dp[i]=nums[i]
		int n=nums.size();
		vector<int> dp(n);
		dp[0]=nums[0];
		
		for(int i=1;i<n;i++)
		{
			if(dp[i-1]+nums[i]>=nums[i])
				dp[i]=dp[i-1]+nums[i];
			else
				dp[i]=nums[i];
		} 
		
		int maxSum=nums[0];
		for(int i=1;i<n;i++)
		{
			if(dp[i]>maxSum)
				maxSum=dp[i];
		}
		return maxSum;
	}
};

//时间击败41%,空间击败91% 
//时间复杂度O(n),空间复杂度O(1) 
class Solution{
public:
	int maxSubArray(vector<int>& nums)
	{
		//使用常数maxSum表示目前为止的最大子数组和
		//使用常数curSum表示以nums[i]结尾的最大子数组和 
		int n=nums.size();
		int maxSum=nums[0];
		int curSum=nums[0];
		
		for(int i=1;i<n;i++)
		{
			curSum=max(curSum+nums[i],nums[i]);
			maxSum=max(maxSum,curSum);
		}
		return maxSum;
	}
};


