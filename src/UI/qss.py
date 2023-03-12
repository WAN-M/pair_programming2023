qss="""
#main_back_ground, #import_export
{
    border:1px solid grey;
    background-color:rgb(66, 66, 66);
}
#import_export
{
    background-color:rgb(66, 66, 66);
}
/* log_text */
#log_text
{
    font-family: 'Microsoft YaHei';
    background-color: rgb(40, 40, 40);
    color: rgb(180, 180, 180);
    /*border: 1px solid rgb(10, 10, 10);*/
}
/* 超级背景板？ */
QAbstractScrollArea
{
    background-color: transparent;
}

/* 滚动条 */
QScrollBar::vertical
{
    margin: 0px 0px 0px 0px;
    background-color: transparent;
    width: 16px;
}

QScrollBar::horizontal
{
    margin: 0px 0px 0px 0px;
    background-color: transparent;
    height: 16px;
}

/* 滑块 */
QScrollBar::handle:vertical
{
    background-color: rgb(140, 140, 140);
    min-height: 8px;
    width: 16px;
}
QScrollBar::handle:horizontal
{
    background-color: rgb(140, 140, 140);
    min-height: 8px;
    height: 16px;
}

/* 未滑过的部分 */
QScrollBar::add-page:vertical
{
    background: transparent;
}
QScrollBar::add-page:horizontal
{
    background: transparent;
}
/* 已滑过的部分 */
QScrollBar::sub-page:vertical
{
    background: transparent;
}
QScrollBar::sub-page:horizontal
{
    background: transparent;
}
/* 上箭头 */
QScrollBar::up-arrow:vertical
{
    background: transparent;
}
QScrollBar::up-arrow:horizontal
{
    background: transparent;
}
/* 下箭头 */
QScrollBar::down-arrow:vertical
{
    background: transparent;
}
QScrollBar::down-arrow:horizontal
{
    background: transparent;
}
/* 滑块上箭头区域 */
QScrollBar::add-line:vertical
{
    background: transparent;
}
QScrollBar::add-line:horizontal
{
    background: transparent;
}
/* 滑块下箭头区域 */
QScrollBar::sub-line:vertical
{
    background: transparent;
}
QScrollBar::sub-line:horizontal
{
    background: transparent;
}
/* menu bar */
#right_menu_bar
{
    border-width: 1px;
    border-color: rgb(100, 100, 100);
    border-style: none none none none;
    background: transparent;
    color: rgb(220, 220, 220);
    padding: 2px;
}

#icon_bar, #icon_bar_2
{
    background: transparent;
    padding: 4px;
}

#run_bar
{

    border-width: 1px;
    border-color: rgb(100, 100, 100);
    border-style: solid none solid none;
    background: transparent;
    padding: 3px;
    
}

QToolButton
{
    font-family: 'Microsoft YaHei';
    border: none;
    background: transparent;
    color: rgb(220, 220, 220);
}

QToolButton:checked
{
    background-color: rgb(50, 50, 50);
}

QMenu
{
    background-color: rgb(66, 66, 66);
    color: rgb(220, 220, 220);
}

QMenu::item:selected
{
    background-color: rgb(75, 110, 174)
}

QToolButton:hover
{
    background-color: rgb(75, 110, 174)
}

#right_menu_bar::item, #icon_bar::item, #icon_bar_2::item
{
    background-color: rgb(66, 66, 66);
}

#run_bar::item:selected, #right_menu_bar::item:selected
{
    background-color: rgb(75, 110, 174);
}

QSplitter::handle
{
    background-color: transparent;
}

QLineEdit
{
    font-family: 'Microsoft YaHei';
    background-color: transparent;
    border: 2px solid rgb(100, 100, 100);
    color: rgb(220, 220, 220);
}

#input_box, #cmd
{
    font-family: 'Microsoft YaHei';
    background-color: rgb(40, 40, 40);
    color: rgb(180, 180, 180);
}

QTabWidget::pane
{
    font-family: 'Microsoft YaHei';
    background-color: transparent;
    border: 1px solid rgb(100, 100, 100);
    /*border: none;*/
}

QTabBar::tab
{
    font-family: 'Microsoft YaHei';
    background-color: transparent;
    color: rgb(220, 220, 220);
}

#text_window, #controller_window
{
    border: 1px solid rgb(100, 100, 100);
}


QTabBar::tab:selected
{
    background-color: rgb(140, 140, 140);
    color: rgb(220, 220, 220);
}

QListView
{
    background-color: rgb(40, 40, 40);
    border: none;
    color: rgb(180, 180, 180);
}

QTreeView::item:selected,
QListView::item:selected
{
    background-color: #112d43;
    color: rgb(180, 180, 180);
}

QTreeView::item:hover,
QListView::item:hover
{
    background-color: #1f3b51;
    color: rgb(180, 180, 180);
}

QPlainTextEdit
{
    font-family: 'Microsoft YaHei';
    background-color: rgb(40, 40, 40);
    color: rgb(180, 180, 180);
}

QTreeView
{
    background-color: rgb(40, 40, 40);
    color: rgb(180, 180, 180);
}

QTreeView::branch:has-children:!has-siblings:closed,
QTreeView::branch:closed:has-children:has-siblings
{
    border-image: none;
    image: url(':/icon/branch_closed.png');
}

QTreeView::branch:open:has-children:!has-siblings,
QTreeView::branch:open:has-children:has-siblings
{
    border-image: none;
    image: url(':/icon/branch_open.png');
}

QTreeView::branch:has-children:!has-siblings:closed:hover,
QTreeView::branch:closed:has-children:has-siblings:hover
{
    image: url(':/icon/branch_closed_focus.png');
}

QTreeView::branch:open:has-children:!has-siblings:hover,
QTreeView::branch:open:has-children:has-siblings:hover
{
    image: url(':/icon/branch_open_focus.png');
}

QLabel
{
    font-family: 'Microsoft YaHei';
    color: rgb(180, 180, 180);
}


QPushButton
{
    color: rgb(220, 220, 220);
    border: none;
    background: transparent;
    padding-left: 8px;
    padding-right: 8px;
    padding-bottom: 3px;
    padding-top: 3px;
    width: 150px;
    height: 25px;
}

QPushButton:hover
{
    background-color: rgb(100, 100, 100);
}

#ok_button
{
    font-family: 'Microsoft YaHei';
    color: rgb(220, 220, 220);
    border-radius: 5px;
    border: 2px solid rgb(180, 180, 180);
    background-color: #347eda;
    padding: 4px;
    width: 100px;
    height: 30px;
}

#ok_button:hover
{
    background-color: #1c7df5;
}

#cancel_button
{
    font-family: 'Microsoft YaHei';
    color: rgb(220, 220, 220);
    border-radius: 5px;
    border: 2px solid rgb(180, 180, 180);
    background-color: rgb(80, 80, 80);
    padding: 4px;
    width: 100px;
    height: 30px;
}

#cancel_button:hover
{
    background-color: rgb(100, 100, 100);
}

QTabBar::tab
{
    font-family: 'Microsoft YaHei';
    width: 180;
    height: 35;
}

QListView::item
{
    height: 30;
}

QTreeView::item
{
    height: 30;
}

#information_window
{
    background-color: rgb(50, 50, 50);
}

QTableView
{
    background: transparent;
    gridline-color: rgb(140, 140, 140);
    color: rgb(180, 180, 180);
}

QHeaderView::section
{
    background: transparent;
    color: rgb(180, 180, 180);
    border: 1px solid rgb(140, 140, 140);
    height: 35;
}

#controller_window
{
    border-width: 1px;
    border-color: rgb(100, 100, 100);
    border-style: solid solid solid solid;
}

#api_debug
{
    border-width: 1px;
    border-color: rgb(100, 100, 100);
    border-style: solid none none none;
}

QTableView
{
    outline: none;
}

"""
