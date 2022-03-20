//ʱ�����88%,�ռ����69% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		//���洢Ԫ��ֵ,ֵ�洢0��1,1��ʾnums2�е����Ԫ���Ѿ����ʹ�
		//unordered_map��ѯ��ʱ�临�Ӷ�ΪO(1),map��ѯ��ʱ�临�Ӷ�ΪO(logn),���Թ�ϣ��ʹ��unordered_map 
		unordered_map<int,int> hash;
		vector<int> ans;
		for(int i=0;i<nums1.size();i++)
		{
			if(hash.find(nums1[i])==hash.end())
			{
				hash[nums1[i]]=0; //��ʼʱ��δ���� 
			}
		}
		for(int j=0;j<nums2.size();j++)
		{
			//�����ϣ������nums2[j],����nums2[j]�������δ������ 
			if(hash.find(nums2[j])!=hash.end() && hash[nums2[j]]==0)
			{
				ans.push_back(nums2[j]);
				hash[nums2[j]]=1; //������Ϊ�ѷ��� 
			}
		} 
		return ans;
	}
};

//������˼·��ͬ,�򻯴���
//ʱ�����88%,�ռ����68% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		vector<int> ans;
		//�ڶ����ϣ���ͬʱ��ʼ��Ϊnums1�е�Ԫ�� 
		unordered_set<int> hash{nums1.begin(),nums1.end()}; 
		
		//��nums2�е�Ԫ�ؽ��б��� 
		for(auto& i:nums2) //i��ʱ���ǵ�����,����Ԫ��ֵ 
		{
			if(hash.find(i)!=hash.end()) //�����ϣ���д���nums2�е���
			{
				//����������붼���� 
//				ans.push_back(i);
				ans.emplace_back(i); //��������� 
				hash.erase(i); //ɾ����ϣ��ĸ�Ԫ�� 
			} 
		}
		return ans;
	}
}; 

//�ٷ�˼·:����+˫ָ��(�ٷ�ò�ƺ�ϲ����˫ָ��)
//ʱ�����88%,�ռ����92% 
class Solution{
public:
	vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
	{
		vector<int> ans;
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		
		vector<int>::iterator it1=nums1.begin();
		vector<int>::iterator it2=nums2.begin();
		int pre=-1; //pre������֤Ԫ���Ƿ���ֹ� 
		while(it1!=nums1.end() && it2!=nums2.end())
		{
			if(*it1==*it2)
			{
				if(*it1!=pre) //��Ԫ��δ���ֹ�,����ʱ��Ԫ����ӽ������ 
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
				//��֤Ԫ�ص�Ψһ��
				//�������������δ��Ԫ��,ֱ�����
				//����ʱ��Ԫ���ڽ��������δ���ֹ�,ֱ����� 
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
