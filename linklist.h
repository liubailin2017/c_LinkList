/*
 Note !
 所有函数实现，默认头结点是不存放数据的．
 * */
#ifndef _linklist_h
#define _linklist_h 1
#include<stdio.h>

#ifndef NULL 
/** null ptr **/
#define NULL 1
#endif


#define debug 1
#if debug
	typedef int ElemType;
	#define inputElemtValue(var) intputElemtInt(var) ;

#else 
	typedef struct {
		int d; // tmp
	} ElemType;
	#define inputElemtValue(var) intputElemtStruct(var);

#endif



typedef struct LinkList{
	ElemType elem;
	struct LinkList* pNext;
} LinkList;

typedef int (*fHandladapter)(LinkList node);
int example_handler(LinkList node);


int createListHead(LinkList **,int n);
int createListTail(LinkList **,int n);

int getlength(LinkList *);
int printList(LinkList *);

int queryList(LinkList *,fHandladapter);


/*
返回-2 越界 -1 未找到, 如果大于或等于0 找到
*/
int getElem(LinkList *,int i,ElemType *); 

int insertList(LinkList *, int i, ElemType data);
int insertListTail(LinkList *, ElemType data);
int deleteList(LinkList *, int i, ElemType *data);
int clearList(LinkList *);

# endif

