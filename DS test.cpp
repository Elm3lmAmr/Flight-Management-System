#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define Elm3lm ios ::sync_with_stdio(false), cin.tie(nullptr), cout.tie(NULL);

class Flight {
private:

	// Private Attributes 

	int flight_id;
	int capacity;
	string airline, destination, model, departure_time;
	double ticket_price;

public:
	// parameterized constructor 
	Flight() {
		//cout << "hello first btngan"; 
	}


	Flight(int new_flight_id, string new_model, int new_capacity, string new_airline, string new_destination, string new_departure_time, double new_ticket_price)

		// initializes the private member variable with the new values

		: flight_id(new_flight_id),
		model(new_model),
		capacity(new_capacity),
		airline(new_airline),
		destination(new_destination),
		departure_time(new_departure_time),
		ticket_price(new_ticket_price) {}

	// Getters

	int get_flight_id() {
		return flight_id;
	}
	string get_model() {
		return model;
	}
	int get_capacity() {
		return capacity;
	}
	string get_airline() {
		return airline;
	}
	string get_destination() {
		return destination;
	}
	string get_departure_time() {
		return departure_time;
	}
	double get_ticket_price() {
		return ticket_price;
	}

	// Setters

	void set_flight_id(int new_flight_id) {
		flight_id = new_flight_id;
	}
	void set_model(string new_model) {
		model = new_model;
	}
	void set_capacity(int new_capacity) {
		capacity = new_capacity;
	}
	void set_airline(string new_airline) {
		airline = new_airline;
	}
	void set_destination(string new_destination) {
		destination = new_destination;
	}
	void set_departure_time(string new_departure_time) {
		departure_time = new_departure_time;
	}
	void set_ticket_price(double new_ticket_price) {
		ticket_price = new_ticket_price;
	}

	// Display Flight Information

	void display_Flight_info() {
		cout << "Flight Information:" << el;
		cout << "Flight ID: " << flight_id << el;
		cout << "Model: " << model << el;
		cout << "Capacity: " << capacity << el;
		cout << "Airline: " << airline << el;
		cout << "Destination: " << destination << el;
		cout << "Departure Time: " << departure_time << el;
		cout << "Ticket Price: " << ticket_price << el;
	}

		// Check if two flights are equal
		bool IsEqual(const Flight& other) const {
			return (flight_id == other.flight_id &&
				model == other.model &&
				capacity == other.capacity &&
				airline == other.airline &&
				destination == other.destination &&
				departure_time == other.departure_time &&
				ticket_price == other.ticket_price);
		}

	};


template <class A>
class Node :  public Flight {
public:

	A data;
	Node<A>* next;

	Node(A e) {
		data = e;
		next = NULL;
	}


};

template <class A>
class FlightList : Flight {
	Node<A>* head;
public:
	FlightList() {
		head = NULL;
	}
	void  insert_flight(int prev_id, A flight) {
		Node<A>* newNode = new Node<A>(flight);

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node<A>* prevNode = head; 
			while (prevNode->data.get_flight_id() != prev_id) {
				prevNode = prevNode->next;
			}

			newNode->next= prevNode->next;
			prevNode->next = newNode;

		}
		



	}

	// insert a new Flight at the end of the list

	void AddFlight(A flight) {
		Node<A>* newNode = new Node<A>(flight);

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node<A>* current = head;
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = newNode;
		}


	}

	// Delete a Flight From The List By Flight_ID

	void delFlight(int flight_id) {
		if (head == NULL) {
			cout << "Error: The list is empty." << el;
			return;
		}
		if (head->data.get_flight_id() == flight_id) {
			Node<A>* temp = head;
			head = head->next;
			delete temp;

			return;
		}
		Node<A>* current = head;
		Node<A>* previous = NULL;

		// search for the flight id 

		while (current != NULL && current->data.get_flight_id() != flight_id) {
			previous = current;
			current = current->next;
		}

		// If the flight id is found

		if (current != NULL && current->data.get_flight_id() == flight_id) {
			previous->next = current->next;
			delete current;
		}
		// if not found
		else {
			cout << "Error: Flight with ID " << flight_id << " not found." << el;
		}

	}
	void DisplayAll(){
		Node<A>* current = head;
		while (current != NULL) {
			current->data.display_Flight_info();
			cout << "-----------------------------" << el;
			if (current == NULL)cout << "THERE IS NOTHING TO DISPLAY";
			current = current->next;
		}

	}
};

