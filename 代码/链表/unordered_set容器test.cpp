#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main()
{
    //����һ���յ�unordered_set����
    unordered_set<string> st;
    //��st�����������
    st.emplace("apple");
    st.emplace("pear");
    st.emplace("mango");
    //�鿴��ǰst�����д洢��Ԫ�ظ���
    cout<<"Ԫ�ظ�����"<<st.size()<<endl;
    //�������st�����д洢������Ԫ��
    auto it=st.begin();
    for(;it!=st.end();it++)
    {
        cout<<(*it)<<endl;
    }
    return 0;
}
