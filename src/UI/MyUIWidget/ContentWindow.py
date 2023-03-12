import traceback

from PyQt5.QtWidgets import QWidget, QHBoxLayout
from MyUIWidget.TextWindow import TextWindow
from MyUIWidget.ControllerWindow import ControllerWindow

class ContentWindow(QWidget):
    def __init__(self):
        try:
            super(ContentWindow, self).__init__()
            self.setObjectName("content_window")
            self.__initUI()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main_container = QHBoxLayout()
        main_container.setContentsMargins(0, 0, 0, 0) # 外边隙0
        main_container.setSpacing(0) # 控件间间隙为0

        controller = ControllerWindow()
        main_container.addWidget(controller)

        text = TextWindow()
        main_container.addWidget(text)

        self.setLayout(main_container)
