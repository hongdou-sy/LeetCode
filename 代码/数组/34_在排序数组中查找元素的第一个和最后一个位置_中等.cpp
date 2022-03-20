#include<stdio.h>
#include<vector>
using namespace std;

//既然要求时间复杂度为O(logN),那必然是二分查找 
vector<int> searchRange(vector<int>& nums,int target)
{
	vector<int> res;
	//先找最左侧元素
	int Lindex;
	int left=0;
	int right=nums.size()-1; //搜索区间为[left,right]
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(nums[mid]==target)
		{
			right=mid-1;
		}
		else if(nums[mid]<target)
		{
			left=mid+1;
		}
		else if(nums[mid]>target)
		{
			right=mid-1;
		}
	} 
	if(left>=nums.size() || nums[left]!=target)
		Lindex=-1;
	else Lindex=left;
	res.push_back(Lindex);
//	printf("最左侧元素对应的下标为%d\n",Lindex);
	
	//再找右侧元素
	int Rindex;
	int left0=0;
	int right0=nums.size()-1; //搜索区间为[left0,right0]
	while(left0<=right0)
	{
		int mid0=left0+(right0-left0)/2;
		if(nums[mid0]==target)
		{
			left0=mid0+1;
		}
		else if(nums[mid0]<target)
		{
			left0=mid0+1;
		}
		else if(nums[mid0]>target)
		{
			right0=mid0-1;
		}
	}
	if(right0<0 || nums[right0]!=target)
		Rindex=-1;
	else Rindex=right0;
//	printf("最右侧元素对应的下标为%d\n",Rindex);
	res.push_back(Rindex);
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
	
	printf("请输入target:");
	int target;
	scanf("%d",&target);
	
	vector<int> res=searchRange(nums,target);
//	vector<int>::iterator it=res.begin();
//	for(;it!=nums.end();it++)
//	{
//		printf("%d ",*it);
//	}
	return 0;
}
