#include <iostream>
#include <cctype>
using namespace std;
#include "patient.h"
int Patient::num = 1;
Patient::Patient()
{
    PatientID = num++;
    PatientName = "";
    PatientCNIC = "";
    PhoneNo = "";
    Disease = "";
    isAdmitted = 0;
}
Patient::Patient(string name, string cnic, string phone, string bimari, char ch)
{
    try
    {
        if (name == "")
        {
            throw invalid_argument("Patient name cannot be an empty string\n");
        }
        else if (cnic == "")
        {
            throw invalid_argument("Patient CNIC cannot be an empty string\n");
        }
        else if (cnic.length() != 13)
        {
            throw invalid_argument("Patient CNIC must consist 13 digits\n");
        }
        else if (phone.length() != 11)
        {
            throw invalid_argument("Patient Phone number must consist 11 digits\n");
        }
        else if (bimari == "")
        {
            throw invalid_argument("Patient Disease cannot be an empty string\n");
        }
        else if (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')
        {
            throw invalid_argument("choose correct choice weather the patient is admitted or not\n");
        }
        else
        {
            for (int i = 0; i < cnic.length(); i++)
            {
                if (!(isdigit(cnic[i])))
                {
                    throw invalid_argument("Patient CNIC must consist of all numbers\n");
                }
            }
            for (int i = 0; i < phone.length(); i++)
            {
                if (!(isdigit(phone[i])))
                {
                    throw invalid_argument("Patient phone no must consist of all numbers\n");
                }
            }
        }
        PatientID = num++;
        PatientName = name;
        PatientCNIC = cnic;
        PhoneNo = phone;
        Disease = bimari;
        if (ch == 'y' || ch == 'Y')
        {
            isAdmitted = 1;
        }
        else
        {
            isAdmitted = 0;
        }
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
void Patient::setName(string name)
{
    try
    {
        if (name == "")
        {
            throw invalid_argument("Patient name cannot be an empty string\n");
        }

        PatientName = name;
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
void Patient::setCNIC(string cnic)
{
    try
    {
        if (cnic == "")
        {
            throw invalid_argument("Patient CNIC cannot be an empty string\n");
        }
        else if (cnic.length() != 13)
        {
            throw invalid_argument("Patient CNIC must consist 13 digits\n");
        }

        else
        {
            for (int i = 0; i < cnic.length(); i++)
            {
                if (!(isdigit(cnic[i])))
                {
                    throw invalid_argument("Patient CNIC must consist of all numbers\n");
                }
            }
        }

        PatientCNIC = cnic;
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
void Patient::setPhone(string phone)
{
    try
    {
        if (phone.length() != 11)
        {
            throw invalid_argument("Patient Phone number must consist 11 digits\n");
        }
        else
        {

            for (int i = 0; i < phone.length(); i++)
            {
                if (!(isdigit(phone[i])))
                {
                    throw invalid_argument("Patient phone no must consist of all numbers\n");
                }
            }
        }

        PhoneNo = phone;
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
void Patient::setDisease(string bimari)
{
    try
    {
        if (bimari == "")
        {
            throw invalid_argument("Patient Disease cannot be an empty string\n");
        }
        Disease = bimari;
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
void Patient::setAdmitStatus(char ch)
{
    try
    {
        if (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')
        {
            throw invalid_argument("choose correct choice weather the patient is admitted or not\n");
        }

        else if (ch == 'y' || ch == 'Y')
        {
            isAdmitted = 1;
        }
        else
        {
            isAdmitted = 0;
        }
    }
    catch (exception &e)
    {
        cerr << "Error:" << e.what() << endl;
    }
}
string Patient::getName() const
{
    return PatientName;
}
string Patient::getCnic() const
{
    return PatientCNIC;
}
string Patient::getPhone() const
{
    return PhoneNo;
}
int Patient::getId() const
{
    return PatientID;
}
bool Patient::getAdmitStatus() const
{
    return isAdmitted;
}
string Patient::getDisease() const
{
    return Disease;
}
void Patient::displayPatient()
{
    if (PatientName != "" && PatientName != "" && Disease != "" && PatientCNIC != "" && PhoneNo != "")
    {
        cout << "Patient Id:" << PatientID << endl;
        cout << "Patient Name:" << PatientName << endl;
        cout << "Patient Disease:" << Disease << endl;
        cout << "Patient CNIC:" << PatientCNIC << endl;
        cout << "Patient Phone no:" << PhoneNo << endl;
        if (isAdmitted)
        {
            cout << "Patient is admitted\n";
        }
        else
        {
            cout << "Patient is not admitted\n";
        }
    }
    else
    {
        cout << "Patient information is incomplete...Add complete and valid information\n";
    }
}