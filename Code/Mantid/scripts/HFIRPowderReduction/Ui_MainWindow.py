# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Ui_MainWindow.ui'
#
# Created: Mon Mar 16 15:24:34 2015
#      by: PyQt4 UI code generator 4.11.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

from MplFigureCanvas import *

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(1124, 1024)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.gridLayout = QtGui.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.verticalLayout = QtGui.QVBoxLayout()
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label_expNo = QtGui.QLabel(self.centralwidget)
        self.label_expNo.setObjectName(_fromUtf8("label_expNo"))
        self.horizontalLayout.addWidget(self.label_expNo)
        self.lineEdit_expNo = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_expNo.setObjectName(_fromUtf8("lineEdit_expNo"))
        self.horizontalLayout.addWidget(self.lineEdit_expNo)
        self.label_scanNo = QtGui.QLabel(self.centralwidget)
        self.label_scanNo.setObjectName(_fromUtf8("label_scanNo"))
        self.horizontalLayout.addWidget(self.label_scanNo)
        self.lineEdit_scanNo = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_scanNo.setObjectName(_fromUtf8("lineEdit_scanNo"))
        self.horizontalLayout.addWidget(self.lineEdit_scanNo)
        self.pushButton_loadData = QtGui.QPushButton(self.centralwidget)
        self.pushButton_loadData.setObjectName(_fromUtf8("pushButton_loadData"))
        self.horizontalLayout.addWidget(self.pushButton_loadData)
        self.label_calibration = QtGui.QLabel(self.centralwidget)
        self.label_calibration.setObjectName(_fromUtf8("label_calibration"))
        self.horizontalLayout.addWidget(self.label_calibration)
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.tabWidget = QtGui.QTabWidget(self.centralwidget)
        self.tabWidget.setObjectName(_fromUtf8("tabWidget"))
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName(_fromUtf8("tab_3"))
        self.gridLayout_4 = QtGui.QGridLayout(self.tab_3)
        self.gridLayout_4.setObjectName(_fromUtf8("gridLayout_4"))
        self.verticalLayout_7 = QtGui.QVBoxLayout()
        self.verticalLayout_7.setObjectName(_fromUtf8("verticalLayout_7"))
        self.horizontalLayout_13 = QtGui.QHBoxLayout()
        self.horizontalLayout_13.setObjectName(_fromUtf8("horizontalLayout_13"))
        self.label_ptNo = QtGui.QLabel(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_ptNo.sizePolicy().hasHeightForWidth())
        self.label_ptNo.setSizePolicy(sizePolicy)
        self.label_ptNo.setMinimumSize(QtCore.QSize(50, 0))
        self.label_ptNo.setObjectName(_fromUtf8("label_ptNo"))
        self.horizontalLayout_13.addWidget(self.label_ptNo)
        self.lineEdit_ptNo = QtGui.QLineEdit(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_ptNo.sizePolicy().hasHeightForWidth())
        self.lineEdit_ptNo.setSizePolicy(sizePolicy)
        self.lineEdit_ptNo.setObjectName(_fromUtf8("lineEdit_ptNo"))
        self.horizontalLayout_13.addWidget(self.lineEdit_ptNo)
        spacerItem1 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_13.addItem(spacerItem1)
        self.label_detNo = QtGui.QLabel(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_detNo.sizePolicy().hasHeightForWidth())
        self.label_detNo.setSizePolicy(sizePolicy)
        self.label_detNo.setMinimumSize(QtCore.QSize(50, 0))
        self.label_detNo.setObjectName(_fromUtf8("label_detNo"))
        self.horizontalLayout_13.addWidget(self.label_detNo)
        self.lineEdit_detNo = QtGui.QLineEdit(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_detNo.sizePolicy().hasHeightForWidth())
        self.lineEdit_detNo.setSizePolicy(sizePolicy)
        self.lineEdit_detNo.setObjectName(_fromUtf8("lineEdit_detNo"))
        self.horizontalLayout_13.addWidget(self.lineEdit_detNo)
        spacerItem2 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_13.addItem(spacerItem2)
        self.verticalLayout_7.addLayout(self.horizontalLayout_13)
        self.horizontalLayout_14 = QtGui.QHBoxLayout()
        self.horizontalLayout_14.setObjectName(_fromUtf8("horizontalLayout_14"))
        #self.graphicsView_Raw = QtGui.QGraphicsView(self.tab_3)
        self.graphicsView_Raw = Qt4MplCanvas(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.graphicsView_Raw.sizePolicy().hasHeightForWidth())
        self.graphicsView_Raw.setSizePolicy(sizePolicy)
        self.graphicsView_Raw.setObjectName(_fromUtf8("graphicsView_Raw"))
        self.horizontalLayout_14.addWidget(self.graphicsView_Raw)
        self.verticalLayout_9 = QtGui.QVBoxLayout()
        self.verticalLayout_9.setObjectName(_fromUtf8("verticalLayout_9"))
        self.pushButton_plotRaw = QtGui.QPushButton(self.tab_3)
        self.pushButton_plotRaw.setObjectName(_fromUtf8("pushButton_plotRaw"))
        self.verticalLayout_9.addWidget(self.pushButton_plotRaw)
        spacerItem3 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred)
        self.verticalLayout_9.addItem(spacerItem3)
        self.pushButton_ptUp = QtGui.QPushButton(self.tab_3)
        self.pushButton_ptUp.setObjectName(_fromUtf8("pushButton_ptUp"))
        self.verticalLayout_9.addWidget(self.pushButton_ptUp)
        self.pushButton_ptDown = QtGui.QPushButton(self.tab_3)
        self.pushButton_ptDown.setObjectName(_fromUtf8("pushButton_ptDown"))
        self.verticalLayout_9.addWidget(self.pushButton_ptDown)
        spacerItem4 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred)
        self.verticalLayout_9.addItem(spacerItem4)
        self.pushButton_detUp = QtGui.QPushButton(self.tab_3)
        self.pushButton_detUp.setObjectName(_fromUtf8("pushButton_detUp"))
        self.verticalLayout_9.addWidget(self.pushButton_detUp)
        self.pushButton_detDown = QtGui.QPushButton(self.tab_3)
        self.pushButton_detDown.setObjectName(_fromUtf8("pushButton_detDown"))
        self.verticalLayout_9.addWidget(self.pushButton_detDown)
        self.horizontalLayout_14.addLayout(self.verticalLayout_9)
        self.verticalLayout_7.addLayout(self.horizontalLayout_14)
        self.horizontalLayout_12 = QtGui.QHBoxLayout()
        self.horizontalLayout_12.setObjectName(_fromUtf8("horizontalLayout_12"))
        self.textBrowser_RawDetInfo = QtGui.QTextBrowser(self.tab_3)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.textBrowser_RawDetInfo.sizePolicy().hasHeightForWidth())
        self.textBrowser_RawDetInfo.setSizePolicy(sizePolicy)
        self.textBrowser_RawDetInfo.setObjectName(_fromUtf8("textBrowser_RawDetInfo"))
        self.horizontalLayout_12.addWidget(self.textBrowser_RawDetInfo)
        self.verticalLayout_7.addLayout(self.horizontalLayout_12)
        self.gridLayout_4.addLayout(self.verticalLayout_7, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab_3, _fromUtf8(""))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.gridLayout_2 = QtGui.QGridLayout(self.tab)
        self.gridLayout_2.setObjectName(_fromUtf8("gridLayout_2"))
        self.verticalLayout_2 = QtGui.QVBoxLayout()
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.horizontalLayout_3 = QtGui.QHBoxLayout()
        self.horizontalLayout_3.setObjectName(_fromUtf8("horizontalLayout_3"))
        self.label_normalizeMonitor = QtGui.QLabel(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_normalizeMonitor.sizePolicy().hasHeightForWidth())
        self.label_normalizeMonitor.setSizePolicy(sizePolicy)
        self.label_normalizeMonitor.setMinimumSize(QtCore.QSize(155, 0))
        self.label_normalizeMonitor.setObjectName(_fromUtf8("label_normalizeMonitor"))
        self.horizontalLayout_3.addWidget(self.label_normalizeMonitor)
        self.lineEdit_normalizeMonitor = QtGui.QLineEdit(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_normalizeMonitor.sizePolicy().hasHeightForWidth())
        self.lineEdit_normalizeMonitor.setSizePolicy(sizePolicy)
        self.lineEdit_normalizeMonitor.setMinimumSize(QtCore.QSize(300, 0))
        self.lineEdit_normalizeMonitor.setObjectName(_fromUtf8("lineEdit_normalizeMonitor"))
        self.horizontalLayout_3.addWidget(self.lineEdit_normalizeMonitor)
        spacerItem5 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem5)
        self.label_outputFormat = QtGui.QLabel(self.tab)
        self.label_outputFormat.setObjectName(_fromUtf8("label_outputFormat"))
        self.horizontalLayout_3.addWidget(self.label_outputFormat)
        self.comboBox_outputFormat = QtGui.QComboBox(self.tab)
        self.comboBox_outputFormat.setObjectName(_fromUtf8("comboBox_outputFormat"))
        self.horizontalLayout_3.addWidget(self.comboBox_outputFormat)
        self.lineEdit_outputFileName = QtGui.QLineEdit(self.tab)
        self.lineEdit_outputFileName.setObjectName(_fromUtf8("lineEdit_outputFileName"))
        self.horizontalLayout_3.addWidget(self.lineEdit_outputFileName)
        self.pushButton_saveData = QtGui.QPushButton(self.tab)
        self.pushButton_saveData.setObjectName(_fromUtf8("pushButton_saveData"))
        self.horizontalLayout_3.addWidget(self.pushButton_saveData)
        spacerItem6 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem6)
        self.verticalLayout_2.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_6 = QtGui.QHBoxLayout()
        self.horizontalLayout_6.setObjectName(_fromUtf8("horizontalLayout_6"))
        self.label_detExcluded = QtGui.QLabel(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_detExcluded.sizePolicy().hasHeightForWidth())
        self.label_detExcluded.setSizePolicy(sizePolicy)
        self.label_detExcluded.setMinimumSize(QtCore.QSize(155, 0))
        self.label_detExcluded.setObjectName(_fromUtf8("label_detExcluded"))
        self.horizontalLayout_6.addWidget(self.label_detExcluded)
        self.lineEdit_detExcluded = QtGui.QLineEdit(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_detExcluded.sizePolicy().hasHeightForWidth())
        self.lineEdit_detExcluded.setSizePolicy(sizePolicy)
        self.lineEdit_detExcluded.setMinimumSize(QtCore.QSize(300, 0))
        self.lineEdit_detExcluded.setObjectName(_fromUtf8("lineEdit_detExcluded"))
        self.horizontalLayout_6.addWidget(self.lineEdit_detExcluded)
        spacerItem7 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_6.addItem(spacerItem7)
        self.label_wavelength = QtGui.QLabel(self.tab)
        self.label_wavelength.setObjectName(_fromUtf8("label_wavelength"))
        self.horizontalLayout_6.addWidget(self.label_wavelength)
        self.lineEdit_wavelength = QtGui.QLineEdit(self.tab)
        self.lineEdit_wavelength.setObjectName(_fromUtf8("lineEdit_wavelength"))
        self.horizontalLayout_6.addWidget(self.lineEdit_wavelength)
        spacerItem8 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_6.addItem(spacerItem8)
        self.verticalLayout_2.addLayout(self.horizontalLayout_6)
        self.horizontalLayout_5 = QtGui.QHBoxLayout()
        self.horizontalLayout_5.setObjectName(_fromUtf8("horizontalLayout_5"))
        #self.graphicsView_reducedData = QtGui.QGraphicsView(self.tab)
        self.graphicsView_reducedData = Qt4MplCanvas(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.graphicsView_reducedData.sizePolicy().hasHeightForWidth())
        self.graphicsView_reducedData.setSizePolicy(sizePolicy)
        self.graphicsView_reducedData.setObjectName(_fromUtf8("graphicsView_reducedData"))
        self.horizontalLayout_5.addWidget(self.graphicsView_reducedData)
        self.verticalLayout_3 = QtGui.QVBoxLayout()
        self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
        self.label_xmin = QtGui.QLabel(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_xmin.sizePolicy().hasHeightForWidth())
        self.label_xmin.setSizePolicy(sizePolicy)
        self.label_xmin.setObjectName(_fromUtf8("label_xmin"))
        self.verticalLayout_3.addWidget(self.label_xmin)
        self.lineEdit_xmin = QtGui.QLineEdit(self.tab)
        self.lineEdit_xmin.setEnabled(False)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_xmin.sizePolicy().hasHeightForWidth())
        self.lineEdit_xmin.setSizePolicy(sizePolicy)
        self.lineEdit_xmin.setObjectName(_fromUtf8("lineEdit_xmin"))
        self.verticalLayout_3.addWidget(self.lineEdit_xmin)
        self.label_xmax_2 = QtGui.QLabel(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_xmax_2.sizePolicy().hasHeightForWidth())
        self.label_xmax_2.setSizePolicy(sizePolicy)
        self.label_xmax_2.setObjectName(_fromUtf8("label_xmax_2"))
        self.verticalLayout_3.addWidget(self.label_xmax_2)
        self.lineEdit_xmax = QtGui.QLineEdit(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_xmax.sizePolicy().hasHeightForWidth())
        self.lineEdit_xmax.setSizePolicy(sizePolicy)
        self.lineEdit_xmax.setObjectName(_fromUtf8("lineEdit_xmax"))
        self.verticalLayout_3.addWidget(self.lineEdit_xmax)
        self.label_binsize = QtGui.QLabel(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_binsize.sizePolicy().hasHeightForWidth())
        self.label_binsize.setSizePolicy(sizePolicy)
        self.label_binsize.setObjectName(_fromUtf8("label_binsize"))
        self.verticalLayout_3.addWidget(self.label_binsize)
        self.lineEdit_binsize = QtGui.QLineEdit(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_binsize.sizePolicy().hasHeightForWidth())
        self.lineEdit_binsize.setSizePolicy(sizePolicy)
        self.lineEdit_binsize.setObjectName(_fromUtf8("lineEdit_binsize"))
        self.verticalLayout_3.addWidget(self.lineEdit_binsize)
        spacerItem9 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_3.addItem(spacerItem9)
        self.pushButton_unit2theta = QtGui.QPushButton(self.tab)
        self.pushButton_unit2theta.setObjectName(_fromUtf8("pushButton_unit2theta"))
        self.verticalLayout_3.addWidget(self.pushButton_unit2theta)
        self.pushButton_unitD = QtGui.QPushButton(self.tab)
        self.pushButton_unitD.setObjectName(_fromUtf8("pushButton_unitD"))
        self.verticalLayout_3.addWidget(self.pushButton_unitD)
        self.pushButton_unitQ = QtGui.QPushButton(self.tab)
        self.pushButton_unitQ.setObjectName(_fromUtf8("pushButton_unitQ"))
        self.verticalLayout_3.addWidget(self.pushButton_unitQ)
        spacerItem10 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_3.addItem(spacerItem10)
        self.horizontalLayout_5.addLayout(self.verticalLayout_3)
        self.verticalLayout_2.addLayout(self.horizontalLayout_5)
        self.gridLayout_2.addLayout(self.verticalLayout_2, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab, _fromUtf8(""))
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName(_fromUtf8("tab_2"))
        self.gridLayout_3 = QtGui.QGridLayout(self.tab_2)
        self.gridLayout_3.setObjectName(_fromUtf8("gridLayout_3"))
        self.verticalLayout_4 = QtGui.QVBoxLayout()
        self.verticalLayout_4.setObjectName(_fromUtf8("verticalLayout_4"))
        self.horizontalLayout_10 = QtGui.QHBoxLayout()
        self.horizontalLayout_10.setObjectName(_fromUtf8("horizontalLayout_10"))
        self.label_instrument = QtGui.QLabel(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_instrument.sizePolicy().hasHeightForWidth())
        self.label_instrument.setSizePolicy(sizePolicy)
        self.label_instrument.setMinimumSize(QtCore.QSize(155, 0))
        self.label_instrument.setObjectName(_fromUtf8("label_instrument"))
        self.horizontalLayout_10.addWidget(self.label_instrument)
        self.comboBox_instrument = QtGui.QComboBox(self.tab_2)
        self.comboBox_instrument.setObjectName(_fromUtf8("comboBox_instrument"))
        self.comboBox_instrument.addItem(_fromUtf8(""))
        self.horizontalLayout_10.addWidget(self.comboBox_instrument)
        spacerItem11 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_10.addItem(spacerItem11)
        self.verticalLayout_4.addLayout(self.horizontalLayout_10)
        self.horizontalLayout_7 = QtGui.QHBoxLayout()
        self.horizontalLayout_7.setObjectName(_fromUtf8("horizontalLayout_7"))
        self.label_cache = QtGui.QLabel(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_cache.sizePolicy().hasHeightForWidth())
        self.label_cache.setSizePolicy(sizePolicy)
        self.label_cache.setMinimumSize(QtCore.QSize(155, 0))
        self.label_cache.setObjectName(_fromUtf8("label_cache"))
        self.horizontalLayout_7.addWidget(self.label_cache)
        self.lineEdit_cache = QtGui.QLineEdit(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_cache.sizePolicy().hasHeightForWidth())
        self.lineEdit_cache.setSizePolicy(sizePolicy)
        self.lineEdit_cache.setMinimumSize(QtCore.QSize(400, 0))
        self.lineEdit_cache.setObjectName(_fromUtf8("lineEdit_cache"))
        self.horizontalLayout_7.addWidget(self.lineEdit_cache)
        self.pushButton_browseCache = QtGui.QPushButton(self.tab_2)
        self.pushButton_browseCache.setObjectName(_fromUtf8("pushButton_browseCache"))
        self.horizontalLayout_7.addWidget(self.pushButton_browseCache)
        self.checkBox_delCache = QtGui.QCheckBox(self.tab_2)
        self.checkBox_delCache.setObjectName(_fromUtf8("checkBox_delCache"))
        self.horizontalLayout_7.addWidget(self.checkBox_delCache)
        spacerItem12 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_7.addItem(spacerItem12)
        self.verticalLayout_4.addLayout(self.horizontalLayout_7)
        self.horizontalLayout_8 = QtGui.QHBoxLayout()
        self.horizontalLayout_8.setObjectName(_fromUtf8("horizontalLayout_8"))
        self.radioButton_useServer = QtGui.QRadioButton(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.radioButton_useServer.sizePolicy().hasHeightForWidth())
        self.radioButton_useServer.setSizePolicy(sizePolicy)
        self.radioButton_useServer.setMinimumSize(QtCore.QSize(20, 0))
        self.radioButton_useServer.setText(_fromUtf8(""))
        self.radioButton_useServer.setObjectName(_fromUtf8("radioButton_useServer"))
        self.horizontalLayout_8.addWidget(self.radioButton_useServer)
        self.label = QtGui.QLabel(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setMinimumSize(QtCore.QSize(135, 0))
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout_8.addWidget(self.label)
        self.lineEdit_dataIP = QtGui.QLineEdit(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_dataIP.sizePolicy().hasHeightForWidth())
        self.lineEdit_dataIP.setSizePolicy(sizePolicy)
        self.lineEdit_dataIP.setMinimumSize(QtCore.QSize(400, 0))
        self.lineEdit_dataIP.setObjectName(_fromUtf8("lineEdit_dataIP"))
        self.horizontalLayout_8.addWidget(self.lineEdit_dataIP)
        self.pushButton_chkServer = QtGui.QPushButton(self.tab_2)
        self.pushButton_chkServer.setObjectName(_fromUtf8("pushButton_chkServer"))
        self.horizontalLayout_8.addWidget(self.pushButton_chkServer)
        spacerItem13 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_8.addItem(spacerItem13)
        self.verticalLayout_4.addLayout(self.horizontalLayout_8)
        self.horizontalLayout_9 = QtGui.QHBoxLayout()
        self.horizontalLayout_9.setObjectName(_fromUtf8("horizontalLayout_9"))
        self.radioButton_useLocal = QtGui.QRadioButton(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.radioButton_useLocal.sizePolicy().hasHeightForWidth())
        self.radioButton_useLocal.setSizePolicy(sizePolicy)
        self.radioButton_useLocal.setMinimumSize(QtCore.QSize(20, 0))
        self.radioButton_useLocal.setText(_fromUtf8(""))
        self.radioButton_useLocal.setObjectName(_fromUtf8("radioButton_useLocal"))
        self.horizontalLayout_9.addWidget(self.radioButton_useLocal)
        self.label_localSrc = QtGui.QLabel(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_localSrc.sizePolicy().hasHeightForWidth())
        self.label_localSrc.setSizePolicy(sizePolicy)
        self.label_localSrc.setMinimumSize(QtCore.QSize(135, 0))
        self.label_localSrc.setObjectName(_fromUtf8("label_localSrc"))
        self.horizontalLayout_9.addWidget(self.label_localSrc)
        self.lineEdit_localSrc = QtGui.QLineEdit(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_localSrc.sizePolicy().hasHeightForWidth())
        self.lineEdit_localSrc.setSizePolicy(sizePolicy)
        self.lineEdit_localSrc.setMinimumSize(QtCore.QSize(400, 0))
        self.lineEdit_localSrc.setObjectName(_fromUtf8("lineEdit_localSrc"))
        self.horizontalLayout_9.addWidget(self.lineEdit_localSrc)
        self.pushButton_browseLocalSrc = QtGui.QPushButton(self.tab_2)
        self.pushButton_browseLocalSrc.setObjectName(_fromUtf8("pushButton_browseLocalSrc"))
        self.horizontalLayout_9.addWidget(self.pushButton_browseLocalSrc)
        spacerItem14 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_9.addItem(spacerItem14)
        self.verticalLayout_4.addLayout(self.horizontalLayout_9)
        self.horizontalLayout_4 = QtGui.QHBoxLayout()
        self.horizontalLayout_4.setObjectName(_fromUtf8("horizontalLayout_4"))
        spacerItem15 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.horizontalLayout_4.addItem(spacerItem15)
        self.verticalLayout_4.addLayout(self.horizontalLayout_4)
        self.gridLayout_3.addLayout(self.verticalLayout_4, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tab_2, _fromUtf8(""))
        self.horizontalLayout_2.addWidget(self.tabWidget)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1124, 25))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        self.menuView = QtGui.QMenu(self.menubar)
        self.menuView.setObjectName(_fromUtf8("menuView"))
        self.menuHelp = QtGui.QMenu(self.menubar)
        self.menuHelp.setObjectName(_fromUtf8("menuHelp"))
        self.menuWindow = QtGui.QMenu(self.menubar)
        self.menuWindow.setObjectName(_fromUtf8("menuWindow"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.actionQuit = QtGui.QAction(MainWindow)
        self.actionQuit.setObjectName(_fromUtf8("actionQuit"))
        self.actionLog = QtGui.QAction(MainWindow)
        self.actionLog.setObjectName(_fromUtf8("actionLog"))
        self.actionNew = QtGui.QAction(MainWindow)
        self.actionNew.setObjectName(_fromUtf8("actionNew"))
        self.actionOpen = QtGui.QAction(MainWindow)
        self.actionOpen.setObjectName(_fromUtf8("actionOpen"))
        self.actionOpen_2 = QtGui.QAction(MainWindow)
        self.actionOpen_2.setObjectName(_fromUtf8("actionOpen_2"))
        self.menuFile.addAction(self.actionNew)
        self.menuFile.addAction(self.actionOpen_2)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionQuit)
        self.menuView.addAction(self.actionLog)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuView.menuAction())
        self.menubar.addAction(self.menuWindow.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.label_expNo.setText(_translate("MainWindow", "Exp No", None))
        self.label_scanNo.setText(_translate("MainWindow", "Scan No", None))
        self.pushButton_loadData.setText(_translate("MainWindow", "Load Data", None))
        self.label_calibration.setText(_translate("MainWindow", "Ge 113 IN Config", None))
        self.label_ptNo.setText(_translate("MainWindow", "Pt.", None))
        self.label_detNo.setText(_translate("MainWindow", "Detector ", None))
        self.pushButton_plotRaw.setText(_translate("MainWindow", "Plot Raw Detector", None))
        self.pushButton_ptUp.setText(_translate("MainWindow", "Previous Pt.", None))
        self.pushButton_ptDown.setText(_translate("MainWindow", "Next Pt.", None))
        self.pushButton_detUp.setText(_translate("MainWindow", "Previous Detector", None))
        self.pushButton_detDown.setText(_translate("MainWindow", "Next Detector", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("MainWindow", "Raw Detectors", None))
        self.label_normalizeMonitor.setText(_translate("MainWindow", "Normalization Monitor", None))
        self.label_outputFormat.setText(_translate("MainWindow", "Save As", None))
        self.pushButton_saveData.setText(_translate("MainWindow", "Save", None))
        self.label_detExcluded.setText(_translate("MainWindow", "Detectors to Exclude   ", None))
        self.label_wavelength.setText(_translate("MainWindow", "Wavelength", None))
        self.label_xmin.setText(_translate("MainWindow", "Minimum X", None))
        self.label_xmax_2.setText(_translate("MainWindow", "Maximum X", None))
        self.label_binsize.setText(_translate("MainWindow", "Bin Size", None))
        self.pushButton_unit2theta.setText(_translate("MainWindow", "2theta", None))
        self.pushButton_unitD.setText(_translate("MainWindow", "dSpacing", None))
        self.pushButton_unitQ.setText(_translate("MainWindow", "Q", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("MainWindow", "Normalized", None))
        self.label_instrument.setText(_translate("MainWindow", "Instrument", None))
        self.comboBox_instrument.setItemText(0, _translate("MainWindow", "HB2A", None))
        self.label_cache.setToolTip(_translate("MainWindow", "<html><head/><body><p>Cache data file download from server to local disk. </p><p>The default is current working directory.  </p><p>The cached files will be deleted with normal quit. </p></body></html>", None))
        self.label_cache.setText(_translate("MainWindow", "Cache Raw Data File", None))
        self.pushButton_browseCache.setText(_translate("MainWindow", "Browse", None))
        self.checkBox_delCache.setToolTip(_translate("MainWindow", "<html><head/><body><p>Cached files will be deleted upon quitting normally.</p></body></html>", None))
        self.checkBox_delCache.setText(_translate("MainWindow", "Delete Cache Before Quit", None))
        self.label.setText(_translate("MainWindow", "Server    Address", None))
        self.pushButton_chkServer.setText(_translate("MainWindow", "Check URL", None))
        self.label_localSrc.setText(_translate("MainWindow", "Local Data Storage", None))
        self.pushButton_browseLocalSrc.setText(_translate("MainWindow", "Browse", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("MainWindow", "Advanced Setup", None))
        self.menuFile.setTitle(_translate("MainWindow", "File", None))
        self.menuView.setTitle(_translate("MainWindow", "View", None))
        self.menuHelp.setTitle(_translate("MainWindow", "Help", None))
        self.menuWindow.setTitle(_translate("MainWindow", "Window", None))
        self.actionQuit.setText(_translate("MainWindow", "Quit", None))
        self.actionQuit.setShortcut(_translate("MainWindow", "Ctrl+Q", None))
        self.actionLog.setText(_translate("MainWindow", "Log", None))
        self.actionLog.setShortcut(_translate("MainWindow", "Ctrl+L", None))
        self.actionNew.setText(_translate("MainWindow", "New", None))
        self.actionNew.setShortcut(_translate("MainWindow", "Ctrl+N", None))
        self.actionOpen.setText(_translate("MainWindow", "Open", None))
        self.actionOpen_2.setText(_translate("MainWindow", "Open", None))
        self.actionOpen_2.setShortcut(_translate("MainWindow", "Ctrl+O", None))

