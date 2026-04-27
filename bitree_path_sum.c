#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int max_sum = 0;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(char** input, int n) {  //根据队列构建二叉树
    if (n == 0 || strcmp(input[0], "null")== 0) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    TreeNode* root = newNode(atoi(input[0]));
    queue[0] = root;
    int front = 0, rear = 1;

    for (int i = 1; i < n; i += 2) {
        TreeNode* current = queue[front++];

        if (strcmp(input[i], "null")!= 0) {
            current->left = newNode(atoi(input[i]));
            queue[rear++] = current->left;
        }

        if (i + 1 < n && strcmp(input[i + 1], "null")!= 0) {
            current->right = newNode(atoi(input[i + 1]));
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

int maxPathSum(TreeNode* root) {
    int left_gain,right_gain,this_gain;
    if (root->left == NULL) {
        left_gain = 0;
    }
    else {
        left_gain = MAX(maxPathSum(root->left),0);
    }
    if (root->right == NULL) {
        right_gain = 0;
    }
    else {
        right_gain = MAX(maxPathSum(root->right),0);
    }
    this_gain = left_gain + right_gain + root->val;
    if (this_gain > max_sum) {
        max_sum = this_gain;
    }
    return root->val + MAX(left_gain,right_gain);

}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    char* inputs[100];
    int n = 0;
    while (token != NULL) {
        inputs[n++] = token;
        token = strtok(NULL, " \n");
    }
    TreeNode* root = buildTree(inputs, n);
    max_sum = root->val;
    int result = maxPathSum(root);
    printf("%d\n", max_sum);

    freeTree(root);

    return 0;
}