#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Customer.cpp"

using namespace std;

class CustomerManagement
{
	private:
		struct Node {
			Customer* data;
			Node* next;
		};
		Node* head;

	public:
		// Hàm khởi tạo không tham số
		CustomerManagement() {
			head = NULL;
		}

		~CustomerManagement() {
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

		void displayListCustomers() {
			cout << "Mã khách hàng\t" << "Tên khách hàng\t" << "Ngày sinh\t" << "Giới tính\t" << "Số điện thoại\t" << "Địa chỉ\t\t\t\t\t" <<  "Trạng thái" << endl;
			Node* current = head;
			while (current != NULL) {
				current->data->displayInfo();
				cout << endl;
				current = current->next;
			}
		}
};

int main() {
    CustomerManagement qlbh;

    Customer* sp1 = new Customer(1,"Tươi","1997-08-13",0,"0868563617","số 11a Ngõ 282 Nguyễn Huy Tưởng",1);
    Customer* sp2 = new Customer(2,"aaaaa","1997-08-13",0,"0868563617","số 11a Ngõ 282 Nguyễn Huy Tưởng",1);

    qlbh.addCustomer(sp1);
    qlbh.addCustomer(sp2);

    qlbh.displayListCustomers();

    delete sp2;

	qlbh.displayListCustomers();

    return 0;
}