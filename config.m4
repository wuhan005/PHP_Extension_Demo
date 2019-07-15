dnl $Id$
dnl config.m4 for extension Eggplant

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(Eggplant, for Eggplant support,
dnl Make sure that the comment is aligned:
dnl [  --with-Eggplant             Include Eggplant support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(Eggplant, whether to enable Eggplant support,
dnl Make sure that the comment is aligned:
[  --enable-Eggplant           Enable Eggplant support])

if test "$PHP_EGGPLANT" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, EGGPLANT_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-Eggplant -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/Eggplant.h"  # you most likely want to change this
  dnl if test -r $PHP_EGGPLANT/$SEARCH_FOR; then # path given as parameter
  dnl   EGGPLANT_DIR=$PHP_EGGPLANT
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for Eggplant files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       EGGPLANT_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$EGGPLANT_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the Eggplant distribution])
  dnl fi

  dnl # --with-Eggplant -> add include path
  dnl PHP_ADD_INCLUDE($EGGPLANT_DIR/include)

  dnl # --with-Eggplant -> check for lib and symbol presence
  dnl LIBNAME=Eggplant # you may want to change this
  dnl LIBSYMBOL=Eggplant # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $EGGPLANT_DIR/$PHP_LIBDIR, EGGPLANT_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_EGGPLANTLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong Eggplant lib version or lib not found])
  dnl ],[
  dnl   -L$EGGPLANT_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(EGGPLANT_SHARED_LIBADD)

  PHP_NEW_EXTENSION(Eggplant, Eggplant.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
