#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isIssued;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, b.title);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter ISBN: ";
    cin >> b.isbn;

    b.isIssued = false;
    library.push_back(b);

    cout << "Book added successfully!\n";
}

void searchBook() {
    string key;
    cout << "Enter title / author / ISBN to search: ";
    cin.ignore();
    getline(cin, key);

    bool found = false;
    for (auto b : library) {
        if (b.title == key || b.author == key || b.isbn == key) {
            cout <<endl<<"Book Found:";
            cout <<endl<<"Title: " << b.title;
            cout <<endl<<"Author: " << b.author;
            cout <<endl<<"ISBN: " << b.isbn;
            cout <<endl<<"Status: " << (b.isIssued ? "Issued" : "Available") << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Book not found!\n";
}

void issueBook() {
    string isbn;
    cout << "Enter ISBN to issue: ";
    cin >> isbn;

    for (auto &b : library) {
        if (b.isbn == isbn) {
            if (b.isIssued) {
                cout << "Book already issued!\n";
            } else {
                b.isIssued = true;
                cout << "Book issued successfully!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook() {
    string isbn;
    int days;
    cout << "Enter ISBN to return: ";
    cin >> isbn;

    for (auto &b : library) {
        if (b.isbn == isbn) {
            b.isIssued = false;
            cout << "Enter late days (0 if none): ";
            cin >> days;

            if (days > 0) {
                cout << "Fine: Rs " << days * 5 << endl;
            } else {
                cout << "No fine.\n";
            }
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
