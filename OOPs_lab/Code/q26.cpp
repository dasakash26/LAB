#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class GradeCard {
  string departmentName;
  string studentName;
  string rollNumber;
  int semester;
  vector<pair<string, int>> subjects; // Pair of subject name and marks
  double cgpa;

public:
  // Constructor to initialize the grade card
  GradeCard(const string &department, const string &name, const string &roll,
            int sem, const vector<pair<string, int>> &subj)
      : departmentName(department), studentName(name), rollNumber(roll),
        semester(sem), subjects(subj) {
    calculateCGPA();
  }

  // Function to calculate CGPA
  void calculateCGPA() {
    if (subjects.empty()) {
      cgpa = 0.0;
      return;
    }
    double totalMarks = 0;
    for (const auto &subject : subjects) {
      totalMarks += subject.second;
    }
    cgpa = totalMarks / subjects.size(); // Simplified CGPA calculation
  }

  // Function to display grade card details
  void display() const {
    cout << "Department: " << departmentName << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Semester: " << semester << endl;
    cout << "Subjects and Marks:" << endl;
    for (const auto &subject : subjects) {
      cout << "  " << subject.first << ": " << subject.second << endl;
    }
    cout << "CGPA: " << cgpa << endl;
  }

  // Getters
  double getCGPA() const { return cgpa; }

  string getStudentName() const { return studentName; }

  string getRollNumber() const { return rollNumber; }

  // Static function to find the student with the highest CGPA
  static GradeCard findTopper(const vector<GradeCard> &gradeCards) {
    if (gradeCards.empty()) {
      throw runtime_error("No grade cards available");
    }
    double maxCGPA = numeric_limits<double>::lowest();
    GradeCard topper = gradeCards[0];
    for (const auto &card : gradeCards) {
      if (card.getCGPA() > maxCGPA) {
        maxCGPA = card.getCGPA();
        topper = card;
      }
    }
    return topper;
  }
};

int main() {
  srand(time(0));

  vector<GradeCard> gradeCards;
  string department = "Computer Science";
  string subjectsArr[] = {"DSA", "OOPs", "DBMS", "CoA", "Maths"};

  // Create 60 grade cards with random data
  for (int i = 0; i < 94; ++i) {
    string name = "Student_" + to_string(i + 1);
    string roll = "0023110010" + to_string(i + 1);
    int semester = 3; // Fixed semester for all students
    vector<pair<string, int>> subjects;

    for (const auto &subj : subjectsArr) {
      subjects.push_back(
          {subj, rand() % 101}); // Random marks between 0 and 100
    }

    GradeCard card(department, name, roll, semester, subjects);
    gradeCards.push_back(card);
  }

  // Find and display the student with the highest CGPA
  try {
    GradeCard topper = GradeCard::findTopper(gradeCards);
    cout << "Topper's Grade Card:" << endl;
    topper.display();
    cout << "Name: " << topper.getStudentName() << endl;
    cout << "Roll Number: " << topper.getRollNumber() << endl;
  } catch (const exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}
