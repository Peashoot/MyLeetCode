/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (42.10%)
 * Total Accepted:    311.2K
 * Total Submissions: 738.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    int i = 0;
    struct ListNode *line = head, *index = head;
    while (index->next != NULL)
    {
        index = index->next;
        if (line->val != index->val)
        {
            line->next = index;
            line = line->next;
        }
        else
        {
            line->next = NULL;
        }
    }
    return head;
}
