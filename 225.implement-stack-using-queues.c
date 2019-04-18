/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (38.61%)
 * Total Accepted:    124.5K
 * Total Submissions: 322.3K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
struct StackNode
{
    int val;
    struct StackNode *last;
};
typedef struct
{
    struct StackNode *top;
    int size;
    int capacity;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack != NULL)
    {
        stack->capacity = maxSize;
        stack->top = NULL;
    }
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->capacity != 0 && obj->size >= obj->capacity)
    {
        return;
    }
    struct StackNode *last = obj->top;
    obj->top = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (obj->top == NULL)
    {
        return;
    }
    obj->top->val = x;
    obj->top->last = last;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret = myStackTop(obj);
    obj->top = obj->top->last;
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->top == NULL)
    {
        return 0;
    }
    return obj->top->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->top == NULL;
}

void myStackFree(MyStack* obj) {
    if (obj == NULL)
    {
        return;
    }
    while (obj->top != NULL)
    {
        struct StackNode *temp = obj->top;
        obj->top = obj->top->last;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */

