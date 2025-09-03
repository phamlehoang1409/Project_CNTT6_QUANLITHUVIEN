#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_BORROWED 10

struct Date {
    int day, month, year;
};

struct Book {
    char bookId[10];
    char title[30];
    char author[20];
    int quantity;
    int price;
    struct Date publication;
};


struct Book books[MAX_BOOKS];
int bookCount = 0;


void printBook(struct Book b) {
    printf("ID: %s | Ten: %s | Tac gia: %s | SL: %d | Gia: %d | Xuat ban: %d/%d/%d\n",
           b.bookId, b.title, b.author, b.quantity, b.price,
           b.publication.day, b.publication.month, b.publication.year);
}


void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Danh sach da day\n");
        return;
    }
    struct Book b;
    printf("Nhap ID sach: ");
    scanf("%s", b.bookId);
    for (int i=0; i<bookCount; i++) {
        if (strcmp(books[i].bookId, b.bookId) == 0) {
            printf("ID sach da ton tai\n");
            return;
        }
    }
    getchar();
    printf("Nhap ten sach: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Nhap tac gia: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    printf("Nhap so luong: ");
    scanf("%d", &b.quantity);

    printf("Nhap gia: ");
    scanf("%d", &b.price);
    printf("Nhap ngay xuat ban (dd mm yyyy): ");
    scanf("%d %d %d", &b.publication.day, &b.publication.month, &b.publication.year);
    getchar();

    books[bookCount++] = b;
    printf("Them thanh cong");
}

void listBooks() {
    if (bookCount == 0) {
        printf("Chua co sach\n");
        return;
    }
    for (int i=0; i<bookCount; i++) {
        printBook(books[i]);
    }
}

void deleteBook() {
    char id[10];
    printf("Nhap ID sach muon xoa: ");
    scanf("%s", id);
    for (int i=0; i<bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            for (int j=i; j<bookCount-1; j++) {
                books[j] = books[j+1];
            }
            bookCount--;
            printf("Da xoa\n");
            return;
        }
    }
    printf("Khong tim thay\n");
}

void searchBook() {
    char keyword[30];
    getchar();
    printf("Nhap ten sach can tim: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    for (int i=0; i<bookCount; i++) {
        if (strstr(books[i].title, keyword) != NULL) {
            printBook(books[i]);
        }
    }
}

void sortBooksByPrice() {
    for (int i=0; i<bookCount-1; i++) {
        for (int j=i+1; j<bookCount; j++) {
            if (books[i].price > books[j].price) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep xong\n");
}


void menu() {
        printf("\n===== QUAN LY THU VIEN =====\n");
        printf("1. Them sach\n");
        printf("2. Hien thi sach\n");
        printf("3. Xoa sach\n");
        printf("4. Tim kiem sach\n");
        printf("5. Sap xep sach theo gia\n");
        printf("0. Thoat\n");
        printf("Chon: ");
    }

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1: addBook();break;
            case 2: listBooks(); break;
            case 3: deleteBook(); break;
            case 4: searchBook(); break;
            case 5: sortBooksByPrice(); break;
            case 0: printf("Thoat chuong trinh\n"); break;

            default:
                printf("Lua chon khong hop le\n"); break;
        }


    } while (choice != 0);
    return 0;
}
