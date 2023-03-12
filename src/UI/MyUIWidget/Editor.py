import traceback

from PyQt5.QtCore import QRect
from PyQt5.QtGui import QFont, QColor, QTextFormat
from PyQt5.QtWidgets import QPlainTextEdit, QTextEdit

from MyUIWidget.NumberBar import NumberBar

class Editor(QPlainTextEdit):
    # def __init__(self):
    #     super(Editor, self).__init__()
    def __init__(self):
        try:
            super(Editor, self).__init__()
            # 文本字体
            self.setFont(QFont("Microsoft YaHei", 14))
            # # 不允许过长换行
            # self.setLineWrapMode(QPlainTextEdit.)

            self.number_bar = NumberBar(self)
            self.__current_line_number = None

            # 所选行高亮
            self.cursorPositionChanged.connect(self.__highligtCurrentLine)
            # 防止text怼进number bar
            self.setViewportMargins(self.number_bar.getWidth(), 0, 0, 0)
            # 默认标记第一行
            self.__highligtCurrentLine()

        except Exception as e:
            print(traceback.format_exc())

    # 重写方法
    def resizeEvent(self, *e):
        try:
            cr = self.contentsRect()
            rec = QRect(cr.left(), cr.top(), self.number_bar.getWidth(), cr.height())
            # rec = QRect(cr.left(), cr.top(), self.number_bar.getWidth(), cr.height())
            self.number_bar.setGeometry(rec)

        except Exception as e:
            print(traceback.format_exc())

    def __highligtCurrentLine(self):
        try:
            # 返回光标所在的块编号
            new_current_line_number = self.textCursor().blockNumber()
            if new_current_line_number != self.__current_line_number:
                line_color = QColor(54, 146, 185).lighter(80)
                self.__current_line_number = new_current_line_number
                # 为文档中已选择的字符指定格式
                selection = QTextEdit.ExtraSelection()
                # 设定背景颜色
                selection.format.setBackground(line_color)
                # 设定文本的整个宽度为显示状态
                selection.format.setProperty(QTextFormat.FullWidthSelection, True)
                # 锚点设置为光标所在位置并清楚当前选择
                selection.cursor = self.textCursor()
                selection.cursor.clearSelection()
                # 运行用指定的颜色临时标记文档中的某些区域，并制定为选项
                self.setExtraSelections([selection])

        except Exception as e:
            print(traceback.format_exc())
