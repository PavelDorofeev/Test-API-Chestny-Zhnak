CONFIG(release,release|debug){

    contains(CONFIG,static){
        # ----------------------------------------------
            LIBS += -LD:\\QtSDK1.2.1\\QtSources\\4.8.1\\lib\\QAxContainer -lQAxContainer
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
            LIBS += -LD:\\QtSDK1.2.1\\QtSources\\4.8.1\\lib\\QAxContainerd -lQAxContainerd
        # ----------------------------------------------
    }
}
