#define NVER1 1
#define NVER2 4
#define STATIC_BUILD_NUMBER 2

#define BITLtd Str("Software\\BIT Ltd\\Chzn Api Test\\")

// для Inno setup !! Str(..) !! работает, а здесь в С++ нифига почему-то
//#define Version Str(NVER1)+"."+Str(NVER2)
#define INNO_PROGRAM_VERSION Str(NVER1)+"."+Str(NVER2)+"."+Str(STATIC_BUILD_NUMBER)

//----------------------------------------------- 
#define PRODUCT_VERSION "1.2.4.1" 
// --------------- sub versions ----------------- 
#define MY_PRODUCT_TYPE  1 
#define MY_OS_TYPE       2 
#define MY_DEBUG_RELEASE 4 
#define MY_IDE           1 
//----------------------------------------------- 
//----------------------------------------------- 

// здесь в Qt так решаем
// const QString appDef::PROGRAM_VERSION = QString("%1.%2.%3").arg(NVER1).arg(NVER2).arg(STATIC_BUILD_NUMBER);


#define BUILDING_PROGRAM_DIR  "D:\\DEVELOPMENT\\QT4\\_MY__\\driver_KKT_BIT\\chzn_subdirs\\chzn_api_test\\release\\"
