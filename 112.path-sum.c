/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (37.26%)
 * Total Accepted:    297.2K
 * Total Submissions: 796.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
struct Queue
{
    struct TreeNode *data[10000];
    int front, rear;
    int sum[10000];
};
void Create(struct Queue *q) //创建一个空队列
{
    q->front = q->rear = 0;
    memset(q->sum, 0, 10000);
}
void Enqueue(struct Queue *q, struct TreeNode *t)
{
    if ((q->rear + 1) % 10000 == q->front)
    {
        return;
    }
    q->rear = (q->rear + 1) % 10000;
    q->data[q->rear] = t;
}
void EnqueueWithSum(struct Queue *q, struct TreeNode *t, int sum)
{
    Enqueue(q, t);
    q->sum[q->rear] = sum;
}
struct TreeNode *Dequeue(struct Queue *q)
{
    struct TreeNode *t;
    q->front = (q->front + 1) % 10000;
    t = q->data[q->front];
    return t;
}
struct TreeNode *DequeueWithSum(struct Queue *q, int *sum) //出队，并返回对头元素
{
    struct TreeNode *t = Dequeue(q);
    *sum = q->sum[q->front];
    return t;
}

bool IsEmpty(struct Queue *q) //判断队列是否为空
{
    return (q->front == q->rear);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
    {
        return 0;
    }
    int target = 0;
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Create(Q);
    EnqueueWithSum(Q, root, root->val + target);
    while (!IsEmpty(Q))
    {
        struct TreeNode *temp = DequeueWithSum(Q, &target);
        if (temp->left == NULL && temp->right == NULL && target == sum)
        {
            return true;
        }
        if (temp->left != NULL)
        {
            EnqueueWithSum(Q, temp->left, temp->left->val + target);
        }
        if (temp->right != NULL)
        {
            EnqueueWithSum(Q, temp->right, temp->right->val + target);
        }
    }
    return false;
}

