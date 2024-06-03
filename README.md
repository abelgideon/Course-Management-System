# Course Management System

This is a console-based Course Management System developed as a final project for the Computer Programming II course. It allows users to manage courses by adding, displaying, searching, updating, and deleting course records.

## Features

- **Create Course:** Users can add new courses with details such as course code, title, description, and credits.
- **Display Courses:** Users can view the list of all courses.
- **Search Courses:** Users can search for courses by course code.
- **Update Course:** Users can update course details.
- **Delete Course:** Users can delete a course by course code.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., GCC)
- Standard C++ Library

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/abelgideon/Course-Management-System.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Course-Management-System
    ```

### Compilation

Compile the project using a C++ compiler:
```sh
g++ -o courseManager courseManager.cpp
```

### Running

Run the compiled program:
```sh
./courseManager
```

## Usage

### Create Course:

- Choose the option to create a new course.
- Enter the course code, title, description, and credits.

### Display Courses:

- Choose the display option to view all courses.

### Search Courses:

- Choose the search option and enter the course code to search for a specific course.

### Update Course:

- Choose the update option and enter the course code to update its details.

### Delete Course:

- Choose the delete option and enter the course code to delete a course.

## File Structure

- courseManager.cpp: The main source file containing all the functionalities.
- courses.txt: Stores course records.

## Example

### Creating a Course

--- Course Management System ---
1. Create Course
2. Display Courses
3. Search Courses
4. Update Course
5. Delete Course
6. Exit

\>\> 1

Enter the course code: CS101

Enter the course name: Introduction to Computer Science

Enter the course's description: Basics of computer science

Enter the course's credits: 4

Do you want to enter more courses?(y/n): n

### Displaying Courses

--- Course Management System ---
1. Create Course
2. Display Courses
3. Search Courses
4. Update Course
5. Delete Course
6. Exit

\>\> 2

Course Code: CS101

Course Title: Introduction to Computer Science

Course Description: Basics of computer science

Course Credits: 4

### Searching for a Course

--- Course Management System ---
1. Create Course
2. Display Courses
3. Search Courses
4. Update Course
5. Delete Course
6. Exit

\>\> 3

Enter course code to search: CS101

Course Code: CS101

Course Title: Introduction to Computer Science

Course Description: Basics of computer science

Course Credits: 4

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.