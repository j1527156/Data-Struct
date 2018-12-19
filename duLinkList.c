#include "head.h"
//带头结点双链表
//插入,尾插法
int insert(duLinkList **phead,duLinkList **ptail,int num)
{
	duLinkList *pnew = (duLinkList *)malloc(sizeof(duLinkList));
	if(pnew == NULL)
	{
		return 0;
	}
	//有头节点，所以不用判断链表是否为空.有头节点的操作是一致的	
	pnew->data = num;
	pnew->next = *phead;
	pnew->pre = *ptail;
	(*phead)->pre = pnew;
	(*ptail)->next = pnew;
	*ptail = pnew;
	
	return 1;
}

//删除节点
void deleteNode(duLinkList **phead,duLinkList **ptail,int num)
{
	if(isEmpty(*phead))
	{
		printf("链表为空\n");
		return ;
	}

	duLinkList *plast = (*phead)->next;
	while(plast && plast != *phead)
	{
		if(plast->data == num)
		{
			plast->pre->next = plast->next;
			plast->next->pre = plast->pre;
	
			if(plast == *ptail)//删除的是最后一个节点，调整尾指针
				*ptail = (*ptail)->pre;
			free(plast);
			
			break;
		}
		plast = plast->next;
	}
}

//修改元素
void modify(duLinkList **phead,int oldNum,int newNum)
{
	duLinkList *ptail = (*phead)->next;
	while(ptail && ptail != *phead) // 如果链表为空就不会执行，所以可以不用判断是否为空
	{
		if(ptail->data == oldNum)
		{
			ptail->data = newNum;
			break;
		}
		ptail = ptail->next;
	}
}

//查询元素
void search(duLinkList *phead,int num)
{
	int flag = 0;
	duLinkList *plast = phead->next;
	while(plast != phead && plast)
	{
		if(plast->data == num)
		{
			printf("find this value:%d\n",plast->data);
			flag = 1;
			break;
		}
		plast = plast->next;
	}

	if(!flag)
	{
		printf("Don't find this value\n");
	}
}

//判断链表是否为空
int isEmpty(duLinkList *phead)
{
	if(phead->next == NULL)
		return 1;
	else
		return 0;
}
