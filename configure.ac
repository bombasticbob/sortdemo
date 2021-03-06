AC_INIT(Sort Demo, 1.1, bobf-at-mrp3-dot-com, sortdemo)

AC_PREREQ(2.59)

AC_CONFIG_SRCDIR(sortdemo.cpp)
AM_INIT_AUTOMAKE
# use system default 'cc' when available; else, gcc
AC_PROG_CC([cc gcc])
AC_PATH_XTRA

AM_OPTIONS_WXCONFIG
AM_PATH_WXCONFIG([3.0.0], wxWin=1)

if test "$wxWin" != 1; then
  AC_MSG_ERROR([
                wxWindows must be installed on your system, but the wx-config
                script couldn't be located. Please check that wx-config is in
                the path, the directory where wxWidgets libraries are installed
                (returned by 'wx-config --libs' command) is in LD_LIBRARY_PATH or
                an equivalent variable, and wxWindows version is 2.6.0 or above.
                If the wx-config location is NOT in the path, or the application 
                name is NOT 'wx-config', you can specify the correct (fully-
                qualified) path name using the --with-wx-config option.]) ;
fi

# recommended by autoscan

AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([sys/timeb.h])
AC_HEADER_STDBOOL
AC_C_INLINE
# use system default 'c++' when available; else, g++
AC_PROG_CXX([c++ g++])
AC_TYPE_SIZE_T

AC_CHECK_FUNCS([printf sprintf ftime memset sqrt])

AC_SEARCH_LIBS([ftime],[compat],,[AC_MSG_ERROR(["missing library for 'ftime'"])])

AC_C_CONST
AC_HEADER_STDC

AC_CANONICAL_HOST

# optional things for Interix vs the rest of the world
case $host in
  i*86-pc-interix*)
    MAN_PAGES="sortdemo.interix"
    CPPFLAGS="$CPPFLAGS -D_ALL_SOURCE"
    ;;
  *)
    MAN_PAGES="sortdemo.1"
    ;;
esac

AC_SUBST([MAN_PAGES])

# locating the 'xrc' library
xrc_exist="N"

xrc_lib=`wx-config --basename`"_xrc-"`wx-config --release`

echo "temporary:  ${AWK}" >&5

echo "$as_me:$LINENO: checking for lib${xrc_lib}" >&5
echo $ECHO_N "checking $xrc_path for lib${xrc_lib} ... $ECHO_C" >&6

# it's difficult expanding this any other way - awk had trouble with the '$0', so
# I couldn't use split to create an array and filter uniques.  Instead I do this

for xrcp0 in `wx-config --libs` ; do

  if echo "${xrcp0}" | grep -vq -- "-L" ; then
    continue
  fi

# remove the '-L' using pattern substitution
  xrcp=${xrcp0##"-L"}

  xrc1="${xrcp}/lib${xrc_lib}.a"
  xrc2="${xrcp}/lib${xrc_lib}.so"

  if test -e "$xrc1" ; then
    echo "$as_me:$LINENO: $xrc1 exists (static)" >&5
    echo "yes (static)" >&6
    xrc_exist="Y"
    WX_LIBS="$WX_LIBS -l$xrc_lib"
    break
  elif test -e "$xrc2" ; then
    echo "$as_me:$LINENO: $xrc1 does not exist" >&5
    echo "$as_me:$LINENO: $xrc2 exists (shared)" >&5
    echo "yes (shared)" >&6
    xrc_exist="Y"
    WX_LIBS="$WX_LIBS -l$xrc_lib"
    break
  fi

done

if test $xrc_exist == "N" ; then
  echo "$as_me:$LINENO: ${xrc1} and ${xrc2} do not exist!!! ** ERROR **" >&5
  echo "no (error)" >&6

  AC_MSG_ERROR([
                wxWidgets contributed software must be installed
                on your system, specifically the 'xrc' library.
                The 'wxrc' application should also be installed
                if you need to re-build the resources.  Please
                check the wxWidgets installation to make sure
                that you have built the 'xrc' library.
               ]) ;
fi

echo "$as_me:$LINENO: checking for wxrc" >&5
echo $ECHO_N "checking for wxrc ... $ECHO_C" >&6

# here is where I differ from the standard scripts and
# check for installations like is used on FreeBSD

WXRC_PATH="" ;
for xpath in `echo "$PATH" | sed 's/:/ /g'` ;
do
  for xp2 in ${xpath}/wxrc* ; do
    if ( test -x "${xp2}" ) ; then
      xp3=`basename ${xp2}`
      WXRC_PATH=`${WX_CONFIG_NAME} --utility=${xp3}`
      if ( test "x" != x"$WXRC_PATH" ) ; then
        break ;
      fi ;
    fi;
  done ;
done

if ( test "$WXRC_PATH" = "" ) ; then
  echo "$as_me:$LINENO: no suitable wxrc has been located in the path" >&5 ;
  echo "no" >&6 ;
else
  echo "$as_me:$LINENO: wxrc has been located at $WXRC_PATH" >&5 ;
  echo "yes ( $WXRC_PATH )" >&6 ;
fi

AC_SUBST([WXRC_PATH])

CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"

LDFLAGS="$LDFLAGS $WX_LIBS"

# the end

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

