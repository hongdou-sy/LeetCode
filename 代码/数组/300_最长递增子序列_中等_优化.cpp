#include<stdio.h>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	int n=nums.size();
	if(n==0)return 0;
	
	vector<int> tail;
	//�ȶ�tail���г�ʼ��
	tail.push_back(nums[0]);
	//Ȼ�����ζ�nums���б���,��������tail����
	for(int i=1;i<n;i++)
	{
		//�������ǰ��ȡ����ֵ����tail�����е�����Ԫ��,����ǰ��ֵ����tail������ 
		if(nums[i]>tail.back())
		{
			tail.push_back(nums[i]);
		}
		
		//�������ǰ��ȡ����ֵnums[i]С��tail�����ĩβԪ�أ�
		//�Ȳ���tail�����д���nums[i]����С��
		//����nums[i]���¸���С�� 
		int left=0;
		int right=tail.size()-1;
		int location;
		while(left<right)
		{
			int mid=left+(right-left)/2; //��ֹ��� 
			//���[left,right]���м�ֵС��Ҫ�Ƚϵ���,���Ƚ�������С���Ұ벿�� 
			if(tail[mid]<nums[i]) 
			{
				left=mid+1; //��λ���϶�����Ҫ�ҵ��� 
			}
			//���[left,right]���м�ֵ����Ҫ�Ƚϵ���,���Ƚ�������С����벿�� 
			else 
			{
				right=mid; //��λ��������Ҫ�ҵ��� 
			}
		}
		//��left==right+1ʱ,�˳�ѭ��
		location=left; //�ҵ��˴���nums[i]����Сֵ
		tail[location]=nums[i]; 
	} 
	
	printf("����tail��Ԫ��Ϊ��"); 
	vector<int>::iterator it=tail.begin();
	for(;it!=tail.end();it++)
	{
		printf("%d ",*it);
	 } 
	 printf("\n");
	return tail.size();
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
	
	int res=lengthOfLIS(nums);
	printf("����������г���Ϊ%d\n",res);
	return 0;
}

