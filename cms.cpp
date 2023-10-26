#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact
{
    char name[100];
    char mobileno[100];
    char email[200];
};

struct contact s[MAX_CONTACTS];
int count = 0;

void addition();
void display();
void search();
void deletion();
void saveContacts();
void loadContacts();

int main()
{
    loadContacts();

    int choice;
    while (1)
    {
        printf("\nCONTACT MANAGEMENT SYSTEM\n1) ADD\n2) SEARCH\n3) DELETE\n4) CONTACT BOOK\n5) EXIT\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addition();
            break;
        case 2:
            search();
            break;
        case 3:
            deletion();
            break;
        case 4:
            display();
            break;
        case 5:
            saveContacts();
            exit(0);
        default:
            printf("\nPlease Enter a Valid Choice\n");
            break;
        }
    }
    return 0;
}

void addition()
{
    if (count < MAX_CONTACTS)
    {
        printf("Enter the Name: ");
        scanf("%s", s[count].name);
        printf("Enter the Mobile Number: ");
        scanf("%s", s[count].mobileno);
        printf("Enter the Email: ");
        scanf("%s", s[count].email);
        count++;
        printf("Contact added successfully.\n");
    }
    else
    {
        printf("Contact list is full.\n");
    }
}

void display()
{
    if (count == 0)
    {
        printf("No contacts to display.\n");
    }
    else
    {
        printf("\n----- CONTACT BOOK -----\n");
        for (int i = 0; i < count; i++)
        {
            printf("Name: %s\nMobile Number: %s\nEmail: %s\n\n", s[i].name, s[i].mobileno, s[i].email);
        }
        printf("------------------------\n");
    }
}

void saveContacts()
{
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %s\n", s[i].name, s[i].mobileno, s[i].email);
    }

    fclose(file);
    printf("Contacts saved successfully.\n");
}

void loadContacts()
{
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL)
    {
        printf("No contacts found.\n");
        return;
    }

    while (fscanf(file, "%s %s %s", s[count].name, s[count].mobileno, s[count].email) != EOF)
    {
        count++;
    }

    fclose(file);
    printf("Contacts loaded successfully.\n");
}

void search()
{
    char searchName[100];
    printf("Enter the Name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(s[i].name, searchName) == 0)
        {
            printf("Name: %s\nMobile Number: %s\nEmail: %s\n", s[i].name, s[i].mobileno, s[i].email);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void deletion()
{
    char deleteName[100];
    printf("Enter the Name to delete: ");
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(s[i].name, deleteName) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(s[j].name, s[j + 1].name);
                strcpy(s[j].mobileno, s[j + 1].mobileno);
                strcpy(s[j].email, s[j + 1].email);
            }
            count--;
            printf("Contact successfully deleted.\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found.\n");
    }
}
