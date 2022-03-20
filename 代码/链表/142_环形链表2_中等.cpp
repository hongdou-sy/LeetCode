
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL);
}; 


//��Ȼ���ص��ǽ��,ͬ��ʹ��unordered-SET�������洢���ʹ��Ľ��
//�ռ临�ӶȽϸ�,Ӧ���½���hash��,ΪO(n) 
ListNode* detectCycle(ListNode* head)
{
	unordered_set<ListNode*> hash;
	ListNode* temp=head;
	
	while(temp!=NULL)
	{
		if(hash.count(temp)) //�����ϣ�����д˽��
		{
			return temp;
		}
		hash.insert(temp); //��ϣ�������û�е�ǰ���,�򽫴˽ڵ�����ϣ��
		temp=temp->next; 
	}
	return NULL;
}

//����ָ��
//ʱ����98%,�ռ���98% 
ListNode* detectCycle(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	
	//�ȹ�����һ������
	while(true) //Ϊʲô����ֱ��while(fast!=slow)?��Ϊfast��slow��ʼ������head,�ͽ�����ѭ���� 
	{
		if(fast==NULL||fast->next==NULL)//��Ϊfastÿ��������,����fast��fast->next��Ҫ���� 
			return NULL;
		fast=fast->next->next;
		slow=slow->next; 
		if(fast==slow) break;
	} 
	//����ѭ��˵����ָ���һ��������
	
	//��ʼ�����ڶ������� 
	fast=head;
	while(fast!=slow)
	{
		fast=fast->next;
		slow=slow->next;
	}
	//����ѭ��˵����ָ��ڶ��������� 
	return fast; //Ҳ����return slow 
}
