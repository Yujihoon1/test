#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void addBook(); // ���� ��� �Լ�
void AllBookList();    // ���� ��� ��� �Լ�
void searchmenu();   // ���� �˻� �޴� �Լ�
void searchBookName(); // ���������� �˻�
void searchAuthor(); // ���ڷ� �˻�
void searchPublisher(); // ���ǻ�� �˻�

typedef struct _book {
	char bookname[30]; // å ����
	char author[30]; // å ����
	char publisher[30]; // å ���ǻ�
	char year[30]; //���ǳ⵵
	char genre[30]; //å �帣
}Book;



FILE* fp;
Book booklist[100];
int bookindex = 0;
int i, j;

int main(void)
{
	int i = 0;
	char fpname[30];
	char fpauth[30];
	char fppubl[30];
	char year[30];
	char fpgenre[30];
	char input[10] = { 0, };

	system("title ���� ���� ���� ���α׷�");
	// int system(const char *command)�� ������� ������ ��� �̸� �Ǵ� ���α׷� �̸��� ��� ���μ����� ���� ����� ȣ��Ʈ ȯ�濡 �����ϰ� ����� �Ϸ�� �� ����

	fp = fopen("input.txt", "a+");
	if (fp == NULL) {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		return 1;
	}

	while (!feof(fp)) //��Ʈ���� ������ ���� �� ǥ�ñⰡ �����Ǹ� 0�� �ƴ� ���� ��ȯ�ϰ�, �׷��� ������ 0�� ��ȯ�˴ϴ�.
	{
		fscanf(fp, "%[^], %[^], %[^], %[^],%[^\n]", booklist[i].bookname, booklist[i].author, booklist[i].publisher);
		fgetc(fp);
		i++;
	}

	while (1)
	{
		system("cls");
		printf("�����߰� �����˻� ������������ �������� ����������  ���� ");
		gets(input);


			 if (!strcmp(input, "�����߰�"))
			registerbook();
		else if (!strcmp(input, "���� �˻�"))
			searchBook();
		else if (!strcmp(input, "���� ���� ����"))
			 changeBook();
		else if (!strcmp(input, "���� ����"))
				 deleteBook();
		else if (!strcmp(input, "������"))
			printbook();
		else if (!strcmp(input, "����"))
		{
			printf("\n\n���� ���� ���α׷��� �����մϴ�.\n\n");
			return 0;
		}
		else
		{
			printf("\n\n�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n\n");
			printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
			_getch();
			continue;
		}
	}

	fclose(fp);

	return 0;
}

