/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (36.10%)
 * Total Accepted:    283.1K
 * Total Submissions: 780.6K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
typedef struct
{
    int *vals;
    int top;
    int minIndex;
    int capacity;
} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate(int maxSize)
{
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->vals = (int *)malloc(sizeof(int) * maxSize);
    stack->capacity = maxSize;
    stack->top = -1;
    stack->minIndex = -1;
    return stack;
}

void minStackPush(MinStack *obj, int x)
{
    if (obj->top + 1 >= obj->capacity)
    {
        return;
    }
    obj->top++;

    obj->vals[obj->top] = x;
    if (obj->minIndex >= 0 && obj->vals[obj->minIndex] > x)
    {
        obj->minIndex = obj->top;
    }
}

void minStackPop(MinStack *obj)
{
    if (obj->top + 1 <= 0)
    {
        return;
    }
    if (obj->minIndex == obj->top)
    {
        obj->minIndex = -1;
    }
    obj->top--;
}

int minStackTop(MinStack *obj)
{
    if (obj->top + 1 <= 0)
    {
        return 0;
    }
    return obj->vals[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    if (obj->minIndex >= 0)
    {
        return obj->vals[obj->minIndex];
    }
    if (obj->top + 1 <= 0)
    {
        return 0;
    }
    int min = obj->vals[0];
    for (int i = 1; i <= obj->top; i++)
    {
        if (min > obj->vals[i])
        {
            min = obj->vals[i];
            obj->minIndex = i;
        }
    }
    return min;
}

void minStackFree(MinStack *obj)
{
    free(obj->vals);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
