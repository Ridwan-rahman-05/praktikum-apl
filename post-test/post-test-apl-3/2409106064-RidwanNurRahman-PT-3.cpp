#include <iostream>
#include <string>
using namespace std;

struct DataMusik {
    string judul;
    string genre;
    string artis;
};


struct Playlist {
    string nama;
    DataMusik musik[10];
    int jumlahMusik = 0; 
};

int main() {
    int kesempatan = 3;
    string username;
    string password;

    int max_playlist = 10;
    Playlist playlist[10];
    int totalPlaylist = 0;

    while (kesempatan > 0) {
        cout << "Masukkan Username: " << endl;
        getline(cin, username);
        cout << "Masukkan Password: " << endl;
        cin >> password;
        cin.ignore();

        if (username == "Ridwan Nur Rahman" && password == "2409106064") {
            while (true) {
                cout << "\n====== Menu Manajemen Playlist Musik ======" << endl;
                cout << "1. Buat playlist" << endl;
                cout << "2. Lihat playlist" << endl;
                cout << "3. Update playlist" << endl;
                cout << "4. Hapus playlist" << endl;
                cout << "0. Keluar program" << endl;
                cout << "Masukkan pilihan: ";
                int pilihan;
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    if (totalPlaylist < max_playlist) {
                        cout << "Nama Playlist: " << endl;
                        getline(cin, playlist[totalPlaylist].nama);

                        cout << "Musik: " << endl;
                        getline(cin, playlist[totalPlaylist].musik[0].judul);
                        cout << "Genre: " << endl;
                        getline(cin, playlist[totalPlaylist].musik[0].genre);
                        cout << "Artis: " << endl;
                        getline(cin, playlist[totalPlaylist].musik[0].artis);

                        playlist[totalPlaylist].jumlahMusik = 1;
                        totalPlaylist++;

                        cout << "Playlist berhasil dibuat!\n" << endl;
                    } else {
                        cout << "Playlist sudah penuh! Hapus playlist untuk menambah yang baru.\n" << endl;
                    }
                } 

                else if (pilihan == 2) {
                    if (totalPlaylist == 0) {
                        cout << "Belum ada playlist yang dibuat.\n" << endl;
                    } else {
                        for (int i = 0; i < totalPlaylist; i++) {
                            cout << i + 1 << ". " << playlist[i].nama << "\n";
                            for (int j = 0; j < playlist[i].jumlahMusik; j++) {
                                cout << "   - " << playlist[i].musik[j].judul << " | " 
                                     << playlist[i].musik[j].genre << " | " 
                                     << playlist[i].musik[j].artis << "\n";
                            }
                        }
                    }
                } 

                else if (pilihan == 3) { 
                    if (totalPlaylist == 0) {
                        cout << "Belum ada playlist yang bisa diubah.\n" << endl;
                        continue;
                    }

                    for (int i = 0; i < totalPlaylist; i++) {
                        cout << i + 1 << ". " << playlist[i].nama << "\n";
                    }

                    cout << "Pilih Playlist: " << endl;
                    int pilih;
                    cin >> pilih;
                    cin.ignore();

                    if (pilih > 0 && pilih <= totalPlaylist) {
                        cout << "1. Tambah Musik\n" << endl;
                        cout << "2. Ubah Playlist\n" << endl;
                        cout << "Masukkan pilihan: " << endl;
                        int opsi;
                        cin >> opsi;
                        cin.ignore();

                        if (opsi == 1) {
                            if (playlist[pilih - 1].jumlahMusik < 10) {
                                int idx = playlist[pilih - 1].jumlahMusik;
                                cout << "Musik: " << endl;
                                getline(cin, playlist[pilih - 1].musik[idx].judul);
                                cout << "Genre: " << endl;
                                getline(cin, playlist[pilih - 1].musik[idx].genre);
                                cout << "Artis: " << endl;
                                getline(cin, playlist[pilih - 1].musik[idx].artis);

                                playlist[pilih - 1].jumlahMusik++;
                                cout << "Musik berhasil ditambahkan!\n" << endl;
                            } else {
                                cout << "Playlist ini sudah penuh!\n" << endl;
                            }
                        } 

                        else if (opsi == 2) { 
                            cout << "1. Ganti Nama Playlist\n" << endl;
                            cout << "2. Ganti Musik\n" << endl;
                            cout << "Masukkan pilihan: " << endl;
                            int opsiubah;
                            cin >> opsiubah;
                            cin.ignore();

                            if (opsiubah == 1) {
                                cout << "Masukkan nama Playlist baru: " << endl;
                                getline(cin, playlist[pilih - 1].nama);
                                cout << "Nama Playlist berhasil diubah!\n" << endl;
                            } 
                            
                            else if (opsiubah == 2) {
                                for (int j = 0; j < playlist[pilih - 1].jumlahMusik; j++) {
                                    cout << j + 1 << ". " << playlist[pilih - 1].musik[j].judul << "\n";
                                }

                                cout << "Pilih musik yang ingin diubah: " << endl;
                                int pilihMusik;
                                cin >> pilihMusik;
                                cin.ignore();

                                if (pilihMusik > 0 && pilihMusik <= playlist[pilih - 1].jumlahMusik) {
                                    cout << "Masukkan Nama Lagu Baru: " << endl;
                                    getline(cin, playlist[pilih - 1].musik[pilihMusik - 1].judul);
                                    cout << "Masukkan Genre Baru: " << endl;
                                    getline(cin, playlist[pilih - 1].musik[pilihMusik - 1].genre);
                                    cout << "Masukkan Artis Baru: " << endl;
                                    getline(cin, playlist[pilih - 1].musik[pilihMusik - 1].artis);

                                    cout << "Lagu berhasil diperbarui!\n" << endl;
                                } else {
                                    cout << "Pilihan tidak valid!\n" << endl;
                                }
                            } else {
                                cout << "Pilihan tidak valid!\n" << endl;
                            }
                        }
                    } else {
                        cout << "Playlist tidak ditemukan!\n" << endl;
                    }
                } 

                else if (pilihan == 4) { 
                    if (totalPlaylist == 0) {
                        cout << "Belum ada playlist yang bisa dihapus.\n" << endl;
                        continue;
                    }

                    for (int i = 0; i < totalPlaylist; i++) {
                        cout << i + 1 << ". " << playlist[i].nama << "\n";
                    }

                    cout << "Pilih Playlist: " << endl;
                    int pilih;
                    cin >> pilih;
                    cin.ignore();

                    if (pilih > 0 && pilih <= totalPlaylist) {
                        cout << "1. Hapus Playlist\n" << endl;
                        cout << "2. Hapus Musik dalam Playlist\n" << endl;
                        cout << "Masukkan pilihan: " << endl;
                        int opsi;
                        cin >> opsi;
                        cin.ignore();

                        if (opsi == 1) { 
                            for (int i = pilih - 1; i < totalPlaylist - 1; i++) {
                                playlist[i] = playlist[i + 1];
                            }
                            totalPlaylist--;
                            cout << "Playlist berhasil dihapus!\n" << endl;
                        } 

                        else if (opsi == 2) {
                            for (int j = 0; j < playlist[pilih - 1].jumlahMusik; j++) {
                                cout << j + 1 << ". " << playlist[pilih - 1].musik[j].judul << "\n";
                            }

                            cout << "Pilih Musik yang ingin dihapus: " << endl;
                            int pilihMusik;
                            cin >> pilihMusik;
                            cin.ignore();

                            if (pilihMusik > 0 && pilihMusik <= playlist[pilih - 1].jumlahMusik) {
                                for (int j = pilihMusik - 1; j < playlist[pilih - 1].jumlahMusik - 1; j++) {
                                    playlist[pilih - 1].musik[j] = playlist[pilih - 1].musik[j + 1];
                                }
                                playlist[pilih - 1].jumlahMusik--;
                                cout << "Musik berhasil dihapus!\n" << endl;
                            } else {
                                cout << "Pilihan tidak valid!\n" << endl;
                            }
                        } else {
                            cout << "Pilihan tidak valid!\n" << endl;
                        }
                    } else {
                        cout << "Playlist tidak ditemukan!\n" << endl;
                    }
                } 

                else if (pilihan == 0) {
                    cout << "Terima kasih telah menggunakan manajemen playlist!\n" << endl;
                    break;
                } else {
                    cout << "Pilihan tidak valid!\n" << endl;
                }
            }
            break;
        } else {
            kesempatan--;
            cout << "Username atau Password salah. Kesempatan login tersisa: " << kesempatan << endl;
        }
    }
    return 0;
}