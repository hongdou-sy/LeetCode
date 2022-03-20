//先利用暴力破解
//时间击败7%,空间击败76% 
class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target)
	{
//		vector<int> ans;
		for(int i=0;i<nums.size()-1;i++)
		{
			for(int j=i;j<nums.size();j++)
			{
				if(nums[i]+nums[j]==target)
				{
//					ans.push_back(i);
//					ans.push_back(j);
//					return ans;
					return {i,j}; //直接返回该组数(默认为了vector类型) 
				}
			}
		}
		return {}; //如果遍历完了不存在满足条件的结果,要记得返回空容器{} 
	}
}; 


class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target)
	{
		//使用unordered_set构建哈希表
		unordered_set<int> hash;
		//对于nums中的每一个元素x,判断target-x是否在哈希表中
		//因此第一步就要将nums中的元素都放入hash表中
		for(int i=0;i<nums.size();i++)
		{
			hash.insert(nums[i]);
		} 
		for(int i=0;i<nums.size();i++)
		{
			//要保证同一个元素不能重复出现,也就是nums[i]和target-nums[i]这两个值在哈希表中的索引位置不一样
			//但因为unordered_set是无序容器,没办法确定索引值,所以该容器弃用 
			//还有一个弃用unordered_set容器的原因：unordered_set容器中不能有重复元素,但nums数组中可能会有 
			if(hash.count(target-nums[i])&&)
		}
		 
	}
};

//哈希表 
//时间超过92%,空间超过20% 
class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target)
	{
		//使用unordered_map构建哈希表,键为nums中的各个元素,值表示其对应的下标 
		unordered_map<int,int> hash;
		
		for(int i=0;i<nums.size();i++)
		{
			auto it=hash.find(target-nums[i]); //判断hash表中是否存在target-nums[i]
			if(it!=hash.end())//如果hash表中存在target-nums[i]
			{
				return {it->second,i}; //返回nums[i]和target-nums[i]对应的下标 
			} 
			//如果hash表中不存在target-nums[i],我们把当前比较的这对键值放入hash表中
			hash[nums[i]]=i; 
		}
		return {};
	}
};
