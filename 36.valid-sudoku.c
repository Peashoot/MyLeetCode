/*
 * @lc app=leetcode id=36 lang=c
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (42.45%)
 * Total Accepted:    227.1K
 * Total Submissions: 533.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */

bool is1To9(char *chrArr)
{
    int arr[9];
    memset(arr, 0, 9 * sizeof(int));
    for (int i = 0; i < 9; i++)
    {
        if (chrArr[i] > '0' && chrArr[i] <= '9')
        {
            if (arr[chrArr[i] - '1'] > 0)
            {
                return false;
            }
            arr[chrArr[i] - '1']++;
        }
        else if (chrArr[i] == '.')
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool isValidSudoku(char** board, int boardRowSize, int *boardColSizes) {
    // if (boardRowSize < 9)
    // {
    //     return false;
    // }
    // for (int i = 0; i < boardRowSize; i++)
    // {
    //     if (boardColSizes[i] < 9)
    //     {
    //         return false;
    //     }
    // }
    for (int i = 0; i < 9; i++)
    {
        char landscape[9], vertial[9], block[9];
        for (int j = 0; j < 9; j++)
        {
            landscape[j] = board[i][j];
            vertial[j] = board[j][i];
            block[j] = board[3 * (i % 3) + j / 3][3 * (i / 3) + j % 3];
        }
        if (!(is1To9(landscape) && is1To9(vertial) && is1To9(block)))
        {
            return false;
        }
    }
    return true;
}

