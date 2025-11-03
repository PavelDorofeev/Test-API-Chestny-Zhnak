ROOT_DIR = $${PWD}/../..

defineReplace(cleanPath) {
    win32:1 ~= s|\\\\|/|g

    #message(cleanPath 1: $$1)

    contains(1, ^/.*):pfx = /
    else:pfx =
    segs = $$split(1, /)
    out =
    for(seg, segs) {
        equals(seg, ..):out = $$member(out, 0, -2)
        else:!equals(seg, .):out += $$seg
    }
    #message(out : $$out)
    #message(pfx : $$pfx)

    win32:return($$join(out, /, $$pfx))


    return($$join(out, /, $ $pfx))
}


defineReplace(includePath) {

    #message(1: $$1)
    !exists($$1){
        error(unavailable path : $$1 )
    }

    path_for_INCLUDE = $$cleanPath($$1)

    contains( INCLUDEPATH, $$path_for_INCLUDE ) {
        message(already included : $$path_for_INCLUDE)
      return ("")
    }

    message(now included : $$path_for_INCLUDE)
    return($$path_for_INCLUDE)
}

defineReplace(dependPath) {

    #message(1: $$1)
    !exists($$1){
        error(unavailable path : $$1 )
    }

    path_for_DEPEND = $$cleanPath($$1)

    contains( DEPENDPATH, $$path_for_DEPEND ) {
        message( DEPENDPATH already included : $$path_for_DEPEND)
      return ("")
    }

    message(now included : $$path_for_DEPEND)
    return($$path_for_DEPEND)
}

defineReplace(include2) {

    #message(1: $$1)
    !exists($$1){
        error(include2 unavailable path : $$1 )
    }

    return($$1)
}

defineReplace(targetWithVer) {
    exists("$$PWD\\base_version.h"){
        FILE = $$cat($$PWD\\base_version.h,lines)
    }else:exists("$$PWD\\version\\base_version.h"){
        FILE = $$cat($$PWD\\version\\base_version.h,lines)
    }else{
        error("unfound  $$PWD\\base_version.h" )
    }
    NVER1 = $$member(FILE,2,2)
    NVER2 = $$member(FILE,6,6)
    NVER3 = $$member(FILE,10,10)
    message(-------------------------)
    NVER=$$NVER1"."$$NVER2"."$$NVER3
#    message(1 $$1)
#    message(NVER $$NVER)
    target_with_ver = $$1"_"$$NVER
    message($$target_with_ver)
    message(-------------------------)
    return($$target_with_ver)
}

HEADERS += \
#    $$PWD/reestr_def.h

SOURCES += \
#    $$PWD/reestr_def.cpp
