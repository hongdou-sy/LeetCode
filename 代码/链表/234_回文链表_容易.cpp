struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//���������������,Ȼ���ж������ǲ��ǻ������� 
bool isPalindrome(ListNode* head)
{
	int a[100005];
	ListNode* cur=head;
	int num=0; //num�洢�����еĽ����Ŀ 
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
	
	int i=0; //iָ�������ײ� 
	int j=num-1; //jָ������β��
	for(;i<j;i++,j--)
	{
		if(a[i]!=a[j])
			return false;
	} 
	return true;
}

//ʹ��˫ָ��
//�����޷�ȥ������ǰ�������ô�죿 
bool isPalindrome(ListNode* head)
{
	
} 
