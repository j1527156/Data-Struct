#include "head.h"
//正序显示
void show(duLinkList *phead)
{
	duLinkList *ptail = phead->next;
	while(ptail != phead && ptail)
	{
		printf("%d ",ptail->data);
		ptail = ptail->next;
	}
	printf("\n");
}
// 逆序显示
void pre_show(duLinkList *phead)
{
	duLinkList *ptail = phead->pre;
	while(ptail != phead && ptail)
	{
		printf("%d ",ptail->data);
		ptail = ptail->pre;
	}
	printf("\n");
}

int main()
{
	duLinkList *phead,*ptail;
	phead = (duLinkList *)malloc(sizeof(duLinkList));
	phead->next = NULL;
	phead->pre = NULL;
	ptail = phead;

	insert(&phead,&ptail,6);
	insert(&phead,&ptail,3);
	insert(&phead,&ptail,7);
	insert(&phead,&ptail,8);
	show(phead);
	//pre_show(phead);
	deleteNode(&phead,&ptail,7);
	insert(&phead,&ptail,9);
	show(phead);
	pre_show(phead);
	modify(&phead,8,88);
	show(phead);
	search(phead,88);
	return 0;
}
