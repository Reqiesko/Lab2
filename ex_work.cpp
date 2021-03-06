#include "ex_work.h"
#include "func.h"


const int ignor = 32767;
const int f_row = 1;


void keyboard_way() {
	int m, n;
	string outpath;
	string inpath;
	cout << "������� ���������� �����: " << endl;
	m = number_check();
	cout << "������� ���������� ��������: " << endl;
	n = number_check();
	double** mat = create_mat(m, n);
	keyboard_input(mat, n);	
	fill_mat(mat, m, n);
	cout << "��������� �������� ������ � ����? " << endl;
	if (save_result_q() == 1) {
		cout << "������� ���� � ����� ������: " << endl;
		print_source(inpath, mat, m, n);
	}
	print_mat(mat, m, n);
	cout << "��������� ������ � ����? " << endl;
	if (save_result_q() == 1) {
		cout << "������� ���� � ����� ������: " << endl;
		print_result_in_file(inpath, outpath, mat, m, n);
	}
	system("pause");
	for (int i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	main_menu();
}


void file_way() {
	int m, n;
	string outpath;
	string inpath;
	ifstream fin;
	cout << "������� ���� � �����: " << endl;
	cin >> inpath;
	fin.open(inpath);
	while (file_name_check(inpath)) {
		fin.close();
		cout << "������! ������ ������������ ���� � �����! \n������� ���� � �����: " << endl;
		cin >> inpath;
		fin.open(inpath);
	}
	if (!fin.is_open()) {
		cout << "������! �� ������ ������� ����!" << endl;
		cin.clear();
		cin.ignore(ignor, '\n');
		main_menu();
	}
	else {
		int temp_int, count = 0, i, j;
		double temp_d;
		if (file_check_size(inpath) == true) {
			cout << "������! ���� ����!" << endl;
			cin.clear();
			cin.ignore(ignor, '\n');
			fin.close();
			main_menu();
		}
		while (fin) {
			if (count < 3) {
				fin >> temp_int;
				if (fin.fail() && !fin.eof()) {
					cout << "������! ���� �������� ������������ ������. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					main_menu();
				}
				count++;
			}
			else {
				fin >> temp_d;
				if (fin.fail() && !fin.eof()) {
					cout << "������! ���� �������� ������������ ������. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					main_menu();
				}
			}
		}
		count = 0;
		fin.close();
		
		fin.open(inpath, ios::in);
		fin >> m;
		fin >> n;
		double** mat = create_mat(m, n);
		bool check = true;
		while (check) {
			for (i = 0; i < f_row; i++) {
				for (j = 0; j < n; j++) {
					fin >> mat[i][j];
				}
				check = false;
			}			
		}	
		cout << m << " " << n << endl;
		fill_mat(mat, m, n);
		print_mat(mat, m, n);
		cout << "��������� ������ � ����? " << endl;
		if (save_result_q() == 1) {
			cout << "������� ���� � ����� ������: " << endl;
			print_result_in_file(inpath, outpath, mat, m, n);
		}
		system("pause");
		for (i = 0; i < m; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
	main_menu();
}


void random_way() {
	string outpath;
	string inpath;
	int m, n, i;
	cout << "������� ���������� �����: " << endl;
	m = number_check();
	cout << "������� ���������� ��������: " << endl;
	n = number_check();
	double** mat = create_mat(m, n);
	random_input(mat, m, n);
	cout << "��������� �������� ������ � ����? " << endl;
	if (save_result_q() == 1) {
		cout << "������� ���� � ����� ������: " << endl;
		print_source(inpath, mat, m, n);
	}
	fill_mat(mat, m, n);
	print_mat(mat, m, n);
	
	cout << "��������� ������ � ����? " << endl;
	if (save_result_q() == 1) {
		cout << "������� ���� � ����� ������: " << endl;
		print_result_in_file(inpath, outpath, mat, m, n);
	}
	system("pause");
	for (i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}





void keyboard_input(double **array, int n) {
	for (int i = 0; i < f_row; i++) {
		for (int j = 0; j < n; j++) {
			cout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			array[i][j] = numb_check();			
		}
	}
}


void random_input(double** array, int m, int n) {
	int max, min;	
	cout << "������� ����������� ��������� ��������: ";
	min = number_check();
	cout << endl;
	cout << "������� ������������� ��������� ��������: ";
	max = number_check();
	for (int i = 0; i < f_row; i++) {
		for (int j = 0; j < n; j++) {		
			array[i][j] = min + rand() % max;
			cout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}