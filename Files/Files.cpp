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
   cout << "Введіть кількість студентів: ";  
   int n;  
   cin >> n;  
   cin.ignore();  

   Student* students = new Student[n];  

   for (int i = 0; i < n; ++i) {  
       cout << "Студент " << i + 1 << ":\n";  
       cout << "Ім'я: ";  
       cin.getline(students[i].name, 50);  
       cout << "Вік: ";  
       cin >> students[i].age;  
       cout << "Середній бал: ";  
       cin >> students[i].grade;  
       cin.ignore();  
   }  

   FILE* file = nullptr;  
   errno_t err = fopen_s(&file, "students.dat", "wb"); // Исправлено использование fopen_s  
   if (err != 0 || !file) {  
       cout << "Помилка відкриття файлу!\n";  
       delete[] students;  
       return 1;  
   }  

   fwrite(&n, sizeof(int), 1, file);  
   fwrite(students, sizeof(Student), n, file);  
   fclose(file);  

   cout << "Дані записано у файл students.dat\n";  

   delete[] students;  
   return 0;  
}