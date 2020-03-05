/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 */


int getSum(int a, int b){
    unsigned int c;
    while (b != 0)
    {                 //循环结束的标志是b==0；这意味着a & b == 0 ，也就是相加不产生进位
        c = (a & b);  //是否有进位
        a = a ^ b;    //实现无进位的相加
        b = (c) << 1; //进位的结果
    }
    return a;
}


