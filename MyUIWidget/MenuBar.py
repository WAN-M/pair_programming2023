import traceback

from PyQt5.QtWidgets import QMenuBar, QWidget, QHBoxLayout, QSpacerItem, QSizePolicy
from tools import base64ToQIcon
from resources import main_png, minimize_png, close_png

class MenuBar(QWidget):
    def __init__(self, main_window):
        try:
            super(MenuBar, self).__init__()

            self.__initIcon()
            self.__initRight(main_window)
            self.__initUI()

            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main_container = QHBoxLayout()
        main_container.setContentsMargins(0, 0, 0, 0)  # 外边隙0
        main_container.setSpacing(0)  # 控件间间隙为0

        main_container.addWidget(self.__icon_bar)

        spacer = QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)
        main_container.addItem(spacer) # 弹簧控件

        main_container.addWidget(self.__right_bar)
        self.setLayout(main_container)

    def __initIcon(self):
        self.__icon_bar = QMenuBar()
        self.__icon_bar.setObjectName("icon_bar")
        icon = self.__icon_bar.addAction("icon")
        icon.setIcon(base64ToQIcon(main_png))

        size = self.__icon_bar.sizePolicy()
        size.setHorizontalPolicy(QSizePolicy.Minimum)
        size.setVerticalPolicy(QSizePolicy.Minimum)
        self.__icon_bar.setSizePolicy(size) # 布局策略

    def __initRight(self, main_window):
        self.__right_bar = QMenuBar()
        self.__right_bar.setObjectName("right_menu_bar")

        minimized_button = self.__right_bar.addAction("Minimize")
        minimized_button.setIcon(base64ToQIcon(minimize_png))
        minimized_button.triggered.connect(main_window.showMinimized)

        close_button = self.__right_bar.addAction("Close")
        close_button.setIcon(base64ToQIcon(close_png))
        close_button.triggered.connect(main_window.close)

        size = self.__right_bar.sizePolicy()
        size.setHorizontalPolicy(QSizePolicy.Minimum)
        size.setVerticalPolicy(QSizePolicy.Minimum)
        self.__right_bar.setSizePolicy(size)

    def __qss(self):
        self.__right_bar.setFixedHeight(40) # 固定高度
        font = self.__right_bar.font()
        font.setPointSize(11)
        self.__right_bar.setFont(font) # 固定字体大小

        self.__icon_bar.setFixedHeight(40) # 固定高度
