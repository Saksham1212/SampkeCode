#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Company {
public:
    Company(std::string name) : m_name(name) {}

    void addEmployee(T employee) {
        m_employees.push_back(employee);
    }

    void removeEmployee(T employee) {
        auto it = std::find(m_employees.begin(), m_employees.end(), employee);
        if (it != m_employees.end()) {
            m_employees.erase(it);
        }
    }

    void printEmployees() {
        std::cout << "Employees of " << m_name << ":" << std::endl;
        for (auto& employee : m_employees) {
            employee.print();
        }
    }

private:
    std::string m_name;
    std::vector<T> m_employees;
};

class Employee {
public:
    Employee(std::string name, int age) : m_name(name), m_age(age) {}

    virtual void print() {
        std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    }

protected:
    std::string m_name;
    int m_age;
};

class Engineer : public Employee {
public:
    Engineer(std::string name, int age, std::string specialization) :
        Employee(name, age), m_specialization(specialization) {}

    void print() override {
        std::cout << "Name: " << m_name << ", Age: " << m_age << ", Specialization: " << m_specialization << std::endl;
    }

private:
    std::string m_specialization;
};

int main() {
    Company<Engineer> google("Google");

    Engineer john("John", 25, "Software Engineering");
    Engineer alice("Alice", 30, "Machine Learning");

    google.addEmployee(john);
    google.addEmployee(alice);

    google.printEmployees();

    google.removeEmployee(john);

    google.printEmployees();

    return 0;
}