template <class A>
class FlightStack : Flight {
private:
	Node<A>* top;

public:
	FlightStack() : top(NULL) {}

	// Check The Duplicated flights

	bool DuplicateFlight(A flight) {
		Node<A>* current = top;

		while (current != NULL) {
			if (current->data.IsEqual(flight)) {
				return true;
			}
			current = current->next;
		}

		return false;
	}

	// Add flight to the stack

	void PushFlight(A flight) {

		// Check for duplicates before pushing

		if (DuplicateFlight(flight))
			cout << "Error: Duplicate flight, rejected." << el;

		Node<A>* newNode = new Node<A>(flight);

		if (newNode == NULL) {
			cout << "Error: Memory allocation failed." << el;
		}

		newNode->next = top;
		top = newNode;
	}

	// Print flights in LIFO order

	void PrintStack() {
		Node<A>* current = top;

		while (current != NULL) {
			current->data.display_Flight_info();
			cout << "-----------------------------" << el;
			current = current->next;
		}
	}

	// Check if the stack is empty

	bool IsEmpty() {
		return top == NULL;
	}

	// Return the latest flight
	A Peek() {
		if (IsEmpty()) {
			cout << "Error: Stack is empty, Cannot Peek. ";
		}
		else
			return top->data;
	}

	// Edit flight information
		// overload func operator ==

	


	void EditFlight(int oldFlightID, A newFlight) {
		Node<A>* current = top;

		while (current != NULL) {
			if (current->data.get_flight_id()== oldFlightID){
				current->data = newFlight;
			}
			current = current->next;
		}

		if (current->data.get_flight_id() != oldFlightID)
			cout << "Error: Flight not found for editing." << el;
	}




	// Delete flight information

	void DeleteFlight(int flight_id) {
		if (top == NULL) {
			cout << "Error: Stack is empty, Cannot delete." << el;
		}

		if (top->data.get_flight_id() == flight_id) {
			Node<A>* temp = top;
			top = top->next;
			delete temp;
		}

		Node<A>* current = top;
		Node<A>* previous = NULL;

		while (current != NULL && current->data.get_flight_id() != flight_id) {
			previous = current;
			current = current->next;
		}

		if (current != NULL) {
			previous->next = current->next;
			delete current;
		}
		else {
			cout << "Error: Flight not found for deletion." << el;
		}
	}
};

