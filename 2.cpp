#include <iostream>
#include <cstring>

class Exam {
private:
    char* studentName;
    char* examDate;
    int score;

public:
    Exam(const char* name, const char* date, int scoreValue) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = scoreValue;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    void display() const {
        std::cout << "Student Name: " << studentName << std::endl;
        std::cout << "Exam Date: " << examDate << std::endl;
        std::cout << "Score: " << score << std::endl;
    }

    void setStudentName(const char* name) {
        delete[] studentName;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
    }

    void setExamDate(const char* date) {
        delete[] examDate;
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
    }

    void setScore(int scoreValue) {
        score = scoreValue;
    }
};

int main() {
    Exam exam1("John Doe", "2024-12-08", 85);
    exam1.display();

    Exam exam2 = exam1;

    std::cout << "After shallow copy:" << std::endl;
    exam2.setStudentName("Jane Smith");
    exam2.setScore(90);
    
    exam1.display();
    exam2.display();

    return 0;
}