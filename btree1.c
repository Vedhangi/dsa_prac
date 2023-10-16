#include <stdio.h>
#include <stdlib.h>

#define ORDER 5

typedef struct BTreeNode {
    int keys[ORDER - 1];
    struct BTreeNode* children[ORDER];
    int numKeys;
} BTreeNode;

BTreeNode* createNode() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->numKeys = 0;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void splitChild(BTreeNode* parent, int childIndex) {
    BTreeNode* child = parent->children[childIndex];
    BTreeNode* newChild = createNode();
    parent->numKeys++;

    for (int i = parent->numKeys - 1; i > childIndex; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[childIndex] = child->keys[ORDER / 2 - 1];
    parent->children[childIndex + 1] = newChild;

    for (int i = 0; i < ORDER / 2 - 1; i++) {
        newChild->keys[i] = child->keys[i + ORDER / 2];
        child->keys[i + ORDER / 2] = 0;
    }

    for (int i = 0; i < ORDER / 2; i++) {
        newChild->children[i] = child->children[i + ORDER / 2];
        child->children[i + ORDER / 2] = NULL;
    }

    child->numKeys = ORDER / 2 - 1;
}

void insert(BTreeNode** root, int key) {
    BTreeNode* rootNode = *root;

    if (rootNode->numKeys == ORDER - 1) {
        BTreeNode* newRoot = createNode();
        newRoot->children[0] = rootNode;
        *root = newRoot;
        splitChild(newRoot, 0);
    }

    BTreeNode* currentNode = rootNode;

    while (1) {
        int i = currentNode->numKeys - 1;
        while (i >= 0 && key < currentNode->keys[i]) {
            currentNode->keys[i + 1] = currentNode->keys[i];
            currentNode->children[i + 2] = currentNode->children[i + 1];
            i--;
        }

        currentNode->keys[i + 1] = key;
        currentNode->numKeys++;

        if (currentNode->children[i + 1] == NULL) {
            break;
        }

        if (currentNode->children[i + 1]->numKeys == ORDER - 1) {
            splitChild(currentNode, i + 1);
            if (key > currentNode->keys[i + 1]) {
                i++;
            }
        }

        currentNode = currentNode->children[i + 1];
    }
}

void display(BTreeNode* node, int level) {
    if (node != NULL) {
        for (int i = node->numKeys - 1; i >= 0; i--) {
            display(node->children[i + 1], level + 1);
            for (int j = 0; j < level; j++) {
                printf("  ");
            }
            printf("%d\n", node->keys[i]);
        }
        display(node->children[0], level + 1);
    }
}

int main() {
    BTreeNode* root = createNode();

    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, values[i]);
    }

    printf("B-tree structure:\n");
    display(root, 0);

    return 0;
}
