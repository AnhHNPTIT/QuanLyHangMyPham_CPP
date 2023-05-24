#include <iostream>
#include <string.h>
#include <iomanip>
#include "ListCustomers.cpp"
#include "ListStaffs.cpp"

using namespace std;

class Menu
{
	private:
		ListCustomers listCustomers;
		ListStaffs listStaffs;

    public:
		void manageStore()
		{
			
			int choose;
			do {
				cout << "\n ====================== Quản lý cửa hàng =====================" << endl;
				cout << " 1- Quản lý khách hàng" << endl;
				cout << " 2- Quản lý nhân viên" << endl;
				cout << " 3- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							manageCustomer();
        	    			break;
						}
					case 2: {
							manageStaff();
							break;
						}                  				
					case 3: {
                            exit(1);
						}	
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 3);
		}

        void manageCustomer()
		{
			
			int choose;
			do {
				cout << "\n ====================== Quản lý khách hàng =====================" << endl;
				cout << " 1- Nhập in danh sách khách hàng. Đọc và lưu file" << endl;
				cout << " 2- Thêm, sửa, xóa khách hàng" << endl;
				cout << " 3- Tìm kiếm khách hàng" << endl;
				cout << " 4- Sắp xếp khách hàng" << endl;
				cout << " 5- Các yêu cầu tìm phần tử lớn nhất, nhỏ nhất" << endl;
				cout << " 6- Các yêu cầu tính tổng, trung bình, đếm" << endl;
				cout << " 7- Các yêu cầu thống kê theo điều kiện" << endl;
				cout << " 8- Quay lại trang quản lý" << endl;
				cout << " 9- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Nhập danh sách khách hàng
							int num;
							cout << "Nhập số lượng khách hàng: ";
							cin >> num;
							listCustomers.enterListCustomers(num);

							// Lưu danh sách khách hàng vào file
							listCustomers.saveListCustomers();

							// Xóa danh sách khách hàng
							listCustomers.~ListCustomers();

							// Đọc danh sách khách hàng từ file
							listCustomers.readFileCustomers();

							// In danh sách khách hàng sau khi đọc từ file
							listCustomers.displayListCustomers();
        	    			break;
						}
					case 2: {
							manageCustomer2();
							break;
						}                  				
					case 3: {
							cin.ignore();
							// Tìm kiếm khách hàng theo tên
							string name;
							cout << "Nhập tên khách hàng cần tìm: ";
							getline(cin, name);
							listCustomers.searchCustomer(name);
					    	break;
						}					
                    case 4: {
							manageCustomer4();
							break;
						}
                    case 5: {
							manageCustomer5();
                            break;
                        }
                    case 6: {
							manageCustomer6();
                            break;
                        }
                    case 7: {
							manageCustomer7();
                            break;
                        }
					case 8: {
					    	manageStore();
							break;
						}	
					case 9: {
					    	exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 8);
		}

		void manageCustomer2()
		{
			
			int choose;
			do {
				cout << "\n ====== Thêm, sửa, xóa khách hàng ======" << endl;
				cout << " 1- Thêm khách hàng" << endl;
				cout << " 2- Sửa thông tin khách hàng" << endl;
				cout << " 3- Xóa khách hàng" << endl;
				cout << " 4- Quay lại trang quản lý khách hàng" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Thêm khách hàng
							cout << "Nhập thông tin khách hàng cần thêm: " << endl;
							Customer* customer = new Customer();
							customer->enterInfo();
							listCustomers.addCustomer(customer);

							// Lưu danh sách khách hàng vào file
							listCustomers.saveListCustomers();

							// Hiển thị danh sách sau khi thêm
							cout << "Danh sách khách hàng sau khi thêm: " << endl;
							listCustomers.displayListCustomers();
        	    			break;
						}
					case 2: {
							// Cập nhật khách hàng
							cout << "Nhập thông tin khách hàng cần cập nhật: " << endl;
							Customer* customer = new Customer();
							customer->enterInfo();
							listCustomers.updateCustomer(customer);

							// Lưu danh sách khách hàng vào file
							listCustomers.saveListCustomers();

							// Hiển thị danh sách sau khi cập nhật
							cout << "Danh sách khách hàng sau khi cập nhật: " << endl;
							listCustomers.displayListCustomers();
							break;
						}                  				
					case 3: {
							// Xóa khách hàng
							int id;
							cout << "Nhập mã khách hàng cần xóa: ";
							cin >> id;
							listCustomers.deleteCustomer(id);

							// Lưu danh sách khách hàng vào file
							listCustomers.saveListCustomers();

							// Hiển thị danh sách sau khi xóa
							cout << "Danh sách khách hàng sau khi xóa: " << endl;
							listCustomers.displayListCustomers();
					    	break;
						}					
                    case 4: {
							manageCustomer();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}

		void manageCustomer4()
		{
			int choose;
			do {
				cout << "\n ====== Sắp xếp khách hàng ======" << endl;
				cout << " 1- Theo mã khách hàng tăng dần" << endl;
				cout << " 2- Theo tên khách hàng giảm dần" << endl;
				cout << " 3- Quay lại trang quản lý khách hàng" << endl;
				cout << " 4- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Sắp xếp danh sách khách hàng theo mã khách hàng tăng dần
							listCustomers.sortListCustomersByIdASC();

							// Hiển thị danh sách sau khi sắp xếp
							cout << "Danh sách khách hàng có mã khách hàng tăng dần: " << endl;
							listCustomers.displayListCustomers();
        	    			break;
						}
					case 2: {
							// Sắp xếp danh sách khách hàng theo tên khách hàng giảm dần
							listCustomers.sortListCustomersByNameDESC();

							// Hiển thị danh sách sau khi sắp xếp
							cout << "Danh sách khách hàng có tên khách hàng giảm dần: " << endl;
							listCustomers.displayListCustomers();
							break;
						}                  						
                    case 3: {
							manageCustomer();
							break;
						}
					case 4: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 4);
		}

		void manageCustomer5()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu tìm phần tử lớn nhất, nhỏ nhất ======" << endl;
				cout << " 1- Tìm khách hàng có mã khách hàng lớn nhất" << endl;
				cout << " 2- Tìm khách hàng có mã khách hàng nhỏ nhất" << endl;
				cout << " 3- Quay lại trang quản lý khách hàng" << endl;
				cout << " 4- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Tìm khách hàng có mã khách hàng lớn nhất
							cout << "Thông tin khách hàng có mã khách hàng lớn nhất: " << endl;
							listCustomers.findCustomerWithIdMax()->displayInfo();
        	    			break;
						}
					case 2: {
							// Tìm khách hàng có mã khách hàng nhỏ nhất
							cout << "Thông tin khách hàng có mã khách hàng nhỏ nhất: " << endl;
							listCustomers.findCustomerWithIdMin()->displayInfo();
							break;
						}                  						
                    case 3: {
							manageCustomer();
							break;
						}
					case 4: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 4);
		}

		void manageCustomer6()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu tính tổng, trung bình, đếm ======" << endl;
				cout << " 1- Đếm số khách hàng hiện có" << endl;
				cout << " 2- Tính độ tuổi trung bình của khách hàng" << endl;
				cout << " 3- Tính tỉ lệ số khách hàng nữ trong hệ thống" << endl;
				cout << " 4- Quay lại trang quản lý khách hàng" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Đếm số khách hàng hiện có
							cout << "Số lượng khách hàng hiện có: " << listCustomers.countCustomers() << endl;
        	    			break;
						}
					case 2: {
							// Tính độ tuổi trung bình của khách hàng
							cout << "Độ tuổi trung bình của khách hàng: " << listCustomers.calAvgAge() << endl;
							break;
						}                  				
					case 3: {
							// Tính tỉ lệ số khách hàng nữ trong hệ thống
							cout << "Tỉ lệ số khách hàng nữ trong hệ thống: " << listCustomers.calRatioWomen() << " %" << endl;
					    	break;
						}					
                    case 4: {
							manageCustomer();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}

		void manageCustomer7()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu thống kê theo điều kiện ======" << endl;
				cout << " 1- Thống kê khách hàng đang bị chặn" << endl;
				cout << " 2- Thống kê khách hàng có độ tuổi từ 18 - 30" << endl;
				cout << " 3- Thống kê khách hàng có giới tính là nữ" << endl;
				cout << " 4- Quay lại trang quản lý khách hàng" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Thống kê khách hàng đang bị chặn
							cout << "Danh sách khách hàng đang bị chặn: " << endl;
							listCustomers.statsBlockedCustomer();
        	    			break;
						}
					case 2: {
							// Thống kê khách hàng có độ tuổi từ 18 - 30
							cout << "Danh sách khách hàng có độ tuổi từ 18 - 30: " << endl;
							listCustomers.statsCustomersByAge();
							break;
						}                  				
					case 3: {
							// Thống kê khách hàng có giới tính là nữ
							cout << "Danh sách khách hàng có giới tính là nữ: " << endl;
							listCustomers.statsWomen();
					    	break;
						}					
                    case 4: {
							manageCustomer();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}

		void manageStaff()
		{
			
			int choose;
			do {
				cout << "\n ====================== Quản lý nhân viên =====================" << endl;
				cout << " 1- Nhập in danh sách nhân viên. Đọc và lưu file" << endl;
				cout << " 2- Thêm, sửa, xóa nhân viên" << endl;
				cout << " 3- Tìm kiếm nhân viên" << endl;
				cout << " 4- Sắp xếp nhân viên" << endl;
				cout << " 5- Các yêu cầu tìm phần tử lớn nhất, nhỏ nhất" << endl;
				cout << " 6- Các yêu cầu tính tổng, trung bình, đếm" << endl;
				cout << " 7- Các yêu cầu thống kê theo điều kiện" << endl;
				cout << " 8- Quay lại trang quản lý" << endl;
				cout << " 9- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Nhập danh sách nhân viên
							int num;
							cout << "Nhập số lượng nhân viên: ";
							cin >> num;
							listStaffs.enterListStaffs(num);

							// Lưu danh sách nhân viên vào file
							listStaffs.saveListStaffs();

							// Xóa danh sách nhân viên
							listStaffs.~ListStaffs();

							// Đọc danh sách nhân viên từ file
							listStaffs.readFileStaffs();

							// In danh sách nhân viên sau khi đọc từ file
							listStaffs.displayListStaffs();
        	    			break;
						}
					case 2: {
							manageStaff2();
							break;
						}                  				
					case 3: {
							cin.ignore();
							// Tìm kiếm nhân viên theo tên
							string name;
							cout << "Nhập tên nhân viên cần tìm: ";
							getline(cin, name);
							listStaffs.searchStaff(name);
					    	break;
						}					
                    case 4: {
							manageStaff4();
							break;
						}
                    case 5: {
							manageStaff5();
                            break;
                        }
                    case 6: {
							manageStaff6();
                            break;
                        }
                    case 7: {
							manageStaff7();
                            break;
                        }
					case 8: {
					    	manageStore();
							break;
						}	
					case 9: {
					    	exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 8);
		}

		void manageStaff2()
		{
			
			int choose;
			do {
				cout << "\n ====== Thêm, sửa, xóa nhân viên ======" << endl;
				cout << " 1- Thêm nhân viên" << endl;
				cout << " 2- Sửa thông tin nhân viên" << endl;
				cout << " 3- Xóa nhân viên" << endl;
				cout << " 4- Quay lại trang quản lý nhân viên" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Thêm nhân viên
							cout << "Nhập thông tin nhân viên cần thêm: " << endl;
							Staff* customer = new Staff();
							customer->enterInfo();
							listStaffs.addStaff(customer);

							// Lưu danh sách nhân viên vào file
							listStaffs.saveListStaffs();

							// Hiển thị danh sách sau khi thêm
							cout << "Danh sách nhân viên sau khi thêm: " << endl;
							listStaffs.displayListStaffs();
        	    			break;
						}
					case 2: {
							// Cập nhật nhân viên
							cout << "Nhập thông tin nhân viên cần cập nhật: " << endl;
							Staff* customer = new Staff();
							customer->enterInfo();
							listStaffs.updateStaff(customer);

							// Lưu danh sách nhân viên vào file
							listStaffs.saveListStaffs();

							// Hiển thị danh sách sau khi cập nhật
							cout << "Danh sách nhân viên sau khi cập nhật: " << endl;
							listStaffs.displayListStaffs();
							break;
						}                  				
					case 3: {
							// Xóa nhân viên
							int id;
							cout << "Nhập mã nhân viên cần xóa: ";
							cin >> id;
							listStaffs.deleteStaff(id);

							// Lưu danh sách nhân viên vào file
							listStaffs.saveListStaffs();

							// Hiển thị danh sách sau khi xóa
							cout << "Danh sách nhân viên sau khi xóa: " << endl;
							listStaffs.displayListStaffs();
					    	break;
						}					
                    case 4: {
							manageStaff();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}

		void manageStaff4()
		{
			int choose;
			do {
				cout << "\n ====== Sắp xếp nhân viên ======" << endl;
				cout << " 1- Theo mã nhân viên tăng dần" << endl;
				cout << " 2- Theo tên nhân viên giảm dần" << endl;
				cout << " 3- Quay lại trang quản lý nhân viên" << endl;
				cout << " 4- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Sắp xếp danh sách nhân viên theo mã nhân viên tăng dần
							listStaffs.sortListStaffsByIdASC();

							// Hiển thị danh sách sau khi sắp xếp
							cout << "Danh sách nhân viên có mã nhân viên tăng dần: " << endl;
							listStaffs.displayListStaffs();
        	    			break;
						}
					case 2: {
							// Sắp xếp danh sách nhân viên theo tên nhân viên giảm dần
							listStaffs.sortListStaffsByNameDESC();

							// Hiển thị danh sách sau khi sắp xếp
							cout << "Danh sách nhân viên có tên nhân viên giảm dần: " << endl;
							listStaffs.displayListStaffs();
							break;
						}                  						
                    case 3: {
							manageStaff();
							break;
						}
					case 4: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 4);
		}

		void manageStaff5()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu tìm phần tử lớn nhất, nhỏ nhất ======" << endl;
				cout << " 1- Tìm nhân viên già nhất" << endl;
				cout << " 2- Tìm nhân viên trẻ nhất" << endl;
				cout << " 3- Quay lại trang quản lý nhân viên" << endl;
				cout << " 4- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Tìm nhân viên già nhất
							cout << "Thông tin nhân viên già nhất: " << endl;
							listStaffs.findOldestStaff()->displayInfo();
        	    			break;
						}
					case 2: {
							// ìm nhân viên trẻ nhất
							cout << "Thông tin nhân viên trẻ nhất: " << endl;
							listStaffs.findYoungestStaff()->displayInfo();
							break;
						}                  						
                    case 3: {
							manageStaff();
							break;
						}
					case 4: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 4);
		}

		void manageStaff6()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu tính tổng, trung bình, đếm ======" << endl;
				cout << " 1- Đếm số nhân viên hiện có" << endl;
				cout << " 2- Tính độ tuổi trung bình của nhân viên" << endl;
				cout << " 3- Tính tỉ lệ số nhân viên nữ trong hệ thống" << endl;
				cout << " 4- Quay lại trang quản lý nhân viên" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Đếm số nhân viên hiện có
							cout << "Số lượng nhân viên hiện có: " << listStaffs.countStaffs() << endl;
        	    			break;
						}
					case 2: {
							// Tính độ tuổi trung bình của nhân viên
							cout << "Độ tuổi trung bình của nhân viên: " << listStaffs.calAvgAge() << endl;
							break;
						}                  				
					case 3: {
							// Tính tỉ lệ số nhân viên nữ trong hệ thống
							cout << "Tỉ lệ số nhân viên nữ trong hệ thống: " << listStaffs.calRatioWomen() << " %" << endl;
					    	break;
						}					
                    case 4: {
							manageStaff();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}

		void manageStaff7()
		{
			int choose;
			do {
				cout << "\n ====== Các yêu cầu thống kê theo điều kiện ======" << endl;
				cout << " 1- Thống kê tất cả nhân viên đang bị chặn" << endl;
				cout << " 2- Thống kê quản lý đang hoạt động" << endl;
				cout << " 3- Thống kê nhân viên đang hoạt động" << endl;
				cout << " 4- Quay lại trang quản lý nhân viên" << endl;
				cout << " 5- Thoát khỏi hệ thống" << endl;
				cout << " ===============================================================" << endl;
        	    cout << "Nhập lựa chọn: "; cin >> choose;

        	    switch (choose) {
        	    	case 1: {
							// Thống kê tất cả nhân viên đang bị chặn
							cout << "Danh sách nhân viên đang bị chặn: " << endl;
							listStaffs.statsBlockedStaff();
        	    			break;
						}
					case 2: {
							// Thống kê nhân viên quản lý đang hoạt động
							cout << "Danh sách nhân viên quản lý đang hoạt động: " << endl;
							listStaffs.statsActivedManagers();
							break;
						}                  				
					case 3: {
							// Thống kê nhân viên đang hoạt động
							cout << "Danh sách nhân viên đang hoạt động: " << endl;
							listStaffs.statsActivedStaffs();
					    	break;
						}					
                    case 4: {
							manageStaff();
							break;
						}
					case 5: {
							exit(1);
						}
                    default: {
                            cout << "Lựa chọn không chính xác. Vui lòng chọn lại" << endl;
                        }
				}
			} while (choose != 5);
		}
};