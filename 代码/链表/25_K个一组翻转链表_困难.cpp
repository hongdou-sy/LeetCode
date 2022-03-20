struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//如果使用迭代法,满足只使用常数额外空间的要求
//该题是两个问题的结合:
//首先需要一个指针确定其后k个要翻转的结点
//其次翻转链表 
//每次循环共分为三个部分:已翻转链表、正在翻转链表、未翻转链表 
//时间击败84%,空间击败20% 
class Solution{
public:
	//从结点temp向后遍历k个结点,不会修改temp指向的结点 
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
		ListNode* dummyNode=new ListNode(0,head);//新建哑结点 
		ListNode* temp=dummyNode; //temp指针指向要翻转的k个结点的前一个结点
		ListNode* prev=new ListNode(); 
		ListNode* curr=new ListNode(); //prev指针和curr指针用于翻转链表
		while(moveK(temp,k)!=NULL) //不断翻转,直到temp后面的结点小于k个
		{
			ListNode* node=moveK(temp,k); //node表示temp向后遍历k个结点后指向的结点
			//将node后面的链表断开,方便翻转 
			ListNode* NextK=node->next; //先把下一轮的头结点存储起来,翻转完链表后再连上 
			node->next=NULL;
			
			//开始翻转k个结点 
			prev=temp;
			curr=temp->next;
			while(curr!=NULL)
			{
				ListNode* t=curr->next;
				curr->next=prev;
				prev=curr;
				curr=t;
			} //此时prev代表k个结点的头结点 
			
			temp->next=prev; //将已翻转链表和正在翻转链表连接起来 
			
			//prev向后移动k-1个结点
			for(int i=0;i<k-1;i++)
			{
				prev=prev->next;
			} 
			prev->next=NextK; //将正在翻转链表和未翻转链表连接起来 
			
			//temp指向此时的prev,也就是下一轮k个结点的前一个结点 
			temp=prev;
		} 
		return dummyNode->next;
	}
	
};
