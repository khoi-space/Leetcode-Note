import inspect
DEBUG = False

def loc(endl=True):
    """
    Print location of where loc() called in format "__file__:__line__"
    """
    if globals.get('DEBUG', False):
        frame = inspect.currentframe().f_back
        if endl:
            print(f"{frame.f_code.co_filename}:{frame.f_lineno}")
        else:
            print(f"{frame.f_code.co_filename}:{frame.f_lineno}", end=" | ")

def dump(*args, endl=True, **kwargs):
    """
    Print arguments

    :example:
        dump(a)                       : a
        dump(a, b, c)                 : a b c 
        dump("x=", x)                 : x=<x>
        dump([1,2,3])                 : [1, 2, 3]
        dump(a, b, sep=", ")          : 1, 2, 3
    """
    if globals().get('DEBUG', False):
        if endl:
            print(*args, **kwargs)
        else:
            print(*args, **kwargs, end=" | ")

def log(*args, endl=True, **kwargs):
    """Same with dump but print into file debug.log"""
    if globals().get('DEBUG', False):
        with open('debug.log', 'a', encoding='utf-8') as f:
            if endl:
                print(*args, **kwargs, file=f)
            else:
                print(*args, **kwargs, end=" | ", file=f)