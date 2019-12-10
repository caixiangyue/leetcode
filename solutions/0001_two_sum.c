/**
 * Author: Xiangyue Cai
 * Date: 2019-12-10
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hash_entry {
int key;
int value;
UT_hash_handle hh;
};

typedef struct hash_entry HashTable;

static void delete_all(HashTable *hash) {
  HashTable *h, *tmp;

  HASH_ITER(hh, hash, h, tmp) {
    HASH_DEL(hash, h);  /* delete; users advances to next */
    free(h);            /* optional- if you want to free  */
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    HashTable *hash = NULL;
    int i = 0;
    int temp;
    int *ret = NULL;
    for (; i < numsSize ; ++i) {
        temp = target - nums[i];
        HashTable *h = NULL;
        HASH_FIND_INT(hash, &temp, h);
        if (h == NULL) {
            h = malloc (sizeof(HashTable));
            h->key = nums[i];
            h->value = i;
            HASH_ADD_INT(hash, key, h);
        } else {
            *returnSize = 2;
            ret = malloc(sizeof(int) * (*returnSize));
            ret[0] = i;
            ret[1] = h->value;
            delete_all(hash);
            return ret;
        }
    }
    *returnSize = 0;
    return NULL;
}
