#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
    return n2 - n1; /* 오름차순 정렬을 위한 문장 */
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap,pc);

    /* 정렬대상을 가지고 힙을 구성한다 */
    for(i = 0; i<n; i++)
        HInsert(&heap, arr[i]);
    
    /* 순서대로 하나씩 꺼내서 정렬을 완성한다. */
    for(i=0; i<n;i++)
        arr[i] = HDelete(&heap);
}
