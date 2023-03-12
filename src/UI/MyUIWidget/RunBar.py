import traceback

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QSizePolicy, QToolBar

from MyUIWidget.ImportExportWindow import ImportExportWindow
from tools import base64ToQIcon
from resources import open_file_png, run_png, save_file_png

class RunBar(QToolBar):
    def __init__(self):
        try:
            super(RunBar, self).__init__()
            self.setToolButtonStyle(Qt.ToolButtonTextBesideIcon) # icon 旁边显示文字
            self.setObjectName("run_bar")
            self.__initButton()
            self.__qss()
        except Exception as e:
            print(traceback.format_exc())

    def __initButton(self):
        import_button = self.addAction("Import")
        import_button.setIcon(base64ToQIcon(open_file_png))
        import_button.triggered.connect(ImportExportWindow.import_window.show)

        export_button = self.addAction("Export")
        export_button.setIcon(base64ToQIcon(save_file_png))
        export_button.triggered.connect(ImportExportWindow.export_window.show)

        run_button = self.addAction("Run")
        run_button.setIcon(base64ToQIcon(run_png))

        size = self.sizePolicy()
        size.setVerticalPolicy(QSizePolicy.Minimum)
        self.setSizePolicy(size)

        run_button.triggered.connect(self.__run)
        import_button.triggered.connect(self.__import)
        export_button.triggered.connect(self.__export)

    def __run(self):
        try:
            pass
        except Exception as e:
            print(traceback.format_exc())

    def __import(self):
        try:
            pass
        except Exception as e:
            print(traceback.format_exc())

    def __export(self):
        try:
            pass
        except Exception as e:
            print(traceback.format_exc())

    def __qss(self):
        self.setFixedHeight(35)
        font = self.font()
        font.setPointSize(11)
        self.setFont(font)
