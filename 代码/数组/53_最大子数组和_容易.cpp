#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

////使用Sum[i]存储以nums[i]结尾的【连续子数组】的最大和 
//int maxSubArray(vector<int>& nums)
//{
//	int n=nums.size();
//	if(n==0) return 0;
//	if(n==1) return nums[0];
////	int Sum[n];
////	
////	Sum[0]=nums[0];
////	for(int i=1;i<n;i++)
////	{
////		Sum[i]=max(Sum[i-1]+nums[i],nums[i]);
////	}
//	int Sum=nums[0];
//	int Pre;
//	int ans=Sum;
//	for(int i=1;i<n;i++)
//	{
//		Pre=Sum;
//		Sum=max(Pre+nums[i],nums[i]);
//		ans=max(ans,Sum);
//	}
//	return ans;
//	
//	//最后从Sum数组中找其最大值
////	int Max=Sum[0];
////	for(int i=0;i<n;i++)
////	{
////		if(Max<Sum[i])
////		{
////			Max=Sum[i];
////		}
////	} 
////	return Max;
//}

//定义一个结构体status,存储每个区间的状态信息 
struct Status{
	int lSum,rSum,mSum,iSum;
};

//pushUp函数用于获取合并区间的状态信息 
Status pushUp(Status lSub,Status rSub)
{
	//先维护合并区间的iSum
	int iSum=lSub.iSum+rSub.iSum; //从元素个数为1开始向上回升 
	//然后维护合并区间的lSum 
	int lSum=max(lSub.lSum,lSub.iSum+rSub.lSum);
	//再维护合并区间的rSum
	int rSum=max(rSub.rSum,rSub.iSum+lSub.rSum);
	//最后维护合并区间的mSum
	int mSum=max(max(lSub.mSum,rSub.mSum),lSub.rSum+rSub.lSum); 
	return (Status){lSum,rSum,mSum,iSum}; //返回合并区间的状态信息 
}

//定义操作get,用来获取区间[l,r]的状态信息status
Status get(vector<int>& a,int l,int r)
{
	if(l==r) //递归的结束条件:仅剩一个元素 
	{
		return (Status){a[l],a[l],a[l],a[l]}; //如果[l,r]区间为仅有一个元素的区间 
	}
	
	int m=(l+r)/2;
	Status lSub=get(a,l,m); //左子区间的状态信息
	Status rSub=get(a,m+1,r); //右子区间的状态信息
	//再通过左右子区间的状态信息来获取合并区间的状态信息
	return pushUp(lSub,rSub); 
} 

int maxSubArray(vector<int>& nums)
{
	Status st=get(nums,0,nums.size()-1);
	return st.mSum;
}

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		nums.push_back(x);
	}
	
	int ans=maxSubArray(nums);
	printf("最大子数组和为%d\n",ans);
	return 0;
}
