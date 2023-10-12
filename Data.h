#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Section
{
public:
    Section() {}
    Section(string sectionId, char grade, string dropDate, bool isActive)
    {
        this->sectionId = sectionId;
        this->grade = grade;
        this->dropDate = dropDate;
        this->isActive = isActive;
    }

private:
    string sectionId;
    char grade;
    string dropDate;
    bool isActive;
};

class Address
{
public:
    Address(){};
    Address(string street, string city, string state, string zip)
    {
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
    };

    void SetStreet(string street)
    {
        this->street = street;
    }
    void SetCity(string city)
    {
        this->city = city;
    }
    void SetState(string state)
    {
        this->state = state;
    }
    void SetZip(string zip)
    {
        this->zip = zip;
    }
    string GetStreet()
    {
        return street;
    }
    string GetCity()
    {
        return city;
    }
    string GetState()
    {
        return state;
    }
    string GetZip()
    {
        return zip;
    }

private:
    string street;
    string city;
    string state;
    string zip;
};

class Contact
{
public:
    Contact() {}
    Contact(string email, string phone, string street, string city, string state, string zip)
    {
        this->email = email;
        this->phone = phone;
        this->Address.SetStreet(street);
        this->Address.SetCity(city);
        this->Address.SetState(state);
        this->Address.SetZip(zip);
    }
    Address Address;

private:
    string email;
    string phone;
};

class Person
{
public:
    Person() {}
    Person(string name, string id)
    {
        this->name = name;
        this->id = id;
    }
    string GetName()
    {
        return name;
    }
    string GetId()
    {
        return id;
    }

private:
    string name;
    string id;
};

class Student : public Person, public Contact
{
public:
    Student() {}
    Student(string name, string id, string email, string phone,
            string street, string city, string state, string zip) : Person(name, id),
                                                                    Contact(email, phone, street, city, state, zip)
    {
        this->SetStudentEmail(studentEmail);
        this->SetStudentId(studentId);
    }

    string GetStudentEmail()
    {
        return studentEmail;
    }
    string GetStudentId()
    {
        return studentId;
    }
    void SetStudentEmail(string studentEmail)
    {
        this->studentEmail = studentEmail;
    }
    void SetStudentId(string studentId)
    {
        this->studentId = studentId;
    }

    void AddSection(Section section)
    {
        enrollment.push_back(section);
    }
    void AddSection(string sectionId, char grade, string dropDate, bool isActive)
    {
        Section section(sectionId, grade, dropDate, isActive);
        enrollment.push_back(section);
    }

private:
    vector<Section> enrollment;
    string studentId;
    string studentEmail;
};

class StudentMgr
{
public:
    StudentMgr() {}
    StudentMgr(Student student)
    {
        AddStudent(student);
    }
    void AddStudent(Student student)
    {
        students.push_back(&student);
    }

    string PrintStudents()
    {
        string output = "";

        for (Student *student : students)
        {
            output += student->GetStudentId() + " " + student->GetName() + "\n";
        }

        return output;
    }

private:
    vector<Student *> students;
};
