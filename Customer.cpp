#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Customer 
{
	private:
		int id; // mã khách hàng
		string name; // tên khách hàng
		string birthday; // ngày sinh
		int gender; // giới tính 0 - nữ, 1 - nam
		string phoneNumber; // số điện thoại
		string address; // địa chỉ
		int status; // trạng thái hoạt động 0 - đang bị chặn, 1 - đang hoạt động

	public:
		Customer() {
			this->id = 0;
			this->name = "";
			this->birthday = "";
			this->gender = 0;
			this->phoneNumber = "";
			this->address = "";
			this->status = 0;
		}

		Customer(int id, string name, string birthday, int gender, string phoneNumber, string address, int status) {
			this->id = id;
			this->name = name;
			this->birthday = birthday;
			this->gender = gender;
			this->phoneNumber = phoneNumber;
			this->address = address;
			this->status = status;
		}
		
		int getId() {
			return this->id;
		}

		void setId(int id) {
			this->id = id;
		}
		
		string getName() {
			return this->name;
		}

		void setName(string name) {
			this->name = name;
		}

		string getBirthday() {
			return this->birthday;
		}

		void setBirthday(string birthday) {
			this->birthday = birthday;
		}

		int getGender() {
			return this->gender;
		}

		void setGender(int gender) {
			this->gender = gender;
		}

		string getPhoneNumber() {
			return this->phoneNumber;
		}

		void setPhoneNumber(string phoneNumber) {
			this->phoneNumber = phoneNumber;
		}

		string getAddress() {
			return this->address;
		}

		void setAddress(string address) {
			this->address = address;
		}

		int getStatus() {
			return this->status;
		}

		void setStatus(int status) {
			this->status = status;
		}

		void displayInfo() {
			cout << id << "\t\t" << name << "\t\t" << birthday << "\t";
			if (gender == 0) {
				cout << "Nữ" << "\t\t";
			}
			else {
				cout << "Nam" << "\t\t";
			}
			cout << phoneNumber << "\t" << address << "\t";
			if (status == 1) {
				cout << "Đang hoạt động";
			}
			else {
				cout << "Đang bị chặn";
			}
			cout << endl;
		}

		Customer enterInfo() {
			cout << "Mã khách hàng: ";
			cin >> id;
			cin.ignore();
			cout << "Tên khách hàng: ";
			getline(cin, name);
			cout << "Ngày sinh (định dạng theo yyyy-mm-dd): ";
			getline(cin, birthday);
			cout << "Giới tính (0 - nữ, 1 - nam): ";
			cin >> gender;
			cin.ignore();
			cout << "Số điện thoại: ";
			getline(cin, phoneNumber);
			cout << "Địa chỉ: ";
			getline(cin, address);
			cout << "Trạng thái hoạt động (0 - đang bị chặn, 1 - đang hoạt động): ";
			cin >> status;
			return Customer(id, name, birthday, gender, phoneNumber, address, status);
		}

};