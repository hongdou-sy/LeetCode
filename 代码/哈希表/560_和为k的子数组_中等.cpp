//暴力解法会超时 
//如下的时间复杂度达到了O(n^3) 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//可以使用双指针,一个指针用于固定,一个指针用于向后枚举
		int len=nums.size();
		int cnt=0; //cnt表示连续子数组的个数 
		for(int L=0;L<len;L++)
		{
			int R=L; //L和R都为nums的索引值
			while(R<len)
			{
				//找到和为k的子数组 
				if(getSum(nums,L,R)==k)
				{
					cnt++; 
				}
				R++;
			} 
		}
		return cnt; 
	}
	
	int getSum(vector<int>& nums,int L,int R)
	{
		int sum=0;
		for(int i=L;i<=R;i++)
		{
			sum+=nums[i];
		}
		return sum;
	}
};

//把以上代码优化成O(n^2) 
//当然还是超时(搞半天,,,官方题解差评) 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//可以使用双指针,一个指针用于固定,一个指针用于向后枚举
		int len=nums.size();
		int cnt=0; //cnt表示连续子数组的个数 
		for(int L=0;L<len;L++)
		{
			int R=L; //L和R都为nums的索引值
			int sum=0;
			for(;R<len;R++)
			{
				sum+=nums[R];
				//找到和为k的子数组 
				if(sum==k)
				{
					cnt++; 
				}
			} 
		}
		return cnt; 
	}
};

//官方题解二:前缀和+哈希表优化 
//时间击败38%,空间击败77% 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//创建哈希表,键为前缀和,值为该前缀和出现的次数(因为要考虑有负数的可能) 
		unordered_map<int,int> hash;
		int pre=0; //pre表示当前前缀和 
		int cnt=0;
		hash[0]=1; //先初始化哈希表:前缀和为0出现的次数为1次 
		
		for(int i=0;i<nums.size();i++)
		{
			//更新哈希表 
			pre+=nums[i]; //计算前缀和pre[i]
			
			//查找前缀和为pre[i]-k出现的次数
			int temp=pre-k;
			//如果存在该键 
			if(hash.find(temp)!=hash.end())
			{
				cnt+=hash[temp];
			} 
			
			//因为哈希表中int默认初始为0,所以不需要考虑其刚开始是否存在,直接++
			hash[pre]++; 
		}
		return cnt;
	}
};



