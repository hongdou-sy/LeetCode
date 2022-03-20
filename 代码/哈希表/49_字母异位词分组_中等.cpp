//˼·û����,����̫��������
//�ռ俪������,��ϣ���е�ֵ����ֱ�Ӵ洢�ַ���,û��Ҫ�ȴ洢����ֵ
//ʱ�����79%,�ռ����39% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//�ȶ��ַ��������е�ÿһ���ַ�����������(������strs�Ŀ�����������) 
		//���ù�ϣ���¼��ͬ�ַ���������
		//���������ϣ���������
		vector<string> str=strs; //��ȡstrs�Ŀ���
		for(int i=0;i<str.size();i++)
		{
			sort(str[i].begin(),str[i].end()); //��ÿ���ַ����������� 
		} 
		
		//������ϣ��,��Ϊ�ַ���,ֵΪ����ֵ����� 
		unordered_map<string,vector<int> > hash;
		for(int i=0;i<str.size();i++)
		{
				hash[str[i]].push_back(i);
		}
		
		//���ù�ϣ���������
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

//�ٷ����:���ù�ϣ�� 
//ע������:
//��sort������ʹ��
//�ڲ��ҹ�ϣ�����Ƿ����ĳһ��ֵ�����õ���find����
//�۶�unordered_map��ö��(���õ���������unordered_map) 
//ʱ�����79%,�ռ����62% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//��strs�е�ÿһ���ַ�����������,�����ϣ����,��ϣ��ļ�Ϊ�ַ���,ֵΪ��Ӧ����ĸ��λ��
		unordered_map<string,vector<string> > hash;
		for(int i=0;i<strs.size();i++)
		{
			string temp=strs[i]; //���ܶ�ԭ�ַ�������,�������ֵ
			//Ҫע����ַ�����������ʹ�õ���������� 
			sort(temp.begin(),temp.end()); //temp�ѱ����� 
			//���ҹ�ϣ�����Ƿ����temp��ֵ��(ע���������õ���find����) 
//			if(hash.find(temp)==hash.end()) //��ʵ����Ҫ�����Ƿ���ڸü�ֵ��,��Ϊvector��ʼ��Ĭ��Ϊ�ձ�,��ʹ�����ڸü�ֵ��,ֱ��push_backҲûë�� 
//			{
//				hash[temp]={strs[i]};
//			} 
//			else
//			{
				hash[temp].push_back(strs[i]);
//			}
		} 
		
		//���ù����õĹ�ϣ���������
		//ע��:���ö��unordered_map
		vector<vector<string> > ans;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			//it->secondָ��ľ���unordered_map�е�ֵ 
			ans.push_back(it->second);
			//����дΪ:
//			ans.emplace_back(it->second); 
		} 
		return ans;
	}
};

//�ٷ�����:�ǳ����,����ʹ����auto,��������ʹ��emplace_back 
//ʱ�����58%,�ռ����47% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		//��strs�е�ÿһ���ַ�����������,�����ϣ����,��ϣ��ļ�Ϊ�ַ���,ֵΪ��Ӧ����ĸ��λ��
		unordered_map<string,vector<string> > hash;
		//���ϵı�������д�����¸�ʽ:
		for(auto& str:strs)
		{
			string temp=str;
			sort(temp.begin(),temp.end());
			hash[temp].emplace_back(str);
		} 
		
		//���ù����õĹ�ϣ���������
		//ע��:���ö��unordered_map
		vector<vector<string> > ans;
		for(auto it=hash.begin();it!=hash.end();it++)
		{
			//it->secondָ��ľ���unordered_map�е�ֵ 
			ans.emplace_back(it->second); 
		} 
		return ans;
	}
};

//�ٷ�������:����
//��ÿ����ĸ���ֵĴ������ɵĳ���Ϊ26���б�ת�����ַ�����Ϊ��ֵ 
//ʱ�����5%,�ռ����5% 
class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs)
	{
		unordered_map<string,vector<string> > hash;
		
		//��strs����,��ȡÿ���ַ�����cnt
		for(auto& st:strs)
		{
			vector<int> cnt(26,0); //��ʼ������,��26��Ԫ��,ÿ��Ԫ�س�ʼ��Ϊ0
			for(auto& c:st)
			{
				cnt[c-'a']++;
			}
			//����ȡ��cntת��Ϊ�ַ���string����
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
