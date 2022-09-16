#include <iostream>
#include <string.h>
#include <vector>

#define N_QUEENS   8
#define BOARD_SIZE 8

using namespace std;

typedef vector<int> row_t;
typedef vector<row_t> matrix_t;

int rows[N_QUEENS]; // the row each queen occupies in column i (0-7)
int max_score = 0;

matrix_t board;

void read_board()
{
    board.clear();
    row_t row(BOARD_SIZE);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            cin >> row[j];
        board.push_back(row);
        cin.ignore(5, '\n');
    }
}

bool is_a_valid_position(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (rows[i] == row || (abs(rows[i] - row) == abs(i - col)))
            return false;
    }

    return true;
}

int score()
{
    int score = 0;
    for (int i = 0; i < N_QUEENS; i++)
        score += board[rows[i]][i]; 

    return score;
}

void backtracking(int col)
{
    if (col == BOARD_SIZE)
    {
        max_score = max(max_score, score());
    }
    else
    {
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            if (is_a_valid_position(row, col))
            {
                rows[col] = row;
                backtracking(col + 1);
            }
        }
    }
}

void test_board()
{
    read_board();
    
    memset(rows, 0, N_QUEENS * sizeof(int));
    max_score = 0;

    backtracking(0);

    printf ("%5d\n", max_score);
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
        test_board();
    
    return 0;
}