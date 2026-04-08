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

Book* CreateBook(Book book) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if(newBook == NULL) {
        return NULL;
    }
    // 修正：正确的赋值顺序
    strcpy(newBook->Book_ID, book.Book_ID);
    strcpy(newBook->Title, book.Title);
    strcpy(newBook->Author, book.Author);
    newBook->Stock = book.Stock;  // 使用传入的库存值
    newBook->next = NULL;
    return newBook;
}

void InsertBook(Book **head, Book book) {
    Book *newBook = CreateBook(book);
    if(newBook == NULL) {
        return;
    }
    
    if(*head == NULL) {
        *head = newBook;
        return;
    }
    
    Book *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBook;
}

int DeleteBook(Book **head, char bookID[]) {  // 修正参数类型
    if(*head == NULL) {
        return 0;
    }
    
    // 处理头节点
    if(strcmp((*head)->Book_ID, bookID) == 0) {
        Book *toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return 1;
    }
    
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
    Book *current = head;
    
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
    Book *current = head;
    
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
        printf("书号:%s, 书名:%s, 作者:%s, 库存:%d\n", 
               book->Book_ID, book->Title, book->Author, book->Stock);
    }
}

void TraverseList(Book *head) {
    Book *current = head;
    
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
    Book *head = NULL; // 链表头节点

    // 添加图书信息
    Book book1 = {"001", "C程序设计", "谭浩强", 10};
    Book book2 = {"002", "数据结构", "严蔚敏", 5};
    Book book3 = {"003", "算法导论", "Thomas H. Cormen", 3};
    InsertBook(&head, book1);
    InsertBook(&head, book2);
    InsertBook(&head, book3);

    // 查找图书信息
    FindBook(head, "002");

    // 修改图书库存数量
    UpdateStock(head, "001", 8);
    //TraverseList(head);

    // 删除图书信息
    DeleteBook(&head, "003");

    // 遍历输出图书列表
    TraverseList(head);

    return 0;
}

/*
#include <stdio.h>
#include <string.h>

typedef struct Book{
    char Book_ID[20];
    char Title[100];
    char Author[50];
    int Stock;
    struct Book *next;
}Book;

Book* CreateBook(Book book){
    Book *newBook = (Book*)malloc(sizeof(Book));
    if(newBook == NULL){
        return NULL;
    }
    strcpy(book.Book_ID,newBook->Book_ID);
    strcpy(book.Title, newBook->Title);
    strcpy(book.Author,newBook->Author);
    newBook->Stock = 1;
    newBook->next = NULL;
    return newBook;
}

void InsertBook(Book **head, Book book){
    Book *temp = (Book*)malloc(sizeof(Book));
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Book *newBook = (Book*)malloc(sizeof(Book));
    newBook = CreateBook(book);
    temp->next = newBook;
}

int DeleteBook(Book **head, char bookID){
    Book *temp1 = (Book*)malloc(sizeof(Book));
    Book *temp2 = (Book*)malloc(sizeof(Book));
    //temp2在temp1后面
    temp1 = head;
    
    if(strcmp(temp1->Book_ID,bookID) && temp1 == head){
        return 1;
    }
    temp1 = temp1->next;
    temp2 = head;
    while(strcmp(temp1->Book_ID,bookID) != 1){
        if(temp1 == NULL){
            return 0;
        }
        else{
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    temp2->next = temp1->next;
    return 1;
}

int UpdataStock(Book *head, char bookID[],int newStock){
    Book *temp1 = (Book*)malloc(sizeof(Book));
    temp1 = head;
    while(strcmp(temp1->Book_ID,bookID) != 1){
        if(temp1 == NULL){
            return 0;
        }
        else{
            temp1 = temp1->next;
        }
    }

    temp1->Stock = newStock;
    return 1;
}

Book* FindBook(Book *head,char bookID[]){
    Book *temp1 = (Book*)malloc(sizeof(Book));
    temp1 = head;
    while(strcmp(temp1->Book_ID,bookID) != 1){
        if(temp1 == NULL){
            return NULL;
        }
        else{
            temp1 = temp1->next;
        }
    }

    printf("书号:%c,书名:%c,作者:%c,库存:%d",temp1->Book_ID,temp1->Title,temp1->Author,temp1->Stock);
    return temp1;
}

void TraverseList(Book *head){
    Book *temp1 = (Book*)malloc(sizeof(Book));
    temp1 = head;
    while(temp1->next != NULL){
        printf("书号:%c,书名:%c,作者:%c,库存:%d",temp1->Book_ID,temp1->Title,temp1->Author,temp1->Stock);
    }
}

*/