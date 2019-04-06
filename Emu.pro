TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = mueb \
          emu

emu.depends = mueb
