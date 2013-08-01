RCC_DIR     = $$_PRO_FILE_PWD_/build/tmp/rcc
UI_DIR      = $$_PRO_FILE_PWD_/build/tmp/ui
MOC_DIR     = $$_PRO_FILE_PWD_/build/tmp/moc
OBJECTS_DIR = $$_PRO_FILE_PWD_/build/tmp/obj

CONFIG(debug, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$_PRO_FILE_PWD_/build/release
}

SOURCES += \
    src/main.cpp \
    src/ui/window.cpp \
    src/objects/scene.cpp \
    src/objects/abstractscene.cpp

HEADERS += \
    src/ui/window.h \
    src/objects/scene.h \
    src/objects/abstractscene.h

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    resources/shaders/basic.frag \
    resources/shaders/basic.vert
