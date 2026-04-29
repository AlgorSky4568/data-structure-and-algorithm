#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_count = 0;
int mirror_count = 0;

typedef struct TreeNode
{
    int val;
    int frontCount; //用来记录访问次数
    struct TreeNode* parents;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* initTree(TreeNode* root)
{
    root->left = root->right = NULL;
    root->val = 0;
    root->frontCount = 0;
}

TreeNode* buildTree(char** input)
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    initTree(root);
    char ch[10];
    strcpy(ch, input[input_count++]);
    if (strcmp(ch,"#") == 0)
    {
        root = NULL;
    }
    else
    {
        root->val = atoi(ch);
        root->left = buildTree(input);
        root->right = buildTree(input);
    }
    return root;

}

int judgeMirror(TreeNode* left, TreeNode* right)
{

    if (left == NULL && right == NULL)
    {
        return 1;
    }
    if ((left == NULL && right != NULL) || (right == NULL && left != NULL))
    {
        return 0;
    }
    if (left->val != right->val)
    {
        return 0;
    }
    if (left->val == right->val)
    {
        if (judgeMirror(left->left, right->right) && judgeMirror(left->right, right->left))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void count_mirror(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (judgeMirror(root->left, root->right))
        {
            mirror_count++;
        }
        count_mirror(root->left);
        count_mirror(root->right);
    }
}
int main(void)
{
    char input[1000];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    char* inputs[100];
    int n = 0;
    while (token != NULL) {
        inputs[n++] = token;
        token = strtok(NULL, " \n");
    }
    TreeNode* root = buildTree(inputs);
    count_mirror(root);
    printf("%d", mirror_count);

    return 0;
}