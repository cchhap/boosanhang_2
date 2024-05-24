#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

// 파라미터
#define LEN_MIN 15 // 기차 길이
#define LEN_MAX 50
#define STM_MIN 0 // 마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 // 확률
#define PROB_MAX 90
#define AGGRO_MIN 0 // 어그로 범위
#define AGGRO_MAX 5
// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0
// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2


//2-1 부산헹(1)코드를 20줄 이내의 함수로 정리한다 ( 몇개정도는 넘어가도 된다고 하심 )
int zom = 0; int cit = 0; int ma = 0; int length = 0; int per = 0; int move1 = 0; int move2 = 0; int turn = 0; int citloc = 0; int zomloc = 0; int mas = 0;//변수선언
int aggro = 1;

void intro() {
	printf("\n----------------------\n"); //인트로
	printf("\nBooSanHang\n");
	printf("\n-start now-\n");
	printf("\n----------------------\n");
	printf("\n\n");
}

void train_length() { //열차의 길이 입력받기
	while(1){
		printf("train_length(15~50)>>");
		scanf_s("%d", &length);
		if (length < 15 || length>50) {
			continue;
		}
		else {
			break;
		}
	}
	
}

void probability_percentage() { //무언가가 일어날 확률
	while(1){
		printf("probability_percentage 'p' (10~90)>>");
		scanf_s("%d", &per);
		if (per < 10 || per > 90) {
			continue;
		}
		else {
			break;
		}
	}
	
}

void madongseok_stamina() { //마동석 체력
	while(1){
		printf("madongseok_stamina(0~5)>>");
		scanf_s("%d", &mas);
		if (mas < 0 || mas > 5) {
			continue;
		}
		else {
			break;
		}
	}
	
}
void output_train() { //기차 출력
	zom = length - 3;
	cit = length - 6;
	ma = length - 2;
	for (int i = 0; i < length; i++) {
		printf("#");
	}

	printf("\n");

	for (int i = 0; i < length; i++) {
		if (i == zom) {
			printf("Z");
		}
		else if (i == cit) {
			printf("C");
		}
		else if (i == ma) {
			printf("M");
		}
		else if (i == 0 || i == length - 1) {
			printf("#");
		}
		else {
			printf(" ");
		}
	}

	printf("\n");

	for (int i = 0; i < length; i++) {
		printf("#");
	}
}

void output_train_1() { //기차 출력 ( 처음말고 그 다음 )
	for (int i = 0; i < length; i++) {
		printf("#");
	}

	printf("\n");

	for (int i = 0; i < length; i++) {
		if (i == zom) {
			printf("Z");
		}
		else if (i == cit) {
			printf("C");
		}
		else if (i == ma) {
			printf("M");
		}
		else if (i == 0 || i == length - 1) {
			printf("#");
		}
		else {
			printf(" ");
		}
	}

	printf("\n");

	for (int i = 0; i < length; i++) {
		printf("#");
	}
}


void cit_status() { //시민 위치 수정
	move1 = rand() % 100 + 1;
		if ((100 - per) > move1) {
			cit--;
			citloc = cit + 1;
		}
		else {
			citloc = cit;
		}
}


void zom_status() {//좀비 위치 수정 ( 홀수턴마다 )

}

int main() {
	srand((unsigned int)time(NULL));
	intro(); //인트로
	train_length(); // 기차 길이
	madongseok_stamina(); // 마동석 스테미나
	probability_percentage(); // 일어날 확률
	output_train();	 // 기차 출력
	printf("\n");
	printf("\n");
	for(int i=0; i<20; i++) {
		cit_status(); // 시민 위치 수정
		zom_status(); // 좀비 위치 수정
		output_train_1(); // 기차 출력 ( 처음말고 )
		printf("\n");
	}
	
}
