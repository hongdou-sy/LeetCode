//�����ⷨ�ᳬʱ 
//���µ�ʱ�临�Ӷȴﵽ��O(n^3) 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//����ʹ��˫ָ��,һ��ָ�����ڹ̶�,һ��ָ���������ö��
		int len=nums.size();
		int cnt=0; //cnt��ʾ����������ĸ��� 
		for(int L=0;L<len;L++)
		{
			int R=L; //L��R��Ϊnums������ֵ
			while(R<len)
			{
				//�ҵ���Ϊk�������� 
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

//�����ϴ����Ż���O(n^2) 
//��Ȼ���ǳ�ʱ(�����,,,�ٷ�������) 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//����ʹ��˫ָ��,һ��ָ�����ڹ̶�,һ��ָ���������ö��
		int len=nums.size();
		int cnt=0; //cnt��ʾ����������ĸ��� 
		for(int L=0;L<len;L++)
		{
			int R=L; //L��R��Ϊnums������ֵ
			int sum=0;
			for(;R<len;R++)
			{
				sum+=nums[R];
				//�ҵ���Ϊk�������� 
				if(sum==k)
				{
					cnt++; 
				}
			} 
		}
		return cnt; 
	}
};

//�ٷ�����:ǰ׺��+��ϣ���Ż� 
//ʱ�����38%,�ռ����77% 
class Solution{
public:
	int subarraySum(vector<int>& nums,int k)
	{
		//������ϣ��,��Ϊǰ׺��,ֵΪ��ǰ׺�ͳ��ֵĴ���(��ΪҪ�����и����Ŀ���) 
		unordered_map<int,int> hash;
		int pre=0; //pre��ʾ��ǰǰ׺�� 
		int cnt=0;
		hash[0]=1; //�ȳ�ʼ����ϣ��:ǰ׺��Ϊ0���ֵĴ���Ϊ1�� 
		
		for(int i=0;i<nums.size();i++)
		{
			//���¹�ϣ�� 
			pre+=nums[i]; //����ǰ׺��pre[i]
			
			//����ǰ׺��Ϊpre[i]-k���ֵĴ���
			int temp=pre-k;
			//������ڸü� 
			if(hash.find(temp)!=hash.end())
			{
				cnt+=hash[temp];
			} 
			
			//��Ϊ��ϣ����intĬ�ϳ�ʼΪ0,���Բ���Ҫ������տ�ʼ�Ƿ����,ֱ��++
			hash[pre]++; 
		}
		return cnt;
	}
};



