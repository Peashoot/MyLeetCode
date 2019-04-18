/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.84%)
 * Total Accepted:    267.9K
 * Total Submissions: 671.8K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
char *countAndSay(int n)
{
    char* start = "1";
    if (n == 1)
    {
        return start;
    }
    for (int i = 2; i <= n; i++)
    {
		int len_of_start = strlen(start) + 1;
        char* str_copy = (char *)malloc(sizeof(char) * len_of_start), * copy = str_copy;
		if (str_copy != NULL)
		{
			strcpy(str_copy, start);
			start = (char *)malloc(sizeof(char) * 2 * len_of_start);
			memset(start, '\0', 2 * len_of_start);
			if (start != NULL)
			{
				char v_num = *(copy++);
				int count = 1;
				int i_start = 0;
				while (*copy != '\0')
				{
				    if (*copy == v_num)
				    {
				        count++;
				    }
				    else
				    {
				        *(start + i_start++) = count + 48;
				        *(start + i_start++) = v_num;
				        v_num = *(copy);
				        count = 1;
				    }
					copy++;
				}
				*(start + i_start++) = count + 48;
				*(start + i_start++) = v_num;
			}
			free(str_copy);
		}
    }
    return start;
}
