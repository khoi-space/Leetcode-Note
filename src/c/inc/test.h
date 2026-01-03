#include <stdio.h>
#include <stdbool.h>
#include "../utils/compare.h"
#include "../utils/convert.h"

static inline bool assertTestInt(int res, int exp, int caseName) {
	printf("Case %d: ", caseName);
	if (!isEqualInt(res, exp)) {
		printf("\033[1;31mFAILED\033[0m\n");
		printf("   \033[32mExpected\033[0m : %d\n", exp);
		printf("   \033[31mGot\033[0m      : %d\n", res);
		return false;
	} else {
		printf("\033[1;32mPASSED\033[0m\n");
		return true;
	}
}

static inline bool assertTestList(ListNode* res, ListNode* exp, int caseName) {
	printf("Case %d: ", caseName);
	if (!isEqualList(res, exp)) {
		printf("\033[1;31mFAILED\033[0m\n");
		printf("   \033[32mExpected\033[0m : "); printLL(exp); printf("\n");
		printf("   \033[31mGot\033[0m      : "); printLL(res); printf("\n");
		return false;
	} else {
		printf("\033[1;32mPASSED\033[0m\n");
		return true;
	}
}

static inline bool assertTestArray(const int* res, int rn, const int* exp, int en, int caseName) {
    printf("Case %d: ", caseName);
    if (!isEqualArray(res, rn, exp, en)) {
        printf("\033[1;31mFAILED\033[0m\n");
		printf("   \033[32mExpected\033[0m : "); printIntArr(exp, (unsigned)en); printf("\n");
		printf("   \033[31mGot\033[0m      : "); printIntArr(res, (unsigned)rn); printf("\n");
        return false;
    } else {
        printf("\033[1;32mPASSED\033[0m\n");
        return true;
    }
}

void test1(void);
void test4000();
