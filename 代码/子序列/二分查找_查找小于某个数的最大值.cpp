#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	printf("��������ֲ��ҵ�����Ԫ�ظ���:");
	scanf("%d",&n);
	
	printf("\n�������Ԫ��:\n");
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a.begin(),a.end());
	//���ֲ���:����С��ĳ���������ֵ 
	int k;
	printf("\n������ָ��ֵk:");
	scanf("%d",&k);
	
	int left=0;
	int right=a.size(); //��������Ϊ[left,right) 
	while(left<right) //��left==right��ʱ������ѭ��,���ؽ�� 
	{
		int mid=left+(right-left)/2;
		if(a[mid]<k)
			left=mid+1;
		else if(a[mid]>=k)
			right=mid-1;
	} //��ʱreturn left-1��return right-1������ 
	
//	int left=0;
//	int right=a.size()-1; //��������Ϊ[left,right]
//	while(left<=right) //��left==right+1��ʱ������ѭ��,���ؽ�� 
//	{
//		int mid=left+(right-left)/2;
//		if(a[mid]<k)
//			left=mid+1;
//		else if(a[mid]>=k)
//			right=mid-1;
//	}  //��ʱreturn right��return left-1������ 
	if(left>=0 && left<n)
//		printf("\n������С��k�����ֵΪ:%d\n",a[right]);
		printf("\n������С��k�����ֵΪ:%d\n",a[left-1]);
	else
		printf("\n�Ҳ�������������ֵ");
}
