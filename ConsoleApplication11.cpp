#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    StudentMgr mgr;

    for (int i = 0; i < 10; i++)
    {
        Student *s = new Student("Devin", "555-55-5555", "devin@email.com", "209-481-8810",
                                 "4600 Old mystic ct", "Salida", "CA", "95368");
        mgr.AddStudent(*s); // Pass the actual Student object, not a pointer
    }

    cout << mgr.PrintStudents();
}
