#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	printf("请输入二分查找的数组元素个数:");
	scanf("%d",&n);
	
	printf("\n请输入各元素:\n");
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a.begin(),a.end());
	//二分查找:查找小于某个数的最大值 
	int k;
	printf("\n请输入指定值k:");
	scanf("%d",&k);
	
	int left=0;
	int right=a.size(); //搜索区间为[left,right) 
	while(left<right) //当left==right的时候跳出循环,返回结果 
	{
		int mid=left+(right-left)/2;
		if(a[mid]<k)
			left=mid+1;
		else if(a[mid]>=k)
			right=mid-1;
	} //此时return left-1或return right-1都可以 
	
//	int left=0;
//	int right=a.size()-1; //搜索区间为[left,right]
//	while(left<=right) //当left==right+1的时候跳出循环,返回结果 
//	{
//		int mid=left+(right-left)/2;
//		if(a[mid]<k)
//			left=mid+1;
//		else if(a[mid]>=k)
//			right=mid-1;
//	}  //此时return right或return left-1都可以 
	if(left>=0 && left<n)
//		printf("\n数组中小于k的最大值为:%d\n",a[right]);
		printf("\n数组中小于k的最大值为:%d\n",a[left-1]);
	else
		printf("\n找不到满足条件的值");
}
