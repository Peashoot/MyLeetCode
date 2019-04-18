/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.66%)
 * Total Accepted:    245.1K
 * Total Submissions: 687.2K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct Node
{
    int val;
    struct Node *last, *next;
};

typedef struct
{
    struct Node *front, *rear;
    int size;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));
    if (ret == NULL)
    {
        return NULL;
    }
    ret->front = ret->rear = NULL;
    ret->size = 0;
    return ret;
}

void myQueuePush(MyQueue *obj, int x)
{
    if (obj == NULL)
    {
        return;
    }
    if (obj->rear == NULL)
    {
        obj->rear = obj->front = (struct Node *)malloc(sizeof(struct Node));
        if (obj->front == NULL)
        {
            return;
        }
        obj->front->val = x;
        obj->front->last = obj->front->next = NULL;
    }
    else
    {
        struct Node *add = (struct Node *)malloc(sizeof(struct Node));
        if (add == NULL)
        {
            return;
        }
        add->last = obj->rear;
        add->val = x;
        add->next = NULL;
        obj->rear->next = add;
        obj->rear = obj->rear->next;
    }
    obj->size++;
}

int myQueuePop(MyQueue *obj)
{
    if (obj == NULL || obj->size == 0)
    {
        return 0;
    }
    int ret = obj->front->val;
    obj->front = obj->front->next;
    if (obj->rear->next == obj->front)
    {
        obj->rear = obj->front;
    }
    obj->size--;
    return ret;
}

bool myQueueEmpty(MyQueue *obj)
{
    return obj == NULL || obj->size == 0;
}

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

MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack != NULL)
    {
        stack->top = NULL;
    }
    return stack;
}

void myStackPush(MyStack *obj, int x)
{
    struct StackNode *last = obj->top;
    obj->top = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (obj->top == NULL)
    {
        return;
    }
    obj->top->val = x;
    obj->top->last = last;
}

int myStackPop(MyStack *obj)
{
    if (obj->top == NULL)
    {
        return 0;
    }
    int ret = obj->top->val;
    obj->top = obj->top->last;
    return ret;
}

bool myStackEmpty(MyStack *obj)
{
    return obj->top == NULL;
}

bool isPalindrome(struct ListNode* head) {
    MyQueue *queue = myQueueCreate();
    MyStack *stack = myStackCreate();
    while (head != NULL)
    {
        myQueuePush(queue, head->val);
        myStackPush(stack, head->val);
        head = head->next;
    }
    while (!myQueueEmpty(queue) && !myStackEmpty(stack))
    {
        if (myQueuePop(queue) != myStackPop(stack))
        {
            return false;
        }
    }
    return true;
}

