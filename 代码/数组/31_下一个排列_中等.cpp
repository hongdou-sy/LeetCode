//�β�ʵ�εĴ���
//reverse��ʹ�� 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//����һ��Ҫ��'&',�����޷���Ӧ��ʵ�� 
void nextpermutation(vector<int> &nums)//ʹ������(ע��:void����һ��Ҫ��return����)
{
	if(nums.size()==0) return; //��������Ԫ�� 
	
	//�����ҵ���ߵĽ�С�����ұߵĽϴ���
	//����������в��ң�ֱ��nums[i]<nums[i+1]����nums[i]���ǽ�С��(��[i+1,n)��Ȼ�ǽ���) 
	int n=nums.size(); //��ȡ������Ԫ�ظ���n
	int i=n-2;
	int j=n-1;
	for(;i>=0;i--) //��������������� 
	{
		if(i==0&&nums[i]>nums[i+1]) //���һֱ�ҵ�nums[0],˵�����������Ѿ������������(���彵��) 
		{
			//ֱ�ӷ�����������������
			reverse(nums.begin(),nums.end());
			return; 
		 } 
		 
		else if(nums[i]<nums[i+1]) //��ʱnums[i]���ǽ�С�� 
		{
			//�ҵ��˽�С����ʼ�ҽϴ���
			//��[i+1,n)�д���������в��ң��ҵ���һ��nums[j]>nums[i]����nums[j]Ϊ�ϴ���
			for(;j>=i+1;j--)
			{
				if(nums[j]>nums[i])
					break;
			}//��ʱnums[i]Ϊ��С��,nums[j]Ϊ�ϴ��� 
			
			//�ڽ�nums[i]��nums[j]���н���,������[i+1,n)��Ȼ�ǽ���
			int temp=nums[i];
			nums[i]=nums[j];
			nums[j]=temp;
			
			//�۽�[i+1,n)����,�����������
			reverse(nums.begin()+i+1,nums.end());
			
			//��ʱ��nums�����е����м�Ϊ��һ������ 
			return; 
		}
	}
}

int main()
{
	vector<int> nums;
	int x;
	int N;
	scanf("%d",&N);//��ȡҪ��������ĸ��� 
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
