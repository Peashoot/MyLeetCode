/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.04%)
 * Total Accepted:    322.2K
 * Total Submissions: 594.9K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct myListNode
{
    char *s;
    struct myListNode *next;
};

char *strInsert(char *dest, char *ins, int pos)
{
    if (pos > strlen(dest))
    {
        pos = strlen(dest);
    }
    char *ret = (char *)malloc(sizeof(char) * (strlen(dest) + strlen(ins) + 1)), *move = ret;
    if (ret == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < pos; i++)
    {
        *move++ = *dest++;
    }
    while (*ins != '\0')
    {
        *move++ = *ins++;
    }
    while (*dest != '\0')
    {
        *move++ = *dest++;
    }
    *move = '\0';
    return ret;
}

char** generateParenthesis(int n, int* returnSize) {
    int count = 1;
    struct myListNode *addList = (struct myListNode *)malloc(sizeof(struct myListNode));
    if (addList == NULL)
    {
        return NULL;
    }
    addList->s = "()";
    addList->next = NULL;
    char *ins = "()";
    for (int i = 1; i < n; i++)
    {
        struct myListNode *past = addList;
        addList = NULL;
        struct myListNode *move = addList;
        count = 0;
        while (past != NULL)
        {
            for (int j = 0; j <= strlen(past->s); j++)
            {
                if (j == 0 || *(past->s + j - 1) == '(')
                {
                    struct myListNode *current = (struct myListNode *)malloc(sizeof(struct myListNode));
                    count++;
                    if (current == NULL)
                    {
                        return NULL;
                    }
                    if (move == NULL)
                    {
                        addList = move = current;
                    }
                    else
                    {
                        move->next = current;
                        move = move->next;
                    }
                    move->s = strInsert(past->s, ins, j);
                    move->next = NULL;
                }
            }
            past = past->next;
        }
    }
    //链表转数组
    char **ret = (char **)malloc(sizeof(char *) * count);
    if (ret == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (addList != NULL)
    {
        bool duplicate = false;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(addList->s, *(ret + j)) == 0)
            {
                duplicate = true;
                break;
            }
        }
        if (duplicate)
        {
            addList = addList->next;
            continue;
        }
        *(ret + i) = addList->s;
        i++;
        addList = addList->next;
    }
    *returnSize = i;
    return ret;
}

