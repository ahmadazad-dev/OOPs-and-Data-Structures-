//#include<iostream>
//using namespace std;
//
//class Train {
//
//	class Compartment {
//		int compartment_number;
//		int passenger_count;
//		Compartment* next;
//	public:
//		static int compartment_count;
//		Compartment();
//		~Compartment();
//		Compartment(const int);
//		Compartment* get_next();
//		void set_next(Compartment*);
//		int get_passenger_count();
//		void set_passenger_count(const int);
//		void print_Compartment();
//		void print_all_Compartments();
//
//	};
//
//	Compartment* head;
//
//public:
//	Train();
//	~Train();
//	void print_train();
//	void push_compartment(int);
//	void station_reached(const int[]);
//	void minimum_passenger_rule();
//	bool check_compartments_passengers();
//	bool check_compartments_capacity();
//	bool all_filled();
//	void maximum_capacity_rule();
//};
//
//int Train::Compartment::compartment_count = 0;
//
////Functions of class Compartment
//Train::Compartment::Compartment() {//Default constructor
//	passenger_count = 0;
//	compartment_number = compartment_count;
//	next = nullptr;
//}
//Train::Compartment::Compartment(const int passenger_count) {//Overloaded Constructor
//	compartment_number = compartment_count;
//	this->passenger_count = passenger_count;
//	this->next = nullptr;
//}
//Train::Compartment::~Compartment() {
//	next = nullptr;
//}
//void Train::Compartment::print_all_Compartments() {//Print all Compartments of a List
//	cout << "  -  " << passenger_count << "  -  ";
//	if (this->next) {
//		next->print_all_Compartments();
//	}
//}
//void Train::Compartment::print_Compartment() {//Print single Compartment
//	if (passenger_count >= 10) {
//		cout << " |      " << passenger_count << "     |";
//	}
//	else {
//		cout << " |      " << passenger_count << "      |";
//	}
//}
//void Train::Compartment::set_next(Compartment* next) {//Sets the address of the next Compartment
//	this->next = next;
//}
//Train::Compartment* Train::Compartment::get_next() {//Returns the address of the next Compartment
//	return this->next;
//}
//void Train::Compartment::set_passenger_count(const int passenger_count) {
//	this->passenger_count = passenger_count;
//}
//int Train::Compartment::get_passenger_count() {
//	return passenger_count;
//}
//
////Functions of class Train
//Train::Train() {
//	head = nullptr;
//}
//Train::~Train() {
//	if (!head) {
//		return;
//	}
//	Compartment* current = head->get_next();
//	Compartment* temp = nullptr;
//	if (current == head) {
//		delete head;
//		head = nullptr;
//		return;
//	}
//	while (current != head) {
//		temp = current;
//		current = current->get_next();
//		delete temp;
//	}
//	delete head;
//	head = nullptr;
//}
//void Train::print_train() {
//	if (head) {
//		Compartment* current = head;
//		if (Train::Compartment::compartment_count == 1 && current == head && current->get_passenger_count() == 0) {
//			cout << "\n All Passengers have left the train\n";
//			return;
//		}
//		cout << endl;
//		cout << endl;
//		cout << "           }}" << endl;
//		cout << "          /  \\" << endl;
//		cout << "          |  |" << endl;
//		for (int i = 0;i < Train::Compartment::compartment_count;i++) {
//			cout << " ---------------   ";
//		}
//		cout << endl;
//		for (int i = 0;i < Train::Compartment::compartment_count;i++) {
//			cout << " |             |   ";
//		}
//		cout << endl;
//		do {
//			current->print_Compartment();
//			if (current->get_next() != head) {
//				cout << " ->";
//			}
//			current = current->get_next();
//		} while (current != head);
//		cout << endl;
//		for (int i = 0;i < Train::Compartment::compartment_count;i++) {
//			cout << " |             |   ";
//		}
//		cout << endl;
//		for (int i = 0;i < Train::Compartment::compartment_count;i++) {
//			cout << " --<O>-----<O>--   ";
//		}
//		cout << endl;
//		for (int i = 0;i < Train::Compartment::compartment_count;i++) {
//			cout << "-------------------";
//		}
//		cout << endl;
//	}
//}
//void Train::push_compartment(int passenger_count) {
//	Compartment* new_compartment = new Compartment(passenger_count);
//	if (!head) {
//		head = new_compartment;
//		head->set_next(head);
//	}
//	else {
//		Compartment* current = head->get_next();
//		while (current->get_next() != head) {
//			current = current->get_next();
//		}
//		current->set_next(new_compartment);
//		new_compartment->set_next(head);
//	}
//	Train::Compartment::compartment_count++;
//}
//bool Train::check_compartments_passengers() {//Returns false if any of the compartment has less than 3 passengers
//	Compartment* current = head;
//	do {
//		if (current->get_passenger_count() <= 3) {
//			return false;
//		}
//		current = current->get_next();
//	} while (current != head);
//	return true;
//}
//bool Train::check_compartments_capacity() {//returns false if any of the compartment has more than 10 passengers
//	Compartment* current = head;
//	do {
//		if (current->get_passenger_count() > 10) {
//			return false;
//		}
//		current = current->get_next();
//	} while (current != head);
//	return true;
//}
//bool Train::all_filled() {//returns true if all the compartments are fully filled
//	Compartment* current = head;
//	do {
//		if (current->get_passenger_count() < 10) {
//			return false;
//		}
//		current = current->get_next();
//	} while (current != head);
//	return true;
//}
//void Train::minimum_passenger_rule() {//applies minimum passenger rule
//	if (head) {
//		Compartment* previous = head;
//		Compartment* forwards = previous->get_next();
//		do {
//			if (forwards->get_passenger_count() <= 3) {
//
//				if (previous == forwards) {
//					return;
//				}
//
//				forwards->get_next()->set_passenger_count(forwards->get_next()->get_passenger_count() + forwards->get_passenger_count());
//				previous->set_next(forwards->get_next());
//
//				if (forwards == head) {
//					head = forwards->get_next();
//				}
//
//				delete forwards;
//				forwards = previous->get_next();
//				Train::Compartment::compartment_count--;
//			}
//			else {
//				previous = forwards;
//				forwards = forwards->get_next();
//			}
//			if (this->check_compartments_passengers()) {
//				break;
//			}
//		} while (true);
//	}
//	else {
//		cout << "Out of range";
//	}
//}
//void Train::maximum_capacity_rule() {//applies maximum passenger rule
//	if (head) {
//		Compartment* previous = head;
//		Compartment* forwards = previous->get_next();
//		int extra_passengers = 0;
//		do {
//			if (forwards->get_passenger_count() > 10) {
//
//				extra_passengers = forwards->get_passenger_count() - 10;
//
//				if (this->all_filled()) {
//					this->push_compartment(extra_passengers);
//					forwards->set_passenger_count(forwards->get_passenger_count() - extra_passengers);
//					if (!this->check_compartments_capacity()) {
//						this->maximum_capacity_rule();
//					}
//					break;
//				}
//				else {
//					forwards->get_next()->set_passenger_count(extra_passengers + forwards->get_next()->get_passenger_count());
//					forwards->set_passenger_count(forwards->get_passenger_count() - extra_passengers);
//
//					previous = forwards;
//					forwards = forwards->get_next();
//				}
//
//			}
//			else {
//				previous = forwards;
//				forwards = forwards->get_next();
//			}
//			if (this->check_compartments_capacity()) {
//				break;
//			}
//		} while (true);
//	}
//	else {
//		cout << "Out of range";
//	}
//}
//void Train::station_reached(const int leaving_passengers[]) {
//	cout << "\n<============== STATION REACHED ==============>\n\n";
//	Compartment* current = head;
//	int i = 0;
//	do {
//		int new_passenger_count = current->get_passenger_count() - leaving_passengers[i++];
//		current->set_passenger_count((new_passenger_count) ? new_passenger_count : 0);
//		current = current->get_next();
//	} while (current != head);
//	this->minimum_passenger_rule();
//	this->maximum_capacity_rule();
//}
//
//
//
//int main() {
//	Train Thomas;
//	int size;
//
//	do {
//		cout << "Enter size of Train (>=0): ";
//		cin >> size;
//		if (size < 0) {
//			cout << "Invalid input. Size must be non-negative.\n";
//		}
//	} while (size < 0);
//
//	if (size == 0) {
//		cout << " Train has no compartments.\n";
//		return 0;
//	}
//
//	int* initial_passengers = new int[size];
//
//	for (int i = 0; i < size; i++) {
//		int passengers;
//		do {
//			cout << "Compartment " << (i + 1) << " - Enter Passengers (3-10): ";
//			cin >> passengers;
//			if (passengers < 3 || passengers > 10) {
//				cout << "Invalid input. Must be between 3 and 10.\n";
//			}
//		} while (passengers < 3 || passengers > 10);
//
//		initial_passengers[i] = passengers;
//		Thomas.push_compartment(passengers);
//	}
//
//	cout << "\n Initial Train: \n";
//	Thomas.print_train();
//
//	int* leaving_passengers = new int[size];
//	cout << "\nEnter number of leaving passengers at station:\n";
//
//	for (int i = 0; i < size; i++) {
//		int leaving;
//		do {
//			cout << "Compartment " << (i + 1)
//				<< " (Max " << initial_passengers[i] << "): ";
//			cin >> leaving;
//			if (leaving < 0 || leaving > initial_passengers[i]) {
//				cout << " Invalid input. Must be between 0 and "
//					<< initial_passengers[i] << ".\n";
//			}
//		} while (leaving < 0 || leaving > initial_passengers[i]);
//
//		leaving_passengers[i] = leaving;
//	}
//
//	Thomas.station_reached(leaving_passengers);
//	Thomas.print_train();
//
//}