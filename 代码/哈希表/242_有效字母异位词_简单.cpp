//ʱ�����26%,�ռ����5%
//�ռ俪��̫����,ʹ���������ַ�����������ϣ�� 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		//��ȷ�����ַ����Ͷ��ַ���
		string Long=s.length()>=t.length()?s:t;
		string Short=s.length()<t.length()?s:t;
		//�ȶԳ��ַ���������ϣ��
		unordered_map<char,int> hashL;
		//�ȶԳ��ַ���������ϣ�� 
		for(int i=0;i<Long.length();i++)
		{
			if(hashL.find(Long[i])==hashL.end()) //����Ҳ�����ĸLong[i]
			{
				hashL[Long[i]]=1;
			} 
			else //�����ϣ�����Ѿ��и��ַ� 
			{
				hashL[Long[i]]++;
			}
		} 
		//�ٶԶ��ַ���������ϣ��
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
		//���Ƚ�������ϣ���Ƿ���ͬ
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

//ͬ��ʹ�ù�ϣ��,������ֻʹ��һ����ϣ��
//��������Ϊ26����ĸ��Ϊ��ֵ�Ĺ�ϣ��
//ʱ�����91%,�ռ����37% 
class Solution{
public:
	bool isAnagram(string s,string t)
	{
		//��������ȶ���һ��,ֱ��return false; 
		if(s.length()!=t.length())
			return false;
		//����ֱ��ʹ��vector����,����Ϊ0��Ϊ��ĸ'a',����Ϊ25��Ϊ��ĸ'z'
		vector<int> hash(26, 0); //��ʼ��Ϊ26��ֵΪ0������
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

//�����ʹ��Unicode����,Ҳ���Ǵʴ����ַ�����Ŀδ֪
//������ϣ��unordered_map,ά���ַ��ĳ���Ƶ��
//˼·����һ��һ��
//ʱ�����26%,�ռ����32% 
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

//������ʹ������ķ���
//�ȶ�s��t��������,Ȼ���ж������������ַ����Ƿ���ͬ
//ʱ�����11%,�ռ����5%
//����ǳ����,ֻ������,������������,ʱ��Ϳռ临�Ӷȶ����� 
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
		//�������д���Ҳ����ֱ��д��:
		return s==t; 
	}
};
 

