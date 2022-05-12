#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

int number1; //number1은 관리 프로그램 업무 선택 번호
char bookname[10];
char writer[8];
int year;
char publisher[10];
char genre[6];


int main()
{
	printf("책 관리 프로그램입니다. 하실 업무를 선택하세요. 1.도서 추가 2.도서 검색 3.개별 검색 4.도서 정보 수정 5.도서 삭제 6.도서 목록 출력 7.프로그램 종료");
		scanf("%d", number1);
		if (number1 == 1) {
			FILE* fp = fopen("input.txt", "w");
			printf("추가하실 책의 이름, 작가, 발행년도, 출판사, 장르를 순서대로 적어주세요.");
			scanf("%s,%s,%d,%s,%s", &bookname, &writer, &year, &publisher, &genre);
			fprintf(fp, "%s %s %d %s %s", &bookname, &writer, &year, &publisher, &genre);

		}
}