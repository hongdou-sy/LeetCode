//空间打败37%,时间打败55% 
bool isPalindrome(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	//快指针fast走到链表尾部时,慢指针slow刚好走到前半部分的尾结点 
	while(fast->next!=NULL&&fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	} 
	
	ListNode* prev=reverseList(slow->next); //返回反转之后的后半部分链表 
	
	//此时prev表示反转之后的后半部分
	//对前后两半部分进行判断 
	bool result=true;
	ListNode* p1=head; //p1表示前半部分的链表头部 
	ListNode* p2=prev; //p2表示后半部分的链表头部 
	while(p2!=NULL)
	{
		if(p1->val!=p2->val)
			result=false;
		p1=p1->next;
		p2=p2->next;
	}
	
	//还原链表 
	slow->next=reverseList(prev);
	
	return result;
}

ListNode* reverseList(ListNode* head)
{
	//使用迭代法
	ListNode* curr=head;
	ListNode* prev=NULL;
	while(curr!=NULL)
	{
		ListNode* next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
