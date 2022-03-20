#include<stdio.h>
#include<vector>
using namespace std;

int search(vector<int>& nums,int target)
{
	int left=0;
	int right=nums.size()-1; 
	
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(nums[mid]==target)
		{
			return mid;
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
	return -1;
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
	
	int target;
	printf("target:");
	scanf("%d",&target);
	
	int res=search(nums,target);
	printf("targe:%d\n",res);
	return 0;
}
