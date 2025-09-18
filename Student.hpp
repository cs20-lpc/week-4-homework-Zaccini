#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "Course.hpp"
#include "LinkedList.hpp"
using namespace std;

class Student{
    private:
        int id;
        string name;
        double gpa;
        LinkedList<Course> course;
    public:
        Student();
        Student(int id, const string& name, double gpa);

        int getId() const;
        const string& getName() const;
        double getGpa() const;

        void addCourse(const Course& c);
};

ostream& operator<<(ostream& os, const Student& s);

#endif