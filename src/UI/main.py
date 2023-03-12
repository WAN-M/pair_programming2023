import sys
import traceback

from PyQt5.QtWidgets import QApplication

from MyUIWidget.ControllerWindow import ControllerWindow
from MyUIWidget.ImportExportWindow import ImportExportWindow
from MyUIWidget.MainWindow import MainWindow
from qss import qss
import qrc

def new_app():
    app = QApplication(sys.argv)

    # 双线程，UI线程+计算线程
    # 主线程为UI线程
    # cal = cpu_thread("cpu")
    # cal.setDaemon(True)
    # cal.start()
    ImportExportWindow.import_window = ImportExportWindow("import")
    ImportExportWindow.export_window = ImportExportWindow("export")
    # 初始化主窗口
    window = MainWindow()
    window.show()

    app.setStyleSheet(qss)
    # ControllerWindow.param_n.click()
    # 显示主窗口
    # window.showMaximized()

    app.exec()

if __name__ == '__main__':
    try:
        new_app()
    except Exception as e:
        print(traceback.format_exc())
