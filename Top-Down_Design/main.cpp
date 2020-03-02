#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#define GpaThreshHold 17
#define plus17GpaMaximumUnitsToTake 24
#define lower17GpaMaximumUnitsToTake 20

using namespace std;

struct CourseTime {
    string day;
    string startTime;
    string endTime;
};
typedef vector<CourseTime> CourseTimes;

struct Course {
    int id;
    string name;
    int units;
    CourseTimes schedule;
    int prerequisitesID;
};
typedef vector<Course> CourseTable;

struct StudentGrade {
    int id;
    float grade;
};
typedef vector<StudentGrade> GradesTable;


vector<string> readCsvFile(const string &filePath, size_t &columnsNumber);

CourseTable parseCourses(const vector<string> &dataRows, size_t numberOfColumns);

CourseTimes parseTime(const string &timeRow);

CourseTable getAllCourses(const string &filePath);

GradesTable parseGrades(const vector<string> &dataRows, size_t numberOfColumns);

GradesTable getAllGrades(const string &filePath);

CourseTable findAvailableCourses(const CourseTable &courses, const GradesTable &grades);

bool passCourseId(const Course &course, const GradesTable &grades, int &id);

bool passPrerequisites(const Course &course, const GradesTable &grades);

bool compareByUnitsAndName(const Course &course1, const Course &course2);

bool compareByName(const Course &course1, const Course &course2);

bool checkCoursesTimeConflicts(const CourseTable &chosenCourses, const Course &availableCourse);

int findMaximumAvailableUnitsToTake(const GradesTable &grades);

CourseTable findNextTermCourses(CourseTable availableCourses, const GradesTable &grades);

int main(int argc, char *argv[]) {
    CourseTable courses = getAllCourses(argv[1]);
    GradesTable grades = getAllGrades(argv[2]);

    CourseTable availableCourses = findAvailableCourses(courses, grades);

    CourseTable coursesForNextTerm = findNextTermCourses(availableCourses, grades);
    for (const auto &course : coursesForNextTerm)
        cout << course.id << endl;

}

// Extract each word in CSV file separated by comma
vector<string> readCsvFile(const string &filePath, size_t &columnsNumber) {

    ifstream inputFile(filePath);
    if (inputFile.fail()) {
        cerr << "Error Opening the file" << endl;
        inputFile.close();
        exit(1);
    }
    vector<string> row;
    string line, word, temp;

    getline(inputFile, line);
    columnsNumber = count(line.begin(), line.end(), ',') + 1;
    // read an entire row and store it in a string variable 'line'
    while (getline(inputFile, line)) {
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            // add all the column data of a row to a vector
            row.push_back(word);
        }
    }
    return row;
}

// For Parsing Courses File into CoursesTable Struct for further use
CourseTable parseCourses(const vector<string> &dataRows, size_t numberOfColumns) {
    CourseTable courses;
    Course newCourse = {};

    for (int numberOfRow = 0; numberOfRow < dataRows.size(); numberOfRow += numberOfColumns) {
        for (int numberOfColumn = 0; numberOfColumn < numberOfColumns; numberOfColumn++) {
            if (numberOfColumn == 0)
                newCourse.id = stoi(dataRows[numberOfColumn + numberOfRow]);
            if (numberOfColumn == 1)
                newCourse.name = dataRows[numberOfColumn + numberOfRow];
            if (numberOfColumn == 2)
                newCourse.units = stoi(dataRows[numberOfColumn + numberOfRow]);
            if (numberOfColumn == 3)
                newCourse.schedule = parseTime(dataRows[numberOfColumn + numberOfRow]);
            if (numberOfColumn == 4)
                newCourse.prerequisitesID = stoi(dataRows[numberOfColumn + numberOfRow]);
        }
        courses.push_back(newCourse);
    }
    return courses;
}

// For Parsing Each Class Time to Struct
CourseTimes parseTime(const string &timeRow) {
    CourseTimes time = {};
    CourseTime newTime = {};
    stringstream row(timeRow);
    string eachDayTime;
    int classTimeNumber = 0;
    while (getline(row, eachDayTime, '/')) {
        stringstream timeForEachClass(eachDayTime);
        string word;
        int rowInTimeForEachClass = 0;
        while (getline(timeForEachClass, word, '-') && rowInTimeForEachClass < 3) {
            if (rowInTimeForEachClass == 0)
                newTime.day = word;
            if (rowInTimeForEachClass == 1)
                newTime.startTime = word;
            if (rowInTimeForEachClass == 2)
                newTime.endTime = word;
            rowInTimeForEachClass++;
        }
        classTimeNumber++;
        time.push_back(newTime);
    }
    return time;
}

