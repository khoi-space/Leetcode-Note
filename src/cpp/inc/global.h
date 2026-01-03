#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>

#ifdef DEBUG
#define db_put(x)      std::cout << "\033[30m" << #x << ": " << x << " | " <<  "\033[0m";
#define db_dump(x)     std::cout << "\033[30m" << #x << ": " << x << "\033[0m" << std::endl;
#define db_say(x)      std::cout << "\033[30m" << x << "\033[0m" << std::endl;
#else
#define db_put(x)      ;
#define db_dump(x)     ;
#define db_say(x)      ;
#endif

#endif // GLOBAL_H