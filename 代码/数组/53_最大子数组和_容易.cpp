#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

////ʹ��Sum[i]�洢��nums[i]��β�ġ����������顿������ 
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
//	//����Sum�������������ֵ
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

//����һ���ṹ��status,�洢ÿ�������״̬��Ϣ 
struct Status{
	int lSum,rSum,mSum,iSum;
};

//pushUp�������ڻ�ȡ�ϲ������״̬��Ϣ 
Status pushUp(Status lSub,Status rSub)
{
	//��ά���ϲ������iSum
	int iSum=lSub.iSum+rSub.iSum; //��Ԫ�ظ���Ϊ1��ʼ���ϻ��� 
	//Ȼ��ά���ϲ������lSum 
	int lSum=max(lSub.lSum,lSub.iSum+rSub.lSum);
	//��ά���ϲ������rSum
	int rSum=max(rSub.rSum,rSub.iSum+lSub.rSum);
	//���ά���ϲ������mSum
	int mSum=max(max(lSub.mSum,rSub.mSum),lSub.rSum+rSub.lSum); 
	return (Status){lSum,rSum,mSum,iSum}; //���غϲ������״̬��Ϣ 
}

//�������get,������ȡ����[l,r]��״̬��Ϣstatus
Status get(vector<int>& a,int l,int r)
{
	if(l==r) //�ݹ�Ľ�������:��ʣһ��Ԫ�� 
	{
		return (Status){a[l],a[l],a[l],a[l]}; //���[l,r]����Ϊ����һ��Ԫ�ص����� 
	}
	
	int m=(l+r)/2;
	Status lSub=get(a,l,m); //���������״̬��Ϣ
	Status rSub=get(a,m+1,r); //���������״̬��Ϣ
	//��ͨ�������������״̬��Ϣ����ȡ�ϲ������״̬��Ϣ
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
	printf("����������Ϊ%d\n",ans);
	return 0;
}
