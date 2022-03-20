//ʱ�����41%,�ռ����21%
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n) 
class Solution{
public:
	int maxSubArray(vector<int>& nums)
	{
		//ʹ������dp,dp[i]��ʾ��nums[i]��β������
		//dp[i-1]+nums[i]��nums[i]���бȽ�
		//���dp[i-1]+nums[i]>=nums[i],dp[i]=dp[i-1]+nums[i]
		//���dp[i-1]+nums[i]<nums[i],dp[i]=nums[i]
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

//ʱ�����41%,�ռ����91% 
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1) 
class Solution{
public:
	int maxSubArray(vector<int>& nums)
	{
		//ʹ�ó���maxSum��ʾĿǰΪֹ������������
		//ʹ�ó���curSum��ʾ��nums[i]��β������������ 
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


