#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Customer.cpp"

using namespace std;

class ListCustomers
{
	private:
		struct Node {
			Customer* data;
			Node* next;
		};
		Node* head;

	public:
		// Hàm khởi tạo không tham số
		ListCustomers() {
			head = NULL;
		}

		~ListCustomers() {
			Node* current = head;
			while (current != NULL) {
				Node* next = current->next;
				delete current->data;
				delete current;
				current = next;
			}
		}
		
		void addCustomer(Customer* data) {
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;

			if (head == NULL) {
				head = newNode;
			} 
			else {
				Node* current = head;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = newNode;
			}
		}

		void enterListCustomers(ListCustomers listCustomers, int &num) {
			int id; 
			string name; 
			string birthday; 
			int gender; 
			string phoneNumber; 
			string address; 
			int status; 
			
			for (int i = 1; i <= num; i++) {
				cout << "Nhập thông tin khách hàng thứ " << i+1 << ":" << endl;
				cout << "Mã khách hàng: ";
				cin >> id;
				cout << "Tên khách hàng: ";
				cin >> name;
				cout << "Ngày sinh: ";
				cin >> birthday;
				cout << "Giới tính (0 - nữ, 1 - nam): ";
				cin >> gender;
				cout << "Số điện thoại: ";
				cin >> phoneNumber;
				cout << "Địa chỉ: ";
				cin >> address;
				cout << "Trạng thái hoạt động (0 - đang bị chặn, 1 - đang hoạt động): ";
				cin >> status;

				Customer* customer = new Customer(id, name, birthday, gender, phoneNumber, address, status);
        		listCustomers.addCustomer(customer);
			}
		}

		void displayListCustomers() {
			cout << "Mã khách hàng\t" << "Tên khách hàng\t\t" << "Ngày sinh\t" << "Giới tính\t" << "Số điện thoại\t" << "Địa chỉ\t\t\t\t" <<  "Trạng thái" << endl;
			Node* current = head;
			while (current != NULL) {
				current->data->displayInfo();
				cout << endl;
				current = current->next;
			}
		}

		

		
};

void readFileCustomers(ListCustomers &listCustomers){
	int id; 
	string name; 
	string birthday; 
	int gender; 
	string phoneNumber; 
	string address; 
	int status; 
	// Customer customer;

	ifstream file("customers.csv",ios::in);
	if(!file){
		cout << "Error:can not open file";
		return;
	}
	string line;
	while (getline(file, line, ',')) {
		id = atoi(line.c_str());
		getline(file, line, ',');
		name = line;
		getline(file, line, ',');
		birthday = line;
		getline(file, line, ',');
		gender = atoi(line.c_str());
		getline(file, line, ',');
		phoneNumber = line;
		getline(file, line, ',');
		address = line;
		getline(file, line, '\n');
		status = atoi(line.c_str());

		Customer* customer = new Customer(id, name, birthday, gender, phoneNumber, address, status);
		listCustomers.addCustomer(customer);
	}
	// Đóng file
	file.close();
}

int main() {
    ListCustomers listCustomers;
	readFileCustomers(listCustomers);
	listCustomers.displayListCustomers();

    
}