import traceback

from PyQt5.QtWidgets import QWidget, QVBoxLayout, QFrame, QSpacerItem, QSizePolicy
from MyUIWidget.ParamWidget import ParamWidget

class ControllerWindow(QFrame):
    def __init__(self):
        try:
            super(ControllerWindow, self).__init__()
            self.setObjectName("controller_window")
            self.__initUI()
            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main_container = QVBoxLayout()
        main_container.setContentsMargins(0, 0, 0, 0) # 外边隙0
        # main_container.setSpacing(0) # 控件间间隙为0

        main_container.addWidget(ParamWidget("-n 单词链个数"))
        main_container.addWidget(ParamWidget("-w 最多单词数"))
        main_container.addWidget(ParamWidget("-c 最多字母数"))
        main_container.addWidget(ParamWidget("-r 允许单词环"))
        main_container.addWidget(ParamWidget("-h 指定首字母", True))
        main_container.addWidget(ParamWidget("-t 指定尾字母", True))
        main_container.addWidget(ParamWidget("-j 禁用首字母", True))

        main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Expanding))

        self.setLayout(main_container)

    def __qss(self):
        self.setFixedWidth(300)
