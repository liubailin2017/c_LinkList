
#ifndef _linklist_h
#define _linklist_h 1

#ifndef NULL 
/** null ptr **/
#define NULL 0 
#endif

#define debug 1

#if debug
typedef int ElemType;
#else 
typedef struct {
	int d; // tmp
} ElemType;
#endif

typedef struct LinkList{
	ElemType elem;
	struct LinkList* pNext;	
} LinkList;

int createListHead(LinkList **,int n);
int createListTail(LinkList **,int n);
int getlength(LinkList *);
int printList(LinkList *);
/*
返回-2 越界 -1 未找到, 如果大于或等于0 找到
*/
int getElem(LinkList *,int i,ElemType *); 
int insertList(LinkList *, int i, ElemType data);
int insertListTail(LinkList *, ElemType data);
int deleteList(LinkList *, int i, ElemType *data);
int clearList(LinkList *);
# endif

