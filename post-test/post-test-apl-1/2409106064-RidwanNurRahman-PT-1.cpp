#include <iostream>
using namespace std;

int main() {
    int kesempatan = 3;
    double saldo = 10000;
 
    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        int pin;
        cin >> pin;

        if (pin != 1064) {
            kesempatan -= 1;
            cout << "PIN salah, Anda memiliki " << kesempatan << " kesempatan lagi." << endl;
        } else {
            cout << "Berhasil login!" << endl;
            break;
        }

        if (kesempatan == 0) {
            cout << "Kesempatan login telah habis. Program berhenti." << endl;
            return 0;
        }
    }

    while (true) {
        cout << "\n====== MENU ATM ======" << endl;
        cout << "1. Setor Tunai" << endl;
        cout << "2. Cek Saldo" << endl;
        cout << "3. Tarik Tunai" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            double setor;
            cout << "Masukkan jumlah uang yang ingin disetor: ";
            cin >> setor;
            if (setor > 0) {
                saldo += setor;
                cout << "Setoran berhasil! Saldo Anda sekarang: " << saldo << endl;
            } else {
                cout << "Jumlah tidak valid!" << endl;
            }
        } else if (pilihan == 2) {
            cout << "Saldo Anda saat ini: " << saldo << endl;
        } else if (pilihan == 3) {
            double tarik;
            cout << "Masukkan jumlah uang yang ingin ditarik: ";
            cin >> tarik;
            if (tarik > 0 && tarik <= saldo) {
                saldo -= tarik;
                cout << "Penarikan berhasil! Saldo Anda sekarang: " << saldo << endl;
            } else {
                cout << "Jumlah tidak valid atau saldo tidak mencukupi!" << endl;
            }
        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan ATM." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
