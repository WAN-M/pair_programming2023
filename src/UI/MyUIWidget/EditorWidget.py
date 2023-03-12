import traceback

from PyQt5.QtWidgets import QTabWidget
from MyUIWidget.Editor import Editor

class EditorWidget(QTabWidget):
    input_text = None
    output_text = None
    def __init__(self, name):
        try:
            super(EditorWidget, self).__init__()
            self.setObjectName(name)

            if name == 'input':
                EditorWidget.input_text = self
            elif name == 'output':
                EditorWidget.output_text = self

            self.__initUI()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        self.editor = Editor()
        self.addTab(self.editor, self.objectName())

    def setText(self, text):
        self.editor.setPlainText(text)

    def getText(self):
        return self.editor.toPlainText()
