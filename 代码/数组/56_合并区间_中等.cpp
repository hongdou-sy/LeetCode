//��һά��������ά������sort��ʹ�ã�

class Solution{
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals)
		{
			if(intervals.size()==0) //���������û������ 
			{
				return {};
			}
			sort(intervals.begin(),intervals.end()); //�Լ��ϰ������Ԫ�ؽ�����������
			vector<vector<int>> merged; //merged�����洢�ϲ�������伯��
			merged.push_back(intervals.begin()); //�Ƚ���һ���������merged�� 
			
			//L��Rʼ�ձ�ʾ��ǰ�������˺��Ҷ� 
			for(int i=0;i<intervals.size();i++)
			{
				int L=intervals[i][0];
				int R=intervals[i][1];
				//���merged�����һ�������Ҷ˵���merged.back()[1]<��ǰ������˵���L,������Ͽ�,����ǰ����ֱ�ӷ���merged 
				if(merged.back()[1]<L)  
				{
					merged.push_back({L,R}); //ע�⣺ʹ��{}ֱ��push_back��ȥ���� 
				}
				//���merged�����һ��������Ҷ˵�<=��ǰ������Ҷ˵�R�����õ�ǰ������Ҷ˵�R��������merged�����һ��������Ҷ˵�(��merged.back()[1]=R)
				else if(merged.back()[1]<=R)
				{
					merged.back()[1]=R;
				}
				//��������һ�������Ҷ˵���merged.back()[1]>=��ǰ�����Ҷ˵���R,���ֲ��� 
				else if(merged.back()[1]>R)
				{
					continue;
				} 
			} 
			return merged;
		}
};
 
 
