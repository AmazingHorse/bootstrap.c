#                                               -*- Autoconf -*-
AC_PREREQ([2.64])

AC_INIT([{{cookiecutter.project_name}}],
        [m4_esyscmd_s([./get-version])],
        [{{cookiecutter.email}}])
AC_CONFIG_SRCDIR([src/log.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror tar-ustar subdir-objects])
AM_MAINTAINER_MODE
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES(yes)])
m4_pattern_allow([AM_PROG_AR])
AM_PROG_AR

# Configure libtool
LT_INIT

#######################
### Checks

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CXX
ACX_PTHREAD([have_pthread=yes], [have_pthread=no])
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_EGREP

# Define variables for unit test using gtest
GTEST_VERSION="1.6.0"
if test "x$have_pthread" = "xyes"; then
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=1 -I\$(top_srcdir)/lib/gmock"
  GTEST_CXXFLAGS="$PTHREAD_CFLAGS"
  GTEST_LDFLAGS="-L\$(top_builddir)/lib/gmock"
  GTEST_LIBS="$PTHREAD_LIBS"
else
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=0 -I\$(top_srcdir)/lib/gmock"
  GTEST_CXXFLAGS=
  GTEST_LDFLAGS="-L\$(top_builddir)/lib/gmock"
  GTEST_LIBS=
fi
AC_SUBST([GTEST_VERSION])
AC_SUBST([GTEST_CPPFLAGS])
AC_SUBST([GTEST_CXXFLAGS])
AC_SUBST([GTEST_LDFLAGS])
AC_SUBST([GTEST_LIBS])

# Check some compiler flags
AX_CFLAGS_GCC_OPTION([-fdiagnostics-show-option],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-pipe],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wall],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-W],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wextra],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wformat],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wformat-security],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wfatal-errors],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wcast-align],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Winline],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-fstack-protector],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-D_FORTIFY_SOURCE=2],[MORE_CPPFLAGS])
AX_CFLAGS_GCC_OPTION([-Wno-unused-parameter],[MORE_CFLAGS])
AX_CFLAGS_GCC_OPTION([-Wno-missing-field-initializers],[MORE_CFLAGS])
AX_LDFLAGS_OPTION([-Wl,-z,relro],[MORE_LDFLAGS])
AX_LDFLAGS_OPTION([-Wl,-z,now],[MORE_LDFLAGS])

dnl Enable _GNU_SOURCE and the like
AX_CFLAGS_GCC_OPTION([-D_GNU_SOURCE],[MORE_CPPFLAGS])    dnl GNU systems (asprintf, ...)
case $host_os in
   solaris*)
     AX_CFLAGS_GCC_OPTION([-D__EXTENSIONS__],[MORE_CPPFLAGS]) dnl (CMSG_*)
     AX_CFLAGS_GCC_OPTION([-D_XPG4_2],[MORE_CPPFLAGS])        dnl (CMSG_*)
     ;;
   hpux*)
     AX_CFLAGS_GCC_OPTION([-D_XOPEN_SOURCE=500],[MORE_CPPFLAGS])      dnl HP-UX
     AX_CFLAGS_GCC_OPTION([-D_XOPEN_SOURCE_EXTENDED],[MORE_CPPFLAGS]) dnl HP-UX
     ;;
esac

AC_CACHE_SAVE

## TODO:2003 Add the dependencies of your project here. An example is commented.

##PKG_CHECK_MODULES([JANSSON], [jansson >= 2.1])

AC_CACHE_SAVE

AC_SUBST([MORE_CFLAGS])
AC_SUBST([MORE_CPPFLAGS])
AC_SUBST([MORE_LDFLAGS])
AC_OUTPUT

cat <<EOF

------------------ Summary ------------------
 $PACKAGE_NAME version $PACKAGE_VERSION
  Prefix.........: $prefix
  C Compiler.....: $CC $MORE_CFLAGS $MORE_CPPFLAGS $CFLAGS $CPPFLAGS
  Linker.........: $LD $MORE_LDFLAGS $LDFLAGS $LIBS
---------------------------------------------

Check the above options and compile with:
 ${MAKE-make}

EOF
