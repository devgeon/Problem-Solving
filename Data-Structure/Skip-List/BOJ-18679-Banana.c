// BOJ-18679 / Banana
// devgeon, 2024.11.03, C99
// https://www.acmicpc.net/problem/18679

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 4
#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 100

struct node {
    char *key;
    char *value;
    struct node *next;
    struct node *down;
};
typedef struct node node_t;

struct kvs {
    struct node *db;
    int items;
    int height;
};
typedef struct kvs kvs_t;

kvs_t *open();
int close(kvs_t *kvs);
int put(kvs_t *kvs, const char *key, const char *value);
char *get(kvs_t *kvs, const char *key);

int main() {
    int num = 0, len = 0, cases = 0;
    char eng_word[21], mini_word[21];
    kvs_t *kvs = open();

    scanf("%d", &num);
    while (num--) {
        scanf("%s = %s", eng_word, mini_word);
        put(kvs, eng_word, mini_word);
    }

    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &len);
        while (len--) {
            scanf("%s", eng_word);
            printf("%s ", get(kvs, eng_word));
        }
        printf("\n");
    }

    return 0;
}

kvs_t *open() {
    kvs_t *kvs = (kvs_t *)malloc(sizeof(kvs_t));
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!kvs || !node) {
        printf("Failed to malloc\n");
        free(kvs), free(node);
        return NULL;
    }

    kvs->items = 0;
    kvs->height = 1;
    node->key = (char *)malloc(sizeof(char) * MAX_KEY_LEN);
    if (!node->key) {
        printf("Failed to malloc\n");
        free(kvs), free(node);
        return NULL;
    }
    node->key[0] = '\0';
    node->value = NULL;
    node->down = NULL;
    kvs->db = node;

    return kvs;
}

int close(kvs_t *kvs) {
    node_t *curr = kvs->db, *next = NULL, *down = NULL;

    while (!(down = curr->down)) {
        while (!(next = curr->next)) {
            free(curr->key);
            free(curr->value);
            free(curr);
            curr = next;
        }
        curr = down;
    }
    free(kvs);

    return 0;
}

int put(kvs_t *kvs, const char *key, const char *value) {
    int cmp = 0, idx = 0;
    char *copied_key = NULL, *copied_value = NULL;
    node_t *curr = kvs->db, *down = NULL, *new_node = NULL;
    node_t *prev[kvs->height];

    do {
        while (curr->next) {
            cmp = strcmp(key, curr->next->key);
            if (cmp < 0)
                break;
            if (cmp == 0) {
                strcpy(curr->next->value, value);
                return 0;
            }
            curr = curr->next;
        }
        prev[idx++] = curr;
    } while ((curr = curr->down));
    idx--;

    copied_key = (char *)malloc(MAX_KEY_LEN);
    copied_value = (char *)malloc(MAX_VAL_LEN);
    if (!copied_value) {
        printf("Failed to malloc\n");
        free(copied_key), free(copied_value);
        return -1;
    }
    strcpy(copied_key, key);
    strcpy(copied_value, value);

    do {
        if (idx < 0) {
            idx = 0;
            new_node = (node_t *)malloc(sizeof(node_t));
            if (!new_node) {
                printf("Failed to malloc\n");
                return -1;
            }
            new_node->key = kvs->db->key;
            new_node->value = NULL;
            new_node->next = NULL;
            new_node->down = kvs->db;
            kvs->db = new_node;
            kvs->height++;
            prev[idx] = kvs->db;
        }
        new_node = (node_t *)malloc(sizeof(node_t));
        if (!new_node) {
            printf("Failed to malloc\n");
            if (!down)
                free(copied_key), free(copied_value);
            return -1;
        }
        new_node->key = copied_key;
        new_node->value = copied_value;
        new_node->next = prev[idx]->next;
        new_node->down = down;
        prev[idx]->next = new_node;
        down = new_node;
        idx--;
    } while (rand() & 1);

    kvs->items++;

    return 0;
}

char *get(kvs_t *kvs, const char *key) {
    int cmp = 0;
    node_t *curr = kvs->db;

    char *value = (char *)malloc(sizeof(char) * MAX_VAL_LEN);
    if (!value) {
        printf("Failed to malloc\n");
        return NULL;
    }

    do {
        while (curr->next) {
            cmp = strcmp(key, curr->next->key);
            if (cmp < 0)
                break;
            if (cmp == 0) {
                strcpy(value, curr->next->value);
                return value;
            }
            curr = curr->next;
        }
    } while ((curr = curr->down));

    strcpy(value, "-1");

    return value;
}
