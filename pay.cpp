#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "person.h"
#include "person.cpp"

using namespace std;

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
    for (int i = 0; i < employees.size(); i++){
        //cout << "test" << endl;
        //cout << employees.at(i).getCompanyName() << endl;

        companyNames.push_back(employees.at(i).getCompanyName());

        //cout << companyNames.at(i) << endl;
    }
}

void readData (vector<Person> &employees)
{
    string fname;
    string lname;
    int id;
    string cname;
    float hours;
    float rate;

    ifstream input("input.txt");


    if (input.is_open())
    {

        while (!input.eof()){
            Person temp;

            input >> fname >> lname >> id >> cname >> hours >> rate;

            temp.setFirstName(fname);
            temp.setLastName(lname);
            temp.setEmployeeId(id);
            temp.setCompanyName(cname);
            temp.setHoursWorked(hours);
            temp.setPayRate(rate);

            employees.push_back(temp);
        }
    }
    input.close();
    employees.pop_back();
}

void printHighestPaid(vector<Person> &employees)
{
    int N;
    for (int i = 0; i < employees.size(); i++){
        //cout << "test" << endl;
        float temp = 0;

        if (employees[i].totalPay() > employees[i+1].totalPay())
        {
            N=i;
            //cout << N << endl;
        }


/*
        if (temp < employees.at(i).totalPay())
        {
            temp = employees.at(i).totalPay();
        }
        */
        //cout << temp << endl;

    }

    cout << "Highest Paid: " << employees.at(N).fullName() << endl;
    cout << "Employee ID: " << employees.at(N).getEmployeeId() << endl;
    cout << "Employer: " << employees.at(N).getCompanyName() << endl;
    cout << "Total Pay: " << employees.at(N).totalPay() << endl;


}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
    string s;
    float total;
    for (int i = 0; i < companyNames.size(); i++)
    {
        string s = companyNames.at(i);
        ofstream output(s + ".txt");
        if (output.is_open())
        {
            for (int j = 0; j < employees.size(); j++)
            {
                if (employees.at(j).getCompanyName() == companyNames.at(i))
                {

                    output << employees.at(j).getFirstName() << " ";
                    output << employees.at(j).getLastName() << "    ";
                    output << employees.at(j).getEmployeeId() << "    ";
                    output << employees.at(j).getCompanyName() << "    ";
                    output <<  "$" << employees.at(j).totalPay() << endl;

                    total += employees.at(j).totalPay();


                }


            }
            output << "Total $" << total << endl;
            total = 0;

        }
        else
            cout << "oops";

    }




}




int main() {
    vector<Person> employees;
    vector<string> companyNames;


    readData(employees);
    getCompanies(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
}
