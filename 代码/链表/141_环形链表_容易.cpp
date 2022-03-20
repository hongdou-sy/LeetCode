//(1)只要某个结点被访问过,将该结点的val加上1000000
//目前访问的结点的val值如果大于1000000,说明该结点被访问过了 
//时间打败92%,空间打败62% 
//存在的问题:会对原链表进行改动 
bool hasCycle(ListNode* head)
{
	ListNode* temp=head; //此时head->next才是首元结点 
	while(temp!=NULL)
	{
		temp=temp->next;
		if(temp->val>-1E5&&temp->val<=1E5)
		{
			temp->val+=1E6;
		}
		else if(temp->val>1E5)
			return true;
	}
	return false;
}

//(2)使用hash表判断该结点此前是否被访问过
//时间打败45%,空间打败21% 
//知识点:unordered_set容器
bool hasCycle(ListNode* head)
{
	unordered_set<ListNode*> hash;
	ListNode* temp=head;
	while(temp!=NULL)
	{
		if(hash.count(temp))
		{
			return true;
		}
		seen.insert(temp);
		temp=temp->next;
	}
	return false;
}

//(2)龟兔赛跑 快慢指针
//时间打败93%,空间打败50% 
bool hasCycle(ListNode* head)
{
	//如果两个初始化位置均不存在结点,说明肯定无环 
	if(head==NULL||head->next==NULL)
	{
		return false;
	}
	
	ListNode* slow=head;
	ListNode* fast=head->next; //初始化快慢指针,一个在后一个在前 
	while(slow!=fast)
	{
		//如果存在环,快指针永远不可能到达空结点 
		if(fast==NULL||fast->next==NULL) //如果快指针最终到达了空结点 
		{
			return false;
		}
		slow=slow->next; //慢指针走一步 
		fast=fast->next->next; //快指针走两步
	}
	return false; 
} 


