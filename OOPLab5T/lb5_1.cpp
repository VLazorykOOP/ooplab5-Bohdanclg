/*Створити клас людина, що має поля: ПІБ(прізвище, ім'я, по-батькові), вік,
вага. Визначити конструктори, деструктор і функцію друку. Створити похідний клас -
школяр, що має поле клас (рік навчання). Визначити конструктори за замовчуванням і
з різним числом параметрів, деструктори, функцію друку. Визначити функції перепризначення віку й класу. Написати програму тестування всіх можливостей цього
класу.*/

#include <iostream>
#include <string>

class PIB{
    public:
    std::string sname;
    std::string name;
    std::string fname;


    PIB(){
        sname = "NoSurname";
        name = "NoName";
        fname = "NoFathername";

        std::cout << "Default constructor" << std::endl;
    }

    PIB(std::string n){
        sname = "NoSurname";
        name = n;
        fname = "NoFathername";
        std::cout << "Constructor PIB(string fn)" << std::endl;
    }

    PIB(std::string n[3]){
        sname = n[0];
        name = n[1];
        fname = n[2];

        std::cout << "Constructor PIB(string n[])" << std::endl;
    }

    PIB(const PIB & s){
        sname = s.sname;
        name = s.name;
        fname = s.fname;

        std::cout << "Constructor Copy PIB(const PIB &)" << std::endl;
    }

    PIB(const PIB && s){
        sname = s.sname;
        name = s.name;
        fname = s.fname;

        std::cout << " Constructor Move PIB(PIB &&)" << std::endl;
    }

    PIB(const char* sn, const char * n, const char *fn){
        sname = sn;
        name = n;
        fname = fn;

        std::cout << " Constructor PIB(const char * ... )" << std::endl;
    }

    ~PIB(){
        std::cout << "Destructor ~PIB()" << std::endl;
    }

    PIB& operator=(const PIB &s){
        sname = s.sname;
        name = s.name;
        fname = s.fname;

        std::cout << " PIB operator=(PIB &)" << std::endl;

        return *this;
    }

    std::string toString(){
        std::string ts = "PIB: " + sname + " " + name + " " + fname + " ";
        return ts;
    }

    bool operator==(PIB &b){
        return sname == b.sname && name == b.name && fname == b.fname ? true : false;
    }

    void Input(){
        std::cout << "Input surname: ";
        std::getline(std::cin, sname);

        std::cout << "Input name: ";
        std::getline(std::cin, name);

        std::cout << "Input father name: ";
        std::getline(std::cin, fname);
    }

};


class Person{
    protected:
        
    int age, weight;
    PIB name;

    public:

    Person(){
        age = 0;
        weight = 0;
        std::cout << "Default constructor Person()" << std::endl;
    }

    Person(int a, int w, std::string n){
        age = a;
        weight = w;
        name = n;

        std::cout << "Constructor Person(int a, int w, string n)" << std::endl;
    }

    Person(int a, int w, PIB& n){
        age = a;
        weight = w;
        name = n;

        std::cout << "Constructor Person(int a, int w, PIB& n)" << std::endl; 
    }

    ~Person(){
        std::cout << "Destructor person ";
    }

    void setAge(int a){
        if(a >= 0 || a < 140) age = a;
        else std::cout << "Age " << a << " not allow, age is " << age << std::endl;;
    }

    void setWeight(int w){
        if(w <= 0 || w > 300) weight = w;
        else std::cout << "Weight " << w << " not exist, weight is " << weight << std::endl;
    }

    std::string toString(){
        std::string r, a, w;
        a = std::to_string(age);
        w = std::to_string(weight);
        r = name.toString() + "age: " + a + " weight: " + w;
        return r;

    }

    void Input(){
        name.Input();
        std::cout << "Input age: ";
        for(int i = 0; i < 1;){
            std::cin >> age;
            if(age >= 0 && age < 140) i++;
        }


        std::cout << "Input weight: ";
        for(int i = 0; i < 1;){
            std::cin >> weight;
            if(weight >= 0 && weight < 300) i++;
        }
        
    }

    friend std::ostream& operator<<(std::ostream &os, Person& a);
    friend std::istream& operator>>(std::istream &os, Person& a);

};

class Rik : public Person {
    int yearofstudy;

    public:

    Rik(){
        yearofstudy = 0;
        std::cout << "Default constructor Rik" << std::endl;
    }

    Rik(int a, int w, std::string n, int i) : Person(a, w, n){
        yearofstudy = i;
        std::cout << " Constructor Rik(int a, int w, string n, int i)" << std::endl;
    }

    Rik(int a, int w, PIB & pib, int i) : Person(a, w, pib){
        yearofstudy = i;
        std::cout << " Constructor Adult(int a, int w, PIB& pib,int i)" << std::endl;

    }

    ~Rik(){
        std::cout << "Destructor Rik" << std::endl;
    }

    void setYear(int i){
        if(i > 0 && i < 12) yearofstudy = i;
        else yearofstudy = 0;
    }

    std::string toString(){
        std::string y;
        
        y = std::to_string(yearofstudy);
 
        std::string s = Person::toString() + " Year of study: " + y;
        return s;
    }
    
    void Output(){
        std::cout << toString() << std::endl;
    }

};

int main() {
    PIB pib1;
    std::cout << "PIB1: " << pib1.toString() << std::endl;

    std::string arr[] = {"Smith", "John", "Doe"};
    PIB pib2(arr);
    std::cout << "PIB2: " << pib2.toString() << std::endl;

    PIB pib3("Doe");
    std::cout << "PIB3: " << pib3.toString() << std::endl;

    PIB pib4 = pib1;
    std::cout << "PIB4: " << pib4.toString() << std::endl;

    Person person1;
    person1.Input();
    std::cout << "Person1: " << person1.toString() << std::endl;

    PIB pib5("Doe", "John", "Smith");
    Person person2(25, 70, pib5);
    std::cout << "Person2: " << person2.toString() << std::endl;

    Person person3(30, 80, "Doe");
    std::cout << "Person3: " << person3.toString() << std::endl;

    Rik rik1;
    rik1.Input();
    rik1.setYear(3);
    std::cout << "Rik1: " << rik1.toString() << std::endl;

    PIB pib6("Doe", "John", "Smith");
    Rik rik2(22, 65, pib6, 2);
    std::cout << "Rik2: " << rik2.toString() << std::endl;

    Rik rik3(18, 60, "Doe", 1);
    std::cout << "Rik3: " << rik3.toString() << std::endl;

    return 0;
}