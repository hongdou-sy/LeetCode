//时间击败30%,空间击败57% 
class Solution{
public:
	struct Status{
		int lSum; //[l,r]内以l为左端点的最大子段和 
		int rSum; //[l,r]内以r为右端点的最大子段和 
		int mSum; //[l,r]内的最大子段和 
		int iSum; //[l,r]的区间和 
	};
	
	//pushUp函数用于获取合并区间的状态信息
	Status pushUp(Status lSub,Status rSub)
	{
		int iSum=lSub.iSum+rSub.iSum; //获取合并区间的区间和
		int lSum=max(lSub.lSum,lSub.iSum+rSub.lSum);
		int rSum=max(rSub.rSum,rSub.iSum+lSub.rSum);
		int mSum=max(max(lSub.mSum,rSub.mSum),lSub.rSum+rSub.lSum);
		return (Status){lSum,rSum,mSum,iSum}; 
	} 
	
	//get函数用于获取区间[l,r]的状态信息
	Status get(vector<int>& a,int l,int r)
	{
		if(l==r)
		{
			return (Status){a[l],a[l],a[l],a[l]};
		}
		
		int m=(l+r)/2; 
		Status lSub=get(a,l,m); //往左子树获取状态信息 
		Status rSub=get(a,m+1,r); //往右子树获取状态信息 
		return pushUp(lSub,rSub); //合并左右子树的状态信息 
	} 
	
	int maxSubArray(vector<int>& nums)
	{
		Status st=get(nums,0,nums.size()-1); //st为区间[0,nums.size()-1]的状态信息
		return st.mSum; //从状态信息中提取最大子序和 
	}
};
