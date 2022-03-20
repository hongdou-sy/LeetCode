//形参实参的传递
//reverse的使用 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//参数一定要加'&',否则无法反应到实参 
void nextpermutation(vector<int> &nums)//使用容器(注意:void函数一定要用return返回)
{
	if(nums.size()==0) return; //容器中无元素 
	
	//①先找到左边的较小数和右边的较大数
	//从右往左进行查找，直到nums[i]<nums[i+1]，则nums[i]就是较小数(且[i+1,n)必然是降序) 
	int n=nums.size(); //获取容器的元素个数n
	int i=n-2;
	int j=n-1;
	for(;i>=0;i--) //从右往左遍历容器 
	{
		if(i==0&&nums[i]>nums[i+1]) //如果一直找到nums[0],说明整个序列已经是最大序列了(整体降序) 
		{
			//直接返回逆序后的升序序列
			reverse(nums.begin(),nums.end());
			return; 
		 } 
		 
		else if(nums[i]<nums[i+1]) //此时nums[i]就是较小数 
		{
			//找到了较小数后开始找较大数
			//在[i+1,n)中从右往左进行查找，找到第一个nums[j]>nums[i]，则nums[j]为较大数
			for(;j>=i+1;j--)
			{
				if(nums[j]>nums[i])
					break;
			}//此时nums[i]为较小数,nums[j]为较大数 
			
			//②将nums[i]和nums[j]进行交换,交换后[i+1,n)依然是降序
			int temp=nums[i];
			nums[i]=nums[j];
			nums[j]=temp;
			
			//③将[i+1,n)逆序,变成升序序列
			reverse(nums.begin()+i+1,nums.end());
			
			//此时的nums容器中的序列即为下一个排列 
			return; 
		}
	}
}

int main()
{
	vector<int> nums;
	int x;
	int N;
	scanf("%d",&N);//获取要输入的数的个数 
	while(N--)
	{
		scanf("%d",&x); 
		nums.push_back(x);
	}
	nextpermutation(nums);
	for(int i=0;i<nums.size();i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
