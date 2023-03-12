import base64
import traceback

from PyQt5.QtGui import QPixmap, QIcon

def readTxt(path):
    try:
        if path.endswith(".txt"):
            with open(path, "r", encoding="UTF-8") as f:
                return True, f.read()
        else:
            return False, "0"
    except Exception as e:
        print(traceback.format_exc())
        return False, "0"

def writeTxt(path, message):
    try:
        with open(path, "w", encoding="UTF-8") as f:
            f.write(message)
        return True
    except Exception as e:
        print(traceback.format_exc())
        return False

def base64ToQPixmap(data):
    try:
        pixmap = QPixmap()
        pixmap.loadFromData(base64.b64decode(data))
        return pixmap

    except Exception as e:
        print(traceback.format_exc())

def base64ToQIcon(data):
    return QIcon(base64ToQPixmap(data))
