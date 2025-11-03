INCLUDEPATH += $$includePath($$PWD/../../) # qp
INCLUDEPATH += $$includePath($$PWD/../) #
#INCLUDEPATH += $$includePath($$PWD/../a_subdirs) # abstract_kkt

CONFIG(release,release|debug){

    contains(CONFIG,static){
        # ----------------------------------------------
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
            DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIBS_USING_MARKING)
            DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIB_IS_EXPORTED_MARKING)
        # ----------------------------------------------
    }
}
#error($$INCLUDEPATH)
