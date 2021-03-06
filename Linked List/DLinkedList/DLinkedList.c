#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
    plist -> head = (Node*)malloc(sizeof(Node));
    plist -> head -> next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    
    newNode->next = plist->head->next; /* 새 노드가 다음 노드를 가리킨다. */
    plist->head->next = newNode;/* 더미 노드가 새 노드를 가리킨다. */
    (plist->numOfData)++;/* 노드 수 증가 시킨다. */
}

void SInsert(List * plist, LData data)
{

}

void LInsert(List *plist, LData data)
{
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
    if(plist->head->next == NULL) //더미 노드가 NULL을 가리킨다면
        return FALSE;   /* 반환할 데이터가 없다 */

    plist->before = plist->head; /* before는 더미 노드를 가리키게함 */
    plist->cur = plist->head->next;  /* cur은 첫 번째 노드를 가리키게함 */

    *pdata = plist->cur->data; /* 첫 번째 노드의 데이터를 전달 */
    return TRUE;/* 데이터 반환 성공 */
}

int LNext(List * plist, LData *pdata)
{
    if(plist->cur->next == NULL)/* cur이 NULL을 가리킨다면 */
        return FALSE;/* 반환할 데이터가 없다 */

    plist->before = plist -> cur;/* cur이 가리키던 것을 before가 가리킴 */
    plist->cur = plist->cur->next;/* cur은 그 다음 노드를 가리킴 */

    *pdata = plist->cur->data;/* cur이 가리키는 노드의 데이터 전달 */
    return TRUE;/* 데이터 반환 성공 */
}

LData LRemove(List *plist)
{
    Node * rpos = plist->cur;/* 소멸되는 노드의 주소 값을 rpos에 저장 */
    LData rdata = rpos -> data; /* 소멸되는 노드의 데이터를 rdata에 저장 */

    plist->before->next = plist->cur->next;/* 소멸 대상을 리스트에서 제거 */
    plist->cur = plist->before;/* cur이 가리키는 위치를 재조정 */

    free(rpos);/* 리스트에서 제거된 노드 소멸 */
    (plist->numOfData)--;/* 저장된 데이터의 수 하나 감소 */
    return rdata;/* 제거된 노드의 데이터 반환 */
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{

}
