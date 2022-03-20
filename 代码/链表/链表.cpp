#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
};

Node* createNode(); //创建链表函数
//链表插入的函数,head是链表,location是插入的位置,data是插入的结点的数据域 
Node* insertNode(Node* head,int location,int data); 
//链表删除的函数,head是链表,location是删除的结点的位置 
Node* deleteNode(Node* head,int location);
//查找结点的函数,Data为目标结点的数据域的值 
int scanNode(Node* head,int Data);
//更新结点的函数,location为要更改的结点的位置,newData为新的数据域的值 
Node* modifyNode(Node* head,int location,int newData);
//输出链表函数
void display(Node* head);

int main()
{
	//初始化链表为(1,2,3,4)
	printf("初始化链表为:");
	Node* head=createNode();
	display(head);
	
	printf("在第4个结点的位置插入元素5:\n");
	head=insertNode(head,4,5);
	display(head);
	
	printf("删除元素3:\n");
	head=deleteNode(head,3);
	display(head);
	
	printf("查找元素2的位置:\n");
	int location=scanNode(head,2);
	if(location==-1)
		printf("没有该元素\n");
	else
		printf("元素2的位置为%d\n",location);
	
	printf("更改第3个结点的值为7:\n");
	head=modifyNode(head,3,7);
	display(head);
	
	return 0;
} 

Node* createNode()
{
	Node* head=(Node*)malloc(sizeof(Node)); //创建一个头结点,head->next才指向首元结点 
	Node* tail=head;
	
	for(int i=1;i<5;i++)
	{
		Node* node=(Node*)malloc(sizeof(Node));
		node->data=i;
		node->next=NULL;
		tail->next=node;
		tail=tail->next;
	} 
	return head;
}

Node* insertNode(Node* head,int location,int newData)
{
	Node* temp=head;
	int i=1;
	while(i<location&&temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	Node* current=temp;
	
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=newData;
	node->next=current->next;
	current->next=node;
	
	return head;
}

Node* deleteNode(Node* head,int location)
{
	Node* temp=head;
	int i=1;
	while(i<location&&temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	Node* current=temp;
	
	Node* del=current->next;
	current->next=del->next;
	free(del);
	
	return head;
}

int scanNode(Node* head,int Data)
{
	Node* temp=head;
	int i=0;
	while(temp!=NULL)
	{
		if(temp->data==Data)
			return i;
		temp=temp->next;
		i++;
	}
	if(temp==NULL)
		return -1;
}

Node* modifyNode(Node* head,int location,int newData)
{
	Node* temp=head;
	int i=1;
	while(i<=location&&temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	
	temp->data=newData;
	return head;
}

void display(Node* head)
{
	Node* temp=head;
	temp=temp->next; //让temp指向首元结点 
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
