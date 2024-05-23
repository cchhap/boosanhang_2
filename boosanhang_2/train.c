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


//2-1 �λ���(1)�ڵ带 20�� �̳��� �Լ��� �����Ѵ�
int zom, cit, ma, length, per, move1 = 0, move2 = 0, turn = 0, citloc = 0, zomloc = 0, mas = 0;//��������

void intro() {
	printf("\n----------------------\n"); //��Ʈ��
	printf("\nBooSanHang\n");
	printf("\n-start now-\n");
	printf("\n----------------------\n");
	Sleep(2000);
	printf("\n\n");
}

void train_length() { //������ ���� �Է¹ޱ�
	printf("train_length>>");
	scanf_s("%d", &length);
	if (length < 15 || length>50) {
		return 0;
	}
}

void probability_percentage() { //���𰡰� �Ͼ Ȯ��
	printf("probability_percentage>>");
	scanf_s("%d", &per);
	if (per < 10 || per > 90) {
		return 0;
	}
}

void madongseok_stamina() { //������ ü��
	printf("madongseok_stamina(0~5)>>");
	scanf_s("%d", &mas);
	if (mas < 0 || mas > 5) {
		return 0;
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

	for (int i = 0; i < length; i++) { // ������ ó�� �������
		printf("#");
	}
}

int main() {
	zom = length - 3;
	cit = length - 6;
	ma = length - 2;
	intro();
	train_length();
	madongseok_stamina();
	probability_percentage();
	output_train();	
}
