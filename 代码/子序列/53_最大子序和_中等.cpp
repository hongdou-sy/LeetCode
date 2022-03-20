//ʱ�����30%,�ռ����57% 
class Solution{
public:
	struct Status{
		int lSum; //[l,r]����lΪ��˵������Ӷκ� 
		int rSum; //[l,r]����rΪ�Ҷ˵������Ӷκ� 
		int mSum; //[l,r]�ڵ�����Ӷκ� 
		int iSum; //[l,r]������� 
	};
	
	//pushUp�������ڻ�ȡ�ϲ������״̬��Ϣ
	Status pushUp(Status lSub,Status rSub)
	{
		int iSum=lSub.iSum+rSub.iSum; //��ȡ�ϲ�����������
		int lSum=max(lSub.lSum,lSub.iSum+rSub.lSum);
		int rSum=max(rSub.rSum,rSub.iSum+lSub.rSum);
		int mSum=max(max(lSub.mSum,rSub.mSum),lSub.rSum+rSub.lSum);
		return (Status){lSum,rSum,mSum,iSum}; 
	} 
	
	//get�������ڻ�ȡ����[l,r]��״̬��Ϣ
	Status get(vector<int>& a,int l,int r)
	{
		if(l==r)
		{
			return (Status){a[l],a[l],a[l],a[l]};
		}
		
		int m=(l+r)/2; 
		Status lSub=get(a,l,m); //����������ȡ״̬��Ϣ 
		Status rSub=get(a,m+1,r); //����������ȡ״̬��Ϣ 
		return pushUp(lSub,rSub); //�ϲ�����������״̬��Ϣ 
	} 
	
	int maxSubArray(vector<int>& nums)
	{
		Status st=get(nums,0,nums.size()-1); //stΪ����[0,nums.size()-1]��״̬��Ϣ
		return st.mSum; //��״̬��Ϣ����ȡ�������� 
	}
};
