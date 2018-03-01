all:
	g++ -std=c++11 main.cpp NetSnmp.cpp -lsnmp

test:
	g++ -std=c++11 tester.cpp NetSnmp.cpp -lsnmp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread -o tester ./tester 
