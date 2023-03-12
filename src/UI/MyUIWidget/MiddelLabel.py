import traceback

from PyQt5.QtWidgets import QWidget, QHBoxLayout, QSpacerItem, QSizePolicy, \
    QLabel

class MiddleLabelWidget(QWidget):
    def __init__(self, name):
        try:
            super(MiddleLabelWidget, self).__init__()
            self.setObjectName(name)
            self.__initUI()
            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        button_container = QHBoxLayout()
        button_container.setContentsMargins(0, 0, 0, 0) # 外边隙0
        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        self.__label = QLabel(self.objectName())
        button_container.addWidget(self.__label)

        button_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        self.setLayout(button_container)

    def __qss(self):
        self.__label.setFixedHeight(20)
        font = self.__label.font()
        font.setPointSize(11)
        self.__label.setFont(font)

