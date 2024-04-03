#ifndef STUDENTS_HPP
#define STUDENTS_HPP

/*
Se crea el archivo donde se define la clase student.
*/


class Student {
public:
    double marks;

    Student(double m);

};

void calculateAverage(Student s1, Student s2);

#endif // STUDENTS_HPP
