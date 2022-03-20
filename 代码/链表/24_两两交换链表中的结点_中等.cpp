 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//����Ҫ�������������,����ɾ��ǰ��Ľ��1,�ٽ�ɾ������������ں�̽��2�ĺ���
//�����Ҫһ��ָ��ָ����1��ǰ�����
//ʱ�����50%,�ռ����97% 
class Solution{
public:
	ListNode* swapPairs(ListNode* head)
	{
		//��Ҫ�½�һ���ƽ��,����ͷ����ɾ�� 
		//ʹ��һ��ָ��pre,��ʼʱָ���ƽ��,ÿ������һ��,preָ������ƶ�����,��֤ÿ�ζ�ָ��Ҫ�������������ǰ�����
		
		ListNode* dummyNode=new ListNode(0,head);//�½��ƽ��
		ListNode* pre=dummyNode; //��ʼ��pre��� 
		
		while(pre->next!=NULL||pre->next->next!=NULL)
		{
			//�ѽ��1ժ��ȥ 
			ListNode* temp=pre->next;
			pre->next=temp->next;
			
			//�ѽ��1������2�ĺ���
			temp->next=pre->next->next;
			pre->next->next=temp;
			
			pre=pre->next->next;
			
			//�ڶ���д�� 
//			ListNode* node1=pre->next;
//			ListNode* node2=pre->next->next;
//			pre->next=node2;
//			node1->next=node2->next;
//			node2->next=node1
//			
//			pre=node1;
		}
		
		return dummyNode->next;
	}
}; 

//�ݹ�˼· 
//ʱ�����100%,�ռ����73% 
class Solution{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if(head==NULL||head->next==NULL) //�ݹ���ֹ����:�޽������һ����� 
			return head;
		
		ListNode* node=head->next;
		//һֱ���µݹ�,ֱ��û�н���ֻʣһ�����Ϳ�ʼ����(���Ϸ���) 
		head->next=swapPairs(node->next); //head->next����node�����Ѿ������õ����� 
		node->next=head; //node������head 
		return node;
	}
}; 

