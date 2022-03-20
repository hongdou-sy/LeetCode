#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

//使用动态规划 
//使用数组dp,定义dp[i]为考虑前i个元素,且以第i个数字结尾的最长上升子序列的长度
//对于dp[i],要找出nums[0]~nums[i]中的最长上升子序列:
//①对已知的dp[0]~dp[i-1]进行遍历(假设遍历下标为j)； 
//②对于dp[j](也就是以nums[j]结尾的最长递增子序列的长度),一旦nums[i]>nums[j],dp[i]=dp[j]+1;
//③直到遍历完dp[0]~dp[i-1],选择获取的所有新dp[i]中的最大值 
int lengthOfLIS(vector<int>& nums)
{
	int n=nums.size();
	if(n==0) return 0;
	
	int dp[n];
	//将数组dp初始化为1,因为每个元素自身都可以看做一个子序列,长度为1
	//要对整型数组全部赋一个非0值,只能使用for循环
	for(int i=0;i<n;i++) //反正也没有提高时间复杂度,尽管循环就行 
	{
		dp[i]=1;
	 } 
	
	for(int i=1;i<n;i++)//对每个元素nums[i]进行遍历,判断前i-1个元素加上这第i个元素后的最长递增子序列 
	{
		for(int j=0;j<i;j++)//dp[j]表示前nums[0]~nums[j]中以nums[j]结尾的最长递增子序列的长度 
		{
			if(nums[i]>nums[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		} 
	}
	
	for(int i=0;i<n;i++)
	{
		printf("前%d个元素中最大递增子序列的长度为%d\n",i,dp[i]);
	 } 
	
	//不能直接返回dp[n-1],因为dp[n-1]仅是nums[0]~nums[n-1]中以nums[n-1]结尾的最长递增子序列的长度
	//可能有别的子序列,不以nums[n-1]结尾,以nums[n-1]前面的数结尾,但子序列长度大于以nums[n-1]结尾的子序列
	//因此,我们返回的应该是以所有元素结尾的最长递增子序列中长度最大的数 
	int MAX=dp[0];
	for(int i=0;i<n;i++)
	{
		if(MAX<dp[i])
		{
			MAX=dp[i];
		}
	}
	return MAX;
}

int main()
{
	int n; //数组元素个数
	scanf("%d",&n);
	vector<int> nums;
	
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		nums.push_back(x);
	} 
	
	int res=lengthOfLIS(nums);
	printf("最长递增子序列的长度为%d\n",res);
	return 0;
}
