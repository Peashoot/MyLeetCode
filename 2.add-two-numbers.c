/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.89%)
 * Total Accepted:    829.6K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int val1 = 0, val2 = 0;
    bool carry = false;
    struct ListNode *node = NULL, *head = node;
    while (!(l1 == NULL && l2 == NULL && !carry))
    {
        val1 = l1 == NULL ? 0 : l1->val;
        val2 = l2 == NULL ? 0 : l2->val;
        struct ListNode *tmp = node;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (node == NULL)
        {
            node = tmp;
            break;
        }
        if (tmp == NULL)
        {
            head = node;
        }
        else
        {
            tmp->next = node;
        }
        int sum = val1 + val2 + carry;
        if (sum > 9)
        {
            carry = true;
            sum -= 10;
        }
        else
        {
            carry = false;
        }
        node->val = sum;
        node->next = NULL;
        if (l1 != NULL)
        {
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2 = l2->next;
        }
    }
    return head;
}

