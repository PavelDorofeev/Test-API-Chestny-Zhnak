/********************************************************************************
** Form generated from reading UI file 'chzn_test_wgt.ui'
**
** Created: Mon 3. Nov 20:40:29 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHZN_TEST_WGT_H
#define UI_CHZN_TEST_WGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chzn_Test_Dlg
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_dark_1;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *verticalGroupBox_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_scan_bar_code;
    QPushButton *btn_GS_remove;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbl_code;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *ledt_gtin;
    QLabel *label_2;
    QLineEdit *ledt_ki;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame_dark_2;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *verticalGroupBox_21;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QGroupBox *gr_lk_api_key;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *ledt_lk_api_key;
    QLineEdit *ledt_inn_uot;
    QComboBox *cmb_api_version;
    QLineEdit *ledt_thumbprint;
    QLabel *label_5;
    QComboBox *cmb_konturType;
    QSpacerItem *horizontalSpacer_9;
    QFrame *frame_dark_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *gr;
    QFormLayout *formLayout_2;
    QPushButton *btn_get_api_key;
    QLineEdit *ledt_api_key;
    QPushButton *btn_get_auth_simpleSignIn;
    QLineEdit *ledt_auth_simpleSignIn;
    QPushButton *btn_get_auth_permissive_access;
    QLineEdit *ledt_auth_permissive_access;
    QLineEdit *ledt_access_token_id;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPushButton *btn_get_cises_ease_info;
    QPushButton *btn_get_codes_check;
    QPushButton *btn_get_nk_short_product;
    QPushButton *btn_get_cises_check;
    QPushButton *btn_get_cises_info;
    QPushButton *btn_get_product_info;
    QPushButton *btn_get_nk_feed_product;
    QPushButton *btn_get_nk_product;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_dark_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_2;
    QPushButton *btn_chzn_validate;
    QPushButton *btn_getCdnHosts;
    QComboBox *cmb_cdb_list;
    QLineEdit *ledt_lk_kkt_token;
    QLabel *label_3;
    QPushButton *btn_chzn_cdn_host_check;
    QPushButton *btn_get_cises_check_history_create;
    QPushButton *btn_get_cises_check_history_receive;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_dark_4;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *ledt_lm_login;
    QLabel *label_8;
    QLineEdit *ledt_lm_pw;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QPushButton *btn_lm_init;
    QLineEdit *ledt_fn_num;
    QPushButton *btn_lm_status;
    QPushButton *btn_lm_cis_check;
    QPushButton *btn_lm_cis_check_old;
    QPushButton *btn_lm_cis_outCheck;
    QPushButton *btn_lm_cis_outCheck_post;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_4;
    QPushButton *btn_log;
    QSpacerItem *horizontalSpacer;
    QLabel *lbl_tempDir;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *Chzn_Test_Dlg)
    {
        if (Chzn_Test_Dlg->objectName().isEmpty())
            Chzn_Test_Dlg->setObjectName(QString::fromUtf8("Chzn_Test_Dlg"));
        Chzn_Test_Dlg->resize(941, 772);
        Chzn_Test_Dlg->setMinimumSize(QSize(941, 772));
        verticalLayout = new QVBoxLayout(Chzn_Test_Dlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Chzn_Test_Dlg);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -212, 995, 942));
        scrollAreaWidgetContents->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_dark_1 = new QFrame(scrollAreaWidgetContents);
        frame_dark_1->setObjectName(QString::fromUtf8("frame_dark_1"));
        horizontalLayout_7 = new QHBoxLayout(frame_dark_1);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalGroupBox_2 = new QGroupBox(frame_dark_1);
        verticalGroupBox_2->setObjectName(QString::fromUtf8("verticalGroupBox_2"));
        verticalGroupBox_2->setCheckable(true);
        verticalLayout_8 = new QVBoxLayout(verticalGroupBox_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, -1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_scan_bar_code = new QPushButton(verticalGroupBox_2);
        btn_scan_bar_code->setObjectName(QString::fromUtf8("btn_scan_bar_code"));
        btn_scan_bar_code->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_scan_bar_code->sizePolicy().hasHeightForWidth());
        btn_scan_bar_code->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btn_scan_bar_code);

        btn_GS_remove = new QPushButton(verticalGroupBox_2);
        btn_GS_remove->setObjectName(QString::fromUtf8("btn_GS_remove"));
        btn_GS_remove->setEnabled(false);
        btn_GS_remove->setText(QString::fromUtf8("GS \321\203\320\261\321\200\320\260\321\202\321\214"));

        horizontalLayout->addWidget(btn_GS_remove);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout);

        lbl_code = new QLabel(verticalGroupBox_2);
        lbl_code->setObjectName(QString::fromUtf8("lbl_code"));
        QFont font;
        font.setPointSize(10);
        lbl_code->setFont(font);
        lbl_code->setFrameShape(QFrame::Box);
        lbl_code->setMidLineWidth(1);
        lbl_code->setText(QString::fromUtf8(""));
        lbl_code->setTextFormat(Qt::PlainText);
        lbl_code->setWordWrap(false);
        lbl_code->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_8->addWidget(lbl_code);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalGroupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        ledt_gtin = new QLineEdit(verticalGroupBox_2);
        ledt_gtin->setObjectName(QString::fromUtf8("ledt_gtin"));
        ledt_gtin->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(ledt_gtin);

        label_2 = new QLabel(verticalGroupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ledt_ki = new QLineEdit(verticalGroupBox_2);
        ledt_ki->setObjectName(QString::fromUtf8("ledt_ki"));

        horizontalLayout_2->addWidget(ledt_ki);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_2);


        horizontalLayout_7->addWidget(verticalGroupBox_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_5->addWidget(frame_dark_1);

        frame_dark_2 = new QFrame(scrollAreaWidgetContents);
        frame_dark_2->setObjectName(QString::fromUtf8("frame_dark_2"));
        frame_dark_2->setFrameShape(QFrame::NoFrame);
        frame_dark_2->setFrameShadow(QFrame::Raised);
        frame_dark_2->setMidLineWidth(1);
        horizontalLayout_9 = new QHBoxLayout(frame_dark_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalGroupBox_21 = new QGroupBox(frame_dark_2);
        verticalGroupBox_21->setObjectName(QString::fromUtf8("verticalGroupBox_21"));
        verticalGroupBox_21->setCheckable(true);
        verticalLayout_6 = new QVBoxLayout(verticalGroupBox_21);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(verticalGroupBox_21);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        gr_lk_api_key = new QGroupBox(verticalGroupBox_21);
        gr_lk_api_key->setObjectName(QString::fromUtf8("gr_lk_api_key"));
        gr_lk_api_key->setCheckable(true);
        gr_lk_api_key->setChecked(false);
        horizontalLayout_4 = new QHBoxLayout(gr_lk_api_key);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ledt_lk_api_key = new QLineEdit(gr_lk_api_key);
        ledt_lk_api_key->setObjectName(QString::fromUtf8("ledt_lk_api_key"));
        ledt_lk_api_key->setEnabled(true);
        ledt_lk_api_key->setMaximumSize(QSize(1111111, 16777215));
        ledt_lk_api_key->setInputMask(QString::fromUtf8(""));
        ledt_lk_api_key->setText(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(ledt_lk_api_key);


        gridLayout->addWidget(gr_lk_api_key, 0, 5, 2, 1);

        ledt_inn_uot = new QLineEdit(verticalGroupBox_21);
        ledt_inn_uot->setObjectName(QString::fromUtf8("ledt_inn_uot"));
        ledt_inn_uot->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(ledt_inn_uot, 1, 2, 1, 1);

        cmb_api_version = new QComboBox(verticalGroupBox_21);
        cmb_api_version->setObjectName(QString::fromUtf8("cmb_api_version"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmb_api_version->sizePolicy().hasHeightForWidth());
        cmb_api_version->setSizePolicy(sizePolicy1);
        cmb_api_version->setMinimumSize(QSize(170, 0));
        cmb_api_version->setMaximumSize(QSize(50, 16777215));
        cmb_api_version->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(cmb_api_version, 1, 3, 1, 1);

        ledt_thumbprint = new QLineEdit(verticalGroupBox_21);
        ledt_thumbprint->setObjectName(QString::fromUtf8("ledt_thumbprint"));
        ledt_thumbprint->setMinimumSize(QSize(400, 0));
        ledt_thumbprint->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(ledt_thumbprint, 0, 2, 1, 1);

        label_5 = new QLabel(verticalGroupBox_21);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        cmb_konturType = new QComboBox(verticalGroupBox_21);
        cmb_konturType->setObjectName(QString::fromUtf8("cmb_konturType"));
        cmb_konturType->setMinimumSize(QSize(170, 0));

        gridLayout->addWidget(cmb_konturType, 0, 3, 1, 1);


        verticalLayout_6->addLayout(gridLayout);


        horizontalLayout_9->addWidget(verticalGroupBox_21);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_5->addWidget(frame_dark_2);

        frame_dark_5 = new QFrame(scrollAreaWidgetContents);
        frame_dark_5->setObjectName(QString::fromUtf8("frame_dark_5"));
        frame_dark_5->setFrameShape(QFrame::NoFrame);
        frame_dark_5->setFrameShadow(QFrame::Raised);
        frame_dark_5->setMidLineWidth(1);
        verticalLayout_4 = new QVBoxLayout(frame_dark_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        gr = new QGroupBox(frame_dark_5);
        gr->setObjectName(QString::fromUtf8("gr"));
#ifndef QT_NO_TOOLTIP
        gr->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        gr->setAutoFillBackground(true);
        gr->setTitle(QString::fromUtf8("\320\247\320\265\321\201\321\202\320\275\321\213\320\271 \320\267\320\275\320\260\320\272:"));
        gr->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gr->setFlat(false);
        gr->setCheckable(true);
        formLayout_2 = new QFormLayout(gr);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_get_api_key = new QPushButton(gr);
        btn_get_api_key->setObjectName(QString::fromUtf8("btn_get_api_key"));
        btn_get_api_key->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_api_key->sizePolicy().hasHeightForWidth());
        btn_get_api_key->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, btn_get_api_key);

        ledt_api_key = new QLineEdit(gr);
        ledt_api_key->setObjectName(QString::fromUtf8("ledt_api_key"));
        ledt_api_key->setMinimumSize(QSize(200, 0));
        ledt_api_key->setInputMask(QString::fromUtf8(""));
        ledt_api_key->setText(QString::fromUtf8(""));
        ledt_api_key->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, ledt_api_key);

        btn_get_auth_simpleSignIn = new QPushButton(gr);
        btn_get_auth_simpleSignIn->setObjectName(QString::fromUtf8("btn_get_auth_simpleSignIn"));
        btn_get_auth_simpleSignIn->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_auth_simpleSignIn->sizePolicy().hasHeightForWidth());
        btn_get_auth_simpleSignIn->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, btn_get_auth_simpleSignIn);

        ledt_auth_simpleSignIn = new QLineEdit(gr);
        ledt_auth_simpleSignIn->setObjectName(QString::fromUtf8("ledt_auth_simpleSignIn"));
        ledt_auth_simpleSignIn->setInputMask(QString::fromUtf8(""));
        ledt_auth_simpleSignIn->setText(QString::fromUtf8(""));
        ledt_auth_simpleSignIn->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, ledt_auth_simpleSignIn);

        btn_get_auth_permissive_access = new QPushButton(gr);
        btn_get_auth_permissive_access->setObjectName(QString::fromUtf8("btn_get_auth_permissive_access"));
        btn_get_auth_permissive_access->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_auth_permissive_access->sizePolicy().hasHeightForWidth());
        btn_get_auth_permissive_access->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, btn_get_auth_permissive_access);

        ledt_auth_permissive_access = new QLineEdit(gr);
        ledt_auth_permissive_access->setObjectName(QString::fromUtf8("ledt_auth_permissive_access"));
        ledt_auth_permissive_access->setMaximumSize(QSize(300, 16777215));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, ledt_auth_permissive_access);

        ledt_access_token_id = new QLineEdit(gr);
        ledt_access_token_id->setObjectName(QString::fromUtf8("ledt_access_token_id"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, ledt_access_token_id);


        horizontalLayout_10->addWidget(gr);

        groupBox = new QGroupBox(frame_dark_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(11, 11, -1, -1);
        btn_get_cises_ease_info = new QPushButton(groupBox);
        btn_get_cises_ease_info->setObjectName(QString::fromUtf8("btn_get_cises_ease_info"));
        btn_get_cises_ease_info->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_cises_ease_info->sizePolicy().hasHeightForWidth());
        btn_get_cises_ease_info->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_cises_ease_info, 1, 3, 1, 1);

        btn_get_codes_check = new QPushButton(groupBox);
        btn_get_codes_check->setObjectName(QString::fromUtf8("btn_get_codes_check"));
        btn_get_codes_check->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_codes_check->sizePolicy().hasHeightForWidth());
        btn_get_codes_check->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_codes_check, 1, 1, 1, 1);

        btn_get_nk_short_product = new QPushButton(groupBox);
        btn_get_nk_short_product->setObjectName(QString::fromUtf8("btn_get_nk_short_product"));
        btn_get_nk_short_product->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_nk_short_product->sizePolicy().hasHeightForWidth());
        btn_get_nk_short_product->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_nk_short_product, 2, 1, 1, 1);

        btn_get_cises_check = new QPushButton(groupBox);
        btn_get_cises_check->setObjectName(QString::fromUtf8("btn_get_cises_check"));
        btn_get_cises_check->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_cises_check->sizePolicy().hasHeightForWidth());
        btn_get_cises_check->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_cises_check, 2, 3, 1, 1);

        btn_get_cises_info = new QPushButton(groupBox);
        btn_get_cises_info->setObjectName(QString::fromUtf8("btn_get_cises_info"));
        btn_get_cises_info->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_cises_info->sizePolicy().hasHeightForWidth());
        btn_get_cises_info->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_cises_info, 0, 3, 1, 1);

        btn_get_product_info = new QPushButton(groupBox);
        btn_get_product_info->setObjectName(QString::fromUtf8("btn_get_product_info"));
        btn_get_product_info->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_product_info->sizePolicy().hasHeightForWidth());
        btn_get_product_info->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_product_info, 0, 1, 1, 1);

        btn_get_nk_feed_product = new QPushButton(groupBox);
        btn_get_nk_feed_product->setObjectName(QString::fromUtf8("btn_get_nk_feed_product"));
        btn_get_nk_feed_product->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_nk_feed_product->sizePolicy().hasHeightForWidth());
        btn_get_nk_feed_product->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_nk_feed_product, 3, 1, 1, 1);

        btn_get_nk_product = new QPushButton(groupBox);
        btn_get_nk_product->setObjectName(QString::fromUtf8("btn_get_nk_product"));
        btn_get_nk_product->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_nk_product->sizePolicy().hasHeightForWidth());
        btn_get_nk_product->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_get_nk_product, 3, 3, 1, 1);


        horizontalLayout_10->addWidget(groupBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_5->addWidget(frame_dark_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        verticalLayout_5->addLayout(horizontalLayout_5);

        frame_dark_3 = new QFrame(scrollAreaWidgetContents);
        frame_dark_3->setObjectName(QString::fromUtf8("frame_dark_3"));
        frame_dark_3->setStyleSheet(QString::fromUtf8(""));
        frame_dark_3->setFrameShape(QFrame::NoFrame);
        frame_dark_3->setFrameShadow(QFrame::Raised);
        frame_dark_3->setLineWidth(1);
        frame_dark_3->setMidLineWidth(1);
        horizontalLayout_3 = new QHBoxLayout(frame_dark_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox1 = new QGroupBox(frame_dark_3);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        groupBox1->setFlat(false);
        groupBox1->setCheckable(true);
        horizontalLayout_6 = new QHBoxLayout(groupBox1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_chzn_validate = new QPushButton(groupBox1);
        btn_chzn_validate->setObjectName(QString::fromUtf8("btn_chzn_validate"));
        btn_chzn_validate->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_chzn_validate->sizePolicy().hasHeightForWidth());
        btn_chzn_validate->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btn_chzn_validate, 2, 1, 1, 1);

        btn_getCdnHosts = new QPushButton(groupBox1);
        btn_getCdnHosts->setObjectName(QString::fromUtf8("btn_getCdnHosts"));
        btn_getCdnHosts->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_getCdnHosts->sizePolicy().hasHeightForWidth());
        btn_getCdnHosts->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btn_getCdnHosts, 1, 1, 1, 1);

        cmb_cdb_list = new QComboBox(groupBox1);
        cmb_cdb_list->setObjectName(QString::fromUtf8("cmb_cdb_list"));
        cmb_cdb_list->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(cmb_cdb_list, 1, 2, 1, 1);

        ledt_lk_kkt_token = new QLineEdit(groupBox1);
        ledt_lk_kkt_token->setObjectName(QString::fromUtf8("ledt_lk_kkt_token"));
        ledt_lk_kkt_token->setMinimumSize(QSize(350, 0));
        ledt_lk_kkt_token->setMaximumSize(QSize(400, 16777215));
        ledt_lk_kkt_token->setPlaceholderText(QString::fromUtf8("\320\242\320\276\320\272\320\265\320\275 \320\264\320\273\321\217 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\276 \320\272\320\260\321\201\321\201\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320\270\320\272\320\270 \320\270\320\267 \320\273\320\272 (\321\207\320\265\321\201\321\202\320\275\320\276\320\263\320\276 \320\267\320\275\320\260\320\272\320\260) : "));

        gridLayout_2->addWidget(ledt_lk_kkt_token, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(222222, 16777215));
        label_3->setWordWrap(true);

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        btn_chzn_cdn_host_check = new QPushButton(groupBox1);
        btn_chzn_cdn_host_check->setObjectName(QString::fromUtf8("btn_chzn_cdn_host_check"));
        btn_chzn_cdn_host_check->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_chzn_cdn_host_check->sizePolicy().hasHeightForWidth());
        btn_chzn_cdn_host_check->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btn_chzn_cdn_host_check, 1, 3, 1, 1);

        btn_get_cises_check_history_create = new QPushButton(groupBox1);
        btn_get_cises_check_history_create->setObjectName(QString::fromUtf8("btn_get_cises_check_history_create"));
        btn_get_cises_check_history_create->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_cises_check_history_create->sizePolicy().hasHeightForWidth());
        btn_get_cises_check_history_create->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btn_get_cises_check_history_create, 2, 2, 1, 1);

        btn_get_cises_check_history_receive = new QPushButton(groupBox1);
        btn_get_cises_check_history_receive->setObjectName(QString::fromUtf8("btn_get_cises_check_history_receive"));
        btn_get_cises_check_history_receive->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_get_cises_check_history_receive->sizePolicy().hasHeightForWidth());
        btn_get_cises_check_history_receive->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btn_get_cises_check_history_receive, 2, 3, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_2);


        horizontalLayout_3->addWidget(groupBox1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addWidget(frame_dark_3);

        frame_dark_4 = new QFrame(scrollAreaWidgetContents);
        frame_dark_4->setObjectName(QString::fromUtf8("frame_dark_4"));
        frame_dark_4->setFrameShape(QFrame::NoFrame);
        frame_dark_4->setFrameShadow(QFrame::Raised);
        frame_dark_4->setMidLineWidth(1);
        horizontalLayout_11 = new QHBoxLayout(frame_dark_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalGroupBox = new QGroupBox(frame_dark_4);
        verticalGroupBox->setObjectName(QString::fromUtf8("verticalGroupBox"));
        verticalGroupBox->setTitle(QString::fromUtf8("\320\273\320\276\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \320\274\320\276\320\264\321\203\320\273\321\214"));
        verticalGroupBox->setCheckable(true);
        verticalLayout_9 = new QVBoxLayout(verticalGroupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(verticalGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        ledt_lm_login = new QLineEdit(verticalGroupBox);
        ledt_lm_login->setObjectName(QString::fromUtf8("ledt_lm_login"));

        horizontalLayout_8->addWidget(ledt_lm_login);

        label_8 = new QLabel(verticalGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        ledt_lm_pw = new QLineEdit(verticalGroupBox);
        ledt_lm_pw->setObjectName(QString::fromUtf8("ledt_lm_pw"));
        ledt_lm_pw->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        ledt_lm_pw->setInputMask(QString::fromUtf8(""));
        ledt_lm_pw->setText(QString::fromUtf8(""));
        ledt_lm_pw->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(ledt_lm_pw);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_9->addLayout(horizontalLayout_8);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(11, 11, -1, -1);
        label_6 = new QLabel(verticalGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        btn_lm_init = new QPushButton(verticalGroupBox);
        btn_lm_init->setObjectName(QString::fromUtf8("btn_lm_init"));

        gridLayout_5->addWidget(btn_lm_init, 0, 2, 1, 1);

        ledt_fn_num = new QLineEdit(verticalGroupBox);
        ledt_fn_num->setObjectName(QString::fromUtf8("ledt_fn_num"));

        gridLayout_5->addWidget(ledt_fn_num, 0, 1, 1, 1);

        btn_lm_status = new QPushButton(verticalGroupBox);
        btn_lm_status->setObjectName(QString::fromUtf8("btn_lm_status"));

        gridLayout_5->addWidget(btn_lm_status, 0, 3, 1, 1);

        btn_lm_cis_check = new QPushButton(verticalGroupBox);
        btn_lm_cis_check->setObjectName(QString::fromUtf8("btn_lm_cis_check"));

        gridLayout_5->addWidget(btn_lm_cis_check, 0, 4, 1, 1);

        btn_lm_cis_check_old = new QPushButton(verticalGroupBox);
        btn_lm_cis_check_old->setObjectName(QString::fromUtf8("btn_lm_cis_check_old"));

        gridLayout_5->addWidget(btn_lm_cis_check_old, 0, 5, 1, 1);

        btn_lm_cis_outCheck = new QPushButton(verticalGroupBox);
        btn_lm_cis_outCheck->setObjectName(QString::fromUtf8("btn_lm_cis_outCheck"));

        gridLayout_5->addWidget(btn_lm_cis_outCheck, 0, 6, 1, 1);

        btn_lm_cis_outCheck_post = new QPushButton(verticalGroupBox);
        btn_lm_cis_outCheck_post->setObjectName(QString::fromUtf8("btn_lm_cis_outCheck_post"));

        gridLayout_5->addWidget(btn_lm_cis_outCheck_post, 0, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 8, 1, 1);


        verticalLayout_9->addLayout(gridLayout_5);


        horizontalLayout_11->addWidget(verticalGroupBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);


        verticalLayout_5->addWidget(frame_dark_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btn_log = new QPushButton(scrollAreaWidgetContents);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_log->sizePolicy().hasHeightForWidth());
        btn_log->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(btn_log, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 3, 1, 1);

        lbl_tempDir = new QLabel(scrollAreaWidgetContents);
        lbl_tempDir->setObjectName(QString::fromUtf8("lbl_tempDir"));
        lbl_tempDir->setText(QString::fromUtf8("\320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275\320\260"));
        lbl_tempDir->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_4->addWidget(lbl_tempDir, 1, 2, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Chzn_Test_Dlg);

        QMetaObject::connectSlotsByName(Chzn_Test_Dlg);
    } // setupUi

    void retranslateUi(QFrame *Chzn_Test_Dlg)
    {
        Chzn_Test_Dlg->setWindowTitle(QApplication::translate("Chzn_Test_Dlg", "Dialog", 0, QApplication::UnicodeUTF8));
        verticalGroupBox_2->setTitle(QApplication::translate("Chzn_Test_Dlg", "\321\201\321\207\320\270\321\202\321\213\320\262\320\260\320\275\320\270\320\265 \320\272\320\276\320\264\320\260 \321\201\320\272\320\260\320\275\320\265\321\200\320\276\320\274 : ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_scan_bar_code->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_scan_bar_code->setText(QApplication::translate("Chzn_Test_Dlg", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \321\201\320\272\320\260\320\275\320\265\321\200\320\276\320\274 \320\272\320\276\320\264 \320\274\320\260\321\200\320\272\320\270\321\200\320\276\320\262\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Chzn_Test_Dlg", "gtin:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Chzn_Test_Dlg", "\320\232\320\230 : ", 0, QApplication::UnicodeUTF8));
        verticalGroupBox_21->setTitle(QApplication::translate("Chzn_Test_Dlg", "\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 : ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Chzn_Test_Dlg", "\320\276\321\202\320\277\320\265\321\207\320\260\321\202\320\276\320\272 \320\255\320\246\320\237 \320\243\320\236\320\242 (thumbprint) : ", 0, QApplication::UnicodeUTF8));
        gr_lk_api_key->setTitle(QApplication::translate("Chzn_Test_Dlg", "api key", 0, QApplication::UnicodeUTF8));
        ledt_lk_api_key->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "API KEY \320\270\320\267 \320\233\320\232", 0, QApplication::UnicodeUTF8));
        ledt_inn_uot->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "\320\230\320\235\320\235 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260 \320\276\320\261\320\276\321\200\320\276\321\202\320\260 \321\202\320\276\320\262\320\260\321\200\320\276\320\262 (\320\243\320\236\320\242)", 0, QApplication::UnicodeUTF8));
        cmb_api_version->clear();
        cmb_api_version->insertItems(0, QStringList()
         << QApplication::translate("Chzn_Test_Dlg", "v3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Chzn_Test_Dlg", "v4", 0, QApplication::UnicodeUTF8)
        );
        ledt_thumbprint->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "\320\276\321\202\320\277\320\265\321\207\320\260\321\202\320\276\320\272 \320\255\320\246\320\237 \320\243\320\236\320\242 (thumbprint)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Chzn_Test_Dlg", "\320\230\320\235\320\235 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260 \320\276\320\261\320\276\321\200\320\276\321\202\320\260 \321\202\320\276\320\262\320\260\321\200\320\276\320\262 (\320\243\320\236\320\242) : ", 0, QApplication::UnicodeUTF8));
        cmb_konturType->clear();
        cmb_konturType->insertItems(0, QStringList()
         << QApplication::translate("Chzn_Test_Dlg", "\320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\270\320\262\320\275\321\213\320\271 \320\272\320\276\320\275\321\202\321\203\321\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Chzn_Test_Dlg", "\321\202\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \320\272\320\276\320\275\321\202\321\203\321\200", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        btn_get_api_key->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_api_key->setText(QApplication::translate("Chzn_Test_Dlg", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\202\320\276\320\272\320\265\320\275 \320\260\321\203\321\202\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270 \321\201 \320\247\320\227", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ledt_api_key->setToolTip(QApplication::translate("Chzn_Test_Dlg", "api/key \320\264\320\273\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270 \320\277\320\276\320\264\320\277\320\270\321\201\320\270 \321\201\321\202\321\200\320\276\320\272\320\270 \321\201\320\276\320\264\320\265\321\200\320\260\320\266\320\275\320\270\321\217 data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ledt_api_key->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "/api/key", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_auth_simpleSignIn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_auth_simpleSignIn->setText(QApplication::translate("Chzn_Test_Dlg", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\202\320\276\320\272\320\265\320\275 \320\260\321\203\321\202\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270 \321\201 \320\247\320\227 (Bearer)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ledt_auth_simpleSignIn->setToolTip(QApplication::translate("Chzn_Test_Dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.5pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#008000;\">Bearer token</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ledt_auth_simpleSignIn->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "/auth/simpleSignIn", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_auth_permissive_access->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_auth_permissive_access->setText(QApplication::translate("Chzn_Test_Dlg", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\202\320\276\320\272\320\265\320\275 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        ledt_auth_permissive_access->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "access_token  /auth/permissive-access", 0, QApplication::UnicodeUTF8));
        ledt_access_token_id->setText(QString());
        ledt_access_token_id->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "token_id (\320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270) /auth/permissive-access", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Chzn_Test_Dlg", "\320\277\321\200\320\276\320\261\321\203\320\265\320\274 \320\274\320\265\321\202\320\276\320\264\321\213 \320\220\320\237\320\230 : ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_cises_ease_info->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_cises_ease_info->setText(QApplication::translate("Chzn_Test_Dlg", "/cises/eaes/info", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_codes_check->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_codes_check->setText(QApplication::translate("Chzn_Test_Dlg", "/codes/check", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_nk_short_product->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_nk_short_product->setText(QApplication::translate("Chzn_Test_Dlg", "/nk/short-product", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_cises_check->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_cises_check->setText(QApplication::translate("Chzn_Test_Dlg", "/cises/check v3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_cises_info->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_cises_info->setText(QApplication::translate("Chzn_Test_Dlg", "/cises/info v3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_product_info->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_product_info->setText(QApplication::translate("Chzn_Test_Dlg", "/product/info v4", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_nk_feed_product->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_nk_feed_product->setText(QApplication::translate("Chzn_Test_Dlg", "/nk/feed-product", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_nk_product->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_nk_product->setText(QApplication::translate("Chzn_Test_Dlg", "/nk/product", 0, QApplication::UnicodeUTF8));
        groupBox1->setTitle(QApplication::translate("Chzn_Test_Dlg", "cdn", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_chzn_validate->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_chzn_validate->setText(QApplication::translate("Chzn_Test_Dlg", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\232\320\234 \321\207\320\265\321\200\320\265\320\267 \321\207\320\265\321\201\321\202\320\275\321\213\320\271 \320\267\320\275\320\260\320\272 (/codes/check)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_getCdnHosts->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_getCdnHosts->setText(QApplication::translate("Chzn_Test_Dlg", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 cdn \320\277\320\273\320\276\321\211\320\260\320\264\320\276\320\272 \320\264\320\273\321\217 \321\202\320\276\320\272\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        ledt_lk_kkt_token->setText(QString());
        label_3->setText(QApplication::translate("Chzn_Test_Dlg", "\320\242\320\276\320\272\320\265\320\275 \320\264\320\273\321\217 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\276 \320\272\320\260\321\201\321\201\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320\270\320\272\320\270 \320\270\320\267 \320\273\320\272 (\321\207\320\265\321\201\321\202\320\275\320\276\320\263\320\276 \320\267\320\275\320\260\320\272\320\260) : ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_chzn_cdn_host_check->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_chzn_cdn_host_check->setText(QApplication::translate("Chzn_Test_Dlg", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 CDN-\320\277\320\273\320\276\321\211\320\260\320\264\320\272\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_cises_check_history_create->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_cises_check_history_create->setText(QApplication::translate("Chzn_Test_Dlg", "/codes/check/history/create", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_get_cises_check_history_receive->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_get_cises_check_history_receive->setText(QApplication::translate("Chzn_Test_Dlg", " /codes/check/history/receive", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Chzn_Test_Dlg", "\320\273\320\276\320\263\320\270\320\275 : ", 0, QApplication::UnicodeUTF8));
        ledt_lm_login->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "\320\273\320\276\320\263\320\270\320\275 \320\277\321\200\320\270 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\265 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\274\320\276\320\264\321\203\320\273\321\217 ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Chzn_Test_Dlg", "\320\277\320\260\321\200\320\276\320\273\321\214 : ", 0, QApplication::UnicodeUTF8));
        ledt_lm_pw->setPlaceholderText(QApplication::translate("Chzn_Test_Dlg", "\320\277\320\260\321\200\320\276\320\273\321\214 \320\277\321\200\320\270 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\265 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\274\320\276\320\264\321\203\320\273\321\217 ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Chzn_Test_Dlg", "\320\244\320\235 \342\204\226:", 0, QApplication::UnicodeUTF8));
        btn_lm_init->setText(QApplication::translate("Chzn_Test_Dlg", "/init", 0, QApplication::UnicodeUTF8));
        btn_lm_status->setText(QApplication::translate("Chzn_Test_Dlg", "/status", 0, QApplication::UnicodeUTF8));
        btn_lm_cis_check->setText(QApplication::translate("Chzn_Test_Dlg", "/cis/check", 0, QApplication::UnicodeUTF8));
        btn_lm_cis_check_old->setText(QApplication::translate("Chzn_Test_Dlg", "/cis/check (post)", 0, QApplication::UnicodeUTF8));
        btn_lm_cis_outCheck->setText(QApplication::translate("Chzn_Test_Dlg", "/cis/out\320\241heck", 0, QApplication::UnicodeUTF8));
        btn_lm_cis_outCheck_post->setText(QApplication::translate("Chzn_Test_Dlg", "/cis/out\320\241heck (post)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_log->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_log->setText(QApplication::translate("Chzn_Test_Dlg", "\320\273\320\276\320\263 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Chzn_Test_Dlg", "\320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217 \320\264\320\273\321\217 \320\273\320\276\320\263\320\276\320\262 : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Chzn_Test_Dlg: public Ui_Chzn_Test_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHZN_TEST_WGT_H
