#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct {
    TreeNode* line[100];
    int first;
    int rear;
}Queue;

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    TreeNode* root = NULL;
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[0];
    int index = 0;//标识根节点在中序遍历中的位置

    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == root->val) {
            index = i;
            break;
        }
    }
    if (index == 0) {//没有左孩子
        root->left = NULL;
    }
    else {
        root->left = buildTree(preorder+1, index, inorder, index);
    }
    if (preorderSize-index-1 <= 0) {//没有右孩子
        root->right = NULL;
    }
    else {
        root->right = buildTree(preorder+index+1,preorderSize-index-1,inorder+index+1,inorderSize-index-1);
    }
    return root;
}

void in_queue(Queue* queue,TreeNode* root) {
    queue->line[queue->rear++] = root;

}
void out_queue(Queue* queue) {
    queue->line[queue->first++] = NULL;
}

void printTree(TreeNode* root) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->first = 0;
    queue->rear = 0;
    TreeNode* le_child = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* ri_child = (TreeNode*)malloc(sizeof(TreeNode));
    in_queue(queue, root);
    while (queue->first != queue->rear) {
        if (root == NULL) {
            out_queue(queue);
            root = queue->line[queue->first];
            printf("null ");
        }
        else {
            le_child = root->left;
            ri_child = root->right;
            printf("%d ", root->val);
            out_queue(queue);
            in_queue(queue,le_child);
            in_queue(queue,ri_child);
            root = queue->line[queue->first];
        }
    }


}

int main() {
    int preorderSize;
    scanf("%d", &preorderSize);
    int* preorder = (int*)malloc(preorderSize * sizeof(int));
    for (int i = 0; i < preorderSize; i++) {
        scanf("%d", &preorder[i]);
    }

    int inorderSize = preorderSize;
    int* inorder = (int*)malloc(inorderSize * sizeof(int));
    for (int i = 0; i < inorderSize; i++) {
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);
    printTree(root);

    return 0;
}