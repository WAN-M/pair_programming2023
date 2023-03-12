import traceback

from PyQt5 import Qt
from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLineEdit, QTextEdit, QLabel
class LogWidget(QWidget):
    cmd = None
    log_text = None
    def __init__(self):
        try:
            super(LogWidget, self).__init__()
            self.__initUI()

            self.__qss()
        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):

        log_container = QVBoxLayout()
        log_container.setContentsMargins(0, 0, 0, 0)  # 外边隙0
        log_container.setSpacing(0)  # 控件间间隙为0

        self.__log_title = QLabel()
        self.__log_title.setText(" Log")
        # self.__log_title.setFocusPolicy(Qt.Qt.NoFocus)
        log_container.addWidget(self.__log_title)

        LogWidget.log_text = QTextEdit()
        LogWidget.log_text.setObjectName("log_text")
        LogWidget.log_text.setFont(QFont("Microsoft YaHei", 11))
        log_container.addWidget(LogWidget.log_text)

        LogWidget.cmd = QLineEdit()
        LogWidget.cmd.setObjectName("cmd")
        log_container.addWidget(LogWidget.cmd)
        LogWidget.cmd.setFocusPolicy(Qt.Qt.NoFocus)
        LogWidget.cmd.setText('未选择必选参数')

        self.setLayout(log_container)

    def __qss(self):
        self.__log_title.setFixedHeight(35)
        font = self.__log_title.font()
        font.setPointSize(10)
        self.__log_title.setFont(font)

        LogWidget.cmd.setFixedHeight(35)
        font = LogWidget.cmd.font()
        font.setPointSize(10)
        LogWidget.cmd.setFont(font)

        self.setMaximumHeight(600)
        # self.setMinimumHeight(300)
