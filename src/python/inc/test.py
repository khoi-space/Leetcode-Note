def assertTest(res, exp, case_name):
	GREEN = '\033[1;32m'
	RED = '\033[1;31m'
	RESET = '\033[0m'
	BOLD = '\033[1m'
	print(f"{BOLD}Case {case_name + 1}: ", end='')
	if res != exp:
		print(f"{RED}FAILED{RESET}")
		print(f"   Expected : {exp}")
		print(f"   Got      : {res}")
		return False
	else:
		print(f"{GREEN}PASSED{RESET}")
		return True