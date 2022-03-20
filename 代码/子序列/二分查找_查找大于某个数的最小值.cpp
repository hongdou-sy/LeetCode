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
	//二分查找:查找大于某个数的最小数
	int k;
	printf("\n请输入指定值k:");
	scanf("%d",&k);
	
	int left=0;
	int right=a.size(); //此时的搜索区间为[left,right) 
	while(left<right) //当left==right时,退出循环,返回结果 
	{
		int mid=left+(right-left)/2;
		if(a[mid]>k)
			right=mid;
		else if(a[mid]<=k)
			left=mid+1;
	}  //此时return left或return right都可以 

//	int left=0;
//	int right=a.size()-1; //此时的搜索区间为[left,right] 
//	while(left<=right) //当left==right+1时,退出循环,返回结果 
//	{
//		int mid=left+(right-left)/2;
//		if(a[mid]>k)
//			right=mid-1;
//		else if(a[mid]<=k)
//			left=mid+1;
//	} //此时return left或者return right+1都可以 
	
	if(left>=0 && left<n)
		printf("\n数组中大于k的最小值为:%d\n",a[left]);
//		printf("\n数组中大于k的最小值为:%d\n",a[right+1]); 
	else
		printf("\n找不到满足条件的值");
}
