/*
 * @lc app=leetcode id=40 lang=c
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.86%)
 * Total Accepted:    213.1K
 * Total Submissions: 519.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define swap(x, y)    \
    {                 \
        int temp = x; \
        x = y;        \
        y = temp;     \
    }
//冒泡排序
void Sort_Bubble(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool changed = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        }
        if (!changed)
        {
            return;
        }
    }
}
struct intArrListNode
{
    int *vals;
    int valsSize;
    struct intArrListNode *next;
};

int **changeListToArr(struct intArrListNode *head, int size, int **columnSizes)
{
    int **ret = (int **)malloc(sizeof(int *) * size);
    *columnSizes = (int *)malloc(sizeof(int) * size);
    if (ret == NULL || *columnSizes == NULL)
    {
        return NULL;
    }
    while (size-- > 0 && head != NULL)
    {
        *(ret + size) = head->vals;
        *((*columnSizes) + size) = head->valsSize;
        head = head->next;
    }
    return ret;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    Sort_Bubble(candidates, candidatesSize);
    *returnSize = 0;
    struct intArrListNode *head = NULL, *move = head;
    for (int i = 0; i < candidatesSize; i++)
    {
        if (i > 0 && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        if (candidates[i] > target)
        {
            break;
        }
        if (candidates[i] == target)
        {
            struct intArrListNode *temp = (struct intArrListNode *)malloc(sizeof(struct intArrListNode));
            if (temp == NULL)
            {
                return NULL;
            }
            if (move == NULL)
            {
                head = move = temp;
            }
            else
            {
                move->next = temp;
                move = move->next;
            }
            temp->vals = (int *)malloc(sizeof(int));
            if (temp->vals == NULL)
            {
                return NULL;
            }
            *(temp->vals) = target;
            temp->valsSize = 1;
            (*returnSize)++;
            temp->next = NULL;
            break;
        }
        int *tempColumnSizes, tempReturnSize;
        int **recur = combinationSum2(candidates + i + 1, candidatesSize - i - 1, target - candidates[i], &tempColumnSizes, &tempReturnSize);
        for (int j = 0; j < tempReturnSize; j++)
        {
            struct intArrListNode *temp = (struct intArrListNode *)malloc(sizeof(struct intArrListNode));
            if (temp == NULL)
            {
                return NULL;
            }
            if (move == NULL)
            {
                head = move = temp;
            }
            else
            {
                move->next = temp;
                move = move->next;
            }
            temp->vals = (int *)malloc(sizeof(int) * (tempColumnSizes[j] + 1));
            if (temp->vals == NULL)
            {
                return NULL;
            }
            memcpy(temp->vals + 1, *(recur + j), sizeof(int) * tempColumnSizes[j]);
            *(temp->vals) = candidates[i];
            temp->valsSize = tempColumnSizes[j] + 1;
            (*returnSize)++;
            temp->next = NULL;
        }
    }
    return changeListToArr(head, *returnSize, columnSizes);
}

