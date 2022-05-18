#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void addBook(); // 도서 등록 함수
void AllBookList();    // 도서 목록 출력 함수
void searchmenu();   // 도서 검색 메뉴 함수
void searchBookName(); // 도서명으로 검색
void searchAuthor(); // 저자로 검색
void searchPublisher(); // 출판사로 검색

typedef struct _book {
	char bookname[30]; // 책 제목
	char author[30]; // 책 저자
	char publisher[30]; // 책 출판사
	char year[30]; //출판년도
	char genre[30]; //책 장르
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

	system("title 도서 종합 관리 프로그램");
	// int system(const char *command)은 명령으로 지정된 명령 이름 또는 프로그램 이름을 명령 프로세서에 의해 실행될 호스트 환경에 전달하고 명령이 완료된 후 리턴

	fp = fopen("input.txt", "a+");
	if (fp == NULL) {
		printf("파일 열기에 실패했습니다.\n");
		return 1;
	}

	while (!feof(fp)) //스트림과 연관된 파일 끝 표시기가 설정되면 0이 아닌 값을 반환하고, 그렇지 않으면 0이 반환됩니다.
	{
		fscanf(fp, "%[^], %[^], %[^], %[^],%[^\n]", booklist[i].bookname, booklist[i].author, booklist[i].publisher);
		fgetc(fp);
		i++;
	}

	while (1)
	{
		system("cls");
		printf("도서추가 도서검색 도서정보수정 도서삭제 도서목록출력  종료 ");
		gets(input);


			 if (!strcmp(input, "도서추가"))
			registerbook();
		else if (!strcmp(input, "도서 검색"))
			searchBook();
		else if (!strcmp(input, "도서 정보 수정"))
			 changeBook();
		else if (!strcmp(input, "도서 삭제"))
				 deleteBook();
		else if (!strcmp(input, "목록출력"))
			printbook();
		else if (!strcmp(input, "종료"))
		{
			printf("\n\n도서 관리 프로그램을 종료합니다.\n\n");
			return 0;
		}
		else
		{
			printf("\n\n잘못된 입력입니다. 다시 입력해주세요.\n\n");
			printf("\n계속하려면 아무 키나 입력하세요...");
			_getch();
			continue;
		}
	}

	fclose(fp);

	return 0;
}

void registerbook()
{
	char yesorno[10] = { 0, }; //배열의 요소를 모두 0으로 초기화
	char bookname[30] = { 0, };
	char author[30] = { 0, };
	char publisher[30] = { 0, };
	char year[30] = { 0, };
	char genre[30] = { 0, };

	printf("\n\n등록할 도서의 이름을 입력하세요 : ");
	gets(bookname);
	printf("등록할 도서의 저자를 입력하세요 : ");
	gets(author);
	printf("등록할 도서의 출판연도를 입력하세요 : ");
	gets(year);
	printf("등록할 도서의 출판사를 입력하세요 : ");
	gets(publisher);	
	printf("등록할 도서의 장르를 입력하세요 : ");
	gets(genre);
	printf("도서명 : %s\n 저자 : %s\n 출판연도:%s\n 출판사 : %s\n 장르: %s\n 위 내용이 맞습니까? (예/아니요) : ", bookname, author,year, publisher,genre);
	gets(yesorno);

	if (strcmp(yesorno, "예"))
	{
		printf("\n\n도서 등록을 취소합니다.\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
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

	printf("\n도서 등록이 완료되었습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void printbook()
{
	printf("\n\n");
	if (!bookindex)
	{
		printf("도서 목록이 비었음\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
		_getch();
		return;
	}
	for (i = 0; i < bookindex; i++)
	{
		printf("=======================\n");
		printf("도서명 : %s\n", booklist[i].bookname);
		printf("저  자 : %s\n", booklist[i].author);
		printf("출판연도 : %s\n", booklist[i].year);
		printf("출판사 : %s\n", booklist[i].publisher);
		printf("장르 : %s\n", booklist[i].genre);
	}
	printf("=======================\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void searchBook()
{
	char input[20] = { 0, };

	printf("\n\n[도서명검색] [저자검색] [출판사검색] : ");
	gets(input);

	if (!strcmp(input, "도서명 검색"))
		searchbookbyname();
	else if (!strcmp(input, "저자 검색"))
		searchbookbyauth();
	else if (!strcmp(input, "출판연도 검색"))
		searchbookbyyear();
	else if (!strcmp(input, "출판사 검색"))
		searchbookbypubl();
	else if (!strcmp(input, "장르 검색"))
		searchbookbygenre();
	else
	{
		printf("\n\n잘못된 입력입니다.\n\n");
		printf("\n계속하려면 아무 키나 입력하세요...");
		_getch();
	}
}

void searchbookbyname()
{
	int namelength;    // 검색할 책 이름의 길이
	int sameword;       // 책 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char bookname[30] = { 0, };

	printf("\n\n도서명을 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
					searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void searchbookbyauth()
{
	int namelength;    // 검색할 저자 이름의 길이
	int sameword;       // 저자 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char author[30] = { 0, };

	printf("\n\n저자명을 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void searchbookbyyear()
{
	int namelength;    // 검색할 출판연도의 길이
	int sameword;       // 출판연도 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char year[30] = { 0, };

	printf("\n\n출판연도를 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void searchbookbypubl()
{
	int namelength;    // 검색할 출판사 이름의 길이
	int sameword;       // 출판사 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char publisher[30] = { 0, };

	printf("\n\n출판사를 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}

void searchbookbygenre()
{
	int namelength;    // 검색할 장르 이름의 길이
	int sameword;       // 장르 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char genre[30] = { 0, };

	printf("\n\n장르 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
	if (searchNum)
		printf("=======================\n\n");
	else
		printf("검색한 도서를 찾지 못했습니다.\n\n");

	printf("\n계속하려면 아무 키나 입력하세요...");
	_getch();
}
void changeBook() {
	int namelength;    // 검색할 책 이름의 길이
	int sameword;       // 책 이름 한 글자씩 비교, 같으면 1씩 증가
	int searchNum = 0; // 총 검색된 도서 개수
	char bookname[30] = { 0, };

	printf("\n\n도서명을 입력하세요 : ");
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
			printf("도서명 : %s\n", booklist[i].bookname);
			printf("저  자 : %s\n", booklist[i].author);
			printf("출판연도 : % s\n", booklist[i].year);
			printf("출판사 : %s\n", booklist[i].publisher);
			printf("장르 : %s\n", booklist[i].genre);
			searchNum++;
		}
	}
}