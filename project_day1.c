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
    for (int i = 0; i < bookCount; i++) {
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
    if (scanf("%d %d %d", &b.publication.day, &b.publication.month, &b.publication.year) != 3 ||
        b.publication.day < 1 || b.publication.day > 31 ||
        b.publication.month < 1 || b.publication.month > 12 ||
        b.publication.year < 0) {
        printf("Ngay xuat ban khong hop le\n");
        getchar();
        return;
    }
    getchar();
    books[bookCount++] = b;
    printf("Them thanh cong\n");
}

void listBooks() {
    if (bookCount == 0) {
        printf("Chua co sach\n");
        return;
    }
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-28s | %-18s | %-8s | %-6s | %-12s |\n",
           "ID", "Ten sach", "Tac gia", "So luong", "Gia", "Xuat ban");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("| %-8s | %-28s | %-18s | %-8d | %-6d | %02d/%02d/%-4d |\n",
               books[i].bookId, books[i].title, books[i].author,
               books[i].quantity, books[i].price,
               books[i].publication.day, books[i].publication.month, books[i].publication.year);
    }
    printf("----------------------------------------------------------------------------------------------\n");
}

void deleteBook() {
    char id[10];
    printf("Nhap ID sach muon xoa: ");
    scanf("%s", id);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
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
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword) != NULL) {
            printBook(books[i]);
        }
    }
}

void sortBooksByPrice() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].price > books[j].price) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep xong\n");
}

void updateBook() {
    char id[10];
    printf("Nhap ID sach muon cap nhat: ");
    scanf("%s", id);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            getchar();
            printf("Nhap ten sach moi: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = 0;
            printf("Nhap tac gia moi: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;
            printf("Nhap so luong moi: ");
            scanf("%d", &books[i].quantity);
            printf("Nhap gia moi: ");
            scanf("%d", &books[i].price);
            printf("Nhap ngay xuat ban moi (dd mm yyyy): ");
            if (scanf("%d %d %d", &books[i].publication.day, &books[i].publication.month, &books[i].publication.year) != 3 ||
                books[i].publication.day < 1 || books[i].publication.day > 31 ||
                books[i].publication.month < 1 || books[i].publication.month > 12 ||
                books[i].publication.year < 0) {
                printf("Ngay xuat ban khong hop le\n");
                getchar();
                return;
            }
            getchar();
            printf("Cap nhat thanh cong\n");
            return;
        }
    }
    printf("Khong tim thay sach\n");
}

void menu() {
    printf("\n===== QUAN LY THU VIEN =====\n");
    printf("1. Them sach\n");
    printf("2. Hien thi sach\n");
    printf("3. Xoa sach\n");
    printf("4. Tim kiem sach\n");
    printf("5. Sap xep sach theo gia\n");
    printf("6. Sua sach\n");
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
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: deleteBook(); break;
            case 4: searchBook(); break;
            case 5: sortBooksByPrice(); break;
            case 6: updateBook(); break;
            case 0: printf("Thoat chuong trinh\n"); break;
            default: printf("Lua chon khong hop le\n"); break;
        }
    } while (choice != 0);
    return 0;
}
