#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

int number1; //number1�� ���� ���α׷� ���� ���� ��ȣ
char bookname[10];
char writer[8];
int year;
char publisher[10];
char genre[6];


int main()
{
	printf("å ���� ���α׷��Դϴ�. �Ͻ� ������ �����ϼ���. 1.���� �߰� 2.���� �˻� 3.���� �˻� 4.���� ���� ���� 5.���� ���� 6.���� ��� ��� 7.���α׷� ����");
		scanf("%d", number1);
		if (number1 == 1) {
			FILE* fp = fopen("input.txt", "w");
			printf("�߰��Ͻ� å�� �̸�, �۰�, ����⵵, ���ǻ�, �帣�� ������� �����ּ���.");
			scanf("%s,%s,%d,%s,%s", &bookname, &writer, &year, &publisher, &genre);
			fprintf(fp, "%s %s %d %s %s", &bookname, &writer, &year, &publisher, &genre);

		}
}