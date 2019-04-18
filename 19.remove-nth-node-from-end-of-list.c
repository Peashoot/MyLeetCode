/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.13%)
 * Total Accepted:    376.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void traversingListWithRemove(struct ListNode *head, int n, int *lastIndex)
{
    if (head == NULL)
    {
        *lastIndex = 0;
        return;
    }
    traversingListWithRemove(head->next, n, lastIndex);
    if (n == *lastIndex)
    {
        struct ListNode *next = head->next;
        if (next == NULL)
        {
            head->next = NULL;
        }
        else
        {
            head->next = next->next;
            free(next);
        }
    }
    (*lastIndex)++;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int lastIndex;
    traversingListWithRemove(head, n, &lastIndex);
    if (head != NULL && lastIndex == n)
    {
        head = head->next;
    }
    return head;
}

