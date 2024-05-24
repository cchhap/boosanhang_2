#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

// �Ķ����
#define LEN_MIN 15 // ���� ����
#define LEN_MAX 50
#define STM_MIN 0 // ������ ü��
#define STM_MAX 5
#define PROB_MIN 10 // Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 // ��׷� ����
#define AGGRO_MAX 5
// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0
// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
// ������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2


//2-1 �λ���(1)�ڵ带 20�� �̳��� �Լ��� �����Ѵ� ( ������� �Ѿ�� �ȴٰ� �Ͻ� )
int zom = 0; int cit = 0; int ma = 0; int length = 0; int per = 0; int move1 = 0; int move2 = 0; int turn = 0; int citloc = 0; int zomloc = 0; int mas = 0;//��������
int aggro = 1; int si = 0; int zo = 0; int ma_aggro = 1; int ma_move_1 = 0;

void intro() {
	printf("\n----------------------\n"); //��Ʈ��
	printf("\nBooSanHang\n");
	printf("\n-start now-\n");
	printf("\n----------------------\n");
	printf("\n\n");
}

void train_length() { //������ ���� �Է¹ޱ�
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

void probability_percentage() { //���𰡰� �Ͼ Ȯ��
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

void madongseok_stamina() { //������ ü��
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
void output_train() { //���� ���
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

void output_train_1() { //���� ��� ( ó������ �� ���� )
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


void cit_status() { //�ù� ��ġ ����
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


void zom_status() {//���� ��ġ ���� ( Ȧ���ϸ��� )
	if (turn % 2 != 0) {
		zom--;
		zomloc = zom + 1;
	}
}

void status() { //����� �ù��� ����ġ
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
	intro(); //��Ʈ��
	train_length(); // ���� ����
	madongseok_stamina(); // ������ ���׹̳�
	probability_percentage(); // �Ͼ Ȯ��
	output_train();	 // ���� ���
	printf("\n");
	printf("\n");
	for(int i=0; i<20; i++) {
		turn++; // ������
		cit_status(); // �ù� ��ġ ����
		zom_status(); // ���� ��ġ ����
		output_train_1(); // ���� ��� ( ó������ )
		status(); // �ù�, ���� ��ġ
		ma_move(); // ������ �̵�
		output_train_1(); // �������
		ma_status(); //������ ��ġ
		printf("\n");
	}
	
}
