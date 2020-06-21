#include "ex_work.h"
#include "func.h"


const int ignor = 32767;
const int f_row = 1;


void keyboard_way() {
	int m, n;
	string outpath;
	string inpath;
	cout << "Введите количество строк: " << endl;
	m = number_check();
	cout << "Введите количество столбцов: " << endl;
	n = number_check();
	double** mat = create(m, n);
	keyboard_input(mat, m, n);
	fill_mas(mat, m, n);
	print(mat, m, n);
	cout << "Сохранить массив в файл? " << endl;
	if (save_result_q() == 1) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_in_file(inpath, outpath, mat, m, n);
	}
	system("pause");
	for (int i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	Menu();
}


void file_way() {
	int m, n;
	string outpath;
	string inpath;
	ifstream fin;
	cout << "Укажите путь к файлу: " << endl;
	cin >> inpath;
	fin.open(inpath);
	while (file_name_check(inpath)) {
		fin.close();
		cout << "Ошибка! Введен неккоректный путь к файлу! \nВведите путь к файлу: " << endl;
		cin >> inpath;
		fin.open(inpath);
	}
	if (!fin.is_open()) {
		cout << "Ошибка! Не удаётся открыть файл!" << endl;
		cin.clear();
		cin.ignore(ignor, '\n');
		Menu();
	}
	else {
		int temp_int, count = 0, i, j;
		double temp_d;
		if (file_check_size(inpath) == true) {
			cout << "Ошибка! Файл пуст!" << endl;
			cin.clear();
			cin.ignore(ignor, '\n');
			fin.close();
			Menu();
		}
		while (fin) {
			if (count < 3) {
				fin >> temp_int;
				if (fin.fail() && !fin.eof()) {
					cout << "Ошибка! Файл содержит некорректные данные. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					Menu();
				}
				count++;
			}
			else {
				fin >> temp_d;
				if (fin.fail() && !fin.eof()) {
					cout << "Ошибка! Файл содержит некорректные данные. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					Menu();
				}
			}
		}
		count = 0;
		fin.close();
		
		fin.open(inpath, ios::in);
		fin >> m;
		fin >> n;
		double** mat = create(m, n);
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
		fill_mas(mat, m, n);
		print(mat, m, n);
		cout << "Сохранить массив в файл? " << endl;
		if (save_result_q() == 1) {
			cout << "Введите путь к файлу вывода: " << endl;
			print_in_file(inpath, outpath, mat, m, n);
		}
		system("pause");
		for (i = 0; i < m; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
	Menu();
}


void random_way() {
	string outpath;
	string inpath;
	int m, n, i;
	cout << "Введите количество строк: " << endl;
	m = number_check();
	cout << "Введите количество столбцов: " << endl;
	n = number_check();
	double** mat = create(m, n);
	random_input(mat, m, n);
	fill_mas(mat, m, n);
	print(mat, m, n);
	cout << "Сохранить массив в файл? " << endl;
	if (save_result_q() == 1) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_in_file(inpath, outpath, mat, m, n);
	}
	system("pause");
	for (i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}


double** create(int m, int n) {
	double** array = new double* [m];
	for (int i = 0; i < m; i++) {
		array[i] = new double[n];
	}
	return array;
}


void keyboard_input(double **array, int m, int n) {
	for (int i = 0; i < f_row; i++) {
		for (int j = 0; j < n; j++) {
			cout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			cin >> array[i][j];				
		}
	}
}


void random_input(double** array, int m, int n) {
	int max, min;	
	cout << "Укажите минимальное возможное значение: ";
	cin >> min;
	cout << endl;
	cout << "Укажите максималльное возможное значение: ";
	cin >> max;
	for (int i = 0; i < f_row; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = min + rand() % max;		
		}		
	}
}