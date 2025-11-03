#ifndef DLL_CHZN_GLOBAL_H
#define DLL_CHZN_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(USING_LIB_CHZN)

#if defined(LIB_IS_EXPORTED_CHZN)

#  define LIB_PREFIX_CHZN Q_DECL_EXPORT

#else

#  define LIB_PREFIX_CHZN Q_DECL_IMPORT

#endif

#else

#   define LIB_PREFIX_CHZN

#endif // USING_LIB_CHZN

#endif // DLL_CHZN_GLOBAL_H
