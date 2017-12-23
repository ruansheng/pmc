dnl $Id$
dnl config.m4 for extension pmc

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(pmc, for pmc support,
dnl Make sure that the comment is aligned:
dnl [  --with-pmc             Include pmc support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(pmc, whether to enable pmc support,
[  --enable-pmc           Enable pmc support])

if test "$PHP_PMC" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-pmc -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/pmc.h"  # you most likely want to change this
  dnl if test -r $PHP_PMC/$SEARCH_FOR; then # path given as parameter
  dnl   PMC_DIR=$PHP_PMC
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for pmc files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PMC_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PMC_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the pmc distribution])
  dnl fi

  dnl # --with-pmc -> add include path
  dnl PHP_ADD_INCLUDE($PMC_DIR/include)

  dnl # --with-pmc -> check for lib and symbol presence
  dnl LIBNAME=pmc # you may want to change this
  dnl LIBSYMBOL=pmc # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PMC_DIR/$PHP_LIBDIR, PMC_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PMCLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong pmc lib version or lib not found])
  dnl ],[
  dnl   -L$PMC_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PMC_SHARED_LIBADD)

  PHP_NEW_EXTENSION(pmc,
    pmc.c \
    pmc_util.c \
    pmc_log.c,
    $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
