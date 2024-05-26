#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <cctype>
using namespace std;
class Patient
{
private:
    static int num;
    int PatientID;
    string PatientName;
    string PatientCNIC;
    string PhoneNo;
    string Disease;
    bool isAdmitted;

public:
    Patient();
    Patient(string name, string cnic, string phone, string bimari, char ch);
    void setName(string name);
    void setCNIC(string cnic);
    void setPhone(string phone);
    void setDisease(string bimari);
    void setAdmitStatus(char ch);
    string getName() const;
    string getCnic() const;
    string getPhone() const;
    int getId() const;
    bool getAdmitStatus() const;
    string getDisease() const;
    void displayPatient();
};
#endif