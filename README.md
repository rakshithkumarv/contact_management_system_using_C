
# Contact Management System

## Overview

The Contact Management System is a command-line application for managing your personal contacts. It allows you to perform various contact-related tasks such as adding, displaying, searching, and deleting contacts.

## Features

### 1. **Add Contacts**

You can easily add new contacts by providing the contact's name, mobile number, and email. The system will validate the provided data to ensure correctness.

### 2. **Display Contacts**

View your contact list in an organized manner. The application lists all your contacts, showing their name, mobile number, and email.

### 3. **Search Contacts**

Search for a specific contact by entering the name. The system will display the contact's details if it exists in your contact list.

### 4. **Delete Contacts**

Remove a contact from your list by providing the name. The system will remove the contact, and it will no longer appear in your contact list.

### 5. **Data Persistence**

Contacts are saved to a text file (`contacts.txt`) and loaded from it. This feature ensures your contacts are stored even after closing the program. The data is stored in a simple text format for easy access and modification.

### 6. **Error Handling**

The program includes error handling and validation for email and mobile numbers to ensure data correctness.

### 7. **Contact Capacity Limitation**

To avoid exceeding the array size, there's a predefined limit of 100 contacts. This limitation helps ensure efficient memory usage and prevents potential crashes due to excessive contact entries.

## Getting Started

1. **Compile the Program:**
    - Compile the program using a C compiler. For example, if you're using GCC, you can compile it with `gcc contact_manager.c -o contact_manager`.

2. **Run the Program:**
    - Run the compiled program using `./contact_manager`.

3. **Interact with the System:**
    - Follow the on-screen menu to add, display, search, and delete contacts.

4. **Exiting the Program:**
    - To exit the program, choose the "EXIT" option in the main menu. This will save your contacts to `contacts.txt` for future use.

## File Management

- The contact data is saved to a file named `contacts.txt`.
- When the program starts, it loads existing contacts from `contacts.txt`, if any.
- When you add, delete, or modify a contact, the data in `contacts.txt` is updated accordingly.
- You can back up this file to prevent data loss.

