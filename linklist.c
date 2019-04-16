#include "linklist.h"
#include<stdlib.h>
#include<stdio.h>

int createListHead(LinkList **head){
	int c = 0;
	LinkList *pHead = (LinkList *) malloc(sizeof(LinkList));
	pHead -> pNext = NULL;
	int t = 0;
	scanf("%d",&t);
	while(t >= 0) { 
		LinkList *tmp = (LinkList *) malloc(sizeof(LinkList));
		tmp -> elem = t;
		tmp -> pNext = pHead -> pNext;
		pHead->pNext = tmp;
		c++;
		scanf("%d",&t);
	}
	*head = pHead;
	return c;
}

int printList(LinkList *pHead) {
	int c = 0;
	while(pHead = pHead->pNext){
		printf("->%d",pHead->elem);
		c++;
	}
	return c;
}

int getElem(LinkList *head,int i,ElemType *elem){
	if(i < 0) return -1;
	if(head == NULL) return -1;
	head = head->pNext;
	while(i--){ 
		if(head == NULL) break; 
		head = head->pNext;
	}
	if(head == NULL) 
		return -1;
	else{ 
		*elem = head-> elem;
		return i;

	}
	
}
// test
int main() { 
	LinkList *h; 
	printf("created count of listList:%d\n",createListHead(&h));
	printf("head");
	printf("count : %d\n",printList(h));

	ElemType elem;
	printf("no. 2 :%d",getElem(h,2,&elem));
	printf("value: %d\n",elem);
	printf("no. 0 :%d",getElem(h,0,&elem));
	printf("value: %d\n",elem);


}

