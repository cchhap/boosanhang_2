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
int aggro = 1; int si = 0; int zo = 0; int ma_aggro = 1; int ma_move_1 = 0; int over = 0; int hold = 0; int pull = 0; int zomma = 0; int zomma_1;

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


void zom_status() {//���� ��ġ ���� ( Ȧ���ϸ��� )
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

void status() { //����� �ù��� ����ġ
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

void ma_move() { // ������ �������� ������ �Է¹ޱ�
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

void ma_status() { //������ ����
	if (ma_move_1 == 0) {
		printf("\nmadongseok stay %d (aggro: %d stamina: %d) \n", ma,ma_aggro, mas);
	}
	else if (ma_move_1 == 1) {
		printf("\nmadongseok action %d (aggro: %d stamina: %d)\n ", ma,ma_aggro, mas);
	}
}

void game_over() { //���� �����°�
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

//������ ���׹̳� ���̴°�
void ma_hurt() {
	if (ma == zom - 1) {
		mas--;
	}
}

//������ ���׹̳� �ȳ������� �ϴ°�
void mas_no_0() {
	if (ma_aggro < AGGRO_MIN) {
		ma_aggro = AGGRO_MIN;
	}
	else if(ma_aggro > AGGRO_MAX) {
		ma_aggro = AGGRO_MAX;
	}
}

//Ȧ�� �� Ȯ��
void grab(){
	hold = rand() % 100 + 1;
}

void citizen_nothing() { // �ù��� �ƹ��͵� ���� �ʾҽ��ϴ�
	if (cit != 1) {
		printf("citizen does nothing");
	}
}

void zombie_attack() { // ���� ���� �޽���
	if (zom - 1 != cit || zom - 1 != ma) {
		printf("zombie attacked nobody");
	}
	else if (zom == ma+1) {
		printf("Zombie attacked madongseok(aggro:%d, madongseok stamina: %d -> %d", ma_aggro,mas+1,mas);
	}
}

// �������� ����� �������� ��
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

// �������� ����� �������� �ʾ��� ��
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
	intro(); //��Ʈ��
	train_length(); // ���� ����
	madongseok_stamina(); // ������ ���׹̳�
	probability_percentage(); // �Ͼ Ȯ��
	output_train();	 // ���� ���
	printf("\n");
	printf("\n");
	while(1) {
		turn++; // ������
		cit_status(); // �ù� ��ġ ����
		zom_status(); // ���� ��ġ ����
		output_train_1(); // ���� ��� ( ó������ )
		status(); // �ù�, ���� ��ġ
		game_over(); // ���ӿ������� �ƴ��� ��� �˻�
		if (over == 1) {
			break;
		}
		ma_move(); // ������ �̵�
		mas_no_0(); //�������� ���¹̳� ����
		ma_hurt(); // �������� �¾Ҵ��� �ƴ��� ����
		printf("\n");
		zombie_ma(); //����� ������ ��
		no_zombie_ma(); // ����� �������� ���� ��
		printf("\n");
		printf("\n");
		output_train_1();
		printf("\n");
		ma_status(); //������ ��ġ
		printf("\n");
		citizen_nothing(); // �ù� �ƹ��͵� ���ߴ�
		printf("\n");
		zombie_attack(); // ���� �����ߴ�
		printf("\n");
	}
	
}
