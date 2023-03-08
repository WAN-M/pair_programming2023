import sys
import traceback

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QCursor
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QFrame

from MyUIWidget.MenuBar import MenuBar
from MyUIWidget.RunBar import RunBar
from MyUIWidget.ContentWindow import ContentWindow

sys.setrecursionlimit(10000)
PADDING = 1

class MainWindow(QFrame):

    def __init__(self):
        try:
            super(MainWindow, self).__init__()
            self.__initUI() # 填充界面元素
            self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowSystemMenuHint) # 自身无边框
            self.SHADOW_WIDTH = 0 # 自身边框距离
            self.setFixedSize(1600, 900)
            self.setObjectName("main_back_ground") # 重命名

            # Plate.minimized_app.triggered.connect(self.minimized_app)
            # Plate.normal_maximized_app.triggered.connect(self.normal_maximized_app)
            # Plate.close_app.triggered.connect(self.close_app)

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        # 最外层垂直布局
        main_container = QVBoxLayout()
        main_container.setContentsMargins(0, 0, 0, 0) # 外边隙
        main_container.setSpacing(0) # 控件间间隙

        # 菜单栏 水平按钮
        menu_bar = MenuBar(self)
        main_container.addWidget(menu_bar)

        # 功能栏 水平按钮
        run_bar = RunBar()
        main_container.addWidget(run_bar)

        # 内容窗口 水平布局
        content_window = ContentWindow()
        main_container.addWidget(content_window)

        # 设置窗口显示的内容是最外层容器
        self.setLayout(main_container)

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.__mouse_flag = True
            self.__mouse_position = event.globalPos() - self.pos() # 获取鼠标相对窗口的位置
            event.accept()
            self.setCursor(QCursor(Qt.OpenHandCursor))  # 更改鼠标图标

    def mouseMoveEvent(self, event):
        if Qt.LeftButton and self.__mouse_flag:
            self.move(event.globalPos() - self.__mouse_position)#更改窗口位置
            event.accept()

    def mouseReleaseEvent(self, QMouseEvent):
        self.__mouse_flag = False
        self.setCursor(QCursor(Qt.ArrowCursor))
