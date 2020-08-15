# Sort Demo version 1.1
A wxWidgets GUI application that graphically demonstrates various methods of sorting


Sort Demo - Graphical demo of various sort methods using wxWidgets
Copyright (c) 1995-2020 by 'Bombastic Bob' Frazier

For licensing information, see LICENSE

There are no other restrictions on its distribution or use.  You may freely
use and distribute this application in accordance with the license.

This software comes with no warantees, either implied or explicit.

'Sort Demo' is based on an idea that someone told me about years ago.  In
fact, I wrote the first version of this back in 1995 using MFC.  Around
2005 I ported it to wxWidgets because of its MFC-like objects and behavior,
and it became a good example of how you can port existing Wiodows
applications (written in C++ using MFC) to Linux and other POSIX
systems with an X11 server (like my favorite OS, FreeBSD).

You can see a video of it working, here:

&nbsp;&nbsp;<a href="https://bombasticbob.github.io/sortdemo-1.1.avi">https://bombasticbob.github.io/sortdemo-1.1.avi</a><br>


INSTALLATION
------------

See 'INSTALL' file included with this distribution

Prior to building, you may have to use the auto tools to [re]create
the necessary files.  To do so, enter the following commands:
<pre>
  aclocal
  autoconf
  automake --add-missing --copy
</pre>
Following this, you will need to re-run the 'configure' script
<pre>
  ./configure
</pre>
You could also run 'autoscan' at least once and do what it says.


PRE-REQUISITES
--------------

This software requires the following packages be installed to build
and to run.

&nbsp;&nbsp;wxWidgets 3.0 or later (now a requirement)<br>
&nbsp;&nbsp;xrc library (contributed software) (necessary to use resources)<br>
&nbsp;&nbsp;wxrc application (contributed software)<br>

You may also need to make sure that you have a pointer to the actual
'wxrc' application in your PATH.  As an example:
<pre>
  mkdir ~/bin
  cd ~/bin
  ln -s /usr/local/bin/wxrc-gtk3u-3.0 ./wxrc
</pre>
"Your Mileage May Vary" as the path to wxrc on your system is likely
to differ.  But doing this works WITH the autotools and avoids you
having to specify the path directly in 'configure'.


For more information on building these, see the instructions included
with wxWidgets.  At some point in the future, xrc and wxrc are supposed
to be made part of the core distribution.  Until then you will need to
find a way to install them.  In FreeBSD, for example, there is a separate
port to install 'contributed' software, and 'development tools' for the
wxWidgets package.  Other systems, such as APT or RPM, will probably have
similar conventions.


