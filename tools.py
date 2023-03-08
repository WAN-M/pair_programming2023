import base64
import traceback

from PyQt5.QtGui import QPixmap, QIcon

def base64ToQPixmap(data):
    try:
        pixmap = QPixmap()
        pixmap.loadFromData(base64.b64decode(data))
        return pixmap

    except Exception as e:
        print(traceback.format_exc())

def base64ToQIcon(data):
    return QIcon(base64ToQPixmap(data))
