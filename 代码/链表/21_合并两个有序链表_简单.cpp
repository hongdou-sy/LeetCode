struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//ʱ�����93%,�ռ����85% 
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
	{
		//ʹ������ָ�������������
		ListNode* first=list1;
		ListNode* second=list2;
		ListNode* ans=new ListNode();
		ListNode* curr=ans;
		while(first!=NULL&&second!=NULL)
		{
			if(first->val<second->val) //���firstָ��Ľ���С,��������� 
			{
				curr->next=first;
				curr=curr->next;
				first=first->next;
			}
			else if(first->val>=second->val) //���secondָ��Ľ���С,��������� 
			{
				curr->next=second;
				curr=curr->next; 
				second=second->next;
			}
		} 
		//�����һ�������������,ֱ�ӽ���һ������ʣ��Ľ����������
		if(first!=NULL)
		{
			curr->next=first;
		} 
		else if(second!=NULL)
		{
			curr->next=second;
		}
		return ans->next;
	}
};

//ʱ�����62%,�ռ����99% 
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
	{
		if(list1==NULL)
			return list2;
		if(list2==NULL)
			return list1;
		if(list1->val<list2->val)
		{
			list1->next=mergeTwoList(list1->next,list2);
			return list1;
		}
		list2->next=mergeTwoList(list1,list2->next);
		return list2;
	}
};
