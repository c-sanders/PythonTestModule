# Makefile.am for package : simpleLexicalAnalyser
# ==============================================================================
#
# GNU Automake automatically provides three '-I' options, and they are ;
#
#   -I.
#   -I${srcdir}
#   -I which points to the directory holding 'config.h'
#
# The last '-I' option will be provided if AC_CONFIG_HEADERS or 
# AM_CONFIG_HEADERS is called within the configure.ac file.
#
# You can disable the default '-I' options using the 'nostdinc' option. - Page
# 68 of Automake version 1.10 manual.
# ------------------------------------------------------------------------------

ACLOCAL_AMFLAGS = -I m4


vpath %.hpp   ${top_srcdir}/include
vpath %.cpp   ${srcdir}
vpath %.o     ${srcdir}


# Primaries
# ---------

bin_PROGRAMS = signalSlotTest


all : signalSlotTest


# ================================================================================
# Target 1) - signalSlotTest
# ================================================================================
#
#   > make quaternionTest
#
# will make this target. Note that the target name is in lower camel case.
#
# ================================================================================

signalSlotTest_SOURCES  = signalSlotTest.cpp \
                          CustomSlot.cpp \
                          RegistrySlots.cpp

signalSlotTest_INCLUDES = -I${top_srcdir}/include

signalSlotTest_CPPFLAGS = -DHAVE_CONFIG_H \
                           ${signalSlotTest_INCLUDES}

signalSlotTest_LDFLAGS  = # -lfl


lib_LTLIBRARIES             = libCustomSlot.la \
                              libPythonTestModule.la


# ================================================================================
# Target 2) - libCustomSlot.la
# ================================================================================
#
# Building the library from within this directory
#
#   > make libCustomSlot.la
#
# Building the library from within the parent directory
#
#   > make libCustomSlot.la -C src
#
# ================================================================================
#
# This library makes use of two other libraries;
#
#   - python3.13       # Python runtime library
#   - boost_python313  # Boost Python library
#
# ================================================================================

libCustomSlot_la_SOURCES    = CustomSlot.cpp
libCustomSlot_la_CPPFLAGS   = -I../include -I/usr/include/python3.13
# libCustomSlot_la_INCLUDES = -I../include
libCustomSlot_la_LDFLAGS    =
libCustomSlot_la_LIBADD     = -lpython3.13 -lboost_python313
# include_HEADERS           = -I../include


# ================================================================================
# Target 3) - libPythonTestModule.la
# ================================================================================
#
# Building the library from within this directory
#
#   > make libPythonTestModule.la
#
# Building the library from within the parent directory
#
#   > make libPythonTestModule.la -C src
#
# ================================================================================
#
# This library makes use of two other libraries;
#
#   - python3.13       # Python runtime library
#   - boost_python313  # Boost Python library
#
# ================================================================================

libPythonTestModule_la_SOURCES    = PythonTestModule.cpp
libPythonTestModule_la_CPPFLAGS   = -I../include -I/usr/include/python3.13
# libPythonTestModule_la_INCLUDES = -I../include
libPythonTestModule_la_LDFLAGS    =
libPythonTestModule_la_LIBADD     = -lpython3.13 -lboost_python313
# include_HEADERS           = -I../include


# .c.o :
# 	@echo "@< ="
#	${CXX} -g -Wall ${signalSlotTest_CPPFLAGS} $<


dummy : signalSlotTest

	echo "${@}"
	echo "${<}"
	echo "${#}"


# Executable target : help
# ------------------------

h    : help
help :
	@echo "                                                                                "
	@echo "This Makefile contains a number of targets and these targets can be divided up  "
	@echo "into two categories; 1) Build based targets, or 2) Ancilliary targets.          "
	@echo "                                                                                "
	@echo "  1) Build based targets                                                        "
	@echo "                                                                                "
	@echo "    - quaternionTest                                                            "
	@echo "                                                                                "
	@echo "  2) Ancilliary targets                                                         "
	@echo "                                                                                "
	@echo "    - clean | c                                                                 "
	@echo "    - archive | a                                                               "
	@echo "    - tar (defaults to tar, i.e. Tape ARchive)                                  "
	@echo "    - help | h                                                                  "
	@echo "    - reset | r                                                                 "
	@echo "    - test                                                                      "
	@echo "    - packageChecker | p                                                        "
	@echo "                                                                                "


# Miscellaneous executable targets
# --------------------------------

.PHONY : displaySettings
displaySettings :
	@echo "BASH           = ${SHELL}"
	@echo "SH             = ${SH}"
	@echo ""
	@echo "top_srcdir     = ${top_srcdir}"
	@echo "srcdir         = ${srcdir}"
	@echo ""
	@echo "builddir       = ${builddir}"
	@echo "abs_builddir   = ${abs_builddir}"
	@echo "top_builddir   = ${top_builddir}"
	@echo ""
	@echo "quaternionTest_INCLUDES = ${quaternionTest_INCLUDES}"
	@echo "quaternionTest_CPPFLAGS = ${quaternionTest_CPPFLAGS}"
