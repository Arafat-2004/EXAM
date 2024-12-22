#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int score;

    Student(std::string n, int s) : name(n), score(s) {}
};

class Exam {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name, int score) {
        students.push_back(Student(name, score));
    }

    void generateResults() {
        std::cout << "Exam Results:\n";
        for (const auto& student : students) {
            std::cout << "Student: " << student.name << ", Score: " << student.score << "\n";
        }
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
