huggle3-qt-lx
=============

Huggle 3 QT-LX is an anti-vandalism tool for use on Wikipedia and other Wikimedia projects, written in C++ (QT framework).
It is supported for Windows and Linux

[![Build Status](https://travis-ci.org/huggle/huggle3-qt-lx.png?branch=ubuntu)](https://travis-ci.org/huggle/huggle3-qt-lx)

This is a repository that is used to build debian packages

Easy
=====

 * git merge master debian
 * run debian.sh

Help
======

 * First we need to download a zip of this package to /tmp
 * Now we can unzip it
 * Now we need to switch to huggle3-qt-lx and create a tarball of huggle folder

tar -zcvf huggle_VERSION.orig.tar.gz huggle

 * Now rename the original huggle folder

mv huggle huggle-VERSION

<<<<<<< .merge_file_bNNuaT
 * switch to it
 * run debuild -us -uc
=======
This repository is running CI using travis, if you want to change anything what doesn't require
sanity check, like documentation or comments, please append [ci skip] to your message

This repository is running CI using travis, if you want to change anything what doesn't require
sanity check, like documentation or comments, please append [ci skip] to your message

Reporting bugs
===============
>>>>>>> .merge_file_fRn8xS

