#include "../utils/compare.h"
#include "../utils/convert.h"

template <typename T>
bool assertTest(const T& res, const T& exp, const int caseName) {
	cout << "Case " << caseName << ": ";
	if (!isEqual(res, exp)) {
		cout << "\033[1;31mFAILED\033[0m" << endl;
		cout << "   Expected : " << exp << endl;
		cout << "   Got      : " << res << endl;
		return false;
	} else {
		cout << "\033[1;32mPASSED\033[0m\n";
		return true;
	}
}

void test1();