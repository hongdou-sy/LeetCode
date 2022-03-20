//知识点:vector的排序操作 
//STL里的sort算法用的什么排序算法？ 
//时间打败93%,空间打败98% 
class Solution{
public:
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		//先进行排序
		sort(nums.begin(),nums.end());
		vector<vector<int> > ans;
		
		int length=nums.size();
		if(length<3) return ans;
		for(int i=0;i<length;i++) //第一重循环 
		{
			if(nums[i]>0) break; //如果第一个数就>0,说明后面不可能再有两个数使得和为0了
			if(i>0 && nums[i]==nums[i-1]) continue; //一重循环去重 
			
			//使用双指针L和R,初始时分别指向nums[i]后的头元素和尾元素 
			int L=i+1;
			int R=length-1;
			while(L<R) //进入二重循环,确定第二个和第三个加数 
			{
				int sum=nums[i]+nums[L]+nums[R];
				if(sum>0) //如果此时三数之和>0,说明nums[R]大了 
					R--;
				else if(sum<0) //如果此时三数之和<0,说明nums[L]小了
					L++; 
				else if(sum==0)//如果此时三数之和等于0,存入结果后继续下一组遍历 
				{
					ans.push_back({nums[i],nums[L],nums[R]}); //存入结果 
					while(L<R && nums[L+1]==nums[L]) L++; //去重,保证下一个L和上一个不同 
					while(L<R && nums[R-1]==nums[R]) R--; //去重,保证下一个R和上一个不同 
					L++;
					R--; 
				} 
			}
		}
		return ans;
	}
};
