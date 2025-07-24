#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 256

struct contact {
    char name[31];
    int number;
};

struct contact contacts[MAX_SIZE]; int id = 0;

void menu(), Ccon(), Vcon(), Ucon(), Dcon(), Allcon();

void menu() {
    char tempc[1];
    int choice;
    printf("1. Create a contact\n");
    printf("2. View a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. All contacts\n");
    printf("6. Exit\n\n");
    
    printf("Enter item number:");
    scanf(" %1[^\n]", tempc);
    choice = atoi(tempc);
    if (choice) {
        if (choice == 1) Ccon();
        else if (choice == 2) Vcon();
        else if (choice == 3) Ucon();
        else if (choice == 4) Dcon();
        else if (choice == 5) Allcon();
        else if (choice == 6) exit(0);
        else { printf("Invalid input\n\n"); menu(); }
    } else { printf("Invalid input\n\n"); menu(); }
}

void Ccon() {
    if (id == MAX_SIZE) {
        printf("\nMax contact limit reached\n\n");
        menu();
    } char c;
    printf("\nGo back to menu? y/n:");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        char tempnum[20];
        int number;
        printf("\nEnter contact name:");
        scanf(" %30[^\n]", contacts[id].name);
        printf("Enter contact number:");
        scanf(" %20[^\n]", tempnum);
        number = atoi(tempnum);
        if (number) {
            contacts[id].number = number;
            int found = 0;
            for (int i=0; i < id; i++)
                if (contacts[i].number == contacts[id].number) {
                    found = 1; break;
                }
            if (found) printf("\nA contact with the same number exists\n\n");
            else id++;
        } else printf("\nInvalid number\n");
        Ccon();
    }
}

void Vcon() {
    char c;
    printf("\nGo back to menu? y/n:");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else if (id == 0) {
        printf("\nNo contacts to retrieve\n\n");
        menu();
    } else {
        char name[30];
        printf("\nEnter contact name:");
        scanf(" %30[^\n]", name);
        int found = 0;
        for (int i=0; i < id; i++)
            if (strcmp(contacts[i].name, name) == 0) {
                found = 1;
                printf("Number: %d\n", contacts[i].number);
            }
        if (!found) printf("\nNo such contact\n");
        Vcon();
    }
}

void Ucon() {
    char c;
    printf("\nGo back to menu? y/n:");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        char tempnum[20];
        int number;
        printf("\nEnter contact number:"); scanf(" %20[^\n]", tempnum);
        number = atoi(tempnum);
        if (number) {
            int i; int found = 0;
            for (i = 0; i < id; i++) if(contacts[i].number == number) {
                found = 1; break;
            }
            if (!found) { printf("\nNo such contact\n\n"); }
            else {
                char tempname[31];
                char tempnum2[20];
                int number2;
                printf("Enter new name:");
                scanf(" %30[^\n]", tempname);
                printf("Enter new number:");
                scanf(" %20[^\n]", tempnum2);
                number2 = atoi(tempnum2);
                if (number2) {
                    strcpy(contacts[i].name, tempname);
                    contacts[i].number = number2;
                    
                } else printf("\nInvalid number\n");
            }
        } else printf("\nInvalid number\n");
        Ucon();
    }
}

void Dcon() {
    char c;
    printf("\nGo back to menu? y/n:");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        char tempnum[20];
        int number;
        printf("Enter contact number:");
        scanf(" %20[^\n]", tempnum);
        number = atoi(tempnum);
        if (number) {
            int i, found = 0;
            for (i=0; i < id; i++) if (contacts[i].number == number) {
                found = 1; break;
            }
            if (!found) { printf("\nNo such contact\n\n"); }
            else {
                for (; i < id-1; i++) contacts[i] = contacts[i+1];
                id--;
            }
        } else printf("\nInvalid number\n");
        Dcon();
    }
}

void Allcon() {
    if (id == 0) {
        printf("\nNo contacts to retrieve\n\n");
        menu();
    } else {
        for (int i=0; i < id; i++)
            for (int j=i+1; j < id-1; j++)
                if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                    struct contact temp;
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
        for (int i=0; i < id; i++)
            printf("Name: %s\nNumber: %d\n\n", contacts[i].name, contacts[i].number);
        menu();
        
    }
}

int main() {
    menu();
    return 0;
}
