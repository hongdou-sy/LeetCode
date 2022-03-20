struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* next):val(x),next(next){}
};

//ʱ�䳬67%%,�ռ䳬62% 
//ʹ�õ�������������ȷ��head1��head2 
class Solution{
public:
	ListNode* sortList(ListNode* head)
	{
		if(head==NULL) //����������޽��,ֱ�ӷ��� 
			return head;
		
		//ȷ������Ľ�����length 
		int length=0;
		ListNode* node=head;
		while(node!=NULL)
		{
			length++;
			node=node->next;
		}
		
		//������ÿ����������һ����кϲ�,ֱ����������subLength>=length
		ListNode* dummyNode=new ListNode(0,head); //����ƽ��
		//ÿ�ν�����ϲ���,subLengthֵ�ӱ�,�Ը�����������������кϲ�����
		for(int subLength=1;subLength<length;subLength<<=1)
		{
			//ÿִ����һ��subLength,prev��curr����ָ������ͷ��� 
			ListNode* prev=dummyNode;
			ListNode* curr=dummyNode->next;
			//ÿ��������ΪsubLength����������Ϊһ����кϲ�,����������������ɶ���ϲ� 
			while(curr!=NULL)
			{
				//1.ȷ��head1��head2��λ�� 
				ListNode* head1=curr; 
				//curr����ƶ�subLength-1��λ��,�ҵ�head2��ǰ����� 
				for(int i=1;i<subLength&&curr->next!=NULL;i++)
				{
					curr=curr->next;
				} 
				//���head1�������������subLength,head2��ָ��NULL,�ϲ��������head1���� 
				ListNode* head2=curr->next;
				
				//2.ȷ����һ�������head1����λ�� 
				curr->next=NULL; //�Ͽ�head1��head2����������,��������ϲ�����������
				curr=head2; //curr����head2λ��,�������ȷ����һ��head1��λ��,����temp�洢���� 
				//curr����ƶ�subLength-1��λ�� 
				for(int i=1;i<subLength&&curr!=NULL&&curr->next!=NULL;i++)
				{
					curr=curr->next;
				} //��ʱcurrָ��������һ����� 
				
				//�½�ָ��temp,������ʱ�洢��һ��head1��λ��
				//����д�� ListNode* temp=new ListNode(0,NULL); �ᳬʱ 
				ListNode* temp=NULL;
				if(curr!=NULL) //�����һ���������,�����ҵ���һ��head1 
				{
					temp=curr->next;//tempָ������������һ�����(Ҳ������������ĵ�һ�����) 
					curr->next=NULL; //����������ָ 
				} 
				
				//3.�ϲ���������,�����ϲ����������ӵ�prevβ�� 
				ListNode* merged=merge(head1,head2); //�ϲ���������
				prev->next=merged; //���ϲ�����������prev
				//prev����ָ����������һ�����,�����´β���(�������ͷ���ΪdummyNode) 
				while(prev->next!=NULL)
				{
					prev=prev->next;
				}
				
				curr=temp; //ȷ����һ��head1 
			}
		} 
		return dummyNode->next;
	}
	
	ListNode* merge(ListNode* head1,ListNode* head2)
	{
		ListNode* dummyNode=new ListNode(0);
		ListNode* temp=dummyNode;
		ListNode* temp1=head1;
		ListNode* temp2=head2;
		while(temp1!=NULL&&temp2!=NULL)
		{
			if(temp1->val<temp2->val)
			{
				temp->next=temp1;
				temp1=temp1->next;
			}
			else
			{
				temp->next=temp2;
				temp2=temp2->next;
			}
			temp=temp->next;
		}
		temp->next=temp1!=NULL?temp1:temp2;
		return dummyNode->next;
	}
};
