//֪ʶ��:vector��������� 
//STL���sort�㷨�õ�ʲô�����㷨�� 
//ʱ����93%,�ռ���98% 
class Solution{
public:
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		//�Ƚ�������
		sort(nums.begin(),nums.end());
		vector<vector<int> > ans;
		
		int length=nums.size();
		if(length<3) return ans;
		for(int i=0;i<length;i++) //��һ��ѭ�� 
		{
			if(nums[i]>0) break; //�����һ������>0,˵�����治��������������ʹ�ú�Ϊ0��
			if(i>0 && nums[i]==nums[i-1]) continue; //һ��ѭ��ȥ�� 
			
			//ʹ��˫ָ��L��R,��ʼʱ�ֱ�ָ��nums[i]���ͷԪ�غ�βԪ�� 
			int L=i+1;
			int R=length-1;
			while(L<R) //�������ѭ��,ȷ���ڶ����͵��������� 
			{
				int sum=nums[i]+nums[L]+nums[R];
				if(sum>0) //�����ʱ����֮��>0,˵��nums[R]���� 
					R--;
				else if(sum<0) //�����ʱ����֮��<0,˵��nums[L]С��
					L++; 
				else if(sum==0)//�����ʱ����֮�͵���0,�������������һ����� 
				{
					ans.push_back({nums[i],nums[L],nums[R]}); //������ 
					while(L<R && nums[L+1]==nums[L]) L++; //ȥ��,��֤��һ��L����һ����ͬ 
					while(L<R && nums[R-1]==nums[R]) R--; //ȥ��,��֤��һ��R����һ����ͬ 
					L++;
					R--; 
				} 
			}
		}
		return ans;
	}
};
