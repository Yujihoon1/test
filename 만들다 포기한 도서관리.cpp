#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

int number1; //number1�� ���� ���α׷� ���� ���� ��ȣ

typedef struct data {  //����ü�� ���� ���ؼ� ����ߴ�. ����ü�� ����Ϸ��� ������ �� �������� �������� ���ؼ�.
	char bookname[10];
	char writer[8];
	int year;
	char publisher[10];
	char genre[6];
}book_info;

void find_book_name(book_info* book, int size);

int main()
{
	struct data d1;
	printf("å ���� ���α׷��Դϴ�. �Ͻ� ������ �����ϼ���. 1.���� �߰� 2.���� �˻� 3.���� ���� ���� 4.���� ���� 5.���� ��� ��� 6.���α׷� ����");
	scanf("%d", &number1);
	if (number1 == 1) {
		printf("�ش� ������ txt���Ͽ� �����մϴ�. \n");
		FILE* fp;
		fp = fopen("input.txt", "a");//a�� append
		printf("�߰��Ͻ� å�� �̸�, �۰�, ����⵵, ���ǻ�, �帣�� ������� �����ּ���. \n");
		scanf("%s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
		fscanf(fp, "%s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
		printf("�Է��Ͻ� ������ ������ �����ϴ�. %s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
	}
	else if (number1 == 2) {
		printf("������ �˻��մϴ�. ã���� ����,�۰�,����⵵,���ǻ�,�帣 �� �ϳ��� �Է����ּ���. \n");
		book_info book[100];
		FILE* fp = fopen("input.txt", "rb"); //rb�� read+binary
		if (fp == NULL) {
			printf("fail to read file");
			return 0;
		}

		int i = 0;
		int num = 0;
		
				find_book_name(book, num);
				return 0;
				}


				

	else if (number1 == 3) {
					printf("�����Ͻ� ������ �Է����ּ���. \n");
					FILE* fp = fopen("input.txt", "rb");


				}
	else if (number1 == 4) {
					printf("�����Ͻ� ������ �Է��ϼ���. \n");

				}
	else if (number1 == 5) {
					printf("��ü ������ ����� �ҷ��ɴϴ�. \n");
					std::ifstream text("input.txt");
					std::string s; // std�� Standard�ν� iostream���ο� ����¿� ���� �Լ����� ������ �ִ� ���ӽ����̽�
					if (text.is_open()) { // ��ġ �����ڸ� ���� ������ �ű��.
						text.seekg(0, std::ios::end); // �׸��� �� ��ġ�� �д´�. (������ ũ��)
						int size = text.tellg(); // �� ũ���� ���ڿ��� �Ҵ��Ѵ�.
						s.resize(size); // ��ġ �����ڸ� �ٽ� ���� �� ������ �ű��.
						text.seekg(0, std::ios::beg); // ���� ��ü ������ �о ���ڿ��� �����Ѵ�.
						text.read(&s[0], size);
						std::cout << s << std::endl;
					}
					else {
						std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
					}
					return 0;

				}
	else if (number1 == 6) {
					printf("���α׷��� �����մϴ�. \n");

				}

}

		void find_book_name(book_info * book, int size)
		{
			printf("ã����� å�� �̸��� �Է��ϼ���: ");
			char find_book[100];
			scanf("%s", find_book);
			char* bwypg;
			book_info* b;
			int line = 0;
			for (b = book; b < book + size; b++, line++) {
				bwypg = strstr(b->bookname, find_book);
				if (bwypg != NULL) {
					printf("������� %d �ٿ� å �̸� %s ���� %s ���࿬�� %d ���ǻ� %s �帣 %s�� �ֽ��ϴ�. \n", line, b->bookname, b->writer, b->year, b->publisher, b->genre);
				}

			}
		}	