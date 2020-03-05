/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */


void reverseString(char* s, int sSize){
    char temp;
    for (int i = 0; i <(sSize + 1) / 2; i++)
    {
        if (s[i] != s[sSize -1 - i])
        {
            temp = s[i];
            s[i] = s[sSize - 1- i];
            s[sSize - 1 - i] = temp;
        }
    }
}



