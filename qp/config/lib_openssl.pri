CONFIG(release,release|debug){

    contains(CONFIG,static){

#        CONFIG += openssl-linked
        OPENSSL_DIR = D:\\OpenSSL\\1_0_2_static
        INCLUDEPATH += $$includePath($$OPENSSL_DIR\\include)

        LIBS += -L$$OPENSSL_DIR\\lib -llibeay32 -lssleay32
#        error(INCLUDEPATH : $$INCLUDEPATH)
        # ------------------------------------------------
        #        вот так подготавливаем
        # configure.exe -opensource -confirm-license -release -static -mp -platform win32-msvc2010 ....
        #    -openssl -openssl-linked -ltcg OPENSSL_LIBS="-llibeay32 -lssleay32"
        #    -I D:\OpenSSL\1_0_2_static\include -L D:\OpenSSL\1_0_2_static\lib
        # ------------------------------------------------
    }
    else{
    }
}
else:CONFIG(debug,release|debug){

    contains(CONFIG,static){
    }
    else:contains(CONFIG,shared){

        OPENSSL_DIR = D:\\OpenSSL\\1_0_2_dll


        INCLUDEPATH += $$includePath($$OPENSSL_DIR\\include)
#        $$includePath($$OPENSSL_DIR\\include)
#        INCLUDEPATH += $OPENSSL_DIR\\include
#        error( $$INCLUDEPATH)

        !exists($$OPENSSL_DIR\\bin\\libeay32.dll): error(unexist $$OPENSSL_DIR\\bin\\libeay32.dll)
        !exists($$OPENSSL_DIR\\bin\\ssleay32.dll): error(unexist $$OPENSSL_DIR\\bin\\ssleay32.dll)

        LIBS += -L$$OPENSSL_DIR\\lib -llibeay32 -lssleay32
        # надо иначе error: LNK1104: cannot open file 'libeay32.lib'

        LIBS += -L$$OPENSSL_DIR\\bin -llibeay32 -lssleay32
        # это важно, иначе libeay32.dll не будет найдена при отладке
        # и при наличии QNetworkAccessManager программа будет падать не доходя даже до старта!
        # и ни хрена будет не понять почему
        # под другому надо кидать ssleay32.dll и libeay32.dll в debug или к qmake.exe!


#        OPENSSL_DIR = D:/OpenSSL/1_0_2_dll
##        OPENSSL_DIR ~= s,/,\\,g


##        $$includePath($$OPENSSL_DIR\\include)
#        INCLUDEPATH += $OPENSSL_DIR/include
##        error( $$INCLUDEPATH)

#        !exists($$OPENSSL_DIR/bin/libeay32.dll): error(unexist $$OPENSSL_DIR/bin/libeay32.dll)
#        !exists($$OPENSSL_DIR/bin/ssleay32.dll): error(unexist $$OPENSSL_DIR/bin/ssleay32.dll)

#        LIBS += -L$$OPENSSL_DIR/lib -llibeay32 -lssleay32
#        # надо иначе error: LNK1104: cannot open file 'libeay32.lib'

##        LIBS += -L$$OPENSSL_DIR/bin -llibeay32 -lssleay32   МОЖНО ЗАКОММЕНТИТЬ
#        # это важно, иначе libeay32.dll не будет найдена при отладке
#        # и при наличии QNetworkAccessManager программа бужет падать не доходя даже до старта!
#        # и ни хрена будет не понять почему
#        # под другому надо кидать ssleay32.dll и libeay32.dll в debug или к qmake.exe

    }
}


#error(OPENSSL_LIBS = $$OPENSSL_LIBS )
