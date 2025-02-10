# library-management
### Overview
This project is a simple Library Management System written in C. It allows users to manage books and issue them to students. The system provides functionalities such as:
- Adding books
- Viewing available books
- Removing books
- Issuing books to students
- Viewing issued book list
### Features
- Add Book: Allows the user to add a book with an ID, name, and author.
- View Book List: Displays all available books.
- Remove Book: Deletes a book based on its ID.
- Issue Book: Assigns a book to a student, recording their details.
- Issued Book List: Displays all books that have been issued to students.
- Exit: Terminates the program.
### Files Used
- `books.txt`: Stores book details.
- `issue.txt`: Stores issued book records.
### Code Structure
The program consists of the following key functions:
1. `main()`
- Displays the menu.
- Takes user input and calls appropriate functions.
- Uses a loop to keep the program running until the user chooses to exit.
2. `addBook()`
- Prompts user for book details.
- Writes them to `books.txt`.
3. `viewBookList()`
- Reads from `books.txt` and displays available books.
4. `removeBook()`
- Deletes a book based on its ID.
- Uses a temporary file to store all records except the one to be removed.
5. `issueBook()`
- Checks if the book exists.
- Asks for student details.
- Writes issued book information to issue.txt.
6. `viewIssuedBookList()`
- Reads from `issue.txt` and displays issued books.
### Limitations
- The program does not check for duplicate book IDs.
- Data persistence is limited to text files; no database is used.
- No authentication system is implemented.
