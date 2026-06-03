#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}Node;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void insert(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }
    else
    {
        if (data < (*root)->data)
        {
            insert(&(*root)->lchild, data);
        }
        else if (data > (*root)->data)
        {
            insert(&(*root)->rchild, data);
        }
        else
        {
            return;
        }
    }
}

void delete(Node **root, int data) {
    if (*root == NULL) return;

    if (data < (*root)->data)
        delete(&(*root)->lchild, data);
    else if (data > (*root)->data)
        delete(&(*root)->rchild, data);
    else {
        Node *node = *root;
        if (node->lchild == NULL && node->rchild == NULL) {
            *root = NULL;
            free(node);
        }
        else if (node->lchild == NULL) {
            *root = node->rchild;
            free(node);
        }
        else if (node->rchild == NULL) {
            *root = node->lchild;
            free(node);
        }
        else {
            // 找左子树最大节点
            Node *parent = node;
            Node *max = node->rchild;
            while (max->lchild != NULL) {
                parent = max;
                max = max->lchild;
            }
            node->data = max->data;
            // 删除 max 节点
            if (parent->lchild == max)
                parent->lchild = max->rchild;
            else
                parent->rchild = max->rchild;
            free(max);
        }
    }
}

void search(Node *root, int L,int R)
{
    if (root == NULL)
    {
        printf("\n");
        return;
    }
    else if (root->data < L)
    {
        search(root->rchild,L,R);
    }
    else if (root->data > R)
    {
        search(root->lchild,L,R);
    }
    else
    {
        printf("%d\n",root->data);
        return;
    }
}
int main(void)
{
    int N;
    scanf("%d",&N);
    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        char ch;
        scanf(" %c",&ch);
        if (ch == 'I')
        {
            int x;
            scanf("%d",&x);
            insert(&root,x);
        }
        else if (ch == 'D')
        {
            int x;
            scanf("%d",&x);
            delete(&root,x);
        }
        else if (ch == 'Q')
        {
            int L,R;
            scanf("%d%d",&L,&R);
            search(root,L,R);
        }
    }
}