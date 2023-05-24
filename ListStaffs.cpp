#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "Staff.cpp"

using namespace std;

class ListStaffs
{
	private:
		struct Node {
			Staff* data;
			Node* next;
		};
		Node* head;

	public:
		ListStaffs() {
			head = NULL;
		}

		~ListStaffs() {
			while (head != NULL) {
				Node* temp = head;
				head = head->next;
				delete temp->data;
				delete temp;
			}
		}
		
		void addStaff(Staff* data) {
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

		void updateStaff(Staff* staff) {
			Node* current = head;
			while (current != NULL) {
				if (current->data->getId() == staff->getId()) {
					current->data = staff;
					return;
				}
				current = current->next;
			}
			cout << "Nhân viên không tồn tại" << endl;
		}

		void deleteStaff(int id) {
			if (head == NULL) {
				cout << "Danh sách nhân viên trống" << endl;
				return;
			}
			if (head->data->getId() == id) {
				Node* temp = head;
				head = head->next;
				delete temp->data;
				delete temp;
				cout << "Xóa nhân viên thành công" << endl;
				return;
			}
			Node* prev = head;
			Node* current = head->next;
			while (current != NULL) {
				if (current->data->getId() == id) {
					prev->next = current->next;
					delete current->data;
					delete current;
					cout << "Xóa nhân viên thành công" << endl;
					return;
				}
				prev = current;
				current = current->next;
			}
			cout << "Nhân viên không tồn tại" << endl;
		}

		void searchStaff(string name) {
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
				cout << "Nhân viên không tồn tại" << endl;
			}
		}

		void enterListStaffs(int &num) {			
			for (int i = 1; i <= num; i++) {
				cout << "Nhập thông tin nhân viên thứ " << i << ":" << endl;
				Staff* staff = new Staff();
				staff->enterInfo();
        		addStaff(staff);
			}
		}

		void displayListStaffs() {
			cout << "Mã nhân viên\t" << "Tên nhân viên\t\t" << "Ngày sinh\t" << "Giới tính\t" << "Số điện thoại\t" << "Địa chỉ\t\t\t\t" <<  "Email\t\t" << "Phân quyền\t" << "Trạng thái" << endl;
			Node* current = head;
			while (current != NULL) {
				current->data->displayInfo();
				current = current->next;
			}
		}

		void saveListStaffs() {
			ofstream file("staffs.csv",ios::out);
			Node* current = head;
			while (current != NULL) {
				Staff* staff = current->data;
				file << staff->getId() << "," << staff->getName() << "," << staff->getBirthday() << "," << staff->getGender() << ","
					<< staff->getPhoneNumber() << "," << staff->getAddress() << "," << staff->getEmail() << "," << staff->getLevel() << "," << staff->getStatus() << endl;
				current = current->next;
			}
			file.close();
		}

		void readFileStaffs() {
			int id; 
			string name; 
			string birthday; 
			int gender; 
			string phoneNumber; 
			string address; 
			string email; 
			int level; 
			int status; 

			ifstream file("staffs.csv",ios::in);
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
				getline(file, line, ',');
				email = line;
				getline(file, line, ',');
				level = atoi(line.c_str());
				getline(file, line, '\n');
				status = atoi(line.c_str());

				Staff* staff = new Staff(id, name, birthday, gender, phoneNumber, address, email, level, status);
				addStaff(staff);
			}
			// Đóng file
			file.close();
		}

		void sortListStaffsByIdASC() {
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
						Staff* temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				tail = current;
			} while (swapped);
		}

		void sortListStaffsByNameDESC() {
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
						Staff* temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				tail = current;
			} while (swapped);
		}

		Staff* findOldestStaff() {
			if (head == NULL) {
				return NULL;
			}

			time_t currentTime = time(NULL);
			tm* localTime = localtime(&currentTime);
			int currentYear = localTime->tm_year + 1900;

			Node* current = head;
			Staff* result = current->data;
			string birthday = result->getBirthday();
			string getYear = birthday.substr(0, 4);
			int year = atoi(getYear.c_str());
			int ageMax = currentYear - year;

			while (current != NULL) {
				birthday = current->data->getBirthday();
				getYear = birthday.substr(0, 4);
				year = atoi(getYear.c_str());
				int age = currentYear - year;

				if (age > ageMax) {
					ageMax = age;
					result = current->data;
				}
				current = current->next;
			}

			return result;
		}

		Staff* findYoungestStaff() {
			if (head == NULL) {
				return NULL;
			}

			time_t currentTime = time(NULL);
			tm* localTime = localtime(&currentTime);
			int currentYear = localTime->tm_year + 1900;

			Node* current = head;
			Staff* result = current->data;
			string birthday = result->getBirthday();
			string getYear = birthday.substr(0, 4);
			int year = atoi(getYear.c_str());
			int ageMax = currentYear - year;

			while (current != NULL) {
				birthday = current->data->getBirthday();
				getYear = birthday.substr(0, 4);
				year = atoi(getYear.c_str());
				int age = currentYear - year;

				if (age < ageMax) {
					ageMax = age;
					result = current->data;
				}
				current = current->next;
			}

			return result;
		}

		int countStaffs() {
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
			int numStaffs = countStaffs();

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
			return static_cast<float>(sumAge)/static_cast<float>(numStaffs);
		}

		float calRatioWomen() {
			int numWomen = 0;
			int numStaffs = countStaffs();

			Node* current = head;
			while (current != NULL) {
				if (current->data->getGender() == 0) {
					numWomen++;
				}
				current = current->next;
			}
			return static_cast<float>(numWomen)*100/static_cast<float>(numStaffs);
		}

		void statsBlockedStaff() {
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

		void statsActivedManagers() {
			int count = 0;
			Node* current = head;
			while (current != NULL) {
				if (current->data->getStatus() == 1 && current->data->getLevel() == 1) {
					current->data->displayInfo();
					count++;
				}
				current = current->next;
			}
			if (count == 0) {
				cout << "Không có dữ liệu nào" << endl;
			}
		}

		void statsActivedStaffs() {
			int count = 0;
			Node* current = head;
			while (current != NULL) {
				if (current->data->getStatus() == 1 && current->data->getLevel() == 0) {
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