#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // 添加这个头文件

typedef struct Book {
    char Book_ID[20];
    char Title[100];
    char Author[50];
    int Stock;
    struct Book *next;
} Book;

Book* CreateBook(Book *pre_book,char Book_ID[], char Title[], char Author[], int Stock) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if(newBook == NULL) {
        return NULL;
    }
    //传入图书数据，创建图书节点，讲其与前节点连接起来
    strcpy(newBook->Book_ID, Book_ID);
    strcpy(newBook->Title, Title);
    strcpy(newBook->Author, Author);
    newBook->Stock = Stock;  
    pre_book->next = newBook;
    newBook->next = NULL;
    return newBook;
}

int DeleteBook(Book **head, char bookID[]) {  // 修正参数类型
    //头节点就是个空节点
    Book *prev = *head;
    Book *current = (*head)->next;
    
    while(current != NULL) {
        if(strcmp(current->Book_ID, bookID) == 0) {  // 修正比较逻辑
            prev->next = current->next;
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    
    return 0;
}

int UpdateStock(Book *head, char bookID[], int newStock) {
    Book *current = head->next;
    
    while(current != NULL) {
        if(strcmp(current->Book_ID, bookID) == 0) {  // 修正比较逻辑
            current->Stock = newStock;
            return 1;
        }
        current = current->next;
    }
    
    return 0;
}

Book* FindBook(Book *head, char bookID[]) {
    Book *current = head->next;
    
    while(current != NULL) {
        if(strcmp(current->Book_ID, bookID) == 0) {  // 修正比较逻辑
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void PrintBook(Book *book) {
    if(book != NULL) {
        printf("书号:%s,书名:%s,作者:%s,库存:%d\n",
               book->Book_ID, book->Title, book->Author, book->Stock);
    }
}

void TraverseList(Book *head) {
    Book *current = head->next;
    
    while(current != NULL) {
        PrintBook(current);
        current = current->next;
    }
}

// 添加释放内存的函数
void FreeList(Book *head) {
    Book *current = head;
    while(current != NULL) {
        Book *next = current->next;
        free(current);
        current = next;
    }
}


int main() {
    Book *head = (Book*)malloc(sizeof(Book)); // 链表头节点
    head->next = NULL;

    // 添加图书信息
    Book *book1 = CreateBook(head,"001", "C程序设计", "谭浩强", 10);
    Book *book2 = CreateBook(book1,"002", "数据结构", "严蔚敏", 5);
    Book *book3 = CreateBook(book2,"003", "算法导论", "Thomas H. Cormen", 3);

    // 查找图书信息
    char BookID_1[20];
    scanf("%s",BookID_1);
    Book *book_1 = FindBook(head, BookID_1);
    printf("查找的图书信息:\n");
    PrintBook(book_1);

    // 修改图书库存数量
    char BookID_2[20];
    int stock_num;
    scanf("%s %d",BookID_2,&stock_num);
    if(UpdateStock(head, BookID_2, stock_num)){
        printf("图书%s的库存数量已修改为%d!\n",BookID_2,stock_num);
    }

    // 删除图书信息
    char BookID_3[20];
    scanf("%s",BookID_3);
    if(DeleteBook(&head, BookID_3)){
        printf("图书%s删除成功!\n",BookID_3);
    }

    // 遍历输出图书列表
    printf("图书列表:\n");
    TraverseList(head);

    return 0;
}
