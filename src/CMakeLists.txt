cmake_minimum_required(VERSION 3.23)
project(monbrain)

# 1. Daftarkan libpqxx terlebih dahulu (biarkan CMake internal libpqxx membaca jalurnya sendiri)
add_subdirectory(Dependencies/libpqxx-7.10.7 build-pqxx)

# 2. Daftarkan modul internal proyek Anda
add_subdirectory(Database)
add_subdirectory(Ledger)

# 3. Buat executable utama
add_executable(monbrain main.cpp)

# 4. Link semua dependency ke target utama
target_link_libraries(monbrain PRIVATE Ledger Database)
