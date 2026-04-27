QT += widgets

HEADERS       = \
                calculator.h
SOURCES       = \
                calculator.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/calculator
INSTALLS += target

FORMS += \
    calculator.ui
