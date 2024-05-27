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
int aggro = 1; int si = 0; int zo = 0; int ma_aggro = 1; int ma_move_1 = 0; int over = 0; int hold = 0; int pull = 0; int zomma = 0; int zomma_1;

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
			if (aggro < AGGRO_MIN) {
				aggro = AGGRO_MIN;
			}
			else if (aggro > AGGRO_MAX) {
				aggro = AGGRO_MAX;
			}
			si = 0;
		}
		else {
			citloc = cit;
			aggro--;
			si = 1;
			if (aggro < AGGRO_MIN) {
				aggro = AGGRO_MIN;
			}
			else if (aggro > AGGRO_MAX) {
				aggro = AGGRO_MAX;
			}
		}
}


void zom_status() {//좀비 위치 수정 ( 홀수턴마다 )
	zomloc = zom;
	if (turn % 2 != 0) {
		if (zom + 1 == ma) {
			zom--;
		}
		else {
			if (aggro > ma_aggro) {
				zom--;
			}
			else if (ma_aggro > aggro) {
				zom++;
			}
			zomloc = zom + 1;
		}
	}
	
}

void status() { //좀비와 시민의 현위치
	if (si == 0 && turn % 2 == 0) {
		printf("\n");
		printf("citizen: %d -> %d (aggro: %d)\n", citloc, cit, aggro);
		printf("zombie: %d ( cannot move )",zom);
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
		printf("zombie: %d ( cannot move )", zom);
		printf("\n");
	}
	else if (si == 1 && turn % 2 != 0) {
		printf("\n");
		printf("citizen: %d  (aggro: %d)\n",cit, aggro);
		printf("zombie: %d -> %d", zomloc, zom);
		printf("\n");
	}
}

void ma_move() { // 마동석 움직일지 안할지 입력받기
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

void ma_status() { //마동석 상태
	if (ma_move_1 == 0) {
		printf("\nmadongseok stay %d (aggro: %d stamina: %d) \n", ma,ma_aggro, mas);
	}
	else if (ma_move_1 == 1) {
		printf("\nmadongseok action %d (aggro: %d stamina: %d)\n ", ma,ma_aggro, mas);
	}
}

void game_over() { //게임 끝나는거
	if (cit == 1) {
		printf("YOU WIN! ...");
		over = 1;
	}
	else if (cit == zom - 1) {
		printf("GAME OVER! citizen dead...");
		over = 1;
	}
	else if (mas == 0) {
		printf("GAME OVER!citizen dead...");
		over = 1;
	}
}

//마동석 스테미나 깎이는거
void ma_hurt() {
	if (ma == zom - 1) {
		mas--;
	}
}

//마동석 스테미나 안내려가게 하는거
void mas_no_0() {
	if (ma_aggro < AGGRO_MIN) {
		ma_aggro = AGGRO_MIN;
	}
	else if(ma_aggro > AGGRO_MAX) {
		ma_aggro = AGGRO_MAX;
	}
}

//홀드 할 확률
void grab(){
	hold = rand() % 100 + 1;
}

void citizen_nothing() { // 시민은 아무것도 하지 않았습니다
	if (cit != 1) {
		printf("citizen does nothing");
	}
}

void zombie_attack() { // 좀비 공격 메시지
	if (zom - 1 != cit || zom - 1 != ma) {
		printf("zombie attacked nobody");
	}
	else if (zom == ma+1) {
		printf("Zombie attacked madongseok(aggro:%d, madongseok stamina: %d -> %d", ma_aggro,mas+1,mas);
	}
}

// 동석이형 좀비와 인접했을 떄
void zombie_ma() {
	if (zom + 1 == ma) {
		printf("madongseok action( 0.rest, 1.provoke, 2.pull)>>");
		scanf_s("%d", &zomma);
		if (zomma == 0) {
			ma_aggro--;
			mas++;
		}
		else if (zomma == 1) {
			ma_aggro = STM_MAX;
		}
		else if (zomma == 2) {
			if ((100 - per) > hold) {
				turn--;
			}
		}
	}
}

// 동석이형 좀비랑 인접하지 않았을 때
void no_zombie_ma() {
	printf("madongseok action( 0.rest, 1.provoke )>>");
	scanf_s("%d", &zomma_1);
	if (zomma_1 == 0) {
		ma_aggro--;
		mas++;
	}
	else if (zomma_1 == 1) {
		ma_aggro = STM_MAX;
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
	while(1) {
		turn++; // 턴증가
		cit_status(); // 시민 위치 수정
		zom_status(); // 좀비 위치 수정
		output_train_1(); // 기차 출력 ( 처음말고 )
		status(); // 시민, 좀비 위치
		game_over(); // 게임오버인지 아닌지 계속 검사
		if (over == 1) {
			break;
		}
		ma_move(); // 마동석 이동
		mas_no_0(); //동석이형 스태미나 관리
		ma_hurt(); // 동석이형 맞았는지 아닌지 보기
		printf("\n");
		zombie_ma(); //좀비랑 인접할 때
		no_zombie_ma(); // 좀비랑 인접하지 않을 때
		printf("\n");
		printf("\n");
		output_train_1();
		printf("\n");
		ma_status(); //마동석 위치
		printf("\n");
		citizen_nothing(); // 시민 아무것도 안했다
		printf("\n");
		zombie_attack(); // 좀비 공격했다
		printf("\n");
	}
	
}
