//思路没问题,但是太过冗杂了
//空间开销过大,哈希表中的值可以直接存储字符串,没必要先存储索引值
//时间击败79%,空间击败39% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//先对字符串数组中的每一个字符串进行排序(对数组strs的拷贝进行排序) 
		//利用哈希表记录相同字符串的索引
		//利用这个哈希表构建结果集
		vector<string> str=strs; //获取strs的拷贝
		for(int i=0;i<str.size();i++)
		{
			sort(str[i].begin(),str[i].end()); //对每个字符串进行排序 
		} 
		
		//构建哈希表,键为字符串,值为其出现的索引 
		unordered_map<string,vector<int> > hash;
		for(int i=0;i<str.size();i++)
		{
				hash[str[i]].push_back(i);
		}
		
		//利用哈希表构建结果集
		vector<vector<string> > ans;
		vector<string> temp;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			for(int i=0;i<it->second.size();i++)
			{
				temp.push_back(strs[it->second[i]]);
			}
			ans.push_back(temp);
			temp.clear();
		} 
		return ans;
	}
};

//官方题解:利用哈希表 
//注意三点:
//①sort函数的使用
//②查找哈希表中是否存在某一键值对利用的是find函数
//③对unordered_map的枚举(利用迭代器遍历unordered_map) 
//时间击败79%,空间击败62% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//对strs中的每一个字符串进行排序,放入哈希表中,哈希表的键为字符串,值为相应的字母异位词
		unordered_map<string,vector<string> > hash;
		for(int i=0;i<strs.size();i++)
		{
			string temp=strs[i]; //不能对原字符串排序,会更改其值
			//要注意对字符串进行排序使用的是其迭代器 
			sort(temp.begin(),temp.end()); //temp已被排序 
			//查找哈希表中是否存在temp键值对(注意这里利用的是find函数) 
//			if(hash.find(temp)==hash.end()) //其实不需要考虑是否存在该键值对,因为vector初始化默认为空表,即使不存在该键值对,直接push_back也没毛病 
//			{
//				hash[temp]={strs[i]};
//			} 
//			else
//			{
				hash[temp].push_back(strs[i]);
//			}
		} 
		
		//利用构建好的哈希表创建结果集
		//注意:如何枚举unordered_map
		vector<vector<string> > ans;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			//it->second指向的就是unordered_map中的值 
			ans.push_back(it->second);
			//或者写为:
//			ans.emplace_back(it->second); 
		} 
		return ans;
	}
};

//官方代码:非常简洁,遍历使用了auto,插入容器使用emplace_back 
//时间击败58%,空间击败47% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//对strs中的每一个字符串进行排序,放入哈希表中,哈希表的键为字符串,值为相应的字母异位词
		unordered_map<string,vector<string> > hash;
		//以上的遍历可以写成如下格式:
		for(auto& str:strs)
		{
			string temp=str;
			sort(temp.begin(),temp.end());
			hash[temp].emplace_back(str);
		} 
		
		//利用构建好的哈希表创建结果集
		//注意:如何枚举unordered_map
		vector<vector<string> > ans;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			//it->second指向的就是unordered_map中的值 
			ans.emplace_back(it->second); 
		} 
		return ans;
	}
};

//官方方法二:计数
//将每个字母出现的次数构成的长度为26的列表转换成字符串作为键值 
//时间击败5%,空间击败5% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		unordered_map<string,vector<string> > hash;
		
		//对strs遍历,获取每个字符串的cnt
		for(auto& st:strs)
		{
			vector<int> cnt(26,0); //初始化数组,共26个元素,每个元素初始化为0
			for(auto& c:st)
			{
				cnt[c-'a']++;
			}
			//将获取的cnt转换为字符串string类型
			string t=""; 
			for(auto& d:cnt)
			{
				t+=to_string(d)+"/";
			}
			hash[t].emplace_back(st);
		} 
		
		vector<vector<string> > ans;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			ans.emplace_back(it->second);
		}
		return ans;
	}
}; 
