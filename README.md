# Billing Warnet Sederhana

Aplikasi ini adalah aplikasi sederhana yang digunakan untuk menghitung biaya berdasarkan waktu yang telah berlalu, dengan tarif yang dapat diatur oleh pengguna. Aplikasi ini menggunakan wxWidgets sebagai toolkit GUI dan C++ untuk implementasinya.

## Fitur

- Menampilkan waktu berjalan dalam format jam:menit:detik.
- Pengguna dapat memasukkan tarif per detik (IDR).
- Aplikasi akan menghitung biaya berdasarkan waktu yang berjalan.
- Ada tombol "Mulai" untuk memulai penghitungan waktu, dan tombol "Berhenti" untuk menghentikan penghitungan dan menampilkan total biaya.
- Konfirmasi sebelum menutup aplikasi.

## Persyaratan

Sebelum menjalankan aplikasi ini, pastikan Anda telah menginstal wxWidgets dan memiliki lingkungan pengembangan C++ yang sesuai.

### Instalasi wxWidgets

1. **Di Linux (Ubuntu):**
   Jalankan perintah berikut untuk menginstal wxWidgets:
   ```bash
   sudo apt-get install libwxgtk3.0-gtk3-dev
   ```

2. **Di Windows:**
   Unduh wxWidgets dari [situs resmi wxWidgets](https://www.wxwidgets.org/downloads/) dan ikuti petunjuk untuk menginstalnya di Visual Studio atau MinGW.

## Cara Menjalankan

1. **Unduh Proyek:**
   Unduh kode sumber proyek ini ke sistem Anda.

2. **Build Proyek:**
   Di Linux/macOS, buka terminal dan jalankan perintah berikut:
   ```bash
   g++ -o billing_app billing_app.cpp `wx-config --cxxflags --libs`
   ```

   Di Windows, gunakan IDE seperti Code::Blocks atau Visual Studio. Pastikan proyek dikonfigurasi dengan benar agar dapat menghubungkan ke wxWidgets.

3. **Jalankan Aplikasi:**
   Setelah build selesai, jalankan aplikasi dengan perintah berikut di terminal:
   ```bash
   ./billing_app
   ```

4. **Gunakan Aplikasi:**
   - Masukkan tarif per detik yang diinginkan.
   - Klik "Mulai" untuk mulai menghitung waktu.
   - Klik "Berhenti" untuk menghentikan penghitungan waktu dan melihat total biaya.

## Kontribusi

Jika Anda ingin berkontribusi pada proyek ini, fork repositori ini dan kirim pull request dengan fitur atau perbaikan yang Anda buat.

## Lisensi

Proyek ini dilisensikan di bawah [MIT License](LICENSE).
