/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */

// @lc code=start

// unsigned short *getStatistics(char *str)
// {
//     unsigned short *ret = (unsigned short *)malloc(sizeof(unsigned short) * 26);
//     if (ret == NULL)
//     {
//         return NULL;
//     }
//     memset(ret, 0, sizeof(unsigned short) * 26);
//     if (str == NULL)
//     {
//         return ret;
//     }
//     while (*str != '\0')
//     {
//         ret[*str - 'a']++;
//         str++;
//     }
//     return ret;
// }

// bool isEqual(unsigned short *a1, unsigned short *a2, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (a1[i] != a2[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
// char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
//     if (strsSize == 0)
//     {
//         return NULL;
//     }
//     *returnSize = 0;
//     char ***ret = (char ***)malloc(sizeof(char **));
//     *returnColumnSizes = (int *)malloc(sizeof(int));
//     unsigned short **allStatistics = (unsigned short **)malloc(sizeof(unsigned short *));
//     if (ret == NULL || *returnColumnSizes == NULL || allStatistics == NULL)
//     {
//         return NULL;
//     }
//     for (int i = 0; i < strsSize; i++)
//     {
//         unsigned short *statistics = getStatistics(strs[i]);
//         int j = 0;
//         for (; j < *returnSize; j++)
//         {
//             if (isEqual(allStatistics[j], statistics, 26))
//             {
//                 free(statistics);
//                 ((*returnColumnSizes)[j])++;
//                 char **reaRetJ = (char **)realloc(ret[j], sizeof(char *) * ((*returnColumnSizes)[j]));
//                 if (reaRetJ == NULL)
//                 {
//                     free(ret[j]);
//                     return NULL;
//                 }
//                 ret[j] = reaRetJ;
//                 ret[j][(*returnColumnSizes)[j] - 1] = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));
//                 if (ret[j][(*returnColumnSizes)[j] - 1] == NULL)
//                 {
//                     return NULL;
//                 }
//                 memcpy(ret[j][(*returnColumnSizes)[j] - 1], strs[i], sizeof(char) * (strlen(strs[i]) + 1));
//                 break;
//             }
//         }
//         if (j == *returnSize)
//         {
//             (*returnSize)++;
//             int *reaRetColSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * *returnSize);
//             if (reaRetColSizes == NULL)
//             {
//                 free(*returnColumnSizes);
//                 return NULL;
//             }
//             *returnColumnSizes = reaRetColSizes;
//             (*returnColumnSizes)[j] = 1;
//             char ***reaRet = (char ***)realloc(ret, sizeof(char **) * (*returnSize));
//             if (reaRet == NULL)
//             {
//                 free(ret);
//                 return NULL;
//             }
//             ret = reaRet;
//             ret[j] = (char **)malloc(sizeof(char *));
//             if (ret[j] == NULL)
//             {
//                 return NULL;
//             }
//             ret[j][0] = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));
//             if (ret[j][0] == NULL)
//             {
//                 return NULL;
//             }
//             memcpy(ret[j][0], strs[i], sizeof(char) * (strlen(strs[i]) + 1));
//             unsigned short **reaAllStatis = (unsigned short **)realloc(allStatistics, sizeof(unsigned short *) * *returnSize);
//             if (reaAllStatis == NULL)
//             {
//                 free(allStatistics);
//                 return NULL;
//             }
//             allStatistics = reaAllStatis;
//             allStatistics[j] = statistics;
//         }
//     }
//     return ret;
// }

void strsort(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        bool changed = false;
        for (int j = 0; j < strlen(str) - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                changed = true;
            }
        }
        if (!changed)
        {
            return;
        }
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    if (strsSize == 0)
    {
        return NULL;
    }
    *returnSize = 0;
    char ***ret = NULL;
    *returnColumnSizes = NULL;
    char **compare = (char**)malloc(strsSize * sizeof(char*));
    for (int i = 0; i < strsSize; i++)
    {
        char *copy = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));
        memcpy(copy, strs[i], sizeof(char) * (strlen(strs[i]) + 1));
        strsort(copy);
        int j = 0;
        for (; j < *returnSize; j++)
        {
            if (strcmp(copy, compare[j]) == 0)
            {
                free(copy);
                ((*returnColumnSizes)[j])++;
                ret[j] = (char **)realloc(ret[j], sizeof(char *) * ((*returnColumnSizes)[j]));
                ret[j][(*returnColumnSizes)[j] - 1] = strs[i];
                break;
            }
        }
        if (j == *returnSize)
        {
            (*returnSize)++;
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * *returnSize);
            (*returnColumnSizes)[j] = 1;
            ret = (char ***)realloc(ret, sizeof(char **) * (*returnSize));
            ret[j] = (char **)malloc(sizeof(char *));
            ret[j][0] = strs[i];
            compare[j] = copy;
        }
    }
    return ret;
}

// @lc code=end

