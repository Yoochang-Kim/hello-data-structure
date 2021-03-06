#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
    /* 양방향 연결 리스트의 생성 및 초기화 */
    List list;
    ListInit(&list);
    Data data;

    /* 8개의 데이터 생성 */
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    /* 저장된 데이터의 조회 */
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        /* 오른쪽 노드로 이동하며 데이터 조회 */
        while (LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }

    // 3의 배수 삭제
    if (LFirst(&list, &data))
    {
        if (data % 3 == 0)
            LRemove(&list);
        /* 오른쪽 노드로 이동하며 데이터 조회 */
        while (LNext(&list, &data))
        {
            if (data % 3 == 0)
                LRemove(&list);
        }
    }

    printf("\n\n");
    /* 저장된 데이터의 조회 */
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        /* 오른쪽 노드로 이동하며 데이터 조회 */
        while (LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }

    return 0;
}