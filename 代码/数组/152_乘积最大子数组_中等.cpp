#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//使用MAX数组存储以nums[i]结尾的【乘积最大子数组】的乘积;
//使用MIN数组存储以nums[i]结尾的【乘积最小子数组】的乘积;
//MAX[i]=max(MAX[i-1]*nums[i],MIN[i-1]*nums[i],nums[i]) 
//int maxProduct(vector<int>& nums)
//{
//	int n=nums.size();
//	int MAX[n];
//	int MIN[n];
//	
//	if(n==1) return nums[0];
//	
//	//对MAX[0]和MIN[0]进行初始化 
//	MAX[0]=nums[0]; //MAX[0]是以nums[0]结尾的【乘积最大子数组】的乘积 
//	MIN[0]=nums[0]; //MIN[0]是以nums[0]结尾的【乘积最小子数组】的乘积 
//	for(int i=1;i<n;i++) //对nums数组进行遍历 
//	{
//		MAX[i]=max(max(MAX[i-1]*nums[i],MIN[i-1]*nums[i]),nums[i]);
//		MIN[i]=min(min(MAX[i-1]*nums[i],MIN[i-1]*nums[i]),nums[i]);
//	} //得到所有以nums[i]结尾的【乘积最大/最小子数组】的乘积数组MAX和MIN 
//	
//	//最后我们要得到的是【乘积最大子数组】的乘积,也就是从MAX数组中获取其最大值
//	int res=MAX[0];
//	for(int i=0;i<n;i++)
//	{
//		if(res<MAX[i])
//		{
//			res=MAX[i];
//		}
//	} 
//	return res;
//}

int maxProduct(vector<int>& nums)
{
	int n=nums.size();
	int Max,Min;
	int res;
	
	if(nums.size()==1) return nums[0];
	
	Max=nums[0];
	Min=nums[0];
	res=Max;
	for(int i=1;i<n;i++)
	{
		int MaxPre=Max;
		int MinPre=Min; //只用两个变量来维护i-1时刻的状态,优化空间
		Max=max(max(MaxPre*nums[i],MinPre*nums[i]),nums[i]); //为什么要新建MaxPre和MinPre?因为如果一直使用Max更新的话,下一句的代码的Max就是当前循环更新过的代码了! 
		Min=min(min(MaxPre*nums[i],MinPre*nums[i]),nums[i]);
		res=max(Max,res);
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> nums;
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		nums.push_back(x);
	}
	int res=maxProduct(nums);
	printf("最大乘积为%d\n",res);
	return 0;
}