void registerbook()
{
	char yesorno[10] = { 0, }; //�迭�� ��Ҹ� ��� 0���� �ʱ�ȭ
	char bookname[30] = { 0, };
	char author[30] = { 0, };
	char publisher[30] = { 0, };
	char year[30] = { 0, };
	char genre[30] = { 0, };

	printf("\n\n����� ������ �̸��� �Է��ϼ��� : ");
	gets(bookname);
	printf("����� ������ ���ڸ� �Է��ϼ��� : ");
	gets(author);
	printf("����� ������ ���ǿ����� �Է��ϼ��� : ");
	gets(year);
	printf("����� ������ ���ǻ縦 �Է��ϼ��� : ");
	gets(publisher);	
	printf("����� ������ �帣�� �Է��ϼ��� : ");
	gets(genre);
	printf("������ : %s\n ���� : %s\n ���ǿ���:%s\n ���ǻ� : %s\n �帣: %s\n �� ������ �½��ϱ�? (��/�ƴϿ�) : ", bookname, author,year, publisher,genre);
	gets(yesorno);

	if (strcmp(yesorno, "��"))
	{
		printf("\n\n���� ����� ����մϴ�.\n\n");
		printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
		_getch();
		return;
	}

	strcpy(booklist[i].bookname, bookname);
	strcpy(booklist[i].author, author);
	strcpy(booklist[i].year, year);
	strcpy(booklist[i].publisher, publisher);
	strcpy(booklist[i].genre, genre);
	bookindex++;

	fprintf(fp, "\n%s,%s,%s,%s,%s", bookname, author,year, publisher ,genre);

	printf("\n���� ����� �Ϸ�Ǿ����ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void printbook()
{
	printf("\n\n");
	if (!bookindex)
	{
		printf("���� ����� �����\n\n");
		printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
		_getch();
		return;
	}
	for (i = 0; i < bookindex; i++)
	{
		printf("=======================\n");
		printf("������ : %s\n", booklist[i].bookname);
		printf("��  �� : %s\n", booklist[i].author);
		printf("���ǿ��� : %s\n", booklist[i].year);
		printf("���ǻ� : %s\n", booklist[i].publisher);
		printf("�帣 : %s\n", booklist[i].genre);
	}
	printf("=======================\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void searchBook()
{
	char input[20] = { 0, };

	printf("\n\n[������˻�] [���ڰ˻�] [���ǻ�˻�] : ");
	gets(input);

	if (!strcmp(input, "������ �˻�"))
		searchbookbyname();
	else if (!strcmp(input, "���� �˻�"))
		searchbookbyauth();
	else if (!strcmp(input, "���ǿ��� �˻�"))
		searchbookbyyear();
	else if (!strcmp(input, "���ǻ� �˻�"))
		searchbookbypubl();
	else if (!strcmp(input, "�帣 �˻�"))
		searchbookbygenre();
	else
	{
		printf("\n\n�߸��� �Է��Դϴ�.\n\n");
		printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
		_getch();
	}
}

void searchbookbyname()
{
	int namelength;    // �˻��� å �̸��� ����
	int sameword;       // å �̸� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char bookname[30] = { 0, };

	printf("\n\n�������� �Է��ϼ��� : ");
	gets(bookname);

	namelength = strlen(bookname);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (bookname[j] == booklist[i].bookname[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
					searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("�˻��� ������ ã�� ���߽��ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void searchbookbyauth()
{
	int namelength;    // �˻��� ���� �̸��� ����
	int sameword;       // ���� �̸� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char author[30] = { 0, };

	printf("\n\n���ڸ��� �Է��ϼ��� : ");
	gets(author);

	namelength = strlen(author);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (author[j] == booklist[i].author[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("�˻��� ������ ã�� ���߽��ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void searchbookbyyear()
{
	int namelength;    // �˻��� ���ǿ����� ����
	int sameword;       // ���ǿ��� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char year[30] = { 0, };

	printf("\n\n���ǿ����� �Է��ϼ��� : ");
	gets(year);

	namelength = strlen(year);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (year[j] == booklist[i].year[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("�˻��� ������ ã�� ���߽��ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void searchbookbypubl()
{
	int namelength;    // �˻��� ���ǻ� �̸��� ����
	int sameword;       // ���ǻ� �̸� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char publisher[30] = { 0, };

	printf("\n\n���ǻ縦 �Է��ϼ��� : ");
	gets(publisher);

	namelength = strlen(publisher);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (publisher[j] == booklist[i].publisher[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("�˻��� ������ ã�� ���߽��ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}

void searchbookbygenre()
{
	int namelength;    // �˻��� �帣 �̸��� ����
	int sameword;       // �帣 �̸� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char genre[30] = { 0, };

	printf("\n\n�帣 �Է��ϼ��� : ");
	gets(genre);

	namelength = strlen(genre);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (genre[j] == booklist[i].genre[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("�˻��� ������ ã�� ���߽��ϴ�.\n\n");

	printf("\n����Ϸ��� �ƹ� Ű�� �Է��ϼ���...");
	_getch();
}
void changeBook() {
	int namelength;    // �˻��� å �̸��� ����
	int sameword;       // å �̸� �� ���ھ� ��, ������ 1�� ����
	int searchNum = 0; // �� �˻��� ���� ����
	char bookname[30] = { 0, };

	printf("\n\n�������� �Է��ϼ��� : ");
	gets(bookname);

	namelength = strlen(bookname);
	printf("\n\n");

	for (i = 0; i < bookindex; i++)
	{
		sameword = 0;
		for (j = 0; j < namelength; j++)
		{
			if (bookname[j] == booklist[i].bookname[j])
				sameword++;
			else
				break;
		}
		if (sameword == namelength)
		{
			printf("=======================\n");
			printf("������ : %s\n", booklist[i].bookname);
			printf("��  �� : %s\n", booklist[i].author);
			printf("���ǿ��� : % s\n", booklist[i].year);
			printf("���ǻ� : %s\n", booklist[i].publisher);
			printf("�帣 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
}