# Student Management System (C++)

A console-based Student Management System built in C++ as a data structures mini-project. It manages student records using an array and demonstrates three classic data structures — **stack**, **queue**, and **linked list** — each used for a distinct, realistic purpose rather than just for show.

## Features

| # | Menu Option | What it does |
| 1 | Add Student | Adds a new student (roll number, name, marks) to the records |
| 2 | Display Students | Lists all currently stored student records |
| 3 | Search Student | Finds a student by roll number |
| 4 | Delete Student | Removes a student by roll number and shifts remaining records |
| 5 | Add Student to Waiting Queue | Adds a name to an admission waiting queue |
| 6 | Serve Waiting Student | Serves (removes) the next student in the waiting queue |
| 7 | Display Student List | Prints all student names via a linked list |
| 8 | Display Last Deleted Student | Shows the most recently deleted student's details |
| 9 | Exit | Ends the program |

## Data Structures Used

- **Array (`Student students[5]`)** — the primary storage for active student records. Chosen because it's the simplest structure for fixed-size, indexed record storage and supports fast search/display by index.
- **Stack (`stack<Student> deletedStudents`)** — stores deleted students. A stack fits naturally here because "last deleted, first shown" (LIFO) is exactly how option 8 (*Display Last Deleted Student*) behaves.
- **Queue (`queue<string> waitingQueue`)** — models an admission waiting list. Students are served in the order they joined (FIFO), which is what a real waiting queue should do.
- **Linked List (`list<string> studentList`)** — stores student names separately, demonstrating traversal and dynamic insertion independent of the array.

Using four different structures for four different jobs (rather than forcing everything into one) is the actual point of the project — each structure was picked because its behavior (LIFO / FIFO / indexed / linked) matches the task.

## How to Compile and Run

Requires a C++ compiler (e.g. `g++`, part of GCC).

```
g++ student_management.cpp -o student_management
./student_management        (or student_management.exe on Windows)
```

## Known Limitations

- The student array has a fixed size of 5 — adding a 6th student will show "Student storage is full." This keeps the project simple; a dynamic structure (e.g. `vector<Student>`) would remove this limit.
- `cin >> name` reads a single word, so names with spaces (e.g. "John Smith") will only capture the first word. Using `cin.getline()` or `std::getline(cin, name)` would fix this.
- No file handling — all data is lost when the program exits.

## Possible Extensions

- Replace the fixed array with `vector<Student>` to remove the 5-student limit
- Add file handling to save/load records between runs
- Add sorting (e.g. by marks or roll number) using the array
- Support full names with spaces in queue/list entries

## License

Feel free to use, modify, and learn from this project.
