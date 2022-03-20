struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* next):val(x),next(next){}
};

//时间击败38%,空间击败14% 
class Solution{
public:
	//对以head为头结点的链表进行排序,返回排好序的链表头结点
	//start为开始排序的链表范围头结点 
	ListNode* sortList(ListNode* head)  
	{
		if(head==NULL||head->next==NULL)
		{
			return head; //此时只有一个结点了,直接返回此节点 
		}
		//使用快慢指针找到中点,如果是偶数个数,找到中心左边的结点
		ListNode* fast=head->next ;
		ListNode* slow=head;
		while(fast!=NULL&&fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		} //此时slow指向中点 
		
		ListNode* temp=slow->next; //temp指向后半部分第一个结点
		slow->next=NULL; //将链表从中点断开
		ListNode* left=sortList(head);
		ListNode* right=sortList(temp);
		ListNode* h=new ListNode(0); //新建结点h存储合并后的链表
		ListNode* res=h; //res链表代表最终结果
		
		//合并两个链表left和right 
		while(left!=NULL&&right!=NULL)
		{
			if(left->val<right->val)
			{
				h->next=left;
				left=left->next;
			}
			else
			{
				h->next=right;
				right=right->next;
			}
			h=h->next;
		 } 
		 h->next=left!=NULL?left:right;
		 return res->next;
	}
};
