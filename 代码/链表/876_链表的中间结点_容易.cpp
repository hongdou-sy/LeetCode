struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

//使用双指针思想,首先一个指针pre遍历整个链表,记录它的走的步数
//再使用一个指针now从头开始前进,如果pre走的步数n为奇数,则now走的步数应该为n/2+1;
//如果pre走的步数为偶数,则now走的步数应该为n/2; 
ListNode* middleNode(ListNode* head)
{
	ListNode* cur=head;
	int n=0; //n记录指针pre走的步数
	int m; //m记录now应该走的步数 
	
	cur=cur->next; //让pre先指向首元结点 
	while(cur!=NULL)
	{
		cur=cur->next;
		n++;
	} 
	
	if(n%2==1)
		m=n/2+1;
	else
		m=n/2;
	
	cur=head;
	for(int i=0;i<m;i++)
	{
		cur=cur->next;
	}
	return cur;
} 

ListNode* middleNode(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
