/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (53.39%)
 * Total Accepted:    550.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseListII(struct ListNode *head, struct ListNode **root)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        *root = head;
        return head;
    }
    struct ListNode *ret = reverseListII(head->next, root);
    head->next = NULL;
    (*root)->next = head;
    *root = head;
    return ret;
}
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode *root = NULL, *ret = reverseListII(head->next, &root);
    head->next = NULL;
    root->next = head;
    return ret;
}
