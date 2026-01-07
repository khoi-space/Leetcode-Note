#include "../utils/compare.h"
#include "../utils/print.h"

// Assert Test and print result to terminal (option unorder_cmp means don't care about the order of res and exp)
template <typename T>
static bool assertTest(const T& res, const T& exp, const int caseName, bool unorder_cmp = false) {
	cout << "\033[1mCase " << caseName + 1 << ": ";
	if (!isEqual(res, exp, unorder_cmp)) {
		cout << "\033[31mFAILED\033[0m" << endl;
		cout << "   Expected : " << exp << endl;
		cout << "   Got      : " << res << endl;
		return false;
	} else {
		cout << "\033[32mPASSED\033[0m\n";
		return true;
	}
}

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test21();
void test28();
void test1161();
void test1339();
void test1975();
