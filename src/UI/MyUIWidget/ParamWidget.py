import traceback

from PyQt5.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QCheckBox, QLineEdit, QSpacerItem, QSizePolicy, QToolBar
from PyQt5.QtCore import Qt

# from MyUIWidget.ControllerWindow import buttunHazard
from order import order_instance
from resources import select_png, selected_png
from tools import base64ToQIcon

class ParamWidget(QWidget):
    def __init__(self, name, need_text=False):
        try:
            super(ParamWidget, self).__init__()
            self.need_text = need_text
            self.setObjectName(name)
            self.__initUI()
            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main_container = QVBoxLayout()
        main_container.setContentsMargins(20, 0, 20, 0) # 外边隙0
        # main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        check_button = QWidget()
        button_container = QHBoxLayout()
        button_container.setContentsMargins(0, 5, 0, 5) # 外边隙0
        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        self.check = QToolBar()
        self.check.setToolButtonStyle(Qt.ToolButtonTextBesideIcon) # icon 旁边显示文字
        self.button = self.check.addAction(self.objectName())
        self.button.triggered.connect(self.changeIcon)
        self.press = False
        self.button.setIcon(base64ToQIcon(select_png))

        button_container.addWidget(self.check)
        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        check_button.setLayout(button_container)
        # main_container.setSpacing(0) # 控件间间隙为0
        # main_container.

        # check = QWidget()
        # check_container = QHBoxLayout()
        # check_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        # self.label = QCheckBox(self.objectName())
        # check_container.addWidget(self.label)

        # check_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        # check.setLayout(check_container)
        main_container.addWidget(check_button)

        if self.need_text:
            self.text = QLineEdit()
            self.text.textChanged.connect(self.__text_change)
            main_container.addWidget(self.text)

        # main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        self.setLayout(main_container)

    def __qss(self):
        self.check.setFixedHeight(35)
        font = self.font()
        font.setPointSize(11)
        self.check.setFont(font)

        if self.need_text:
            self.text.setFixedHeight(35)
            self.text.setObjectName("input_box")
            font = self.text.font()
            font.setPointSize(10)
            self.text.setFont(font)

    def changeIcon(self):
        # buttunHazard(self.objectName())

        if self.press:
            self.press = False
            self.button.setIcon(base64ToQIcon(select_png))
            order_instance.changeParam(self.objectName().split(" ")[0], False)
        else:
            self.press = True
            self.button.setIcon(base64ToQIcon(selected_png))
            order_instance.changeParam(self.objectName().split(" ")[0], True)

        # if self.need_text:
        #     order_instance.setText(self.objectName().split(" ")[0], self.text.text())
        order_instance.changeCmdText()

    def __text_change(self):
        order_instance.setText(self.objectName().split(" ")[0], self.text.text())
        order_instance.changeCmdText()

    def click(self):
        self.button.trigger()

    def setStatus(self, status):
        # order_instance.changeParam(self.objectName().split(" ")[0], status)
        self.setEnabled(status)
