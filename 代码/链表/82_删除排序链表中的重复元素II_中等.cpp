struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//迭代法 
//时间击败93%,空间击败23% 
class Solution{
public:
	ListNode* deleteDuplicate(ListNode* head)
	{
		//仅使用一个指针temp来进行迭代
		//使用一个指针prev始终保存它的前驱结点 
		ListNode* dummyNode=new ListNode(0,head);
		ListNode* temp=head;
		ListNode* prev=dummyNode; 
		while(temp!=NULL&&temp->next!=NULL)
		{
			if(temp->next->val!=temp->val)
			{
				temp=temp->next;
				prev=prev->next;
			}
			else
			{
				//将重复的后继元素均删除(注意防止temp->next==NULL,因此要加上终止条件) 
				while(temp->next!=NULL&&temp->val==temp->next->val)
				{
					//将temp->next删除
					ListNode* del=temp->next;
					temp->next=del->next;
					delete del; 
				}
				//最后删除temp自身
				ListNode* del=temp;
				temp=del->next;
				prev->next=temp;
				delete del;
			}
		} 
		return dummyNode->next;
	}
};

//时间击败100%,空间击败52% 
class Solution{
public:
	ListNode* deleteDuplicate(ListNode* head)
	{
		if(head==NULL||head->next==NULL)
			return head;
		if(head->next->val!=head->val)
		{
			head->next=deleteDuplicates(head->next);
		}
		else
		{
			ListNode* move=head->next;
			while(move!=NULL&&move->val==head->val)
			{
				move=move->next;
			}
			return deleteDuplicates(move);
		}
		return head;
	}
};
