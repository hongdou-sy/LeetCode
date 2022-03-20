//swap�������÷� 
//��ά����Ķ�̬����(ʹ��vector) 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//�Է�ת������ת
//����ˮƽ�Գ��ᷭת���������Խ��߷�ת 
void rotate(vector<vector<int> >& matrix) //vector�������ÿһ��Ԫ��Ҳ����vector����(��ά���Ǳ䳤��) 
{
	int n=matrix.size();//��ȡ��ά���������
	
	//����ˮƽ�Գ��ᷭת 
	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n;j++) //��һ�еĸ���Ԫ�طֱ�ת 
		{
			swap(matrix[i][j],matrix[n-i-1][j]);
		}
	}
	
	//���ԶԽ��߽��з�ת
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
	vector<vector<int> > v; //����һ����ά���� 
	vector<int> t; //����һ��һά���� 
	
	for(int i=0;i<n;i++)
	{
		t.clear(); //�����鷵��ʱҪ���
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			t.push_back(temp);
		} 
		v.push_back(t); //����ȡ��һά��������ά������ 
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
