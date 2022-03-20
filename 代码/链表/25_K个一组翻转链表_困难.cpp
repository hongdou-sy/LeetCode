struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//���ʹ�õ�����,����ֻʹ�ó�������ռ��Ҫ��
//��������������Ľ��:
//������Ҫһ��ָ��ȷ�����k��Ҫ��ת�Ľ��
//��η�ת���� 
//ÿ��ѭ������Ϊ��������:�ѷ�ת�������ڷ�ת����δ��ת���� 
//ʱ�����84%,�ռ����20% 
class Solution{
public:
	//�ӽ��temp������k�����,�����޸�tempָ��Ľ�� 
	ListNode* moveK(ListNode* temp,int k)
	{
		ListNode* Node=temp;
		for(int i=0;i<k&&Node!=NULL;i++)
		{
			Node=Node->next;
		}
		if(Node==NULL)
			return NULL;
		else
			return Node;
	}
	
	ListNode* reverseKGroup(ListNode* head,int k)
	{
		ListNode* dummyNode=new ListNode(0,head);//�½��ƽ�� 
		ListNode* temp=dummyNode; //tempָ��ָ��Ҫ��ת��k������ǰһ�����
		ListNode* prev=new ListNode(); 
		ListNode* curr=new ListNode(); //prevָ���currָ�����ڷ�ת����
		while(moveK(temp,k)!=NULL) //���Ϸ�ת,ֱ��temp����Ľ��С��k��
		{
			ListNode* node=moveK(temp,k); //node��ʾtemp������k������ָ��Ľ��
			//��node���������Ͽ�,���㷭ת 
			ListNode* NextK=node->next; //�Ȱ���һ�ֵ�ͷ���洢����,��ת������������� 
			node->next=NULL;
			
			//��ʼ��תk����� 
			prev=temp;
			curr=temp->next;
			while(curr!=NULL)
			{
				ListNode* t=curr->next;
				curr->next=prev;
				prev=curr;
				curr=t;
			} //��ʱprev����k������ͷ��� 
			
			temp->next=prev; //���ѷ�ת��������ڷ�ת������������ 
			
			//prev����ƶ�k-1�����
			for(int i=0;i<k-1;i++)
			{
				prev=prev->next;
			} 
			prev->next=NextK; //�����ڷ�ת�����δ��ת������������ 
			
			//tempָ���ʱ��prev,Ҳ������һ��k������ǰһ����� 
			temp=prev;
		} 
		return dummyNode->next;
	}
	
};
