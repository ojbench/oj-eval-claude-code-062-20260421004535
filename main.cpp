#include <iostream>
#include <cstring>
#include "MemoryRiver.hpp"

using namespace std;

struct TestData {
    int id;
    char name[50];
    double value;
};

int main() {
    // Test basic functionality
    MemoryRiver<TestData, 3> river("test.dat");

    // Initialize the file
    river.initialise();

    // Test write_info and get_info
    river.write_info(100, 1);
    river.write_info(200, 2);
    river.write_info(300, 3);

    int info1, info2, info3;
    river.get_info(info1, 1);
    river.get_info(info2, 2);
    river.get_info(info3, 3);

    cout << "Info values: " << info1 << " " << info2 << " " << info3 << endl;

    // Test write
    TestData data1 = {1, "Alice", 3.14};
    TestData data2 = {2, "Bob", 2.71};

    int idx1 = river.write(data1);
    int idx2 = river.write(data2);

    cout << "Write indices: " << idx1 << " " << idx2 << endl;

    // Test read
    TestData readData1, readData2;
    river.read(readData1, idx1);
    river.read(readData2, idx2);

    cout << "Read data1: " << readData1.id << " " << readData1.name << " " << readData1.value << endl;
    cout << "Read data2: " << readData2.id << " " << readData2.name << " " << readData2.value << endl;

    // Test update
    TestData updateData = {3, "Charlie", 1.41};
    river.update(updateData, idx1);

    TestData readUpdated;
    river.read(readUpdated, idx1);
    cout << "Updated data: " << readUpdated.id << " " << readUpdated.name << " " << readUpdated.value << endl;

    return 0;
}
