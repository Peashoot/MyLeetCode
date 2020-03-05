/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */


bool isPowerOfFour(int num){
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}



