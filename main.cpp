#include "struct.h"

int main() {
    Table table = {};
    int n;
    cout << "Select option: \n"
            "1 - Fill the table with test data\n"
            "2 - Select task\n"
            "0 - Exit\n";
    cin >> n;
    if (n == 1) {
        push_back(table, {"090302", "Applied_Informatics",
                          "090302_1", "Data_management", 2022});
        push_back(table, {"090304", "Software_engineering",
                          "090304_1", "OOP", 2023});
        push_back(table, {"090304", "Software_engineering",
                          "090304_2", "Mobile_applications", 2024});
        push_back(table, {"090304", "Software_engineering",
                          "090304_3", "Mathematical_analysis", 2023});
        push_back(table, {"090304", "Software_engineering",
                          "090304_4", "Linear_algebra", 2018});
        cout << table;
    }
    while (n != 0) {
        cout << "Select task: \n"
                "1 - Fill out an entry for one curriculum\n"
                "2 - Insert an entry in the plan table at the beginning of the sublist, with the same direction cipher\n"
                "3 - Display the names of the profiles and the start year of the curriculum of the given direction\n"
                "4 - Delete plans that have expired after 4 years\n"
                "0 - Exit\n";
        cin >> n;
        if (n == 1) {
            Curriculum curriculum = {};
            cin >> curriculum;
            push_back(table, curriculum);
            cout << table;
        }
        if (n == 2) {
            Curriculum curriculum = {};
            cin >> curriculum;
            insert(table, curriculum);
            cout << table;
        }
        if (n == 3) {
            cout << "Input Direction cipher\n";
            char direction_cipher[100];
            cin >> direction_cipher;
            find_curriculum(table, direction_cipher);
        }
        if (n == 4) {
            delete_on_expiration(table);
            cout << table;
        }
    }
    return 0;
}