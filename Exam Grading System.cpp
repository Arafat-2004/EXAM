#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int score;

    // Constructor to initialize Student
    Student(std::string n, int s) : name(n), score(s) {}
};

class Exam {
private:
    std::vector<Student> students;

public:
    // Add a student to the exam list
    void addStudent(const std::string& name, int score) {
        if (score < 0 || score > 100) {
            std::cout << "Invalid score for " << name << ". Score must be between 0 and 100.\n";
            return;
        }
        students.emplace_back(name, score); // Optimized using emplace_back
    }

    // Generate a list of results
    void generateResults() {
        std::cout << "Exam Results:\n";
        std::cout << "---------------------------\n";
        std::cout << "Student Name    | Score\n";
        std::cout << "---------------------------\n";
        for (const auto& student : students) {
            std::cout << student.name << "       | " << student.score << "\n";
        }
        std::cout << "---------------------------\n";
    }

 
    void calculateGrades() {
        std::cout << "Grades:\n";
        for (const auto& student : students) {
            char grade;
            if (student.score >= 90) grade = 'A';
            else if (student.score >= 80) grade = 'B';
            else if (student.score >= 70) grade = 'C';
            else if (student.score >= 60) grade = 'D';
            else grade = 'F';

            std::cout << "Student: " << student.name << ", Grade: " << grade << "\n";
        }
    }
};

int main() {
    Exam exam;
    exam.addStudent("Lazaro", 85);
    exam.addStudent("Carlos", 92);
    exam.addStudent("Furuwash", 78);
    exam.addStudent("Cannibal", 65);
    exam.addStudent("Malone", 55);

    exam.generateResults();
    exam.calculateGrades();

    return 0;
}
