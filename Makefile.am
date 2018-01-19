### Makefile.am
### Copyright 2012 Mac Radigan
### All Rights Reserved

AM_LDFLAGS  = -pthread                                                         \
              -L/usr/lib -ldl -lm                                              \
              -L/usr/lib/x86_64-linux-gnu -lgflags                             \
              -lstdc++fs                                                       \
              -lltdl                                                            

AM_CPPFLAGS = -I$(top_srcdir)/include                                          \
              -std=c++1z                                                       \
              -O3
AM_FCFLAGS  = -Jmod

hdf5tree_ldadd             = libhdf5tree.la                                    \
                             -ldl -lm                                          \
                             -lrt                                              \
                             -lstdc++fs                                        \
                             -lltdl                                             

bin_PROGRAMS               = hdf5tree                                          \
                             hdf5dump                                          \
                             test_hdf5tree

hdf5dump_SOURCES           = src/apps/hdf5dump.cc
hdf5dump_LDADD             = $(hdf5tree_ldadd)

test_hdf5tree_SOURCES      = src/tests/test_hdf5tree.cc
test_hdf5tree_LDADD        = $(hdf5tree_ldadd)

hdf5tree_SOURCES           = src/apps/hdf5tree.cc
hdf5tree_LDADD             = $(hdf5tree_ldadd)

lib_LTLIBRARIES            = libhdf5tree.la                                     

libhdf5tree_la_SOURCES     = src/packages/hdf5tree/hdf5tree.cc
libhdf5tree_la_LIBADD      = -L/usr/lib/x86_64-linux-gnu -lrt
libhdf5tree_la_LDFLAGS     = -export-symbols-regex '^hdf5tree_[^_]' -fPIC      \
                             -shared -pthread                                  \
                             -L/usr/lib/x86_64-linux-gnu -lrt                   

pkginclude_HEADERS         = include/packages/hdf5tree/hdf5tree.h

### *EOF*
