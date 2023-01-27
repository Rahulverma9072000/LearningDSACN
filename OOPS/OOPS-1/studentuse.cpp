#include<iostream>
#include"student.h"
using namespace std;
int main()
{
    //Creates object Statically 
    Student s1;
    Student s2 ;
    Student s3,s4,s5;
    //Putting the values 
    s1.age = 12;
    s1.rollNumber = 1;
    //Printing the values of s1
    cout<<s1.age<<" "<<s1.rollNumber<<endl;
    //Creates object dynamically
    Student* s6 = new Student;
    //Putting the values in dynamic object 
    //(*s6).age = 24;
    s6->age = 24;
    s6->rollNumber = 6;
    //Accesing the properties of dynamically created object 
    cout<<s6->age<<" "<<s6->rollNumber<<endl;
    return 0;
}