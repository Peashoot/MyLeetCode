/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.94%)
 * Total Accepted:    300.8K
 * Total Submissions: 682.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *move = head, *last = NULL;
    while (move != NULL)
    {
        struct ListNode *next = move->next;
        if (next != NULL)
        {
            if (last == NULL)
            {
                head = move->next;
            }
            else
            {
                last->next = next;
            }
            move->next = next->next;
            next->next = move;
            last = move;
        }
        move = move->next;
    }
    return head;
}

