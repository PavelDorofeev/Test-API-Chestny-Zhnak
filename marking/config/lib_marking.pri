#INCLUDEPATH += $$includePath( $$PWD/../) # "abstract_kkt/xxxxxxxx.h"
INCLUDEPATH += $$includePath( $$PWD/../../) #


CONFIG(release,release|debug){

    contains(CONFIG,static){
        # ----------------------------------------------
            LIBS += -L$$PWD/../release -lmarking
        # ----------------------------------------------

    }
    else{
        #error(6597589789506870948609)
    }
}
else:CONFIG(debug,release|debug){

    contains(CONFIG,static){
        #error(648498954546463465)
    }
    else:contains(CONFIG,shared){

        # ----------------------------------------------
            LIBS += -L$$PWD/../debug -lmarking
        # ----------------------------------------------

        DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIBS_USING_MARKING)
        DEFINES -= $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIB_IS_EXPORTED_MARKING)

    }
}
