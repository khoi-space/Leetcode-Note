def assertTest(res, exp, case_name):
	GREEN = '\033[1;32m'
	RED = '\033[1;31m'
	RESET = '\033[0m'
	BOLD_GREEN = '\033[32m'
	BOLD_RED = '\033[31m'
	print(f"Case {case_name + 1}: ", end='')
	if res != exp:
		print(f"{RED}FAILED{RESET}")
		print(f"   {BOLD_GREEN}Expected{RESET} : {exp}")
		print(f"   {BOLD_RED}Got{RESET}      : {res}")
		return False
	else:
		print(f"{GREEN}PASSED{RESET}")
		return True