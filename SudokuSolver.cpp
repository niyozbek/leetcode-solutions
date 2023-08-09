// Problem 37. Sudoku Solver (https://leetcode.com/problems/sudoku-solver/description/)

class Solution {
public:
    vector<vector<vector<char>>> solutions;

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuBacktrack(board);
        board = solutions[0];
    }

    void solveSudokuBacktrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char value = '1'; value <= '9'; value++) {
                        if (isValidEntry(board, i, j, value)) {
                            board[i][j] = value;
                            solveSudokuBacktrack(board);
                            board[i][j] = '.';
                        }
                    }
                    return; // loop until we find '.'
                }
            }
        }
        // if all fields are filled
        vector<vector<char>> solution(board); 
        solutions.push_back(solution);
        // printSudoku(board);
    }

    void printSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    bool isValidEntry(vector<vector<char>>& board, int row, int col, char value) {
        // column check
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == value) return false;
        }

        // row check
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == value) return false;
        }

        // box check
        // 0 => 0; 2 => 0; 3 => 3, 5 => 3; 6 => 6; 8 => 6 
        int box_i = row / 3 * 3;
        int box_j = col / 3 * 3;
        for (int i = box_i; i < box_i + 3; i++) {
            for (int j = box_j; j < box_j + 3; j++) {
                if (board[i][j] == value) return false;
            }
        }

        return true;
    }
};