CourseTable getAllCourses(const string &filePath) {
    size_t numberOfColumns;
    vector<string> rows = readCsvFile(filePath, numberOfColumns);
    CourseTable courses = parseCourses(rows, numberOfColumns);
    return courses;
}

GradesTable parseGrades(const vector<string> &dataRows, size_t numberOfColumns) {
    GradesTable grade;
    StudentGrade newGrade = {};

    for (int numberOfRow = 0; numberOfRow < dataRows.size(); numberOfRow += numberOfColumns) {
        for (int numberOfColumn = 0; numberOfColumn < numberOfColumns; numberOfColumn++) {
            if (numberOfColumn == 0)
                newGrade.id = stoi(dataRows[numberOfColumn + numberOfRow]);
            if (numberOfColumn == 1)
                newGrade.grade = stof(dataRows[numberOfColumn + numberOfRow]);
        }
        grade.push_back(newGrade);
    }
    return grade;
}

GradesTable getAllGrades(const string &filePath) {
    size_t numberOfColumns;
    vector<string> rows = readCsvFile(filePath, numberOfColumns);
    GradesTable grades = parseGrades(rows, numberOfColumns);
    return grades;
}

CourseTable findAvailableCourses(const CourseTable &courses, const GradesTable &grades) {
    CourseTable availableCourseId;

    for (auto &course : courses) {
        for (auto &grade : grades) {
            int id = 0;
            if ((passPrerequisites(course, grades) && !passCourseId(course, grades, id)) ||
                (!passCourseId(course, grades, id) && course.prerequisitesID == 0)) {
                availableCourseId.push_back(course);
                break;
            }
        }
    }
    return availableCourseId;
}

bool passCourseId(const Course &course, const GradesTable &grades, int &id) {
    for (auto grade : grades)
        if (course.id == grade.id && grade.grade >= 10) {
            return true;
        }
    return false;
}

bool passPrerequisites(const Course &course, const GradesTable &grades) {
    for (auto grade : grades)
        if (course.prerequisitesID == grade.id && grade.grade >= 10) {
            return true;
        }
    return false;
}

bool compareByUnitsAndName(const Course &course1, const Course &course2) {
    if (course1.units == course2.units)
        return course1.name < course2.name;
    else
        return course1.units > course2.units;
}

bool compareByName(const Course &course1, const Course &course2) {
    return course1.name < course2.name;
}

int findMaximumAvailableUnitsToTake(const GradesTable &grades) {
    float sumOfGrades = 0;
    for (auto grade : grades)
        sumOfGrades += grade.grade;
    float gpa = sumOfGrades / grades.size();
    if (gpa >= GpaThreshHold)
        return plus17GpaMaximumUnitsToTake;
    else
        return lower17GpaMaximumUnitsToTake;
}

CourseTable findNextTermCourses(CourseTable availableCourses, const GradesTable &grades) {
    // To Find What is the maximum units to take for next term depending on GPA
    int MaximumUnitsToTake = findMaximumAvailableUnitsToTake(grades);

    // To sort available courses by their units and name for same course units
    sort(availableCourses.begin(), availableCourses.end(), compareByUnitsAndName);

    // To find if new course can be taken such that sum of units taken cant be larger than maximum units
    // And 2 different courses cant have conflicts in time
    CourseTable coursesForNextTerm;
    int sumOfUnitsTaken = 0;
    for (const auto &course : availableCourses) {
        if (sumOfUnitsTaken + course.units <= MaximumUnitsToTake &&
            checkCoursesTimeConflicts(coursesForNextTerm, course)) {
            coursesForNextTerm.push_back(course);
            sumOfUnitsTaken += course.units;
        }
    }
    sort(coursesForNextTerm.begin(), coursesForNextTerm.end(), compareByName);
    return coursesForNextTerm;
}

bool checkCoursesTimeConflicts(const CourseTable &chosenCourses, const Course &availableCourse) {
    for (const auto &takenCourse : chosenCourses) {
        for (const auto &availableTime : availableCourse.schedule) {
            for (const auto &takenTime : takenCourse.schedule) {
                if (availableTime.day == takenTime.day)
                    if (availableTime.startTime == takenTime.startTime && availableTime.endTime == takenTime.endTime)
                        return false;
            }
        }
    }
    return true;
}