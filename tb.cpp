#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 6	//最大支持人数
#define ATTN 11	//属性数量

int Player[N][ATTN];
int n_player = -1;
// 战斗属性
const int ZD_HP = 0;//血量
const int ZD_DEX = 1;//战斗敏捷
const int ZD_FANJI = 2;//格斗、反击
const int ZD_SHANBI = 3;//战斗闪避
const int ZD_YILIAO = 4;// 医疗
const int ZD_TIZHI = 5;//体质
const int ZD_SHJZ = 6;//伤害加值
const int ZD_JIJIU = 7;//急救

// 追击属性
const int RUN_MOVE = 8;//追击移速
const int RUN_PANPA = 9;//追击攀爬
const int RUN_JUMP = 10;//追击跳跃

const char* Name(int id) {
	if (id == 0)return "血量";
	if (id == 1)return "敏捷";
	if (id == 2)return "反击";
	if (id == 3)return "闪避";
	if (id == 4)return "医疗";
	if (id == 5)return "体质";
	if (id == 6)return "增伤";
	if (id == 7)return "急救";
	if (id == 8)return "移速";
	if (id == 9)return "攀爬";
	if (id == 10)return "跳跃";
	return "未知";
}

void input_player_info() {
	printf("请输入游戏人数:");
	scanf("%d", &n_player);
	if (n_player < 2 || n_player > N) {
		printf("游戏需要2~%d人，您输入了%d\n", N, n_player);
		return;
	}
	printf("请依次以血量，敏捷，格斗，闪避, 医疗，体质，伤害加值，急救，移速，攀爬，跳跃输入人物属性\n");
	for (int i = 0; i < n_player; i++) {
		printf("请输入第%d个人的属性:\n", i);
		for (int j = 0; j < ATTN; j++) {
			scanf("%d", &Player[i][j]);
		}
	}
	printf("输入成功\n");
}

int random_int(int min, int max) {
	return (rand() % (max + 1 - min)) + min;
}

//追击模式
void trace_mode() {
	int move[2] = { 1,  Player [1][RUN_MOVE]- Player [0][RUN_MOVE] + 1};
	int pos[2] = { 0, 2 };
	int player = 1;
	int val;
	do {
		printf("=======================\n");
		printf("玩家0位置:%d\n", pos[0]);
		printf("玩家1位置:%d\n", pos[1]);
		printf("距离:%d\n", pos[1] - pos[0]);
		printf("=======================\n");
		int moved = 0;
		for (int i = 0; i < move[player]; i++) {
			printf("玩家%d，请输入1进行下一步行动（剩余行动力:%d）\n", player, move[player]-i);
			scanf("%d", &val);
			if (val != 1) {
				printf("无效输入\n");
				continue;
			}
			int action = random_int(RUN_MOVE, RUN_JUMP);
			printf("出现障碍,需要:%s，%d", Name(action), action);
			int point = random_int(1, 100);
			if (point < Player[player][action]) {
				pos[player]++;
				moved++;
				printf("判定值(%d)，判定成功，前进一步\n", point);
			}
			else {
				printf("判定值(%d)，判定失败，停在原地\n", point);
			}
		}
		printf("玩家%d前进了%d步\n", player, moved);
		player = (player == 0) ? 1 : 0;
	}
	while (pos[1] - pos[0] >= 1);
}

// 按照战斗敏捷度排序
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

// 输出所有玩家的状态
void print_player_info() {
	printf("血量 敏捷 格斗 闪避 医疗 体质 增伤 急救 移速 攀爬 跳跃\n");
	for (int i = 0; i < n_player; i++) {
		for (int j = 0; j < ATTN; j++) {
			printf("%-5d", Player[i][j]);
		}
		printf("\n");
	}
}

