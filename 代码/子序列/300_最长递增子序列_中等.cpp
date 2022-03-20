#include<stdio.h>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	int n=nums.size();
	if(n==0) return 0;
	
	vector<int> tail;
	//先对tail进行初始化
	tail.push_back(nums[0]);
	//然后依次对nums进行遍历,持续更新tail数组
	for(int i=1;i<n;i++)
	{
		//①如果当前读取的数值大于tail数组中的所有元素,将当前数值插入tail数组中 
		if(nums[i]>tail.back())
		{
			tail.push_back(nums[i]);
		}
		
		else if(nums[i]<tail.back())
		{
			//②如果当前读取的数值nums[i]小于tail数组的末尾元素：
			//先查找tail数组中大于等于nums[i]的最小数
			//在用nums[i]更新该最小数 
			int left=0;
			int right=tail.size(); //right的初始值决定了搜索区间为[left,right) 
	        //注意二分查找的循环条件何时为left<=right何时为left<right
			while(left<right) //当left==right时跳出循环,返回结果 
			{
				int mid=left+(right-left)/2; //防止溢出 
				//如果[left,right)的中间值大于等于要比较的数,将比较区间缩小到左半部分 
				if(tail[mid]>=nums[i]) 
				{
					right=mid; //中位数肯定不是要找的数 
				}
				//如果[left,right)的中间值小于要比较的数,将比较区间缩小到右半部分 
				else if(tail[mid]<nums[i])
				{
					left=mid+1; //中位数可能是要找的数 
				}
			}
			//当left==right时,退出循环
			//找到了大于nums[i]的最小值为tail[left](或者说tail[right]) 
			tail[left]=nums[i]; 
		}
	} 
	
	printf("数组tail中元素为："); 
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
	printf("最长递增子序列长度为%d\n",res);
	return 0;
}
