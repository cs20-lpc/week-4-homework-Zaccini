#include <iostream>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
using namespace std;

int main() {
	LinkedList<Student> studentList;
	int choice;

	while (true) {
		cout << "1. Insert Student\n";
		cout << "2. Delete Student\n";
		cout << "3. Search Student\n";
		cout << "4. Display All\n";
		cout << "5. Count Students\n";
		cout << "6. Add a course\n";
		cout << "7. Exit\n";
		cout << endl << "Enter choice: ";
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		switch (choice) {
			case 1: {
				int id;
				string name;
				double gpa;
				cout << "Enter Student ID: ";
				cin >> id;
				if (cin.fail() || id < 1) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid ID. Please enter a positive integer.\n";
					continue;
				}
				cout << "Enter Student Name: ";
				cin >> name;
				cout << "Enter Student GPA: ";
				cin >> gpa;
				if (cin.fail() || gpa < 1) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid GPA. Please enter a positive number.\n";
					continue;
				}
				Student s(id, name, gpa);
				studentList.append(s);
				break;
			}
			case 2: {
				int id;
				cout << "Enter Student ID to delete: ";
				cin >> id;
				if (cin.fail() || id < 1) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid ID. Please enter a positive integer.\n";
					continue;
				}
				bool found = false;
				for (int i = 0; i < studentList.getLength(); i++) {
					Student s = studentList.getElement(i);
					if (s.getId() == id) {
						studentList.remove(i);
						cout << "Student with ID " << id << " deleted.\n";
						found = true;
						break;
					}
				}
				if (!found) {
					cout << "Student with ID " << id << " not found.\n";
				}
				break;
			}
			case 3: {
				int id;
				cout << "Enter Student ID to search: ";
				cin >> id;
				if (cin.fail() || id < 1) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid ID. Please enter a positive integer.\n";
					continue;
				}
				bool found = false;
				for (int i = 0; i < studentList.getLength(); i++) {
					Student s = studentList.getElement(i);
					if (s.getId() == id) {
						cout << "Name: " << s.getName() << "\n GPA: " << s.getGpa() << endl;
						found = true;
						break;
					}
				}
				if (!found) {
					cout << "Student with ID " << id << " not found.\n";
				}
				break;
			}
			case 4: {
				cout << "Students in List:\n";
				cout << studentList;
				break;
			}
			case 5: {
				cout << "Total students: " << studentList.getLength() << endl;
				break;
			}
			case 6: {
				int id;
				cout << "Enter Student ID to add course: ";
				cin >> id;
				if (cin.fail() || id < 1) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid ID. Please enter a positive integer.\n";
					continue;
				}
				bool found = false;
				for (int i = 0; i < studentList.getLength(); ++i) {
					Student s = studentList.getElement(i);
					if (s.getId() == id) {
						string courseName, location;
						cout << "Enter Course Name: ";
						cin >> courseName;
						cout << "Enter Location: ";
						cin >> location;
						Course c(courseName, location);
						s.addCourse(c);
						studentList.replace(i, s);
						cout << "Course added to student ID " << id << ".\n";
						found = true;
						break;
					}
				}
				if (!found) {
					cout << "Student with ID " << id << " not found.\n";
				}
				break;
			}
			case 7: {
				return 0;
			}
			default:
				cout << "Invalid choice. Please select a number from 1 to 7.\n";
				break;
		}
	}
}
