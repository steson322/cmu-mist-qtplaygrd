OTHER_FILES += \

HEADERS += \
    MainWindow/presentation/presenter/MainWindowModel.h \
    $$PWD/presentation/model/MainWindowViewModel.h \
    $$PWD/presentation/model/ConditionBarViewModel.h \
    $$PWD/presentation/model/ConditionBarViewModel.h

SOURCES += \
    MainWindow/presentation/presenter/MainWindowModel.cpp \
    $$PWD/presentation/model/MainWindowViewModel.cpp \
    $$PWD/presentation/model/ConditionBarViewModel.cpp

DISTFILES += \
    $$PWD/presentation/view/MainWindow.qml \
    $$PWD/presentation/view/ConditionBar.qml\
    $$PWD/presentation/view/TaskBar.qml
