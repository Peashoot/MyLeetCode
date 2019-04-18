/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.25%)
 * Total Accepted:    304.4K
 * Total Submissions: 972.5K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
char* convert(char* s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int len = strlen(s);
	char* ret = (char*)malloc(sizeof(char) * (len + 1)), * tmp = ret;
	if (ret == NULL) {
		return NULL;
	}
	memset(ret, '\0', (len + 1) * sizeof(char));
	int* diff = (int*)malloc(sizeof(int) * numRows);
	if (diff == NULL) {
		return NULL;
	}
	memset(diff, 0, sizeof(int) * numRows);
	for (int i = 0; i < numRows; i++) {
		*(diff + i) = 2 * numRows - 2 * i - 2;
	}
	for (int level = 0; level < numRows; level++) {
		int index = level, odd = 0;
		while (index < len) {
			*tmp++ = *(s + index);
			int step = odd++ % 2 == 0 ? diff[level] : diff[numRows - 1 - level];
			if (step == 0) {
				step = odd++ % 2 == 0 ? diff[level] : diff[numRows - 1 - level];
            }
            if (step == 0)
            {
                break;
            }
            index += step;
		}
	}
	free(diff);
	return ret;
}

