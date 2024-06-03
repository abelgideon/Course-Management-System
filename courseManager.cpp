#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

struct Course
{
    string courseCode;
    string title;
    string description;
    int credits;
};

int acceptCourse(Course courses[])
{
    int i = 0;
    string choice;

    do
    {
        cout << "Enter the course code: ";
        cin >> courses[i].courseCode;
        cin.ignore();

        cout << "Enter the course name: ";
        getline(cin, courses[i].title);

        cout << "Enter the course's description: ";
        getline(cin, courses[i].description);

        cout << "Enter the course's credits: ";
        while (!(cin >> courses[i].credits))
        {
            cout << "Invalid input.\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        i++;

        cout << "Do you want to enter more courses?(y/n): ";
        cin >> choice;
    } while (choice == "y");

    return i;
}

void saveCourse(Course courses[], int n, fstream &f)
{
    f.open("courses.txt", ios::app);
    if (f)
    {
        for (int i = 0; i < n; i++)
        {
            f << courses[i].courseCode << "," << courses[i].title << "," << courses[i].description << "," << courses[i].credits << endl;
        }
    }
    else
    {
        cout << "Error opening file." << endl;
    }
    f.close();
}

int getFileSize(fstream &f)
{
    string str;
    int lines = 0;

    f.open("courses.txt", ios::in);
    if (f)
    {
        while (getline(f, str))
            lines++;
    }
    else
    {
        cout << "Error opening file." << endl;
    }

    f.close();
    return lines;
}

Course *readCourse(fstream &f, int lines)
{
    Course *courses = new Course[lines];

    f.open("courses.txt", ios::in);

    if (f)
    {
        for (int i = 0; i < lines; i++)
        {
            getline(f, courses[i].courseCode, ',');
            getline(f, courses[i].title, ',');
            getline(f, courses[i].description, ',');
            f >> courses[i].credits;
            f.ignore();
        }
    }
    else
    {
        cout << "Error opening file." << endl;
    }

    f.close();
    return courses;
}

void searchCourse(Course courses[], int lines)
{
    bool isFound = false;
    string search;
    cout << "Enter course code to search: ";
    cin >> search;

    for (int i = 0; i < lines; i++)
    {
        if (courses[i].courseCode == search)
        {
            cout << "Course Code: " << courses[i].courseCode << endl;
            cout << "Course Title: " << courses[i].title << endl;
            cout << "Course Description: " << courses[i].description << endl;
            cout << "Course Credits: " << courses[i].credits << endl;
            cout << endl;
            isFound = true;
        }
    }

    if (!isFound)
    {
        cout << "Course not found." << endl;
    }
}

void updateCourse(Course courses[], fstream &f, int lines)
{
    bool isFound = false;
    string code;
    cout << "Enter course code to update: ";
    cin >> code;

    for (int i = 0; i < lines; i++)
    {
        if (courses[i].courseCode == code)
        {
            isFound = true;
            int choice;

            cout << "1. Update course code\n2. Update course title\n3. Update course description\n4. Update course credits\n5. Back\n>> ";
            while (!(cin >> choice) || (choice < 1) || (choice > 5))
            {
                cout << "Invalid input.\n>> ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            if (choice == 1)
            {
                string newCourseCode;
                cout << "Enter new course code: ";
                cin >> newCourseCode;

                courses[i].courseCode = newCourseCode;
            }
            else if (choice == 2)
            {
                string newCourseTitle;
                cout << "Enter new course title: ";
                getline(cin, newCourseTitle);

                courses[i].title = newCourseTitle;
            }
            else if (choice == 3)
            {
                string newCourseDescription;
                cout << "Enter new course description: ";
                getline(cin, newCourseDescription);

                courses[i].description = newCourseDescription;
            }
            else if (choice == 4)
            {
                int newCredits;
                cout << "Enter new course credits: ";
                while (!(cin >> newCredits))
                {
                    cout << "Invalid input.\n>> ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                courses[i].credits = newCredits;
            }
            else if (choice == 5)
            {
                return;
            }
        }
    }

    if (!isFound)
    {
        cout << "Course not found." << endl;
        return;
    }

    f.open("courses.txt", ios::out);

    if (f)
    {
        for (int i = 0; i < lines; i++)
        {
            f << courses[i].courseCode << "," << courses[i].title << "," << courses[i].description << "," << courses[i].credits << endl;
        }
        cout << "Course updated." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }

    f.close();
}

void deleteCourse(Course courses[], fstream &f, int lines)
{
    int indexToDelete = -1;
    string code;
    cout << "Enter course code to delete: ";
    cin >> code;

    for (int i = 0; i < lines; i++)
    {
        if (courses[i].courseCode == code)
        {
            string choice;
            cout << "Are you sure you want to delete " << courses[i].title << "?(y/n): ";
            cin >> choice;

            if (choice == "y")
            {
                indexToDelete = i;
                break;
            }
            else
            {
                return;
            }
        }
    }

    if (indexToDelete == -1)
    {
        cout << "Course not found." << endl;
        return;
    }

    for (int i = indexToDelete; i < lines - 1; i++)
    {
        courses[i] = courses[i + 1];
    }
    lines--;

    f.open("courses.txt", ios::out);

    if (f)
    {
        for (int i = 0; i < lines; i++)
        {
            f << courses[i].courseCode << "," << courses[i].title << "," << courses[i].description << "," << courses[i].credits << endl;
        }
        cout << "Course Deleted." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
    f.close();
}

void display(Course courses[], int lines)
{
    for (int i = 0; i < lines; i++)
    {
        cout << "Course Code: " << courses[i].courseCode << endl;
        cout << "Course Title: " << courses[i].title << endl;
        cout << "Course Description: " << courses[i].description << endl;
        cout << "Course Credits: " << courses[i].credits << endl;
        cout << endl;
    }
}

int main()
{
    Course *courses = new Course[100];
    fstream f;
    Course *readCourses;
    int lines;

    int choice;

    while (true)
    {
        cout << "------------------------" << endl;
        cout << "Course Management System" << endl;
        cout << "------------------------" << endl;

        cout << "1. Create Course\n2. Display Courses\n3. Search Courses\n4. Update Course\n5. Delete Course\n6. Exit\n>> ";
        while (!(cin >> choice) || (choice < 1) || (choice > 6))
        {
            cout << "Invalid input.\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 1)
        {
            int numCourses = acceptCourse(courses);
            saveCourse(courses, numCourses, f);
        }
        else if (choice == 2)
        {
            lines = getFileSize(f);
            readCourses = readCourse(f, lines);
            display(readCourses, lines);
        }
        else if (choice == 3)
        {
            lines = getFileSize(f);
            readCourses = readCourse(f, lines);
            searchCourse(readCourses, lines);
        }
        else if (choice == 4)
        {
            lines = getFileSize(f);
            readCourses = readCourse(f, lines);
            updateCourse(readCourses, f, lines);
        }
        else if (choice == 5)
        {
            lines = getFileSize(f);
            readCourses = readCourse(f, lines);
            deleteCourse(readCourses, f, lines);
        }
        else if (choice == 6)
        {
            break;
        }
    }
}