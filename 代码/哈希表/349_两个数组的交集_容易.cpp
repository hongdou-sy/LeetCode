//时间击败88%,空间击败69% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		//键存储元素值,值存储0和1,1表示nums2中的这个元素已经访问过
		//unordered_map查询的时间复杂度为O(1),map查询的时间复杂度为O(logn),所以哈希表使用unordered_map 
		unordered_map<int,int> hash;
		vector<int> ans;
		for(int i=0;i<nums1.size();i++)
		{
			if(hash.find(nums1[i])==hash.end())
			{
				hash[nums1[i]]=0; //初始时均未访问 
			}
		}
		for(int j=0;j<nums2.size();j++)
		{
			//如果哈希表中有nums2[j],并且nums2[j]这个数尚未被访问 
			if(hash.find(nums2[j])!=hash.end() && hash[nums2[j]]==0)
			{
				ans.push_back(nums2[j]);
				hash[nums2[j]]=1; //将其标记为已访问 
			}
		} 
		return ans;
	}
};

//与上面思路相同,简化代码
//时间击败88%,空间击败68% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		vector<int> ans;
		//在定义哈希表的同时初始化为nums1中的元素 
		unordered_set<int> hash{nums1.begin(),nums1.end()}; 
		
		//对nums2中的元素进行遍历 
		for(auto& i:nums2) //i此时并非迭代器,而是元素值 
		{
			if(hash.find(i)!=hash.end()) //如果哈希表中存在nums2中的数
			{
				//以下两句代码都可行 
//				ans.push_back(i);
				ans.emplace_back(i); //添加入结果集 
				hash.erase(i); //删除哈希表的该元素 
			} 
		}
		return ans;
	}
}; 

//官方思路:排序+双指针(官方貌似很喜欢用双指针)
//时间击败88%,空间击败92% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		vector<int> ans;
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		
		vector<int>::iterator it1=nums1.begin();
		vector<int>::iterator it2=nums2.begin();
		int pre=-1; //pre用于验证元素是否出现过 
		while(it1!=nums1.end() && it2!=nums2.end())
		{
			if(*it1==*it2)
			{
				if(*it1!=pre) //若元素未出现过,将此时的元素添加进结果集 
				{
					ans.push_back(*it1);
					pre=*it1;
				}
				it1++;
				it2++;
			}
			else if(*it1<*it2)
			{
				it1++;
			}
			else if(*it1>*it2)
			{
				it2++;
			}
		}
		return ans;
	}
}; 

class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		vector<int> ans;
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		
		vector<int>::iterator it1=nums1.begin();
		vector<int>::iterator it2=nums2.begin();
		while(it1!=nums1.end() && it2!=nums2.end())
		{
			if(*it1==*it2)
			{
				//保证元素的唯一性
				//若结果集里面尚未有元素,直接添加
				//若此时的元素在结果集内尚未出现过,直接添加 
				if(ans.size()==0 || *it1!=ans.back()) 
				{
					ans.push_back(*it1);
				}
				it1++;
				it2++;
			}
			else if(*it1<*it2)
			{
				it1++;
			}
			else if(*it1>*it2)
			{
				it2++;
			}
		}
		return ans;
	}
}; 
