#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iResult;
int n;
void main()
{
	int array[6]=	{0};
	printf("���ڸ� 6�� �Է��Ͻÿ�. �� ,�� ������� ��Ÿ�� ��");
	scanf("%d,%d,%d,%d,%d,%d", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);
	for (int n = 0; n < 6; n++)
	{
			iResult += array[n];
	}

	printf("�Է��� ���ڵ��� ���� %d�Դϴ�.", iResult);
}