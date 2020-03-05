/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start


char * toHex(int num){
    char *ret = (char *)malloc(sizeof(char) * 9);
    if (ret == NULL)
    {
        return NULL;
    }
    memset(ret, '\0', sizeof(char) * 9);
    int temp = 0;
    if (num < 0)
    {
        num += 1;
        num = 0 - num;
        memset(ret, 'f', sizeof(char) * 8);
        for (int i = 7; i >= 0 && num > 0; i--)
        {
            temp = num % 16;
            temp = 15 - temp;
            *(ret + i) = temp > 9 ? temp - 10 + 'a' : temp + '0';
            num >>= 4;
        }
        return ret;
    }
    else if (num == 0)
    {
        return "0";
    }
    else
    {
        int i;
        for (i = 7; i >= 0 && num > 0; i--)
        {
            temp = num % 16;
            *(ret + i) = temp > 9 ? temp - 10 + 'a' : temp + '0';
            num >>= 4;
        }
        return ret + i + 1;
    }
}


// @lc code=end

