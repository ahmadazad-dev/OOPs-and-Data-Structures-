//#include<iostream>
//#include<string>
//#include<cctype>
//#include<thread>
//#include<iomanip>
//#include<chrono>
//using namespace std;
//
//class Helper {
//public:
//	static bool isvalid_name(string);
//	static bool isvalid_condition(string);.
// .
// 
//	static int binary_to_decimal(int[], int);
//};
//class Paitient {
//public:
//	//Variables
//	string name;
//	int age;
//	string condition;
//	int priority;
//	int waiting_count;
//	Paitient* next_waiter;
//	//Functions
//	Paitient();
//	Paitient(const Paitient&);
//	void register_paitient();
//	void set_priority_order();
//	void print_paitient();
//};
//class HospitalQueue {
//	Paitient* next_paitient;
//	Paitient* latest_paitient;
//public:
//	int number_of_paitients;
//	HospitalQueue();
//	void dequeue_paitient();
//	void enqueue_paitient(Paitient*);
//	void enqueue(Paitient*);
//	HospitalQueue& operator=(const HospitalQueue&);
//	void increment_waiting_time();
//	void doctor_call();
//	void boost_priority();
//	void print_queue();
//	Paitient* reception();
//	Paitient* front();
//};
//class HospitalStack {
//	Paitient* top_paitient;
//public:
//	HospitalStack();
//	void push(Paitient*);
//	void pop();
//	Paitient* peek();
//	Paitient* peek_with_popping();
//	HospitalStack& operator=(const HospitalStack&);
//	bool isEmpty();
//	void print_stack();
//	void reverse_stack();
//};
//
//
////<-----------------------------------------HOSPITAL QUEUE-------------------------------------------------->
//HospitalQueue::HospitalQueue() {
//	next_paitient = nullptr;
//	latest_paitient = nullptr;
//	number_of_paitients = 1;
//}
//void HospitalQueue::enqueue(Paitient* new_paitient) {//It adds the paitient without any priority label
//	if (!latest_paitient) {
//		next_paitient = latest_paitient = new_paitient; return;
//	}
//	latest_paitient->next_waiter = new_paitient;
//	latest_paitient = new_paitient;
//	number_of_paitients++;
//}
//void HospitalQueue::enqueue_paitient(Paitient* new_paitient) {
//	new_paitient->next_waiter = nullptr;
//	if(!latest_paitient) {next_paitient = latest_paitient = new_paitient; return;}
//	HospitalQueue tempQueue;
//	Paitient* current = next_paitient;
//	bool inserted = false;
//	while (current || !inserted) {
//		if (current) {
//			if (current->priority < new_paitient->priority && !inserted) {
//				tempQueue.enqueue(new_paitient);
//				inserted = !inserted;
//			}
//			else {
//				Paitient* temp = new Paitient(*current);
//				tempQueue.enqueue(temp);
//				current = current->next_waiter;
//				this->dequeue_paitient();
//			}
//		}
//		else{
//			tempQueue.enqueue(new_paitient);
//			inserted = !inserted;
//		}
//	}
//	*this = tempQueue;
//	number_of_paitients++;
//}
//void HospitalQueue::dequeue_paitient() {
//	if(!next_paitient) return;
//	Paitient* temp = next_paitient;
//	next_paitient = next_paitient->next_waiter;
//	if(!next_paitient) latest_paitient = nullptr;
//	delete temp;
//	number_of_paitients--;
//}
//HospitalQueue& HospitalQueue::operator=(const HospitalQueue& rhs) {
//	if (this == &rhs) return *this;
//	while (next_paitient) dequeue_paitient();
//	Paitient* current = rhs.next_paitient;
//	while (current) {
//		Paitient* temp = new Paitient(*current);
//		this->enqueue(temp);
//		current = current->next_waiter;
//	}
//	return *this;
//}
//void HospitalQueue::print_queue() {
//	if (!latest_paitient) return;
//	Paitient* current = next_paitient;
//	cout << "+-----------------+-------+--------------------------+------------+\n";
//	cout << "| Name            | Age   | Condition                | Reference  |\n";
//	cout << "+-----------------+-------+--------------------------+------------+\n";
//
//	while (current) {
//		cout << "| " << left << setw(15) << current->name
//			<< " | " << setw(5) << current->age
//			<< " | " << setw(24) << current->condition
//			<< " | " << setw(10) << current->priority << " |\n";
//		current = current->next_waiter;
//	}
//
//	cout << "+-----------------+-------+--------------------------+------------+\n";
//}
//Paitient* HospitalQueue::front() {
//	return next_paitient;
//}
//void HospitalQueue::increment_waiting_time() {
//	if(!next_paitient) return;
//	HospitalQueue tempQueue;
//	HospitalStack tempStack;
//	Paitient* current = next_paitient;
//	while (current) {
//		Paitient* temp = new Paitient(*current);
//		temp->waiting_count++;
//		if(temp->age>=60 && temp->waiting_count >= 3) {
//			temp->priority+=15;
//			tempStack.push(new Paitient(*temp));
//		}
//		else tempQueue.enqueue(temp);
//		current = current->next_waiter;
//		this->dequeue_paitient();
//	}
//	*this = tempQueue;
//	while (!tempStack.isEmpty()) {
//		this->enqueue_paitient(new Paitient(*tempStack.peek_with_popping()));
//	}
//}
//void HospitalQueue::doctor_call() {
//	dequeue_paitient();
//	cout << "\n+-----------------------------------------------+\n";
//	cout << "|                Next Patient Info              |\n";
//	cout << "+-----------------------------------------------+\n";
//	cout << "| Name       : " << left << setw(30) << next_paitient->name << "|\n";
//	cout << "| Age        : " << setw(30) << next_paitient->age << "|\n";
//	cout << "| Condition  : " << setw(30) << next_paitient->condition << "|\n";
//	cout << "+-----------------------------------------------+\n";
//	increment_waiting_time();
//}
//Paitient* HospitalQueue::reception() {
//	Paitient* new_paitient = new Paitient();
//	new_paitient->register_paitient();
//	return new_paitient;
//}
////<-----------------------------------------HOSPITAL QUEUE-------------------------------------------------->
//HospitalStack::HospitalStack() {
//	top_paitient = nullptr;
//}
//void HospitalStack::push(Paitient* new_paitient) {
//	if(!new_paitient) return;
//	if(!top_paitient){
//		new_paitient->next_waiter = nullptr;
//		top_paitient = new_paitient; return;
//	}
//	new_paitient->next_waiter = top_paitient;
//	top_paitient = new_paitient;
//}
//void HospitalStack::pop() {
//	if(!top_paitient) return;
//	Paitient* temp = top_paitient;
//	top_paitient = top_paitient->next_waiter;
//	temp->next_waiter = nullptr;
//	delete temp;
//}
//Paitient* HospitalStack::peek() {
//	return top_paitient;
//}
//bool HospitalStack::isEmpty() {
//	return top_paitient == nullptr;
//}
//void HospitalStack::print_stack() {
//	if (!top_paitient) return;
//	Paitient* current = top_paitient;
//	while (current) {
//		current->print_paitient();
//		current = current->next_waiter;
//	}
//}
//HospitalStack& HospitalStack::operator=(const HospitalStack& rhs) {
//	if (this == &rhs) return *this;
//	while (top_paitient) pop();
//	HospitalStack tempStack;
//	Paitient* current = rhs.top_paitient;
//	while (current) {
//		Paitient* temp = new Paitient(*current);
//		tempStack.push(temp);
//		current = current->next_waiter;
//	}
//	while (!tempStack.isEmpty()) {
//		this->push(new Paitient(*(tempStack.peek_with_popping())));
//	}
//	return *this;
//}
//void HospitalStack::reverse_stack() {
//	if(!top_paitient) return;
//	HospitalStack tempStack;
//	Paitient* current = top_paitient;
//	while (current) {
//		Paitient* temp = new Paitient(*current);
//		tempStack.push(temp);
//		current = current->next_waiter;
//		pop();
//	}
//	*this = tempStack;
//}
//Paitient* HospitalStack::peek_with_popping() {
//	if(!top_paitient) return nullptr;
//	Paitient* temp = new Paitient(*top_paitient);
//	top_paitient = top_paitient->next_waiter;
//	temp->next_waiter = nullptr;
//	return temp;
//}
////<--------------------------------------------PAITIENT----------------------------------------------------->
//Paitient::Paitient() {
//	name = "null";
//	age = 0;
//	condition = "null";
//	priority = 0;
//	waiting_count = 0;
//	next_waiter = nullptr;
//}
//void Paitient::register_paitient() {
//	cout << "Registration Form\n\n";
//	do{
//		cout << "Enter your complete Name:\t";getline(cin, name); 
//		}while(!Helper::isvalid_name(name));
//	do{ 
//		cout << "Enter your age:\t";cin >> age; 
//		}while(age<0 || age>110);
//	cin.ignore();
//	do{ 
//		cout << "Are you\nNormal\nCritical\nIntense\nEnter:\t";getline(cin, condition); 
//		}while(!Helper::isvalid_condition(condition));
//	do{ 
//		cout << "Do you have any Reference?\nPress 1 if you have any reference.\nPress 0 if you don't have any reference.\nInput:\t";cin >> priority; 
//		}while(priority<0 || priority>1);
//	system("cls");
//	cin.ignore();
//	set_priority_order();
//}
//void Paitient::set_priority_order() {
//	int priority_order[4]{0};
//	if(age>=60) priority_order[3] = 1;
//	if(priority) priority_order[0] = 1;
//	if(condition=="intense") {priority_order[1] = 1;priority_order[2] = 0; }
//	if(condition=="critical") { priority_order[1] = 1;priority_order[2] = 1; }
//	priority = Helper::binary_to_decimal(priority_order,4);
//}
//void Paitient::print_paitient() {
//	cout << name;
//}
//Paitient::Paitient(const Paitient& rhs) {
//	name = rhs.name;
//	age = rhs.age;
//	condition = rhs.condition;
//	priority = rhs.priority;
//	waiting_count = rhs.waiting_count;
//	next_waiter = nullptr;
//}
////<--------------------------------------------HELPER----------------------------------------------------->
//bool Helper::isvalid_condition(string condition) {
//	for (int i = 0;i < condition.length();i++) condition[i] = tolower(condition[i]);
//	return (condition == "normal" || condition == "critical" || condition == "intense");
//}
//bool Helper::isvalid_name(string name) {
//	if(name.empty()) return false;
//	for(int i=0;i<name.length();i++) if(!isalpha(name[i])&&!isspace(name[i])) return false;
//	return true;
//}
//int Helper::binary_to_decimal(int arr[], int size) {
//	int sum = 0;
//	for (int i = 0;i <size;i++) sum += (arr[i] * pow(2, size-i-1));
//	return sum;
//}
//
//void myFunct() {
//	cout<<"hello after 2seconds"<<endl;
//}
//
//int main() {
//	HospitalQueue hospital;
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//	hospital.enqueue_paitient(hospital.reception());
//	hospital.print_queue();
//
//	cout<<"\nDequeuing Starts here\n";
//
//	while (hospital.front()) {
//		cout<<endl;
//		hospital.doctor_call();
//		hospital.print_queue();
//		this_thread::sleep_for(chrono::seconds(2));
//		cout<<endl<<endl;
//	}
//}