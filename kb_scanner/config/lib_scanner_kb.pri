INCLUDEPATH += $$includePath($$PWD/../)

CONFIG(release,release|debug){

    contains(CONFIG,static){
        # ----------------------------------------------
            LIBS += -L$$PWD/../kb_wgt/release -lkb_wgt
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

        DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIBS_USING_KB_SCANNER)
        DEFINES -= $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIB_IS_EXPORTED_KB_SCANNER )

        # ----------------------------------------------
            LIBS += -L$$PWD/../kb_wgt/debug -lkb_wgt
        # ----------------------------------------------
    }
}
