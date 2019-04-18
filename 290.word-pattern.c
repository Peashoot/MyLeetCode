/*
 * @lc app=leetcode id=290 lang=c
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (34.75%)
 * Total Accepted:    135.9K
 * Total Submissions: 390.8K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
bool wordPattern(char* pattern, char* str) {
    int strCount = 0;
    int patternSize = strlen(pattern);
    char **translate = (char **)calloc(26, sizeof(char *));
    if (translate == NULL)
    {
        return false;
    }
    char *token;

    // Seperate the string by space and assign pointer at the beginning of
    // each word to the pattern associated table
    token = strtok(str, " ");
    while (token != NULL && strCount < patternSize)
    {
        if (!translate[pattern[strCount] - 'a'])
        {
            translate[pattern[strCount] - 'a'] = token;
        }
        else
        {
            if (strcmp(translate[pattern[strCount] - 'a'], token))
            {
                return false;
            }
        }
        token = strtok(NULL, " ");
        strCount++;
    }

    // If pattern and words have different size return false
    if (strCount < patternSize || token != NULL)
        return false;

    // Check if two character have assigned to the same word
    for (int i = 0; i < 25; i++)
    {
        if (translate[i])
        {
            //printf("%s\n", translate[i]);
            for (int j = i + 1; j < 26; j++)
            {
                if (translate[j])
                {
                    if (strcmp(translate[i], translate[j]) == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

