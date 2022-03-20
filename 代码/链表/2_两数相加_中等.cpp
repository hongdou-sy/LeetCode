//(1)官方解答,没有引入头结点的情况(时间击败63%,空间击败90%) 
class Solution{
	public:
		//本方法使用新链表存储【结果】 
		ListNode* addTwoNumber(ListNode* l1,ListNode* l2)
		{
			//新建一个链表作为【结果链表】 
			ListNode* head=NULL; //【结果链表】的头指针head 
			ListNode* tail=NULL; //【结果链表】的尾指针tail 
			int carry=0;
			while(l1||l2) //只要两个链表都没有到达null结点,l1->val和l2->val为当前的两个操作数 
			//不能是while(l1->next||l2->next),因为l1和l2没有引入头结点,l1和l2本身就指向第一个操作数 
			{
                int n1,n2;//获取当前两个加数n1和n2 
				if(l1) //如果l1没到达尾结点 
				{
					n1=l1->val;
				}
				else //如果l1到达了尾结点 
				{
					n1=0;
				}
				if(l2) //如果l2没到达尾结点
				{
					n2=l2->val;
				}
				else //如果l2到达了尾结点 
				{
					n2=0;
				}
				//以上代码可写作下面两行
				//int n1=l1?l1->val:0;
				//int n2=l2?l2->val:0; 
				
				//开始计算每个结点,将计算下来的结果放入【结果链表】 
				int sum=n1+n2+carry; //当前两个加数加上上一轮循环的进位 
				if(!head) //如果【结果链表】里面还没有结点,即head==null 
				{
					head=tail=new ListNode(sum%10); //头结点和尾结点就指向我们新建的这个结点 
				} 
				else //如果【结果链表】里面已经有结点了,即head!=null 
				{
					//向尾结点后面插入新结点 
					tail->next=new ListNode(sum%10);  
					tail=tail->next; //tail始终指向尾结点
					//head头结点就不再变化了 
				}
				carry=sum/10;
				
				if(l1) //如果l1还没到达尾结点 
				{
					l1=l1->next; //继续获取l1的后一个结点 
				}
				if(l2) //如果l2还没到达尾结点 
				{
					l2=l2->next; //继续获取l2的后一个结点 
				}
			}
			if(carry>0) //如果计算完l1和l2的最后两个加数后还有进位
			{
				tail->next=new ListNode(carry);
			} 
			return head;
		}
};

//(2)官方解答,引入头结点的情况(时间击败80%,空间击败49%) 
class Solution{
	public:
		ListNode* addTwoNumber(ListNode* l1,ListNode* l2)
		{
			//新建一个链表作为【结果链表】 
			//类似于双指针,head始终不动,tail负责向尾部插入新结点 
			ListNode* head=new ListNode(-1);//head->next才是【结果链表】的真正的头指针
			ListNode* tail=head; //tail为尾指针,表示当前移动的指针
			int carry=0;
			
			while(l1||l2||carry) //把carry放在这里判断,可以减少时间 
			{
				int n1=l1?l1->val:0;
				int n2=l2?l2->val:0;//获取当前两个操作数n1和n2
				
				ListNode* node=new ListNode((n1+n2+carry)%10); //新建新的结果结点 
				tail->next=node; //插入下一个结点
				tail=tail->next;//tail始终指向尾结点 
				
				l1=l1?l1->next:NULL;
				l2=l2?l2->next:NULL; //获取l1和l2下一个操作数 
				carry=(n1+n2+carry)/10;
			} 
//			if(carry>0)
//			{
//				ListNode* node=new ListNode(carry);
//				tail->next=node;
//			} 
			return head->next;
		}
}; 

//(3)直接在原链表上操作,不需要创建新链表作为结果链表(时间击败80%,空间击败92%) 
//首先计算l1和l2等长部分的和,然后多出来的部分就不用操作了,直接返回较长的那个链表 
//注意这里用了三层嵌套,编码不太规范 
class Solution{
	public ListNode addTwoNumber(ListNode l1,ListNode l2)
	{
		ListNode* s1=l1;
		ListNode* s2=l2; //在l1和l2原链表上进行操作 
		//对l1和l2等长的部分进行add 
		while(s1!=NULL && s2!=NULL) 
		{
			if(s1->val+s2->val>=10)
			{
				if(s1->next==NULL) //l1长度<l2长度 
					s1->next=new ListNode(1); //为s1向后添加结点 
				else if(s2->next==NULL) //l1长度>l2长度 
					s2->next=new ListNode(1); //为s2向后添加结点 
				else //两者都未到达尾端结点 
					s1->next->val+=1; //为后一个结点添加进位 
			}
			s1->val=(s1->val+s2->val)%10;
			s2->val=s1->val; //不能省略,两个链表都要修改,因为我们不知道哪个链表更长,最后返回的是更长的那个链表,所以要把两个链表都修改了 
			s1=s1->next;
			s2=s2->next;
		}
		
		//返回较长的链表 
		if(s1==NULL) //如果s1先到达NULL 
		{
			return l2;
		}
		else //如果s2先到达NULL
		{
			return l1;
		} 
	}
};
