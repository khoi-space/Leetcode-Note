#ifndef TEST_H
#define TEST_H
#include <cmath>
#include "compare.h"
#include "convert.h"
class Test {
public:
	template<typename T>
	void assertTest(const T& res, const T& exp, const int caseName);
	// Testcases
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();
	void test8();
	void test9();
	void test10();
	void test11();
	void test12();
	void test13();
	void test14();
	void test15();
	void test16();
	void test17();
	void test18();
	void test19();
	void test20();
	void test21();
	void test22();
	void test23();
	void test24();
	void test25();
	void test26();
	void test27();
	void test28();
	void test29();
	void test30();
	void test1523();
	void test2211();
	void test3432();
	void test3433();
};

template <typename T>
void Test::assertTest(const T& res, const T& exp, const int caseName) {
	cout << "Case " << caseName << ": ";
	if (!isEqual(res, exp)) {
		cout << "\033[31mFAILED\033[0m: " << "Expected=" << exp << " Got=" << res << endl;
	} else {
		cout << "\033[32mPASSED\033[0m\n";
	}
}
#endif //TEST_H