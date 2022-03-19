#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iResult;
int n;
void main()
{
	int array[6]=	{0};
	printf("숫자를 6개 입력하시오. 단 ,로 구분지어서 나타낼 것");
	scanf("%d,%d,%d,%d,%d,%d", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
	for (int n = 0; n < 6; n++)
	{
			iResult += array[n];
	}

	printf("입력한 숫자들의 합은 %d입니다.", iResult);
}