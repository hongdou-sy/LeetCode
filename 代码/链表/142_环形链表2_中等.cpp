
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL);
}; 


//既然返回的是结点,同样使用unordered-SET容器来存储访问过的结点
//空间复杂度较高,应该新建了hash表,为O(n) 
ListNode* detectCycle(ListNode* head)
{
	unordered_set<ListNode*> hash;
	ListNode* temp=head;
	
	while(temp!=NULL)
	{
		if(hash.count(temp)) //如果哈希表中有此结点
		{
			return temp;
		}
		hash.insert(temp); //哈希表中如果没有当前结点,则将此节点加入哈希表
		temp=temp->next; 
	}
	return NULL;
}

//快慢指针
//时间打败98%,空间打败98% 
ListNode* detectCycle(ListNode* head)
{
	ListNode* fast=head;
	ListNode* slow=head;
	
	//先构建第一次相遇
	while(true) //为什么不能直接while(fast!=slow)?因为fast和slow初始化都是head,就进不了循环了 
	{
		if(fast==NULL||fast->next==NULL)//因为fast每次走两步,所以fast和fast->next都要考虑 
			return NULL;
		fast=fast->next->next;
		slow=slow->next; 
		if(fast==slow) break;
	} 
	//出了循环说明两指针第一次相遇了
	
	//开始构建第二次相遇 
	fast=head;
	while(fast!=slow)
	{
		fast=fast->next;
		slow=slow->next;
	}
	//出了循环说明两指针第二次相遇了 
	return fast; //也可以return slow 
}
