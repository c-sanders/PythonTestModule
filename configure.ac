# ------------------------------------------------------------------------------
# Filename : configure.ac
# =======================
#
# Process this file with autoconf to produce a configure script.
# ------------------------------------------------------------------------------


# AC_INIT([#		Simple Scanner generated using GNU Flex],[#		0.0.1],[#		support@gravitas.com],[#		SimpleScanner],[#		http://www.gravitas-toolworks.com])

AC_INIT([SignalSlotExample],
        [0.0.1])

AC_CONFIG_SRCDIR([src/signalSlotTest.cpp])

AC_CONFIG_AUX_DIR(config)

AM_INIT_AUTOMAKE([subdir-objects])

AC_CONFIG_MACRO_DIR([m4])

AX_BOOST_BASE

# AC_PROG_LIBTOOL

AC_PROG_RANLIB
AM_PROG_AR
LT_INIT

AC_CONFIG_FILES([Makefile src/Makefile])

AC_PROG_CC
AC_PROG_CXX([${CXX}])

AC_OUTPUT

