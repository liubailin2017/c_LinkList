
#ifndef _linklist_h
#define _linklist_h 1


#define NULL 0 

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

int createListHead(LinkList **);
int createListTail(LinkList **);
int getlength(LinkList *);
int printList(LinkList *);
int getElem(LinkList *,int i,ElemType *);
int insertList(LinkList *, int i, ElemType data);
int insertListTail(LinkList *, ElemType data);
int deleteList(LinkList *, int i, ElemType *data);
int clearList(LinkList *);
# endif

