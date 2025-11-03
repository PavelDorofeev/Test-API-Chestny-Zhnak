TEMPLATE = subdirs

CONFIG += ordered

win32:SRC_SUBDIRS += chzn
chzn.subdir = $$PWD/chzn
chzn.target = sub-chzn

win32:SRC_SUBDIRS += chzn_api_test
chzn_api_test.subdir = $$PWD/chzn_api_test
chzn_api_test.target = sub-chzn_api_test
chzn_api_test.depends +=  chzn


SUBDIRS += $$SRC_SUBDIRS