// 多人对战模式
void pvps_mode() {
	printf("战斗模式\n");
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
			printf("当前行动玩家:%d，已经死亡，跳过回合\n", player);
			player++;
			continue;
		}
		printf("当前行动玩家:%d\n", player);
		if (dying[player]) {
			point = random_int(1, 100);
			printf("玩家处于濒死状态，判断值（%d）,", point);
			if (point >= Player[player][ZD_TIZHI]) {
				printf("玩家%d死亡\n", player);
				dead[player] = 1;
				lives--;
			}
			continue;
		}
		int act = 0;
		while(1) {
			printf("请输入采取的行动: 0.攻击 1.医疗 2.急救\n");
			scanf("%d", &act);
			if (act == 0 || act == 1|| act == 2) {
				break;
			}
			else {
				printf("输入无效\n");
			}
		}
		int level = random_int(1, 100);
		if (level > Player[player][MD[act]]) {
			printf("判定值（%d），判定失败!\n", level);
			level = 1;
			player++;
			continue;
		}else if (level > Player[player][MD[act]] / 2) {
			printf("判定值（%d），普通成功\n",level);
			level = 2;
		}else if (level > Player[player][MD[act]] / 3) {
			printf("判定值（%d），困难成功\n", level);
			level = 3;
		}else{
			printf("判定值（%d），极难成功\n", level);
			level = 4;
		}
		int index;
		if (act == 0) {
			// 攻击者选择行动
			while (1) {
				printf("请输入要攻击的玩家:\n");
				scanf("%d", &index);
				if (dying[index]) {
					printf("你不能攻击濒死的玩家\n");
				}
				else if (dead[index]) {
					printf("你不能攻击已经死亡的玩家\n");
				}
				else {
					break;
				}
			}

			// 被攻击者随机防守
			int defen_lv;
			act = random_int(2, 3);
			printf("防守者触发%s，", Name(act));
			defen_lv = random_int(1, 100);
			if (defen_lv > Player[index][act]) {
				printf("判定值（%d），判定失败!\n", defen_lv);
				defen_lv = 1;
			}
			else if (defen_lv > Player[index][act] / 2) {
				printf("判定值（%d），普通成功\n", defen_lv);
				defen_lv = 2;
			}
			else if (defen_lv > Player[index][act] / 3) {
				printf("判定值（%d），困难成功\n", defen_lv);
				defen_lv = 3;
			}
			else {
				printf("判定值（%d），极难成功\n", defen_lv);
				defen_lv = 4;
			}
			if (defen_lv > level) {
				printf("玩家%d防守成功!\n", index);
				if (act == ZD_FANJI) {
					int damage = random_int(1, 3);
					for (int i = 0; i < Player[player][ZD_SHJZ]; i++) {
						damage += random_int(1, 4);
					}
					Player[player][ZD_HP] -= damage;//收到反击伤害
					printf("玩家%d受到反击伤害%d，剩余生命值%d", player, damage, Player[player][ZD_HP]);
					if (Player[player][ZD_HP] < 0) {
						// 玩家被攻击至濒死状态
						Player[player][ZD_HP] = 1;
						dying[player] = 1;
						printf(",玩家%d进入濒死状态\n", player);
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
				printf("玩家%d受到伤害%d，剩余生命值%d", index, damage, Player[index][ZD_HP]);
				if (Player[index][ZD_HP] < 0) {
					// 玩家被攻击至濒死状态
					Player[index][ZD_HP] = 1;
					dying[index] = 1;
					printf(",玩家%d进入濒死状态\n", index);
				}
				printf("\n");
			}
		}else if(act==1){
			// 医疗
			while (1) {
				printf("请输入要治疗的对象:\n");
				scanf("%d", &index);
				if (dying[index] || dead[index]) {
					printf("你不能治疗濒死或者已经死亡的对象\n");
				}
				else {
					break;
				}
			}
			int point = random_int(1, 100);
			if (point > Player[player][ZD_YILIAO]) {
				printf("判定值（%d），判定失败\n", point);
				player++;
				continue;
			}
			else {
				printf("判定值（%d），判定成功\n", point);
				int cure = 0;
				if (Player[index][ZD_HP] + Player[player][ZD_YILIAO] > 100) {
					cure = 100 - Player[index][ZD_HP];
					Player[index][ZD_HP] = 100;
				}
				else {
					cure = Player[player][ZD_YILIAO];
					Player[index][ZD_HP] += Player[player][ZD_YILIAO];
				}
				printf("玩家%d受到%d点治疗\n", index, cure);
			}
		}
		else {
			// 急救
			while (1) {
				printf("请输入要急救的对象:\n");
				scanf("%d", &index);
				if (!dying[index]) {
					printf("你不能对没有濒死的对象进行急救\n");
				}
				else {
					break;
				}
			}
			int point = random_int(1, 100);
			if (point > Player[player][ZD_JIJIU]) {
				printf("判定值（%d），判定失败\n", point);
				player++;
				continue;
			}
			else {
				printf("判定值（%d），判定成功\n", point);
				int cure = 0;
				cure = Player[player][ZD_YILIAO];
				Player[index][ZD_HP] += Player[player][ZD_YILIAO];
				printf("玩家%d受到急救，血量回复%d\n", index, cure);
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
