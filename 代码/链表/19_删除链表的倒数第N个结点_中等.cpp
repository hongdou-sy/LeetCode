struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//时间击败77%,空间击败92% 
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
		}//得到链表长度
		//先新建哑结点dummy node
		ListNode* dummyNode=new ListNode();
		dummyNode->next=head;
		//开始查找删除结点的前驱结点
		temp=dummyNode;
		for(int i=0;i<L-n;i++)
		{
			temp=temp->next;
		} 
		temp->next=temp->next->next; //直接删除结点,不释放结点空间 
		ListNode* ans=dummyNode->next;
		delete dummyNode; //释放新建的哑结点空间 
		return ans;
	}
};

//时间击败14%,空间击败5% 
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		//新建哑结点
		ListNode* dummyNode=new ListNode(0,head);
		//创建栈
		stack<ListNode*> stk;
		//把链表结点依次放入栈中
		ListNode* curr=dummyNode;
		while(curr!=NULL)
		{
			stk.push(curr);
			curr=curr->next;
		}
		//从栈中依次弹出n个结点
		for(int i=0;i<n;i++)
		{
			stk.pop();
		} 
		//此时栈顶元素时前驱结点
		ListNode* prev=stk.top();
		prev->next=prev->next->next;
		ListNode* ans=dummyNode->next;
		delete dummyNode;
		return ans; 
	}
};

//时间打败77%,空间打败56% 
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n)
	{
		//先新建哑结点
		ListNode* dummyNode=new ListNode(0,head);
		ListNode* first=head;
		ListNode* second=dummyNode;
		//让first先行n步
		for(int i=0;i<n;i++)
		{
			first=first->next;
		} 
		//接下来两个指针一起走
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
        list.add(null);//防止越界
        if(n==list.size()-1){return head.next;}
        list.get(list.size()-n-2).next=list.get(list.size()-n);
        return head;
	}
};
