struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//时间击败93%,空间击败85% 
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
	{
		//使用两个指针遍历两个链表
		ListNode* first=list1;
		ListNode* second=list2;
		ListNode* ans=new ListNode();
		ListNode* curr=ans;
		while(first!=NULL&&second!=NULL)
		{
			if(first->val<second->val) //如果first指向的结点较小,插入答案链表 
			{
				curr->next=first;
				curr=curr->next;
				first=first->next;
			}
			else if(first->val>=second->val) //如果second指向的结点较小,插入答案链表 
			{
				curr->next=second;
				curr=curr->next; 
				second=second->next;
			}
		} 
		//如果有一个链表遍历结束,直接将另一个链表剩余的结点插入答案链表
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

//时间击败62%,空间击败99% 
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
