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

// 1. Selection Sort: Nama Playlist (Descending - Z to A)
void sortPlaylistByNamaDesc(Playlist playlist[], int total) {
    for (int i = 0; i < total - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < total; j++) {
            if (playlist[j].nama > playlist[maxIdx].nama) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(playlist[i], playlist[maxIdx]);
        }
    }
}

// 2. Insertion Sort: Jumlah Musik (Ascending - sedikit ke banyak) - FITUR UTAMA
void sortPlaylistByJumlahMusik(Playlist playlist[], int total) {
    for (int i = 1; i < total; i++) {
        Playlist key = playlist[i];
        int j = i - 1;
        while (j >= 0 && playlist[j].jumlahMusik > key.jumlahMusik) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = key;
    }
}

// 3. Merge Sort: Nama Musik (Descending - Z to A)
void merge(DataMusik arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    DataMusik L[10], R[10];
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].judul > R[j].judul) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(DataMusik arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void buatPlaylist(Playlist playlist[], int &totalPlaylist, int max_playlist) {
    if (totalPlaylist < max_playlist) {
        cout << "Nama Playlist: ";
        getline(cin, playlist[totalPlaylist].nama);
        cout << "Judul Musik: ";
        getline(cin, playlist[totalPlaylist].musik[0].judul);
        cout << "Genre: ";
        getline(cin, playlist[totalPlaylist].musik[0].genre);
        cout << "Artis: ";
        getline(cin, playlist[totalPlaylist].musik[0].artis);

        playlist[totalPlaylist].jumlahMusik = 1;
        totalPlaylist++;

        sortPlaylistByNamaDesc(playlist, totalPlaylist);
        
        cout << "Playlist berhasil dibuat!\n" << endl;
    } else {
        cout << "Playlist sudah penuh!\n" << endl;
    }
}

void lihatPlaylist(Playlist playlist[], int totalPlaylist, bool sortByJumlah = false) {
    if (totalPlaylist == 0) {
        cout << "Belum ada playlist.\n" << endl;
    } else {
        if (sortByJumlah) {
            sortPlaylistByJumlahMusik(playlist, totalPlaylist);
            cout << "=== Daftar Playlist (Sort by Jumlah Lagu) ===\n";
        } else {
            sortPlaylistByNamaDesc(playlist, totalPlaylist);
            cout << "=== Daftar Playlist (Sort by Nama) ===\n";
        }
        
        for (int i = 0; i < totalPlaylist; i++) {
            mergeSort(playlist[i].musik, 0, playlist[i].jumlahMusik - 1);
            
            cout << i + 1 << ". " << playlist[i].nama << " (" << playlist[i].jumlahMusik << " lagu)\n";
            for (int j = 0; j < playlist[i].jumlahMusik; j++) {
                cout << "   - " << playlist[i].musik[j].judul << " | "
                    << playlist[i].musik[j].genre << " | "
                    << playlist[i].musik[j].artis << "\n";
            }
        }
    }
}

void tambahMusik(Playlist &pl) {
    if (pl.jumlahMusik < 10) {
        int idx = pl.jumlahMusik;
        DataMusik *lagu = &pl.musik[idx];
        cout << "Judul Musik: ";
        getline(cin, lagu->judul);
        cout << "Genre: ";
        getline(cin, lagu->genre);
        cout << "Artis: ";
        getline(cin, lagu->artis);
        pl.jumlahMusik++;
        
        mergeSort(pl.musik, 0, pl.jumlahMusik - 1);
        
        cout << "Musik berhasil ditambahkan!\n" << endl;
    } else {
        cout << "Playlist ini sudah penuh!\n" << endl;
    }
}

    void ubahNamaPlaylist(Playlist &pl, Playlist playlist[], int totalPlaylist) {
        cout << "Masukkan nama baru: ";
        getline(cin, pl.nama);
        
        sortPlaylistByNamaDesc(playlist, totalPlaylist);
        
        cout << "Nama berhasil diubah!\n" << endl;
    }

void ubahMusik(Playlist &pl) {
    for (int i = 0; i < pl.jumlahMusik; i++) {
        cout << i + 1 << ". " << pl.musik[i].judul << "\n";
    }

    int pilih;
    cout << "Pilih musik yang ingin diubah: ";
    cin >> pilih;
    cin.ignore();

    if (pilih > 0 && pilih <= pl.jumlahMusik) {
        cout << "Judul Baru: ";
        getline(cin, pl.musik[pilih - 1].judul);
        cout << "Genre Baru: ";
        getline(cin, pl.musik[pilih - 1].genre);
        cout << "Artis Baru: ";
        getline(cin, pl.musik[pilih - 1].artis);
        
        // Auto-sort musik setelah perubahan
        mergeSort(pl.musik, 0, pl.jumlahMusik - 1);
        
        cout << "Musik berhasil diperbarui!\n" << endl;
    } else {
        cout << "Pilihan tidak valid!\n" << endl;
    }
}

void hapusPlaylist(Playlist playlist[], int &totalPlaylist, int index) {
    for (int i = index; i < totalPlaylist - 1; i++) {
        playlist[i] = playlist[i + 1];
    }
    totalPlaylist--;
    
    cout << "Playlist berhasil dihapus!\n" << endl;
}

void hapusMusikDalamPlaylist(Playlist &pl) {
    for (int i = 0; i < pl.jumlahMusik; i++) {
        cout << i + 1 << ". " << pl.musik[i].judul << "\n";
    }

    int pilih;
    cout << "Pilih musik yang ingin dihapus: ";
    cin >> pilih;
    cin.ignore();

    if (pilih > 0 && pilih <= pl.jumlahMusik) {
        for (int i = pilih - 1; i < pl.jumlahMusik - 1; i++) {
            pl.musik[i] = pl.musik[i + 1];
        }
        pl.jumlahMusik--;
        
        mergeSort(pl.musik, 0, pl.jumlahMusik - 1);
        
        cout << "Musik berhasil dihapus!\n" << endl;
    } else {
        cout << "Pilihan tidak valid!\n" << endl;
    }
}

bool login(string &user, string &pass) {
    return (user == "Ridwan Nur Rahman" && pass == "2409106064");
}

int main() {
    int kesempatan = 3;
    string username, password;

    const int max_playlist = 10;
    Playlist playlist[max_playlist];
    int totalPlaylist = 0;

    while (kesempatan > 0) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        cin >> password;
        cin.ignore();

        if (login(username, password)) {
            int pilihan;
            while (true) {
                cout << "\n====== Menu Manajemen Playlist Musik ======\n";
                cout << "1. Buat playlist\n";
                cout << "2. Lihat playlist (Sort by Nama)\n";
                cout << "3. Lihat playlist (Sort by Jumlah Musik)\n"; // FITUR UTAMA
                cout << "4. Update playlist\n";
                cout << "5. Hapus playlist\n";
                cout << "0. Keluar\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    buatPlaylist(playlist, totalPlaylist, max_playlist);
                } else if (pilihan == 2) {
                    lihatPlaylist(playlist, totalPlaylist, false);
                } else if (pilihan == 3) {
                    lihatPlaylist(playlist, totalPlaylist, true); // Memanggil dengan sorting jumlah musik
                } else if (pilihan == 4) {
                    if (totalPlaylist == 0) {
                        cout << "Belum ada playlist.\n";
                        continue;
                    }

                    lihatPlaylist(playlist, totalPlaylist, false);

                    int pilih;
                    cout << "Pilih Playlist: ";
                    cin >> pilih;
                    cin.ignore();

                    if (pilih > 0 && pilih <= totalPlaylist) {
                        cout << "1. Tambah Musik\n";
                        cout << "2. Ubah Playlist\n";
                        int opsi;
                        cout << "Pilihan: ";
                        cin >> opsi;
                        cin.ignore();

                        if (opsi == 1) {
                            tambahMusik(playlist[pilih - 1]);
                        } else if (opsi == 2) {
                            cout << "1. Ubah Nama Playlist\n";
                            cout << "2. Ubah Musik\n";
                            int opsiubah;
                            cout << "Pilihan: ";
                            cin >> opsiubah;
                            cin.ignore();

                            if (opsiubah == 1) {
                                ubahNamaPlaylist(playlist[pilih - 1], playlist, totalPlaylist);
                            } else if (opsiubah == 2) {
                                ubahMusik(playlist[pilih - 1]);
                            } else {
                                cout << "Pilihan tidak valid!\n";
                            }
                        } else {
                            cout << "Pilihan tidak valid!\n";
                        }
                    } else {
                        cout << "Playlist tidak ditemukan!\n";
                    }
                } else if (pilihan == 5) {
                    if (totalPlaylist == 0) {
                        cout << "Tidak ada playlist.\n";
                        continue;
                    }

                    lihatPlaylist(playlist, totalPlaylist, false);

                    int pilih;
                    cout << "Pilih Playlist: ";
                    cin >> pilih;
                    cin.ignore();

                    if (pilih > 0 && pilih <= totalPlaylist) {
                        cout << "1. Hapus Playlist\n";
                        cout << "2. Hapus Musik\n";
                        int opsi;
                        cout << "Pilihan: ";
                        cin >> opsi;
                        cin.ignore();

                        if (opsi == 1) {
                            hapusPlaylist(playlist, totalPlaylist, pilih - 1);
                        } else if (opsi == 2) {
                            hapusMusikDalamPlaylist(playlist[pilih - 1]);
                        } else {
                            cout << "Pilihan tidak valid!\n";
                        }
                    } else {
                        cout << "Playlist tidak ditemukan!\n";
                    }
                } else if (pilihan == 0) {
                    cout << "Terima kasih telah menggunakan program ini!\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
            break;
        } else {
            kesempatan--;
            cout << "Username atau password salah! Kesempatan tersisa: " << kesempatan << endl;
        }
    }

    return 0;
}