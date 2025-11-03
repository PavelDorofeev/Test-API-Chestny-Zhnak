#ifndef DLL_MARKING_GLOBAL_H
#define DLL_MARKING_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(USING_LIB_MARKING)

#if defined(LIB_IS_EXPORTED_MARKING)

#  define LIB_PREFIX_MARKING Q_DECL_EXPORT

#else

#  define LIB_PREFIX_MARKING Q_DECL_IMPORT

#endif

#else

#   define LIB_PREFIX_MARKING

#endif // USING_LIB_MARKING

#endif // DLL_MARKING_GLOBAL_H
