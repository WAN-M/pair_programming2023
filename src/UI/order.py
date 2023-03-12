import os

from MyUIWidget.LogWidget import LogWidget


class Order:
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
    head = "Wordlist.exe"
    txt = "ui.txt"
    def __init__(self):
        exe_path = './WordList.exe'
        dll_path = './WordList.dll'

        if os.path.exists(exe_path):
            self.model = 1
        elif os.path.exists(dll_path):
            self.model = 2
        else:
            self.model = 0

        self.input_path = ""


    def changeParam(self, key):
        if Order.order_dict[key][0]:
            Order.order_dict[key][0] = False
        else:
            Order.order_dict[key][0] = True

    def setText(self, key, text):
        Order.order_dict[key][1] = text

    def changeCmdText(self):
        text = Order.head
        for key in Order.order_dict.keys():
            if Order.order_dict[key][0]:
                text += " " + key + " " + Order.order_dict[key][1]
        text += " " + Order.txt
        LogWidget.cmd.setText(text)

order_instance = Order()
