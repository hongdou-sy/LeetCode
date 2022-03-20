//ʱ�����99%,�ռ����91% 
class Solution{
public:
	//����ʹ��˫ָ�� 
	vector<vector<int> > fourSum(vector<int>& nums,int target)
	{
		vector<vector<int> > ans;
		sort(nums.begin(),nums.end()); //��������������
		
		int length=nums.size();
		if(length<4) return ans; 
		for(int i=0;i<length-3;i++)
		{
//			if(nums[i]>target) break; //���target�Ǳ���������С�ĸ���,�Ͳ��ܽ����ж�nums[i]�� 
			if(i>0 && nums[i]==nums[i-1]) continue; //ȥ��
			if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break; //��nums[i]�̶��������,����С�Ͷ�>target,��ֱ�ӷ��ؽ���� 
			if((long)nums[i]+nums[length-3]+nums[length-2]+nums[length-1]<target) continue; //��nums[i]�̶��������,�����Ͷ�<target,˵����ʱnums[i]С��,ֱ�ӱ�����һ��nums[i] 
			
			for(int j=i+1;j<length-2;j++)
			{
//				if(nums[i]+nums[j]>target) break;
				if(j>i+1 && nums[j]==nums[j-1]) continue; //ȥ�� 
				if((long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
				if((long)nums[i]+nums[j]+nums[length-2]+nums[length-1]<target) continue;
				
				//˫ָ�� 
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
						while(L<R && nums[L]==nums[L+1]) L++; //Ŀ�Ĳ���ȥ��,��������ƶ� 
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
