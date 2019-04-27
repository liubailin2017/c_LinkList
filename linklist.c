#include "linklist.h"
#include<stdlib.h>
#include<stdio.h>

#if debug
 	ElemType intputElemtInt(ElemType* n) {
		printf("inputElemtValue");
		scanf("%d",n);
		return *n;
	}	int example_handler(LinkList node) {
		printf("%p->%d\n",&node, node.elem);
		return 1;
	}
#else
	ElemType intputElemtStruct(ElemType* n) {
		scanf("%d",&(n->d));
		return *n;
	}

	int example_handler(LinkList node) {
		printf("%p->%d\n",&node, node.elem.d);
		return 1;
	}
#endif



int createListHead(LinkList **head,int n){
	int c = 0;
	LinkList *pHead = (LinkList *) malloc(sizeof(LinkList));
	pHead -> pNext = NULL;
	ElemType t;
	for(; n> 0;n--) { 
		inputElemtValue(&t);
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
	
	ElemType t ;
	for(; n> 0;n--) { 
		inputElemtValue(&t);
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

int queryList(LinkList *pHead,fHandladapter handler) {
	int c = 0;
		while(pHead = pHead->pNext){
			if(!handler(*pHead)) break;
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

int insertList(LinkList *head, int i, ElemType data) {
	if(i < 0) return -2;
	if(head == NULL) return -1;
	int n = 0;
	for(; n < i;n++){
		if(head == NULL) break;
		head = head->pNext;
	}

	if(head == NULL)
		return -2;
	else{
		LinkList *tmp = (LinkList *) malloc(sizeof(LinkList));
		tmp->elem = data;
		tmp->pNext = head->pNext;
		head->pNext = tmp;
		return i;
	}
}
int insertListTail(LinkList *head, ElemType data) {

	if(head == NULL) return -1;

	int i = 0;
	LinkList *p;
	p = head;

	while(head->pNext) {
		head = head->pNext;
		p = head;
		i++;
	}

	LinkList *tmp = (LinkList *) malloc(sizeof(LinkList));
	tmp->elem = data;
	tmp->pNext = p->pNext;
	p->pNext = tmp;
	return i;
}

int getlength(LinkList *pHead) {
	int c = 0;
	while(pHead = pHead->pNext){
		c++;
	}
	return c;
}


int deleteList(LinkList *head, int i, ElemType *elem) {
	LinkList *tmp;
	if(i < 0) return -2;
		if(head == NULL) return -1;
		tmp = head;
		head = head->pNext;
		int n = 0;
		for(; n < i;n++){
			if(head == NULL) break;
			tmp = head;
			head = head->pNext;
		}

		if(head == NULL)
			return -2;
		else{
			tmp->pNext = tmp ->pNext->pNext;
			if(elem != NULL)
				*elem = head-> elem;
			free(head);
			return i;
		}
}

int clearList(LinkList *pHead) {

	int c = 0;
	if(pHead == NULL) {
		return -1;
	}
	LinkList *head = pHead->pNext;
	LinkList *tmp;

	while(head) {
		tmp = head -> pNext;
//		printf("-free %d-",head->elem);
		free(head);
		c++;
		head = tmp;
	}

	pHead->pNext = NULL;
	return c;
}


