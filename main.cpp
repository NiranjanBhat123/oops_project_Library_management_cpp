#include <iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;
unordered_map<int, string> staff;

class Library {
public:
    map<int, pair<string, int>> books;
    map<int, pair<string, int>> db;
    Library() {
        books[1] = {"C++", 1};
        books[2] = {"Python", 10};
        books[3] = {"Automata",5};
    }

    void display_books() {
        cout << "book id| Name |copies available\n";
        for (auto it: books) {
            cout << it.first << "\t\t" << it.second.first << "\t\t" << it.second.second << "\n";
        }
    }

    void display_db() {
        cout << "student id| Name |number of books issued\n";
        for (auto it: db) {
            cout << it.first << "\t\t" << it.second.first << "\t\t" << it.second.second << "\n";
        }
    }

    void issue(int id, int stud_id, string name) {
        if (books.find(id) == books.end() or books[id].second == 0 or db[stud_id].second == 2) {
            cout << "book not available\n";
            return;
        }
        books[id].second--;
        db[stud_id].first = name;
        db[stud_id].second++;
        cout << books[id].first << " issued succesfully\nThank you for Using Library services\n";
        return;
    }

    void give_back(int id, int stud_id, string bookname) {
        books[id].second++;
        books[id].first = bookname;
        db[stud_id].second--;
        cout << "Returned succesfully\nThank you for Using Library services\n";
        return;
    }
};

class Staff : public Library {

public:
    void add_book(Library &L) {
        int id, copies;
        string name;
        cout << "enter the ID of new book\n";
        cin >> id;
        cout << "enter the book name\n";
        cin >> name;
        cout << "enter the number of copies\n";
        cin >> copies;
        if (L.books.find(id) != L.books.end()) {
            cout << "book with similar ID already exists\n";
            return;
        }
        L.books[id].first = name;
        L.books[id].second += copies;
        cout << "book " << name << " added successfully\n";
        return;
    }
};


int main() {
    staff[1] = "Raju";
    staff[2] = "Harish";
    int command = 0;
    string name, bookname;
    int id, stud_id, opt;
    Library L;
    while (1) {
        cout << "\nenter usertype\n1 : student\n2 : staff\n";
        cin >> opt;
        if (opt == 1) {
            cout << "\nWelcome to the library\nEnter\n1 : view available books\n2 : borrow a book\n3 : Return a book\n";
            cin >> command;
            switch (command) {
                case 1 :
                    L.display_books();
                    break;
                case 2:

                    cout << "enter your name\n";
                    cin >> name;
                    cout << "enter your college ID\n";
                    cin >> stud_id;
                    cout << "enter the id of the book you want\n";
                    cin >> id;
                    L.issue(id, stud_id, name);
                    break;


                case 3:

                    cout << "enter your name\n";
                    cin >> name;
                    cout << "enter your college ID\n";
                    cin >> stud_id;
                    cout << "enter the id of the book to be returned\n";
                    cin >> id;
                    cout << "enter the name of the book\n";
                    cin >> bookname;
                    L.give_back(id, stud_id, bookname);
                    break;


                default:
                    cout << "invalid choice\n";

            }
        } else if (opt == 2) {
            Staff s;

            int staff_id;
            string staff_name;
            cout << "enter your staff ID\n";
            cin >> staff_id;
            cout << "enter your name\n";
            cin >> staff_name;
            if (staff.find(staff_id) == staff.end() or staff[staff_id] != staff_name) {
                cout << "invalid id\n";
            } else {
                int com;

                cout<< "Welcome Admin\n1 : add books\n2 : display student database\n3 : display books\n-1 : close the library\n";
                cin >> com;
                if (com == -1)break;
                switch (com) {
                    case 1:
                        s.add_book(L);
                        break;
                    case 2 :
                        s.display_db();
                        break;

                    case 3:
                        s.display_books();
                        break;

                    default:
                        cout << "invalid command\n";
                        break;
                }


            }


        }

    }


    return 0;
}
