/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.32%)
 * Total Accepted:    536.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode)), *change = ret;
    ret->next = NULL;
    while (l1 != NULL || l2 != NULL)
    {
        struct ListNode *temp = NULL;
        if (l2 == NULL || (l1 != NULL && l1->val < l2->val))
        {
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp = l2;
            l2 = l2->next;
        }
        change->next = temp;
        change = change->next;
    }
    return ret->next;
}

