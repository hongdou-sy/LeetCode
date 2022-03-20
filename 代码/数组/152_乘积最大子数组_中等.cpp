#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//ʹ��MAX����洢��nums[i]��β�ġ��˻���������顿�ĳ˻�;
//ʹ��MIN����洢��nums[i]��β�ġ��˻���С�����顿�ĳ˻�;
//MAX[i]=max(MAX[i-1]*nums[i],MIN[i-1]*nums[i],nums[i]) 
//int maxProduct(vector<int>& nums)
//{
//	int n=nums.size();
//	int MAX[n];
//	int MIN[n];
//	
//	if(n==1) return nums[0];
//	
//	//��MAX[0]��MIN[0]���г�ʼ�� 
//	MAX[0]=nums[0]; //MAX[0]����nums[0]��β�ġ��˻���������顿�ĳ˻� 
//	MIN[0]=nums[0]; //MIN[0]����nums[0]��β�ġ��˻���С�����顿�ĳ˻� 
//	for(int i=1;i<n;i++) //��nums������б��� 
//	{
//		MAX[i]=max(max(MAX[i-1]*nums[i],MIN[i-1]*nums[i]),nums[i]);
//		MIN[i]=min(min(MAX[i-1]*nums[i],MIN[i-1]*nums[i]),nums[i]);
//	} //�õ�������nums[i]��β�ġ��˻����/��С�����顿�ĳ˻�����MAX��MIN 
//	
//	//�������Ҫ�õ����ǡ��˻���������顿�ĳ˻�,Ҳ���Ǵ�MAX�����л�ȡ�����ֵ
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
		int MinPre=Min; //ֻ������������ά��i-1ʱ�̵�״̬,�Ż��ռ�
		Max=max(max(MaxPre*nums[i],MinPre*nums[i]),nums[i]); //ΪʲôҪ�½�MaxPre��MinPre?��Ϊ���һֱʹ��Max���µĻ�,��һ��Ĵ����Max���ǵ�ǰѭ�����¹��Ĵ�����! 
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
	printf("���˻�Ϊ%d\n",res);
	return 0;
}
