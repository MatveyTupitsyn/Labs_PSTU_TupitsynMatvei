#include <iostream>
#include <clocale>
#include <random>
#include <string>
#include <fstream>
using namespace std;

struct point{
    string key;
    point* next;
    point* prev;
};

string randomString(int low, int high)
{
    static mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(low, high);
    uniform_int_distribution<int> distalp(0, 25);          // индексы 0..25
    static const string alphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";

    int len = dist(gen);
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i)
        s += alphabet[distalp(gen)];
    return s;
}

point* make_point(int n)
{
    point *first = nullptr, *p;

    for (int i=n;i>0;i--)
    {
        p=new point;
        p->key = randomString(2,15);
        p->next = first;
        p->prev = nullptr;
        if (first)
            first->prev = p;
        first=p;
    }
    return first;
}

void print_list(point *first)
{
    point *p = first;
    if (!first){
        cout << "Список пуст!" << endl;
        return;
    }
    while (p){
        cout << p->key << ' ';
        p = p->next;
    }
    cout << endl;
}

point* delete_el(point *first, int index)
{
    if (!first || index < 0) 
        return first;

    point *p = first;
    while (p && index > 0) 
    { 
        p = p->next;
        --index;
    }
    if (!p) 
        return first;                        // индекс вне списка

    if (p->prev) 
        p->prev->next = p->next;
    else 
        first = p->next;                // удаляем голову

    if (p->next) 
        p->next->prev = p->prev;        // хвост — просто пропускаем

    delete p;
    return first;
}

point* add_el(point *first, int index, int k)
{
    if (!first || k <= 0 || index < 0) return first;

    point *target = first;
    while (target && index > 0) { target = target->next; --index; }
    if (!target) return first;              // индекс вне списка — ничего не вставляем

    point *head = nullptr, *tail = nullptr;
    for (int i = 0; i < k; ++i) {
        point *node = new point;
        node->key  = randomString(3, 15);
        node->prev = tail;
        node->next = nullptr;
        if (tail) tail->next = node;
        else      head = node;
        tail = node;
    }

    point *after = target->next;
    target->next  = head;
    head->prev    = target;
    tail->next    = after;
    if (after) after->prev = tail;

    return first;
}

void save_list(point *first)
{
    if (!first){
        cout << "Список пуст!" << endl;
        return;
    }
    ofstream file("list.txt",ios_base::out);
    point *p = first;
    while (p)
    {
        file << p->key << endl;
        p = p->next;
    }
    cout << "Список сохранен!" << endl;
    file.close();
}

void delete_list(point *first)
{
    while (first != nullptr)
    {
        point *p = first->next;
        delete first;
        first = p;
    }
    cout << "Список удален!!!" << endl;
}

point* recover_list(string filename)
{
    ifstream file(filename);
    if (!file) return nullptr;

    point *first = nullptr, *tail = nullptr;
    string s;
    while (file >> s) {
        point *p = new point;
        p->key  = s;
        p->next = nullptr;
        p->prev = tail;
        if (tail) tail->next = p;
        else      first = p;
        tail = p;
    }
    return first;
}

int main()
{
    setlocale(LC_ALL,".UTF8");
    int N,K,L = 0;
    string s;
    cout << "Введите длину списка: ";
    cin >> N;
    point *array = make_point(N);
    cout << "Cписок до изменений:" << endl;
    print_list(array);
    cout << "Введите значение, которое надо удалить: ";
    cin >> s;
    point *p = array;
    while (true)
    {
        if (p->key == s)
        {
            array = delete_el(array,L);
            break;
        }
        else
            p = p->next;
            
        L++;
    }
    cout << "Список после удаления элемента:" << endl;
    print_list(array);
    cout << "Введите кол-во элементов для добавления: ";
    cin >> K;
    array = add_el(array,L,K);
    cout << "Список после добавления элементов:" << endl;
    print_list(array);
    save_list(array);
    delete_list(array);
    print_list(array);
    point *arr = recover_list("list.txt");
    print_list(arr);
    return 0;
}