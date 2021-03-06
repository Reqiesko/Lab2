#include "ui.h"
#include "func.h"
#include "ex_work.h"
#include "test.h"

const int ignor = 32767;

void greeting() {
	cout << "� ������������ ������������� ����������� M x N �������." << endl;
	cout << "� ������� ����������� ������ ������ ������." << endl;
	cout << "� ���������� ������ ������ ����������� �� ���������� �������:" << endl;
	cout << "U(i,j) = (U(i,j-1) + U(i+1,j-1)) / 2;" << endl;
	cout << "��������: U(i,j) = |U(i,j-1) + U(i+1,j-1)| / 2" << endl;
	cout << endl;
	cout << "�����: ����������� �������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �2" << endl;
	cout << "������� 12" << endl;
	cout << endl;
}

void main_menu() {
	fill_matrix floor = keyboard;
	int var = floor;
	cout << endl;
	while (true) {
		cout << "Menu" << endl;
		cout << "�������� �������: " << endl;
		cout << "1. ��������� ������ � ����������. " << endl;
		cout << "2. ��������� ������ ���������� �� �����. " << endl;
		cout << "3. ��������� ������ ���������� ����������. " << endl;
		cout << "4. ��������� �����. " << endl;
		cout << "5. ����� �� ���������. " << endl;
		cout << endl;
		cin >> var;
		
		if (!error_check()) {
			continue;
		}
		cin.ignore(32767, '\n');
		switch (var) {
			case keyboard: {
				keyboard_way();
				break;
			}
			case from_file: {
				file_way();
				break;
			}
			case random: {
				random_way();
				break;
			}
			case test: {
				module_tests();
				main_menu();
			}
			case out: {
				cout << "��������� ���������." << endl;
				exit(0);
				break;
			}
			default: {
				cout << "���������� ������� ����� �� ���� ���������. " << endl;
			}
		}
		cin.clear();
	}
}

int save_result_q() {
	saveinfile floor = yes;
	int var = floor;
	int way = 0;
	bool sw = true;
	while (sw) {
		cout << "1. �� " << endl;
		cout << "2. ��� " << endl;
		cin >> var;
		if (!error_check()) {
			continue;
		}
		cin.ignore(ignor, '\n');
		switch (var) {
			case yes: {
				way = 1;
				sw = false;
				break;
			}
			case no: {
				sw = false;
				break;
			}
			default: {
				cout << "���������� ������� ����� 1 ��� 2. " << endl;
			}
		}
		cin.clear();
	}
	return way;
}

int wtdw_file(string& pFile) {
	bool d = true;
	ifstream foutcheck;
	int del;

	while (d) {
		cout << "���� �� ����! �������� �������." << endl;
		cout << "1. ������������." << endl;
		cout << "2. �������� � �����." << endl;
		cout << "3. ������� ������ ����." << endl;
		cin >> del;

		if (!error_check()) {
			continue;
		}
		cin.ignore(ignor, '\n');
		switch (del) {
		case rewrite: {
			return rewrite;
		}
		case add: {
			return add;
		}
		case newfile: {
			bool trg = true;
			while (trg) {
				cout << "������� ���� � �����. " << endl;
				cin >> pFile;
				foutcheck.open(pFile, ios::in);
				while (file_name_check(pFile)) {
					foutcheck.close();
					cout << "������! ������������ ���� ��� ��� �����." << endl;
					cout << "������� ���� � �����: " << endl;
					cin >> pFile;
					foutcheck.open(pFile, ios::in);
				}
				while (!check_read_only(pFile)) {
					foutcheck.close();
					cout << "������� ���� � �����: " << endl;
					cin >> pFile;
					foutcheck.open(pFile);
				}
				if (!foutcheck.is_open()) {
					ifstream newfile(pFile);
					newfile.close();
					return rewrite;
				}
				else {
					bool check = file_check_size(pFile);
					foutcheck.close();
					if (check) {
						return 0;
					}
					else {
						return wtdw_file(pFile);
					}
				}
			}
		}
		default: {
			cout << "���������� ������� ����� 1, 2 ��� 3.  " << endl;
		}
		}
	}
}