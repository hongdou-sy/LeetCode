//(1)ֻҪĳ����㱻���ʹ�,���ý���val����1000000
//Ŀǰ���ʵĽ���valֵ�������1000000,˵���ý�㱻���ʹ��� 
//ʱ����92%,�ռ���62% 
//���ڵ�����:���ԭ������иĶ� 
bool hasCycle(ListNode* head)
{
	ListNode* temp=head; //��ʱhead->next������Ԫ��� 
	while(temp!=NULL)
	{
		temp=temp->next;
		if(temp->val>-1E5&&temp->val<=1E5)
		{
			temp->val+=1E6;
		}
		else if(temp->val>1E5)
			return true;
	}
	return false;
}

//(2)ʹ��hash���жϸý���ǰ�Ƿ񱻷��ʹ�
//ʱ����45%,�ռ���21% 
//֪ʶ��:unordered_set����
bool hasCycle(ListNode* head)
{
	unordered_set<ListNode*> hash;
	ListNode* temp=head;
	while(temp!=NULL)
	{
		if(hash.count(temp))
		{
			return true;
		}
		seen.insert(temp);
		temp=temp->next;
	}
	return false;
}

//(2)�������� ����ָ��
//ʱ����93%,�ռ���50% 
bool hasCycle(ListNode* head)
{
	//���������ʼ��λ�þ������ڽ��,˵���϶��޻� 
	if(head==NULL||head->next==NULL)
	{
		return false;
	}
	
	ListNode* slow=head;
	ListNode* fast=head->next; //��ʼ������ָ��,һ���ں�һ����ǰ 
	while(slow!=fast)
	{
		//������ڻ�,��ָ����Զ�����ܵ���ս�� 
		if(fast==NULL||fast->next==NULL) //�����ָ�����յ����˿ս�� 
		{
			return false;
		}
		slow=slow->next; //��ָ����һ�� 
		fast=fast->next->next; //��ָ��������
	}
	return false; 
} 


