#ifndef DATAMATRIX_TEXT_EDIT_123_H
#define DATAMATRIX_TEXT_EDIT_123_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QEvent>
#include <QByteArray>
#include <QTime>
#include "qp/core/meta/qhashbuilder.h"

#include "../dll_kb_scanner_global.h"

class LIB_PREFIX_KB_SCANNER  DatamatrixTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit DatamatrixTextEdit(QWidget *parent = 0);

    QByteArray barcode;

    int readden;

    //void  set_GS_isAllow( bool GS_isAllow);
    void  set_log_isAllow( bool log_isAllowed);

    int contains_GS() const;

    void redefine_GS( const QList<quint32> & ba );

    static const QHash<quint32,uchar> scanCodeSymbolLower;
    static const QHash<quint32,uchar> scanCodeSymbolUpper;
    static const QHash<quint32,QString> scanCodeInvisibleSymbol;

    void setAutoDetection( bool on);
    void addLog(  QKeyEvent *evt , int nativeScanCode_XT, unsigned char ucha, const QString & txt);

    QString log;

    QList<quint32> rawReaddenLst;

public:
    //bool eventFilter(QObject *obj, QEvent *event);
protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void sig_enter_finished();
    void sig_symbol_readden(const uchar );
    void sig_auto_detect_replacement(const QList<quint32> &lst );
    void sig_some_errors(const QString);
    
public slots:

private:

    //bool GS_isAllow;
    bool log_isAllowed;
    int is_GS_present;
    bool autoDetection;

    //bool ShiftModifier;    //void aaa();
    QTime tmr;
    QList<quint32>  lstSumbolsSetToConvertToGS;

    int replacedCnt;

    uchar arr[10];

    bool testReplace(QKeyEvent *evt, const quint32 &nativeScanCode_XT, const uchar &ucha , bool modif = false);
    uchar decodeWithShift( const Qt::KeyboardModifiers &mdf , const int&nativeScanCode_XT   ) ;
    const QString readdentoStr( const QList<quint32> & lst ) const;
    
};

/*


    (Table 00006)
    Values for keyboard make/break (scan) code:
    01h    Esc              31h    N
    02h    1 !              32h    M
    03h    2 @              33h    , <              63h    F16
    04h    3 #              34h    . >              64h    F17
    05h    4 $              35h    / ?              65h    F18
    06h    5 %              36h    Right Shift      66h    F19
    07h    6 ^              37h    Grey*            67h    F20
    08h    7 &              38h    Alt              68h    F21 (Fn) [*]
    09h    8 *              39h    SpaceBar         69h    F22
    0Ah    9 (              3Ah    CapsLock         6Ah    F23
    0Bh    0 )              3Bh    F1               6Bh    F24
    0Ch    - _              3Ch    F2               6Ch    --
    0Dh    = +              3Dh    F3               6Dh    EraseEOF
    0Eh    Backspace        3Eh    F4
    0Fh    Tab              3Fh    F5               6Fh    Copy/Play
    10h    Q                40h    F6
    11h    W                41h    F7
    12h    E                42h    F8               72h    CrSel
    13h    R                43h    F9               73h     [*]
    14h    T                44h    F10              74h    ExSel
    15h    Y                45h    NumLock          75h    --
    16h    U                46h    ScrollLock       76h    Clear
    17h    I                47h    Home             77h    [Note2] Joyst But1
    18h    O                48h    UpArrow          78h    [Note2] Joyst But2
    19h    P                49h    PgUp             79h    [Note2] Joyst Right
    1Ah    [ {              4Ah    Grey-            7Ah    [Note2] Joyst Left
    1Bh    ] }              4Bh    LeftArrow        7Bh    [Note2] Joyst Up
    1Ch    Enter            4Ch    Keypad 5         7Ch    [Note2] Joyst Down
    1Dh    Ctrl             4Dh    RightArrow       7Dh    [Note2] right mouse
    1Eh    A                4Eh    Grey+            7Eh    [Note2] left mouse
    1Fh    S                4Fh    End
    20h    D                50h    DownArrow
    21h    F                51h    PgDn
    22h    G                52h    Ins
    23h    H                53h    Del
    24h    J                54h    SysReq          ---non-key codes---
    25h    K                55h    [Note1] F11      00h    kbd buffer full
    26h    L                56h    left \| (102-key)

    27h    ; :
    57h    F11              AAh    self-test complete
    28h    ' "              58h    F12              E0h    prefix code
    29h    ` ~              59h    [Note1] F15      E1h    prefix code
    2Ah    Left Shift       5Ah    PA1              EEh    ECHO
    2Bh    \ |              5Bh    F13 (LWin)       F0h    prefix code (key break)
    2Ch    Z                5Ch    F14 (RWin)       FAh    ACK
    2Dh    X                5Dh    F15 (Menu)       FCh    diag failure (MF-kbd)
    2Eh    C                                        FDh    diag failure (AT-kbd)
    2Fh    V                                        FEh    RESEND
    30h    B                                        FFh    kbd error/buffer full
    */


#endif // DATAMATRIX_LINE_EDIT_H
