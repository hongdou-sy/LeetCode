struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
	ListNode(int x,ListNode* next):val(x),next(next){}
};

//时间超67%%,空间超62% 
//使用迭代法依次往后确定head1和head2 
class Solution{
public:
	ListNode* sortList(ListNode* head)
	{
		if(head==NULL) //如果链表中无结点,直接返回 
			return head;
		
		//确定链表的结点个数length 
		int length=0;
		ListNode* node=head;
		while(node!=NULL)
		{
			length++;
			node=node->next;
		}
		
		//接下来每两个子链表一组进行合并,直到子链表长度subLength>=length
		ListNode* dummyNode=new ListNode(0,head); //添加哑结点
		//每次将链表合并完,subLength值加倍,对更长的有序子链表进行合并操作
		for(int subLength=1;subLength<length;subLength<<=1)
		{
			//每执行完一轮subLength,prev和curr重新指向链表头结点 
			ListNode* prev=dummyNode;
			ListNode* curr=dummyNode->next;
			//每两个长度为subLength的子链表作为一组进行合并,依次向后遍历链表完成多组合并 
			while(curr!=NULL)
			{
				//1.确定head1、head2的位置 
				ListNode* head1=curr; 
				//curr向后移动subLength-1个位置,找到head2的前驱结点 
				for(int i=1;i<subLength&&curr->next!=NULL;i++)
				{
					curr=curr->next;
				} 
				//如果head1链表结点个数不足subLength,head2就指向NULL,合并结果就是head1本身 
				ListNode* head2=curr->next;
				
				//2.确定下一组链表的head1结点的位置 
				curr->next=NULL; //断开head1和head2两部分链表,方便后续合并这两个链表
				curr=head2; //curr跳到head2位置,方便向后确定下一个head1的位置,并用temp存储起来 
				//curr向后移动subLength-1个位置 
				for(int i=1;i<subLength&&curr!=NULL&&curr->next!=NULL;i++)
				{
					curr=curr->next;
				} //此时curr指向该组最后一个结点 
				
				//新建指针temp,用于临时存储下一组head1的位置
				//不能写作 ListNode* temp=new ListNode(0,NULL); 会超时 
				ListNode* temp=NULL;
				if(curr!=NULL) //如果下一组链表存在,才能找到下一组head1 
				{
					temp=curr->next;//temp指向该组链表的下一个结点(也就是下组链表的第一个结点) 
					curr->next=NULL; //将两组链表分割开 
				} 
				
				//3.合并该组链表,并将合并后的链表添加到prev尾部 
				ListNode* merged=merge(head1,head2); //合并该组链表
				prev->next=merged; //将合并后的链表加入prev
				//prev继续指向链表的最后一个结点,方便下次插入(该链表的头结点为dummyNode) 
				while(prev->next!=NULL)
				{
					prev=prev->next;
				}
				
				curr=temp; //确定下一个head1 
			}
		} 
		return dummyNode->next;
	}
	
	ListNode* merge(ListNode* head1,ListNode* head2)
	{
		ListNode* dummyNode=new ListNode(0);
		ListNode* temp=dummyNode;
		ListNode* temp1=head1;
		ListNode* temp2=head2;
		while(temp1!=NULL&&temp2!=NULL)
		{
			if(temp1->val<temp2->val)
			{
				temp->next=temp1;
				temp1=temp1->next;
			}
			else
			{
				temp->next=temp2;
				temp2=temp2->next;
			}
			temp=temp->next;
		}
		temp->next=temp1!=NULL?temp1:temp2;
		return dummyNode->next;
	}
};
