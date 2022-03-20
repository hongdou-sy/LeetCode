//归并排序
//Merge函数用于归并两个序列
//将a数组中[low,mid](已排序)和[mid+1,high](已排序)这两组元素进行合并,合并之后的元素先存放到temp数组 
void Merge(int a[],int low,int mid,int high) 
{
	int *temp=new int[high-low+1]; //temp数组用来暂存合并的有序序列 
	int i=low; //指针i指向前半部分第一个元素
	int j=mid+1; //指针j指向后半部分第一个元素
	int k=0; //k表示temp数组中已放入的元素个数 
	
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

	//最后将temp数组中的元素因此存入数组a中
	for(int m=low,n=0;m<=high;m++,n++)
	{
		a[m]=temp[n];
	} 
	delete []temp; //释放数组内存 
}

//递归函数实现归并排序,[low,high]为排序的数组范围 
void MergeSort(int a[],int low,int high)
{
	if(low>=high) //递归终止 
		return; //子序列长度为1时,终止递归 
	int mid=low+(high-low)/2;
	MergeSort(a,low,mid);
	MergeSort(a,mid+1,high);
	Merge(a,low,mid,high);
}
