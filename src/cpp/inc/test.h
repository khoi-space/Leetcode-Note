#include "../utils/compare.h"
#include "../utils/convert.h"

template <typename T>
bool assertTest(const T& res, const T& exp, const int caseName) {
	cout << "\033[1mCase " << caseName + 1 << ": ";
	if (!isEqual(res, exp)) {
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
void test4();
void test21();
void test28();
void test1975();
