/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (35.43%)
 * Total Accepted:    215.3K
 * Total Submissions: 606.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    struct ListNode *tmp = head;
    while (tmp != NULL)
    {
        struct ListNode *next = tmp->next;
        if (next != NULL && next->val == val)
        {
            tmp->next = next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return head;
}
