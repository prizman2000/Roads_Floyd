#include "gtest/gtest.h"
#include "lib.h"

TEST(OperatorSum, expectedSum) {

    ifstream file("/Users/apple/CLionProjects/OOP_dorogi/roads");
    Doroga *mass = new Doroga[Roads];
    string a;

    for (int i = 0; i < Roads; i++) {

        getline(file, a);
        mass[i].destination = a[0];

        a = a.erase(0, 2);
        mass[i].arrival = a[0];

        a = a.erase(0, 2);
        int len = atoi(a.c_str());
        mass[i].length = len;
    }

EXPECT_EQ(choose_shortest('A','C', mass), 3);
EXPECT_EQ(choose_shortest('C','B', mass), 4);
EXPECT_EQ(choose_shortest('A','B', mass), 5);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
