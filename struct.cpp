#include "struct.h"
#include <iomanip>
#include <ctime>

ostream &operator<<(ostream &os, const Table &table) {
    cout.setf(ios::left);
    cout << setw(20) << "Direction cipher" << " | ";
    cout << setw(25) << "Direction title" << " | ";
    cout << setw(20) << "Profile cipher" << " | ";
    cout << setw(25) << "Profile title" << " | ";
    cout << setw(10) << "Start year" << "\n";
    cout << setw(112) << setfill('-') << "" << "\n";
    for (size_t i = 0; i < table.size; ++i) {
        cout << setw(20) << setfill(' ') << table.rows[i].direction_cipher << " | ";
        cout << setw(25) << table.rows[i].direction_title << " | ";
        cout << setw(20) << table.rows[i].profile_cipher << " | ";
        cout << setw(25) << table.rows[i].profile_title << " | ";
        cout << setw(10) << table.rows[i].start_year << "\n";
    }
    return os;
}

istream &operator>>(istream &is, Curriculum &curriculum) {
    cout << "Input Direction cipher, Direction title, Profile cipher, Profile title, Start year, "
            "use \"space\" as delimiter\n";
    cout << "Example: 090304 Software_engineering 090304_2 Mobile_applications 2024\n";
    is >> curriculum.direction_cipher >> curriculum.direction_title >> curriculum.profile_cipher;
    is >> curriculum.profile_title >> curriculum.start_year;
    return is;
}

void push_back(Table &table, const Curriculum &curriculum) {
    table.size++;
    auto *resized = new Curriculum[table.size];
    for (size_t i = 0; i < table.size - 1; ++i) {
        resized[i] = table.rows[i];
    }
    resized[table.size - 1] = curriculum;
    delete[] table.rows;
    table.rows = resized;
}

void insert(Table &table, const Curriculum &curriculum) {
    size_t insert_index = -1;
    for (size_t i = 0; i < table.size; ++i) {
        if (strcmp(table.rows[i].direction_cipher, curriculum.direction_cipher) == 0) {
            insert_index = i;
            break;
        }
    }
    if (insert_index == -1) {
        cout << "No cipher found\n";
        return;
    }
    table.size++;
    auto *resized = new Curriculum[table.size];
    for (size_t i = 0; i < insert_index; ++i) {
        resized[i] = table.rows[i];
    }
    resized[insert_index] = curriculum;
    for (size_t i = insert_index + 1; i < table.size; ++i) {
        resized[i] = table.rows[i - 1];
    }
    delete[] table.rows;
    table.rows = resized;
}

void find_curriculum(Table &table, char direction_cipher[100]) {
    bool flag = false;
    for (size_t i = 0; i < table.size; ++i) {
        if (strcmp(table.rows[i].direction_cipher, direction_cipher) == 0) {
            if (!flag) {
                cout << setw(25) << "Profile title" << " | ";
                cout << setw(10) << "Start year" << "\n";
                cout << setw(38) << setfill('-') << "" << "\n";
                flag = true;
            }
            cout << setw(25) << setfill(' ') << table.rows[i].profile_title << " | ";
            cout << setw(10) << table.rows[i].start_year << "\n";
        }
    }
    if (!flag) {
        cout << "No cipher found\n";
    }
}

void delete_on_expiration(Table &table) {
    time_t now = time(nullptr);
    tm ltm = {};
    localtime_s(&ltm, &now);
    for (size_t i = 0; i < table.size; ++i) {
        if (table.rows[i].start_year < ltm.tm_year + 1900 - 3) {
            table.size--;
            auto *resized = new Curriculum[table.size];
            for (size_t j = 0; j < i; ++j) {
                resized[j] = table.rows[j];
            }
            for (size_t j = i; j < table.size ; ++j) {
                resized[j] = table.rows[j + 1];
            }
            delete[] table.rows;
            table.rows = resized;
            --i;
        }
    }
}