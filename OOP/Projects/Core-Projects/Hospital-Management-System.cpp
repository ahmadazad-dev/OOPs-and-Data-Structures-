#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <ctime>

using namespace std;

class Person {
protected:
    string personId;
    string name;
    int age;
    string gender;
    string contactNumber;

public:
    Person(string id, string n, int a, string g, string contact)
        : personId(id), name(n), age(a), gender(g), contactNumber(contact) {}

    virtual ~Person() {}

    virtual void displayDetails() const = 0;
    virtual string getType() const = 0;
    virtual string serialize() const = 0;

    string getId() const { return personId; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getContactNumber() const { return contactNumber; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setContactNumber(string contact) { contactNumber = contact; }
};

class MedicalRecord {
private:
    string recordId;
    string patientId;
    string diagnosis;
    string prescription;
    string recordDate;
    string doctorId;

public:
    MedicalRecord(string rid, string pid, string diag, string presc, string date, string did)
        : recordId(rid), patientId(pid), diagnosis(diag), prescription(presc), recordDate(date), doctorId(did) {}

    string getRecordId() const { return recordId; }
    string getPatientId() const { return patientId; }
    string getDiagnosis() const { return diagnosis; }
    string getPrescription() const { return prescription; }
    string getRecordDate() const { return recordDate; }
    string getDoctorId() const { return doctorId; }

    void displayRecord() const {
        cout << "  Record ID: " << recordId << endl;
        cout << "  Date: " << recordDate << endl;
        cout << "  Diagnosis: " << diagnosis << endl;
        cout << "  Prescription: " << prescription << endl;
        cout << "  Doctor ID: " << doctorId << endl;
    }

    string serialize() const {
        return recordId + "," + patientId + "," + diagnosis + "," + prescription + "," + recordDate + "," + doctorId;
    }
};

class Doctor : public Person {
private:
    string specialization;
    vector<string> availableSlots;
    double consultationFee;

public:
    Doctor(string id, string n, int a, string g, string contact, string spec, double fee)
        : Person(id, n, a, g, contact), specialization(spec), consultationFee(fee) {
        initializeSlots();
    }

    void initializeSlots() {
        availableSlots = {"09:00", "10:00", "11:00", "14:00", "15:00", "16:00"};
    }

    void displayDetails() const override {
        cout << "  ID: " << personId << " | Name: " << name << " | Age: " << age
             << " | Gender: " << gender << endl;
        cout << "  Specialization: " << specialization << " | Fee: $" << consultationFee
             << " | Contact: " << contactNumber << endl;
    }

    string getType() const override { return "DOCTOR"; }

    string serialize() const override {
        return personId + "," + name + "," + to_string(age) + "," + gender + "," +
               contactNumber + "," + specialization + "," + to_string(consultationFee);
    }

    string getSpecialization() const { return specialization; }
    double getConsultationFee() const { return consultationFee; }
    vector<string> getAvailableSlots() const { return availableSlots; }

    void setSpecialization(string spec) { specialization = spec; }
    void setConsultationFee(double fee) { consultationFee = fee; }
};

class Patient : public Person {
private:
    string bloodGroup;
    vector<MedicalRecord*> medicalHistory;
    string assignedDoctorId;

public:
    Patient(string id, string n, int a, string g, string contact, string blood)
        : Person(id, n, a, g, contact), bloodGroup(blood), assignedDoctorId("") {}

    ~Patient() {
        for (auto record : medicalHistory) {
            delete record;
        }
    }

    void displayDetails() const override {
        cout << "  ID: " << personId << " | Name: " << name << " | Age: " << age
             << " | Gender: " << gender << endl;
        cout << "  Blood Group: " << bloodGroup << " | Contact: " << contactNumber;
        if (!assignedDoctorId.empty()) {
            cout << " | Assigned Doctor: " << assignedDoctorId;
        }
        cout << endl;
    }

    string getType() const override { return "PATIENT"; }

    string serialize() const override {
        return personId + "," + name + "," + to_string(age) + "," + gender + "," +
               contactNumber + "," + bloodGroup + "," + assignedDoctorId;
    }

    string getBloodGroup() const { return bloodGroup; }
    string getAssignedDoctorId() const { return assignedDoctorId; }
    vector<MedicalRecord*> getMedicalHistory() const { return medicalHistory; }

    void setBloodGroup(string blood) { bloodGroup = blood; }
    void assignDoctor(string doctorId) { assignedDoctorId = doctorId; }
    void addMedicalRecord(MedicalRecord* record) { medicalHistory.push_back(record); }
};

class Staff : public Person {
private:
    string role;
    double salary;

public:
    Staff(string id, string n, int a, string g, string contact, string r, double sal)
        : Person(id, n, a, g, contact), role(r), salary(sal) {}

    void displayDetails() const override {
        cout << "  ID: " << personId << " | Name: " << name << " | Age: " << age
             << " | Gender: " << gender << endl;
        cout << "  Role: " << role << " | Salary: $" << salary
             << " | Contact: " << contactNumber << endl;
    }

    string getType() const override { return "STAFF"; }

    string serialize() const override {
        return personId + "," + name + "," + to_string(age) + "," + gender + "," +
               contactNumber + "," + role + "," + to_string(salary);
    }

    string getRole() const { return role; }
    double getSalary() const { return salary; }

    void setRole(string r) { role = r; }
    void setSalary(double sal) { salary = sal; }
};

class Appointment {
private:
    string appointmentId;
    string patientId;
    string doctorId;
    string appointmentDate;
    string timeSlot;
    string status;

public:
    Appointment(string aid, string pid, string did, string date, string time)
        : appointmentId(aid), patientId(pid), doctorId(did),
          appointmentDate(date), timeSlot(time), status("Scheduled") {}

    string getAppointmentId() const { return appointmentId; }
    string getPatientId() const { return patientId; }
    string getDoctorId() const { return doctorId; }
    string getAppointmentDate() const { return appointmentDate; }
    string getTimeSlot() const { return timeSlot; }
    string getStatus() const { return status; }

    void setStatus(string s) { status = s; }

    void displayAppointment() const {
        cout << "  Appointment ID: " << appointmentId << endl;
        cout << "  Patient ID: " << patientId << " | Doctor ID: " << doctorId << endl;
        cout << "  Date: " << appointmentDate << " | Time: " << timeSlot << endl;
        cout << "  Status: " << status << endl;
    }

    string serialize() const {
        return appointmentId + "," + patientId + "," + doctorId + "," +
               appointmentDate + "," + timeSlot + "," + status;
    }
};

class Hospital {
private:
    string hospitalName;
    map<string, Doctor*> doctors;
    map<string, Patient*> patients;
    map<string, Staff*> staffMembers;
    vector<Appointment*> appointments;
    vector<MedicalRecord*> allMedicalRecords;

    int doctorCounter;
    int patientCounter;
    int staffCounter;
    int appointmentCounter;
    int recordCounter;

    bool checkAppointmentClash(string doctorId, string date, string timeSlot) const {
        for (const auto& apt : appointments) {
            if (apt->getDoctorId() == doctorId &&
                apt->getAppointmentDate() == date &&
                apt->getTimeSlot() == timeSlot &&
                apt->getStatus() == "Scheduled") {
                return true;
            }
        }
        return false;
    }

    string generateId(string prefix, int counter) {
        stringstream ss;
        ss << prefix << setfill('0') << setw(4) << counter;
        return ss.str();
    }

    string getCurrentDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        stringstream ss;
        ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
           << setw(2) << (1 + ltm->tm_mon) << "/"
           << (1900 + ltm->tm_year);
        return ss.str();
    }

public:
    Hospital(string name)
        : hospitalName(name), doctorCounter(1), patientCounter(1),
          staffCounter(1), appointmentCounter(1), recordCounter(1) {}

    ~Hospital() {
        for (auto& pair : doctors) delete pair.second;
        for (auto& pair : patients) delete pair.second;
        for (auto& pair : staffMembers) delete pair.second;
        for (auto apt : appointments) delete apt;
        for (auto rec : allMedicalRecords) delete rec;
    }

    void registerDoctor(string name, int age, string gender, string contact,
                       string specialization, double fee) {
        string id = generateId("DOC", doctorCounter++);
        Doctor* doc = new Doctor(id, name, age, gender, contact, specialization, fee);
        doctors[id] = doc;
        cout << "\n  Doctor registered successfully! ID: " << id << endl;
    }

    void registerPatient(string name, int age, string gender, string contact, string bloodGroup) {
        string id = generateId("PAT", patientCounter++);
        Patient* pat = new Patient(id, name, age, gender, contact, bloodGroup);
        patients[id] = pat;
        cout << "\n  Patient registered successfully! ID: " << id << endl;
    }

    void registerStaff(string name, int age, string gender, string contact,
                      string role, double salary) {
        string id = generateId("STF", staffCounter++);
        Staff* stf = new Staff(id, name, age, gender, contact, role, salary);
        staffMembers[id] = stf;
        cout << "\n  Staff registered successfully! ID: " << id << endl;
    }

    void scheduleAppointment(string patientId, string doctorId, string date, string timeSlot) {
        if (patients.find(patientId) == patients.end()) {
            cout << "\n  Error: Patient not found!" << endl;
            return;
        }
        if (doctors.find(doctorId) == doctors.end()) {
            cout << "\n  Error: Doctor not found!" << endl;
            return;
        }

        if (checkAppointmentClash(doctorId, date, timeSlot)) {
            cout << "\n  Error: Appointment slot already booked!" << endl;
            return;
        }

        string id = generateId("APT", appointmentCounter++);
        Appointment* apt = new Appointment(id, patientId, doctorId, date, timeSlot);
        appointments.push_back(apt);
        cout << "\n  Appointment scheduled successfully! ID: " << id << endl;
    }

    void cancelAppointment(string appointmentId) {
        for (auto apt : appointments) {
            if (apt->getAppointmentId() == appointmentId) {
                if (apt->getStatus() == "Scheduled") {
                    apt->setStatus("Cancelled");
                    cout << "\n  Appointment cancelled successfully!" << endl;
                } else {
                    cout << "\n  Appointment already " << apt->getStatus() << "!" << endl;
                }
                return;
            }
        }
        cout << "\n  Error: Appointment not found!" << endl;
    }

    void assignDoctorToPatient(string patientId, string doctorId) {
        if (patients.find(patientId) == patients.end()) {
            cout << "\n  Error: Patient not found!" << endl;
            return;
        }
        if (doctors.find(doctorId) == doctors.end()) {
            cout << "\n  Error: Doctor not found!" << endl;
            return;
        }

        patients[patientId]->assignDoctor(doctorId);
        cout << "\n  Doctor assigned successfully!" << endl;
    }

    void addMedicalRecord(string patientId, string diagnosis, string prescription, string doctorId) {
        if (patients.find(patientId) == patients.end()) {
            cout << "\n  Error: Patient not found!" << endl;
            return;
        }

        string id = generateId("REC", recordCounter++);
        string date = getCurrentDate();
        MedicalRecord* record = new MedicalRecord(id, patientId, diagnosis, prescription, date, doctorId);

        patients[patientId]->addMedicalRecord(record);
        allMedicalRecords.push_back(record);
        cout << "\n  Medical record added successfully! ID: " << id << endl;
    }

    void displayAllDoctors() const {
        cout << "\n========== ALL DOCTORS ==========" << endl;
        if (doctors.empty()) {
            cout << "  No doctors registered." << endl;
            return;
        }
        for (const auto& pair : doctors) {
            pair.second->displayDetails();
            cout << "  ---------------------------------" << endl;
        }
    }

    void displayAllPatients() const {
        cout << "\n========== ALL PATIENTS ==========" << endl;
        if (patients.empty()) {
            cout << "  No patients registered." << endl;
            return;
        }
        for (const auto& pair : patients) {
            pair.second->displayDetails();
            cout << "  ---------------------------------" << endl;
        }
    }

    void displayAllStaff() const {
        cout << "\n========== ALL STAFF ==========" << endl;
        if (staffMembers.empty()) {
            cout << "  No staff members registered." << endl;
            return;
        }
        for (const auto& pair : staffMembers) {
            pair.second->displayDetails();
            cout << "  ---------------------------------" << endl;
        }
    }

    void displayAllAppointments() const {
        cout << "\n========== ALL APPOINTMENTS ==========" << endl;
        if (appointments.empty()) {
            cout << "  No appointments scheduled." << endl;
            return;
        }
        for (const auto& apt : appointments) {
            apt->displayAppointment();
            cout << "  ---------------------------------" << endl;
        }
    }

    void displayPatientMedicalHistory(string patientId) const {
        if (patients.find(patientId) == patients.end()) {
            cout << "\n  Error: Patient not found!" << endl;
            return;
        }

        cout << "\n========== MEDICAL HISTORY FOR PATIENT " << patientId << " ==========" << endl;
        vector<MedicalRecord*> history = patients.at(patientId)->getMedicalHistory();

        if (history.empty()) {
            cout << "  No medical records found." << endl;
            return;
        }

        for (const auto& record : history) {
            record->displayRecord();
            cout << "  ---------------------------------" << endl;
        }
    }

    void updateDoctor(string doctorId, string name, string contact, string specialization, double fee) {
        if (doctors.find(doctorId) == doctors.end()) {
            cout << "\n  Error: Doctor not found!" << endl;
            return;
        }

        Doctor* doc = doctors[doctorId];
        if (!name.empty()) doc->setName(name);
        if (!contact.empty()) doc->setContactNumber(contact);
        if (!specialization.empty()) doc->setSpecialization(specialization);
        if (fee > 0) doc->setConsultationFee(fee);

        cout << "\n  Doctor information updated successfully!" << endl;
    }

    void removeDoctor(string doctorId) {
        if (doctors.find(doctorId) == doctors.end()) {
            cout << "\n  Error: Doctor not found!" << endl;
            return;
        }

        delete doctors[doctorId];
        doctors.erase(doctorId);
        cout << "\n  Doctor removed successfully!" << endl;
    }

    void removePatient(string patientId) {
        if (patients.find(patientId) == patients.end()) {
            cout << "\n  Error: Patient not found!" << endl;
            return;
        }

        delete patients[patientId];
        patients.erase(patientId);
        cout << "\n  Patient removed successfully!" << endl;
    }

    void saveToFiles() {
        ofstream doctorFile("doctors.txt");
        for (const auto& pair : doctors) {
            doctorFile << pair.second->serialize() << endl;
        }
        doctorFile.close();

        ofstream patientFile("patients.txt");
        for (const auto& pair : patients) {
            patientFile << pair.second->serialize() << endl;
        }
        patientFile.close();

        ofstream staffFile("staff.txt");
        for (const auto& pair : staffMembers) {
            staffFile << pair.second->serialize() << endl;
        }
        staffFile.close();

        ofstream appointmentFile("appointments.txt");
        for (const auto& apt : appointments) {
            appointmentFile << apt->serialize() << endl;
        }
        appointmentFile.close();

        ofstream recordFile("records.txt");
        for (const auto& rec : allMedicalRecords) {
            recordFile << rec->serialize() << endl;
        }
        recordFile.close();

        cout << "\n  All data saved successfully!" << endl;
    }

    void loadFromFiles() {
        ifstream doctorFile("doctors.txt");
        string line;
        while (getline(doctorFile, line)) {
            stringstream ss(line);
            string id, name, ageStr, gender, contact, spec, feeStr;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, gender, ',');
            getline(ss, contact, ',');
            getline(ss, spec, ',');
            getline(ss, feeStr, ',');

            Doctor* doc = new Doctor(id, name, stoi(ageStr), gender, contact, spec, stod(feeStr));
            doctors[id] = doc;
        }
        doctorFile.close();

        ifstream patientFile("patients.txt");
        while (getline(patientFile, line)) {
            stringstream ss(line);
            string id, name, ageStr, gender, contact, blood, assignedDoc;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, gender, ',');
            getline(ss, contact, ',');
            getline(ss, blood, ',');
            getline(ss, assignedDoc, ',');

            Patient* pat = new Patient(id, name, stoi(ageStr), gender, contact, blood);
            if (!assignedDoc.empty()) pat->assignDoctor(assignedDoc);
            patients[id] = pat;
        }
        patientFile.close();

