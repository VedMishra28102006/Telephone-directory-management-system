#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 256

struct contact {
    char name[30];
    int number;
};

struct contact contacts[MAX_SIZE]; int id = 0;

void menu() {
    int choice;
    printf("1. Create a contact\n");
    printf("2. View a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n\n");
    
    printf("Enter item number:");
    scanf(" %d", &choice);
    if (choice == 1) Ccon();
    else if (choice == 2) Vcon();
    else if (choice == 3) Ucon();
    else if (choice == 4) Dcon();
    else if (choice == 5) exit(0);
    else { printf("Invalid input\n"); menu(); }
}

void Ccon() {
    if (id == MAX_SIZE) {
        printf("Max contact limit reached\n");
        menu();
    } char c;
    printf("Go back to menu? y/n");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        printf("Enter contact name:");
        scanf(" %30[^\n]", contacts[id].name);
        printf("Enter contact number:");
        scanf("%d", &contacts[id].number);
        int found = 0;
        for (int i=0; i < id; i++)
            if (contacts[i].number == contacts[id].number) {
                found = 1; break;
            }
        if (found) printf("A contact with the same number exists\n");
        else id++;
        Ccon();
    }
}

void Vcon() {
    char c;
    printf("Go back to menu? y/n");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else if (id == 0) {
        printf("No contacts to retrieve\n");
        menu();
    } else {
        char name[30];
        printf("Enter contact name:");
        scanf(" %30[^\n]", name);
        int found = 0;
        for (int i=0; i < id; i++)
            if (strcmp(contacts[i].name, name) == 0) {
                found = 1;
                printf("Number: %d\n", contacts[i].number);
            }
        if (!found) printf("No such contact\n");
        Vcon();
    }
}

void Ucon() {
    char c;
    printf("Go back to menu? y/n");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        int number;
        printf("Enter contact number:"); scanf(" %d", &number);
        int i; int found = 0;
        for (i = 0; i < id; i++) if(contacts[i].number == number) {
            found = 1; break;
        }
        if (!found) { printf("No such contact\n"); }
        else {
            printf("Enter new name:");
            scanf(" %30[^\n]", contacts[i].name);
            printf("Enter new number:");
            scanf("%d", &contacts[i].number);
        } Ucon();
    }
}

void Dcon() {
    char c;
    printf("Go back to menu? y/n");
    scanf(" %c", &c);
    if (c != 'n') menu();
    else {
        int number;
        printf("Enter contact number:");
        scanf(" %d", &number);
        int i, found = 0;
        for (i=0; i < id; i++) if (contacts[i].number == number) {
            found = 1; break;
        }
        if (!found) { printf("No such contact\n"); }
        else {
            for (; i < id-1; i++) contacts[i] = contacts[i+1];
            id--;
        }
        Dcon();
    }
}

int main() {
    menu();
    return 0;
}
