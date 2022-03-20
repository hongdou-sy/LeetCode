struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//ʹ��˫ָ��˼��,����һ��ָ��pre������������,��¼�����ߵĲ���
//��ʹ��һ��ָ��now��ͷ��ʼǰ��,���pre�ߵĲ���nΪ����,��now�ߵĲ���Ӧ��Ϊn/2+1;
//���pre�ߵĲ���Ϊż��,��now�ߵĲ���Ӧ��Ϊn/2; 
ListNode* middleNode(ListNode* head)
{
	ListNode* cur=head;
	int n=0; //n��¼ָ��pre�ߵĲ���
	int m; //m��¼nowӦ���ߵĲ��� 
	
	cur=cur->next; //��pre��ָ����Ԫ��� 
	while(cur!=NULL)
	{
		cur=cur->next;
		n++;
	} 
	
	if(n%2==1)
		m=n/2+1;
	else
		m=n/2;
	
	cur=head;
	for(int i=0;i<m;i++)
	{
		cur=cur->next;
	}
	return cur;
} 

ListNode* middleNode(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
