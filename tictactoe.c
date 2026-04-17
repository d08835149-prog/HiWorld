#include <stdio.h>

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char mark; // 'X' 또는 'O'

// 보드 그리기 함수
void drawBoard() {
    printf("\n--- Tic Tac Toe ---\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

// 승리 조건 체크 (1이면 승리, 0이면 진행 중, -1이면 무승부)
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // 가로, 세로 체크
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // 대각선 체크
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    // 무승부 체크 (빈 공간이 있는지 확인)
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') count++;
    
    if (count == 0) return -1;
    return 0;
}

int main() {
    int player = 1, choice, row, col, status;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("플레이어 %d, 번호를 선택하세요: ", player);
        scanf("%d", &choice);

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("잘못된 이동입니다! 다시 선택하세요.\n");
            player--;
        } else {
            board[row][col] = mark;
        }

        status = checkWin();
        player++;
    } while (status == 0);

    drawBoard();
    if (status == 1) printf("==> 플레이어 %d 승리!\n", --player);
    else printf("==> 무승부입니다!\n");

    return 0;
}
