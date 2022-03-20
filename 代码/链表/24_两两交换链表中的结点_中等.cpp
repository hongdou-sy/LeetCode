 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//对于要交换的两个结点,首先删除前面的结点1,再将删除的这个结点放在后继结点2的后面
//因此需要一个指针指向结点1的前驱结点
//时间击败50%,空间击败97% 
class Solution{
public:
	ListNode* swapPairs(ListNode* head)
	{
		//需要新建一个哑结点,方便头结点的删除 
		//使用一个指针pre,初始时指向哑结点,每交换完一次,pre指针向后移动两步,保证每次都指向要交换的那组结点的前驱结点
		
		ListNode* dummyNode=new ListNode(0,head);//新建哑结点
		ListNode* pre=dummyNode; //初始化pre结点 
		
		while(pre->next!=NULL||pre->next->next!=NULL)
		{
			//把结点1摘出去 
			ListNode* temp=pre->next;
			pre->next=temp->next;
			
			//把结点1插入结点2的后面
			temp->next=pre->next->next;
			pre->next->next=temp;
			
			pre=pre->next->next;
			
			//第二种写法 
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

//递归思路 
//时间击败100%,空间击败73% 
class Solution{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if(head==NULL||head->next==NULL) //递归终止条件:无结点或仅有一个结点 
			return head;
		
		ListNode* node=head->next;
		//一直向下递归,直到没有结点或只剩一个结点就开始回溯(向上反弹) 
		head->next=swapPairs(node->next); //head->next连上node后面已经交换好的链表 
		node->next=head; //node再连上head 
		return node;
	}
}; 

