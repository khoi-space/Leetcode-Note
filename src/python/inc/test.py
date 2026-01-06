def assertTest(res, exp, case_name):
	GREEN = '\033[1;32m'
	RED = '\033[1;31m'
	RESET = '\033[0m'
	BOLD = '\033[1m'
	print(f"{BOLD}Case {case_name + 1}: ", end='')

	def is_listnode(obj):
		return hasattr(obj, 'val') and hasattr(obj, 'next')

	def listnode_equal(a, b):
		while a and b:
			if a.val != b.val:
				return False
			a = a.next
			b = b.next
		return a is None and b is None

	equal = False
	if is_listnode(res) and is_listnode(exp):
		equal = listnode_equal(res, exp)
	else:
		equal = (res == exp)

	if not equal:
		print(f"{RED}FAILED{RESET}")
		print(f"   Expected : {exp}")
		print(f"   Got      : {res}")
		return False
	else:
		print(f"{GREEN}PASSED{RESET}")
		return True