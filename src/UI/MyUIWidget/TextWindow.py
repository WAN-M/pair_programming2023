import traceback

from PyQt5 import Qt
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QSplitter
from MyUIWidget.EditorWidget import EditorWidget
from MyUIWidget.LogWidget import LogWidget

class TextWindow(QSplitter):
    def __init__(self):
        try:
            super(TextWindow, self).__init__(Qt.Qt.Vertical)
            self.setObjectName("text_window")
            self.__initUI()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main = QWidget()

        # main_container = QSplitter()
        # main_container.setContentsMargins(0, 0, 0, 0)  # 外边隙0

        top_container = QHBoxLayout()
        top_container.setContentsMargins(0, 0, 0, 0)  # 外边隙0
        top_container.setSpacing(0)  # 控件间间隙为0

        top_container.addWidget(EditorWidget("input"))
        top_container.addWidget(EditorWidget("output"))

        main.setLayout(top_container)
        self.addWidget(main)

        # main_container.addWidget(main)
        self.addWidget(LogWidget())
        # main_container.addWidget(LogWidget())
        self.setStretchFactor(0, 70)
        self.setStretchFactor(1, 30)

        # self.setLayout(main_container)
