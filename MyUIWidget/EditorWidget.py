import traceback

from PyQt5.QtWidgets import QTabWidget
from MyUIWidget.Editor import Editor

class EditorWidget(QTabWidget):
    def __init__(self, name):
        try:
            super(EditorWidget, self).__init__()
            self.setObjectName(name)

            self.__initUI()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        self.addTab(Editor(), self.objectName())
