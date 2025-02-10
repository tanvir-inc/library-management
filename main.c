#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct books{
int id;
char bookName[50];
char authorName[50];
}b;

struct student{
int id;
char sName[50];
char sClass[50];
int sRoll;
char bookName[50];
}s;

FILE*fp;

int main(){
int n;
while(1){
system("cls");
printf("<== Library Management System ==>\n\n");
printf("1. Add Book\n");
printf("2. View Book List\n");
printf("3. Remove Book\n");
printf("4. Issue Book\n");
printf("5. Issued Book List\n");
printf("0. Exit\n\n");
printf("Enter your choice: ");
scanf("%d",&n);

switch(n){

case 0: exit(0);

case 1: addBook();
break;

case 2: viewBookList();
break;

case 3: removeBook();
break;

case 4: issueBook();
break;

case 5: viewIssuedBookList();
break;

default: printf("Invalid Choice!\n");
}
printf("Press any button to continue...");
getch();
}
return 0;
}

void addBook(){
fp=fopen("books.txt","ab");
printf("Enter Book ID: ");
scanf("%d",&b.id);
printf("Enter Book Name: ");
fflush(stdin);
gets(b.bookName);
printf("Enter Author Name: ");
fflush(stdin);
gets(b.authorName);
printf("\nBook Added Successfully.\n\n");
fwrite(&b,sizeof(b),1,fp);
fclose(fp);
}

void viewBookList(){
system("cls");
printf("<== Available Books ==>\n\n");
printf("%-10s %-30s %-20s\n", "Book ID", "Book Name", "Author Name");
fp = fopen("books.txt", "rb");
while (fread(&b, sizeof(b), 1, fp) == 1) {
printf("%-10d %-30s %-20s\n", b.id, b.bookName, b.authorName);
}
fclose(fp);
}

void removeBook(){
int id, f = 0;
system("cls");
printf("<== Remove Book ==>\n");
printf("Enter Book ID: ");
scanf("%d", &id);
FILE* ft;
fp = fopen("books.txt", "rb");
ft = fopen("tmp.txt", "wb");
while(fread(&b, sizeof(b),1,fp) == 1){
if (id == b.id) {
f = 1;
}
else{
fwrite(&b, sizeof(b), 1, ft);
}
}
fclose(fp);
fclose(ft);
if (f == 1){
printf("\nBook Removed Successfully.\n");
}
else {
printf("\nNo Book Found.\n");
}
remove("books.txt");
rename("tmp.txt", "books.txt");
}

void issueBook(){
int f = 0;
system("cls");
printf("\n<== Issue Book ==>\n");
printf("Enter Book ID: ");
scanf("%d", &s.id);
fp = fopen("books.txt", "rb");
while (fread(&b, sizeof(b), 1, fp) == 1){
if (b.id == s.id){
strncpy(s.bookName, b.bookName, sizeof(s.bookName) - 1);
s.bookName[sizeof(s.bookName) - 1] = '\0';
f = 1;
break;
}
}
fclose(fp);
if (f == 0) {
printf("\nNo Book Found With This ID.");
printf("\nTry Again With Another ID.");
return;
}
fp = fopen("issue.txt", "ab");
printf("Enter Student Name: ");
fflush(stdin);
fgets(s.sName, sizeof(s.sName),stdin);
s.sName[strcspn(s.sName, "\n")] = '\0';
printf("Enter Class: ");
fflush(stdin);
fgets(s.sClass, sizeof(s.sClass), stdin);
s.sClass[strcspn(s.sClass, "\n")] = '\0';
printf("Enter Roll: ");
scanf("%d", &s.sRoll);
fwrite(&s, sizeof(s),1,fp);
fclose(fp);
}

void viewIssuedBookList(){
system("cls");
printf("\n<== Issued Book ==>\n");
printf("%-10s %-30s %-20s %-10s %-30s\n","S.id","Name","Class","Roll","Book Name"); fp=fopen("issue.txt","rb");
while(fread(&s,sizeof(s),1,fp)==1){
printf("%-10d %-30s %-20s %-10d %-30s\n",s.id,s.sName,s.sClass,s.sRoll,s.bookName);
}
fclose(fp);
}
