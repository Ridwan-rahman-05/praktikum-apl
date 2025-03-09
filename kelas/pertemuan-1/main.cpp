#include <iostream>
using namespace std;

int main() 
{
    bool malas = true;
    bool lapar = true;
    if (malas)
    {
        cout <<"saya scroll fb";
    }else if (lapar)
        cout <<"saya makan";
    else {
        cout <<"saya belajar";
    }
    string firstName; //camelCase
    string last_name; //snake_case
    string FullName; //PascalCase

    string nama;
    cout << "masukkan nama :";
    //cin >> nama;
    getline(cin, nama);
    cout << "nama saya adalah :" << nama;
    std::cout << "Hello World" << std::endl;
    std::cout << "Saya sedang belajar c++";

    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }
    return 0;
}