#include "linklist.h"
#include<stdlib.h>
#include<stdio.h>

int createListHead(LinkList **head,int n){
	int c = 0;
	LinkList *pHead = (LinkList *) malloc(sizeof(LinkList));
	pHead -> pNext = NULL;
	int t = 0;
	for(; n> 0;n--) { 
		scanf("%d",&t);
		LinkList *tmp = (LinkList *) malloc(sizeof(LinkList));
		tmp -> elem = t;
		tmp -> pNext = pHead -> pNext;
		pHead->pNext = tmp;
		c++;
	}
	*head = pHead;
	return c;
}

int createListTail(LinkList **head,int n) {
	int c = 0;
	LinkList *pHead = (LinkList *) malloc(sizeof(LinkList));
	pHead -> pNext = NULL;
	*head = pHead;
	
	LinkList *tail = pHead;
	
	int t = 0;
	for(; n> 0;n--) { 
		scanf("%d",&t);
		LinkList *tmp = (LinkList *) malloc(sizeof(LinkList));
		tmp -> elem = t;
		tail -> pNext = tmp;
		tmp -> pNext = NULL;
		tail = tmp;
		c++;
	}
	
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
	
	if(i < 0) return -2;
	if(head == NULL) return -1;
	
	head = head->pNext;
	int n = 0; 
	for(; n < i;n++){ 
		if(head == NULL) break; 
		head = head->pNext;
	}
	if(head == NULL) 
		return -2;
	else{ 
		*elem = head-> elem;
		return i;
	}
	
}
// test
int main() { 
	LinkList *h; 
	printf("created count of listList:%d\n",createListTail(&h,4));
	printf("head");
	printf("count : %d\n",printList(h));

	ElemType elem;
	printf("no. 2 :%d",getElem(h,2,&elem));
	printf("value: %d\n",elem);
	printf("no. 0 :%d",getElem(h,0,&elem));
	printf("value: %d\n",elem);


}

