#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    Person(int id, string name) : id(id), name(name) {}
    virtual string getRole() const = 0;
    virtual int getId() const { return id; }
    virtual string getName() const { return name; }
    virtual ~Person() {}
};

class Doctor : public Person
{
    string specialization;

public:
    Doctor(int id, string name, string specialization)
        : Person(id, name), specialization(specialization) {}

    string getSpecialization() const { return specialization; }
    string getRole() const override { return "Doctor"; }
};

class Patient : public Person
{
    int assignedDoctorId;

public:
    Patient(int id, string name)
        : Person(id, name), assignedDoctorId(-1) {}

    void assignDoctor(int doctorId) { assignedDoctorId = doctorId; }
    int getAssignedDoctor() const { return assignedDoctorId; }
    string getRole() const override { return "Patient"; }
};

class Staff : public Person
{
    string department;

public:
    Staff(int id, string name, string department)
        : Person(id, name), department(department) {}

    string getRole() const override { return "Staff"; }
};

class MedicalRecord
{
    int patientId;
    string diagnosis;
    string treatment;

public:
    MedicalRecord(int patientId, string diagnosis, string treatment)
        : patientId(patientId), diagnosis(diagnosis), treatment(treatment) {}

    int getPatientId() const { return patientId; }
    string getSummary() const
    {
        return diagnosis + " | " + treatment;
    }
};

class Appointment
{
    int appointmentId;
    int doctorId;
    int patientId;
    string date;

public:
    Appointment(int appointmentId, int doctorId, int patientId, string date)
        : appointmentId(appointmentId), doctorId(doctorId), patientId(patientId), date(date) {}

    int getDoctorId() const { return doctorId; }
    int getPatientId() const { return patientId; }
    string getDate() const { return date; }
};

class Hospital
{
    map<int, Doctor*> doctors;
    map<int, Patient*> patients;
    vector<Appointment*> appointments;
    vector<MedicalRecord*> medicalRecords;

public:
    ~Hospital()
    {
        for (auto& d : doctors) delete d.second;
        for (auto& p : patients) delete p.second;
        for (auto a : appointments) delete a;
        for (auto r : medicalRecords) delete r;
    }

    void addDoctor(int id, string name, string specialization)
    {
        doctors[id] = new Doctor(id, name, specialization);
    }

    void addPatient(int id, string name)
    {
        patients[id] = new Patient(id, name);
    }

    void assignDoctorToPatient(int doctorId, int patientId)
    {
        if (doctors.count(doctorId) && patients.count(patientId))
            patients[patientId]->assignDoctor(doctorId);
    }

    bool appointmentExists(int doctorId, string date)
    {
        for (auto a : appointments)
            if (a->getDoctorId() == doctorId && a->getDate() == date)
                return true;
        return false;
    }

    void scheduleAppointment(int appointmentId, int doctorId, int patientId, string date)
    {
        if (!appointmentExists(doctorId, date))
            appointments.push_back(new Appointment(appointmentId, doctorId, patientId, date));
    }

    void addMedicalRecord(int patientId, string diagnosis, string treatment)
    {
        medicalRecords.push_back(new MedicalRecord(patientId, diagnosis, treatment));
    }

    void displayDoctors()
    {
        for (auto& d : doctors)
            cout << d.second->getId() << " " << d.second->getName() << " " << d.second->getSpecialization() << "\n";
    }

    void displayPatients()
    {
        for (auto& p : patients)
            cout << p.second->getId() << " " << p.second->getName() << " DoctorID: " << p.second->getAssignedDoctor() << "\n";
    }

    void displayAppointments()
    {
        for (auto a : appointments)
            cout << a->getDoctorId() << " " << a->getPatientId() << " " << a->getDate() << "\n";
    }

    void saveData()
    {
        ofstream file("hospital.txt");
        for (auto& d : doctors)
            file << "D " << d.second->getId() << " " << d.second->getName() << "\n";
        for (auto& p : patients)
            file << "P " << p.second->getId() << " " << p.second->getName() << "\n";
        file.close();
    }
};

int main()
{
    Hospital hospital;
    int choice;

    do
    {
        cout << "\n1 Add Doctor\n2 Add Patient\n3 Assign Doctor\n4 Schedule Appointment\n5 Add Medical Record\n6 Show Doctors\n7 Show Patients\n8 Show Appointments\n9 Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name, spec;
            cin >> id >> name >> spec;
            hospital.addDoctor(id, name, spec);
        }
        else if (choice == 2)
        {
            int id;
            string name;
            cin >> id >> name;
            hospital.addPatient(id, name);
        }
        else if (choice == 3)
        {
            int did, pid;
            cin >> did >> pid;
            hospital.assignDoctorToPatient(did, pid);
        }
        else if (choice == 4)
        {
            int aid, did, pid;
            string date;
            cin >> aid >> did >> pid >> date;
            hospital.scheduleAppointment(aid, did, pid, date);
        }
        else if (choice == 5)
        {
            int pid;
            string diag, treat;
            cin >> pid >> diag >> treat;
            hospital.addMedicalRecord(pid, diag, treat);
        }
        else if (choice == 6)
            hospital.displayDoctors();
        else if (choice == 7)
            hospital.displayPatients();
        else if (choice == 8)
            hospital.displayAppointments();

    } while (choice != 9);

    return 0;
}
