#include <iostream>
#include "World.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: run the program with <init file name> <location file name>" << std::endl;
        exit(1);
    }
    std::string file_1 = argv[1];
    std::string file_2 = argv[2];
    World *world;
    int length_v;
    int pm;
    int *target;
    string line;
    ifstream file1(file_1);
    if (!file1.is_open()) {
        cout << "Unable to open file";
        exit(1);
    } else {
        getline(file1, line);
        length_v = stoi(line);
        getline(file1, line);
        pm = stoi(line);
        string num;
        target = new int[length_v];
        getline(file1, line);
        stringstream ss(line);
        int i = 0;
        while (ss >> num) {
            if (i >= length_v) {
                cerr << "Invalid input.\n";
                exit(1);
            }
            target[i] = stoi(num);
            i++;
        }
        if (i != length_v) {
            cerr << "Invalid input.\n";
            exit(1);
        }

    }
    file1.close();
    int amount_virus;
    ifstream file2(file_2);
    if (!file2.is_open()) {
        cerr << "Unable to open file";
        exit(1);
    } else {
        getline(file2, line);
        amount_virus = stoi(line);
        string name;
        string num;
        int count = 0;
        world = new World(amount_virus);

        while (getline(file2, line)) {
            if (count >= amount_virus) {
                cerr << "Invalid input.\n";
                exit(1);
            }

            stringstream ss(line);
            ss >> name;

            int *v = new int[length_v];
            int i = 0;
            while (ss >> num) {
                if (i >= length_v) {
                    cerr << "Invalid input.\n";
                    exit(1);
                }
                v[i] = stoi(num);
                i++;
            }
            if (i != length_v) {
                cerr << "Invalid input.\n";
                exit(1);
            }

            world->add_virus(name, length_v, pm, target, v, count);
            count++;

        }
        if (count != amount_virus) {
            cerr << "Invalid input.\n";
            exit(1);
        }
    }
    int time = 0;
    int h;
    cin >> h;
    //world->sort_virus();
    while (!(time >= (h) || world->isErrorZero())) {

        (*world)++;
        world->updating_all_single();

        time++;
    }
    world->print_world();
    cout << "\n";

    return 0;

}