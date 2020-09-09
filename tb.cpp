#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 6	//���֧������
#define ATTN 11	//��������

int Player[N][ATTN];
int n_player = -1;
// ս������
const int ZD_HP = 0;//Ѫ��
const int ZD_DEX = 1;//ս������
const int ZD_FANJI = 2;//�񶷡�����
const int ZD_SHANBI = 3;//ս������
const int ZD_YILIAO = 4;// ҽ��
const int ZD_TIZHI = 5;//����
const int ZD_SHJZ = 6;//�˺���ֵ
const int ZD_JIJIU = 7;//����

// ׷������
const int RUN_MOVE = 8;//׷������
const int RUN_PANPA = 9;//׷������
const int RUN_JUMP = 10;//׷����Ծ

const char* Name(int id) {
	if (id == 0)return "Ѫ��";
	if (id == 1)return "����";
	if (id == 2)return "����";
	if (id == 3)return "����";
	if (id == 4)return "ҽ��";
	if (id == 5)return "����";
	if (id == 6)return "����";
	if (id == 7)return "����";
	if (id == 8)return "����";
	if (id == 9)return "����";
	if (id == 10)return "��Ծ";
	return "δ֪";
}

void input_player_info() {
	printf("��������Ϸ����:");
	scanf("%d", &n_player);
	if (n_player < 2 || n_player > N) {
		printf("��Ϸ��Ҫ2~%d�ˣ���������%d\n", N, n_player);
		return;
	}
	printf("��������Ѫ�������ݣ��񶷣�����, ҽ�ƣ����ʣ��˺���ֵ�����ȣ����٣���������Ծ������������\n");
	for (int i = 0; i < n_player; i++) {
		printf("�������%d���˵�����:\n", i);
		for (int j = 0; j < ATTN; j++) {
			scanf("%d", &Player[i][j]);
		}
	}
	printf("����ɹ�\n");
}

int random_int(int min, int max) {
	return (rand() % (max + 1 - min)) + min;
}

//׷��ģʽ
void trace_mode() {
	int move[2] = { 1,  Player [1][RUN_MOVE]- Player [0][RUN_MOVE] + 1};
	int pos[2] = { 0, 2 };
	int player = 1;
	int val;
	do {
		printf("=======================\n");
		printf("���0λ��:%d\n", pos[0]);
		printf("���1λ��:%d\n", pos[1]);
		printf("����:%d\n", pos[1] - pos[0]);
		printf("=======================\n");
		int moved = 0;
		for (int i = 0; i < move[player]; i++) {
			printf("���%d��������1������һ���ж���ʣ���ж���:%d��\n", player, move[player]-i);
			scanf("%d", &val);
			if (val != 1) {
				printf("��Ч����\n");
				continue;
			}
			int action = random_int(RUN_MOVE, RUN_JUMP);
			printf("�����ϰ�,��Ҫ:%s��%d", Name(action), action);
			int point = random_int(1, 100);
			if (point < Player[player][action]) {
				pos[player]++;
				moved++;
				printf("�ж�ֵ(%d)���ж��ɹ���ǰ��һ��\n", point);
			}
			else {
				printf("�ж�ֵ(%d)���ж�ʧ�ܣ�ͣ��ԭ��\n", point);
			}
		}
		printf("���%dǰ����%d��\n", player, moved);
		player = (player == 0) ? 1 : 0;
	}
	while (pos[1] - pos[0] >= 1);
}

// ����ս�����ݶ�����
void sort_by_ZD_DEX() {
	for (int i = 0; i < n_player; i++) {
		for (int j = 0; j < n_player - i - 1; j++) {
			if (Player[j][ZD_DEX] < Player[j + 1][ZD_DEX]) {
				int t[N];
				memmove(t, Player[j], sizeof(int) * N);
				memmove(Player[j], Player[j + 1], sizeof(int) * N);
				memmove(Player[j + 1], t, sizeof(int) * N);
			}
		}
	}
}

// ���������ҵ�״̬
void print_player_info() {
	printf("Ѫ�� ���� �� ���� ҽ�� ���� ���� ���� ���� ���� ��Ծ\n");
	for (int i = 0; i < n_player; i++) {
		for (int j = 0; j < ATTN; j++) {
			printf("%-5d", Player[i][j]);
		}
		printf("\n");
	}
}

