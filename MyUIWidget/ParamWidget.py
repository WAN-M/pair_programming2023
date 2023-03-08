import traceback

from PyQt5.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QCheckBox, QLineEdit, QSpacerItem, QSizePolicy


class ParamWidget(QWidget):
    def __init__(self, name, need_text=False):
        try:
            super(ParamWidget, self).__init__()
            self.setObjectName(name)
            self.__initUI(need_text)

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self, need_text):
        main_container = QVBoxLayout()
        main_container.setContentsMargins(20, 0, 20, 0) # 外边隙0
        main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        # main_container.setSpacing(0) # 控件间间隙为0
        # main_container.

        check = QWidget()
        check_container = QHBoxLayout()
        check_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))

        self.label = QCheckBox(self.objectName())
        check_container.addWidget(self.label)

        check_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        check.setLayout(check_container)
        main_container.addWidget(check)

        if need_text:
            self.text = QLineEdit()
            main_container.addWidget(self.text)

        main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum))
        self.setLayout(main_container)
