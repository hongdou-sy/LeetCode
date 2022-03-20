struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

//ʱ����90%,�ռ���44% 
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
	ListNode* p1=headA;
	ListNode* p2=headB;
	//p1��������A,��������A��ȥ������B
	//p2��������B,��������B��ȥ������A
	while(p1!=NULL||p2!=NULL) //���p1��p2ͬʱָ����β���null,˵���������ཻ�ڵ� 
	{
		if(p1==NULL) //���p1������������A 
			p1=headB;
		if(p2==NULL) //���p2������������B 
			p2=headA;
		if(p1==p2) 
			return p1;
		p1=p1->next;
		p2=p2->next;
	} 
	return NULL;
}

//�Ż�����
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
	ListNode *p1=headA,*p2=headB;
	//���û���ཻ���,����ָ��һ��ָ��NULL���,���Ҳֱ�ӷ���NULL
	//������ཻ���,�����ཻ��� 
	while(p1!=p2)
	{
		p1= p1!=NULL ?p1->next:headB;
		p2= p2!=NULL ?p2->next:headA;
	} 
	return p1;
} 

