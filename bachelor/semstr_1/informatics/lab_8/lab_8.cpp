#include <iostream>
#include <stdio.h>
#include <clocale>
#include <limits>
using namespace std;

struct Stadium {
    char name[50];
    int year;
    int amount;
    char sports[100];
};

void Add_Stadium(Stadium &s) {
    cout << "Введите название стадиона: ";
    cin.getline(s.name, 50);

    cout << "Введите год постройки: ";
    cin >> s.year;

    cout << "Введите количество площадок: ";
    cin >> s.amount;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите виды спорта: ";
    cin.getline(s.sports, 100);
}

void print_Stadium (Stadium &s){ //функция для печати стадионов
    cout << "Название: " << s.name << '\n' 
    << "Год постройки: " << s.year << '\n'
    << "Кол-во площадок: " << s.amount << '\n'
    << "Виды спорта: " << s.sports << endl; 
}

void createFile(const char *filename, int n) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Stadium s;
    for (int i = 0; i < n; i++) {
        cout << "\nЗапись №" << i + 1 << ":" << endl;
        Add_Stadium(s);
        fwrite(&s, sizeof(Stadium), 1, f);
    }

    fclose(f);
}
void printFile(const char* filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) 
    { 
        cout << "Файл пуст или не существует." << endl; 
        return;
    }
    
    Stadium s;
    cout << "\n--- Содержимое файла ---" << endl;
    while (fread(&s, sizeof(Stadium), 1, f) == 1) {
        print_Stadium(s);
    }
    fclose(f);
}

void delete_el (const char *filename,int targetYear){ // функция для удаления ненужных элементов
    FILE *f = fopen(filename,"rb");
    FILE *temp = fopen("temp.dat","wb");
    if (!f){
        cout << "Файл пуст или его не сущетсвует!" << endl;
        return;
    }
    Stadium s;
    while (fread(&s,sizeof(Stadium),1,f)) {
        if (s.year >= targetYear)
            fwrite(&s,sizeof(Stadium),1,temp);
    }
    fclose(f);
    fclose(temp);

    remove(filename);
    rename("temp.dat",filename);
}

void Add_el (const char *filename, int index){ //функция для добавления элементов
    FILE *f = fopen(filename,"rb");
    FILE *temp = fopen("temp.dat","wb");
    if (!f){
        cout << "Файл пуст или его не существует!" << endl;
        return;
    }

    Stadium s;
    int count = 0;
    bool added = false;

    while (fread(&s,sizeof(Stadium),1,f)){
        if (count == index - 1 && !added)
        {
            for (int i = 0; i < 2; i++){
                cout << "Добавление нового элемента" << endl;
                Stadium newS;
                Add_Stadium(newS);
                fwrite(&newS,sizeof(Stadium),1,temp);
            }
            added = true;
        }
        fwrite (&s,sizeof(Stadium),1,temp);
        count++;
    }

    fclose(f);
    fclose(temp);

    remove(filename);
    rename("temp.dat",filename);
}

int main(){
    setlocale(LC_ALL,".UTF8");

    const char *filename = "stadium.dat";

    createFile(filename,3);
    printFile(filename);

    int target;
    cout << "Введите год постройки, чтобы удалить элементы старше него: ";
    cin >> target;
    delete_el(filename,target);

    int index;
    cout << "Введите индекс: ";
    cin >> index;
    Add_el(filename,index);
    printFile(filename);
    return 0;
}