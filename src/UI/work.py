import os

def test():
    text = os.popen("test.exe -n -h s", "r").read()
    print("shit")
    print(text)

test()
