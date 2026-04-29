#include <stdio.h>
#include <stdlib.h>

int sum = 0;

struct TreeNode {
    int val;
    int color;
    struct TreeNode *left;
    struct TreeNode *right;
};

/******************* 染色 *******************/
void visitTree(struct TreeNode *root,int min, int max,int color)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (min <= root->val && root->val <= max) //染色
        {
            root->color = color;
        }
        visitTree(root->left,min,max,color); //递归访问左右子树
        visitTree(root->right,min,max,color);
    }
}

void ColorNum(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->color == 1)
        {
            sum++;
        }
        ColorNum(root->left);
        ColorNum(root->right);
    }
}

void getNumber(struct TreeNode* root, int** ops, int opsSize){
    int min, max, color;
    for (int i = 0; i < opsSize; i++)
    {
        color = ops[i][0];
        min = ops[i][1];
        max = ops[i][2];
        visitTree(root,min,max,color);
    }

}
/*****************************************************/

/******************* 读取数据 *******************/
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->color = 0;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* constructTree(int size) {
    if (size == 0)
        return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    for (int i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        if (val == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = newTreeNode(val);
        }
    }

    for (int i = 0, j = 1; j < size; i++) {
        if (nodes[i] != NULL) {
            if (j < size)
                nodes[i]->left = nodes[j++];
            if (j < size)
                nodes[i]->right = nodes[j++];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void readOps(int ***ops, int *opsSize) {
    scanf("%d", opsSize);

    *ops = (int **)malloc(*opsSize * sizeof(int *));
    while(getchar() != '[') {}
    for (int i = 0; i < *opsSize; i++) {
        (*ops)[i] = (int *)malloc(3 * sizeof(int));
        while(getchar() != '[') {}
        for (int j = 0; j < 3; j++) {
            scanf("%d", &((*ops)[i][j]));
        }
        while(getchar() != ']') {}
    }
}
/*****************************************************/

int main() {
    int nodeSize;
    scanf("%d", &nodeSize);
    struct TreeNode* root = constructTree(nodeSize);
    int **ops, opsSize;
    readOps(&ops, &opsSize);
    getNumber(root, ops, opsSize);
    ColorNum(root);
    printf("%d",sum);
    
    return 0;
}