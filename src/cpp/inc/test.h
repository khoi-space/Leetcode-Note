#include "../utils/compare.h"
#include "../utils/convert.h"

template <typename T>
bool assertTest(const T& res, const T& exp, const int caseName) {
	cout << "Case " << caseName << ": ";
	if (!isEqual(res, exp)) {
		cout << "\033[1;31mFAILED\033[0m" << endl;
		cout << "   \033[32mExpected\033[0m : " << exp << endl;
		cout << "   \033[31mGot\033[0m      : " << res << endl;
		return false;
	} else {
		cout << "\033[1;32mPASSED\033[0m\n";
		return true;
	}
}

void test0();
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
void test66();
void test67();
void test151();
void test162();
void test238();
void test283();
void test334();
void test345();
void test392();
void test443();
void test605();
void test643();
void test724();
void test840();
void test944();
void test955();
void test1004();
void test1071();
void test1207();
void test1351();
void test1431();
void test1456();
void test1493();
void test1523();
void test1657();
void test1679();
void test1732();
void test1768();
void test1925();
void test1957();
void test2110();
void test2210();
void test2211();
void test2215();
void test2352();
void test2390();
void test3074();
void test3432();
void test3433();
void test3487();
void test3606();
