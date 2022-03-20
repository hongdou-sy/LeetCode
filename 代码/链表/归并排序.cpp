//�鲢����
//Merge�������ڹ鲢��������
//��a������[low,mid](������)��[mid+1,high](������)������Ԫ�ؽ��кϲ�,�ϲ�֮���Ԫ���ȴ�ŵ�temp���� 
void Merge(int a[],int low,int mid,int high) 
{
	int *temp=new int[high-low+1]; //temp���������ݴ�ϲ����������� 
	int i=low; //ָ��iָ��ǰ�벿�ֵ�һ��Ԫ��
	int j=mid+1; //ָ��jָ���벿�ֵ�һ��Ԫ��
	int k=0; //k��ʾtemp�������ѷ����Ԫ�ظ��� 
	
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	} 
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];

	//���temp�����е�Ԫ����˴�������a��
	for(int m=low,n=0;m<=high;m++,n++)
	{
		a[m]=temp[n];
	} 
	delete []temp; //�ͷ������ڴ� 
}

//�ݹ麯��ʵ�ֹ鲢����,[low,high]Ϊ��������鷶Χ 
void MergeSort(int a[],int low,int high)
{
	if(low>=high) //�ݹ���ֹ 
		return; //�����г���Ϊ1ʱ,��ֹ�ݹ� 
	int mid=low+(high-low)/2;
	MergeSort(a,low,mid);
	MergeSort(a,mid+1,high);
	Merge(a,low,mid,high);
}
