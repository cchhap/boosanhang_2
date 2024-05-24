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
int aggro = 1; int si = 0; int zo = 0; int ma_aggro = 1; int ma_move_1 = 0;

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
			aggro++;
			if (aggro < 0) {
				aggro = 0;
			}
			else if (aggro > 5) {
				aggro = 5;
			}
			si = 0;
		}
		else {
			citloc = cit;
			aggro--;
			si = 1;
			if (aggro < 0) {
				aggro = 0;
			}
			else if (aggro > 5) {
				aggro = 5;
			}
		}
}


void zom_status() {//좀비 위치 수정 ( 홀수턴마다 )
	if (turn % 2 != 0) {
		zom--;
		zomloc = zom + 1;
	}
}

void status() { //좀비와 시민의 현위치
	if (si == 0 && turn % 2 == 0) {
		printf("\n");
		printf("citizen: %d -> %d (aggro: %d)\n", citloc, cit, aggro);
		printf("zombie: %d",zom);
		printf("\n");
	}
	else if (si == 0 && turn % 2 != 0) {
		printf("\n");
		printf("citizen: %d -> %d (aggro: %d)\n", citloc, cit, aggro);
		printf("zombie: %d -> %d", zomloc, zom);
		printf("\n");
	}
	else if (si == 1 && turn % 2 == 0) {
		printf("\n");
		printf("citizen: %d (aggro: %d)\n", cit, aggro);
		printf("zombie: %d", zom);
		printf("\n");
	}
	else if (si == 1 && turn % 2 != 0) {
		printf("\n");
		printf("citizen: %d  (aggro: %d)\n",cit, aggro);
		printf("zombie: %d -> %d", zomloc, zom);
		printf("\n");
	}
}
void ma_move() {
	while (1) {
		printf("madongseok move(0:stay, 1:left)>>");
		scanf_s("%d", &ma_move_1);
		if (ma_move_1 == 0) {
			ma_aggro--;
			break;
		}
		else if (ma_move_1 == 1) {
			mas--;
			ma--;
			ma_aggro++;
			break;
		}
		else {
			continue;
		}
	}
}

void ma_status() {
	if (ma_move_1 == 0) {
		printf("\nmadongseok stay %d (aggro: %d stamina: %d) \n", ma,ma_aggro, mas);
	}
	else if (ma_move_1 == 1) {
		printf("\nmadongseok action %d (aggro: %d stamina: %d)\n ", ma,ma_aggro, mas);
	}
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
		turn++; // 턴증가
		cit_status(); // 시민 위치 수정
		zom_status(); // 좀비 위치 수정
		output_train_1(); // 기차 출력 ( 처음말고 )
		status(); // 시민, 좀비 위치
		ma_move(); // 마동석 이동
		output_train_1(); // 기차출력
		ma_status(); //마동석 위치
		printf("\n");
	}
	
}
