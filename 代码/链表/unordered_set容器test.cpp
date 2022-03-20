#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main()
{
    //创建一个空的unordered_set容器
    unordered_set<string> st;
    //给st容器添加数据
    st.emplace("apple");
    st.emplace("pear");
    st.emplace("mango");
    //查看当前st容器中存储的元素个数
    cout<<"元素个数有"<<st.size()<<endl;
    //遍历输出st容器中存储的所有元素
    auto it=st.begin();
    for(;it!=st.end();it++)
    {
        cout<<(*it)<<endl;
    }
    return 0;
}
