#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    float marks;
};

int main()
{
    // Array - stores student records
    Student students[5];
    int count = 0;

    // Stack - stores recently deleted students
    stack<Student> deletedStudents;

    // Queue - stores students waiting for admission
    queue<string> waitingQueue;

    // Linked List - stores student names
    list<string> studentList;

    int choice;
    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Add Student to Waiting Queue\n";
        cout << "6. Serve Waiting Student\n";
        cout << "7. Display Student List\n";
        cout << "8. Display Last Deleted Student\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                if (count < 5)
                {
                    cout << "Enter Roll Number: ";
                    cin >> students[count].rollNo;

                    cout << "Enter Name: ";
                    cin >> students[count].name;

                    cout << "Enter Marks: ";
                    cin >> students[count].marks;

                    studentList.push_back(students[count].name);

                    count++;
                    cout << "Student added successfully.\n";
                }
                else
                {
                    cout << "Student storage is full.\n";
                }
                break;

            case 2:
                if (count == 0)
                {
                    cout << "No students available.\n";
                }
                else
                {
                    cout << "\n--- Student Records ---\n";

                    for (int i = 0; i < count; i++)
                    {
                        cout << "Roll No: " << students[i].rollNo
                             << ", Name: " << students[i].name
                             << ", Marks: " << students[i].marks
                             << endl;
                    }
                }
                break;

            case 3:
            {
                int roll, found = 0;
                cout << "Enter Roll Number to search: ";
                cin >> roll;

                for (int i = 0; i < count; i++)
                {
                    if (students[i].rollNo == roll)
                    {
                        cout << "Student Found!\n";
                        cout << "Name: " << students[i].name << endl;
                        cout << "Marks: " << students[i].marks << endl;
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    cout << "Student not found.\n";
                break;
            }

            case 4:
            {
                int roll, found = -1;

                cout << "Enter Roll Number to delete: ";
                cin >> roll;

                for (int i = 0; i < count; i++)
                {
                    if (students[i].rollNo == roll)
                    {
                        found = i;
                        break;
                    }
                }

                if (found != -1)
                {
                    deletedStudents.push(students[found]);

                    for (int i = found; i < count - 1; i++)
                    {
                        students[i] = students[i + 1];
                    }

                    count--;

                    cout << "Student deleted successfully.\n";
                }
                else
                {
                    cout << "Student not found.\n";
                }

                break;
            }

            case 5:
            {
                string name;

                cout << "Enter student name: ";
                cin >> name;

                waitingQueue.push(name);

                cout << name << " added to waiting queue.\n";
                break;
            }

            case 6:
                if (waitingQueue.empty())
                {
                    cout << "Waiting queue is empty.\n";
                }
                else
                {
                    cout << "Serving student: "
                         << waitingQueue.front() << endl;

                    waitingQueue.pop();
                }
                break;

            case 7:
                cout << "\n--- Student Linked List ---\n";

                if (studentList.empty())
                {
                    cout << "List is empty.\n";
                }
                else
                {
                    for (string name : studentList)
                    {
                        cout << name << " -> ";
                    }

                    cout << "NULL\n";
                }
                break;

            case 8:
                if (deletedStudents.empty())
                {
                    cout << "No student has been deleted.\n";
                }
                else
                {
                    cout << "\nLast Deleted Student:\n";
                    cout << "Roll No: "
                         << deletedStudents.top().rollNo << endl;
                    cout << "Name: "
                         << deletedStudents.top().name << endl;
                    cout << "Marks: "
                         << deletedStudents.top().marks << endl;
                }
                break;

            case 9:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
