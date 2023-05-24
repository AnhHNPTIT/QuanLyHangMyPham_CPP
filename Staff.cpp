#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Staff 
{
	private:
		int id; // mã khách hàng
		string name; // tên khách hàng
		string birthday; // ngày sinh
		int gender; // giới tính 0 - nữ, 1 - nam
		string phoneNumber; // số điện thoại
		string address; // địa chỉ
		string email; // email
		int level; // phân quyền 0 - nhân viên, 1 - quản lý
		int status; // trạng thái hoạt động 0 - đang bị chặn, 1 - đang hoạt động

	public:
		Staff() {
			this->id = 0;
			this->name = "";
			this->birthday = "";
			this->gender = 0;
			this->phoneNumber = "";
			this->address = "";
			this->email = "";
			this->level = 0;
			this->status = 0;
		}

		Staff(int id, string name, string birthday, int gender, string phoneNumber, string address, string email, int level, int status) {
			this->id = id;
			this->name = name;
			this->birthday = birthday;
			this->gender = gender;
			this->phoneNumber = phoneNumber;
			this->address = address;
			this->email = email;
			this->level = level;
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

		string getEmail() {
			return this->email;
		}

		void setEmail(string email) {
			this->email = email;
		}

		int getLevel() {
			return this->level;
		}

		void setLevel(int level) {
			this->level = level;
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
			cout << phoneNumber << "\t" << address << "\t"<< email << "\t";
			if (level == 1) {
				cout << "Quản lý" << "\t";
			}
			else {
				cout << "Nhân viên" << "\t";
			}
			if (level == 1) {
				cout << "Đang hoạt động";
			}
			else {
				cout << "Đang bị chặn";
			}
			cout << endl;
		}

		Staff enterInfo() {
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
			cout << "Email: ";
			getline(cin, email);
			cout << "Phân quyền (0 - nhân viên, 1 - quản lý): ";
			cin >> level;
			cout << "Trạng thái hoạt động (0 - đang bị chặn, 1 - đang hoạt động): ";
			cin >> status;
			return Staff(id, name, birthday, gender, phoneNumber, address, email, level, status);
		}

};