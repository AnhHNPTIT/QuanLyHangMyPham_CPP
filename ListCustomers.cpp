#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
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
		ListCustomers() {
			head = NULL;
		}

		~ListCustomers() {
			while (head != NULL) {
				Node* temp = head;
				head = head->next;
				delete temp->data;
				delete temp;
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

		void updateCustomer(Customer* customer) {
			Node* current = head;
			while (current != NULL) {
				if (current->data->getId() == customer->getId()) {
					current->data = customer;
					return;
				}
				current = current->next;
			}
			cout << "Khách hàng không tồn tại" << endl;
		}

		void deleteCustomer(int id) {
			if (head == NULL) {
				cout << "Danh sách khách hàng trống" << endl;
				return;
			}
			if (head->data->getId() == id) {
				Node* temp = head;
				head = head->next;
				delete temp->data;
				delete temp;
				cout << "Xóa khách hàng thành công" << endl;
				return;
			}
			Node* prev = head;
			Node* current = head->next;
			while (current != NULL) {
				if (current->data->getId() == id) {
					prev->next = current->next;
					delete current->data;
					delete current;
					cout << "Xóa khách hàng thành công" << endl;
					return;
				}
				prev = current;
				current = current->next;
			}
			cout << "Khách hàng không tồn tại" << endl;
		}

		void searchCustomer(string name) {
			int count = 0;
			Node* current = head;
			while (current != NULL) {
				if (current->data->getName() == name) {
					current->data->displayInfo();
					count++;
				}
				current = current->next;
			}
			if (count == 0) {
				cout << "Khách hàng không tồn tại" << endl;
			}
		}

		void enterListCustomers(int &num) {		
			for (int i = 1; i <= num; i++) {
				cout << "Nhập thông tin khách hàng thứ " << i << ":" << endl;
				Customer* customer = new Customer();
				customer->enterInfo();
        		addCustomer(customer);
			}
		}

		void displayListCustomers() {
			cout << "Mã khách hàng\t" << "Tên khách hàng\t\t" << "Ngày sinh\t" << "Giới tính\t" << "Số điện thoại\t" << "Địa chỉ\t\t\t\t" <<  "Trạng thái" << endl;
			Node* current = head;
			while (current != NULL) {
				current->data->displayInfo();
				current = current->next;
			}
		}

		void saveListCustomers() {
			ofstream file("customers.csv",ios::out);
			Node* current = head;
			while (current != NULL) {
				Customer* customer = current->data;
				file << customer->getId() << "," << customer->getName() << "," << customer->getBirthday() << "," << customer->getGender() << ","
					<< customer->getPhoneNumber() << "," << customer->getAddress() << "," << customer->getStatus() << endl;
				current = current->next;
			}
			file.close();
		}

		void readFileCustomers() {
			int id; 
			string name; 
			string birthday; 
			int gender; 
			string phoneNumber; 
			string address; 
			int status; 

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
				addCustomer(customer);
			}
			// Đóng file
			file.close();
		}

		void sortListCustomersByIdASC() {
			if (head == NULL || head->next == NULL) {
				return;
			}
			bool swapped;
			Node* current;
			Node* tail = NULL;
			do {
				swapped = false;
				current = head;
				while (current->next != tail) {
					if (current->data->getId() > current->next->data->getId()) {
						Customer* temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				tail = current;
			} while (swapped);
		}

		void sortListCustomersByNameDESC() {
			if (head == NULL || head->next == NULL) {
				return;
			}
			bool swapped;
			Node* current;
			Node* tail = NULL;
			do {
				swapped = false;
				current = head;
				while (current->next != tail) {
					if (current->data->getName() < current->next->data->getName()) {
						Customer* temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				tail = current;
			} while (swapped);
		}

		Customer* findCustomerWithIdMax() {
			if (head == NULL) {
				return NULL;
			}

			Node* current = head;
			Customer* result = current->data;
			int idMax = result->getId();

			while (current != NULL) {
				if (current->data->getId() > idMax) {
					idMax = current->data->getId();
					result = current->data;
				}
				current = current->next;
			}

			return result;
		}

		Customer* findCustomerWithIdMin() {
			if (head == NULL) {
				return NULL;
			}

			Node* current = head;
			Customer* result = current->data;
			int idMin = result->getId();

			while (current != NULL) {
				if (current->data->getId() < idMin) {
					idMin = current->data->getId();
					result = current->data;
				}
				current = current->next;
			}

			return result;
		}

		int countCustomers() {
			int result = 0;
			Node* current = head;
			while (current != NULL) {
				result++;
				current = current->next;
			}
			return result;
		}

		float calAvgAge() {
			int sumAge = 0;
			int numCustomers = countCustomers();

			time_t currentTime = time(NULL);
			tm* localTime = localtime(&currentTime);
			int currentYear = localTime->tm_year + 1900;

			Node* current = head;
			while (current != NULL) {
				string birthday = current->data->getBirthday();
				string getYear = birthday.substr(0, 4);
				int year = atoi(getYear.c_str());

				sumAge += (currentYear - year);
				current = current->next;
			}
			return static_cast<float>(sumAge)/static_cast<float>(numCustomers);
		}

		float calRatioWomen() {
			int numWomen = 0;
			int numCustomers = countCustomers();

			Node* current = head;
			while (current != NULL) {
				if (current->data->getGender() == 0) {
					numWomen++;
				}
				current = current->next;
			}
			return static_cast<float>(numWomen)*100/static_cast<float>(numCustomers);
		}

		void statsBlockedCustomer() {
			int count = 0;
			Node* current = head;
			while (current != NULL) {
				if (current->data->getStatus() == 0) {
					current->data->displayInfo();
					count++;
				}
				current = current->next;
			}
			if (count == 0) {
				cout << "Không có dữ liệu nào" << endl;
			}
		}

		void statsCustomersByAge() {
			int count = 0;
			time_t currentTime = time(NULL);
			tm* localTime = localtime(&currentTime);
			int currentYear = localTime->tm_year + 1900;

			Node* current = head;
			while (current != NULL) {
				string birthday = current->data->getBirthday();
				string getYear = birthday.substr(0, 4);
				int year = atoi(getYear.c_str());

				int age = currentYear - year;
				if (age >= 18 && age <= 30) {
					current->data->displayInfo();
				}
				current = current->next;
			}
			if (count == 0) {
				cout << "Không có dữ liệu nào" << endl;
			}
		}

		void statsWomen() {
			int count = 0;
			Node* current = head;
			while (current != NULL) {
				if (current->data->getGender() == 0) {
					current->data->displayInfo();
					count++;
				}
				current = current->next;
			}
			if (count == 0) {
				cout << "Không có dữ liệu nào" << endl;
			}
		}
};