int main() {
	cout << "Welcome to the Flight Management System" << el;

	int mainChoice;
	int subChoice;
	bool continueProgram = true;

	FlightList<Flight> flightList;
	Flight f;
	FlightStack<Flight> flightStack;


	int flight_id, capacity, oldID;
	string airline, destination, model, departure_time;
	double ticket_price;





	do {
		cout << "Choose one of the following options:" << el;
		cout << "1. Linked List" << el;
		cout << "2. Stack" << el;
		cout << "3. Close the program" << el;
		cout << "Enter your choice: ";

		cin >> mainChoice;

		switch (mainChoice) {
		case 1:
			do {
				cout << "Linked List Operations:" << el;
				cout << "1. Add new flight" << el;
				cout << "2. Delete Flight" << el;
				cout << "3. Display All Flights" << el;
				cout << "4. Insert new flight" << el;
				cout << "5. Back to main menu" << el;
				cout << "Enter your choice: ";

				cin >> subChoice;

				switch (subChoice) {
				case 1:
					cout << "Enter Flight ID to Add: "; cin >> flight_id; f.set_flight_id(flight_id);
					cout << "Enter capacity to Add: "; cin >> capacity; f.set_capacity(capacity);
					cout << "Enter airline to Add: "; cin >> airline; f.set_airline(airline);
					cout << "Enter destination to Add: "; cin >> destination; f.set_destination(destination);
					cout << "Enter model to Add: "; cin >> model; f.set_model(model);
					cout << "Enter departure_time to Add: "; cin >> departure_time; f.set_departure_time(departure_time);
					cout << "Enter ticket_price to Add: "; cin >> ticket_price; f.set_ticket_price(ticket_price);

					flightList.AddFlight(f);
					break;
				case 2:
					int flight_To_Delete;
					cout << "Enter Flight ID to delete: ";
					cin >> flight_To_Delete;
					flightList.delFlight(flight_To_Delete);
					break;
				case 3:
					flightList.DisplayAll();
					break;
				case 4:
					int prev_id;
					cout << "Enter Previous Flight ID : "; cin >> prev_id;

					cout << "Enter  NewFlight ID to Insert: "; cin >> flight_id; f.set_flight_id(flight_id);
					cout << "Enter capacity to Insert: "; cin >> capacity; f.set_capacity(capacity);
					cout << "Enter airline to Insert: "; cin >> airline; f.set_airline(airline);
					cout << "Enter destination to Insert: "; cin >> destination; f.set_destination(destination);
					cout << "Enter model to Insert: "; cin >> model; f.set_model(model);
					cout << "Enter departure_time to Insert: "; cin >> departure_time; f.set_departure_time(departure_time);
					cout << "Enter ticket_price to Insert: "; cin >> ticket_price; f.set_ticket_price(ticket_price);

					flightList.insert_flight(prev_id, f);
					break;
				case 5:
					// Back to main menu
					break;
				default:
					cout << "Invalid choice. Please enter a valid option." << el;
					break;
				}
			} while (subChoice != 5);
			break;

		case 2:
			do {
				cout << "Stack Operations:" << el;
				cout << "1. Insert new flight" << el;
				cout << "2. Check the latest Added Flight" << el;
				cout << "3. Print all the flights" << el;
				cout << "4. Edit flight" << el;
				cout << "5. Delete flight" << el;
				cout << "6. Back to main menu" << el;
				cout << "Enter your choice: ";

				cin >> subChoice;

				switch (subChoice) {
				case 1:
					cout << "Enter Flight ID to Push: "; cin >> flight_id; f.set_flight_id(flight_id);
					cout << "Enter capacity to Push: "; cin >> capacity; f.set_capacity(capacity);
					cout << "Enter airline to Push: "; cin >> airline; f.set_airline(airline);
					cout << "Enter destination to Push: "; cin >> destination; f.set_destination(destination);
					cout << "Enter model to Push: "; cin >> model; f.set_model(model);
					cout << "Enter departure_time to Push: "; cin >> departure_time; f.set_departure_time(departure_time);
					cout << "Enter ticket_price to Push: "; cin >> ticket_price; f.set_ticket_price(ticket_price);
					flightStack.PushFlight(f);
					break;
				case 2:
					try {
						flightStack.Peek().display_Flight_info();
					}
					catch (exception e) {
						cout << e.what() << el;
					}
					break;
				case 3:
					flightStack.PrintStack();
					break;
					
					case 4:
						
						cout << "Enter Old Flight ID : "; cin >> oldID;
						
						cout << "-------------------------------------------------------------"<<el;
						cout << "Enter  New Flight ID to Insert: "; cin >> flight_id; f.set_flight_id(flight_id);
						cout << "Enter New capacity to Insert: "; cin >> capacity; f.set_capacity(capacity);
						cout << "Enter New airline to Insert: "; cin >> airline; f.set_airline(airline);
						cout << "Enter New destination to Insert: "; cin >> destination; f.set_destination(destination);
						cout << "Enter New model to Insert: "; cin >> model; f.set_model(model);
						cout << "Enter New departure_time to Insert: "; cin >> departure_time; f.set_departure_time(departure_time);
						cout << "Enter New ticket_price to Insert: "; cin >> ticket_price; f.set_ticket_price(ticket_price);

						flightStack.EditFlight(oldID,f);
						break;
						
					case 5:
						int flight_To_Delete;
						cout << "Enter Flight ID to delete: ";
						cin >> flight_To_Delete;
						flightStack.DeleteFlight(flight_To_Delete);
						break;
					case 6:
						// Back to main menu
						break;
					default:
						cout << "Invalid choice. Please enter a valid option." << el;
						break;
				}
			} while (subChoice != 6);
			break;

		case 3:
			continueProgram = false;
			break;

		default:
			cout << "Invalid choice. Please enter a valid option." << el;
			break;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (continueProgram);

	cout << "Program closed. Goodbye!" << el;

	return 0;
}
