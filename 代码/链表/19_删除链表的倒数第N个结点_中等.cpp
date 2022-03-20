struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//ʱ�����77%,�ռ����92% 
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		ListNode* temp=head;
		int L=0;
		while(temp!=NULL)
		{
			L++;
			temp=temp->next;
		}//�õ�������
		//���½��ƽ��dummy node
		ListNode* dummyNode=new ListNode();
		dummyNode->next=head;
		//��ʼ����ɾ������ǰ�����
		temp=dummyNode;
		for(int i=0;i<L-n;i++)
		{
			temp=temp->next;
		} 
		temp->next=temp->next->next; //ֱ��ɾ�����,���ͷŽ��ռ� 
		ListNode* ans=dummyNode->next;
		delete dummyNode; //�ͷ��½����ƽ��ռ� 
		return ans;
	}
};

//ʱ�����14%,�ռ����5% 
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		//�½��ƽ��
		ListNode* dummyNode=new ListNode(0,head);
		//����ջ
		stack<ListNode*> stk;
		//�����������η���ջ��
		ListNode* curr=dummyNode;
		while(curr!=NULL)
		{
			stk.push(curr);
			curr=curr->next;
		}
		//��ջ�����ε���n�����
		for(int i=0;i<n;i++)
		{
			stk.pop();
		} 
		//��ʱջ��Ԫ��ʱǰ�����
		ListNode* prev=stk.top();
		prev->next=prev->next->next;
		ListNode* ans=dummyNode->next;
		delete dummyNode;
		return ans; 
	}
};

//ʱ����77%,�ռ���56% 
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		//���½��ƽ��
		ListNode* dummyNode=new ListNode(0,head);
		ListNode* first=head;
		ListNode* second=dummyNode;
		//��first����n��
		for(int i=0;i<n;i++)
		{
			first=first->next;
		} 
		//����������ָ��һ����
		while(first!=NULL)
		{
			first=first->next;
			second=second->next;
		} 
		second->next=second->next->next;
		ListNode* ans=dummyNode->next;
		delete dummyNode;
		return ans;
	}
};

class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		ListNode h=head;
        List<ListNode> list=new ArrayList<>();
        while(h!=null){
            list.add(h);
            h=h.next;
        }
        list.add(null);//��ֹԽ��
        if(n==list.size()-1){return head.next;}
        list.get(list.size()-n-2).next=list.get(list.size()-n);
        return head;
	}
};
