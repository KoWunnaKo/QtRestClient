TEMPLATE = subdirs

SUBDIRS = qrestbuilder

qrestbuilder.CONFIG += no_lrelease_target

prepareRecursiveTarget(lrelease)
QMAKE_EXTRA_TARGETS += lrelease
