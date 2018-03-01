#include <cstdlib>
#include<iostream>
#include"SnmpError.h"
#include "NetSnmp.h"
#include  <gtest/gtest.h>

using namespace std;

TEST(CreateNetSnmpTest, BadCommunity) {

ASSERT_THROW(NetSnmp("127.0.0.1", "illegal_community"), SnmpError);

}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


