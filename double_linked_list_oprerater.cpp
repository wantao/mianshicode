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
	pDNode p1 = head;
	if (p1->next)
	{	
		head = head->next;
		head->pre = NULL;
		p->next = NULL;
		printf("head->data:%d\n",head->data);
		free(p1);
		p1 = NULL;
		return head;
	}
	return NULL;
}

pDNode dNode_del(pDNode u_head,const int& u_delNumber)
{
	if (u_head == NULL)
	{
		printf("dNode_del failure:head is NULL\n");
		return u_head;
	}
	pDNode p = u_head;
	while (u_delNumber != p->data && p->next != NULL)
	{
		p = p->next;
	}
	if (u_delNumber == p->data)
	{
		if (p == u_head)
		{
			u_head = u_head->next;
			u_head->pre = NULL;
		}
		else if (p->next == NULL)
		{
			p->pre->next = NULL;
		}
		else
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
		}
		free(p);
		p = NULL;
	}
	else
	{
		printf("dNode_del not found delNumber:%d\n",u_delNumber);
	}
	return u_head;
}

pDNode dNode_insert(pDNode u_head,const int& u_insertNumber)
{
	pDNode p = NULL;
	p = (pDNode)malloc(sizeof(pDNode));
	if (p != NULL)
	{
		p->data = u_insertNumber;
		p->pre = NULL;
		p->next = NULL;

		pDNode pTmp = u_head;
		while (p->data > pTmp->data && pTmp->next != NULL)
		{
			pTmp = pTmp->next;
		}
		if (p->data <= pTmp->data)
		{
			if (pTmp == u_head)
			{
				p->next = pTmp;
				pTmp->pre = p;
				u_head = p;
			}
			else
			{
				pTmp->pre->next = p;
				p->pre = pTmp->pre;
				p->next = pTmp;
				pTmp->pre = p;
			}
		}
		else
		{
			pTmp->next = p;
			p->pre = pTmp;
			p->next = NULL;
		}
	}
	else
	{
		printf("dNode_insert malloc node failure\n");
	}
	return u_head;

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
	
	/*int u_delNumber = 0;
	printf("\ninput the delNumber:");
	scanf("%d",&u_delNumber);
	head = dNode_del(head,u_delNumber);
	print_double_linked_list(head);*/

	int u_insertNumber = 0;
	printf("\ninput the insertNumber:");
	scanf("%d",&u_insertNumber);
	head = dNode_insert(head,u_insertNumber);
	print_double_linked_list(head);

	return 0;
}