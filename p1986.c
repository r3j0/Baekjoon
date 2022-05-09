//1986. 체스
#include <stdio.h>
int board[1001][1001];
int count;

void queen_go(int y, int x, int max_y, int max_x) {
	int i = 1;
	//1. left
	while (x - i >= 0) {
		if (board[y][x - i] > 0) {
			break;
		}
		else if (board[y][x - i] == 0) {
			board[y][x - i] = -1;
			count--;
		}
		i++;
	}
	//2. left up
	i = 1;
	while (x - i >= 0 && y - i >= 0) {
		if (board[y - i][x - i] > 0) {
			break;
		}
		else if (board[y - i][x - i] == 0) {
			board[y - i][x - i] = -1;
			count--;
		}
		i++;
	}
	//3. up
	i = 1;
	while (y - i >= 0) {
		if (board[y - i][x] > 0) {
			break;
		}
		else if (board[y - i][x] == 0) {
			board[y - i][x] = -1;
			count--;
		}
		i++;
	}
	//4. up right
	i = 1;
	while (y - i >= 0 && x + i < max_x) {
		if (board[y - i][x + i] > 0) {
			break;
		}
		else if (board[y - i][x + i] == 0) {
			board[y - i][x + i] = -1;
			count--;
		}
		i++;
	}
	//5. right
	i = 1;
	while (x + i < max_x) {
		if (board[y][x + i] > 0) {
			break;
		}
		else if (board[y][x + i] == 0) {
			board[y][x + i] = -1;
			count--;
		}
		i++;
	}
	//6. right down
	i = 1;
	while (x + i < max_x && y + i < max_y) {
		if (board[y + i][x + i] > 0) {
			break;
		}
		else if (board[y + i][x + i] == 0) {
			board[y + i][x + i] = -1;
			count--;
		}
		i++;
	}
	//7. down
	i = 1;
	while (y + i < max_y) {
		if (board[y + i][x] > 0) {
			break;
		}
		else if (board[y + i][x] == 0) {
			board[y + i][x] = -1;
			count--;
		}
		i++;
	}
	//8. left down
	i = 1;
	while (x - i >= 0 && y + i < max_y) {
		if (board[y + i][x - i] > 0) {
			break;
		}
		else if (board[y + i][x - i] == 0) {
			board[y + i][x - i] = -1;
			count--;
		}
		i++;
	}
}
void knight_go(int y, int x, int max_y, int max_x) {
	//1. left up
	if (y - 1 >= 0 && y - 1 < max_y && x - 2 >= 0 && x - 2 < max_x) {
		if (board[y - 1][x - 2] == 0) {
			board[y - 1][x - 2] = -1; count--;
		}
	}
	//2. up left
	if (y - 2 >= 0 && y - 2 < max_y && x - 1 >= 0 && x - 1 < max_x) {
		if (board[y - 2][x - 1] == 0) {
			board[y - 2][x - 1] = -1; count--;
		}
	}
	//3. up right
	if (y - 2 >= 0 && y - 2 < max_y && x + 1 >= 0 && x + 1 < max_x) {
		if (board[y - 2][x + 1] == 0) {
			board[y - 2][x + 1] = -1; count--;
		}
	}
	//4. right up
	if (y - 1 >= 0 && y - 1 < max_y && x + 2 >= 0 && x + 2 < max_x) {
		if (board[y - 1][x + 2] == 0) {
			board[y - 1][x + 2] = -1; count--;
		}
	}
	//5. right down
	if (y + 1 >= 0 && y + 1 < max_y && x + 2 >= 0 && x + 2 < max_x) {
		if (board[y + 1][x + 2] == 0) {
			board[y + 1][x + 2] = -1; count--;
		} 
	}
	//6. down right
	if (y + 2 >= 0 && y + 2 < max_y && x + 1 >= 0 && x + 1 < max_x) {
		if (board[y + 2][x + 1] == 0) {
			board[y + 2][x + 1] = -1; count--;
		}
	}
	//7. down left
	if (y + 2 >= 0 && y + 2 < max_y && x - 1 >= 0 && x - 1 < max_x) {
		if (board[y + 2][x - 1] == 0) {
			board[y + 2][x - 1] = -1; count--;
		}
	}
	//8. left down
	if (y + 1 >= 0 && y + 1 < max_y && x - 2 >= 0 && x - 2 < max_x) {
		if (board[y + 1][x - 2] == 0) {
			board[y + 1][x - 2] = -1; count--;
		}
	}
}

int main(void) {
	int n, m;
	int queen_n;
	int queen_l[1001][2]; // x y
	int knight_n;
	int knight_l[1001][2]; // x y
	int pawn_n;
	int pawn_l[1001][2]; // x y

	scanf("%d %d", &n, &m);
	count = n * m;
	scanf("%d", &queen_n);
	for (int i = 0; i < queen_n; i++) {
		scanf("%d %d", &queen_l[i][0], &queen_l[i][1]);
		board[queen_l[i][0]-1][queen_l[i][1]-1] = 1;
		count--;
	}
	scanf("%d", &knight_n);
	for (int i = 0; i < knight_n; i++) {
		scanf("%d %d", &knight_l[i][0], &knight_l[i][1]);
		board[knight_l[i][0]-1][knight_l[i][1]-1] = 2;
		count--;
	}
	scanf("%d", &pawn_n);
	for (int i = 0; i < pawn_n; i++) {
		scanf("%d %d", &pawn_l[i][0], &pawn_l[i][1]);
		board[pawn_l[i][0]-1][pawn_l[i][1]-1] = 3;
		count--;
	}

	for (int i = 0; i < queen_n; i++) {
		queen_go(queen_l[i][0]-1, queen_l[i][1]-1, n, m);
	}
	for (int i = 0; i < knight_n; i++) {
		knight_go(knight_l[i][0]-1, knight_l[i][1]-1, n, m);
	}

	printf("%d", count);
	return 0;
}

