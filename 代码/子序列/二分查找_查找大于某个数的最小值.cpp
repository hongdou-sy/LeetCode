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
	//���ֲ���:���Ҵ���ĳ��������С��
	int k;
	printf("\n������ָ��ֵk:");
	scanf("%d",&k);
	
	int left=0;
	int right=a.size(); //��ʱ����������Ϊ[left,right) 
	while(left<right) //��left==rightʱ,�˳�ѭ��,���ؽ�� 
	{
		int mid=left+(right-left)/2;
		if(a[mid]>k)
			right=mid;
		else if(a[mid]<=k)
			left=mid+1;
	}  //��ʱreturn left��return right������ 

//	int left=0;
//	int right=a.size()-1; //��ʱ����������Ϊ[left,right] 
//	while(left<=right) //��left==right+1ʱ,�˳�ѭ��,���ؽ�� 
//	{
//		int mid=left+(right-left)/2;
//		if(a[mid]>k)
//			right=mid-1;
//		else if(a[mid]<=k)
//			left=mid+1;
//	} //��ʱreturn left����return right+1������ 
	
	if(left>=0 && left<n)
		printf("\n�����д���k����СֵΪ:%d\n",a[left]);
//		printf("\n�����д���k����СֵΪ:%d\n",a[right+1]); 
	else
		printf("\n�Ҳ�������������ֵ");
}
