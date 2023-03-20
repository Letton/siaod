#ifndef SIAOD_STRUCT_H
#define SIAOD_STRUCT_H

#include <iostream>

using namespace std;

struct Curriculum {
    char direction_cipher[100];
    char direction_title[100];
    char profile_cipher[100];
    char profile_title[100];
    unsigned short start_year;
};

struct Table {
    Curriculum *rows;
    size_t size;
};

ostream &operator<<(ostream &os, const Table &table);

istream &operator>>(istream &is, Curriculum &curriculum);

void push_back(Table &table, const Curriculum &curriculum);

void insert(Table &table, const Curriculum &curriculum);

void find_curriculum(Table &table, char direction_cipher[100]);

void delete_on_expiration(Table &table);

#endif //SIAOD_STRUCT_H