// ���˶�սģʽ
void pvps_mode() {
	printf("ս��ģʽ\n");
	sort_by_ZD_DEX();
	print_player_info();
	int player = 0;
	int lives = n_player;
	int MD[] = {2,4,7};
	int dying[N] = {0};
	int dead[N] = {0};
	int point;

	while (lives > 1) {
		printf("===================================\n");
		print_player_info();
		printf("===================================\n");
		player = player % n_player;
		if (dead[player]) {
			printf("��ǰ�ж����:%d���Ѿ������������غ�\n", player);
			player++;
			continue;
		}
		printf("��ǰ�ж����:%d\n", player);
		if (dying[player]) {
			point = random_int(1, 100);
			printf("��Ҵ��ڱ���״̬���ж�ֵ��%d��,", point);
			if (point >= Player[player][ZD_TIZHI]) {
				printf("���%d����\n", player);
				dead[player] = 1;
				lives--;
			}
			continue;
		}
		int act = 0;
		while(1) {
			printf("�������ȡ���ж�: 0.���� 1.ҽ�� 2.����\n");
			scanf("%d", &act);
			if (act == 0 || act == 1|| act == 2) {
				break;
			}
			else {
				printf("������Ч\n");
			}
		}
		int level = random_int(1, 100);
		if (level > Player[player][MD[act]]) {
			printf("�ж�ֵ��%d�����ж�ʧ��!\n", level);
			level = 1;
			player++;
			continue;
		}else if (level > Player[player][MD[act]] / 2) {
			printf("�ж�ֵ��%d������ͨ�ɹ�\n",level);
			level = 2;
		}else if (level > Player[player][MD[act]] / 3) {
			printf("�ж�ֵ��%d�������ѳɹ�\n", level);
			level = 3;
		}else{
			printf("�ж�ֵ��%d�������ѳɹ�\n", level);
			level = 4;
		}
		int index;
		if (act == 0) {
			// ������ѡ���ж�
			while (1) {
				printf("������Ҫ���������:\n");
				scanf("%d", &index);
				if (dying[index]) {
					printf("�㲻�ܹ������������\n");
				}
				else if (dead[index]) {
					printf("�㲻�ܹ����Ѿ����������\n");
				}
				else {
					break;
				}
			}

			// ���������������
			int defen_lv;
			act = random_int(2, 3);
			printf("�����ߴ���%s��", Name(act));
			defen_lv = random_int(1, 100);
			if (defen_lv > Player[index][act]) {
				printf("�ж�ֵ��%d�����ж�ʧ��!\n", defen_lv);
				defen_lv = 1;
			}
			else if (defen_lv > Player[index][act] / 2) {
				printf("�ж�ֵ��%d������ͨ�ɹ�\n", defen_lv);
				defen_lv = 2;
			}
			else if (defen_lv > Player[index][act] / 3) {
				printf("�ж�ֵ��%d�������ѳɹ�\n", defen_lv);
				defen_lv = 3;
			}
			else {
				printf("�ж�ֵ��%d�������ѳɹ�\n", defen_lv);
				defen_lv = 4;
			}
			if (defen_lv > level) {
				printf("���%d���سɹ�!\n", index);
				if (act == ZD_FANJI) {
					int damage = random_int(1, 3);
					for (int i = 0; i < Player[player][ZD_SHJZ]; i++) {
						damage += random_int(1, 4);
					}
					Player[player][ZD_HP] -= damage;//�յ������˺�
					printf("���%d�ܵ������˺�%d��ʣ������ֵ%d", player, damage, Player[player][ZD_HP]);
					if (Player[player][ZD_HP] < 0) {
						// ��ұ�����������״̬
						Player[player][ZD_HP] = 1;
						dying[player] = 1;
						printf(",���%d�������״̬\n", player);
					}
					printf("\n");
				}
			}
			else {
				int damage = random_int(1, 3);
				for (int i = 0; i < Player[player][ZD_SHJZ]; i++) {
					damage += random_int(1, 4);
				}
				Player[index][ZD_HP] -= damage;
				printf("���%d�ܵ��˺�%d��ʣ������ֵ%d", index, damage, Player[index][ZD_HP]);
				if (Player[index][ZD_HP] < 0) {
					// ��ұ�����������״̬
					Player[index][ZD_HP] = 1;
					dying[index] = 1;
					printf(",���%d�������״̬\n", index);
				}
				printf("\n");
			}
		}else if(act==1){
			// ҽ��
			while (1) {
				printf("������Ҫ���ƵĶ���:\n");
				scanf("%d", &index);
				if (dying[index] || dead[index]) {
					printf("�㲻�����Ʊ��������Ѿ������Ķ���\n");
				}
				else {
					break;
				}
			}
			int point = random_int(1, 100);
			if (point > Player[player][ZD_YILIAO]) {
				printf("�ж�ֵ��%d�����ж�ʧ��\n", point);
				player++;
				continue;
			}
			else {
				printf("�ж�ֵ��%d�����ж��ɹ�\n", point);
				int cure = 0;
				if (Player[index][ZD_HP] + Player[player][ZD_YILIAO] > 100) {
					cure = 100 - Player[index][ZD_HP];
					Player[index][ZD_HP] = 100;
				}
				else {
					cure = Player[player][ZD_YILIAO];
					Player[index][ZD_HP] += Player[player][ZD_YILIAO];
				}
				printf("���%d�ܵ�%d������\n", index, cure);
			}
		}
		else {
			// ����
			while (1) {
				printf("������Ҫ���ȵĶ���:\n");
				scanf("%d", &index);
				if (!dying[index]) {
					printf("�㲻�ܶ�û�б����Ķ�����м���\n");
				}
				else {
					break;
				}
			}
			int point = random_int(1, 100);
			if (point > Player[player][ZD_JIJIU]) {
				printf("�ж�ֵ��%d�����ж�ʧ��\n", point);
				player++;
				continue;
			}
			else {
				printf("�ж�ֵ��%d�����ж��ɹ�\n", point);
				int cure = 0;
				cure = Player[player][ZD_YILIAO];
				Player[index][ZD_HP] += Player[player][ZD_YILIAO];
				printf("���%d�ܵ����ȣ�Ѫ���ظ�%d\n", index, cure);
			}
		}
		player++;
	}
}

int main()
{
	srand((unsigned int)(time(0)));
	freopen("input.txt", "r", stdin);
	input_player_info();
	fclose(stdin);
	freopen("CON", "r", stdin);
	print_player_info();
	if (n_player == 2) {
		trace_mode();
	}
	pvps_mode();
	return 0;
}
