/*
 ============================================================================
 Name        : Test.c
 Author      : liubailin
 Version     :
 Copyright   : Your copyright notice
 Description : Test
 ============================================================================
 */
#include"linklist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	LinkList *h;
	printf("### TEST create\n");
	printf("created count of listList:%d\n",createListTail(&h,4));

	printf("### TEST getElem\n");
	ElemType elem;
	printf("no. 2 :%d",getElem(h,2,&elem));
	printf("value: %d\n",elem);
	printf("no. 0 :%d",getElem(h,0,&elem));
	printf("value: %d\n",elem);

	printf("### TEST insert\n");

	insertList(h,0,100);
	insertListTail(h,1000);
	insertListTail(h,2000);
	printf("head");
	printf("count : %d\n",queryList(h,example_handler));
	printf("### TEST delete\n ");
	ElemType t;
	deleteList(h,0,&t);
	printf("delete %d\n",t);
	printf("count : %d\n",queryList(h,example_handler));

	printf("### TEST clear\n");
	printf("ret %d\n",clearList(h));
	printf("size%d \n",getlength(h));
}
