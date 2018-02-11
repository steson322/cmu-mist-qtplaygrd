OTHER_FILES += \

HEADERS += \
    $$PWD/presentation/model/MainWindowViewModel.h \
    $$PWD/presentation/model/ConditionBarViewModel.h \
    $$PWD/presentation/model/TaskBarViewModel.h \
    $$PWD/model/ConfigurationModel.h

SOURCES += \
    $$PWD/presentation/model/MainWindowViewModel.cpp \
    $$PWD/presentation/model/ConditionBarViewModel.cpp \
    $$PWD/presentation/model/TaskBarViewModel.cpp \
    $$PWD/model/ConfigurationModel.cpp

DISTFILES += \
    $$PWD/presentation/view/MainWindow.qml \
    $$PWD/presentation/view/ConditionBar.qml\
    $$PWD/presentation/view/TaskBar.qml
