// 추가적인 함수를 구현하는 파일입니다.
#include <stdio.h>

void println()
{
    printf("\n-------------------------------\n\n");
};

void success_fail(int result)
{
    if (result == 1)
    {
        printf("작업 수행 성공\n");
        println();
    }
    else if (result == 0)
    {
        printf("작업 수행 실패\n");
        println();
    }
}