#include<stdio.h>
#include<vector>
using namespace std;

//��ȻҪ��ʱ�临�Ӷ�ΪO(logN),�Ǳ�Ȼ�Ƕ��ֲ��� 
vector<int> searchRange(vector<int>& nums,int target)
{
	vector<int> res;
	//���������Ԫ��
	int Lindex;
	int left=0;
	int right=nums.size()-1; //��������Ϊ[left,right]
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
//	printf("�����Ԫ�ض�Ӧ���±�Ϊ%d\n",Lindex);
	
	//�����Ҳ�Ԫ��
	int Rindex;
	int left0=0;
	int right0=nums.size()-1; //��������Ϊ[left0,right0]
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
//	printf("���Ҳ�Ԫ�ض�Ӧ���±�Ϊ%d\n",Rindex);
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
	
	printf("������target:");
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
