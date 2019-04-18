/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.99%)
 * Total Accepted:    282.3K
 * Total Submissions: 805.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct queue //队列的数据结构
{
    struct TreeNode *data[10000];
    int front, rear;
    int floor[10000];
};

void creat(struct queue *q)
{
    q->front = q->rear = 0;
    memset(q->floor, 0, sizeof(int) * 10000);
}

void enqueue(struct queue *q, struct TreeNode *t, int floor)
{
    if ((q->rear + 1) % 10000 == q->front)
    {
        return;
    }
    q->rear = (q->rear + 1) % 10000;
    q->data[q->rear] = t;
    q->floor[q->rear] = floor;
}

struct TreeNode *dequeue(struct queue *q, int *floor)
{
    struct TreeNode *t;
    q->front = (q->front + 1) % 10000;
    t = q->data[q->front];
    *floor = q->floor[q->front];
    return t;
}

bool isempty(struct queue *q)
{
    return (q->front == q->rear);
}

int minDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int floor = 1;
    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    creat(Q);
    enqueue(Q, root, floor);
    while (!isempty(Q))
    {
        struct TreeNode *temp = dequeue(Q, &floor);
        if (temp->left == NULL && temp->right == NULL)
        {
            return floor;
        }
        if (temp->left != NULL)
        {
            enqueue(Q, temp->left, floor + 1);
        }
        if (temp->right != NULL)
        {
            enqueue(Q, temp->right, floor + 1);
        }
    }
    return floor;
}
