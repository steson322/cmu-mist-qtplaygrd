OTHER_FILES += \

HEADERS += \
    MainWindow/presentation/presenter/MainWindowModel.h \
    $$PWD/presentation/model/MainWindowViewModel.h

SOURCES += \
    MainWindow/presentation/presenter/MainWindowModel.cpp \
    $$PWD/presentation/model/MainWindowViewModel.cpp

DISTFILES += \
    $$PWD/presentation/view/MainWindow.qml \
    $$PWD/presentation/view/ConditionBar.qml\
    $$PWD/presentation/view/TaskBar.qml
