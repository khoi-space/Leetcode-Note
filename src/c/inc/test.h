#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../utils/compare.h"
#include "../utils/print.h"

typedef bool (*cmp_func)(const void*, const void*);
typedef void (*print_func)(const void*);

// Generic assertion function for any data type
// res: result pointer
// rn: result length (< 0 if res is linked list type)
// exp: expected pointer
// en: expected length (< 0 if exp is linked list type)
// caseName: case number
// elem_size: size of each element (use sizeof)
// cmp: comparison function pointer
// printElem: print function pointer
static inline bool assertTest(const void* res, int rn, const void* exp, int en, int caseName, size_t elem_size, cmp_func cmp, print_func printElem) {
	printf("\033[1mCase %d: ", caseName + 1);
	if (rn < 0 || en < 0) {
		if (!cmp(res, exp)) {
			printf("\033[31mFAILED\033[0m\n");
			printf("   Expected : ");
			printElem(exp);
			printf("   Got      : ");
			printElem(res);
			return false;
		}
	}

	if (rn != en) {
		printf("\033[31mFAILED\033[0m\n");
		printf("   Expected : (length %d)\n", en);
		printf("   Got      : (length %d)\n", rn);
		return false;
	}

	for (int i = 0; i < rn; ++i) {
		const void* a = (const char*)res + i * elem_size;
		const void* b = (const char*)exp + i * elem_size;
		if (!cmp(a, b)) {
			printf("\033[31mFAILED\033[0m\n");
			printf("   Expected : ");
			for (int j = 0; j < en; ++j) printElem((const char*)exp + j * elem_size);
			printf("\n");
			printf("   Got      : ");
			for (int j = 0; j < rn; ++j) printElem((const char*)res + j * elem_size);
			printf("\n");
			return false;
		}
	}
	printf("\033[32mPASSED\033[0m\n");
	return true;
}

void test1(void);
void test2(void);
