#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
};

Node* createNode(); //����������
//�������ĺ���,head������,location�ǲ����λ��,data�ǲ���Ľ��������� 
Node* insertNode(Node* head,int location,int data); 
//����ɾ���ĺ���,head������,location��ɾ���Ľ���λ�� 
Node* deleteNode(Node* head,int location);
//���ҽ��ĺ���,DataΪĿ������������ֵ 
int scanNode(Node* head,int Data);
//���½��ĺ���,locationΪҪ���ĵĽ���λ��,newDataΪ�µ��������ֵ 
Node* modifyNode(Node* head,int location,int newData);
//���������
void display(Node* head);

int main()
{
	//��ʼ������Ϊ(1,2,3,4)
	printf("��ʼ������Ϊ:");
	Node* head=createNode();
	display(head);
	
	printf("�ڵ�4������λ�ò���Ԫ��5:\n");
	head=insertNode(head,4,5);
	display(head);
	
	printf("ɾ��Ԫ��3:\n");
	head=deleteNode(head,3);
	display(head);
	
	printf("����Ԫ��2��λ��:\n");
	int location=scanNode(head,2);
	if(location==-1)
		printf("û�и�Ԫ��\n");
	else
		printf("Ԫ��2��λ��Ϊ%d\n",location);
	
	printf("���ĵ�3������ֵΪ7:\n");
	head=modifyNode(head,3,7);
	display(head);
	
	return 0;
} 

Node* createNode()
{
	Node* head=(Node*)malloc(sizeof(Node)); //����һ��ͷ���,head->next��ָ����Ԫ��� 
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
	temp=temp->next; //��tempָ����Ԫ��� 
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
