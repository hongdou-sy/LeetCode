//时间击败99%,空间击败91% 
class Solution{
public:
	//还是使用双指针 
	vector<vector<int> > fourSum(vector<int>& nums,int target)
	{
		vector<vector<int> > ans;
		sort(nums.begin(),nums.end()); //对容器进行排序
		
		int length=nums.size();
		if(length<4) return ans; 
		for(int i=0;i<length-3;i++)
		{
//			if(nums[i]>target) break; //如果target是比所有数都小的负数,就不能仅仅判断nums[i]了 
			if(i>0 && nums[i]==nums[i-1]) continue; //去重
			if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break; //在nums[i]固定的情况下,若最小和都>target,则直接返回结果集 
			if((long)nums[i]+nums[length-3]+nums[length-2]+nums[length-1]<target) continue; //在nums[i]固定的情况下,若最大和都<target,说明此时nums[i]小了,直接遍历下一个nums[i] 
			
			for(int j=i+1;j<length-2;j++)
			{
//				if(nums[i]+nums[j]>target) break;
				if(j>i+1 && nums[j]==nums[j-1]) continue; //去重 
				if((long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
				if((long)nums[i]+nums[j]+nums[length-2]+nums[length-1]<target) continue;
				
				//双指针 
				int L=j+1;
				int R=length-1;
				while(L<R)
				{
					int sum=nums[i]+nums[j]+nums[L]+nums[R];
					if(sum<target)
						L++;
					else if(sum>target)
						R--;
					else if(sum==target)
					{
						ans.push_back({nums[i],nums[j],nums[L],nums[R]});
						while(L<R && nums[L]==nums[L+1]) L++; //目的不是去重,而是向后移动 
						while(L<R && nums[R]==nums[R-1]) R--;
						L++;
						R--;
					}
				}
			}
		}
		return ans;
	}
};
