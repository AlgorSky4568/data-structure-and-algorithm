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

