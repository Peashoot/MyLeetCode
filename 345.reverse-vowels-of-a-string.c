/*
 * @lc app=leetcode id=345 lang=c
 *
 * [345] Reverse Vowels of a String
 */


char * reverseVowels(char * s){
    if (s == NULL) {return NULL;}
    int len = strlen(s);
    char temp;
    int j = len;
    for (int i = 0; i < j; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            for (; j > i; j--)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    j--;
                    break;
                }
            }
        }
    }
    return s;
}



