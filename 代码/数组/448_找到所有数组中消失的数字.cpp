//C++��������ĳ�ʼ�� 
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

//����һ��������a,��СΪn
//��������nums,��nums�г��ֵ���ֵ��Ϊ�±�,���������и��±��Ӧ��ֵ��Ϊ1(��true)
//����ٶ�����a���б���,ֻҪֵΪ0,˵������������nums��û�г���
//ȱ�㣺ʹ���˶���ռ�,�ռ临�Ӷ�ΪO(n) 
vector<int> findDisappearedNumber(vector<int>& nums)
{
	int n=nums.size(); //n��ʾ����nums��Ԫ�ظ��� 
	vector<int> res;
	for(int i=0;i<n;i++)
	{
		//��������ĳ��λ��ʱ,���е��������Ѿ������ӹ�,�����Ҫ��nȡģ����ԭ����������ֵ 
		int x=(nums[i]-1)%n; //��ʱx���ǳ��ֵ�ԭʼ��ֵ 
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
	for(it=res.begin();it!=res.end();it++) //��vector�������б��� 
	{
		printf("%d ",*it);
	}
	printf("\n");
	return 0;
}
