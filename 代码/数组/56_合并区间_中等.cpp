//在一维容器、二维容器中sort的使用；

class Solution{
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals)
		{
			if(intervals.size()==0) //如果集合中没有区间 
			{
				return {};
			}
			sort(intervals.begin(),intervals.end()); //对集合按照左端元素进行升序排序
			vector<vector<int>> merged; //merged用来存储合并后的区间集合
			merged.push_back(intervals.begin()); //先将第一个区间放入merged中 
			
			//L和R始终表示当前区间的左端和右端 
			for(int i=0;i<intervals.size();i++)
			{
				int L=intervals[i][0];
				int R=intervals[i][1];
				//如果merged中最后一个区间右端的数merged.back()[1]<当前区间左端的数L,则区间断开,将当前区间直接放入merged 
				if(merged.back()[1]<L)  
				{
					merged.push_back({L,R}); //注意：使用{}直接push_back进去即可 
				}
				//如果merged中最后一个区间的右端点<=当前区间的右端点R，则用当前区间的右端点R更新数组merged中最后一个区间的右端点(即merged.back()[1]=R)
				else if(merged.back()[1]<=R)
				{
					merged.back()[1]=R;
				}
				//而如果最后一个区间右端的数merged.back()[1]>=当前区间右端的数R,保持不动 
				else if(merged.back()[1]>R)
				{
					continue;
				} 
			} 
			return merged;
		}
};
 
 
