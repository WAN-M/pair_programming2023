import traceback

from PyQt5.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QCheckBox, QLineEdit, QSpacerItem, QSizePolicy, QToolBar
from PyQt5.QtCore import Qt
from resources import add_break_png, del_break_png, debug_png
from tools import base64ToQIcon


class APIWidget(QWidget):
    def __init__(self, name):
        try:
            super(APIWidget, self).__init__()
            self.setObjectName(name)
            self.__initUI()
            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        button_container = QHBoxLayout()
        button_container.setContentsMargins(0, 5, 0, 5) # 外边隙0
        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        self.check = QToolBar()
        self.check.setToolButtonStyle(Qt.ToolButtonTextBesideIcon) # icon 旁边显示文字
        self.button = self.check.addAction(self.objectName())
        self.button.setIcon(base64ToQIcon(debug_png))

        button_container.addWidget(self.check)
        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        self.setLayout(button_container)

    def __qss(self):
        self.check.setFixedHeight(35)
        font = self.font()
        font.setPointSize(11)
        self.check.setFont(font)
