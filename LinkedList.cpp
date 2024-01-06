#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Pendefinisan fungsi gotoxy()
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

// Pendefinian Fungsi Gotoxy()
class Linked_List_Stack
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *top;
    node *entry;
    node *print;
    node *bottom;
    node *last_entry;
    node *second_last_entry;

public:
    Linked_List_Stack();
    void pop();
    void push();
    void print_list();
    void show_working();
};

Linked_List_Stack::Linked_List_Stack()
{
    top = NULL;
    bottom = NULL;
}

// push()
void Linked_List_Stack::push()
{
    int num;

    cout << "\n\n\n\n\n\t Masukkan angka pada stack: ";
    cin >> num;

    entry = new node;

    if (bottom == NULL)
    {
        entry->data = num;
        entry->next = NULL;
        bottom = entry;
        top = entry;
    }
    else
    {
        entry->data = num;
        entry->next = NULL;
        top->next = entry;
        top = entry;
    }

    cout << "\n\n\t *** " << num << " berhasil masuk dalam stack." << endl;
    cout << "\n\n\n\t\t Press any key to return to menu.";

    getch();
}

// pop()
void Linked_List_Stack::pop()
{
    if (bottom == NULL)
        cout << "\n\n\n\t *** Error : Stack is empty.\n"
             << endl;
    else
    {
        for (last_entry = bottom; last_entry->next != NULL;
             last_entry = last_entry->next)
            second_last_entry = last_entry;

        if (top == bottom)
            bottom = NULL;

        int popped_element = top->data;

        delete top;

        top = second_last_entry;
        top->next = NULL;

        cout << "\n\n\n\t *** " << popped_element << " sudah diambil dari stack." << endl;
    }
    cout << "\n\n\n\t\t Press any key to return to menu.";
    getch();
}

// print_list()
void Linked_List_Stack::print_list()
{
    print = bottom;

    if (print != NULL)
        cout << "\n\n\n\n\n\t *** Angka-angka yang ada di stack adalah: \n"
             << endl;
    else
        cout << "\n\n\n\n\n\t *** Tidak ada data yang bisa ditampilkan." << endl;

    while (print != NULL)
    {
        cout << "\t " << print->data << endl;
        print = print->next;
    }
    cout << "\n\n\n\t\t Press any key to return to menu.";
    getch();
}

// show_working
void Linked_List_Stack::show_working()
{
    char key = 0;
    do
    {
        system("cls");
        gotoxy(5, 5);
        cout << "********** Implementation of Linked List as a Stack **********" << endl;
        gotoxy(10, 8);
        cout << "Pilih salah satu menu :" << endl;

        gotoxy(15, 10);
        cout << "- Press 'P' to Masukkan data" << endl;

        gotoxy(15, 12);
        cout << "- Press 'O' to Mengambil data" << endl;

        gotoxy(15, 14);
        cout << "- Press 'S' to Menampilkan data" << endl;

        gotoxy(15, 16);
        cout << "- Press 'E' to Exit" << endl;

    input:
        gotoxy(10, 20);
        cout << "                     ";

        gotoxy(10, 18);
        cout << "Masukkan Pilihan : ";

        key = getche();
        if (int(key) == 27 || key == 'E')
            break;
        else if (key == 'p' || key == 'P')
            push();
        else if (key == 'o' || key == 'O')
            pop();
        else if (key == 's' || key == 'S')
            print_list();
        else
            goto input;
    } while (1);
}

// main()
int main()
{
    Linked_List_Stack obj;
    obj.show_working();
    return 0;
}

