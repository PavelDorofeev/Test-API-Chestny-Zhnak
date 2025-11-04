TEMPLATE = subdirs

CONFIG += ordered

win32:SRC_SUBDIRS += qp
qp.subdir = $$PWD/../qp
qp.target = sub-qp

win32:SRC_SUBDIRS += kb_wgt
kb_wgt.subdir = $$PWD/../kb_scanner/kb_wgt
kb_wgt.target = sub-kb_wgt

win32:SRC_SUBDIRS += chzn
chzn.subdir = $$PWD/chzn
chzn.target = sub-chzn
chzn.depends += qp kb_wgt

win32:SRC_SUBDIRS += chzn_api_test
chzn_api_test.subdir = $$PWD/chzn_api_test
chzn_api_test.target = sub-chzn_api_test
chzn_api_test.depends +=  chzn qp kb_wgt


SUBDIRS += $$SRC_SUBDIRS
