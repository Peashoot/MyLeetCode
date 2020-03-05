/*
 * @lc app=leetcode id=401 lang=c
 *
 * [401] Binary Watch
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *readBinaryArray(char *nums)
{
    int hours = ((((nums[0] - '0') << 1) + (nums[1] - '0') << 1) + (nums[2] - '0') << 1) + (nums[3] - '0');
    int minutes = ((((((nums[4] - '0') << 1) + (nums[5] - '0') << 1) + (nums[6] - '0') << 1) + (nums[7] - '0') << 1) + (nums[8] - '0') << 1) + (nums[9] - '0');
    char *ret = (char *)malloc(sizeof(char) * 6);
    if (ret == NULL || hours > 11 || minutes > 59)
    {
        return NULL;
    }
    memset(ret, '\0', sizeof(char) * 6);
    int i = 0;
    if (hours / 10 > 0)
    {
        ret[i++] = hours / 10 + '0';
    }
    ret[i++] = hours % 10 + '0';
    ret[i++] = ':';
    ret[i++] = minutes / 10 + '0';
    ret[i++] = minutes % 10 + '0';
    return ret;
}
char **readBinaryWatchWithLength(int num, int length, int *returnSize)
{
    *returnSize = 1;
    for (int i = length; i > length - num; i--)
    {
        *returnSize *= i;
    }
    for (int i = 2; i < num + 1; i++)
    {
        *returnSize /= i;
    }
    char **ret = (char **)malloc(sizeof(char *) * (*returnSize));
    if (ret == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < *returnSize; i++)
    {
        *(ret + i) = (char *)malloc(sizeof(char) * length);
        if (*(ret + i) == NULL)
        {
            return NULL;
        }
        memset(*(ret + i), '0', sizeof(char) * length);
    }
    if (num == 0)
    {
        return ret;
    }
    int index = 0;
    for (int i = 0; i <= length - num; i++)
    {
        char *prefix = (char *)malloc(sizeof(char) * (i + 1));
        if (prefix == NULL)
        {
            continue;
        }
        memset(prefix, '0', sizeof(char) * (i + 1));
        prefix[i] = '1';
        int bodySize = 0;
        char **bodys = readBinaryWatchWithLength(num - 1, length - i - 1, &bodySize);
        if (bodys == NULL)
        {
            return NULL;
        }
        for (int j = 0; j < bodySize; j++)
        {
            if (bodys[j] == NULL)
            {
                continue;
            }
            memcpy(*(ret + index), prefix, sizeof(char) * (i + 1));
            memcpy(*(ret + index) + i + 1, *(bodys + j), sizeof(char) * (length - i - 1));
            index++;
        }
    }
    return ret;
}

char ** readBinaryWatch(int num, int* returnSize){
    int size = (*returnSize) = 0;
    char **all = readBinaryWatchWithLength(num, 10, &size);
    char **ret = (char **)malloc(sizeof(char *) * size);
    if (ret == NULL)
    {
        return NULL;
    }
    char *temp = NULL;
    for (int i = 0, j = 0; i < size; i++)
    {
        temp = readBinaryArray(*(all + i));
        if (temp != NULL)
        {
            *(ret + j++) = temp;
            (*returnSize)++;
        }
    }
    return ret;
}


