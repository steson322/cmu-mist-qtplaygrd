OTHER_FILES += \

HEADERS += \
    $$PWD/presentation/model/MainWindowViewModel.h \
    $$PWD/presentation/model/ConditionBarViewModel.h \
    $$PWD/presentation/model/TaskBarViewModel.h \
    $$PWD/presentation/model/ProtocolSectionListViewModel.h \
    $$PWD/presentation/model/ProtocolSectionViewModel.h \
    $$PWD/presentation/model/ProtocolViewModel.h

SOURCES += \
    $$PWD/presentation/model/MainWindowViewModel.cpp \
    $$PWD/presentation/model/ConditionBarViewModel.cpp \
    $$PWD/presentation/model/TaskBarViewModel.cpp \
    $$PWD/presentation/model/ProtocolSectionListViewModel.cpp \
    $$PWD/presentation/model/ProtocolSectionViewModel.cpp \
    $$PWD/presentation/model/ProtocolViewModel.cpp

DISTFILES += \
    $$PWD/presentation/view/MainWindow.qml \
    $$PWD/presentation/view/ConditionBar.qml\
    $$PWD/presentation/view/TaskBar.qml \
    $$PWD/presentation/view/ProtocolSectionListView.qml
