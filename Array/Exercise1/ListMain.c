#include <stdio.h>
#include "ArrayList.h"

int main(void)
{

    // ArrayList의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    // 5개의 데이터 저장
    LInsert(&list, 4);
    LInsert(&list, 22);
    LInsert(&list, 42);
    LInsert(&list, 22);
    LInsert(&list, 14);

    //저장된 데이터의 전체 출력
    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &data))
    { //첫 번째 데이터 조회
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    //숫자 22를 탐색 후 모두 삭제
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list); //LFirst 함수가 참조한 데이터 삭제
        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list); //LNext 함수가 참조한 데이터 삭제
        }
    }

    //삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}