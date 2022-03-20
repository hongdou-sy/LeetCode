//C++整型数组的初始化 
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

//构建一个新数组a,大小为n
//遍历数组nums,以nums中出现的数值作为下标,将新数组中该下标对应的值设为1(即true)
//最后再对数组a进行遍历,只要值为0,说明该数在数组nums中没有出现
//缺点：使用了额外空间,空间复杂度为O(n) 
vector<int> findDisappearedNumber(vector<int>& nums)
{
	int n=nums.size(); //n表示数组nums的元素个数 
	vector<int> res;
	for(int i=0;i<n;i++)
	{
		//当遍历到某个位置时,其中的数可能已经被增加过,因此需要对n取模来还原出它本来的值 
		int x=(nums[i]-1)%n; //此时x才是出现的原始数值 
		nums[x]+=n;
	}
	
	for(int i=0;i<n;i++)
	{
		if(nums[i]<=n)
		{
			res.push_back(i+1);
		}
	}
	
	return res;
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
	
	vector<int> res=findDisappearedNumber(nums);
	vector<int>::iterator it;
	for(it=res.begin();it!=res.end();it++) //对vector容器进行遍历 
	{
		printf("%d ",*it);
	}
	printf("\n");
	return 0;
}
