struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* next):val(x),next(next){}
};

//ʱ�����38%,�ռ����14% 
class Solution{
public:
	//����headΪͷ���������������,�����ź��������ͷ���
	//startΪ��ʼ���������Χͷ��� 
	ListNode* sortList(ListNode* head)  
	{
		if(head==NULL||head->next==NULL)
		{
			return head; //��ʱֻ��һ�������,ֱ�ӷ��ش˽ڵ� 
		}
		//ʹ�ÿ���ָ���ҵ��е�,�����ż������,�ҵ�������ߵĽ��
		ListNode* fast=head->next ;
		ListNode* slow=head;
		while(fast!=NULL&&fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		} //��ʱslowָ���е� 
		
		ListNode* temp=slow->next; //tempָ���벿�ֵ�һ�����
		slow->next=NULL; //��������е�Ͽ�
		ListNode* left=sortList(head);
		ListNode* right=sortList(temp);
		ListNode* h=new ListNode(0); //�½����h�洢�ϲ��������
		ListNode* res=h; //res����������ս��
		
		//�ϲ���������left��right 
		while(left!=NULL&&right!=NULL)
		{
			if(left->val<right->val)
			{
				h->next=left;
				left=left->next;
			}
			else
			{
				h->next=right;
				right=right->next;
			}
			h=h->next;
		 } 
		 h->next=left!=NULL?left:right;
		 return res->next;
	}
};
