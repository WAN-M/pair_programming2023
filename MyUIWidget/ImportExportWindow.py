import os
import traceback
from os.path import isdir, exists, dirname
from os import mkdir, rename

from PyQt5.QtCore import Qt, QPoint
from PyQt5.QtGui import QMouseEvent, QFont, QCursor
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLabel, QHBoxLayout, QPushButton, QLineEdit, QTreeView, QSpacerItem, \
    QSizePolicy, QFileSystemModel, QMenuBar, QFrame

from resources import main_png, new_folder_png, rename_folder_png
from tools import base64ToQIcon

class ImportExportWindow(QFrame):
    import_window = None
    export_window = None

    def __init__(self, label):
        try:
            super(ImportExportWindow, self).__init__()
            self.setObjectName("import_export")
            self.label = label
            self.__init_ui()
            self.__init_tree()
            self.setWindowModality(Qt.ApplicationModal)



            if label == "import":
                self.ok_button.clicked.connect(self.open_project)
            elif label == "export":
                self.ok_button.clicked.connect(self.save_project)

            self.__qss()
        except Exception as e:
            print(traceback.format_exc())

    def __init_ui(self):
        # 垂直布局
        main_container = QVBoxLayout()

        title_widget = QWidget()

        title_container = QHBoxLayout()
        title_container.setContentsMargins(0, 0, 0, 0)  # 外边隙0
        title_container.setSpacing(0)  # 控件间间隙为0

        icon_bar = QMenuBar()
        icon_bar.setObjectName("icon_bar_2")
        size = icon_bar.sizePolicy()
        size.setHorizontalPolicy(QSizePolicy.Minimum)
        size.setVerticalPolicy(QSizePolicy.Minimum)
        icon_bar.setSizePolicy(size)
        icon = icon_bar.addAction("icon")
        icon.setIcon(base64ToQIcon(main_png))
        title_container.addWidget(icon_bar)

        title = QLabel()
        title.setText(self.label)
        title.setFont(QFont("Microsoft YaHei", 12))
        title_container.addWidget(title)

        spacer = QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)
        title_container.addItem(spacer)

        title_widget.setLayout(title_container)
        main_container.addWidget(title_widget)

        self.path_text = QLineEdit()
        main_container.addWidget(self.path_text)

        self.directory_tree = QTreeView()
        self.directory_tree.setFont(QFont("Microsoft YaHei", 10))
        self.directory_tree.clicked.connect(self.show_path)
        main_container.addWidget(self.directory_tree)

        confirm_widget = QWidget()
        confirm_container = QHBoxLayout()

        left_spacer = QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)
        confirm_container.addItem(left_spacer)

        self.ok_button = QPushButton()
        self.ok_button.setText("OK")
        self.ok_button.setFont(QFont("Microsoft YaHei", 11))
        self.ok_button.setObjectName("ok_button")
        confirm_container.addWidget(self.ok_button)

        cancel_button = QPushButton()
        cancel_button.setText("Cancel")
        cancel_button.setFont(QFont("Microsoft YaHei", 11))
        cancel_button.clicked.connect(self.close)
        cancel_button.setObjectName("cancel_button")
        confirm_container.addWidget(cancel_button)

        confirm_widget.setLayout(confirm_container)
        main_container.addWidget(confirm_widget)

        self.setLayout(main_container)

    def __init_tree(self):
        self.tree_model = QFileSystemModel()
        self.tree_model.setRootPath('')
        self.directory_tree.setModel(self.tree_model)
        self.directory_tree.setHeaderHidden(True)
        self.directory_tree.setRootIndex(self.tree_model.index(''))
        for col in range(1, 4):
            self.directory_tree.setColumnHidden(col, True)

    def show_path(self, Qmodelidx):
        try:
            #获取单击后的指定路径
            filePath = self.tree_model.filePath(Qmodelidx)
            #判断拿到的文件是文件夹还是文件，Flase为文件，True为文件夹
            if isdir(filePath):
                self.path_text.setText(filePath)
                self.old_directory = filePath
            else:
                self.file = filePath
        except Exception as e:
            print(traceback.format_exc())

    def make_dir(self):
        try:
            path = self.path_text.text()
            if isdir(path):
                directory = path + "/Project"
                i = 0
                while exists(directory + str(i)):
                    i += 1
                mkdir(directory + str(i))
            else:
                mkdir(path)
        except Exception as e:
            print(traceback.format_exc())

    def open_project(self):
        try:
            pass
        except Exception as e:
            print(traceback.format_exc())

    def refresh_tree(self):
        try:
            pass
            # if Plate.project_directory_path is not None and os.path.isdir(Plate.project_directory_path):
            #     self.path_text.setText(Plate.project_directory_path + "/code0.txt")
            #     self.tree_model.setRootPath(Plate.project_directory_path)
            #     self.directory_tree.setRootIndex(self.tree_model.index(Plate.project_directory_path))
            # else:
            #     self.path_text.setText("C:/code0.txt")
        except Exception as e:
            print(traceback.format_exc())

    def save_project(self):
        try:
            pass
            # path = self.path_text.text()
            # if isdir(path):
            #     Plate.project_directory_path = path
            #     path += "/project.cpu"
            #     Plate.project_path = path
            #     save_project_data(path)
            #     Plate.plate.refresh_project_tree.emit(Plate.project_directory_path)
            #     self.close()
            # elif path.endswith(Plate.project_ends):
            #     Plate.project_directory_path = dirname(path)
            #     Plate.project_path = path
            #     save_project_data(path)
            #     Plate.plate.refresh_project_tree.emit(Plate.project_directory_path)
            #     self.close()
        except Exception as e:
            print(traceback.format_exc())

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

    def __qss(self):
        self.resize(600, 600)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.directory_tree.setFocusPolicy(Qt.NoFocus)
        self.path_text.setFixedHeight(35)
        font = self.path_text.font()
        font.setPointSize(10)
        self.path_text.setFont(font)
