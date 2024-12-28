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

// Calculate grades for each student
    void calculateGrades() {
        std::cout << "Grades:\n";
        std::cout << "---------------------------\n";
        for (const auto& student : students) {
            char grade;
            if (student.score >= 90) grade = 'A';
            else if (student.score >= 80) grade = 'B';
            else if (student.score >= 70) grade = 'C';
            else if (student.score >= 60) grade = 'D';
            else grade = 'F';

            std::cout << "Student: " << student.name << ", Grade: " << grade << "\n";
        }
        std::cout << "---------------------------\n";
    } 
// Calculate the average score
    void calculateStatistics() {
        if (students.empty()) {
            std::cout << "No students available to calculate statistics.\n";
            return;
        }

        int totalScore = 0;
        int maxScore = 0;
        int minScore = 100;
        std::string topStudent, bottomStudent;

        for (const auto& student : students) {
            totalScore += student.score;
            if (student.score > maxScore) {
                maxScore = student.score;
                topStudent = student.name;
            }
            if (student.score < minScore) {
                minScore = student.score;
                bottomStudent = student.name;
            }
        }

        double average = static_cast<double>(totalScore) / students.size();
        std::cout << "Statistics:\n";
        std::cout << "---------------------------\n";
        std::cout << "Average Score: " << average << "\n";
        std::cout << "Top Student: " << topStudent << " with score " << maxScore << "\n";
        std::cout << "Lowest Score: " << bottomStudent << " with score " << minScore << "\n";
        std::cout << "---------------------------\n";
    }
};

int main() {
    Exam exam;

    // Sample data for testing
    exam.addStudent("Lazaro", 85);
    exam.addStudent("Carlos", 92);
    exam.addStudent("Furuwash", 78);
    exam.addStudent("Cannibal", 65);
    exam.addStudent("Malone", 55);

    // Displaying exam results and grades
    exam.generateResults();
    exam.calculateGrades();
    exam.calculateStatistics();

    return 0;
}
