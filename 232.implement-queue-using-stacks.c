/*
 * @lc app=leetcode id=232 lang=c
 *
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (42.65%)
 * Total Accepted:    143.4K
 * Total Submissions: 336.1K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
struct Node
{
    int val;
    struct Node*next;
};
typedef struct {
    struct Node *front, *rear;
    int size, capacity;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));
    if (ret == NULL)
    {
        return NULL;
    }
    ret->front = ret->rear = NULL;
    ret->size = 0;
    ret->capacity = maxSize;
    return ret;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj == NULL || obj->capacity == obj->size)
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
        obj->front->next = NULL;
    }
    else
    {
        struct Node *add = (struct Node *)malloc(sizeof(struct Node));
        if (add == NULL)
        {
            return;
        }
        add->val = x;
        add->next = NULL;
        obj->rear->next = add;
        obj->rear = obj->rear->next;
    }
    obj->size++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
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

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj == NULL || obj->size == 0)
    {
        return 0;
    }
    return obj->front->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj == NULL || obj->size == 0;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL)
    {
        return;
    }
    // if (obj->front != NULL)
    // {
    //     free(obj->front);
    // }
    // if (obj->rear != NULL)
    // {
    //     free(obj->rear);
    // }
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

