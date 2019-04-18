/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (34.98%)
 * Total Accepted:    190.2K
 * Total Submissions: 543.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */
struct Hash
{
    struct Pair **buckets;
    int size;
};

struct Pair
{
    int key;
    int value;
    struct Pair *next;
};

int GetHash(int num, int size)
{
    return abs(num % size);
}

struct Hash *CreateHash(int size)
{
    struct Hash *ret = (struct Hash *)malloc(sizeof(struct Hash));
    if (ret == NULL)
    {
        return NULL;
    }
    ret->buckets = (struct Pair **)malloc(sizeof(struct Pair *) * size);
    if (ret->buckets == NULL)
    {
        return NULL;
    }
    memset(ret->buckets, NULL, sizeof(struct Pair *) * size);
    ret->size = size;
    return ret;
}

bool Put(struct Hash *hash, int key, int value)
{
    if (hash == NULL)
    {
        return false;
    }
    int h = GetHash(key, hash->size);

    if (hash->buckets[h] == NULL)
    {
        hash->buckets[h] = (struct Pair *)malloc(sizeof(struct Pair));
        struct Pair *pair = hash->buckets[h];
        if (pair == NULL)
        {
            return false;
        }
        pair->key = key;
        pair->value = value;
        pair->next = NULL;
        return true;
    }
    else
    {
        struct Pair *pair = hash->buckets[h], *last = pair;
        while (pair != NULL)
        {
            if (pair->key == key)
            {
                pair->value = value;
                return true;
            }
            last = pair;
            pair = pair->next;
        }
        struct Pair *newpair = (struct Pair *)malloc(sizeof(struct Pair));
        if (newpair == NULL)
        {
            return false;
        }
        newpair->key = key;
        newpair->value = value;
        newpair->next = NULL;
        last->next = newpair;
        return true;
    }
    return false;
}

bool Get(struct Hash *hash, int key, int *value)
{
    if (hash == NULL)
    {
        return false;
    }
    int h = GetHash(key, hash->size);
    struct Pair *pair = hash->buckets[h];
    while (pair != NULL)
    {
        if (pair->key == key)
        {
            *value = pair->value;
            return true;
        }
        pair = pair->next;
    }
    return false;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (numsSize == 0)
    {
        return false;
    }
    struct Hash *hash = CreateHash(sqrt(numsSize));
    if (hash == NULL)
    {
        return false;
    }
    for (int i = 0; i < numsSize; i++)
    {
        int value = -1;
        Get(hash, nums[i], &value);
        if (value != -1 && i - value <= k)
        {
            free(hash);
            return true;
        }
        Put(hash, nums[i], i);
    }
    free(hash);
    return false;
}
