#include <iostream>  
#include <cstdio>
using namespace std;  

struct Student {  
   char name[50];  
   int age;  
   float grade;  
};  

int main() { 
    setlocale(LC_ALL, "");
   cout << "������ ������� ��������: ";  
   int n;  
   cin >> n;  
   cin.ignore();  

   Student* students = new Student[n];  

   for (int i = 0; i < n; ++i) {  
       cout << "������� " << i + 1 << ":\n";  
       cout << "��'�: ";  
       cin.getline(students[i].name, 50);  
       cout << "³�: ";  
       cin >> students[i].age;  
       cout << "������� ���: ";  
       cin >> students[i].grade;  
       cin.ignore();  
   }  

   FILE* file = nullptr;  
   errno_t err = fopen_s(&file, "students.dat", "wb"); // ���������� ������������� fopen_s  
   if (err != 0 || !file) {  
       cout << "������� �������� �����!\n";  
       delete[] students;  
       return 1;  
   }  

   fwrite(&n, sizeof(int), 1, file);  
   fwrite(students, sizeof(Student), n, file);  
   fclose(file);  

   cout << "��� �������� � ���� students.dat\n";  

   delete[] students;  
   return 0;  
}