        ifstream staffFile("staff.txt");
        while (getline(staffFile, line)) {
            stringstream ss(line);
            string id, name, ageStr, gender, contact, role, salStr;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, gender, ',');
            getline(ss, contact, ',');
            getline(ss, role, ',');
            getline(ss, salStr, ',');

            Staff* stf = new Staff(id, name, stoi(ageStr), gender, contact, role, stod(salStr));
            staffMembers[id] = stf;
        }
        staffFile.close();

        ifstream appointmentFile("appointments.txt");
        while (getline(appointmentFile, line)) {
            stringstream ss(line);
            string id, patId, docId, date, time, status;
            getline(ss, id, ',');
            getline(ss, patId, ',');
            getline(ss, docId, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, status, ',');

            Appointment* apt = new Appointment(id, patId, docId, date, time);
            apt->setStatus(status);
            appointments.push_back(apt);
        }
        appointmentFile.close();

        ifstream recordFile("records.txt");
        while (getline(recordFile, line)) {
            stringstream ss(line);
            string id, patId, diag, presc, date, docId;
            getline(ss, id, ',');
            getline(ss, patId, ',');
            getline(ss, diag, ',');
            getline(ss, presc, ',');
            getline(ss, date, ',');
            getline(ss, docId, ',');

            MedicalRecord* rec = new MedicalRecord(id, patId, diag, presc, date, docId);
            allMedicalRecords.push_back(rec);

            if (patients.find(patId) != patients.end()) {
                patients[patId]->addMedicalRecord(rec);
            }
        }
        recordFile.close();

        cout << "\n  Data loaded successfully!" << endl;
    }

    void displayHospitalSummary() const {
        cout << "\n========================================" << endl;
        cout << "    " << hospitalName << " - SUMMARY" << endl;
        cout << "========================================" << endl;
        cout << "  Total Doctors: " << doctors.size() << endl;
        cout << "  Total Patients: " << patients.size() << endl;
        cout << "  Total Staff: " << staffMembers.size() << endl;
        cout << "  Total Appointments: " << appointments.size() << endl;
        cout << "  Total Medical Records: " << allMedicalRecords.size() << endl;
        cout << "========================================" << endl;
    }
};

