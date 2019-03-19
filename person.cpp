#include "person.h"

Person::Person()
{
    lastName = "";
    firstName = "";
    payRate = 0;
    hoursWorked = 0;
    employeeID = 0;
    companyName = "";
}


string Person::getFirstName() {
    return firstName;
}


string Person::getLastName()
{
    return lastName;
}
float Person::getPayRate()
{
    return payRate;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
void Person::setFirstName(string fName)
{
    firstName = fName;

}
void Person::setLastName(string lName)
{
    lastName = lName;

}
void Person::setPayRate(float rate)
{
    payRate = rate;

}
void Person::setHoursWorked(float hours)
{
    hoursWorked = hours;

}
float Person::totalPay()
{
    return payRate * hoursWorked;

}
string Person::fullName()
{
    return firstName + " " + lastName;

}
void Person::setEmployeeId(int id)
{
    employeeID = id;
}
int Person::getEmployeeId()
{
    return employeeID;

}
void Person::setCompanyName(string coName)
{
    companyName = coName;

}
string Person::getCompanyName()
{
    return companyName;

}
