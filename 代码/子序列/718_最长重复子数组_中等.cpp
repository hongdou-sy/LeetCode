//动态规划 
//以下代码适用于不连续子序列 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		vector<vector<int> > dp(m+1,vector<int>(n+1)); //新建一个m+1行n+1列的动态数组
		
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

//动态规划:用于本题的连续子序列 
//时间击败76%,空间击败16% 
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

//动态规划优化:利用滚动数组 
//时间击败76%,空间击败88% 
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


//滑动窗口 
//时间击败88%,空间击败93% 
class Solution{
public:
	int findLength(vector<int>& nums1,vector<int>& nums2)
	{
		//区分较长数组和较短数组,方便后续操作 
		if(nums1.size()<=nums2.size())
			return findMax(nums1,nums2);
		else
			return findMax(nums2,nums1);
	}
	
	//滑动窗口找到最长重复子数组 
	int findMax(vector<int>& nums1,vector<int>& nums2)
	{
		int Max = 0;
		int m = nums1.size();
		int n = nums2.size();
		//本函数已经默认数组nums1的长度小于数组nums2的长度
		//初始位置: nums2的右边界挨着nums1的左边界,nums2从左往右滑动 
		
		//第一阶段: nums2从左往右滑动,两数组重合部分长度len从1开始不断增加
		//重合部分: num1起点下标为0;nums2起点下标为n-len,重合部分长度为len 
		for(int len=1; len<=m; len++) //len表示进入阶段两者的重合长度 
		{
			Max = max(Max, maxLen(nums1,0,nums2,n-len,len));
		}
		//第二阶段: nums2从左往右滑动,nums1完全包含在nums2范围内,因此两数组重合部分长度不变,重合部分长度始终为nums1的长度m
		//重合部分: nums1起点下标为0;nums2最开始重合时起点下标为n-m,随后nums2的起点下标开始递减 
		for(int i=n-m; i>=0; i--) //i表示的是nums2的起点下标 
		{
			Max=max(Max, maxLen(nums1,0,nums2,i,m));
		}
		//第三阶段: nums2从左往右滑动,两数组重合部分长度递减,重合部分长度从nums1的长度m开始递减
		//重合部分: nums1起点下标为j,j依次递增;nums2的起点下标为0 
		for(int j=1; j<m; j++) //j表示的是nums1的起点下标 
		{
			Max=max(Max, maxLen(nums1,j,nums2,0,m-j));
		}
		return Max;
	}
	
	//num1中从下标i开始,nums2中从下标j开始,重合部分长度为len,查找重合部分的最长公共子数组的长度 
	int maxLen(vector<int>& nums1, int i, vector<int>& nums2, int j, int len)
	{
		int count=0;
		int Max=0;
		for(int k=0; k<len; k++)
		{
			if(nums1[i+k] == nums2[j+k])
			{
				count++;
				Max = max(Max,count);//更新目前为止的公共子数组的最大值 
			}
			//如果当前两个数不等,即公共子数组不再连续
			//记录当前的最大值,同时将count归零 
			else if(nums1[i+k]!=nums2[j+k] && count>0)
			{
				Max = max(Max,count);
				count = 0;
			}
		}
		return Max;
	}
};











