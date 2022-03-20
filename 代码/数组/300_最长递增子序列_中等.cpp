#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

//ʹ�ö�̬�滮 
//ʹ������dp,����dp[i]Ϊ����ǰi��Ԫ��,���Ե�i�����ֽ�β������������еĳ���
//����dp[i],Ҫ�ҳ�nums[0]~nums[i]�е������������:
//�ٶ���֪��dp[0]~dp[i-1]���б���(��������±�Ϊj)�� 
//�ڶ���dp[j](Ҳ������nums[j]��β������������еĳ���),һ��nums[i]>nums[j],dp[i]=dp[j]+1;
//��ֱ��������dp[0]~dp[i-1],ѡ���ȡ��������dp[i]�е����ֵ 
int lengthOfLIS(vector<int>& nums)
{
	int n=nums.size();
	if(n==0) return 0;
	
	int dp[n];
	//������dp��ʼ��Ϊ1,��Ϊÿ��Ԫ���������Կ���һ��������,����Ϊ1
	//Ҫ����������ȫ����һ����0ֵ,ֻ��ʹ��forѭ��
	for(int i=0;i<n;i++) //����Ҳû�����ʱ�临�Ӷ�,����ѭ������ 
	{
		dp[i]=1;
	 } 
	
	for(int i=1;i<n;i++)//��ÿ��Ԫ��nums[i]���б���,�ж�ǰi-1��Ԫ�ؼ������i��Ԫ�غ������������� 
	{
		for(int j=0;j<i;j++)//dp[j]��ʾǰnums[0]~nums[j]����nums[j]��β������������еĳ��� 
		{
			if(nums[i]>nums[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		} 
	}
	
	for(int i=0;i<n;i++)
	{
		printf("ǰ%d��Ԫ���������������еĳ���Ϊ%d\n",i,dp[i]);
	 } 
	
	//����ֱ�ӷ���dp[n-1],��Ϊdp[n-1]����nums[0]~nums[n-1]����nums[n-1]��β������������еĳ���
	//�����б��������,����nums[n-1]��β,��nums[n-1]ǰ�������β,�������г��ȴ�����nums[n-1]��β��������
	//���,���Ƿ��ص�Ӧ����������Ԫ�ؽ�β��������������г��������� 
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
	int n; //����Ԫ�ظ���
	scanf("%d",&n);
	vector<int> nums;
	
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		nums.push_back(x);
	} 
	
	int res=lengthOfLIS(nums);
	printf("����������еĳ���Ϊ%d\n",res);
	return 0;
}
