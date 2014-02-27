#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct dNode
{
	int data;
	struct dNode* pre;
	struct dNode* next;
};

typedef struct dNode* pDNode;

pDNode create_double_linked_list()
{
	pDNode head = NULL,p = NULL,s = NULL;
	int inputNumber = 0,flag=1;
	head = (pDNode)malloc(sizeof(pDNode));
	if (head == NULL)
	{
		printf("create_double_linked_list create head failure\n");
		return NULL;
	}
	p = head;
	while (flag)
	{
		printf("input the number:");
		scanf("%d",&inputNumber);
		if (inputNumber != 0)
		{
			s = (pDNode)malloc(sizeof(pDNode));
			if (s == NULL)
			{
				printf("create_double_linked_list create node failure\n");
				return NULL;
			}
			s->data = inputNumber;
			p->next = s;
			s->pre = p;
			p = s;
		}
		else
		{
			flag = 0;
		}
	}
	head = head->next;
	head->pre = NULL;
	p->next = NULL;
	printf("head->data:%d\n",head->data);
	return head;
}

void print_double_linked_list(pDNode u_head)
{
	pDNode p = u_head;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int main(void)
{
	pDNode head = create_double_linked_list();
	if (head)
	{
		print_double_linked_list(head);
	}
	return 0;
}