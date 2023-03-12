import traceback

from PyQt5.QtCore import QRect, Qt
from PyQt5.QtGui import QFont, QColor, QPainter
from PyQt5.QtWidgets import QWidget

class NumberBar(QWidget):
    def __init__(self, editor):
        try:
            QWidget.__init__(self, editor)
            self.editor = editor
            # 当块数发生变化时调整宽度
            self.editor.blockCountChanged.connect(self.updateWidth)
            # 当文字滚动时进行调整，显示行号
            self.editor.updateRequest.connect(self.updateContents)
            # 设置字体颜色
            self.font = QFont('Microsoft YaHei', 14)
            self.__number_bar_color = QColor(55, 55, 55)

            # print("sss")

        except Exception as e:
            print(traceback.format_exc())

    def updateWidth(self):
        try:
            width = self.getWidth()
            # 变更宽度
            self.editor.setViewportMargins(width, 0, 0, 0)
        except Exception as e:
            print(traceback.format_exc())

    def getWidth(self):
        # 只有行数过多了才会加宽number bar
        count = self.editor.blockCount()
        if 0 <= count < 99999:
            width = self.fontMetrics().width('99999')
        else:
            width = self.fontMetrics().width(str(count))
        return width

    def updateContents(self, rect, dy):
        try:
            if dy:
                # 如果是垂直滚动，且像素dy > 0，则小部件向下滚动
                self.scroll(0, dy)
            else:
                # 否则更新小部件内的矩形
                self.update(0, rect.y(), self.width(), rect.height())
            # 判断编辑器视口的矩形是否在这个矩形中
            if rect.contains(self.editor.viewport().rect()):
                fontSize = self.editor.currentCharFormat().font().pointSize()
                self.font.setPointSize(fontSize)
                self.font.setStyle(QFont.StyleNormal)
                self.updateWidth()
        except Exception as e:
            print(traceback.format_exc())

    def paintEvent(self, event):
        try:
            # 在repaint或者update时被调用
            # 用指定颜色填充给定的矩形
            painter = QPainter(self)
            painter.fillRect(event.rect(), self.__number_bar_color)

            # 返回第一个文本块
            block = self.editor.firstVisibleBlock()
            # print("Sssssss")
            # 文本块有效时循环
            while block.isValid():
                try:
                    block_number = block.blockNumber()
                    # 当鼠标选择某行时，行号变粗加黑
                    block_top = self.editor.blockBoundingGeometry(block).translated(self.editor.contentOffset()).top()
                    paint_rect = QRect(0, block_top, self.width(), self.editor.fontMetrics().height())

                    if block_number == self.editor.textCursor().blockNumber():
                        self.font.setBold(True)
                        painter.setPen(QColor(180, 180, 180))
                    else:
                        self.font.setBold(False)
                        painter.setPen(QColor(120, 120, 120))

                    painter.drawText(paint_rect, Qt.AlignCenter, str(block_number + 1))
                    block = block.next()
                    # print(block_number)
                except Exception as e:
                    print(traceback.format_exc())

        except Exception as e:
            print(traceback.format_exc())
