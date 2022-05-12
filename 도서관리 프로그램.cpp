#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

int number1; //number1은 관리 프로그램 업무 선택 번호

typedef struct data {  //구조체를 쓰기 위해서 사용했다. 구조체를 사용하려는 이유는 각 종류별로 구별짓기 위해서.
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
	printf("책 관리 프로그램입니다. 하실 업무를 선택하세요. 1.도서 추가 2.도서 검색 3.도서 정보 수정 4.도서 삭제 5.도서 목록 출력 6.프로그램 종료");
	scanf("%d", &number1);
	if (number1 == 1) {
		printf("해당 도서를 txt파일에 저장합니다. \n");
		FILE* fp;
		fp = fopen("input.txt", "a");//a는 append
		printf("추가하실 책의 이름, 작가, 발행년도, 출판사, 장르를 순서대로 적어주세요. \n");
		scanf("%s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
		fscanf(fp, "%s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
		printf("입력하신 내용은 다음과 같습니다. %s %s %d %s %s", d1.bookname, d1.writer, &d1.year, d1.publisher, d1.genre);
	}
	else if (number1 == 2) {
		printf("도서를 검색합니다. 찾으실 도서,작가,발행년도,출판사,장르 중 하나를 입력해주세요. \n");
		book_info book[100];
		FILE* fp = fopen("input.txt", "rb"); //rb는 read+binary
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
					printf("수정하실 도서를 입력해주세요. \n");
					FILE* fp = fopen("input.txt", "rb");


				}
	else if (number1 == 4) {
					printf("삭제하실 도서를 입력하세요. \n");

				}
	else if (number1 == 5) {
					printf("전체 도서의 목록을 불러옵니다. \n");
					std::ifstream text("input.txt");
					std::string s; // std는 Standard로써 iostream내부에 입출력에 관한 함수들을 가지고 있는 네임스페이스
					if (text.is_open()) { // 위치 지정자를 파일 끝으로 옮긴다.
						text.seekg(0, std::ios::end); // 그리고 그 위치를 읽는다. (파일의 크기)
						int size = text.tellg(); // 그 크기의 문자열을 할당한다.
						s.resize(size); // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
						text.seekg(0, std::ios::beg); // 파일 전체 내용을 읽어서 문자열에 저장한다.
						text.read(&s[0], size);
						std::cout << s << std::endl;
					}
					else {
						std::cout << "파일을 찾을 수 없습니다!" << std::endl;
					}
					return 0;

				}
	else if (number1 == 6) {
					printf("프로그램을 종료합니다. \n");

				}

}

		void find_book_name(book_info * book, int size)
		{
			printf("찾고싶은 책의 이름을 입력하세요: ");
			char find_book[100];
			scanf("%s", find_book);
			char* bwypg;
			book_info* b;
			int line = 0;
			for (b = book; b < book + size; b++, line++) {
				bwypg = strstr(b->bookname, find_book);
				if (bwypg != NULL) {
					printf("도서목록 %d 줄에 책 이름 %s 저자 %s 발행연도 %d 출판사 %s 장르 %s가 있습니다. \n", line, b->bookname, b->writer, b->year, b->publisher, b->genre);
				}

			}
		}	