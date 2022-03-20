struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

//时间打败90%,空间打败44% 
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
	ListNode* p1=headA;
	ListNode* p2=headB;
	//p1先走链表A,走完链表A再去走链表B
	//p2先走链表B,走完链表B再去走链表A
	while(p1!=NULL||p2!=NULL) //如果p1和p2同时指向了尾结点null,说明不存在相交节点 
	{
		if(p1==NULL) //如果p1遍历完了链表A 
			p1=headB;
		if(p2==NULL) //如果p2遍历完了链表B 
			p2=headA;
		if(p1==p2) 
			return p1;
		p1=p1->next;
		p2=p2->next;
	} 
	return NULL;
}

//优化代码
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
	ListNode *p1=headA,*p2=headB;
	//如果没有相交结点,两个指针一起指向NULL结点,最后也直接返回NULL
	//如果有相交结点,返回相交结点 
	while(p1!=p2)
	{
		p1= p1!=NULL ?p1->next:headB;
		p2= p2!=NULL ?p2->next:headA;
	} 
	return p1;
} 

