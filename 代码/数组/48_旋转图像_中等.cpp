//swap函数的用法 
//二维数组的动态输入(使用vector) 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//以翻转代替旋转
//先以水平对称轴翻转，再以主对角线翻转 
void rotate(vector<vector<int> >& matrix) //vector容器里的每一个元素也都是vector容器(两维都是变长的) 
{
	int n=matrix.size();//获取二维数组的列数
	
	//先以水平对称轴翻转 
	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n;j++) //将一行的各个元素分别翻转 
		{
			swap(matrix[i][j],matrix[n-i-1][j]);
		}
	}
	
	//再以对角线进行翻转
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			swap(matrix[i][j],matrix[j][i]);
		}
	} 
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	vector<vector<int> > v; //定义一个二维数组 
	vector<int> t; //定义一个一维数组 
	
	for(int i=0;i<n;i++)
	{
		t.clear(); //子数组返回时要清除
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			t.push_back(temp);
		} 
		v.push_back(t); //将获取的一维数组放入二维数组中 
	} 
	
	rotate(v);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
