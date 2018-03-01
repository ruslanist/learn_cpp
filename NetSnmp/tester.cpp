#include <cstdlib>
#include<iostream>
#include"SnmpError.h"
#include "NetSnmp.h"
#include  <gtest/gtest.h>

using namespace std;

TEST(CreateNetSnmpTest, BadAidGetInt) {

NetSnmp netSnmp("127.0.0.1", "illegal_community");

ASSERT_THROW(netSnmp.getInt("1.4.3.6.5.4.8.65"), SnmpError);

}


TEST(CreateNetSnmpTest, BadAidGetString) {

NetSnmp netSnmp("127.0.0.1", "illegal_community");

ASSERT_THROW(netSnmp.getString("1.4.3.6.5.4.8.67"), SnmpError);

}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


