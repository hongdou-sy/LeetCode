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
	ListNode* ans=new ListNode(0); //��������ans��ʱ�洢������
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
	//�ٽ��ϲ�����������ν�����leftΪͷ�ڵ������ 
	ListNode* t=ans->next;
	left=t; //�Ƚ�ͷ��㸳��left 
	t=t->next;
	while(t!=NULL)
	{
		left->next=t;
		t=t->next;
	}//��ʱleft��ʼ[left,right+subLength-1]���Ǻϲ�֮������� 
}

ListNode* sortList(ListNode* head)
{
	while(head==NULL)
		return NULL;
	//ȷ��������
	ListNode* temp=head;
	int length=0;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;
	} 
	//����һ���ƽ�� 
	ListNode* dummyNode=new ListNode(0,head);
	temp=dummyNode;
	int subLength=1; //�ӳ���Ϊ1��������ʼ���� 
	//ֱ��������ĳ��ȴ���ԭ����ĳ���,�Ͳ��ٽ��кϲ� 
	while(subLength<length) 
	{
		while(temp!=NULL)
		{
			//�ڽ��кϲ���ʱ��,ֻ��Ҫ֪��ͷ��������е㼴�� 
			ListNode* left=temp->next;
			for(int i=0;i<subLength-1;i++)
			{
				temp=temp->next;
			}//��ʱtempָ��left��ʼ��ǰ�벿�ֵ����һ����� 
			//�����left��ʼʣ�µĽ�㲻��subLength��,�Ͳ��ٽ��кϲ� 
			if(temp==NULL)
				break;
			ListNode* right=temp->next;
			merge(left,right);
		}
		subLength*=2;
	}
} 
