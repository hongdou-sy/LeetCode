//时间击败26%,空间击败5%
//空间开销太大了,使用了两个字符串和两个哈希表 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		//先确定长字符串和短字符串
		string Long=s.length()>=t.length()?s:t;
		string Short=s.length()<t.length()?s:t;
		//先对长字符串建立哈希表
		unordered_map<char,int> hashL;
		//先对长字符串建立哈希表 
		for(int i=0;i<Long.length();i++)
		{
			if(hashL.find(Long[i])==hashL.end()) //如果找不到字母Long[i]
			{
				hashL[Long[i]]=1;
			} 
			else //如果哈希表中已经有该字符 
			{
				hashL[Long[i]]++;
			}
		} 
		//再对短字符串建立哈希表
		unordered_map<char,int> hashS;
		for(int j=0;j<Short.length();j++)
		{
			if(hashS.find(Short[j])==hashS.end())
			{
				hashS[Short[j]]=1;
			}
			else
			{
				hashS[Short[j]]++;
			}
		} 
		//最后比较两个哈希表是否相同
		for(int k=0;k<Long.length();k++)
		{
			if(hashS.find(Long[k])==hashS.end() || hashS[Long[k]]!=hashL[Long[k]])
				return false;
			else if(hashS[Long[k]]==hashL[Long[k]])
				continue;
		} 
		return true;
	}
};

//同样使用哈希表,但可以只使用一个哈希表
//建立长度为26个字母作为键值的哈希表
//时间击败91%,空间击败37% 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		//如果连长度都不一致,直接return false; 
		if(s.length()!=t.length())
			return false;
		//可以直接使用vector容器,索引为0的为字母'a',索引为25的为字母'z'
		vector<int> hash(26, 0); //初始化为26个值为0的整数
		for(auto& c:s)
		{
			hash[c-'a']++;
		} 
		for(auto& c:t)
		{
			hash[c-'a']--;
			if(hash[c-'a']<0)
				return false;
		}
		return true;
	}
};

//如果是使用Unicode编码,也就是词袋中字符的数目未知
//建立哈希表unordered_map,维护字符的出现频次
//思路和上一个一样
//时间击败26%,空间击败32% 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		if(s.length()!=t.length())
			return false;
		unordered_map<char,int> hash;
		for(auto& c:s)
		{
			if(hash.find(c)==hash.end())
				hash[c]=1;
			else
				hash[c]++;
		}
		for(auto& c:t)
		{
			if(hash.find(c)==hash.end())
				return false;
			else
			{
				hash[c]--;
				if(hash[c]<0)
					return false;
			}
		}
		return true;
	}
};

//还可以使用排序的方法
//先对s和t进行排序,然后判断排序后的两个字符串是否相同
//时间击败11%,空间击败5%
//代码非常简洁,只需三行,但是由于排序,时间和空间复杂度都不低 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
//		if(s==t)
//			return true;
//		else
//			return false;
		//以上四行代码也可以直接写成:
		return s==t; 
	}
};
 

