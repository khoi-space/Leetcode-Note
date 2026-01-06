from typing import List, Optional, Dict, Set, Tuple
from inc.listnode import *
from inc.treenode import *

def isEqual(lhs, rhs, unorder=False) -> bool:
	"""
	Compare lhs and rhs
	
	:param lhs, rhs: arguments
	:param unorder: don't care about order
	"""
	if is_listnode(lhs) and is_listnode(rhs):
		# Handle with listnode
		return listnode_equal(lhs, rhs, unorder)
	elif is_treenode(lhs) and is_treenode(rhs):
		# Handle with treenode
		return treenode_equal(lhs, rhs, unorder)
	else:
		# Handle with basic types
		if unorder and isinstance(lhs, (list, tuple, str) and isinstance(rhs, (list, tuple, str))):
			# Sort first
			sorted(lhs)
			sorted(rhs)

		return lhs == rhs

def assertTest(res, exp, case_name, unorder=False):
	GREEN = '\033[1;32m'
	RED = '\033[1;31m'
	RESET = '\033[0m'
	BOLD = '\033[1m'
	print(f"{BOLD}Case {case_name + 1}: ", end='')

	equal = isEqual(res, exp, unorder)

	if not equal:
		print(f"{RED}FAILED{RESET}")
		print(f"   Expected : {exp}")
		print(f"   Got      : {res}")
		return False
	else:
		print(f"{GREEN}PASSED{RESET}")
		return True