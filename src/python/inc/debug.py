DEBUG = False

def dump(*args, endl=True, **kwargs):
    """Print value with a short expression"""
    if globals().get('DEBUG', False):
        if endl:
            print(*args, **kwargs)
        else:
            print(*args, **kwargs, end=" | ")

def see(*args, endl=True):
    """Just print the value"""
    if globals().get('DEBUG', False):
        if endl:
            print(*args)
        else:
            print(*args, end=" | ")

def log(*args, endl=True, **kwargs):
    """Print the value with short expression into debug.log"""
    if globals().get('DEBUG', False):
        with open('debug.log', 'a', encoding='utf-8') as f:
            if endl:
                print(*args, **kwargs, file=f)
            else:
                print(*args, **kwargs, end=" | ", file=f)