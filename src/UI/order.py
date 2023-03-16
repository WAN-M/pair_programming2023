import os
import traceback
import time

from PyQt5.QtCore import QDir

from MyUIWidget.LogWidget import LogWidget
from MyUIWidget.EditorWidget import EditorWidget

def checkPath():
    model = 0
    try:
        # exe_path = QDir.currentPath() + '/WordList.exe'
        # dll_path = QDir.currentPath() + '/WordList.dll'
        exe_path = os.path.dirname(os.path.realpath(__file__)) + '/WordList.exe'
        dll_path = os.path.dirname(os.path.realpath(__file__)) + '/WordList.dll'
        if os.path.exists(exe_path):
            model = 1
        elif os.path.exists(dll_path):
            model = 2
    except:
        pass
    return model

class Order:
    head = "Wordlist.exe"
    txt = "ui.txt"
    order_dict = {
        '-n':[False, ""],
        '-w':[False, ""],
        '-c':[False, ""],
        '-r':[False, ""],
        '-h':[False, ""],
        '-t':[False, ""],
        '-j':[False, ""],
    }
    api_dict = {
        'chain_word':False,
        'chains_all':False,
        'chain_word_unique':False,
        'chain_char':False,
    }

    def __init__(self):
        self.input_path = ""
        self.model = 0

    def changeParam(self, key, status):
        Order.order_dict[key][0] = status

    def setText(self, key, text):
        Order.order_dict[key][1] = text

    def changeCmdText(self):
        text = Order.head
        # for key in Order.order_dict.keys():
        #     if Order.order_dict[key][0]:
        #         text += " " + key + " " + Order.order_dict[key][1]

        if Order.order_dict['-n'][0]:
            text += " " + '-n'
        elif Order.order_dict['-w'][0] or Order.order_dict['-c'][0]:
            for key in Order.order_dict.keys():
                if Order.order_dict[key][0]:
                    text += " " + key + " " + Order.order_dict[key][1]
        else:
            text = '未选择必选参数'
            LogWidget.cmd.setText(text)
            return
        text += " " + Order.txt
        LogWidget.cmd.setText(text)

    def run(self):
        try:
            text = EditorWidget.input_text.getText()
            if len(LogWidget.cmd.text()) < 2 or LogWidget.cmd.text() == '未选择必选参数':
                LogWidget.log_text.setText('参数不足')
                return
            with open(Order.txt, "w") as f:
                f.write(text)
            try:
                model = checkPath()
                if model == 1:
                    t1 = time.time()
                    res = os.popen(LogWidget.cmd.text(), "r").read()
                    # print(res)
                    t2 = time.time()
                    EditorWidget.output_text.setText(res)
                    LogWidget.log_text.setText('程序运行时间:%s秒' % (round(t2 - t1, 2)))
                else:
                    pass
                    LogWidget.log_text.setText(os.path.dirname(os.path.realpath(__file__)))
            except Exception as e:
                pass
                LogWidget.log_text.setText(traceback.format_exc())
        except Exception as e:
            print(e)
            pass
            LogWidget.log_text.setText(traceback.format_exc())

order_instance = Order()
