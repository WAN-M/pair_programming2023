import traceback

from PyQt5.QtWidgets import QWidget, QVBoxLayout, QFrame, QSpacerItem, QSizePolicy, QLabel
from MyUIWidget.ParamWidget import ParamWidget
from MyUIWidget.APIWidget import APIWidget
from MyUIWidget.MiddelLabel import MiddleLabelWidget

def setMayParam(status):
    ControllerWindow.param_r.setStatus(status)
    ControllerWindow.param_h.setStatus(status)
    ControllerWindow.param_t.setStatus(status)
    ControllerWindow.param_j.setStatus(status)

def clearAPI():
    if ControllerWindow.api_chains_all.press:
        ControllerWindow.api_chains_all.changeIcon()
    if ControllerWindow.api_chain_char.press:
        ControllerWindow.api_chain_char.changeIcon()
    if ControllerWindow.api_chain_word.press:
        ControllerWindow.api_chain_word.changeIcon()
    # if ControllerWindow.api_chain_word_unique.press:
    #     ControllerWindow.api_chain_word_unique.changeIcon()

def clearParam():
    if ControllerWindow.param_n.press:
        ControllerWindow.param_n.changeIcon()
    if ControllerWindow.param_w.press:
        ControllerWindow.param_w.changeIcon()
    if ControllerWindow.param_c.press:
        ControllerWindow.param_c.changeIcon()

    setMayParam(True)

    if ControllerWindow.param_r.press:
        ControllerWindow.param_r.changeIcon()
    if ControllerWindow.param_h.press:
        ControllerWindow.param_h.changeIcon()
    if ControllerWindow.param_t.press:
        ControllerWindow.param_t.changeIcon()
    if ControllerWindow.param_j.press:
        ControllerWindow.param_j.changeIcon()


def paramN():
    if ControllerWindow.param_w.press:
        ControllerWindow.param_w.changeIcon()
    if ControllerWindow.param_c.press:
        ControllerWindow.param_c.changeIcon()
    clearAPI()
    if ControllerWindow.param_n.press:
        setMayParam(False)
    else:
        setMayParam(True)

def paramW():
    if ControllerWindow.param_n.press:
        ControllerWindow.param_n.changeIcon()
    if ControllerWindow.param_c.press:
        ControllerWindow.param_c.changeIcon()
    clearAPI()
    setMayParam(True)

def paramC():
    if ControllerWindow.param_n.press:
        ControllerWindow.param_n.changeIcon()
    if ControllerWindow.param_w.press:
        ControllerWindow.param_w.changeIcon()
    clearAPI()
    setMayParam(True)

def apiChainsAll():
    if ControllerWindow.api_chains_all.press:
        ControllerWindow.param_n.click()
        ControllerWindow.api_chains_all.changeIcon()
    else:
        ControllerWindow.param_n.click()

def apiChainWord():
    if ControllerWindow.api_chain_word.press:
        ControllerWindow.param_w.click()
        ControllerWindow.api_chain_word.changeIcon()
    else:
        ControllerWindow.param_w.click()

def apiChainChar():
    if ControllerWindow.api_chain_char.press:
        ControllerWindow.param_c.click()
        ControllerWindow.api_chain_char.changeIcon()
    else:
        ControllerWindow.param_c.click()

class ControllerWindow(QFrame):
    # must
    param_n = None
    param_w = None
    param_c = None
    # may
    param_r = None
    param_h = None
    param_t = None
    param_j = None
    # api
    api_chain_word = None
    api_chains_all = None
    # api_chain_word_unique = None
    api_chain_char = None

    def __init__(self):
        try:
            super(ControllerWindow, self).__init__()
            self.setObjectName("controller_window")
            self.__initUI()
            self.__qss()

        except Exception as e:
            print(traceback.format_exc())

    def __initUI(self):
        main_container = QVBoxLayout()
        main_container.setContentsMargins(0, 0, 0, 0) # 外边隙0
        # main_container.setSpacing(0) # 控件间间隙为0

        ########################################################################
        param_must = QFrame()
        param_must.setObjectName("param_must")
        param_must_layout = QVBoxLayout()
        param_must_layout.addWidget(MiddleLabelWidget("必选参数"))

        ControllerWindow.param_n = ParamWidget("-n 单词链个数")
        ControllerWindow.param_n.button.triggered.connect(paramN)
        ControllerWindow.param_w = ParamWidget("-w 最多单词数")
        ControllerWindow.param_w.button.triggered.connect(paramW)
        ControllerWindow.param_c = ParamWidget("-c 最多字母数")
        ControllerWindow.param_c.button.triggered.connect(paramC)

        param_must_layout.addWidget(ControllerWindow.param_n)
        param_must_layout.addWidget(ControllerWindow.param_w)
        param_must_layout.addWidget(ControllerWindow.param_c)

        param_must.setLayout(param_must_layout)

        main_container.addWidget(param_must)
        ######################################################################################
        param_may = QFrame()
        param_may_layout = QVBoxLayout()
        param_may_layout.addWidget(MiddleLabelWidget("可选参数"))

        ControllerWindow.param_r = ParamWidget("-r 允许单词环")
        ControllerWindow.param_r.button.triggered.connect(clearAPI)
        ControllerWindow.param_h = ParamWidget("-h 指定首字母", True)
        ControllerWindow.param_h.button.triggered.connect(clearAPI)
        ControllerWindow.param_t = ParamWidget("-t 指定尾字母", True)
        ControllerWindow.param_t.button.triggered.connect(clearAPI)
        ControllerWindow.param_j = ParamWidget("-j 禁用首字母", True)
        ControllerWindow.param_j.button.triggered.connect(clearAPI)

        param_may_layout.addWidget(ControllerWindow.param_r)
        param_may_layout.addWidget(ControllerWindow.param_h)
        param_may_layout.addWidget(ControllerWindow.param_t)
        param_may_layout.addWidget(ControllerWindow.param_j)

        param_may.setLayout(param_may_layout)

        main_container.addWidget(param_may)
        #######################################################################

        api_debug = QFrame()
        api_debug.setObjectName("api_debug")
        api_layout = QVBoxLayout()
        api_layout.addWidget(MiddleLabelWidget("直接测试指定接口"))

        ControllerWindow.api_chain_word = APIWidget('gen_chain_word')
        ControllerWindow.api_chain_word.button.triggered.connect(apiChainWord)
        ControllerWindow.api_chains_all = APIWidget('gen_chains_all')
        ControllerWindow.api_chains_all.button.triggered.connect(apiChainsAll)
        # ControllerWindow.api_chain_word_unique = APIWidget('gen_chain_word_unique')
        ControllerWindow.api_chain_char = APIWidget('gen_chain_char')
        ControllerWindow.api_chain_char.button.triggered.connect(apiChainChar)

        api_layout.addWidget(ControllerWindow.api_chains_all)
        api_layout.addWidget(ControllerWindow.api_chain_word)
        # api_layout.addWidget(ControllerWindow.api_chain_word_unique)
        api_layout.addWidget(ControllerWindow.api_chain_char)

        api_debug.setLayout(api_layout)

        main_container.addWidget(api_debug)
        #############################################################################
        main_container.addItem(QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Expanding))

        self.setLayout(main_container)

    def __qss(self):
        self.setFixedWidth(300)


