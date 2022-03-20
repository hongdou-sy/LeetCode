//�ռ���37%,ʱ����55% 
bool isPalindrome(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	//��ָ��fast�ߵ�����β��ʱ,��ָ��slow�պ��ߵ�ǰ�벿�ֵ�β��� 
	while(fast->next!=NULL&&fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	} 
	
	ListNode* prev=reverseList(slow->next); //���ط�ת֮��ĺ�벿������ 
	
	//��ʱprev��ʾ��ת֮��ĺ�벿��
	//��ǰ�����벿�ֽ����ж� 
	bool result=true;
	ListNode* p1=head; //p1��ʾǰ�벿�ֵ�����ͷ�� 
	ListNode* p2=prev; //p2��ʾ��벿�ֵ�����ͷ�� 
	while(p2!=NULL)
	{
		if(p1->val!=p2->val)
			result=false;
		p1=p1->next;
		p2=p2->next;
	}
	
	//��ԭ���� 
	slow->next=reverseList(prev);
	
	return result;
}

ListNode* reverseList(ListNode* head)
{
	//ʹ�õ�����
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
