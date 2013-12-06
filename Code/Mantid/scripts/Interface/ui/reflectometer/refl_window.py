# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'D:\mantid\windows\Code\Mantid\scripts\Interface\ui\reflectometer/refl_window.ui'
#
# Created: Fri Dec 06 12:25:52 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_windowRefl(object):
    def setupUi(self, windowRefl):
        windowRefl.setObjectName(_fromUtf8("windowRefl"))
        windowRefl.resize(1000, 400)
        windowRefl.setAcceptDrops(True)
        self.widgetMainRow = QtGui.QWidget(windowRefl)
        self.widgetMainRow.setObjectName(_fromUtf8("widgetMainRow"))
        self.layoutMainRow = QtGui.QVBoxLayout(self.widgetMainRow)
        self.layoutMainRow.setMargin(9)
        self.layoutMainRow.setObjectName(_fromUtf8("layoutMainRow"))
        self.layoutTopRow = QtGui.QHBoxLayout()
        self.layoutTopRow.setSpacing(12)
        self.layoutTopRow.setObjectName(_fromUtf8("layoutTopRow"))
        self.comboInstrument = QtGui.QComboBox(self.widgetMainRow)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.comboInstrument.sizePolicy().hasHeightForWidth())
        self.comboInstrument.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.comboInstrument.setFont(font)
        self.comboInstrument.setObjectName(_fromUtf8("comboInstrument"))
        self.comboInstrument.addItem(_fromUtf8(""))
        self.comboInstrument.addItem(_fromUtf8(""))
        self.comboInstrument.addItem(_fromUtf8(""))
        self.comboInstrument.addItem(_fromUtf8(""))
        self.layoutTopRow.addWidget(self.comboInstrument)
        self.comboCycle = QtGui.QComboBox(self.widgetMainRow)
        self.comboCycle.setObjectName(_fromUtf8("comboCycle"))
        self.layoutTopRow.addWidget(self.comboCycle)
        self.labelRB = QtGui.QLabel(self.widgetMainRow)
        self.labelRB.setObjectName(_fromUtf8("labelRB"))
        self.layoutTopRow.addWidget(self.labelRB)
        self.textRB = QtGui.QLineEdit(self.widgetMainRow)
        self.textRB.setMaximumSize(QtCore.QSize(55, 16777215))
        self.textRB.setCursorPosition(0)
        self.textRB.setObjectName(_fromUtf8("textRB"))
        self.layoutTopRow.addWidget(self.textRB)
        self.labelRuns = QtGui.QLabel(self.widgetMainRow)
        self.labelRuns.setObjectName(_fromUtf8("labelRuns"))
        self.layoutTopRow.addWidget(self.labelRuns)
        self.textRuns = QtGui.QLineEdit(self.widgetMainRow)
        self.textRuns.setMaximumSize(QtCore.QSize(100, 16777215))
        self.textRuns.setObjectName(_fromUtf8("textRuns"))
        self.layoutTopRow.addWidget(self.textRuns)
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.layoutTopRow.addItem(spacerItem)
        self.labelPolarCorrect = QtGui.QLabel(self.widgetMainRow)
        self.labelPolarCorrect.setObjectName(_fromUtf8("labelPolarCorrect"))
        self.layoutTopRow.addWidget(self.labelPolarCorrect)
        self.comboPolarCorrect = QtGui.QComboBox(self.widgetMainRow)
        font = QtGui.QFont()
        font.setWeight(75)
        font.setBold(True)
        self.comboPolarCorrect.setFont(font)
        self.comboPolarCorrect.setObjectName(_fromUtf8("comboPolarCorrect"))
        self.comboPolarCorrect.addItem(_fromUtf8(""))
        self.comboPolarCorrect.addItem(_fromUtf8(""))
        self.comboPolarCorrect.addItem(_fromUtf8(""))
        self.comboPolarCorrect.addItem(_fromUtf8(""))
        self.layoutTopRow.addWidget(self.comboPolarCorrect)
        spacerItem1 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.layoutTopRow.addItem(spacerItem1)
        self.checkTickAll = QtGui.QCheckBox(self.widgetMainRow)
        self.checkTickAll.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.checkTickAll.setTristate(False)
        self.checkTickAll.setObjectName(_fromUtf8("checkTickAll"))
        self.layoutTopRow.addWidget(self.checkTickAll)
        spacerItem2 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.layoutTopRow.addItem(spacerItem2)
        self.buttonAuto = QtGui.QPushButton(self.widgetMainRow)
        self.buttonAuto.setObjectName(_fromUtf8("buttonAuto"))
        self.layoutTopRow.addWidget(self.buttonAuto)
        self.layoutMainRow.addLayout(self.layoutTopRow)
        self.layoutBottomRow = QtGui.QHBoxLayout()
        self.layoutBottomRow.setObjectName(_fromUtf8("layoutBottomRow"))
        self.listMain = QtGui.QListWidget(self.widgetMainRow)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.listMain.sizePolicy().hasHeightForWidth())
        self.listMain.setSizePolicy(sizePolicy)
        self.listMain.setMaximumSize(QtCore.QSize(200, 16777215))
        self.listMain.setSelectionMode(QtGui.QAbstractItemView.ExtendedSelection)
        self.listMain.setObjectName(_fromUtf8("listMain"))
        self.layoutBottomRow.addWidget(self.listMain)
        self.buttonTransfer = QtGui.QPushButton(self.widgetMainRow)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.buttonTransfer.sizePolicy().hasHeightForWidth())
        self.buttonTransfer.setSizePolicy(sizePolicy)
        self.buttonTransfer.setMaximumSize(QtCore.QSize(25, 16777215))
        self.buttonTransfer.setObjectName(_fromUtf8("buttonTransfer"))
        self.layoutBottomRow.addWidget(self.buttonTransfer)
        self.layoutTableColumn = QtGui.QVBoxLayout()
        self.layoutTableColumn.setObjectName(_fromUtf8("layoutTableColumn"))
        self.tableMain = QtGui.QTableWidget(self.widgetMainRow)
        font = QtGui.QFont()
        font.setWeight(50)
        font.setBold(False)
        self.tableMain.setFont(font)
        self.tableMain.setAlternatingRowColors(True)
        self.tableMain.setRowCount(100)
        self.tableMain.setColumnCount(18)
        self.tableMain.setObjectName(_fromUtf8("tableMain"))
        self.tableMain.setColumnCount(18)
        self.tableMain.setRowCount(100)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(0, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(1, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(2, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(3, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(4, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(5, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(6, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(7, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(8, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(9, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(10, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(11, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(12, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(13, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(14, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(15, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(16, item)
        item = QtGui.QTableWidgetItem()
        self.tableMain.setHorizontalHeaderItem(17, item)
        self.tableMain.horizontalHeader().setCascadingSectionResizes(True)
        self.tableMain.horizontalHeader().setDefaultSectionSize(60)
        self.tableMain.horizontalHeader().setMinimumSectionSize(20)
        self.tableMain.verticalHeader().setDefaultSectionSize(20)
        self.layoutTableColumn.addWidget(self.tableMain)
        self.layoutTableButton = QtGui.QHBoxLayout()
        self.layoutTableButton.setObjectName(_fromUtf8("layoutTableButton"))
        self.buttonProcess = QtGui.QPushButton(self.widgetMainRow)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.buttonProcess.sizePolicy().hasHeightForWidth())
        self.buttonProcess.setSizePolicy(sizePolicy)
        self.buttonProcess.setObjectName(_fromUtf8("buttonProcess"))
        self.layoutTableButton.addWidget(self.buttonProcess)
        self.buttonClear = QtGui.QPushButton(self.widgetMainRow)
        self.buttonClear.setObjectName(_fromUtf8("buttonClear"))
        self.layoutTableButton.addWidget(self.buttonClear)
        self.layoutTableColumn.addLayout(self.layoutTableButton)
        self.layoutBottomRow.addLayout(self.layoutTableColumn)
        self.layoutMainRow.addLayout(self.layoutBottomRow)
        windowRefl.setCentralWidget(self.widgetMainRow)
        self.menuBar = QtGui.QMenuBar(windowRefl)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 1000, 21))
        self.menuBar.setObjectName(_fromUtf8("menuBar"))
        self.menuFile = QtGui.QMenu(self.menuBar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        self.menuHelp = QtGui.QMenu(self.menuBar)
        self.menuHelp.setObjectName(_fromUtf8("menuHelp"))
        windowRefl.setMenuBar(self.menuBar)
        self.actionSave_Table = QtGui.QAction(windowRefl)
        self.actionSave_Table.setObjectName(_fromUtf8("actionSave_Table"))
        self.actionLoad_Table = QtGui.QAction(windowRefl)
        self.actionLoad_Table.setObjectName(_fromUtf8("actionLoad_Table"))
        self.actionRe_Load_Table = QtGui.QAction(windowRefl)
        self.actionRe_Load_Table.setObjectName(_fromUtf8("actionRe_Load_Table"))
        self.actionSave_Workspaces = QtGui.QAction(windowRefl)
        self.actionSave_Workspaces.setObjectName(_fromUtf8("actionSave_Workspaces"))
        self.actionMantid_Help = QtGui.QAction(windowRefl)
        self.actionMantid_Help.setObjectName(_fromUtf8("actionMantid_Help"))
        self.menuFile.addAction(self.actionSave_Table)
        self.menuFile.addAction(self.actionLoad_Table)
        self.menuFile.addAction(self.actionRe_Load_Table)
        self.menuFile.addAction(self.actionSave_Workspaces)
        self.menuHelp.addAction(self.actionMantid_Help)
        self.menuBar.addAction(self.menuFile.menuAction())
        self.menuBar.addAction(self.menuHelp.menuAction())

        self.retranslateUi(windowRefl)
        QtCore.QMetaObject.connectSlotsByName(windowRefl)

    def retranslateUi(self, windowRefl):
        windowRefl.setWindowTitle(QtGui.QApplication.translate("windowRefl", "ISIS Reflectometry", None, QtGui.QApplication.UnicodeUTF8))
        self.comboInstrument.setItemText(0, QtGui.QApplication.translate("windowRefl", "Inter", None, QtGui.QApplication.UnicodeUTF8))
        self.comboInstrument.setItemText(1, QtGui.QApplication.translate("windowRefl", "SURF", None, QtGui.QApplication.UnicodeUTF8))
        self.comboInstrument.setItemText(2, QtGui.QApplication.translate("windowRefl", "CRISP", None, QtGui.QApplication.UnicodeUTF8))
        self.comboInstrument.setItemText(3, QtGui.QApplication.translate("windowRefl", "PolRef", None, QtGui.QApplication.UnicodeUTF8))
        self.labelRB.setText(QtGui.QApplication.translate("windowRefl", "RB:", None, QtGui.QApplication.UnicodeUTF8))
        self.labelRuns.setText(QtGui.QApplication.translate("windowRefl", "Transmission run(s):", None, QtGui.QApplication.UnicodeUTF8))
        self.labelPolarCorrect.setText(QtGui.QApplication.translate("windowRefl", "Polarisation corrections", None, QtGui.QApplication.UnicodeUTF8))
        self.comboPolarCorrect.setItemText(0, QtGui.QApplication.translate("windowRefl", "None", None, QtGui.QApplication.UnicodeUTF8))
        self.comboPolarCorrect.setItemText(1, QtGui.QApplication.translate("windowRefl", "1-PNR", None, QtGui.QApplication.UnicodeUTF8))
        self.comboPolarCorrect.setItemText(2, QtGui.QApplication.translate("windowRefl", "2-PA", None, QtGui.QApplication.UnicodeUTF8))
        self.comboPolarCorrect.setItemText(3, QtGui.QApplication.translate("windowRefl", "3-Other", None, QtGui.QApplication.UnicodeUTF8))
        self.checkTickAll.setText(QtGui.QApplication.translate("windowRefl", "(un)tick all", None, QtGui.QApplication.UnicodeUTF8))
        self.buttonAuto.setText(QtGui.QApplication.translate("windowRefl", "AutoFill", None, QtGui.QApplication.UnicodeUTF8))
        self.buttonTransfer.setText(QtGui.QApplication.translate("windowRefl", "=>", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(0).setText(QtGui.QApplication.translate("windowRefl", "Run(s)", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(1).setText(QtGui.QApplication.translate("windowRefl", "Angle 1", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(2).setText(QtGui.QApplication.translate("windowRefl", "trans 1", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(3).setText(QtGui.QApplication.translate("windowRefl", "qmin_1", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(4).setText(QtGui.QApplication.translate("windowRefl", "qmax_1", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(5).setText(QtGui.QApplication.translate("windowRefl", "Run(s)", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(6).setText(QtGui.QApplication.translate("windowRefl", "Angle 2", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(7).setText(QtGui.QApplication.translate("windowRefl", "trans 2", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(8).setText(QtGui.QApplication.translate("windowRefl", "qmin_2", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(9).setText(QtGui.QApplication.translate("windowRefl", "qmax_2", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(10).setText(QtGui.QApplication.translate("windowRefl", "Run(s)", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(11).setText(QtGui.QApplication.translate("windowRefl", "Angle 3", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(12).setText(QtGui.QApplication.translate("windowRefl", "trans 3", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(13).setText(QtGui.QApplication.translate("windowRefl", "qmin_3", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(14).setText(QtGui.QApplication.translate("windowRefl", "qmax_3", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(15).setText(QtGui.QApplication.translate("windowRefl", "dq/q", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(16).setText(QtGui.QApplication.translate("windowRefl", "Scale", None, QtGui.QApplication.UnicodeUTF8))
        self.tableMain.horizontalHeaderItem(17).setText(QtGui.QApplication.translate("windowRefl", "Stitch?", None, QtGui.QApplication.UnicodeUTF8))
        self.buttonProcess.setText(QtGui.QApplication.translate("windowRefl", "Process", None, QtGui.QApplication.UnicodeUTF8))
        self.buttonClear.setText(QtGui.QApplication.translate("windowRefl", "Clear all", None, QtGui.QApplication.UnicodeUTF8))
        self.menuFile.setTitle(QtGui.QApplication.translate("windowRefl", "File", None, QtGui.QApplication.UnicodeUTF8))
        self.menuHelp.setTitle(QtGui.QApplication.translate("windowRefl", "Help", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave_Table.setText(QtGui.QApplication.translate("windowRefl", "Save Table", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave_Table.setShortcut(QtGui.QApplication.translate("windowRefl", "Ctrl+S", None, QtGui.QApplication.UnicodeUTF8))
        self.actionLoad_Table.setText(QtGui.QApplication.translate("windowRefl", "Load Table", None, QtGui.QApplication.UnicodeUTF8))
        self.actionLoad_Table.setShortcut(QtGui.QApplication.translate("windowRefl", "Ctrl+O", None, QtGui.QApplication.UnicodeUTF8))
        self.actionRe_Load_Table.setText(QtGui.QApplication.translate("windowRefl", "Re-Load Table", None, QtGui.QApplication.UnicodeUTF8))
        self.actionRe_Load_Table.setShortcut(QtGui.QApplication.translate("windowRefl", "Ctrl+R", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave_Workspaces.setText(QtGui.QApplication.translate("windowRefl", "Save Workspaces", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave_Workspaces.setShortcut(QtGui.QApplication.translate("windowRefl", "Ctrl+Shift+S", None, QtGui.QApplication.UnicodeUTF8))
        self.actionMantid_Help.setText(QtGui.QApplication.translate("windowRefl", "Mantid Help", None, QtGui.QApplication.UnicodeUTF8))
        self.actionMantid_Help.setShortcut(QtGui.QApplication.translate("windowRefl", "Ctrl+H", None, QtGui.QApplication.UnicodeUTF8))

