/**
 * @file UASPemdas.cpp
 * @author Pradipa Yogananda
 * @brief UAS PEMDAS 24 June
 * @version 0.1
 * @date 2024-06-24
 *
 * @copyright Copyright (c) 2024
 *
 */
 /*! \mainpage Sistem Menghitung kelulusan
 *
 * \section intro_sec Pengantar
 * Selamat datang di Dokumentasi "Sistem kelulusan".
 * Sistem ini dirancang untuk melihat kelulusan
 *
 * \section structure_sec Struktur Code
 *
 * \section setup_sec Setup dan Konfigurasi
 * Untuk menjalankan dan mengubah code ini anda membutuhkan kompiler seperti Visual Studio.
 *
 * \section note_sec Catatan
 * Dokumentasi ini dihasilkan dengan Doxygen.
 */

#include <iostream>
using namespace std;

class MataKuliah {
protected:
    float presensi, activity, exercise, tugasAkhir, NilaiAkhir;

public:
    MataKuliah() : presensi(0.0), activity(0.0), exercise(0.0), tugasAkhir(0.0), NilaiAkhir(0.0) {}

    virtual void namaMataKuliah() {
        return;
    }

    void setPresensi(float nilai) {
        this->presensi = nilai;
    }

    float getPresensi() const {
        return presensi;
    }

    virtual void inputNilai() = 0; // Pure virtual function

    virtual void hitungNilaiAkhir() = 0; // Pure virtual function

    float getNilaiAkhir() const {
        return NilaiAkhir;
    }

    virtual void display() const = 0; // Pure virtual function

protected:
    void setNilaiAkhir(float nilai) {
        this->NilaiAkhir = nilai;
    }
};

class Pemrograman : public MataKuliah {
public:
    void inputNilai() override {
        cout << "Masukan Nilai Presensi: ";
        cin >> presensi;
        cout << "Masukan Nilai Activity: ";
        cin >> activity;
        cout << "Masukan Nilai Exercise: ";
        cin >> exercise;
        cout << "Masukan Nilai Tugas Akhir: ";
        cin >> tugasAkhir;
    }

    void hitungNilaiAkhir() override {
        NilaiAkhir = (presensi * 0.1) + (activity * 0.2) + (exercise * 0.3) + (tugasAkhir * 0.4);
    }

    void display() const override {
        cout << "Nilai Presensi: " << presensi << endl;
        cout << "Nilai Activity: " << activity << endl;
        cout << "Nilai Exercise: " << exercise << endl;
        cout << "Nilai Tugas Akhir: " << tugasAkhir << endl;
        cout << "Nilai Akhir: " << NilaiAkhir << endl;
    }
};

class Jaringan : public MataKuliah {
public:
    void inputNilai() override {
        cout << "Masukan Nilai Activity: ";
        cin >> activity;
        cout << "Masukan Nilai Exercise: ";
        cin >> exercise;
    }

    void hitungNilaiAkhir() override {
        NilaiAkhir = (activity * 0.4) + (exercise * 0.6);
    }

    void display() const override {
        cout << "Nilai Activity: " << activity << endl;
        cout << "Nilai Exercise: " << exercise << endl;
        cout << "Nilai Akhir: " << NilaiAkhir << endl;
    }
};

int main() {
    char pilih;
    MataKuliah* mataKuliah = nullptr;
    Pemrograman pemrograman;
    Jaringan jaringan;

    do {
        cout << "Pilih Mata Kuliah: " << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case '1':
            mataKuliah = &pemrograman;
            break;
        case '2':
            mataKuliah = &jaringan;
            break;
        case '3':
            cout << "Selesai." << endl;
            break;
        default:
            cout << "Tidak ada opsi itu." << endl;
            continue;
        }

        if (pilih == '1' || pilih == '2') {
            mataKuliah->inputNilai();
            mataKuliah->hitungNilaiAkhir();
            mataKuliah->display();
        }

    } while (pilih != '3');

    return 0;
}
