/*
 * @lc app=leetcode id=367 lang=c
 *
 * [367] Valid Perfect Square
 */


bool isPerfectSquare(int num){
    if (num == 1) {return true;}
    for (int i = 1; i <= num / 2 && i < 46341; i++) {
        if (i * i == num)
        {
            return true;
        }
        if (i * i > num)
        {
            break;
        }
    }
    return false;
}



