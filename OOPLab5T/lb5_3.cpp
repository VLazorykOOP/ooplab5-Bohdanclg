/*Задача 3.8. Створити ієрархію класів студент і студент дипломник. Перевизначити
вивід у потік і введення з потоку, конструктор копіювання, оператор присвоювання
через відповідні функції базового класу.*/


#include <iostream>
#include <string>


class Student{
    protected:

    std::string name;
    int age;
    int yearofstudy;

    public:


    Student(){
        name = "-";
        age = 0;
        yearofstudy = 0;
    }

    Student(std::string n, int a, int year){
        name = n;
        age = a;
        yearofstudy = year;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student){
        os << "Name: " << student.name << ", Age: " << student.age << ", Year of study: " << student.yearofstudy;
    return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& student){
        std::cout << "Enter name: ";
        is >> student.name;
        std::cout << "Enter age: ";
        is >> student.age;
        std::cout << "Enter year of study: ";
        is >> student.yearofstudy;
        return is;
    }

    Student(const Student& other){
        name = other.name;
        age = other.age;
        yearofstudy = other.yearofstudy;
    }

    Student& operator=(const Student& other){
        if (this != &other) {
            name = other.name;
            age = other.age;
            yearofstudy = other.yearofstudy;
        }
        return *this;
    }

};

class GradStudent : public Student{
    private:
    std::string researchTopic;

    public:

    GradStudent(){
        Student();
        researchTopic = "-"; 
    }

    GradStudent(std::string n, int a, int year, std::string topic) : Student(n, a, year), researchTopic(topic) {}
    
    friend std::ostream& operator<<(std::ostream& os, const GradStudent& gradStudent) {
        os << static_cast<const Student&>(gradStudent) << ", Research Topic: " << gradStudent.researchTopic;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, GradStudent& gradStudent) {
        is >> static_cast<Student&>(gradStudent);
        std::cout << "Enter research topic: ";
        is >> gradStudent.researchTopic;
        return is;
    }

    GradStudent(const GradStudent& other) : Student(other), researchTopic(other.researchTopic) {}

    GradStudent& operator=(const GradStudent& other) {
        if (this != &other) {
            static_cast<Student&>(*this) = other;
            researchTopic = other.researchTopic;
        }
        return *this;
    }


};

int main() {
    Student student1("John Doe", 20, 2);

    std::cout << "Student 1: " << student1 << std::endl;

    GradStudent gradStudent1;

    std::cin >> gradStudent1;

    std::cout << "Grad Student 1: " << gradStudent1 << std::endl;

    GradStudent gradStudent2("Alice Smith", 25, 1, "Machine Learning");

    std::cout << "Grad Student 2: " << gradStudent2 << std::endl;

    gradStudent1 = gradStudent2;

    std::cout << "Grad Student 1 (after assignment): " << gradStudent1 << std::endl;

    return 0;

}