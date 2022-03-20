struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* next):val(x),next(next){}
};

void merge(ListNode* left,ListNode* right)
{
	ListNode* first=left;
	ListNode* second=right;
	ListNode* ans=new ListNode(0); //先用链表ans暂时存储答案链表
	while(first!=NULL&&second!=NULL)
	{
		if(first->val<second->val)
		{
			ans->next=first;
			first=first->next;
		}
		else
		{
			ans->next=second;
			second=second->next;
		}
		ans=ans->next;
	} 
	ans->next=first!=NULL?first:second;
	//再将合并后的链表依次接入以left为头节点的链表 
	ListNode* t=ans->next;
	left=t; //先将头结点赋给left 
	t=t->next;
	while(t!=NULL)
	{
		left->next=t;
		t=t->next;
	}//此时left开始[left,right+subLength-1]就是合并之后的链表 
}

ListNode* sortList(ListNode* head)
{
	while(head==NULL)
		return NULL;
	//确定链表长度
	ListNode* temp=head;
	int length=0;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;
	} 
	//附加一个哑结点 
	ListNode* dummyNode=new ListNode(0,head);
	temp=dummyNode;
	int subLength=1; //从长度为1的子链表开始排序 
	//直到子链表的长度大于原链表的长度,就不再进行合并 
	while(subLength<length) 
	{
		while(temp!=NULL)
		{
			//在进行合并的时候,只需要知道头结点和左边中点即可 
			ListNode* left=temp->next;
			for(int i=0;i<subLength-1;i++)
			{
				temp=temp->next;
			}//此时temp指向left开始的前半部分的最后一个结点 
			//如果从left开始剩下的结点不足subLength个,就不再进行合并 
			if(temp==NULL)
				break;
			ListNode* right=temp->next;
			merge(left,right);
		}
		subLength*=2;
	}
} 
