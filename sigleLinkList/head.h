#ifndef _HEAD_H_
#define _HEAD_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *pre;
	struct node *next;
}duLinkList;

//插入,尾插法
int insert(duLinkList **,duLinkList **,int );

//删除节点
void deleteNode(duLinkList **,duLinkList **,int);

//修改元素
void modify(duLinkList **,int,int);

//查询元素
void search(duLinkList *,int);

//判断链表是否为空
int isEmpty(duLinkList *);

#endif
