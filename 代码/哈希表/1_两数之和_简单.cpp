//�����ñ����ƽ�
//ʱ�����7%,�ռ����76% 
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
					return {i,j}; //ֱ�ӷ��ظ�����(Ĭ��Ϊ��vector����) 
				}
			}
		}
		return {}; //����������˲��������������Ľ��,Ҫ�ǵ÷��ؿ�����{} 
	}
}; 


class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target)
	{
		//ʹ��unordered_set������ϣ��
		unordered_set<int> hash;
		//����nums�е�ÿһ��Ԫ��x,�ж�target-x�Ƿ��ڹ�ϣ����
		//��˵�һ����Ҫ��nums�е�Ԫ�ض�����hash����
		for(int i=0;i<nums.size();i++)
		{
			hash.insert(nums[i]);
		} 
		for(int i=0;i<nums.size();i++)
		{
			//Ҫ��֤ͬһ��Ԫ�ز����ظ�����,Ҳ����nums[i]��target-nums[i]������ֵ�ڹ�ϣ���е�����λ�ò�һ��
			//����Ϊunordered_set����������,û�취ȷ������ֵ,���Ը��������� 
			//����һ������unordered_set������ԭ��unordered_set�����в������ظ�Ԫ��,��nums�����п��ܻ��� 
			if(hash.count(target-nums[i])&&)
		}
		 
	}
};

//��ϣ�� 
//ʱ�䳬��92%,�ռ䳬��20% 
class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target)
	{
		//ʹ��unordered_map������ϣ��,��Ϊnums�еĸ���Ԫ��,ֵ��ʾ���Ӧ���±� 
		unordered_map<int,int> hash;
		
		for(int i=0;i<nums.size();i++)
		{
			auto it=hash.find(target-nums[i]); //�ж�hash�����Ƿ����target-nums[i]
			if(it!=hash.end())//���hash���д���target-nums[i]
			{
				return {it->second,i}; //����nums[i]��target-nums[i]��Ӧ���±� 
			} 
			//���hash���в�����target-nums[i],���ǰѵ�ǰ�Ƚϵ���Լ�ֵ����hash����
			hash[nums[i]]=i; 
		}
		return {};
	}
};
