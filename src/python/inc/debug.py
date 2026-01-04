DEBUG = False

def see(*args, endl=True, **kwargs):
    if globals().get('DEBUG', False):
        if endl:
            print(*args, **kwargs)
        else:
            print(*args, **kwargs, end=" | ")

def say(*args, endl=True):
    if globals().get('DEBUG', False):
        if endl:
            print(*args)
        else:
            print(*args, end=" | ")