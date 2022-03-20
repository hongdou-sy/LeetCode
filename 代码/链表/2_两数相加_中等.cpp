//(1)�ٷ����,û������ͷ�������(ʱ�����63%,�ռ����90%) 
class Solution{
	public:
		//������ʹ��������洢������� 
		ListNode* addTwoNumber(ListNode* l1,ListNode* l2)
		{
			//�½�һ��������Ϊ��������� 
			ListNode* head=NULL; //�����������ͷָ��head 
			ListNode* tail=NULL; //�����������βָ��tail 
			int carry=0;
			while(l1||l2) //ֻҪ��������û�е���null���,l1->val��l2->valΪ��ǰ������������ 
			//������while(l1->next||l2->next),��Ϊl1��l2û������ͷ���,l1��l2�����ָ���һ�������� 
			{
                int n1,n2;//��ȡ��ǰ��������n1��n2 
				if(l1) //���l1û����β��� 
				{
					n1=l1->val;
				}
				else //���l1������β��� 
				{
					n1=0;
				}
				if(l2) //���l2û����β���
				{
					n2=l2->val;
				}
				else //���l2������β��� 
				{
					n2=0;
				}
				//���ϴ����д����������
				//int n1=l1?l1->val:0;
				//int n2=l2?l2->val:0; 
				
				//��ʼ����ÿ�����,�����������Ľ�����롾������� 
				int sum=n1+n2+carry; //��ǰ��������������һ��ѭ���Ľ�λ 
				if(!head) //���������������滹û�н��,��head==null 
				{
					head=tail=new ListNode(sum%10); //ͷ����β����ָ�������½��������� 
				} 
				else //�����������������Ѿ��н����,��head!=null 
				{
					//��β����������½�� 
					tail->next=new ListNode(sum%10);  
					tail=tail->next; //tailʼ��ָ��β���
					//headͷ���Ͳ��ٱ仯�� 
				}
				carry=sum/10;
				
				if(l1) //���l1��û����β��� 
				{
					l1=l1->next; //������ȡl1�ĺ�һ����� 
				}
				if(l2) //���l2��û����β��� 
				{
					l2=l2->next; //������ȡl2�ĺ�һ����� 
				}
			}
			if(carry>0) //���������l1��l2����������������н�λ
			{
				tail->next=new ListNode(carry);
			} 
			return head;
		}
};

//(2)�ٷ����,����ͷ�������(ʱ�����80%,�ռ����49%) 
class Solution{
	public:
		ListNode* addTwoNumber(ListNode* l1,ListNode* l2)
		{
			//�½�һ��������Ϊ��������� 
			//������˫ָ��,headʼ�ղ���,tail������β�������½�� 
			ListNode* head=new ListNode(-1);//head->next���ǡ����������������ͷָ��
			ListNode* tail=head; //tailΪβָ��,��ʾ��ǰ�ƶ���ָ��
			int carry=0;
			
			while(l1||l2||carry) //��carry���������ж�,���Լ���ʱ�� 
			{
				int n1=l1?l1->val:0;
				int n2=l2?l2->val:0;//��ȡ��ǰ����������n1��n2
				
				ListNode* node=new ListNode((n1+n2+carry)%10); //�½��µĽ����� 
				tail->next=node; //������һ�����
				tail=tail->next;//tailʼ��ָ��β��� 
				
				l1=l1?l1->next:NULL;
				l2=l2?l2->next:NULL; //��ȡl1��l2��һ�������� 
				carry=(n1+n2+carry)/10;
			} 
//			if(carry>0)
//			{
//				ListNode* node=new ListNode(carry);
//				tail->next=node;
//			} 
			return head->next;
		}
}; 

//(3)ֱ����ԭ�����ϲ���,����Ҫ������������Ϊ�������(ʱ�����80%,�ռ����92%) 
//���ȼ���l1��l2�ȳ����ֵĺ�,Ȼ�������Ĳ��־Ͳ��ò�����,ֱ�ӷ��ؽϳ����Ǹ����� 
//ע��������������Ƕ��,���벻̫�淶 
class Solution{
	public ListNode addTwoNumber(ListNode l1,ListNode l2)
	{
		ListNode* s1=l1;
		ListNode* s2=l2; //��l1��l2ԭ�����Ͻ��в��� 
		//��l1��l2�ȳ��Ĳ��ֽ���add 
		while(s1!=NULL && s2!=NULL) 
		{
			if(s1->val+s2->val>=10)
			{
				if(s1->next==NULL) //l1����<l2���� 
					s1->next=new ListNode(1); //Ϊs1�����ӽ�� 
				else if(s2->next==NULL) //l1����>l2���� 
					s2->next=new ListNode(1); //Ϊs2�����ӽ�� 
				else //���߶�δ����β�˽�� 
					s1->next->val+=1; //Ϊ��һ�������ӽ�λ 
			}
			s1->val=(s1->val+s2->val)%10;
			s2->val=s1->val; //����ʡ��,��������Ҫ�޸�,��Ϊ���ǲ�֪���ĸ��������,��󷵻ص��Ǹ������Ǹ�����,����Ҫ�����������޸��� 
			s1=s1->next;
			s2=s2->next;
		}
		
		//���ؽϳ������� 
		if(s1==NULL) //���s1�ȵ���NULL 
		{
			return l2;
		}
		else //���s2�ȵ���NULL
		{
			return l1;
		} 
	}
};
