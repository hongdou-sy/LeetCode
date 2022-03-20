struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//把链表放入数组中,然后判断数组是不是回文链表 
bool isPalindrome(ListNode* head)
{
	int a[100005];
	ListNode* cur=head;
	int num=0; //num存储链表中的结点数目 
	while(cur!=NULL)
	{
		a[num]=cur->val;
		cur=cur->next;
		num++;
	}
	
	for(int i=0;i<num/2;i++)
	{
		if(a[i]!=a[num-1-i])
		{
			return false;
		}
	}
	return true;
}

bool isPalindrome(ListNode* head)
{
	vector<int> a;
	ListNode* cur=head;
	int num=0;
	while(cur!=NULL)
	{
		a.push_back(cur->val);
		cur=cur->next;
		num++;
	}
	
	int i=0; //i指向数组首部 
	int j=num-1; //j指向数组尾部
	for(;i<j;i++,j--)
	{
		if(a[i]!=a[j])
			return false;
	} 
	return true;
}

//使用双指针
//链表无法去找它的前驱结点怎么办？ 
bool isPalindrome(ListNode* head)
{
	
} 
