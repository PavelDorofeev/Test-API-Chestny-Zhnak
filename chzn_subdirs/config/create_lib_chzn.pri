
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
            DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIBS_USING_CHZN)
            DEFINES += $$fromfile( $$PWD/cfg_debug.pri , DEFINES_LIB_IS_EXPORTED_CHZN)
        # ----------------------------------------------
    }
}