void displayMainMenu() {
    cout << "\n========================================" << endl;
    cout << "  SMART HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "  1.  Register Doctor" << endl;
    cout << "  2.  Register Patient" << endl;
    cout << "  3.  Register Staff" << endl;
    cout << "  4.  Schedule Appointment" << endl;
    cout << "  5.  Cancel Appointment" << endl;
    cout << "  6.  Assign Doctor to Patient" << endl;
    cout << "  7.  Add Medical Record" << endl;
    cout << "  8.  Display All Doctors" << endl;
    cout << "  9.  Display All Patients" << endl;
    cout << "  10. Display All Staff" << endl;
    cout << "  11. Display All Appointments" << endl;
    cout << "  12. Display Patient Medical History" << endl;
    cout << "  13. Update Doctor Information" << endl;
    cout << "  14. Remove Doctor" << endl;
    cout << "  15. Remove Patient" << endl;
    cout << "  16. Display Hospital Summary" << endl;
    cout << "  17. Save Data to Files" << endl;
    cout << "  18. Load Data from Files" << endl;
    cout << "  0.  Exit" << endl;
    cout << "========================================" << endl;
    cout << "  Enter your choice: ";
}

int main() {
    Hospital hospital("City General Hospital");
    int choice;
    string name, gender, contact, specialization, role, bloodGroup;
    string patientId, doctorId, appointmentId, date, timeSlot;
    string diagnosis, prescription;
    int age;
    double fee, salary;

    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n--- Register Doctor ---" << endl;
            cout << "  Name: "; getline(cin, name);
            cout << "  Age: "; cin >> age;
            cin.ignore();
            cout << "  Gender: "; getline(cin, gender);
            cout << "  Contact: "; getline(cin, contact);
            cout << "  Specialization: "; getline(cin, specialization);
            cout << "  Consultation Fee: "; cin >> fee;
            hospital.registerDoctor(name, age, gender, contact, specialization, fee);
            break;

        case 2:
            cout << "\n--- Register Patient ---" << endl;
            cout << "  Name: "; getline(cin, name);
            cout << "  Age: "; cin >> age;
            cin.ignore();
            cout << "  Gender: "; getline(cin, gender);
            cout << "  Contact: "; getline(cin, contact);
            cout << "  Blood Group: "; getline(cin, bloodGroup);
            hospital.registerPatient(name, age, gender, contact, bloodGroup);
            break;

        case 3:
            cout << "\n--- Register Staff ---" << endl;
            cout << "  Name: "; getline(cin, name);
            cout << "  Age: "; cin >> age;
            cin.ignore();
            cout << "  Gender: "; getline(cin, gender);
            cout << "  Contact: "; getline(cin, contact);
            cout << "  Role: "; getline(cin, role);
            cout << "  Salary: "; cin >> salary;
            hospital.registerStaff(name, age, gender, contact, role, salary);
            break;

        case 4:
            cout << "\n--- Schedule Appointment ---" << endl;
            cout << "  Patient ID: "; getline(cin, patientId);
            cout << "  Doctor ID: "; getline(cin, doctorId);
            cout << "  Date (DD/MM/YYYY): "; getline(cin, date);
            cout << "  Time Slot (HH:MM): "; getline(cin, timeSlot);
            hospital.scheduleAppointment(patientId, doctorId, date, timeSlot);
            break;

        case 5:
            cout << "\n--- Cancel Appointment ---" << endl;
            cout << "  Appointment ID: "; getline(cin, appointmentId);
            hospital.cancelAppointment(appointmentId);
            break;

        case 6:
            cout << "\n--- Assign Doctor to Patient ---" << endl;
            cout << "  Patient ID: "; getline(cin, patientId);
            cout << "  Doctor ID: "; getline(cin, doctorId);
            hospital.assignDoctorToPatient(patientId, doctorId);
            break;

        case 7:
            cout << "\n--- Add Medical Record ---" << endl;
            cout << "  Patient ID: "; getline(cin, patientId);
            cout << "  Diagnosis: "; getline(cin, diagnosis);
            cout << "  Prescription: "; getline(cin, prescription);
            cout << "  Doctor ID: "; getline(cin, doctorId);
            hospital.addMedicalRecord(patientId, diagnosis, prescription, doctorId);
            break;

        case 8:
            hospital.displayAllDoctors();
            break;

        case 9:
            hospital.displayAllPatients();
            break;

        case 10:
            hospital.displayAllStaff();
            break;

        case 11:
            hospital.displayAllAppointments();
            break;

        case 12:
            cout << "\n--- Display Patient Medical History ---" << endl;
            cout << "  Patient ID: "; getline(cin, patientId);
            hospital.displayPatientMedicalHistory(patientId);
            break;

        case 13:
            cout << "\n--- Update Doctor Information ---" << endl;
            cout << "  Doctor ID: "; getline(cin, doctorId);
            cout << "  New Name (or press Enter to skip): "; getline(cin, name);
            cout << "  New Contact (or press Enter to skip): "; getline(cin, contact);
            cout << "  New Specialization (or press Enter to skip): "; getline(cin, specialization);
            cout << "  New Fee (or 0 to skip): "; cin >> fee;
            hospital.updateDoctor(doctorId, name, contact, specialization, fee);
            break;

        case 14:
            cout << "\n--- Remove Doctor ---" << endl;
            cout << "  Doctor ID: "; getline(cin, doctorId);
            hospital.removeDoctor(doctorId);
            break;

        case 15:
            cout << "\n--- Remove Patient ---" << endl;
            cout << "  Patient ID: "; getline(cin, patientId);
            hospital.removePatient(patientId);
            break;

        case 16:
            hospital.displayHospitalSummary();
            break;

        case 17:
            hospital.saveToFiles();
            break;

        case 18:
            hospital.loadFromFiles();
            break;

        case 0:
            cout << "\n  Thank you for using Smart Hospital Management System!" << endl;
            break;

        default:
            cout << "\n  Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
