struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//������ 
//ʱ�����93%,�ռ����23% 
class Solution{
public:
	ListNode* deleteDuplicate(ListNode* head)
	{
		//��ʹ��һ��ָ��temp�����е���
		//ʹ��һ��ָ��prevʼ�ձ�������ǰ����� 
		ListNode* dummyNode=new ListNode(0,head);
		ListNode* temp=head;
		ListNode* prev=dummyNode; 
		while(temp!=NULL&&temp->next!=NULL)
		{
			if(temp->next->val!=temp->val)
			{
				temp=temp->next;
				prev=prev->next;
			}
			else
			{
				//���ظ��ĺ��Ԫ�ؾ�ɾ��(ע���ֹtemp->next==NULL,���Ҫ������ֹ����) 
				while(temp->next!=NULL&&temp->val==temp->next->val)
				{
					//��temp->nextɾ��
					ListNode* del=temp->next;
					temp->next=del->next;
					delete del; 
				}
				//���ɾ��temp����
				ListNode* del=temp;
				temp=del->next;
				prev->next=temp;
				delete del;
			}
		} 
		return dummyNode->next;
	}
};

//ʱ�����100%,�ռ����52% 
class Solution{
public:
	ListNode* deleteDuplicate(ListNode* head)
	{
		if(head==NULL||head->next==NULL)
			return head;
		if(head->next->val!=head->val)
		{
			head->next=deleteDuplicates(head->next);
		}
		else
		{
			ListNode* move=head->next;
			while(move!=NULL&&move->val==head->val)
			{
				move=move->next;
			}
			return deleteDuplicates(move);
		}
		return head;
	}
};
