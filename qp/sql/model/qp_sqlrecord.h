#ifndef QP_SQLRECORD_H
#define QP_SQLRECORD_H

#include <QSqlRecord>
#include <QHash>

class QpSqlRecord;
class QpCmnSqlTableModel;
class FormDlg;

typedef void (*cb_ui_recalculate) ( QpCmnSqlTableModel *, FormDlg*, int, QWidget*, const QpSqlRecord &, QpSqlRecord &);

class QpCmnSqlTableModel;

#include "qp/sql/dll_qp_sql_global.h"
class LIB_PREFIX_QP_SQL QpSqlRecord : public QSqlRecord
{

public:


    QpSqlRecord();

    explicit QpSqlRecord( QpCmnSqlTableModel *mdl ,
                          const QSqlRecord &rec);

    QpSqlRecord& operator=(const QSqlRecord& other);

    virtual ~QpSqlRecord();


    int getRelIdCol(const QString& relCol) const;

    void setRefToModel(QpCmnSqlTableModel *mdl);

    QpCmnSqlTableModel *model();

    bool qp_setValue( int col, const QVariant &newValue , bool generated = true);
    bool qp_setValue( const QString &FieldName, const QVariant &newValue , bool generated = true);

private:

    void func1(const QSqlRecord &rec);

    QpCmnSqlTableModel *mdl;


};

#endif // QP_SQLRECORD_H
