# Mockingjay
Mimicking of Belady's min algorithm to improve cache replacement: https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=9773195. Using zsim for simulation. 

# Project Structure
```
.
├── README.md
├── benchmarks.z01
├── benchmarks.z02
├── benchmarks.z03
├── benchmarks.zip
├── cse_server.patch
├── out.txt
├── setup_env
├── tools
│   ├── local
│   │   ├── bin
│   │   │   ├── gif2h5
│   │   │   ├── h52gif
│   │   │   ├── h5cc
│   │   │   ├── h5copy
│   │   │   ├── h5debug
│   │   │   ├── h5diff
│   │   │   ├── h5dump
│   │   │   ├── h5import
│   │   │   ├── h5jam
│   │   │   ├── h5ls
│   │   │   ├── h5mkgrp
│   │   │   ├── h5perf_serial
│   │   │   ├── h5redeploy
│   │   │   ├── h5repack
│   │   │   ├── h5repart
│   │   │   ├── h5stat
│   │   │   ├── h5unjam
│   │   │   ├── htop
│   │   │   ├── scons
│   │   │   ├── scons-2.5.1
│   │   │   ├── scons-configure-cache
│   │   │   ├── scons-configure-cache-2.5.1
│   │   │   ├── scons-time
│   │   │   ├── scons-time-2.5.1
│   │   │   ├── sconsign
│   │   │   └── sconsign-2.5.1
│   │   ├── include
│   │   │   ├── H5ACpublic.h
│   │   │   ├── H5Apublic.h
│   │   │   ├── H5Cpublic.h
│   │   │   ├── H5DOpublic.h
│   │   │   ├── H5DSpublic.h
│   │   │   ├── H5Dpublic.h
│   │   │   ├── H5Epubgen.h
│   │   │   ├── H5Epublic.h
│   │   │   ├── H5FDcore.h
│   │   │   ├── H5FDdirect.h
│   │   │   ├── H5FDfamily.h
│   │   │   ├── H5FDlog.h
│   │   │   ├── H5FDmpi.h
│   │   │   ├── H5FDmpio.h
│   │   │   ├── H5FDmulti.h
│   │   │   ├── H5FDpublic.h
│   │   │   ├── H5FDsec2.h
│   │   │   ├── H5FDstdio.h
│   │   │   ├── H5Fpublic.h
│   │   │   ├── H5Gpublic.h
│   │   │   ├── H5IMpublic.h
│   │   │   ├── H5Ipublic.h
│   │   │   ├── H5LTpublic.h
│   │   │   ├── H5Lpublic.h
│   │   │   ├── H5MMpublic.h
│   │   │   ├── H5Opublic.h
│   │   │   ├── H5PLextern.h
│   │   │   ├── H5PLpublic.h
│   │   │   ├── H5PTpublic.h
│   │   │   ├── H5Ppublic.h
│   │   │   ├── H5Rpublic.h
│   │   │   ├── H5Spublic.h
│   │   │   ├── H5TBpublic.h
│   │   │   ├── H5Tpublic.h
│   │   │   ├── H5Zpublic.h
│   │   │   ├── H5api_adpt.h
│   │   │   ├── H5overflow.h
│   │   │   ├── H5pubconf.h
│   │   │   ├── H5public.h
│   │   │   ├── H5version.h
│   │   │   ├── gelf.h
│   │   │   ├── hdf5.h
│   │   │   ├── hdf5_hl.h
│   │   │   ├── libconfig.h
│   │   │   ├── libconfig.h++
│   │   │   ├── libelf
│   │   │   │   ├── elf_repl.h
│   │   │   │   ├── gelf.h
│   │   │   │   ├── libelf.h
│   │   │   │   ├── nlist.h
│   │   │   │   └── sys_elf.h
│   │   │   ├── libelf.h
│   │   │   └── nlist.h
│   │   ├── lib
│   │   │   ├── libconfig++.a
│   │   │   ├── libconfig++.la
│   │   │   ├── libconfig++.so
│   │   │   ├── libconfig++.so.9
│   │   │   ├── libconfig++.so.9.2.0
│   │   │   ├── libconfig.a
│   │   │   ├── libconfig.la
│   │   │   ├── libconfig.so
│   │   │   ├── libconfig.so.9
│   │   │   ├── libconfig.so.9.2.0
│   │   │   ├── libelf.a
│   │   │   ├── libelf.so
│   │   │   ├── libelf.so.0
│   │   │   ├── libelf.so.0.8.13
│   │   │   ├── libhdf5.a
│   │   │   ├── libhdf5.la
│   │   │   ├── libhdf5.settings
│   │   │   ├── libhdf5.so
│   │   │   ├── libhdf5.so.10
│   │   │   ├── libhdf5.so.10.2.1
│   │   │   ├── libhdf5_hl.a
│   │   │   ├── libhdf5_hl.la
│   │   │   ├── libhdf5_hl.so
│   │   │   ├── libhdf5_hl.so.10
│   │   │   ├── libhdf5_hl.so.10.1.1
│   │   │   ├── pkgconfig
│   │   │   │   ├── libconfig++.pc
│   │   │   │   ├── libconfig.pc
│   │   │   │   └── libelf.pc
│   │   │   └── scons-2.5.1
│   │   │       ├── SCons
│   │   │       │   ├── Action.py
│   │   │       │   ├── Action.pyc
│   │   │       │   ├── Builder.py
│   │   │       │   ├── Builder.pyc
│   │   │       │   ├── CacheDir.py
│   │   │       │   ├── CacheDir.pyc
│   │   │       │   ├── Conftest.py
│   │   │       │   ├── Conftest.pyc
│   │   │       │   ├── Debug.py
│   │   │       │   ├── Debug.pyc
│   │   │       │   ├── Defaults.py
│   │   │       │   ├── Defaults.pyc
│   │   │       │   ├── Environment.py
│   │   │       │   ├── Environment.pyc
│   │   │       │   ├── Errors.py
│   │   │       │   ├── Errors.pyc
│   │   │       │   ├── Executor.py
│   │   │       │   ├── Executor.pyc
│   │   │       │   ├── Job.py
│   │   │       │   ├── Job.pyc
│   │   │       │   ├── Memoize.py
│   │   │       │   ├── Memoize.pyc
│   │   │       │   ├── Node
│   │   │       │   │   ├── Alias.py
│   │   │       │   │   ├── Alias.pyc
│   │   │       │   │   ├── FS.py
│   │   │       │   │   ├── FS.pyc
│   │   │       │   │   ├── Python.py
│   │   │       │   │   ├── Python.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   └── __init__.pyc
│   │   │       │   ├── Options
│   │   │       │   │   ├── BoolOption.py
│   │   │       │   │   ├── BoolOption.pyc
│   │   │       │   │   ├── EnumOption.py
│   │   │       │   │   ├── EnumOption.pyc
│   │   │       │   │   ├── ListOption.py
│   │   │       │   │   ├── ListOption.pyc
│   │   │       │   │   ├── PackageOption.py
│   │   │       │   │   ├── PackageOption.pyc
│   │   │       │   │   ├── PathOption.py
│   │   │       │   │   ├── PathOption.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   └── __init__.pyc
│   │   │       │   ├── PathList.py
│   │   │       │   ├── PathList.pyc
│   │   │       │   ├── Platform
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   ├── __init__.pyc
│   │   │       │   │   ├── aix.py
│   │   │       │   │   ├── aix.pyc
│   │   │       │   │   ├── cygwin.py
│   │   │       │   │   ├── cygwin.pyc
│   │   │       │   │   ├── darwin.py
│   │   │       │   │   ├── darwin.pyc
│   │   │       │   │   ├── hpux.py
│   │   │       │   │   ├── hpux.pyc
│   │   │       │   │   ├── irix.py
│   │   │       │   │   ├── irix.pyc
│   │   │       │   │   ├── os2.py
│   │   │       │   │   ├── os2.pyc
│   │   │       │   │   ├── posix.py
│   │   │       │   │   ├── posix.pyc
│   │   │       │   │   ├── sunos.py
│   │   │       │   │   ├── sunos.pyc
│   │   │       │   │   ├── win32.py
│   │   │       │   │   └── win32.pyc
│   │   │       │   ├── SConf.py
│   │   │       │   ├── SConf.pyc
│   │   │       │   ├── SConsign.py
│   │   │       │   ├── SConsign.pyc
│   │   │       │   ├── Scanner
│   │   │       │   │   ├── C.py
│   │   │       │   │   ├── C.pyc
│   │   │       │   │   ├── D.py
│   │   │       │   │   ├── D.pyc
│   │   │       │   │   ├── Dir.py
│   │   │       │   │   ├── Dir.pyc
│   │   │       │   │   ├── Fortran.py
│   │   │       │   │   ├── Fortran.pyc
│   │   │       │   │   ├── IDL.py
│   │   │       │   │   ├── IDL.pyc
│   │   │       │   │   ├── LaTeX.py
│   │   │       │   │   ├── LaTeX.pyc
│   │   │       │   │   ├── Prog.py
│   │   │       │   │   ├── Prog.pyc
│   │   │       │   │   ├── RC.py
│   │   │       │   │   ├── RC.pyc
│   │   │       │   │   ├── SWIG.py
│   │   │       │   │   ├── SWIG.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   └── __init__.pyc
│   │   │       │   ├── Script
│   │   │       │   │   ├── Interactive.py
│   │   │       │   │   ├── Interactive.pyc
│   │   │       │   │   ├── Main.py
│   │   │       │   │   ├── Main.pyc
│   │   │       │   │   ├── SConsOptions.py
│   │   │       │   │   ├── SConsOptions.pyc
│   │   │       │   │   ├── SConscript.py
│   │   │       │   │   ├── SConscript.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   └── __init__.pyc
│   │   │       │   ├── Sig.py
│   │   │       │   ├── Sig.pyc
│   │   │       │   ├── Subst.py
│   │   │       │   ├── Subst.pyc
│   │   │       │   ├── Taskmaster.py
│   │   │       │   ├── Taskmaster.pyc
│   │   │       │   ├── Tool
│   │   │       │   │   ├── 386asm.py
│   │   │       │   │   ├── 386asm.pyc
│   │   │       │   │   ├── BitKeeper.py
│   │   │       │   │   ├── BitKeeper.pyc
│   │   │       │   │   ├── CVS.py
│   │   │       │   │   ├── CVS.pyc
│   │   │       │   │   ├── DCommon.py
│   │   │       │   │   ├── DCommon.pyc
│   │   │       │   │   ├── FortranCommon.py
│   │   │       │   │   ├── FortranCommon.pyc
│   │   │       │   │   ├── GettextCommon.py
│   │   │       │   │   ├── GettextCommon.pyc
│   │   │       │   │   ├── JavaCommon.py
│   │   │       │   │   ├── JavaCommon.pyc
│   │   │       │   │   ├── MSCommon
│   │   │       │   │   │   ├── __init__.py
│   │   │       │   │   │   ├── __init__.pyc
│   │   │       │   │   │   ├── arch.py
│   │   │       │   │   │   ├── arch.pyc
│   │   │       │   │   │   ├── common.py
│   │   │       │   │   │   ├── common.pyc
│   │   │       │   │   │   ├── netframework.py
│   │   │       │   │   │   ├── netframework.pyc
│   │   │       │   │   │   ├── sdk.py
│   │   │       │   │   │   ├── sdk.pyc
│   │   │       │   │   │   ├── vc.py
│   │   │       │   │   │   ├── vc.pyc
│   │   │       │   │   │   ├── vs.py
│   │   │       │   │   │   └── vs.pyc
│   │   │       │   │   ├── Perforce.py
│   │   │       │   │   ├── Perforce.pyc
│   │   │       │   │   ├── PharLapCommon.py
│   │   │       │   │   ├── PharLapCommon.pyc
│   │   │       │   │   ├── RCS.py
│   │   │       │   │   ├── RCS.pyc
│   │   │       │   │   ├── SCCS.py
│   │   │       │   │   ├── SCCS.pyc
│   │   │       │   │   ├── Subversion.py
│   │   │       │   │   ├── Subversion.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   ├── __init__.pyc
│   │   │       │   │   ├── aixc++.py
│   │   │       │   │   ├── aixc++.pyc
│   │   │       │   │   ├── aixcc.py
│   │   │       │   │   ├── aixcc.pyc
│   │   │       │   │   ├── aixf77.py
│   │   │       │   │   ├── aixf77.pyc
│   │   │       │   │   ├── aixlink.py
│   │   │       │   │   ├── aixlink.pyc
│   │   │       │   │   ├── applelink.py
│   │   │       │   │   ├── applelink.pyc
│   │   │       │   │   ├── ar.py
│   │   │       │   │   ├── ar.pyc
│   │   │       │   │   ├── as.py
│   │   │       │   │   ├── as.pyc
│   │   │       │   │   ├── bcc32.py
│   │   │       │   │   ├── bcc32.pyc
│   │   │       │   │   ├── c++.py
│   │   │       │   │   ├── c++.pyc
│   │   │       │   │   ├── cc.py
│   │   │       │   │   ├── cc.pyc
│   │   │       │   │   ├── cvf.py
│   │   │       │   │   ├── cvf.pyc
│   │   │       │   │   ├── cyglink.py
│   │   │       │   │   ├── cyglink.pyc
│   │   │       │   │   ├── default.py
│   │   │       │   │   ├── default.pyc
│   │   │       │   │   ├── dmd.py
│   │   │       │   │   ├── dmd.pyc
│   │   │       │   │   ├── docbook
│   │   │       │   │   │   ├── __init__.py
│   │   │       │   │   │   └── __init__.pyc
│   │   │       │   │   ├── dvi.py
│   │   │       │   │   ├── dvi.pyc
│   │   │       │   │   ├── dvipdf.py
│   │   │       │   │   ├── dvipdf.pyc
│   │   │       │   │   ├── dvips.py
│   │   │       │   │   ├── dvips.pyc
│   │   │       │   │   ├── f03.py
│   │   │       │   │   ├── f03.pyc
│   │   │       │   │   ├── f77.py
│   │   │       │   │   ├── f77.pyc
│   │   │       │   │   ├── f90.py
│   │   │       │   │   ├── f90.pyc
│   │   │       │   │   ├── f95.py
│   │   │       │   │   ├── f95.pyc
│   │   │       │   │   ├── filesystem.py
│   │   │       │   │   ├── filesystem.pyc
│   │   │       │   │   ├── fortran.py
│   │   │       │   │   ├── fortran.pyc
│   │   │       │   │   ├── g++.py
│   │   │       │   │   ├── g++.pyc
│   │   │       │   │   ├── g77.py
│   │   │       │   │   ├── g77.pyc
│   │   │       │   │   ├── gas.py
│   │   │       │   │   ├── gas.pyc
│   │   │       │   │   ├── gcc.py
│   │   │       │   │   ├── gcc.pyc
│   │   │       │   │   ├── gdc.py
│   │   │       │   │   ├── gdc.pyc
│   │   │       │   │   ├── gettext.py
│   │   │       │   │   ├── gettext.pyc
│   │   │       │   │   ├── gfortran.py
│   │   │       │   │   ├── gfortran.pyc
│   │   │       │   │   ├── gnulink.py
│   │   │       │   │   ├── gnulink.pyc
│   │   │       │   │   ├── gs.py
│   │   │       │   │   ├── gs.pyc
│   │   │       │   │   ├── hpc++.py
│   │   │       │   │   ├── hpc++.pyc
│   │   │       │   │   ├── hpcc.py
│   │   │       │   │   ├── hpcc.pyc
│   │   │       │   │   ├── hplink.py
│   │   │       │   │   ├── hplink.pyc
│   │   │       │   │   ├── icc.py
│   │   │       │   │   ├── icc.pyc
│   │   │       │   │   ├── icl.py
│   │   │       │   │   ├── icl.pyc
│   │   │       │   │   ├── ifl.py
│   │   │       │   │   ├── ifl.pyc
│   │   │       │   │   ├── ifort.py
│   │   │       │   │   ├── ifort.pyc
│   │   │       │   │   ├── ilink.py
│   │   │       │   │   ├── ilink.pyc
│   │   │       │   │   ├── ilink32.py
│   │   │       │   │   ├── ilink32.pyc
│   │   │       │   │   ├── install.py
│   │   │       │   │   ├── install.pyc
│   │   │       │   │   ├── intelc.py
│   │   │       │   │   ├── intelc.pyc
│   │   │       │   │   ├── ipkg.py
│   │   │       │   │   ├── ipkg.pyc
│   │   │       │   │   ├── jar.py
│   │   │       │   │   ├── jar.pyc
│   │   │       │   │   ├── javac.py
│   │   │       │   │   ├── javac.pyc
│   │   │       │   │   ├── javah.py
│   │   │       │   │   ├── javah.pyc
│   │   │       │   │   ├── latex.py
│   │   │       │   │   ├── latex.pyc
│   │   │       │   │   ├── ldc.py
│   │   │       │   │   ├── ldc.pyc
│   │   │       │   │   ├── lex.py
│   │   │       │   │   ├── lex.pyc
│   │   │       │   │   ├── link.py
│   │   │       │   │   ├── link.pyc
│   │   │       │   │   ├── linkloc.py
│   │   │       │   │   ├── linkloc.pyc
│   │   │       │   │   ├── m4.py
│   │   │       │   │   ├── m4.pyc
│   │   │       │   │   ├── masm.py
│   │   │       │   │   ├── masm.pyc
│   │   │       │   │   ├── midl.py
│   │   │       │   │   ├── midl.pyc
│   │   │       │   │   ├── mingw.py
│   │   │       │   │   ├── mingw.pyc
│   │   │       │   │   ├── msgfmt.py
│   │   │       │   │   ├── msgfmt.pyc
│   │   │       │   │   ├── msginit.py
│   │   │       │   │   ├── msginit.pyc
│   │   │       │   │   ├── msgmerge.py
│   │   │       │   │   ├── msgmerge.pyc
│   │   │       │   │   ├── mslib.py
│   │   │       │   │   ├── mslib.pyc
│   │   │       │   │   ├── mslink.py
│   │   │       │   │   ├── mslink.pyc
│   │   │       │   │   ├── mssdk.py
│   │   │       │   │   ├── mssdk.pyc
│   │   │       │   │   ├── msvc.py
│   │   │       │   │   ├── msvc.pyc
│   │   │       │   │   ├── msvs.py
│   │   │       │   │   ├── msvs.pyc
│   │   │       │   │   ├── mwcc.py
│   │   │       │   │   ├── mwcc.pyc
│   │   │       │   │   ├── mwld.py
│   │   │       │   │   ├── mwld.pyc
│   │   │       │   │   ├── nasm.py
│   │   │       │   │   ├── nasm.pyc
│   │   │       │   │   ├── packaging
│   │   │       │   │   │   ├── __init__.py
│   │   │       │   │   │   ├── __init__.pyc
│   │   │       │   │   │   ├── ipk.py
│   │   │       │   │   │   ├── ipk.pyc
│   │   │       │   │   │   ├── msi.py
│   │   │       │   │   │   ├── msi.pyc
│   │   │       │   │   │   ├── rpm.py
│   │   │       │   │   │   ├── rpm.pyc
│   │   │       │   │   │   ├── src_tarbz2.py
│   │   │       │   │   │   ├── src_tarbz2.pyc
│   │   │       │   │   │   ├── src_targz.py
│   │   │       │   │   │   ├── src_targz.pyc
│   │   │       │   │   │   ├── src_zip.py
│   │   │       │   │   │   ├── src_zip.pyc
│   │   │       │   │   │   ├── tarbz2.py
│   │   │       │   │   │   ├── tarbz2.pyc
│   │   │       │   │   │   ├── targz.py
│   │   │       │   │   │   ├── targz.pyc
│   │   │       │   │   │   ├── zip.py
│   │   │       │   │   │   └── zip.pyc
│   │   │       │   │   ├── pdf.py
│   │   │       │   │   ├── pdf.pyc
│   │   │       │   │   ├── pdflatex.py
│   │   │       │   │   ├── pdflatex.pyc
│   │   │       │   │   ├── pdftex.py
│   │   │       │   │   ├── pdftex.pyc
│   │   │       │   │   ├── qt.py
│   │   │       │   │   ├── qt.pyc
│   │   │       │   │   ├── rmic.py
│   │   │       │   │   ├── rmic.pyc
│   │   │       │   │   ├── rpcgen.py
│   │   │       │   │   ├── rpcgen.pyc
│   │   │       │   │   ├── rpm.py
│   │   │       │   │   ├── rpm.pyc
│   │   │       │   │   ├── rpmutils.py
│   │   │       │   │   ├── rpmutils.pyc
│   │   │       │   │   ├── sgiar.py
│   │   │       │   │   ├── sgiar.pyc
│   │   │       │   │   ├── sgic++.py
│   │   │       │   │   ├── sgic++.pyc
│   │   │       │   │   ├── sgicc.py
│   │   │       │   │   ├── sgicc.pyc
│   │   │       │   │   ├── sgilink.py
│   │   │       │   │   ├── sgilink.pyc
│   │   │       │   │   ├── sunar.py
│   │   │       │   │   ├── sunar.pyc
│   │   │       │   │   ├── sunc++.py
│   │   │       │   │   ├── sunc++.pyc
│   │   │       │   │   ├── suncc.py
│   │   │       │   │   ├── suncc.pyc
│   │   │       │   │   ├── sunf77.py
│   │   │       │   │   ├── sunf77.pyc
│   │   │       │   │   ├── sunf90.py
│   │   │       │   │   ├── sunf90.pyc
│   │   │       │   │   ├── sunf95.py
│   │   │       │   │   ├── sunf95.pyc
│   │   │       │   │   ├── sunlink.py
│   │   │       │   │   ├── sunlink.pyc
│   │   │       │   │   ├── swig.py
│   │   │       │   │   ├── swig.pyc
│   │   │       │   │   ├── tar.py
│   │   │       │   │   ├── tar.pyc
│   │   │       │   │   ├── tex.py
│   │   │       │   │   ├── tex.pyc
│   │   │       │   │   ├── textfile.py
│   │   │       │   │   ├── textfile.pyc
│   │   │       │   │   ├── tlib.py
│   │   │       │   │   ├── tlib.pyc
│   │   │       │   │   ├── wix.py
│   │   │       │   │   ├── wix.pyc
│   │   │       │   │   ├── xgettext.py
│   │   │       │   │   ├── xgettext.pyc
│   │   │       │   │   ├── yacc.py
│   │   │       │   │   ├── yacc.pyc
│   │   │       │   │   ├── zip.py
│   │   │       │   │   └── zip.pyc
│   │   │       │   ├── Util.py
│   │   │       │   ├── Util.pyc
│   │   │       │   ├── Variables
│   │   │       │   │   ├── BoolVariable.py
│   │   │       │   │   ├── BoolVariable.pyc
│   │   │       │   │   ├── EnumVariable.py
│   │   │       │   │   ├── EnumVariable.pyc
│   │   │       │   │   ├── ListVariable.py
│   │   │       │   │   ├── ListVariable.pyc
│   │   │       │   │   ├── PackageVariable.py
│   │   │       │   │   ├── PackageVariable.pyc
│   │   │       │   │   ├── PathVariable.py
│   │   │       │   │   ├── PathVariable.pyc
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   └── __init__.pyc
│   │   │       │   ├── Warnings.py
│   │   │       │   ├── Warnings.pyc
│   │   │       │   ├── __init__.py
│   │   │       │   ├── __init__.pyc
│   │   │       │   ├── compat
│   │   │       │   │   ├── __init__.py
│   │   │       │   │   ├── __init__.pyc
│   │   │       │   │   ├── _scons_dbm.py
│   │   │       │   │   └── _scons_dbm.pyc
│   │   │       │   ├── cpp.py
│   │   │       │   ├── cpp.pyc
│   │   │       │   ├── dblite.py
│   │   │       │   ├── dblite.pyc
│   │   │       │   ├── exitfuncs.py
│   │   │       │   └── exitfuncs.pyc
│   │   │       └── scons-2.5.1-py2.7.egg-info
│   │   ├── man
│   │   │   └── man1
│   │   │       ├── scons-time.1
│   │   │       ├── scons.1
│   │   │       └── sconsign.1
│   │   └── share
│   │       ├── applications
│   │       │   └── htop.desktop
│   │       ├── hdf5_examples
│   │       │   ├── README
│   │       │   ├── c
│   │       │   │   ├── h5_attribute.c
│   │       │   │   ├── h5_chunk_read.c
│   │       │   │   ├── h5_cmprss.c
│   │       │   │   ├── h5_compound.c
│   │       │   │   ├── h5_crtatt.c
│   │       │   │   ├── h5_crtdat.c
│   │       │   │   ├── h5_crtgrp.c
│   │       │   │   ├── h5_crtgrpar.c
│   │       │   │   ├── h5_crtgrpd.c
│   │       │   │   ├── h5_drivers.c
│   │       │   │   ├── h5_elink_unix2win.c
│   │       │   │   ├── h5_extend.c
│   │       │   │   ├── h5_extend_write.c
│   │       │   │   ├── h5_extlink.c
│   │       │   │   ├── h5_group.c
│   │       │   │   ├── h5_mount.c
│   │       │   │   ├── h5_rdwt.c
│   │       │   │   ├── h5_read.c
│   │       │   │   ├── h5_ref2reg.c
│   │       │   │   ├── h5_reference.c
│   │       │   │   ├── h5_select.c
│   │       │   │   ├── h5_shared_mesg.c
│   │       │   │   ├── h5_subset.c
│   │       │   │   ├── h5_write.c
│   │       │   │   ├── ph5example.c
│   │       │   │   └── run-c-ex.sh
│   │       │   ├── hl
│   │       │   │   ├── c
│   │       │   │   │   ├── ex_ds1.c
│   │       │   │   │   ├── ex_image1.c
│   │       │   │   │   ├── ex_image2.c
│   │       │   │   │   ├── ex_lite1.c
│   │       │   │   │   ├── ex_lite2.c
│   │       │   │   │   ├── ex_lite3.c
│   │       │   │   │   ├── ex_table_01.c
│   │       │   │   │   ├── ex_table_02.c
│   │       │   │   │   ├── ex_table_03.c
│   │       │   │   │   ├── ex_table_04.c
│   │       │   │   │   ├── ex_table_05.c
│   │       │   │   │   ├── ex_table_06.c
│   │       │   │   │   ├── ex_table_07.c
│   │       │   │   │   ├── ex_table_08.c
│   │       │   │   │   ├── ex_table_09.c
│   │       │   │   │   ├── ex_table_10.c
│   │       │   │   │   ├── ex_table_11.c
│   │       │   │   │   ├── ex_table_12.c
│   │       │   │   │   ├── image24pixel.txt
│   │       │   │   │   ├── image8.txt
│   │       │   │   │   ├── pal_rgb.h
│   │       │   │   │   ├── ptExampleFL.c
│   │       │   │   │   └── run-hlc-ex.sh
│   │       │   │   └── run-hl-ex.sh
│   │       │   └── run-all-ex.sh
│   │       ├── info
│   │       │   ├── dir
│   │       │   └── libconfig.info
│   │       ├── locale
│   │       │   └── de
│   │       │       └── LC_MESSAGES
│   │       │           └── libelf.mo
│   │       ├── man
│   │       │   └── man1
│   │       │       └── htop.1
│   │       └── pixmaps
│   │           └── htop.png
│   └── pin-2.14-71313-gcc.4.4.7-linux
│       ├── LICENSE
│       ├── README
│       ├── doc
│       │   └── html
│       │       ├── annotated.html
│       │       ├── classDEBUGGER__SHELL_1_1ICUSTOM__INSTRUMENTOR-members.html
│       │       ├── classDEBUGGER__SHELL_1_1ICUSTOM__INSTRUMENTOR.html
│       │       ├── classDEBUGGER__SHELL_1_1ISHELL-members.html
│       │       ├── classDEBUGGER__SHELL_1_1ISHELL.html
│       │       ├── classINSTLIB_1_1FOLLOW__CHILD-members.html
│       │       ├── classINSTLIB_1_1FOLLOW__CHILD.html
│       │       ├── classINSTLIB_1_1ICOUNT-members.html
│       │       ├── classINSTLIB_1_1ICOUNT.html
│       │       ├── classes.html
│       │       ├── doxygen.css
│       │       ├── doxygen.png
│       │       ├── functions.html
│       │       ├── functions_enum.html
│       │       ├── functions_eval.html
│       │       ├── functions_func.html
│       │       ├── functions_vars.html
│       │       ├── group__ALARM.html
│       │       ├── group__API__REF.html
│       │       ├── group__APPDEBUG__API.html
│       │       ├── group__BBL__BASIC__API.html
│       │       ├── group__BUFFER__API.html
│       │       ├── group__CHILD__PROCESS__API.html
│       │       ├── group__CODECACHE__API.html
│       │       ├── group__CONTEXT__API.html
│       │       ├── group__CONTROLLER__REGIONS.html
│       │       ├── group__DEBUGGER__SHELL.html
│       │       ├── group__DEBUG__API.html
│       │       ├── group__DEPRECATED__PIN__API.html
│       │       ├── group__ERROR__FILE__BASIC.html
│       │       ├── group__EXCEPTION__API.html
│       │       ├── group__FILTER.html
│       │       ├── group__FILTER__LIB.html
│       │       ├── group__FILTER__MULTI.html
│       │       ├── group__FILTER__RTN.html
│       │       ├── group__FOLLOW__CHILD.html
│       │       ├── group__ICOUNT.html
│       │       ├── group__IMG__BASIC__API.html
│       │       ├── group__INSTLIB.html
│       │       ├── group__INST__ARGS.html
│       │       ├── group__INS__BASIC__API.html
│       │       ├── group__INS__BASIC__API__GEN__IA32.html
│       │       ├── group__INS__BASIC__API__IA32.html
│       │       ├── group__INS__INST__API.html
│       │       ├── group__INS__MOD__API__GEN__IA32.html
│       │       ├── group__KNOBS.html
│       │       ├── group__KNOB__API.html
│       │       ├── group__KNOB__BASIC.html
│       │       ├── group__KNOB__PRINT.html
│       │       ├── group__LOCK.html
│       │       ├── group__MISC.html
│       │       ├── group__MISC__PARSE.html
│       │       ├── group__MISC__PRINT.html
│       │       ├── group__PHYSICAL__CONTEXT__API.html
│       │       ├── group__PIN__CALLBACKS.html
│       │       ├── group__PIN__CONTROL.html
│       │       ├── group__PIN__PROCESS__API.html
│       │       ├── group__PIN__SYSCALL__API.html
│       │       ├── group__PIN__THREAD__API.html
│       │       ├── group__PROTO.html
│       │       ├── group__PROTO__API.html
│       │       ├── group__REG__BASIC__API.html
│       │       ├── group__REG__CPU__GENERIC.html
│       │       ├── group__REG__CPU__IA32.html
│       │       ├── group__RTN__BASIC__API.html
│       │       ├── group__SEC__BASIC__API.html
│       │       ├── group__SKIPPER.html
│       │       ├── group__SKIP__INT3.html
│       │       ├── group__STOPPED__THREAD__API.html
│       │       ├── group__SYM__BASIC__API.html
│       │       ├── group__TIME__WARPER.html
│       │       ├── group__TIME__WARPER__RDTSC.html
│       │       ├── group__TRACE__BASIC__API.html
│       │       ├── group__TRACE__VERSION__API.html
│       │       ├── group__TYPE__BASE.html
│       │       ├── group__UTILS.html
│       │       ├── hierarchy.html
│       │       ├── index.html
│       │       ├── installdox
│       │       ├── modules.html
│       │       ├── namespaceLEVEL__BASE.html
│       │       ├── namespaceLEVEL__CORE.html
│       │       ├── namespaceLEVEL__PINCLIENT.html
│       │       ├── namespacemembers.html
│       │       ├── namespacemembers_0x61.html
│       │       ├── namespacemembers_0x62.html
│       │       ├── namespacemembers_0x63.html
│       │       ├── namespacemembers_0x64.html
│       │       ├── namespacemembers_0x65.html
│       │       ├── namespacemembers_0x66.html
│       │       ├── namespacemembers_0x67.html
│       │       ├── namespacemembers_0x68.html
│       │       ├── namespacemembers_0x69.html
│       │       ├── namespacemembers_0x6a.html
│       │       ├── namespacemembers_0x6b.html
│       │       ├── namespacemembers_0x6c.html
│       │       ├── namespacemembers_0x6d.html
│       │       ├── namespacemembers_0x6e.html
│       │       ├── namespacemembers_0x6f.html
│       │       ├── namespacemembers_0x70.html
│       │       ├── namespacemembers_0x72.html
│       │       ├── namespacemembers_0x73.html
│       │       ├── namespacemembers_0x74.html
│       │       ├── namespacemembers_0x75.html
│       │       ├── namespacemembers_0x76.html
│       │       ├── namespacemembers_0x78.html
│       │       ├── namespacemembers_enum.html
│       │       ├── namespacemembers_eval.html
│       │       ├── namespacemembers_func.html
│       │       ├── namespacemembers_func_0x62.html
│       │       ├── namespacemembers_func_0x63.html
│       │       ├── namespacemembers_func_0x64.html
│       │       ├── namespacemembers_func_0x65.html
│       │       ├── namespacemembers_func_0x66.html
│       │       ├── namespacemembers_func_0x67.html
│       │       ├── namespacemembers_func_0x68.html
│       │       ├── namespacemembers_func_0x69.html
│       │       ├── namespacemembers_func_0x6a.html
│       │       ├── namespacemembers_func_0x6b.html
│       │       ├── namespacemembers_func_0x6c.html
│       │       ├── namespacemembers_func_0x6d.html
│       │       ├── namespacemembers_func_0x6e.html
│       │       ├── namespacemembers_func_0x6f.html
│       │       ├── namespacemembers_func_0x70.html
│       │       ├── namespacemembers_func_0x72.html
│       │       ├── namespacemembers_func_0x73.html
│       │       ├── namespacemembers_func_0x74.html
│       │       ├── namespacemembers_func_0x75.html
│       │       ├── namespacemembers_func_0x76.html
│       │       ├── namespacemembers_func_0x78.html
│       │       ├── namespacemembers_type.html
│       │       ├── namespacemembers_vars.html
│       │       ├── namespaces.html
│       │       ├── pin-debugger-attach.png
│       │       ├── pin-debugger-option-pages-properties.png
│       │       ├── pin-debugger-project-properties1.png
│       │       ├── pin-debugger-project-properties2.png
│       │       ├── search.idx
│       │       ├── search.php
│       │       ├── stack-debugger-commands.png
│       │       ├── stack-debugger-custom-break.png
│       │       ├── structCALL__APPLICATION__FUNCTION__PARAM-members.html
│       │       ├── structCALL__APPLICATION__FUNCTION__PARAM.html
│       │       ├── structDEBUGGER__REG__DESCRIPTION-members.html
│       │       ├── structDEBUGGER__REG__DESCRIPTION.html
│       │       ├── structDEBUGGER__SHELL_1_1STARTUP__ARGUMENTS-members.html
│       │       ├── structDEBUGGER__SHELL_1_1STARTUP__ARGUMENTS.html
│       │       ├── structDEBUG__CONNECTION__INFO-members.html
│       │       ├── structDEBUG__CONNECTION__INFO.html
│       │       ├── structDEBUG__MODE-members.html
│       │       ├── structDEBUG__MODE.html
│       │       ├── structLEVEL__BASE_1_1ImageLoaderInfo-members.html
│       │       ├── structLEVEL__BASE_1_1ImageLoaderInfo.html
│       │       ├── structPIN__CODE__RANGE-members.html
│       │       ├── structPIN__CODE__RANGE.html
│       │       ├── structPIN__MEM__ACCESS__INFO-members.html
│       │       ├── structPIN__MEM__ACCESS__INFO.html
│       │       ├── structPIN__MULTI__MEM__ACCESS__INFO-members.html
│       │       ├── structPIN__MULTI__MEM__ACCESS__INFO.html
│       │       ├── struct__tcpClientStruct-members.html
│       │       ├── struct__tcpClientStruct.html
│       │       ├── struct__tcpServerStruct-members.html
│       │       ├── struct__tcpServerStruct.html
│       │       ├── tab_b.gif
│       │       ├── tab_l.gif
│       │       ├── tab_r.gif
│       │       ├── tabs.css
│       │       ├── unionPIN__MEM__TRANS__FLAGS-members.html
│       │       ├── unionPIN__MEM__TRANS__FLAGS.html
│       │       ├── unionPIN__REGISTER-members.html
│       │       └── unionPIN__REGISTER.html
│       ├── extras
│       │   ├── components
│       │   │   ├── include
│       │   │   │   ├── asm
│       │   │   │   │   ├── gas-ia64.h
│       │   │   │   │   ├── gas-x86.h
│       │   │   │   │   ├── masm-x86.h
│       │   │   │   │   ├── nasm-x86.h
│       │   │   │   │   ├── unix-intel64.h
│       │   │   │   │   └── windows-intel64.h
│       │   │   │   ├── asm.h
│       │   │   │   ├── atomic
│       │   │   │   │   ├── config.hpp
│       │   │   │   │   ├── exponential-backoff.hpp
│       │   │   │   │   ├── fixed-lifo.hpp
│       │   │   │   │   ├── fixed-multimap.hpp
│       │   │   │   │   ├── fixed-multiset.hpp
│       │   │   │   │   ├── idset.hpp
│       │   │   │   │   ├── lifo-ctr.hpp
│       │   │   │   │   ├── lifo-ptr.hpp
│       │   │   │   │   ├── nullstats.hpp
│       │   │   │   │   ├── ops-enum.hpp
│       │   │   │   │   ├── ops.hpp
│       │   │   │   │   └── private
│       │   │   │   │       ├── backoff-impl.hpp
│       │   │   │   │       ├── ia32
│       │   │   │   │       │   ├── ops-impl-ia32-asm.hpp
│       │   │   │   │       │   └── ops-impl.hpp
│       │   │   │   │       ├── ia64
│       │   │   │   │       │   ├── ops-impl-ia64-asm.hpp
│       │   │   │   │       │   └── ops-impl.hpp
│       │   │   │   │       ├── intel64
│       │   │   │   │       │   ├── ops-impl-intel64-asm.hpp
│       │   │   │   │       │   └── ops-impl.hpp
│       │   │   │   │       └── ops-common-impl.hpp
│       │   │   │   ├── atomic.hpp
│       │   │   │   ├── barecrt
│       │   │   │   │   ├── bsd-intel64
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── futex.hpp
│       │   │   │   │   ├── linux-ia32
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── linux-ia64
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── linux-intel64
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── mac-ia32
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── mac-intel64
│       │   │   │   │   │   ├── resource.hpp
│       │   │   │   │   │   └── signal-types.hpp
│       │   │   │   │   ├── process.hpp
│       │   │   │   │   ├── signal-mac.hpp
│       │   │   │   │   ├── signal.hpp
│       │   │   │   │   ├── sigset128.hpp
│       │   │   │   │   ├── sigset32.hpp
│       │   │   │   │   ├── sigset64.hpp
│       │   │   │   │   ├── time.hpp
│       │   │   │   │   └── types.hpp
│       │   │   │   ├── barecrt.hpp
│       │   │   │   ├── debugger-protocol
│       │   │   │   │   ├── event-linux.hpp
│       │   │   │   │   ├── event-mac.hpp
│       │   │   │   │   ├── event-windows.hpp
│       │   │   │   │   ├── forward.hpp
│       │   │   │   │   ├── image-linux.hpp
│       │   │   │   │   ├── image-mac.hpp
│       │   │   │   │   ├── image-windows.hpp
│       │   │   │   │   ├── regs-gdb-linux-avx32.hpp
│       │   │   │   │   ├── regs-gdb-linux-avx64.hpp
│       │   │   │   │   ├── regs-gdb-linux-ia32.hpp
│       │   │   │   │   ├── regs-gdb-linux-intel64.hpp
│       │   │   │   │   ├── regs-gdb-mac-ia32.hpp
│       │   │   │   │   ├── regs-gdb-mac-intel64.hpp
│       │   │   │   │   ├── regs-windows-ia32.hpp
│       │   │   │   │   ├── regs-windows-intel64.hpp
│       │   │   │   │   ├── thread-linux.hpp
│       │   │   │   │   ├── thread-mac.hpp
│       │   │   │   │   └── thread-windows.hpp
│       │   │   │   ├── debugger-protocol.hpp
│       │   │   │   ├── fund
│       │   │   │   │   ├── config-hostos.h
│       │   │   │   │   ├── config-targetos.h
│       │   │   │   │   └── config.h
│       │   │   │   ├── fund.hpp
│       │   │   │   ├── sync
│       │   │   │   │   ├── backoff-or-yield.hpp
│       │   │   │   │   ├── config.hpp
│       │   │   │   │   ├── documentation.hpp
│       │   │   │   │   ├── os-barecrt-linux.hpp
│       │   │   │   │   ├── os-barecrt-time.hpp
│       │   │   │   │   ├── os-barecrt.hpp
│       │   │   │   │   ├── os-posix-time.hpp
│       │   │   │   │   ├── os-posix.hpp
│       │   │   │   │   ├── reader-writer-lock-futex.hpp
│       │   │   │   │   ├── reader-writer-lock-spin.hpp
│       │   │   │   │   ├── reader-writer-lock.hpp
│       │   │   │   │   ├── semaphore-event.hpp
│       │   │   │   │   ├── semaphore-futex.hpp
│       │   │   │   │   ├── semaphore-spin.hpp
│       │   │   │   │   ├── semaphore.hpp
│       │   │   │   │   ├── simple-lock-futex.hpp
│       │   │   │   │   ├── simple-lock-spin.hpp
│       │   │   │   │   └── simple-lock.hpp
│       │   │   │   ├── sync.hpp
│       │   │   │   ├── util
│       │   │   │   │   ├── data.hpp
│       │   │   │   │   ├── intel-fp.hpp
│       │   │   │   │   ├── locker.hpp
│       │   │   │   │   ├── numberbits.hpp
│       │   │   │   │   ├── quote-argument-ms.hpp
│       │   │   │   │   ├── range.hpp
│       │   │   │   │   ├── regvalue.hpp
│       │   │   │   │   ├── round.hpp
│       │   │   │   │   ├── scoped-array.hpp
│       │   │   │   │   ├── scoped-ptr.hpp
│       │   │   │   │   ├── singleton.hpp
│       │   │   │   │   └── strings.hpp
│       │   │   │   └── util.hpp
│       │   │   └── lib
│       │   │       ├── ia32
│       │   │       │   ├── libatomic.a
│       │   │       │   ├── libdebugger-protocol.a
│       │   │       │   └── libdebugger-protocol.so
│       │   │       └── intel64
│       │   │           ├── libatomic.a
│       │   │           ├── libdebugger-protocol.a
│       │   │           └── libdebugger-protocol.so
│       │   ├── xed-ia32
│       │   │   ├── BUG-REPORTS.txt
│       │   │   ├── LICENSE.txt
│       │   │   ├── README.txt
│       │   │   ├── bin
│       │   │   │   └── xed
│       │   │   ├── doc
│       │   │   │   └── ref-manual
│       │   │   │       ├── html
│       │   │   │       │   ├── annotated.html
│       │   │   │       │   ├── classes.html
│       │   │   │       │   ├── doxygen.css
│       │   │   │       │   ├── doxygen.png
│       │   │   │       │   ├── files.html
│       │   │   │       │   ├── ftv2blank.png
│       │   │   │       │   ├── ftv2doc.png
│       │   │   │       │   ├── ftv2folderclosed.png
│       │   │   │       │   ├── ftv2folderopen.png
│       │   │   │       │   ├── ftv2lastnode.png
│       │   │   │       │   ├── ftv2link.png
│       │   │   │       │   ├── ftv2mlastnode.png
│       │   │   │       │   ├── ftv2mnode.png
│       │   │   │       │   ├── ftv2node.png
│       │   │   │       │   ├── ftv2plastnode.png
│       │   │   │       │   ├── ftv2pnode.png
│       │   │   │       │   ├── ftv2vertline.png
│       │   │   │       │   ├── functions.html
│       │   │   │       │   ├── functions_0x61.html
│       │   │   │       │   ├── functions_0x62.html
│       │   │   │       │   ├── functions_0x63.html
│       │   │   │       │   ├── functions_0x64.html
│       │   │   │       │   ├── functions_0x65.html
│       │   │   │       │   ├── functions_0x66.html
│       │   │   │       │   ├── functions_0x68.html
│       │   │   │       │   ├── functions_0x69.html
│       │   │   │       │   ├── functions_0x6c.html
│       │   │   │       │   ├── functions_0x6d.html
│       │   │   │       │   ├── functions_0x6e.html
│       │   │   │       │   ├── functions_0x6f.html
│       │   │   │       │   ├── functions_0x70.html
│       │   │   │       │   ├── functions_0x71.html
│       │   │   │       │   ├── functions_0x72.html
│       │   │   │       │   ├── functions_0x73.html
│       │   │   │       │   ├── functions_0x74.html
│       │   │   │       │   ├── functions_0x75.html
│       │   │   │       │   ├── functions_0x76.html
│       │   │   │       │   ├── functions_0x77.html
│       │   │   │       │   ├── functions_0x78.html
│       │   │   │       │   ├── functions_0x7a.html
│       │   │   │       │   ├── functions_vars.html
│       │   │   │       │   ├── functions_vars_0x61.html
│       │   │   │       │   ├── functions_vars_0x62.html
│       │   │   │       │   ├── functions_vars_0x63.html
│       │   │   │       │   ├── functions_vars_0x64.html
│       │   │   │       │   ├── functions_vars_0x65.html
│       │   │   │       │   ├── functions_vars_0x66.html
│       │   │   │       │   ├── functions_vars_0x68.html
│       │   │   │       │   ├── functions_vars_0x69.html
│       │   │   │       │   ├── functions_vars_0x6c.html
│       │   │   │       │   ├── functions_vars_0x6d.html
│       │   │   │       │   ├── functions_vars_0x6e.html
│       │   │   │       │   ├── functions_vars_0x6f.html
│       │   │   │       │   ├── functions_vars_0x70.html
│       │   │   │       │   ├── functions_vars_0x71.html
│       │   │   │       │   ├── functions_vars_0x72.html
│       │   │   │       │   ├── functions_vars_0x73.html
│       │   │   │       │   ├── functions_vars_0x74.html
│       │   │   │       │   ├── functions_vars_0x75.html
│       │   │   │       │   ├── functions_vars_0x76.html
│       │   │   │       │   ├── functions_vars_0x77.html
│       │   │   │       │   ├── functions_vars_0x78.html
│       │   │   │       │   ├── functions_vars_0x7a.html
│       │   │   │       │   ├── globals.html
│       │   │   │       │   ├── globals_0x73.html
│       │   │   │       │   ├── globals_0x78.html
│       │   │   │       │   ├── globals_defs.html
│       │   │   │       │   ├── globals_enum.html
│       │   │   │       │   ├── globals_eval.html
│       │   │   │       │   ├── globals_func.html
│       │   │   │       │   ├── globals_func_0x78.html
│       │   │   │       │   ├── globals_type.html
│       │   │   │       │   ├── globals_vars.html
│       │   │   │       │   ├── group__AGEN.html
│       │   │   │       │   ├── group__CMDLINE.html
│       │   │   │       │   ├── group__DEC.html
│       │   │   │       │   ├── group__ENC.html
│       │   │   │       │   ├── group__ENCHL.html
│       │   │   │       │   ├── group__ENUM.html
│       │   │   │       │   ├── group__EXAMPLES.html
│       │   │   │       │   ├── group__FLAGS.html
│       │   │   │       │   ├── group__IFORM.html
│       │   │   │       │   ├── group__INIT.html
│       │   │   │       │   ├── group__ISASET.html
│       │   │   │       │   ├── group__OPERANDS.html
│       │   │   │       │   ├── group__PRINT.html
│       │   │   │       │   ├── group__REGINTFC.html
│       │   │   │       │   ├── group__SMALLEXAMPLES.html
│       │   │   │       │   ├── hierarchy.html
│       │   │   │       │   ├── index.html
│       │   │   │       │   ├── installdox
│       │   │   │       │   ├── main.html
│       │   │   │       │   ├── modules.html
│       │   │   │       │   ├── search.idx
│       │   │   │       │   ├── search.php
│       │   │   │       │   ├── structxed__attributes__t.html
│       │   │   │       │   ├── structxed__convert__table__t.html
│       │   │   │       │   ├── structxed__decoded__inst__s.html
│       │   │   │       │   ├── structxed__enc__displacement__t.html
│       │   │   │       │   ├── structxed__encoder__iforms__s.html
│       │   │   │       │   ├── structxed__encoder__instruction__t.html
│       │   │   │       │   ├── structxed__encoder__operand__t.html
│       │   │   │       │   ├── structxed__flag__enum__s.html
│       │   │   │       │   ├── structxed__format__options__t.html
│       │   │   │       │   ├── structxed__iform__info__s.html
│       │   │   │       │   ├── structxed__immdis__s.html
│       │   │   │       │   ├── structxed__inst__s.html
│       │   │   │       │   ├── structxed__memop__t.html
│       │   │   │       │   ├── structxed__operand__s.html
│       │   │   │       │   ├── structxed__operand__storage__s.html
│       │   │   │       │   ├── structxed__print__info__t.html
│       │   │   │       │   ├── structxed__simple__flag__s.html
│       │   │   │       │   ├── structxed__state__s.html
│       │   │   │       │   ├── tab_b.gif
│       │   │   │       │   ├── tab_l.gif
│       │   │   │       │   ├── tab_r.gif
│       │   │   │       │   ├── tabs.css
│       │   │   │       │   ├── tree.html
│       │   │   │       │   ├── unionxed__encoder__prefixes__t.html
│       │   │   │       │   ├── unionxed__flag__set__s.html
│       │   │   │       │   ├── unionxed__immdis__values__t.html
│       │   │   │       │   ├── unionxed__union16__t.html
│       │   │   │       │   ├── unionxed__union32__t.html
│       │   │   │       │   ├── unionxed__union64__t.html
│       │   │   │       │   ├── xed-address-width-enum_8h-source.html
│       │   │   │       │   ├── xed-address-width-enum_8h.html
│       │   │   │       │   ├── xed-agen_8h-source.html
│       │   │   │       │   ├── xed-agen_8h.html
│       │   │   │       │   ├── xed-attribute-enum_8h-source.html
│       │   │   │       │   ├── xed-attribute-enum_8h.html
│       │   │   │       │   ├── xed-attributes_8h-source.html
│       │   │   │       │   ├── xed-attributes_8h.html
│       │   │   │       │   ├── xed-build-defines_8h-source.html
│       │   │   │       │   ├── xed-build-defines_8h.html
│       │   │   │       │   ├── xed-category-enum_8h-source.html
│       │   │   │       │   ├── xed-category-enum_8h.html
│       │   │   │       │   ├── xed-chip-enum_8h-source.html
│       │   │   │       │   ├── xed-chip-enum_8h.html
│       │   │   │       │   ├── xed-common-defs_8h-source.html
│       │   │   │       │   ├── xed-common-defs_8h.html
│       │   │   │       │   ├── xed-common-hdrs_8h-source.html
│       │   │   │       │   ├── xed-common-hdrs_8h.html
│       │   │   │       │   ├── xed-convert-table-init_8h-source.html
│       │   │   │       │   ├── xed-convert-table-init_8h.html
│       │   │   │       │   ├── xed-decode_8h-source.html
│       │   │   │       │   ├── xed-decode_8h.html
│       │   │   │       │   ├── xed-decoded-inst-api_8h-source.html
│       │   │   │       │   ├── xed-decoded-inst-api_8h.html
│       │   │   │       │   ├── xed-decoded-inst_8h-source.html
│       │   │   │       │   ├── xed-decoded-inst_8h.html
│       │   │   │       │   ├── xed-disas_8h-source.html
│       │   │   │       │   ├── xed-disas_8h.html
│       │   │   │       │   ├── xed-doc-top_8txt.html
│       │   │   │       │   ├── xed-encode_8h-source.html
│       │   │   │       │   ├── xed-encode_8h.html
│       │   │   │       │   ├── xed-encoder-gen-defs_8h-source.html
│       │   │   │       │   ├── xed-encoder-gen-defs_8h.html
│       │   │   │       │   ├── xed-encoder-hl_8h-source.html
│       │   │   │       │   ├── xed-encoder-hl_8h.html
│       │   │   │       │   ├── xed-encoder-iforms_8h-source.html
│       │   │   │       │   ├── xed-encoder-iforms_8h.html
│       │   │   │       │   ├── xed-error-enum_8h-source.html
│       │   │   │       │   ├── xed-error-enum_8h.html
│       │   │   │       │   ├── xed-exception-enum_8h-source.html
│       │   │   │       │   ├── xed-exception-enum_8h.html
│       │   │   │       │   ├── xed-extension-enum_8h-source.html
│       │   │   │       │   ├── xed-extension-enum_8h.html
│       │   │   │       │   ├── xed-flag-action-enum_8h-source.html
│       │   │   │       │   ├── xed-flag-action-enum_8h.html
│       │   │   │       │   ├── xed-flag-enum_8h-source.html
│       │   │   │       │   ├── xed-flag-enum_8h.html
│       │   │   │       │   ├── xed-flags_8h-source.html
│       │   │   │       │   ├── xed-flags_8h.html
│       │   │   │       │   ├── xed-format-options_8h-source.html
│       │   │   │       │   ├── xed-format-options_8h.html
│       │   │   │       │   ├── xed-gen-table-defs_8h-source.html
│       │   │   │       │   ├── xed-gen-table-defs_8h.html
│       │   │   │       │   ├── xed-get-time_8h-source.html
│       │   │   │       │   ├── xed-get-time_8h.html
│       │   │   │       │   ├── xed-iclass-enum_8h-source.html
│       │   │   │       │   ├── xed-iclass-enum_8h.html
│       │   │   │       │   ├── xed-iform-enum_8h-source.html
│       │   │   │       │   ├── xed-iform-enum_8h.html
│       │   │   │       │   ├── xed-iform-map_8h-source.html
│       │   │   │       │   ├── xed-iform-map_8h.html
│       │   │   │       │   ├── xed-iformfl-enum_8h-source.html
│       │   │   │       │   ├── xed-iformfl-enum_8h.html
│       │   │   │       │   ├── xed-ild_8h-source.html
│       │   │   │       │   ├── xed-ild_8h.html
│       │   │   │       │   ├── xed-immdis_8h-source.html
│       │   │   │       │   ├── xed-immdis_8h.html
│       │   │   │       │   ├── xed-immed_8h-source.html
│       │   │   │       │   ├── xed-immed_8h.html
│       │   │   │       │   ├── xed-init-pointer-names_8h-source.html
│       │   │   │       │   ├── xed-init-pointer-names_8h.html
│       │   │   │       │   ├── xed-init_8h-source.html
│       │   │   │       │   ├── xed-init_8h.html
│       │   │   │       │   ├── xed-inst_8h-source.html
│       │   │   │       │   ├── xed-inst_8h.html
│       │   │   │       │   ├── xed-interface_8h-source.html
│       │   │   │       │   ├── xed-interface_8h.html
│       │   │   │       │   ├── xed-isa-set-enum_8h-source.html
│       │   │   │       │   ├── xed-isa-set-enum_8h.html
│       │   │   │       │   ├── xed-isa-set_8h-source.html
│       │   │   │       │   ├── xed-isa-set_8h.html
│       │   │   │       │   ├── xed-machine-mode-enum_8h-source.html
│       │   │   │       │   ├── xed-machine-mode-enum_8h.html
│       │   │   │       │   ├── xed-nonterminal-enum_8h-source.html
│       │   │   │       │   ├── xed-nonterminal-enum_8h.html
│       │   │   │       │   ├── xed-operand-accessors_8h-source.html
│       │   │   │       │   ├── xed-operand-accessors_8h.html
│       │   │   │       │   ├── xed-operand-action-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-action-enum_8h.html
│       │   │   │       │   ├── xed-operand-action_8h-source.html
│       │   │   │       │   ├── xed-operand-action_8h.html
│       │   │   │       │   ├── xed-operand-convert-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-convert-enum_8h.html
│       │   │   │       │   ├── xed-operand-ctype-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-ctype-enum_8h.html
│       │   │   │       │   ├── xed-operand-ctype-map_8h-source.html
│       │   │   │       │   ├── xed-operand-ctype-map_8h.html
│       │   │   │       │   ├── xed-operand-element-type-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-element-type-enum_8h.html
│       │   │   │       │   ├── xed-operand-element-xtype-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-element-xtype-enum_8h.html
│       │   │   │       │   ├── xed-operand-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-enum_8h.html
│       │   │   │       │   ├── xed-operand-storage_8h-source.html
│       │   │   │       │   ├── xed-operand-storage_8h.html
│       │   │   │       │   ├── xed-operand-type-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-type-enum_8h.html
│       │   │   │       │   ├── xed-operand-values-interface_8h-source.html
│       │   │   │       │   ├── xed-operand-values-interface_8h.html
│       │   │   │       │   ├── xed-operand-visibility-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-visibility-enum_8h.html
│       │   │   │       │   ├── xed-operand-width-enum_8h-source.html
│       │   │   │       │   ├── xed-operand-width-enum_8h.html
│       │   │   │       │   ├── xed-portability_8h-source.html
│       │   │   │       │   ├── xed-portability_8h.html
│       │   │   │       │   ├── xed-print-info_8h-source.html
│       │   │   │       │   ├── xed-print-info_8h.html
│       │   │   │       │   ├── xed-reg-class-enum_8h-source.html
│       │   │   │       │   ├── xed-reg-class-enum_8h.html
│       │   │   │       │   ├── xed-reg-class_8h-source.html
│       │   │   │       │   ├── xed-reg-class_8h.html
│       │   │   │       │   ├── xed-reg-enum_8h-source.html
│       │   │   │       │   ├── xed-reg-enum_8h.html
│       │   │   │       │   ├── xed-reg-role-enum_8h-source.html
│       │   │   │       │   ├── xed-reg-role-enum_8h.html
│       │   │   │       │   ├── xed-state_8h-source.html
│       │   │   │       │   ├── xed-state_8h.html
│       │   │   │       │   ├── xed-syntax-enum_8h-source.html
│       │   │   │       │   ├── xed-syntax-enum_8h.html
│       │   │   │       │   ├── xed-types_8h-source.html
│       │   │   │       │   ├── xed-types_8h.html
│       │   │   │       │   ├── xed-util_8h-source.html
│       │   │   │       │   ├── xed-util_8h.html
│       │   │   │       │   ├── xed-version_8h-source.html
│       │   │   │       │   └── xed-version_8h.html
│       │   │   │       └── xed.tag
│       │   │   ├── examples
│       │   │   │   ├── makefile
│       │   │   │   ├── udhelp.H
│       │   │   │   ├── udhelp.cpp
│       │   │   │   ├── xed-disas-elf.H
│       │   │   │   ├── xed-disas-elf.cpp
│       │   │   │   ├── xed-disas-hex.H
│       │   │   │   ├── xed-disas-hex.cpp
│       │   │   │   ├── xed-disas-macho.H
│       │   │   │   ├── xed-disas-macho.cpp
│       │   │   │   ├── xed-disas-pecoff.H
│       │   │   │   ├── xed-disas-pecoff.cpp
│       │   │   │   ├── xed-disas-raw.H
│       │   │   │   ├── xed-disas-raw.cpp
│       │   │   │   ├── xed-dll-discovery.c
│       │   │   │   ├── xed-dot-prep.c
│       │   │   │   ├── xed-dot-prep.h
│       │   │   │   ├── xed-dot.c
│       │   │   │   ├── xed-dot.h
│       │   │   │   ├── xed-enc-lang.H
│       │   │   │   ├── xed-enc-lang.cpp
│       │   │   │   ├── xed-ex-agen.c
│       │   │   │   ├── xed-ex-ild.c
│       │   │   │   ├── xed-ex-ild2.c
│       │   │   │   ├── xed-ex1.cpp
│       │   │   │   ├── xed-ex2.cpp
│       │   │   │   ├── xed-ex3.cpp
│       │   │   │   ├── xed-ex4.c
│       │   │   │   ├── xed-ex5-enc.c
│       │   │   │   ├── xed-ex6.c
│       │   │   │   ├── xed-ex7.c
│       │   │   │   ├── xed-ex8.c
│       │   │   │   ├── xed-examples-ostreams.H
│       │   │   │   ├── xed-examples-ostreams.cpp
│       │   │   │   ├── xed-examples-util.c
│       │   │   │   ├── xed-examples-util.h
│       │   │   │   ├── xed-min.c
│       │   │   │   ├── xed-size.c
│       │   │   │   ├── xed-symbol-table.H
│       │   │   │   ├── xed-symbol-table.cpp
│       │   │   │   ├── xed-tables.c
│       │   │   │   ├── xed-tester.cpp
│       │   │   │   └── xed.cpp
│       │   │   ├── extlib
│       │   │   │   ├── libc.so.6
│       │   │   │   ├── libgcc_s.so.1
│       │   │   │   ├── libm.so.6
│       │   │   │   └── libstdc++.so.6
│       │   │   ├── include
│       │   │   │   ├── xed-address-width-enum.h
│       │   │   │   ├── xed-agen.h
│       │   │   │   ├── xed-attribute-enum.h
│       │   │   │   ├── xed-attributes.h
│       │   │   │   ├── xed-build-defines.h
│       │   │   │   ├── xed-category-enum.h
│       │   │   │   ├── xed-chip-enum.h
│       │   │   │   ├── xed-common-defs.h
│       │   │   │   ├── xed-common-hdrs.h
│       │   │   │   ├── xed-convert-table-init.h
│       │   │   │   ├── xed-decode.h
│       │   │   │   ├── xed-decoded-inst-api.h
│       │   │   │   ├── xed-decoded-inst.h
│       │   │   │   ├── xed-disas.h
│       │   │   │   ├── xed-encode.h
│       │   │   │   ├── xed-encoder-gen-defs.h
│       │   │   │   ├── xed-encoder-hl.h
│       │   │   │   ├── xed-encoder-iforms.h
│       │   │   │   ├── xed-error-enum.h
│       │   │   │   ├── xed-exception-enum.h
│       │   │   │   ├── xed-extension-enum.h
│       │   │   │   ├── xed-flag-action-enum.h
│       │   │   │   ├── xed-flag-enum.h
│       │   │   │   ├── xed-flags.h
│       │   │   │   ├── xed-format-options.h
│       │   │   │   ├── xed-gen-table-defs.h
│       │   │   │   ├── xed-get-time.h
│       │   │   │   ├── xed-iclass-enum.h
│       │   │   │   ├── xed-iform-enum.h
│       │   │   │   ├── xed-iform-map.h
│       │   │   │   ├── xed-iformfl-enum.h
│       │   │   │   ├── xed-ild.h
│       │   │   │   ├── xed-immdis.h
│       │   │   │   ├── xed-immed.h
│       │   │   │   ├── xed-init-pointer-names.h
│       │   │   │   ├── xed-init.h
│       │   │   │   ├── xed-inst.h
│       │   │   │   ├── xed-interface.h
│       │   │   │   ├── xed-isa-set-enum.h
│       │   │   │   ├── xed-isa-set.h
│       │   │   │   ├── xed-machine-mode-enum.h
│       │   │   │   ├── xed-nonterminal-enum.h
│       │   │   │   ├── xed-operand-accessors.h
│       │   │   │   ├── xed-operand-action-enum.h
│       │   │   │   ├── xed-operand-action.h
│       │   │   │   ├── xed-operand-convert-enum.h
│       │   │   │   ├── xed-operand-ctype-enum.h
│       │   │   │   ├── xed-operand-ctype-map.h
│       │   │   │   ├── xed-operand-element-type-enum.h
│       │   │   │   ├── xed-operand-element-xtype-enum.h
│       │   │   │   ├── xed-operand-enum.h
│       │   │   │   ├── xed-operand-storage.h
│       │   │   │   ├── xed-operand-type-enum.h
│       │   │   │   ├── xed-operand-values-interface.h
│       │   │   │   ├── xed-operand-visibility-enum.h
│       │   │   │   ├── xed-operand-width-enum.h
│       │   │   │   ├── xed-portability.h
│       │   │   │   ├── xed-print-info.h
│       │   │   │   ├── xed-reg-class-enum.h
│       │   │   │   ├── xed-reg-class.h
│       │   │   │   ├── xed-reg-enum.h
│       │   │   │   ├── xed-reg-role-enum.h
│       │   │   │   ├── xed-state.h
│       │   │   │   ├── xed-syntax-enum.h
│       │   │   │   ├── xed-types.h
│       │   │   │   ├── xed-util.h
│       │   │   │   └── xed-version.h
│       │   │   ├── lib
│       │   │   │   ├── libxed-ild.a
│       │   │   │   └── libxed.a
│       │   │   ├── misc
│       │   │   │   └── idata.txt
│       │   │   └── redist.txt
│       │   └── xed-intel64
│       │       ├── BUG-REPORTS.txt
│       │       ├── LICENSE.txt
│       │       ├── README.txt
│       │       ├── bin
│       │       │   └── xed
│       │       ├── doc
│       │       │   └── ref-manual
│       │       │       ├── html
│       │       │       │   ├── annotated.html
│       │       │       │   ├── classes.html
│       │       │       │   ├── doxygen.css
│       │       │       │   ├── doxygen.png
│       │       │       │   ├── files.html
│       │       │       │   ├── ftv2blank.png
│       │       │       │   ├── ftv2doc.png
│       │       │       │   ├── ftv2folderclosed.png
│       │       │       │   ├── ftv2folderopen.png
│       │       │       │   ├── ftv2lastnode.png
│       │       │       │   ├── ftv2link.png
│       │       │       │   ├── ftv2mlastnode.png
│       │       │       │   ├── ftv2mnode.png
│       │       │       │   ├── ftv2node.png
│       │       │       │   ├── ftv2plastnode.png
│       │       │       │   ├── ftv2pnode.png
│       │       │       │   ├── ftv2vertline.png
│       │       │       │   ├── functions.html
│       │       │       │   ├── functions_0x61.html
│       │       │       │   ├── functions_0x62.html
│       │       │       │   ├── functions_0x63.html
│       │       │       │   ├── functions_0x64.html
│       │       │       │   ├── functions_0x65.html
│       │       │       │   ├── functions_0x66.html
│       │       │       │   ├── functions_0x68.html
│       │       │       │   ├── functions_0x69.html
│       │       │       │   ├── functions_0x6c.html
│       │       │       │   ├── functions_0x6d.html
│       │       │       │   ├── functions_0x6e.html
│       │       │       │   ├── functions_0x6f.html
│       │       │       │   ├── functions_0x70.html
│       │       │       │   ├── functions_0x71.html
│       │       │       │   ├── functions_0x72.html
│       │       │       │   ├── functions_0x73.html
│       │       │       │   ├── functions_0x74.html
│       │       │       │   ├── functions_0x75.html
│       │       │       │   ├── functions_0x76.html
│       │       │       │   ├── functions_0x77.html
│       │       │       │   ├── functions_0x78.html
│       │       │       │   ├── functions_0x7a.html
│       │       │       │   ├── functions_vars.html
│       │       │       │   ├── functions_vars_0x61.html
│       │       │       │   ├── functions_vars_0x62.html
│       │       │       │   ├── functions_vars_0x63.html
│       │       │       │   ├── functions_vars_0x64.html
│       │       │       │   ├── functions_vars_0x65.html
│       │       │       │   ├── functions_vars_0x66.html
│       │       │       │   ├── functions_vars_0x68.html
│       │       │       │   ├── functions_vars_0x69.html
│       │       │       │   ├── functions_vars_0x6c.html
│       │       │       │   ├── functions_vars_0x6d.html
│       │       │       │   ├── functions_vars_0x6e.html
│       │       │       │   ├── functions_vars_0x6f.html
│       │       │       │   ├── functions_vars_0x70.html
│       │       │       │   ├── functions_vars_0x71.html
│       │       │       │   ├── functions_vars_0x72.html
│       │       │       │   ├── functions_vars_0x73.html
│       │       │       │   ├── functions_vars_0x74.html
│       │       │       │   ├── functions_vars_0x75.html
│       │       │       │   ├── functions_vars_0x76.html
│       │       │       │   ├── functions_vars_0x77.html
│       │       │       │   ├── functions_vars_0x78.html
│       │       │       │   ├── functions_vars_0x7a.html
│       │       │       │   ├── globals.html
│       │       │       │   ├── globals_0x73.html
│       │       │       │   ├── globals_0x78.html
│       │       │       │   ├── globals_defs.html
│       │       │       │   ├── globals_enum.html
│       │       │       │   ├── globals_eval.html
│       │       │       │   ├── globals_func.html
│       │       │       │   ├── globals_func_0x78.html
│       │       │       │   ├── globals_type.html
│       │       │       │   ├── globals_vars.html
│       │       │       │   ├── group__AGEN.html
│       │       │       │   ├── group__CMDLINE.html
│       │       │       │   ├── group__DEC.html
│       │       │       │   ├── group__ENC.html
│       │       │       │   ├── group__ENCHL.html
│       │       │       │   ├── group__ENUM.html
│       │       │       │   ├── group__EXAMPLES.html
│       │       │       │   ├── group__FLAGS.html
│       │       │       │   ├── group__IFORM.html
│       │       │       │   ├── group__INIT.html
│       │       │       │   ├── group__ISASET.html
│       │       │       │   ├── group__OPERANDS.html
│       │       │       │   ├── group__PRINT.html
│       │       │       │   ├── group__REGINTFC.html
│       │       │       │   ├── group__SMALLEXAMPLES.html
│       │       │       │   ├── hierarchy.html
│       │       │       │   ├── index.html
│       │       │       │   ├── installdox
│       │       │       │   ├── main.html
│       │       │       │   ├── modules.html
│       │       │       │   ├── search.idx
│       │       │       │   ├── search.php
│       │       │       │   ├── structxed__attributes__t.html
│       │       │       │   ├── structxed__convert__table__t.html
│       │       │       │   ├── structxed__decoded__inst__s.html
│       │       │       │   ├── structxed__enc__displacement__t.html
│       │       │       │   ├── structxed__encoder__iforms__s.html
│       │       │       │   ├── structxed__encoder__instruction__t.html
│       │       │       │   ├── structxed__encoder__operand__t.html
│       │       │       │   ├── structxed__flag__enum__s.html
│       │       │       │   ├── structxed__format__options__t.html
│       │       │       │   ├── structxed__iform__info__s.html
│       │       │       │   ├── structxed__immdis__s.html
│       │       │       │   ├── structxed__inst__s.html
│       │       │       │   ├── structxed__memop__t.html
│       │       │       │   ├── structxed__operand__s.html
│       │       │       │   ├── structxed__operand__storage__s.html
│       │       │       │   ├── structxed__print__info__t.html
│       │       │       │   ├── structxed__simple__flag__s.html
│       │       │       │   ├── structxed__state__s.html
│       │       │       │   ├── tab_b.gif
│       │       │       │   ├── tab_l.gif
│       │       │       │   ├── tab_r.gif
│       │       │       │   ├── tabs.css
│       │       │       │   ├── tree.html
│       │       │       │   ├── unionxed__encoder__prefixes__t.html
│       │       │       │   ├── unionxed__flag__set__s.html
│       │       │       │   ├── unionxed__immdis__values__t.html
│       │       │       │   ├── unionxed__union16__t.html
│       │       │       │   ├── unionxed__union32__t.html
│       │       │       │   ├── unionxed__union64__t.html
│       │       │       │   ├── xed-address-width-enum_8h-source.html
│       │       │       │   ├── xed-address-width-enum_8h.html
│       │       │       │   ├── xed-agen_8h-source.html
│       │       │       │   ├── xed-agen_8h.html
│       │       │       │   ├── xed-attribute-enum_8h-source.html
│       │       │       │   ├── xed-attribute-enum_8h.html
│       │       │       │   ├── xed-attributes_8h-source.html
│       │       │       │   ├── xed-attributes_8h.html
│       │       │       │   ├── xed-build-defines_8h-source.html
│       │       │       │   ├── xed-build-defines_8h.html
│       │       │       │   ├── xed-category-enum_8h-source.html
│       │       │       │   ├── xed-category-enum_8h.html
│       │       │       │   ├── xed-chip-enum_8h-source.html
│       │       │       │   ├── xed-chip-enum_8h.html
│       │       │       │   ├── xed-common-defs_8h-source.html
│       │       │       │   ├── xed-common-defs_8h.html
│       │       │       │   ├── xed-common-hdrs_8h-source.html
│       │       │       │   ├── xed-common-hdrs_8h.html
│       │       │       │   ├── xed-convert-table-init_8h-source.html
│       │       │       │   ├── xed-convert-table-init_8h.html
│       │       │       │   ├── xed-decode_8h-source.html
│       │       │       │   ├── xed-decode_8h.html
│       │       │       │   ├── xed-decoded-inst-api_8h-source.html
│       │       │       │   ├── xed-decoded-inst-api_8h.html
│       │       │       │   ├── xed-decoded-inst_8h-source.html
│       │       │       │   ├── xed-decoded-inst_8h.html
│       │       │       │   ├── xed-disas_8h-source.html
│       │       │       │   ├── xed-disas_8h.html
│       │       │       │   ├── xed-doc-top_8txt.html
│       │       │       │   ├── xed-encode_8h-source.html
│       │       │       │   ├── xed-encode_8h.html
│       │       │       │   ├── xed-encoder-gen-defs_8h-source.html
│       │       │       │   ├── xed-encoder-gen-defs_8h.html
│       │       │       │   ├── xed-encoder-hl_8h-source.html
│       │       │       │   ├── xed-encoder-hl_8h.html
│       │       │       │   ├── xed-encoder-iforms_8h-source.html
│       │       │       │   ├── xed-encoder-iforms_8h.html
│       │       │       │   ├── xed-error-enum_8h-source.html
│       │       │       │   ├── xed-error-enum_8h.html
│       │       │       │   ├── xed-exception-enum_8h-source.html
│       │       │       │   ├── xed-exception-enum_8h.html
│       │       │       │   ├── xed-extension-enum_8h-source.html
│       │       │       │   ├── xed-extension-enum_8h.html
│       │       │       │   ├── xed-flag-action-enum_8h-source.html
│       │       │       │   ├── xed-flag-action-enum_8h.html
│       │       │       │   ├── xed-flag-enum_8h-source.html
│       │       │       │   ├── xed-flag-enum_8h.html
│       │       │       │   ├── xed-flags_8h-source.html
│       │       │       │   ├── xed-flags_8h.html
│       │       │       │   ├── xed-format-options_8h-source.html
│       │       │       │   ├── xed-format-options_8h.html
│       │       │       │   ├── xed-gen-table-defs_8h-source.html
│       │       │       │   ├── xed-gen-table-defs_8h.html
│       │       │       │   ├── xed-get-time_8h-source.html
│       │       │       │   ├── xed-get-time_8h.html
│       │       │       │   ├── xed-iclass-enum_8h-source.html
│       │       │       │   ├── xed-iclass-enum_8h.html
│       │       │       │   ├── xed-iform-enum_8h-source.html
│       │       │       │   ├── xed-iform-enum_8h.html
│       │       │       │   ├── xed-iform-map_8h-source.html
│       │       │       │   ├── xed-iform-map_8h.html
│       │       │       │   ├── xed-iformfl-enum_8h-source.html
│       │       │       │   ├── xed-iformfl-enum_8h.html
│       │       │       │   ├── xed-ild_8h-source.html
│       │       │       │   ├── xed-ild_8h.html
│       │       │       │   ├── xed-immdis_8h-source.html
│       │       │       │   ├── xed-immdis_8h.html
│       │       │       │   ├── xed-immed_8h-source.html
│       │       │       │   ├── xed-immed_8h.html
│       │       │       │   ├── xed-init-pointer-names_8h-source.html
│       │       │       │   ├── xed-init-pointer-names_8h.html
│       │       │       │   ├── xed-init_8h-source.html
│       │       │       │   ├── xed-init_8h.html
│       │       │       │   ├── xed-inst_8h-source.html
│       │       │       │   ├── xed-inst_8h.html
│       │       │       │   ├── xed-interface_8h-source.html
│       │       │       │   ├── xed-interface_8h.html
│       │       │       │   ├── xed-isa-set-enum_8h-source.html
│       │       │       │   ├── xed-isa-set-enum_8h.html
│       │       │       │   ├── xed-isa-set_8h-source.html
│       │       │       │   ├── xed-isa-set_8h.html
│       │       │       │   ├── xed-machine-mode-enum_8h-source.html
│       │       │       │   ├── xed-machine-mode-enum_8h.html
│       │       │       │   ├── xed-nonterminal-enum_8h-source.html
│       │       │       │   ├── xed-nonterminal-enum_8h.html
│       │       │       │   ├── xed-operand-accessors_8h-source.html
│       │       │       │   ├── xed-operand-accessors_8h.html
│       │       │       │   ├── xed-operand-action-enum_8h-source.html
│       │       │       │   ├── xed-operand-action-enum_8h.html
│       │       │       │   ├── xed-operand-action_8h-source.html
│       │       │       │   ├── xed-operand-action_8h.html
│       │       │       │   ├── xed-operand-convert-enum_8h-source.html
│       │       │       │   ├── xed-operand-convert-enum_8h.html
│       │       │       │   ├── xed-operand-ctype-enum_8h-source.html
│       │       │       │   ├── xed-operand-ctype-enum_8h.html
│       │       │       │   ├── xed-operand-ctype-map_8h-source.html
│       │       │       │   ├── xed-operand-ctype-map_8h.html
│       │       │       │   ├── xed-operand-element-type-enum_8h-source.html
│       │       │       │   ├── xed-operand-element-type-enum_8h.html
│       │       │       │   ├── xed-operand-element-xtype-enum_8h-source.html
│       │       │       │   ├── xed-operand-element-xtype-enum_8h.html
│       │       │       │   ├── xed-operand-enum_8h-source.html
│       │       │       │   ├── xed-operand-enum_8h.html
│       │       │       │   ├── xed-operand-storage_8h-source.html
│       │       │       │   ├── xed-operand-storage_8h.html
│       │       │       │   ├── xed-operand-type-enum_8h-source.html
│       │       │       │   ├── xed-operand-type-enum_8h.html
│       │       │       │   ├── xed-operand-values-interface_8h-source.html
│       │       │       │   ├── xed-operand-values-interface_8h.html
│       │       │       │   ├── xed-operand-visibility-enum_8h-source.html
│       │       │       │   ├── xed-operand-visibility-enum_8h.html
│       │       │       │   ├── xed-operand-width-enum_8h-source.html
│       │       │       │   ├── xed-operand-width-enum_8h.html
│       │       │       │   ├── xed-portability_8h-source.html
│       │       │       │   ├── xed-portability_8h.html
│       │       │       │   ├── xed-print-info_8h-source.html
│       │       │       │   ├── xed-print-info_8h.html
│       │       │       │   ├── xed-reg-class-enum_8h-source.html
│       │       │       │   ├── xed-reg-class-enum_8h.html
│       │       │       │   ├── xed-reg-class_8h-source.html
│       │       │       │   ├── xed-reg-class_8h.html
│       │       │       │   ├── xed-reg-enum_8h-source.html
│       │       │       │   ├── xed-reg-enum_8h.html
│       │       │       │   ├── xed-reg-role-enum_8h-source.html
│       │       │       │   ├── xed-reg-role-enum_8h.html
│       │       │       │   ├── xed-state_8h-source.html
│       │       │       │   ├── xed-state_8h.html
│       │       │       │   ├── xed-syntax-enum_8h-source.html
│       │       │       │   ├── xed-syntax-enum_8h.html
│       │       │       │   ├── xed-types_8h-source.html
│       │       │       │   ├── xed-types_8h.html
│       │       │       │   ├── xed-util_8h-source.html
│       │       │       │   ├── xed-util_8h.html
│       │       │       │   ├── xed-version_8h-source.html
│       │       │       │   └── xed-version_8h.html
│       │       │       └── xed.tag
│       │       ├── examples
│       │       │   ├── makefile
│       │       │   ├── udhelp.H
│       │       │   ├── udhelp.cpp
│       │       │   ├── xed-disas-elf.H
│       │       │   ├── xed-disas-elf.cpp
│       │       │   ├── xed-disas-hex.H
│       │       │   ├── xed-disas-hex.cpp
│       │       │   ├── xed-disas-macho.H
│       │       │   ├── xed-disas-macho.cpp
│       │       │   ├── xed-disas-pecoff.H
│       │       │   ├── xed-disas-pecoff.cpp
│       │       │   ├── xed-disas-raw.H
│       │       │   ├── xed-disas-raw.cpp
│       │       │   ├── xed-dll-discovery.c
│       │       │   ├── xed-dot-prep.c
│       │       │   ├── xed-dot-prep.h
│       │       │   ├── xed-dot.c
│       │       │   ├── xed-dot.h
│       │       │   ├── xed-enc-lang.H
│       │       │   ├── xed-enc-lang.cpp
│       │       │   ├── xed-ex-agen.c
│       │       │   ├── xed-ex-ild.c
│       │       │   ├── xed-ex-ild2.c
│       │       │   ├── xed-ex1.cpp
│       │       │   ├── xed-ex2.cpp
│       │       │   ├── xed-ex3.cpp
│       │       │   ├── xed-ex4.c
│       │       │   ├── xed-ex5-enc.c
│       │       │   ├── xed-ex6.c
│       │       │   ├── xed-ex7.c
│       │       │   ├── xed-ex8.c
│       │       │   ├── xed-examples-ostreams.H
│       │       │   ├── xed-examples-ostreams.cpp
│       │       │   ├── xed-examples-util.c
│       │       │   ├── xed-examples-util.h
│       │       │   ├── xed-min.c
│       │       │   ├── xed-size.c
│       │       │   ├── xed-symbol-table.H
│       │       │   ├── xed-symbol-table.cpp
│       │       │   ├── xed-tables.c
│       │       │   ├── xed-tester.cpp
│       │       │   └── xed.cpp
│       │       ├── extlib
│       │       │   ├── libc.so.6
│       │       │   ├── libgcc_s.so.1
│       │       │   ├── libm.so.6
│       │       │   └── libstdc++.so.6
│       │       ├── include
│       │       │   ├── xed-address-width-enum.h
│       │       │   ├── xed-agen.h
│       │       │   ├── xed-attribute-enum.h
│       │       │   ├── xed-attributes.h
│       │       │   ├── xed-build-defines.h
│       │       │   ├── xed-category-enum.h
│       │       │   ├── xed-chip-enum.h
│       │       │   ├── xed-common-defs.h
│       │       │   ├── xed-common-hdrs.h
│       │       │   ├── xed-convert-table-init.h
│       │       │   ├── xed-decode.h
│       │       │   ├── xed-decoded-inst-api.h
│       │       │   ├── xed-decoded-inst.h
│       │       │   ├── xed-disas.h
│       │       │   ├── xed-encode.h
│       │       │   ├── xed-encoder-gen-defs.h
│       │       │   ├── xed-encoder-hl.h
│       │       │   ├── xed-encoder-iforms.h
│       │       │   ├── xed-error-enum.h
│       │       │   ├── xed-exception-enum.h
│       │       │   ├── xed-extension-enum.h
│       │       │   ├── xed-flag-action-enum.h
│       │       │   ├── xed-flag-enum.h
│       │       │   ├── xed-flags.h
│       │       │   ├── xed-format-options.h
│       │       │   ├── xed-gen-table-defs.h
│       │       │   ├── xed-get-time.h
│       │       │   ├── xed-iclass-enum.h
│       │       │   ├── xed-iform-enum.h
│       │       │   ├── xed-iform-map.h
│       │       │   ├── xed-iformfl-enum.h
│       │       │   ├── xed-ild.h
│       │       │   ├── xed-immdis.h
│       │       │   ├── xed-immed.h
│       │       │   ├── xed-init-pointer-names.h
│       │       │   ├── xed-init.h
│       │       │   ├── xed-inst.h
│       │       │   ├── xed-interface.h
│       │       │   ├── xed-isa-set-enum.h
│       │       │   ├── xed-isa-set.h
│       │       │   ├── xed-machine-mode-enum.h
│       │       │   ├── xed-nonterminal-enum.h
│       │       │   ├── xed-operand-accessors.h
│       │       │   ├── xed-operand-action-enum.h
│       │       │   ├── xed-operand-action.h
│       │       │   ├── xed-operand-convert-enum.h
│       │       │   ├── xed-operand-ctype-enum.h
│       │       │   ├── xed-operand-ctype-map.h
│       │       │   ├── xed-operand-element-type-enum.h
│       │       │   ├── xed-operand-element-xtype-enum.h
│       │       │   ├── xed-operand-enum.h
│       │       │   ├── xed-operand-storage.h
│       │       │   ├── xed-operand-type-enum.h
│       │       │   ├── xed-operand-values-interface.h
│       │       │   ├── xed-operand-visibility-enum.h
│       │       │   ├── xed-operand-width-enum.h
│       │       │   ├── xed-portability.h
│       │       │   ├── xed-print-info.h
│       │       │   ├── xed-reg-class-enum.h
│       │       │   ├── xed-reg-class.h
│       │       │   ├── xed-reg-enum.h
│       │       │   ├── xed-reg-role-enum.h
│       │       │   ├── xed-state.h
│       │       │   ├── xed-syntax-enum.h
│       │       │   ├── xed-types.h
│       │       │   ├── xed-util.h
│       │       │   └── xed-version.h
│       │       ├── lib
│       │       │   ├── libxed-ild.a
│       │       │   └── libxed.a
│       │       ├── misc
│       │       │   └── idata.txt
│       │       └── redist.txt
│       ├── ia32
│       │   ├── bin
│       │   │   ├── pinbin
│       │   │   └── pindb
│       │   ├── lib
│       │   │   ├── libpin.a
│       │   │   ├── libpinapp.a
│       │   │   ├── libpinjitprofiling.so
│       │   │   ├── libpinvm.a
│       │   │   └── libsapin.a
│       │   ├── lib-ext
│       │   │   ├── EXTLICENSE
│       │   │   └── libpindwarf.a
│       │   └── runtime
│       │       ├── GPLv3.txt
│       │       ├── LGPL-2.1.txt
│       │       ├── LICENSE-RUNTIME
│       │       └── cpplibs
│       │           ├── libgcc_s.so
│       │           ├── libgcc_s.so.1
│       │           ├── libstdc++.so
│       │           ├── libstdc++.so.6
│       │           └── libstdc++.so.6.0.13
│       ├── intel64
│       │   ├── bin
│       │   │   ├── pinbin
│       │   │   └── pindb
│       │   ├── lib
│       │   │   ├── libpin.a
│       │   │   ├── libpinapp.a
│       │   │   ├── libpinjitprofiling.so
│       │   │   ├── libpinvm.a
│       │   │   └── libsapin.a
│       │   ├── lib-ext
│       │   │   ├── EXTLICENSE
│       │   │   └── libpindwarf.a
│       │   └── runtime
│       │       ├── GPLv3.txt
│       │       ├── LGPL-2.1.txt
│       │       ├── LICENSE-RUNTIME
│       │       └── cpplibs
│       │           ├── libgcc_s.so
│       │           ├── libgcc_s.so.1
│       │           ├── libstdc++.so
│       │           ├── libstdc++.so.6
│       │           └── libstdc++.so.6.0.13
│       ├── pin
│       ├── pin.sh
│       ├── redist.txt
│       └── source
│           ├── include
│           │   └── pin
│           │       ├── compiler_version_check2.H
│           │       ├── foundation.PLH
│           │       ├── gen
│           │       │   ├── base_ia32.PH
│           │       │   ├── bbl.PH
│           │       │   ├── cache_client.PH
│           │       │   ├── cc_used_ia32_l.CVH
│           │       │   ├── cc_used_ia32e_l.CVH
│           │       │   ├── child_process.PH
│           │       │   ├── child_process_client.PH
│           │       │   ├── client_asm_ia32.PH
│           │       │   ├── debug.PH
│           │       │   ├── debugger_client.PH
│           │       │   ├── deprecated_client.PH
│           │       │   ├── edg.PH
│           │       │   ├── exception.PH
│           │       │   ├── fpstate_ia32.PH
│           │       │   ├── fpstate_ia32e.PH
│           │       │   ├── image.PH
│           │       │   ├── image_elf.PH
│           │       │   ├── img.PH
│           │       │   ├── ins.PH
│           │       │   ├── ins_api_xed_ia32.PH
│           │       │   ├── ins_ia32.PH
│           │       │   ├── ins_syscall_ia32_unix.PH
│           │       │   ├── ins_xed_ia32.PH
│           │       │   ├── internal_exception_client.PH
│           │       │   ├── knob.PH
│           │       │   ├── lock.PH
│           │       │   ├── message.PH
│           │       │   ├── operand_ia32.PH
│           │       │   ├── opin_client.PH
│           │       │   ├── pin_api_version.TLH
│           │       │   ├── pin_client.PH
│           │       │   ├── pin_client_replay.PH
│           │       │   ├── pinsync-linux.hpp
│           │       │   ├── pinsync.hpp
│           │       │   ├── probe_instrument.PH
│           │       │   ├── probe_instrument_ia32.PH
│           │       │   ├── reg_ia32.PH
│           │       │   ├── reg_partial_ia32.PH
│           │       │   ├── reginfo_ia32.PH
│           │       │   ├── regset.PH
│           │       │   ├── regset_ia32.PH
│           │       │   ├── sec.PH
│           │       │   ├── stopped_thread_client.PH
│           │       │   ├── symbol_elf.PH
│           │       │   ├── sysfuncs_linux.PH
│           │       │   ├── thread_client.PH
│           │       │   ├── tls.PH
│           │       │   ├── tls_client.PH
│           │       │   ├── types_base.TLH
│           │       │   ├── types_core.TLH
│           │       │   ├── types_foundation.TLH
│           │       │   ├── types_marker.TLH
│           │       │   ├── types_vmapi.TLH
│           │       │   ├── util.PH
│           │       │   ├── val.PH
│           │       │   └── versions_client.PH
│           │       ├── level_base.PLH
│           │       ├── level_core.PLH
│           │       ├── level_foundation.PLH
│           │       ├── level_pinclient.PLH
│           │       ├── level_vmapi.PLH
│           │       ├── pin-errtype.h
│           │       ├── pin.H
│           │       ├── pin_basic.h
│           │       ├── pin_cache.H
│           │       ├── pin_isa.H
│           │       ├── pin_profile.H
│           │       ├── pin_ucontext.h
│           │       ├── pin_util.H
│           │       ├── pinapp.h
│           │       ├── pintool.exp
│           │       ├── pintool.ver
│           │       └── portability.H
│           ├── launcher
│           │   ├── launcher_u.c
│           │   ├── os_specific.h
│           │   ├── os_specific_a.c
│           │   ├── os_specific_b.c
│           │   ├── os_specific_l.c
│           │   ├── os_specific_m.c
│           │   ├── os_specific_mic.c
│           │   ├── utils.c
│           │   └── utils.h
│           └── tools
│               ├── AlignChk
│               │   ├── alignchk.H
│               │   ├── alignchk.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── misaligned.c
│               │   ├── movdqa_test2.cpp
│               │   ├── movdqa_test2_ia32.s
│               │   ├── movdqa_test_ia32.asm
│               │   └── movdqa_test_intel64.asm
│               ├── AttachDetach
│               │   ├── attachReattachThreadDetachCallbacks_app.cpp
│               │   ├── attach_auxv_access.cpp
│               │   ├── attach_auxv_access.reference
│               │   ├── attach_auxv_access_app.cpp
│               │   ├── attach_in_sighandler_app.cpp
│               │   ├── change_mask.cpp
│               │   ├── change_mask_app.cpp
│               │   ├── detach_in_sighandler_app.cpp
│               │   ├── detach_on_blocking_syscall.c
│               │   ├── detach_probed_app.cpp
│               │   ├── detach_probed_tool.cpp
│               │   ├── detach_probed_wait_child_app.cpp
│               │   ├── detach_syscall.cpp
│               │   ├── detach_syscall_app.cpp
│               │   ├── fp_save_restore_ia32.s
│               │   ├── fp_save_restore_intel64.s
│               │   ├── hello_world.cpp
│               │   ├── jit_anls_detach.cpp
│               │   ├── jit_detach_tool.cpp
│               │   ├── jit_instr_detach.cpp
│               │   ├── jit_tool.cpp
│               │   ├── launchReattachThreadDetachCallbacks_app.cpp
│               │   ├── main_attach_app.cpp
│               │   ├── main_command_line_app.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mt_attach.cpp
│               │   ├── mt_attach_and_execv.cpp
│               │   ├── mt_attach_android.cpp
│               │   ├── mt_blocked.cpp
│               │   ├── mt_detach.cpp
│               │   ├── mt_fork_app.cpp
│               │   ├── mt_thread.cpp
│               │   ├── my_dll.c
│               │   ├── my_exe.c
│               │   ├── pause_msg_app.cpp
│               │   ├── probe_tool.cpp
│               │   ├── read_write_app.cpp
│               │   ├── reattachThreadDetachCallbacks_tool.cpp
│               │   ├── reattachZombie_tool.cpp
│               │   ├── reattach_probed_app.cpp
│               │   ├── reattach_probed_tool.cpp
│               │   ├── reattach_verify_sigmask_app.cpp
│               │   ├── run_many
│               │   ├── secondary_attach_app.cpp
│               │   ├── secondary_command_line_app.cpp
│               │   ├── send_signals.sh
│               │   ├── send_signals_android.sh
│               │   ├── short_func_app.cpp
│               │   ├── short_func_ia32.s
│               │   ├── short_func_intel64.s
│               │   ├── short_func_mic.s
│               │   ├── short_func_tool.cpp
│               │   ├── simple_tool.cpp
│               │   ├── threadOrder.cpp
│               │   ├── threadOrder_tool.cpp
│               │   ├── tls_app_ia32.cpp
│               │   ├── tls_app_intel64.cpp
│               │   ├── tls_app_mic.cpp
│               │   ├── tls_check_tool.cpp
│               │   ├── verify_fpstate_app.cpp
│               │   ├── verify_sigmask.cpp
│               │   ├── verify_sigmask_android.cpp
│               │   ├── w_app1.cpp
│               │   ├── w_app2.cpp
│               │   ├── w_app3.cpp
│               │   ├── w_app4.cpp
│               │   ├── w_app_launcher.cpp
│               │   ├── w_attach_tool1.cpp
│               │   ├── w_attach_tool2.cpp
│               │   ├── w_attach_tool3.cpp
│               │   ├── w_attach_tool4.cpp
│               │   ├── w_attach_tool5.cpp
│               │   ├── w_pin_service_launcher.cpp
│               │   ├── w_service_app1.cpp
│               │   ├── zombie_utils.cpp
│               │   └── zombie_utils.h
│               ├── Buffer
│               │   ├── allocate.cpp
│               │   ├── buffer-lengths.cpp
│               │   ├── buffer-predicate.cpp
│               │   ├── buffer-then.cpp
│               │   ├── buffer_invalid_reg.cpp
│               │   ├── bufferaddr.cpp
│               │   ├── buffererror.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mlog_buffer.cpp
│               │   └── two_buffers.cpp
│               ├── CacheClient
│               │   ├── action_pending_cachefull.cpp
│               │   ├── action_pending_cachefull_app.c
│               │   ├── bb_test.cpp
│               │   ├── bigBinary.c
│               │   ├── bigRegion.c
│               │   ├── br_test.cpp
│               │   ├── cache_doubler.cpp
│               │   ├── cache_flusher.cpp
│               │   ├── cache_simulator.cpp
│               │   ├── cache_stats.cpp
│               │   ├── callFooTwice.c
│               │   ├── code_cache_gui.py
│               │   ├── codecache_stress.cpp
│               │   ├── codecache_stress_app.cpp
│               │   ├── codecache_stress_app_asm_ia32.asm
│               │   ├── codecache_stress_app_asm_ia32.s
│               │   ├── codecache_stress_app_asm_intel64.asm
│               │   ├── codecache_stress_app_asm_intel64.s
│               │   ├── codecache_stress_app_asm_mic.asm
│               │   ├── codecache_stress_app_asm_mic.s
│               │   ├── deleteTrace.cpp
│               │   ├── enter_exit.cpp
│               │   ├── event_trace.cpp
│               │   ├── flushAndInsert.cpp
│               │   ├── flush_at_if.cpp
│               │   ├── flush_leaks.cpp
│               │   ├── insertDelete.cpp
│               │   ├── invalidate_cache_analysis.cpp
│               │   ├── link_unlink.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── manyIndirects.c
│               │   ├── mem_usage.cpp
│               │   ├── mtFlush.cpp
│               │   ├── orig_address.cpp
│               │   ├── threadWait.c
│               │   ├── trace_insertions.cpp
│               │   ├── utils.H
│               │   ├── utils.cpp
│               │   └── watch_fragmentation.cpp
│               ├── ChildProcess
│               │   ├── 1.sh
│               │   ├── 2.sh
│               │   ├── arglist.cpp
│               │   ├── arglist.h
│               │   ├── badexec.c
│               │   ├── bind_now_app.c
│               │   ├── bind_now_tool.cpp
│               │   ├── child_process.cpp
│               │   ├── execvp.c
│               │   ├── follow_child.cpp
│               │   ├── follow_child_3gen_tool.cpp
│               │   ├── follow_child_3gen_tool_initsym.cpp
│               │   ├── follow_child_tool.cpp
│               │   ├── fork_app.c
│               │   ├── fork_jit_tool.cpp
│               │   ├── fork_probed_tool.cpp
│               │   ├── fork_vm_lock_app.cpp
│               │   ├── fork_vm_lock_tool.cpp
│               │   ├── grand_parent_tool.cpp
│               │   ├── injection_test_app.c
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── null_arg_check_tool.cpp
│               │   ├── null_check_app1.cpp
│               │   ├── null_check_app2.cpp
│               │   ├── parent_process.cpp
│               │   ├── parent_process_launcher.sh
│               │   ├── parent_tool.cpp
│               │   ├── selfexec_app.c
│               │   ├── sigchld_app.cpp
│               │   ├── sigchld_app.reference
│               │   ├── simple_tool.cpp
│               │   ├── uname_script.sh
│               │   ├── unix_parent_tool.cpp
│               │   ├── vfork_app.c
│               │   ├── win_child_process.cpp
│               │   ├── win_early_termination.cpp
│               │   ├── win_launcher_debugged_process.cpp
│               │   ├── win_launcher_process.cpp
│               │   ├── win_parent_process.cpp
│               │   ├── win_parent_process1.reference
│               │   ├── win_parent_process1_probed.reference
│               │   ├── win_parent_process1_unicode_probed.reference
│               │   ├── win_parent_process1_unicode_probed_withsym.reference
│               │   ├── win_parent_process2.reference
│               │   ├── win_parent_process2_jjj.reference
│               │   ├── win_parent_process2_jjp.reference
│               │   ├── win_parent_process2_jpj.reference
│               │   ├── win_parent_process2_jpp.reference
│               │   ├── win_parent_process2_mt_ppp.reference
│               │   ├── win_parent_process2_pjj.reference
│               │   ├── win_parent_process2_pjp.reference
│               │   ├── win_parent_process2_ppj.reference
│               │   ├── win_parent_process2_ppp.reference
│               │   ├── win_parent_process2_unicode_ppp.reference
│               │   ├── win_parent_process_launcher.bat
│               │   ├── win_parent_process_mt.cpp
│               │   ├── win_parent_process_mt_launcher.bat
│               │   ├── win_parent_process_mt_test_launcher.bat
│               │   ├── win_parent_process_mt_test_launcher_w_pintool_args.bat
│               │   ├── win_parent_process_test_launcher.bat
│               │   ├── win_parent_process_test_launcher_w_pintool_args.bat
│               │   ├── win_parent_process_unicode.cpp
│               │   ├── win_parent_process_unicode_launcher.bat
│               │   └── win_terminate_process_dll.cpp
│               ├── Config
│               │   ├── makefile.config
│               │   ├── makefile.debug.rules
│               │   ├── makefile.default.rules
│               │   ├── makefile.rules.tmpl
│               │   ├── makefile.tmpl
│               │   ├── makefile.unix.config
│               │   └── unix.vars
│               ├── Cpp11Tests
│               │   ├── cpp11Threads.cpp
│               │   ├── cpp11ThreadsApp.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── CrossIa32Intel64
│               │   ├── child_process_injection.cpp
│               │   ├── child_process_injection_app.c
│               │   ├── child_process_injection_app1.c
│               │   ├── child_process_linux.cpp
│               │   ├── child_process_windows.cpp
│               │   ├── compiler-env.bat
│               │   ├── early_termination.cpp
│               │   ├── follow_child_tool.cpp
│               │   ├── follow_child_tool_sym.cpp
│               │   ├── follow_child_tool_windows.cpp
│               │   ├── grand_child_process_linux.cpp
│               │   ├── grand_child_process_windows.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── parent_process_linux.cpp
│               │   ├── parent_process_windows.cpp
│               │   ├── parent_tool.cpp
│               │   ├── sigchld_app.cpp
│               │   ├── sigchld_app.reference
│               │   ├── w_terminate_process_dll.cpp
│               │   ├── win_launcher_debugged_process.cpp
│               │   └── win_launcher_process.cpp
│               ├── DebugInfo
│               │   ├── debugtest.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   └── omit_source_location.cpp
│               ├── DebugTrace
│               │   ├── debugtrace.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── Debugger
│               │   ├── access-64-on-32.compare
│               │   ├── access-64-on-32.pindb
│               │   ├── action-pending-app.cpp
│               │   ├── action-pending-tool.cpp
│               │   ├── action-pending.compare
│               │   ├── action-pending.gdb
│               │   ├── app-pause-app.cpp
│               │   ├── app-pause-in-app-thread-tool.cpp
│               │   ├── app-pause-in-int-thread-tool.cpp
│               │   ├── bp-icount.compare
│               │   ├── bp-icount.gdb
│               │   ├── bphandler.compare
│               │   ├── bphandler.cpp
│               │   ├── bphandler.gdb
│               │   ├── bphandler_app.c
│               │   ├── bptest-asm-ia32.s
│               │   ├── bptest-asm-intel64.s
│               │   ├── bptest-ia32.compare
│               │   ├── bptest-ia32.compareICC
│               │   ├── bptest-ia32.gdb
│               │   ├── bptest-intel64.compare
│               │   ├── bptest-intel64.compareICC
│               │   ├── bptest-intel64.gdb
│               │   ├── bptest.cpp
│               │   ├── breaktool-wait.compare
│               │   ├── breaktool-wait.gdb
│               │   ├── breaktool.compare
│               │   ├── breaktool.cpp
│               │   ├── breaktool.gdb
│               │   ├── breaktool_const_context.compare
│               │   ├── breaktool_const_context.gdb
│               │   ├── callerapp.c
│               │   ├── check-if-thread-stopped.compare
│               │   ├── check-if-thread-stopped.cpp
│               │   ├── check-if-thread-stopped.pindb
│               │   ├── checkpoint-app.c
│               │   ├── checkpoint-app.compare
│               │   ├── checkpoint-gdb.compare
│               │   ├── checkpoint.cpp
│               │   ├── checkpoint.gdb
│               │   ├── debugger-shell-app-ia32.s
│               │   ├── debugger-shell-app-intel64.s
│               │   ├── debugger-shell-app.cpp
│               │   ├── debugger-type.cpp
│               │   ├── debugger-type.gdb
│               │   ├── dlopen-dlclose.c
│               │   ├── exec.cpp
│               │   ├── execfail.compare
│               │   ├── execfail.gdb
│               │   ├── fork.compare
│               │   ├── fork.cpp
│               │   ├── fork.gdb
│               │   ├── gdb-detach-reattach-1.gdb
│               │   ├── gdb-detach-reattach-2.gdb
│               │   ├── gdb-detach-reattach-app.compare
│               │   ├── gdb-detach-reattach-fixed-port-1.gdb
│               │   ├── gdb-detach-reattach-fixed-port-2.gdb
│               │   ├── gdb-detach-reattach-fixed-port-app.compare
│               │   ├── gdb-detach-reattach-fixed-port-gdb-1.compare
│               │   ├── gdb-detach-reattach-fixed-port-gdb-2.compare
│               │   ├── gdb-detach-reattach-gdb-1.compare
│               │   ├── gdb-detach-reattach-gdb-2.compare
│               │   ├── gdb-fixed-port.compare
│               │   ├── gdb-fixed-port.gdb
│               │   ├── gdb-pthread-step-exit.compare
│               │   ├── gdb-pthread-step-exit.gdb
│               │   ├── gdb-svr4-libraries-extension.compare
│               │   ├── gdb-svr4-libraries-extension.gdb
│               │   ├── int3-count.cpp
│               │   ├── intercept-app-asm-ia32.s
│               │   ├── intercept-app-asm-intel64.s
│               │   ├── intercept-app.cpp
│               │   ├── intercept-breakpoint-app.compare
│               │   ├── intercept-breakpoint-gdb.compare
│               │   ├── intercept-breakpoint.gdb
│               │   ├── intercept-tool.cpp
│               │   ├── interpreter-remove.cpp
│               │   ├── invalid-write.compare
│               │   ├── invalid-write.gdb
│               │   ├── invalidate-regs.cpp
│               │   ├── launch-gdb-tool.cpp
│               │   ├── launch-gdb.compare
│               │   ├── launch-gdb.gdb
│               │   ├── launch-gdb_const_context.compare
│               │   ├── launch-gdb_const_context.gdb
│               │   ├── launch-pin-attach-debugger.py
│               │   ├── library-load-tool.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── memlog.hpp
│               │   ├── mt-exit-tool.cpp
│               │   ├── mt-exit.cpp
│               │   ├── mt-exit.gdb
│               │   ├── null-emulator-ia32.cpp
│               │   ├── null-emulator-intel64.cpp
│               │   ├── pc-change-async-asm-ia32.s
│               │   ├── pc-change-async-asm-intel64.s
│               │   ├── pc-change-async-tool.cpp
│               │   ├── pc-change-async.compare
│               │   ├── pc-change-async.cpp
│               │   ├── pc-change-async.gdb
│               │   ├── pc-change-bp-asm-ia32.s
│               │   ├── pc-change-bp-asm-intel64.s
│               │   ├── pc-change-bp.compare
│               │   ├── pc-change-bp.cpp
│               │   ├── pc-change-bp.gdb
│               │   ├── pick-random-port.c
│               │   ├── pindb-abrupt-disconnect.pindb
│               │   ├── pindb-async-stop.pindb
│               │   ├── pindb-attach-after-custom-stop.compare
│               │   ├── pindb-attach-after-custom-stop.pindbin
│               │   ├── pindb-invalidate-regs.compare
│               │   ├── pindb-invalidate-regs.pindb
│               │   ├── pindb-kill-like-gdb.pindb
│               │   ├── pindb-noprompt-kill.pindb
│               │   ├── pindb-pthread-cont-exitgroup.compare
│               │   ├── pindb-pthread-cont-exitgroup.pindb
│               │   ├── pindb-pthread-step-exit.compare
│               │   ├── pindb-pthread-step-exit.pindb
│               │   ├── pindb-pthread-step-exitgroup.pindb
│               │   ├── pindb-simple-command.pindb
│               │   ├── pindb-simple-simultaneous-multi-serialize.compare1
│               │   ├── pindb-simple-simultaneous-multi-serialize.compare2
│               │   ├── pindb-simple-simultaneous-multi-serialize.pindb
│               │   ├── pindb-simple-simultaneous-multi.compare1
│               │   ├── pindb-simple-simultaneous-multi.compare2
│               │   ├── pindb-simple-simultaneous-multi.pindb
│               │   ├── pindb-simultaneous-multi-serialize.compare1
│               │   ├── pindb-simultaneous-multi-serialize.compare2
│               │   ├── pindb-simultaneous-multi-serialize.compare3
│               │   ├── pindb-simultaneous-multi-serialize.compare4
│               │   ├── pindb-simultaneous-multi-serialize.pindb
│               │   ├── pindb-simultaneous-multi.compare1
│               │   ├── pindb-simultaneous-multi.compare2
│               │   ├── pindb-simultaneous-multi.compare3
│               │   ├── pindb-simultaneous-multi.compare4
│               │   ├── pindb-simultaneous-multi.pindb
│               │   ├── pindb-simultaneous-toolbreak-attach.compare
│               │   ├── pindb-simultaneous-toolbreak-attach.pindbin
│               │   ├── pindb-simultaneous-toolbreak-change.compare
│               │   ├── pindb-simultaneous-toolbreak-change.pindb
│               │   ├── pindb-simultaneous-toolbreak-serialize.compare
│               │   ├── pindb-simultaneous-toolbreak-serialize.pindb
│               │   ├── pindb-simultaneous-toolbreak-squash.compare
│               │   ├── pindb-simultaneous-toolbreak-squash.pindb
│               │   ├── pindb-simultaneous-toolbreak-step.compare
│               │   ├── pindb-simultaneous-toolbreak-step.pindb
│               │   ├── pindb-simultaneous-toolbreak.compare
│               │   ├── pindb-simultaneous-toolbreak.pindb
│               │   ├── pindb-start-fini.pindb
│               │   ├── pindb-win-continued-exception1.compare
│               │   ├── pindb-win-continued-exception1.pindb
│               │   ├── pindb-win-continued-exception2.compare
│               │   ├── pindb-win-continued-exception2.pindb
│               │   ├── pindb-win-cpp-exception.compare
│               │   ├── pindb-win-cpp-exception.pindb
│               │   ├── pindb-win-handled-exception.compare
│               │   ├── pindb-win-handled-exception.pindb
│               │   ├── pindb-win-library-notifications.compare
│               │   ├── pindb-win-library-notifications.pindb
│               │   ├── pindb-win-software-exception.compare
│               │   ├── pindb-win-software-exception.pindb
│               │   ├── pindb-win-squash-exception.compare
│               │   ├── pindb-win-squash-exception.pindb
│               │   ├── pindb-win-step-exception.compare
│               │   ├── pindb-win-step-exception.pindb
│               │   ├── pindb-win-step-library.compare
│               │   ├── pindb-win-step-library.pindb
│               │   ├── pindb-win-thread-stress.compare
│               │   ├── pindb-win-thread-stress.pindb
│               │   ├── pindb-win-unhandled-exception.compare
│               │   ├── pindb-win-unhandled-exception.pindb
│               │   ├── pthread-bare-exit-asm-ia32.s
│               │   ├── pthread-bare-exit-asm-intel64.s
│               │   ├── pthread-bare-exit.cpp
│               │   ├── pthread-bare-exitgroup-asm-ia32.s
│               │   ├── pthread-bare-exitgroup-asm-intel64.s
│               │   ├── pthread-bare-exitgroup.cpp
│               │   ├── quit.gdb
│               │   ├── reattach-loop.cpp
│               │   ├── set-mode-tool.cpp
│               │   ├── set_xmm_scratches.cpp
│               │   ├── set_xmm_scratches_before_breakpoint.cpp
│               │   ├── set_xmm_scratches_before_breakpoint_and_set_xmm_reg.cpp
│               │   ├── set_xmm_scratches_for_ymmtest.cpp
│               │   ├── set_xmm_scratches_ia32.s
│               │   ├── set_xmm_scratches_intel64.s
│               │   ├── siginfo.compare
│               │   ├── siginfo.gdb
│               │   ├── signal-catch.cpp
│               │   ├── signal-step.compare
│               │   ├── signal-step.gdb
│               │   ├── simple-command-tool.cpp
│               │   ├── simple-pindb-asm-linux-ia32.s
│               │   ├── simple-pindb-asm-linux-intel64.s
│               │   ├── simple-pindb-asm-windows-ia32.asm
│               │   ├── simple-pindb-asm-windows-intel64.asm
│               │   ├── simple-pindb.cpp
│               │   ├── simple.c
│               │   ├── simple.compare
│               │   ├── simple.gdb
│               │   ├── simultaneous-toolbreak-attach.compare
│               │   ├── simultaneous-toolbreak-attach.gdb
│               │   ├── simultaneous-toolbreak-change.compare
│               │   ├── simultaneous-toolbreak-change.gdb
│               │   ├── simultaneous-toolbreak-squash.compare
│               │   ├── simultaneous-toolbreak-squash.gdb
│               │   ├── simultaneous-toolbreak.compare
│               │   ├── simultaneous-toolbreak.cpp
│               │   ├── simultaneous-toolbreak.gdb
│               │   ├── simultaneous-toolbreak_const_context.compare
│               │   ├── simultaneous-toolbreak_const_context.gdb
│               │   ├── sleep-unix.c
│               │   ├── stack-debugger-late.compare
│               │   ├── stack-debugger-late.gdb
│               │   ├── stack-debugger.compare
│               │   ├── stack-debugger.gdb
│               │   ├── start-fini-callback.cpp
│               │   ├── start-fini.reference
│               │   ├── stop-resume-when-suspended.cpp
│               │   ├── stop-resume-when-suspended.pindb
│               │   ├── stop-resume-when-suspended.reference
│               │   ├── thread-unix.cpp
│               │   ├── thread-win.cpp
│               │   ├── thread.compare
│               │   ├── thread.cpp
│               │   ├── thread.gdb
│               │   ├── use-debugger-shell.cpp
│               │   ├── watchpoint-app.c
│               │   ├── watchpoint.compare
│               │   ├── watchpoint.cpp
│               │   ├── watchpoint_const_context.compare
│               │   ├── win-continued-exception1.cpp
│               │   ├── win-continued-exception2.cpp
│               │   ├── win-cpp-exception.cpp
│               │   ├── win-foo-library.cpp
│               │   ├── win-handled-exception.cpp
│               │   ├── win-load-library.cpp
│               │   ├── win-software-exception.cpp
│               │   ├── win-thread-stress.cpp
│               │   ├── win-unhandled-exception.cpp
│               │   ├── xmm-asm-ia32.s
│               │   ├── xmm-asm-intel64.s
│               │   ├── xmm-ia32.compare
│               │   ├── xmm-ia32.gdb
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_before_breakpoint_tool.compare
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_before_breakpoint_tool.gdb
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_before_breakpoint_tool_and_set_xmm_reg.gdb
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_before_breakpoint_tool_const_context.gdb
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_tool.compare
│               │   ├── xmm-ia32_with_set_xmm_scratch_regs_tool.gdb
│               │   ├── xmm-intel64.compare
│               │   ├── xmm-intel64.gdb
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_before_breakpoint_tool.compare
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_before_breakpoint_tool.gdb
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_before_breakpoint_tool_and_set_xmm_reg.gdb
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_before_breakpoint_tool_const_context.compare
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_before_breakpoint_tool_const_context.gdb
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_tool.compare
│               │   ├── xmm-intel64_with_set_xmm_scratch_regs_tool.gdb
│               │   ├── xmm.c
│               │   ├── ymm-asm-ia32.s
│               │   ├── ymm-asm-intel64.s
│               │   ├── ymm.compare
│               │   ├── ymm.cpp
│               │   ├── ymm.gdb
│               │   ├── ymm_with_set_xmm_scratch_regs_tool.compare
│               │   └── ymm_with_set_xmm_scratch_regs_tool.gdb
│               ├── GracefulExit
│               │   ├── applicationexit.cpp
│               │   ├── applicationexit.master
│               │   ├── exitApplicationLocked_app.cpp
│               │   ├── exitApplicationLocked_tool.cpp
│               │   ├── exitFromFini_app.cpp
│               │   ├── exitFromFini_tool.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── raceToEnterVm_app.cpp
│               │   ├── raceToExit_app.cpp
│               │   ├── threadFini_app.cpp
│               │   ├── threadFini_exception_app.cpp
│               │   ├── threadFini_sendsig.cpp
│               │   ├── threadFini_sig_app.cpp
│               │   ├── threadFini_tool.cpp
│               │   ├── threadUtils.h
│               │   ├── threadUtils_android.cpp
│               │   ├── threadUtils_linux.cpp
│               │   └── threadUtils_windows.cpp
│               ├── I18N
│               │   ├── i18n_tool.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── unix_i18n_tool.reference
│               │   ├── unix_unicode.cpp
│               │   ├── unix_unicode.reference
│               │   ├── unix_unicode_test_launcher.cpp
│               │   ├── win_i18n_tool.reference
│               │   ├── win_unicode.cpp
│               │   ├── win_unicode.reference
│               │   ├── win_unicode_ia32.exe
│               │   ├── win_unicode_ia32.pdb
│               │   ├── win_unicode_intel64.exe
│               │   ├── win_unicode_intel64.pdb
│               │   └── win_unicode_test_launcher.cpp
│               ├── IArg
│               │   ├── iarg_explicit_memory_ea.cpp
│               │   ├── iarg_explicit_memory_ea_app.cpp
│               │   ├── iarg_explicit_memory_ea_app_asm_ia32.asm
│               │   ├── iarg_explicit_memory_ea_app_asm_intel64.asm
│               │   ├── iarg_inst_ptr_error_msg.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── ImageTests
│               │   ├── attachReattachImageLoadCallbacks_app.cpp
│               │   ├── badmunmap_app.cpp
│               │   ├── badmunmap_tool.cpp
│               │   ├── dummy_dll.c
│               │   ├── full_path_app.cpp
│               │   ├── full_path_tool.cpp
│               │   ├── imageLoad_tool.cpp
│               │   ├── imageUnload_app.c
│               │   ├── imageUnload_tool.cpp
│               │   ├── image_load.cpp
│               │   ├── images_on_attach_app.cpp
│               │   ├── images_on_attach_tool.cpp
│               │   ├── img_find_by_addr.cpp
│               │   ├── img_open_win.cpp
│               │   ├── l_imageLoad_app.cpp
│               │   ├── launchReattachImageLoadCallbacks_app.cpp
│               │   ├── load_dummy_dll.c
│               │   ├── load_dummy_dll_tool.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── my_dll.c
│               │   ├── one.c
│               │   ├── reattachImageLoadCallback_tool.cpp
│               │   ├── rebase_dll.c
│               │   ├── rebase_dll_tool.cpp
│               │   ├── region_compare.py
│               │   ├── split_image.cpp
│               │   ├── split_image_app.cpp
│               │   ├── two.c
│               │   ├── w_app_launcher.cpp
│               │   ├── w_imageLoad_app.cpp
│               │   ├── win_load_ntdll.c
│               │   └── x86dll_app.cpp
│               ├── InlinedFuncsOpt
│               │   ├── inlined_funcs_ia32.asm
│               │   ├── inlined_funcs_intel64.asm
│               │   ├── inlined_funcs_opt.cpp
│               │   ├── inscount.out
│               │   ├── inscount_for_lea_opt.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   └── update_icount_intel64.asm
│               ├── Insmix
│               │   ├── insmix.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── InstLib
│               │   ├── alarm_manager.H
│               │   ├── alarm_manager.cpp
│               │   ├── alarms.H
│               │   ├── alarms.cpp
│               │   ├── asm_macros.h
│               │   ├── asm_macros.inc
│               │   ├── call-stack.H
│               │   ├── call-stack.cpp
│               │   ├── cntrl_client.py
│               │   ├── control_chain.H
│               │   ├── control_chain.cpp
│               │   ├── control_manager.H
│               │   ├── control_manager.cpp
│               │   ├── controller_events.H
│               │   ├── controller_events.cpp
│               │   ├── debugger-shell.H
│               │   ├── debugger-shell.cpp
│               │   ├── filter.H
│               │   ├── follow_child.H
│               │   ├── ialarm.H
│               │   ├── ialarm.cpp
│               │   ├── icount.H
│               │   ├── init_alarm.H
│               │   ├── init_alarm.cpp
│               │   ├── instlib.H
│               │   ├── interactive_listener.H
│               │   ├── interactive_listener.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── parse_control.H
│               │   ├── parse_control.cpp
│               │   ├── regions_control.H
│               │   ├── skipper.H
│               │   └── time_warp.H
│               ├── InstLibExamples
│               │   ├── control.cpp
│               │   ├── control_detach.cpp
│               │   ├── filter.cpp
│               │   ├── filter_app.c
│               │   ├── follow_child.cpp
│               │   ├── icount.cpp
│               │   ├── int3-test.c
│               │   ├── itext-marker-test.c
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── multi-start-stop-test.c
│               │   ├── one.c
│               │   └── test-mt3.cpp
│               ├── InstructionTests
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── pushpopcall_riprelative.s
│               │   └── rewritememop1.cpp
│               ├── InstrumentationOrderAndVersion
│               │   ├── callbacks_order.cpp
│               │   ├── callbacks_order.reference
│               │   ├── instrumentation_order.cpp
│               │   ├── instrumentation_order.ref
│               │   ├── instrumentation_order1.cpp
│               │   ├── instrumentation_order1.ref
│               │   ├── instrumentation_order10.cpp
│               │   ├── instrumentation_order10.ref
│               │   ├── instrumentation_order11.cpp
│               │   ├── instrumentation_order11.ref
│               │   ├── instrumentation_order12.cpp
│               │   ├── instrumentation_order12.ref
│               │   ├── instrumentation_order13.cpp
│               │   ├── instrumentation_order13.ref
│               │   ├── instrumentation_order14.cpp
│               │   ├── instrumentation_order15.cpp
│               │   ├── instrumentation_order15.ref
│               │   ├── instrumentation_order16.cpp
│               │   ├── instrumentation_order16.ref
│               │   ├── instrumentation_order17.cpp
│               │   ├── instrumentation_order17.ref
│               │   ├── instrumentation_order18.cpp
│               │   ├── instrumentation_order18.ref
│               │   ├── instrumentation_order19.cpp
│               │   ├── instrumentation_order19.ref
│               │   ├── instrumentation_order2.cpp
│               │   ├── instrumentation_order2.ref
│               │   ├── instrumentation_order20.cpp
│               │   ├── instrumentation_order21.cpp
│               │   ├── instrumentation_order22.cpp
│               │   ├── instrumentation_order23.cpp
│               │   ├── instrumentation_order3.cpp
│               │   ├── instrumentation_order3.ref
│               │   ├── instrumentation_order4.cpp
│               │   ├── instrumentation_order4.ref
│               │   ├── instrumentation_order5.cpp
│               │   ├── instrumentation_order5.ref
│               │   ├── instrumentation_order6.cpp
│               │   ├── instrumentation_order6.ref
│               │   ├── instrumentation_order7.cpp
│               │   ├── instrumentation_order7.ref
│               │   ├── instrumentation_order8.cpp
│               │   ├── instrumentation_order8.ref
│               │   ├── instrumentation_order9.cpp
│               │   ├── instrumentation_order9.ref
│               │   ├── instrumentation_order_app.cpp
│               │   ├── instrumentation_order_app.h
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── redblue.cpp
│               │   ├── redblue.s
│               │   ├── redblue_ia32.asm
│               │   ├── redblue_intel64.asm
│               │   ├── special.cpp
│               │   ├── special.ref
│               │   ├── special_case.cpp
│               │   ├── special_case.ref
│               │   ├── special_case1.cpp
│               │   ├── special_case1.ref
│               │   ├── special_case2.cpp
│               │   ├── special_case3.cpp
│               │   ├── special_case_aoti.cpp
│               │   ├── special_case_aoti.ref
│               │   ├── special_case_aoti1.cpp
│               │   ├── special_case_aoti1.ref
│               │   └── special_case_app.cpp
│               ├── JitProfilingApiTests
│               │   ├── DynamicFuncInstrument.cpp
│               │   ├── DynamicInsCount.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── MacTests
│               │   ├── bundle_app.c
│               │   ├── bundle_bundle.c
│               │   ├── bundle_tool.cpp
│               │   ├── libdep.c
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mylib.c
│               │   ├── section_app.c
│               │   ├── section_tool.cpp
│               │   ├── thcnt.cpp
│               │   └── wqtimer.c
│               ├── Maid
│               │   ├── CallStack.H
│               │   ├── CallStack.cpp
│               │   ├── Maid.cpp
│               │   ├── README
│               │   ├── addrfile.txt
│               │   ├── argv_readparam.cpp
│               │   ├── argv_readparam.h
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── syscall_names.H
│               │   └── syscall_names.cpp
│               ├── ManualExamples
│               │   ├── buffer_linux.cpp
│               │   ├── buffer_windows.cpp
│               │   ├── countreps.cpp
│               │   ├── detach.cpp
│               │   ├── divide_by_zero_linux.c
│               │   ├── divide_by_zero_windows.c
│               │   ├── emudiv.cpp
│               │   ├── fibonacci.cpp
│               │   ├── follow_child_app1.cpp
│               │   ├── follow_child_app2.cpp
│               │   ├── follow_child_tool.cpp
│               │   ├── fork_app.cpp
│               │   ├── fork_jit_tool.cpp
│               │   ├── imageload.cpp
│               │   ├── inscount0.cpp
│               │   ├── inscount1.cpp
│               │   ├── inscount2.cpp
│               │   ├── inscount_tls.cpp
│               │   ├── invocation.cpp
│               │   ├── isampling.cpp
│               │   ├── itrace.cpp
│               │   ├── little_malloc.c
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── malloc_mt.cpp
│               │   ├── malloctrace.cpp
│               │   ├── nonstatica.cpp
│               │   ├── pinatrace.cpp
│               │   ├── proccount.cpp
│               │   ├── replacesigprobed.cpp
│               │   ├── safecopy.cpp
│               │   ├── stack-debugger-tutorial.sln
│               │   ├── stack-debugger-tutorial.vcxproj
│               │   ├── stack-debugger-tutorial.vcxproj.filters
│               │   ├── stack-debugger.cpp
│               │   ├── statica.cpp
│               │   ├── staticcount.cpp
│               │   ├── strace.cpp
│               │   ├── thread_unix.c
│               │   ├── thread_win.c
│               │   └── w_malloctrace.cpp
│               ├── MaskVector
│               │   ├── iarg_reg_mask.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── maskedBranchTaken.cpp
│               │   ├── maskedJump_app.cpp
│               │   ├── maskedJump_mic.s
│               │   ├── memoryVector_app.cpp
│               │   ├── memoryVector_mic.s
│               │   ├── vcount.cpp
│               │   ├── vectorUtilization.cpp
│               │   ├── vectorUtilizationTypes.cpp
│               │   ├── vectorUtilizationTypes.h
│               │   ├── vectorvalues.cpp
│               │   └── vectorvalues.h
│               ├── MemTrace
│               │   ├── atomic_increment_ia32.asm
│               │   ├── atomic_increment_ia32.s
│               │   ├── atomic_increment_intel64.asm
│               │   ├── atomic_increment_intel64.s
│               │   ├── atomic_increment_mic.s
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── membuffer.cpp
│               │   ├── membuffer_simple.cpp
│               │   ├── membuffer_simple_tid.cpp
│               │   ├── membuffer_threadpool.cpp
│               │   ├── memtrace.cpp
│               │   ├── memtrace_simple.cpp
│               │   ├── memtrace_threadpool.cpp
│               │   ├── thread.c
│               │   ├── thread2.cpp
│               │   └── threadpool_statistics.h
│               ├── MemTranslate
│               │   ├── indirect_jmp.asm
│               │   ├── indirect_jmp.s
│               │   ├── indirect_jmp_with_translation.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── memory_addr_callback.cpp
│               │   └── memory_callback_error.cpp
│               ├── Memory
│               │   ├── README
│               │   ├── access_protection_app.cpp
│               │   ├── address_mapping.cpp
│               │   ├── address_mapping_probe.cpp
│               │   ├── allcache.cpp
│               │   ├── big_malloc.cpp
│               │   ├── cache.H
│               │   ├── dcache.cpp
│               │   ├── dcache_xscale_config.cpp
│               │   ├── footprint.H
│               │   ├── footprint.cpp
│               │   ├── icache.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── memalign.cpp
│               │   ├── memalloc.cpp
│               │   ├── memalloc2.cpp
│               │   ├── memory_allocation_from_app_access_protection_tool.cpp
│               │   ├── memory_allocation_from_tool_access_protection_tool.cpp
│               │   ├── memory_limit.cpp
│               │   ├── mmap_reader_app.cpp
│               │   ├── new_delete_app.cpp
│               │   ├── new_delete_tool.cpp
│               │   ├── print_stack.c
│               │   ├── print_vdso.c
│               │   └── restrict_memory_vdso.cpp
│               ├── Mix
│               │   ├── README
│               │   ├── assy-support-ia32.asm
│               │   ├── assy-support-intel64.asm
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── marker-example.cpp
│               │   ├── mix-fp-state.H
│               │   ├── mix-mt.cpp
│               │   ├── summarize.py
│               │   └── test-mt.cpp
│               ├── Mmx
│               │   ├── fpstack_ia32_win.asm
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mmx_test1_app.cpp
│               │   ├── mmx_test1_tool.cpp
│               │   ├── mmx_test2_app.cpp
│               │   ├── mmx_test2_tool.cpp
│               │   └── mmxsequence_ia32_win.asm
│               ├── MyPinTool
│               │   ├── MyPinTool.cpp
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── Probes
│               │   ├── app_trace.c
│               │   ├── arglist.cpp
│               │   ├── arglist.h
│               │   ├── bad_call.c
│               │   ├── bad_jump.c
│               │   ├── before_after_defaultcall.cpp
│               │   ├── before_after_defaultcall_app.c
│               │   ├── before_after_defaultcall_app.exe.zi.ia32
│               │   ├── before_after_defaultcall_app.exe.zi.intel64
│               │   ├── before_after_defaultcall_app.pdb.zi.ia32
│               │   ├── before_after_defaultcall_app.pdb.zi.intel64
│               │   ├── before_after_fastcall.cpp
│               │   ├── before_after_fastcall_app.c
│               │   ├── before_after_fastcall_app.exe.zi.ia32
│               │   ├── before_after_fastcall_app.exe.zi.intel64
│               │   ├── before_after_fastcall_app.pdb.zi.ia32
│               │   ├── before_after_fastcall_app.pdb.zi.intel64
│               │   ├── before_after_stdcall.cpp
│               │   ├── before_after_stdcall_app.c
│               │   ├── before_after_stdcall_app.exe.zi
│               │   ├── before_after_stdcall_app.exe.zi.ia32
│               │   ├── before_after_stdcall_app.exe.zi.intel64
│               │   ├── before_after_stdcall_app.pdb.zi
│               │   ├── before_after_stdcall_app.pdb.zi.ia32
│               │   ├── before_after_stdcall_app.pdb.zi.intel64
│               │   ├── child_process.cpp
│               │   ├── code_range.cpp
│               │   ├── context_probe.cpp
│               │   ├── create_process_app.cpp
│               │   ├── dltest_unix.c
│               │   ├── dltest_win.c
│               │   ├── do_nothing_ia32.asm
│               │   ├── do_nothing_ia32.s
│               │   ├── do_nothing_intel64.asm
│               │   ├── do_nothing_intel64.s
│               │   ├── empty.c
│               │   ├── emptysub.c
│               │   ├── err_call.c
│               │   ├── err_replace.c
│               │   ├── error-lin-jit.cpp
│               │   ├── error-lin-probe.cpp
│               │   ├── error-main.c
│               │   ├── error-sub.c
│               │   ├── error-win-jit.cpp
│               │   ├── error-win-probe.cpp
│               │   ├── exc.cpp
│               │   ├── exception_in_dll_app.cpp
│               │   ├── exception_in_dll_tool.cpp
│               │   ├── exception_in_mt_attach.cpp
│               │   ├── exception_in_mt_attach_app.cpp
│               │   ├── exception_in_probe.cpp
│               │   ├── exception_in_probe_app.c
│               │   ├── exception_in_probe_on_probe.cpp
│               │   ├── exception_in_probe_on_probe_sig.cpp
│               │   ├── exception_in_probe_sig.cpp
│               │   ├── exception_in_probed_call.cpp
│               │   ├── exception_in_probed_call_after.cpp
│               │   ├── exception_in_probed_call_after_app.c
│               │   ├── exception_in_probed_call_app.c
│               │   ├── exception_in_probed_call_cpp_after_app.cpp
│               │   ├── exception_in_probed_call_cpp_app.cpp
│               │   ├── exception_in_probed_call_sig.cpp
│               │   ├── exit_app.cpp
│               │   ├── exit_repl.cpp
│               │   ├── fall_thru.c
│               │   ├── fork_app.cpp
│               │   ├── getesp_ia32.asm
│               │   ├── getesp_intel64.asm
│               │   ├── getstack_ia32.s
│               │   ├── getstack_intel64.s
│               │   ├── good_jump.c
│               │   ├── heavy_stack_win.c
│               │   ├── high_target.c
│               │   ├── init.cpp
│               │   ├── insert1.cpp
│               │   ├── insert10.cpp
│               │   ├── insert11.cpp
│               │   ├── insert12.cpp
│               │   ├── insert1win.cpp
│               │   ├── insert2.cpp
│               │   ├── insert2win.cpp
│               │   ├── insert3.cpp
│               │   ├── insert3win.cpp
│               │   ├── insert4.cpp
│               │   ├── insert5.cpp
│               │   ├── insert6.cpp
│               │   ├── insert7.cpp
│               │   ├── insert8.cpp
│               │   ├── insert9.cpp
│               │   ├── insert_call_probed.cpp
│               │   ├── insert_call_probed.reference
│               │   ├── insert_call_probed_app.c
│               │   ├── insertfast.cpp
│               │   ├── insertstd.cpp
│               │   ├── ipr.c
│               │   ├── iprtool.cpp
│               │   ├── jmp_in_probe.cpp
│               │   ├── jmp_in_probe_app.cpp
│               │   ├── jmp_in_probe_app1.cpp
│               │   ├── jmp_in_probe_intel64.asm
│               │   ├── jmp_in_probe_intel64.s
│               │   ├── little_malloc.c
│               │   ├── load_map.cpp
│               │   ├── load_map_app.cpp
│               │   ├── local_branch_ia32.s
│               │   ├── local_branch_intel64.s
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── malloctrace2.cpp
│               │   ├── malloctrace2win.cpp
│               │   ├── malloctrace_locktest.cpp
│               │   ├── mallocwrappers_unix.c
│               │   ├── move_ip.c
│               │   ├── one_unix.c
│               │   ├── one_win.c
│               │   ├── parent_process.cpp
│               │   ├── pc64.s
│               │   ├── probe1.cpp
│               │   ├── probe10.cpp
│               │   ├── probe2.cpp
│               │   ├── probe3.cpp
│               │   ├── probe4.cpp
│               │   ├── probe5.cpp
│               │   ├── probe6.cpp
│               │   ├── probe7.cpp
│               │   ├── probe8.cpp
│               │   ├── probe9.cpp
│               │   ├── probe_close.cpp
│               │   ├── probe_err1.cpp
│               │   ├── probe_err2.cpp
│               │   ├── probe_err4.cpp
│               │   ├── probe_err5.cpp
│               │   ├── probe_err6.cpp
│               │   ├── probe_movip.cpp
│               │   ├── probe_on_probe1.cpp
│               │   ├── probe_on_probe1.reference
│               │   ├── probe_on_probe2.cpp
│               │   ├── probe_safe_test_ia32.s
│               │   ├── probe_safe_test_intel64.s
│               │   ├── probe_stdcall_fastcall.h
│               │   ├── probecdecl.cpp
│               │   ├── probefastcall.cpp
│               │   ├── probefastcall_app.c
│               │   ├── probefastcall_app.exe.zi
│               │   ├── probefastcall_app.pdb.zi
│               │   ├── probeheapalloc.cpp
│               │   ├── probemalloctrace.cpp
│               │   ├── probesafetest.cpp
│               │   ├── probesafetest_app.c
│               │   ├── probesleep.cpp
│               │   ├── probestdcall.cpp
│               │   ├── probestdcall_app.c
│               │   ├── probestdcall_app.exe.zi
│               │   ├── probestdcall_app.pdb.zi
│               │   ├── proto1.cpp
│               │   ├── proto1win-err.cpp
│               │   ├── proto1win.cpp
│               │   ├── proto2.cpp
│               │   ├── proto3.cpp
│               │   ├── proto3win.cpp
│               │   ├── proto4.cpp
│               │   ├── protobar.c
│               │   ├── protofoo.c
│               │   ├── protorbar.c
│               │   ├── pthread_exit_app.c
│               │   ├── pthread_exit_tool.cpp
│               │   ├── relocate_app.cpp
│               │   ├── relocate_asm_ia32.s
│               │   ├── relocate_asm_intel64.s
│               │   ├── relocate_rtn.cpp
│               │   ├── remove_probe.cpp
│               │   ├── remove_probe2.cpp
│               │   ├── replace_empty.cpp
│               │   ├── replace_empty_twice.cpp
│               │   ├── replace_exit.cpp
│               │   ├── replaceapp.c
│               │   ├── replaceapp.def
│               │   ├── replacecall.c
│               │   ├── replacedisp.c
│               │   ├── replacefun.c
│               │   ├── replacejmp.c
│               │   ├── replaceshorty.c
│               │   ├── replacesig_empty.cpp
│               │   ├── scan_all_rtns_for_probe.cpp
│               │   ├── sectest.cpp
│               │   ├── sempost_app.cpp
│               │   ├── sempost_repl.cpp
│               │   ├── set_tp.s
│               │   ├── shortBB.cpp
│               │   ├── shortBB64.cpp
│               │   ├── shortBB64app.c
│               │   ├── shortBB64foo.asm
│               │   ├── shortBBapp.c
│               │   ├── signals.cpp
│               │   ├── signals_app.cpp
│               │   ├── simplebar.c
│               │   ├── simplefoo.c
│               │   ├── simplefoo10.c
│               │   ├── simplefoo9.c
│               │   ├── simplesp.s
│               │   ├── simplestd10.c
│               │   ├── sleep_unix.c
│               │   ├── sleep_win.c
│               │   ├── spin_lock_app.c
│               │   ├── spinlock_insert.cpp
│               │   ├── spinlock_repl.cpp
│               │   ├── spinlock_replsig.cpp
│               │   ├── ssewin.cpp
│               │   ├── svcraw_app.cpp
│               │   ├── svcraw_repl.cpp
│               │   ├── symbolnames.cpp
│               │   ├── syscall_in_probe.cpp
│               │   ├── syscall_in_probe_app.c
│               │   ├── syscall_yield64.s
│               │   ├── thd_malloc.c
│               │   ├── tpss.cpp
│               │   ├── tpss_lin_libc.cpp
│               │   ├── tpss_lin_libdl.cpp
│               │   ├── tpss_lin_libncurses.cpp
│               │   ├── tpss_lin_libpthread.cpp
│               │   ├── tpss_lin_librt.cpp
│               │   ├── two_unix.c
│               │   ├── two_win.c
│               │   ├── unix_parent_tool.cpp
│               │   ├── unloadtest_unix.c
│               │   ├── unloadtest_win.c
│               │   └── win_child_process.cpp
│               ├── Regvalue
│               │   ├── changeRegs_ia32.asm
│               │   ├── changeRegs_ia32.s
│               │   ├── changeRegs_intel64.asm
│               │   ├── changeRegs_intel64.s
│               │   ├── changeRegs_mic.s
│               │   ├── change_context_regvalue.cpp
│               │   ├── checkXStateBV_app.cpp
│               │   ├── checkXStateBV_tool.cpp
│               │   ├── context_regvalue.cpp
│               │   ├── context_utils.cpp
│               │   ├── context_utils.h
│               │   ├── doXsave_ia32.asm
│               │   ├── doXsave_ia32.s
│               │   ├── doXsave_intel64.asm
│               │   ├── doXsave_intel64.s
│               │   ├── emu_context_regvalue.cpp
│               │   ├── iarg_reg_reference.cpp
│               │   ├── iarg_reg_reference_flags.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── print_flags.c
│               │   ├── print_flags_asm.asm
│               │   ├── print_flags_asm.s
│               │   ├── register_modification_utils.cpp
│               │   ├── register_modification_utils.h
│               │   ├── regvalue_app.cpp
│               │   ├── regvalue_test_utils.cpp
│               │   ├── regvalue_test_utils.h
│               │   ├── regvalues.cpp
│               │   ├── regvalues.h
│               │   ├── xsave_iarg_mem.cpp
│               │   ├── xsave_iarg_mem_app.cpp
│               │   ├── xstateBVUtils.cpp
│               │   └── xstateBVUtils.h
│               ├── Replay
│               │   ├── call_function_natively.cpp
│               │   ├── call_function_natively.reference
│               │   ├── call_function_natively_app.cpp
│               │   ├── ia32_cross_os_replay.record
│               │   ├── ia32_cross_os_replay.reference
│               │   ├── intel64_cross_os_replay.record
│               │   ├── intel64_cross_os_replay.reference
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mic_cross_os_replay.record
│               │   ├── mic_cross_os_replay.reference
│               │   ├── record_imageload.cpp
│               │   ├── record_imageload2.cpp
│               │   ├── replay_syscall.cpp
│               │   ├── win_exception.c
│               │   └── win_replay_exception.cpp
│               ├── RtnTests
│               │   ├── ifuncInstrumentation.cpp
│               │   ├── ifuncInstrumentationApp.c
│               │   ├── makefile
│               │   └── makefile.rules
│               ├── SegTrace
│               │   ├── disasm_container.H
│               │   ├── hello.c
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── pending_syscalls.H
│               │   ├── segtrace.cpp
│               │   └── thread.c
│               ├── SegmentsVirtualization
│               │   ├── fixed_base_reg.cpp
│               │   ├── gcc_thread_local_vars.reference
│               │   ├── gcc_thread_local_vars_app.c
│               │   ├── load_far_pointer_ia32.cpp
│               │   ├── load_far_pointer_ia32.s
│               │   ├── load_far_pointer_intel64.cpp
│               │   ├── load_far_pointer_intel64.s
│               │   ├── load_far_pointer_mic.cpp
│               │   ├── load_far_pointer_mic.s
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── modify_ldt.cpp
│               │   ├── movs.s
│               │   ├── set_thread_area1.cpp
│               │   ├── set_thread_area2.cpp
│               │   └── set_thread_area3.cpp
│               ├── SignalTests
│               │   ├── action-pending.cpp
│               │   ├── altstack.c
│               │   ├── async_multithreadingapp.c
│               │   ├── async_multithreadingtool.cpp
│               │   ├── asyncfpe.c
│               │   ├── bad-stack-alt-android.reference
│               │   ├── bad-stack-alt-android.toolreference
│               │   ├── bad-stack-alt-linux.reference
│               │   ├── bad-stack-alt-linux.toolreference
│               │   ├── bad-stack-alt-mac.reference
│               │   ├── bad-stack-alt-mac.toolreference
│               │   ├── bad-stack-ia32-asm.s
│               │   ├── bad-stack-intel64-asm.s
│               │   ├── bad-stack-noalt-android.reference
│               │   ├── bad-stack-noalt-android.toolreference
│               │   ├── bad-stack-noalt-linux.reference
│               │   ├── bad-stack-noalt-linux.toolreference
│               │   ├── bad-stack-noalt-mac.reference
│               │   ├── bad-stack-noalt-mac.toolreference
│               │   ├── bad-stack-sigret-android.reference
│               │   ├── bad-stack-sigret-android.toolreference
│               │   ├── bad-stack-sigret-linux.reference
│               │   ├── bad-stack-sigret-linux.toolreference
│               │   ├── bad-stack-sigret-mac.reference
│               │   ├── bad-stack-sigret-mac.toolreference
│               │   ├── bad-stack.c
│               │   ├── blockingsyscall.c
│               │   ├── blockingsyscall.reference
│               │   ├── blockloop.c
│               │   ├── call-app-stress-tool.cpp
│               │   ├── call-app-stress.cpp
│               │   ├── call-app-tool.cpp
│               │   ├── call-app.cpp
│               │   ├── call-app.reference
│               │   ├── copywithxmm_ia32.s
│               │   ├── copywithxmm_intel64.s
│               │   ├── deprecated-intercept.app-handle.reference
│               │   ├── deprecated-intercept.app-nohandle.reference
│               │   ├── deprecated-intercept.cpp
│               │   ├── deprecated-intercept.tool.reference
│               │   ├── dfcheck.c
│               │   ├── dfcheck_ia32.s
│               │   ├── dfcheck_intel64.s
│               │   ├── double.c
│               │   ├── efault.c
│               │   ├── errcheck.c
│               │   ├── exithandler.c
│               │   ├── exittool.cpp
│               │   ├── fastsigchecktool.cpp
│               │   ├── fatal.c
│               │   ├── fatal_block_sync.c
│               │   ├── fatal_block_sync.reference
│               │   ├── fatallog.reference
│               │   ├── fatalsync.c
│               │   ├── faultcheck-ia32-asm.s
│               │   ├── faultcheck-intel64-asm.s
│               │   ├── faultcheck-target.h
│               │   ├── faultcheck-x86.c
│               │   ├── faultcheck.c
│               │   ├── faultcheck_flags.c
│               │   ├── faultcheck_flags_ia32_asm.s
│               │   ├── faultcheck_flags_tool1.cpp
│               │   ├── faultcheck_flags_tool2.cpp
│               │   ├── faultcheck_flags_tool3.cpp
│               │   ├── faultcheck_ipf_asm.s
│               │   ├── faulttool.cpp
│               │   ├── forktest_altstack.c
│               │   ├── fpcheck.c
│               │   ├── fptags.c
│               │   ├── fptags_ia32.s
│               │   ├── futex.c
│               │   ├── handle-usr1.c
│               │   ├── handlerAlignment.cpp
│               │   ├── handlerAlignment_ia32.s
│               │   ├── hlt.c
│               │   ├── insfault-intel64-asm.s
│               │   ├── insfault-intel64.h
│               │   ├── insfault-linux-intel64.cpp
│               │   ├── insfault.cpp
│               │   ├── inst-type-app.cpp
│               │   ├── inst-type-tool.cpp
│               │   ├── intercept.tool.reference
│               │   ├── interceptall.cpp
│               │   ├── interceptor_for_regbindings_cache_test.cpp
│               │   ├── interceptsegv.compare
│               │   ├── interceptsegv.cpp
│               │   ├── intercepttool.cpp
│               │   ├── log.reference
│               │   ├── logtool.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── maskcheck.c
│               │   ├── movsbtest.c
│               │   ├── movsbtest_ia32.s
│               │   ├── movsbtest_intel64.s
│               │   ├── movsbtest_mic.s
│               │   ├── mtstress.cpp
│               │   ├── nestmask.c
│               │   ├── null-rewrite-tool.cpp
│               │   ├── num_segvs.h
│               │   ├── raise-exception-addrs.h
│               │   ├── raise-exception-tool.cpp
│               │   ├── recursive.c
│               │   ├── reg-pressure-tool.cpp
│               │   ├── regbindings_cache_test_checker.c
│               │   ├── replay-signal-app.c
│               │   ├── replay-signal-tool.cpp
│               │   ├── replay-signal.reference
│               │   ├── reporter.cpp
│               │   ├── resetcont.c
│               │   ├── resetcont.reference
│               │   ├── resetsegv-safecopy.cpp
│               │   ├── resetsegv.c
│               │   ├── resetsegv.reference
│               │   ├── segv.c
│               │   ├── segv_for_regbindings_cache_test.c
│               │   ├── segv_on_fetch.c
│               │   ├── setcontext.c
│               │   ├── shortmask.c
│               │   ├── sig64.cpp
│               │   ├── sigaltstack.c
│               │   ├── sigcont.c
│               │   ├── sigenable.cpp
│               │   ├── sigenable.reference
│               │   ├── sigenableapp.c
│               │   ├── sigenableapp2.c
│               │   ├── sigflowcheck.cpp
│               │   ├── sigflowcheck1.reference
│               │   ├── sigflowcheck2.reference
│               │   ├── sigprocmask_short.cpp
│               │   ├── sigsuspend.c
│               │   ├── sigusr2.c
│               │   ├── simple.c
│               │   ├── simpleasync.reference
│               │   ├── simplesync.reference
│               │   ├── spilltool.cpp
│               │   ├── suspendmask.c
│               │   ├── syncasyncapp.c
│               │   ├── syncasynctool.cpp
│               │   ├── then-stress-app.cpp
│               │   ├── then-stress-tool.cpp
│               │   ├── threadtest_altstack.c
│               │   ├── xmmcheck.c
│               │   └── xmmfaultcheck.c
│               ├── SimpleExamples
│               │   ├── callgraph.py
│               │   ├── calltrace.cpp
│               │   ├── catmix.cpp
│               │   ├── coco.cpp
│               │   ├── dcache.H
│               │   ├── dcache.cpp
│               │   ├── edgcnt.cpp
│               │   ├── emuload.cpp
│               │   ├── extmix.cpp
│               │   ├── fence.cpp
│               │   ├── flowgraph.py
│               │   ├── get_source_app.cpp
│               │   ├── get_source_location.cpp
│               │   ├── icount.cpp
│               │   ├── ilenmix.cpp
│               │   ├── inscount2_mt.cpp
│               │   ├── inscount2_vregs.cpp
│               │   ├── jumpmix.cpp
│               │   ├── ldstmix.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── malloctrace.cpp
│               │   ├── objdump-routine.csh
│               │   ├── opcodemix.cpp
│               │   ├── oper-imm.cpp
│               │   ├── oper-imm.ia32.reference
│               │   ├── oper-imm.intel64.reference
│               │   ├── oper_imm_app.cpp
│               │   ├── oper_imm_asm.asm
│               │   ├── oper_imm_asm.s
│               │   ├── pinatrace.cpp
│               │   ├── regmix.cpp
│               │   ├── regval.cpp
│               │   ├── regval_app.cpp
│               │   ├── topopcode.cpp
│               │   ├── toprtn.cpp
│               │   ├── trace.cpp
│               │   ├── xed-print.cpp
│               │   └── xed-use.cpp
│               ├── SyncTests
│               │   ├── lock-tester.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── mt-worker-unix.cpp
│               │   ├── mt-worker-win.cpp
│               │   ├── rt-locks-app.cpp
│               │   ├── rt-locks-tool.cpp
│               │   ├── stress-client-lock-app.cpp
│               │   └── stress-client-lock-tool.cpp
│               ├── SyscallsEmulation
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── ppollEmulation_app.cpp
│               │   ├── syscalls_and_locks_app.cpp
│               │   └── syscalls_and_locks_tool.cpp
│               ├── Tests
│               │   ├── IARGList.cpp
│               │   ├── after.cpp
│               │   ├── alah.cpp
│               │   ├── bblCache.cpp
│               │   ├── bblFallThrough.cpp
│               │   ├── bblnull.cpp
│               │   ├── brtaken.cpp
│               │   ├── callargs.cpp
│               │   ├── callargs_probe_tool.cpp
│               │   ├── cflowcheck.cpp
│               │   ├── check_env.cpp
│               │   ├── check_env.sh
│               │   ├── checkaddress.cpp
│               │   ├── checkaddressapp.s
│               │   ├── child_sig_while_execv_app.c
│               │   ├── child_sig_while_execv_simple_app.c
│               │   ├── clear_df_flag_tool.cpp
│               │   ├── const_context_at_ins.cpp
│               │   ├── context-pc.cpp
│               │   ├── context.cpp
│               │   ├── context_stack_and_spill.cpp
│               │   ├── correct_winapp_runs_pin_cmdline.cpp
│               │   ├── detach.cpp
│               │   ├── ea_verifier.cpp
│               │   ├── emu.cpp
│               │   ├── exitProcess.cpp
│               │   ├── exitProcessApp.c
│               │   ├── finiRemove.cpp
│               │   ├── foobar.c
│               │   ├── hello.cpp
│               │   ├── icount1.cpp
│               │   ├── icount2.cpp
│               │   ├── icount3.cpp
│               │   ├── icount4.cpp
│               │   ├── icount5.cpp
│               │   ├── icountcheck.cpp
│               │   ├── ifunc_tst.cpp
│               │   ├── ifuncmemcpy.cpp
│               │   ├── illegalEnvp_app.c
│               │   ├── imageLoad.cpp
│               │   ├── imageLoadBackward.cpp
│               │   ├── insMix.cpp
│               │   ├── insMixApp.s
│               │   ├── inscount2_mt_debuginfo.cpp
│               │   ├── inscount_per_image.cpp
│               │   ├── int3test.c
│               │   ├── jecxz_ia32.asm
│               │   ├── jecxz_ia32.s
│               │   ├── jecxz_intel64.asm
│               │   ├── jecxz_intel64.s
│               │   ├── jecxz_mic.s
│               │   ├── lasterror.cpp
│               │   ├── launcher_app.cpp
│               │   ├── launcher_tool.cpp
│               │   ├── limitedTraces.cpp
│               │   ├── loop.s
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── malloc.cpp
│               │   ├── memcpy_app.c
│               │   ├── memident.cpp
│               │   ├── memory_displacement_app
│               │   ├── mtest.cpp
│               │   ├── multipleinstrumentation.cpp
│               │   ├── mysetenv.c
│               │   ├── new.cpp
│               │   ├── operand.cpp
│               │   ├── pagetable.H
│               │   ├── parse_executed_rtns.cpp
│               │   ├── pin_tests_util.H
│               │   ├── prefix.cpp
│               │   ├── prefixApp.s
│               │   ├── probe.cpp
│               │   ├── reg.cpp
│               │   ├── reg_ref_inlined.cpp
│               │   ├── removeinstrumentation.cpp
│               │   ├── rep_ip_at_ipoint_after_app.c
│               │   ├── rep_ip_at_ipoint_after_app_unix.s
│               │   ├── rep_ip_at_ipoint_after_tool.cpp
│               │   ├── rtnNumIns.cpp
│               │   ├── rtn_create_at_dup.cpp
│               │   ├── rtn_insert_call_probed.cpp
│               │   ├── sampleApp.s
│               │   ├── sec.cpp
│               │   ├── segv.cpp
│               │   ├── sequence.cpp
│               │   ├── sequencecheck.cpp
│               │   ├── set_df_flag_tool.cpp
│               │   ├── set_status_flags_tool.cpp
│               │   ├── smc_check.cpp
│               │   ├── smc_test_l.c
│               │   ├── snprintf.cpp
│               │   ├── sourceLocation_app.cpp
│               │   ├── sourceLocation_img1.cpp
│               │   ├── sourceLocation_img2.cpp
│               │   ├── sourceLocation_tool.cpp
│               │   ├── statdyn_app.cpp
│               │   ├── statdyn_tool.cpp
│               │   ├── strcmp_app.c
│               │   ├── swizzle1.cpp
│               │   ├── symOutOfBound.cpp
│               │   ├── syntax.cpp
│               │   ├── syntax_tst.cpp
│               │   ├── test_ebx_in_exceptions_ia32_unix.s
│               │   ├── test_ebx_in_exceptions_ia32_win.asm
│               │   ├── test_ebx_in_exceptions_unix.cpp
│               │   ├── test_ebx_in_exceptions_win.cpp
│               │   ├── test_ebx_in_exceptions_xed_interface.cpp
│               │   ├── thread.cpp
│               │   ├── threadApp.cpp
│               │   ├── traceOriginal.cpp
│               │   ├── tracecount.cpp
│               │   ├── traceusage.cpp
│               │   ├── util.cpp
│               │   ├── verify.cpp
│               │   ├── win_cvapp_test_tool.cpp
│               │   ├── winapp_runs_pin.cpp
│               │   ├── winapp_runs_pin.h
│               │   ├── winapp_runs_pin.ico
│               │   ├── winapp_runs_pin.opensdf
│               │   ├── winapp_runs_pin.rc
│               │   ├── winapp_runs_pin.sln
│               │   ├── winapp_runs_pin.suo
│               │   ├── winapp_runs_pin.vcxproj
│               │   ├── winapp_runs_pin_ia32.xex
│               │   ├── winapp_runs_pin_intel64.xex
│               │   └── xedReg.cpp
│               ├── ToolUnitTests
│               │   ├── addit.c
│               │   ├── addr32_override_app.cpp
│               │   ├── addr32_override_app_asm.s
│               │   ├── align_access.cpp
│               │   ├── align_access_app.c
│               │   ├── analysis_flag_overwrite_app.c
│               │   ├── analysis_flag_overwrite_app_win.asm
│               │   ├── analysis_flag_overwrite_test1_inline.reference
│               │   ├── analysis_flag_overwrite_test1_noinline.reference
│               │   ├── analysis_flag_overwrite_test1_noinline_bridge.reference
│               │   ├── analysis_flag_overwrite_test2_inline.reference
│               │   ├── analysis_flag_overwrite_test2_noinline.reference
│               │   ├── analysis_flag_overwrite_test2_noinline_bridge.reference
│               │   ├── analysis_flag_overwrite_test3_inline.reference
│               │   ├── analysis_flag_overwrite_test3_noinline.reference
│               │   ├── analysis_flag_overwrite_test3_noinline_bridge.reference
│               │   ├── analysis_flag_overwrite_tool1.cpp
│               │   ├── analysis_flag_overwrite_tool1_win.asm
│               │   ├── analysis_flag_overwrite_tool2.cpp
│               │   ├── analysis_flag_overwrite_tool2_win.asm
│               │   ├── analysis_flag_overwrite_tool3.cpp
│               │   ├── analysis_flag_overwrite_tool3_win.asm
│               │   ├── and.s
│               │   ├── aoti_mutation_target.c
│               │   ├── aoti_mutation_tool.cpp
│               │   ├── apc_monitor.cpp
│               │   ├── apc_monitor.reference
│               │   ├── app_inspects_internal_thread_win.cpp
│               │   ├── app_inspects_internal_thread_win_app.c
│               │   ├── args.cpp
│               │   ├── args.reference
│               │   ├── args_err.cpp
│               │   ├── args_lineno.cpp
│               │   ├── attach.cpp
│               │   ├── attach_app.cpp
│               │   ├── attach_tool.reference
│               │   ├── badfile.reference
│               │   ├── badpath.reference
│               │   ├── baserel_in_probe_tool.cpp
│               │   ├── big_bss.c
│               │   ├── bigrange.address
│               │   ├── branch_target_addr.cpp
│               │   ├── btc.s
│               │   ├── btc_app.c
│               │   ├── callapp-flush.cpp
│               │   ├── callapp0.cpp
│               │   ├── callapp0i.cpp
│               │   ├── callapp1.cpp
│               │   ├── callapp10.cpp
│               │   ├── callapp10i.cpp
│               │   ├── callapp12.cpp
│               │   ├── callapp13.cpp
│               │   ├── callapp14.cpp
│               │   ├── callapp15.cpp
│               │   ├── callapp1i.cpp
│               │   ├── callapp2.cpp
│               │   ├── callapp3.cpp
│               │   ├── callapp4.cpp
│               │   ├── callapp5.cpp
│               │   ├── callapp6.cpp
│               │   ├── callapp7.cpp
│               │   ├── callapp8.cpp
│               │   ├── callapp9.cpp
│               │   ├── callapp_64bit_param_app_1.c
│               │   ├── callapp_64bit_param_app_2.c
│               │   ├── callapp_64bit_param_tool.cpp
│               │   ├── callapp_nested_app.c
│               │   ├── callapp_nested_app1.c
│               │   ├── callapp_nested_tool.cpp
│               │   ├── callapp_perf_app.c
│               │   ├── callapp_perf_app1.c
│               │   ├── callapp_perf_tool.cpp
│               │   ├── callappfast10.cpp
│               │   ├── callappstd10.cpp
│               │   ├── callsp_ia32.s
│               │   ├── callsp_intel64.s
│               │   ├── callsp_mic.s
│               │   ├── cancel.c
│               │   ├── change_syscall.cpp
│               │   ├── change_syscall_app.c
│               │   ├── check_env.cpp
│               │   ├── check_env_app.cpp
│               │   ├── check_fpstate.cpp
│               │   ├── check_fpstate_app.c
│               │   ├── check_legal_callbacks.cpp
│               │   ├── check_tool_malloc.sh
│               │   ├── checkerrorfile.cpp
│               │   ├── checkexecuting.cpp
│               │   ├── checkinline.cpp
│               │   ├── checkreps.cpp
│               │   ├── claim_regs.cpp
│               │   ├── clobber.cpp
│               │   ├── clobber_asm.s
│               │   ├── cmovstest.c
│               │   ├── cmpxchg8b_unix.s
│               │   ├── cmpxchg8b_win.asm
│               │   ├── cmpxchg8b_with_explicit_ebx_win.asm
│               │   ├── code_cache_block_overflow1.cpp
│               │   ├── code_cache_block_overflow2.cpp
│               │   ├── context.cpp
│               │   ├── context_state_apis.cpp
│               │   ├── control_init.cpp
│               │   ├── create_rtn.cpp
│               │   ├── create_rtn.strip
│               │   ├── create_rtn_app.cpp
│               │   ├── data_in_code_win.cpp
│               │   ├── data_in_code_win_app.c
│               │   ├── datasym.cpp
│               │   ├── datasym_app.c
│               │   ├── debugservice_monitor.cpp
│               │   ├── debugservice_monitor.reference
│               │   ├── deepbind.cpp
│               │   ├── deepbind.ver
│               │   ├── deepbind_app.c
│               │   ├── deepbind_syscalls.c
│               │   ├── df_test1_inline.reference
│               │   ├── df_test1_noinline.reference
│               │   ├── df_test1_noinline_bridge.reference
│               │   ├── df_test2_inline.reference
│               │   ├── df_test2_noinline.reference
│               │   ├── df_test2_noinline_bridge.reference
│               │   ├── df_test3_inline.reference
│               │   ├── df_test3_noinline.reference
│               │   ├── df_test3_noinline_bridge.reference
│               │   ├── df_test4_inline.reference
│               │   ├── df_test4_noinline.reference
│               │   ├── df_test4_noinline_bridge.reference
│               │   ├── df_test5_inline.reference
│               │   ├── df_test5_noinline.reference
│               │   ├── df_test5_noinline_bridge.reference
│               │   ├── df_test_app.c
│               │   ├── df_test_app_win.asm
│               │   ├── df_test_tool1.cpp
│               │   ├── df_test_tool1_win.asm
│               │   ├── df_test_tool2.cpp
│               │   ├── df_test_tool2_win.asm
│               │   ├── df_test_tool3.cpp
│               │   ├── df_test_tool3_win.asm
│               │   ├── df_test_tool4.cpp
│               │   ├── df_test_tool4_win.asm
│               │   ├── df_test_tool5.cpp
│               │   ├── df_test_tool5_win.asm
│               │   ├── dlclose.cpp
│               │   ├── dlclose_app.cpp
│               │   ├── dltest.c
│               │   ├── dltest2.c
│               │   ├── doint.c
│               │   ├── doint_ia32.s
│               │   ├── dummy_dll.c
│               │   ├── dynamic_secondary_dll.cpp
│               │   ├── ea_verifier_addr16.cpp
│               │   ├── ea_verifier_addr16_win.asm
│               │   ├── ea_verifier_bt.cpp
│               │   ├── earlymalloc.cpp
│               │   ├── earlyout.cpp
│               │   ├── elf_symbols.cpp
│               │   ├── elf_symsize.cpp
│               │   ├── emu_jumps.cpp
│               │   ├── emu_stack.cpp
│               │   ├── error_log.cpp
│               │   ├── error_log_app.cpp
│               │   ├── exceptionAddress_lin.cpp
│               │   ├── exceptionAddress_lin_app.cpp
│               │   ├── exception_app_ia32.s
│               │   ├── exception_app_intel64.s
│               │   ├── exception_app_mic.s
│               │   ├── exception_context_monitor.cpp
│               │   ├── exception_monitor.cpp
│               │   ├── exception_monitor_for_cpp_exception_test.reference
│               │   ├── exception_monitor_for_divide_by_zero_test.reference
│               │   ├── exception_monitor_for_iret_order.cpp
│               │   ├── exception_tool_ia32.s
│               │   ├── exception_tool_intel64.s
│               │   ├── exception_tool_mic.s
│               │   ├── executeat_callback.cpp
│               │   ├── executeat_lock.cpp
│               │   ├── execvp.c
│               │   ├── execvp.reference
│               │   ├── exports_only_tool.cpp
│               │   ├── far.s
│               │   ├── farmain.cpp
│               │   ├── findthreadwithappstack.reference
│               │   ├── fini.cpp
│               │   ├── flag_ac_app.c
│               │   ├── flag_ac_app_ia32_unix.s
│               │   ├── flag_ac_app_ia32_win.asm
│               │   ├── flag_ac_app_intel64_unix.s
│               │   ├── flag_ac_app_intel64_win.asm
│               │   ├── flag_ac_app_mic_unix.s
│               │   ├── flag_ac_app_u_64.s
│               │   ├── flag_ac_inline.reference
│               │   ├── flag_ac_noinline.reference
│               │   ├── flag_ac_noinline_bridge.reference
│               │   ├── flag_ac_tool.cpp
│               │   ├── flag_ac_win_app.c
│               │   ├── flag_ac_win_inline.reference
│               │   ├── flag_ac_win_noinline.reference
│               │   ├── flag_ac_win_noinline_bridge.reference
│               │   ├── flag_ac_win_tool.cpp
│               │   ├── flag_spill_fill_app.c
│               │   ├── flag_spill_fill_app_win.asm
│               │   ├── flag_spill_fill_test1_inline.reference
│               │   ├── flag_spill_fill_test1_noinline.reference
│               │   ├── flag_spill_fill_test1_noinline_bridge.reference
│               │   ├── flag_spill_fill_tool1.cpp
│               │   ├── flag_spill_fill_tool1.dll.reference
│               │   ├── flag_spill_fill_tool1_win.asm
│               │   ├── flags_at_analysis_app.c
│               │   ├── flags_at_analysis_app_win.asm
│               │   ├── flags_at_analysis_tool.cpp
│               │   ├── fp_args.cpp
│               │   ├── fp_args.reference
│               │   ├── fp_args_app.cpp
│               │   ├── fp_context_set_const_context.cpp
│               │   ├── fp_insert.cpp
│               │   ├── fp_replace.cpp
│               │   ├── fp_replace_app.c
│               │   ├── funcarg_ep.cpp
│               │   ├── funcarg_ep_app.cpp
│               │   ├── funcarg_ep_ia32.reference
│               │   ├── funcarg_ep_intel64.reference
│               │   ├── funcarg_ep_mic.reference
│               │   ├── funreplace.reference
│               │   ├── funreplace_alert.cpp
│               │   ├── funreplace_alert.reference
│               │   ├── guard_page.cpp
│               │   ├── guard_page_app.cpp
│               │   ├── hello.reference
│               │   ├── htab.c
│               │   ├── iarg_tsc1.cpp
│               │   ├── iarg_tsc2.cpp
│               │   ├── iarg_tsc3.cpp
│               │   ├── iarg_tsc4.cpp
│               │   ├── iarg_tsc5.cpp
│               │   ├── iarg_tsc_probed1.cpp
│               │   ├── illegal_call_app.cpp
│               │   ├── image_entry.cpp
│               │   ├── image_entry.reference
│               │   ├── image_load.cpp
│               │   ├── incebx.cpp
│               │   ├── indirect_call_branch_target_addr.cpp
│               │   ├── inline_opt_test.cpp
│               │   ├── inline_opt_test_app.cpp
│               │   ├── inline_opt_test_app_ia32.asm
│               │   ├── inline_opt_test_app_ia32.s
│               │   ├── inline_opt_test_app_intel64.asm
│               │   ├── inline_opt_test_app_intel64.s
│               │   ├── inline_opt_test_df1.cpp
│               │   ├── inline_opt_test_df3.cpp
│               │   ├── inline_opt_test_df_app.cpp
│               │   ├── inline_opt_test_df_app_ia32.asm
│               │   ├── inline_opt_test_df_ia32.asm
│               │   ├── inline_opt_test_ia32.asm
│               │   ├── inline_opt_test_ia32.s
│               │   ├── inline_opt_test_intel64.asm
│               │   ├── inline_opt_test_intel64.s
│               │   ├── inlinecall.cpp
│               │   ├── inlinecall.reference
│               │   ├── inlined-stack-arg.cpp
│               │   ├── inlined-stack-arg.reference
│               │   ├── inlined-stack-arg1.cpp
│               │   ├── inlined-stack-arg1.reference
│               │   ├── inlined-stack-arg2.cpp
│               │   ├── inlined-stack-arg2.reference
│               │   ├── inlined-stack-arg2_win.asm
│               │   ├── inlined-stack-arg2_win_intel64.asm
│               │   ├── inner.c
│               │   ├── ins_check_fetcher.cpp
│               │   ├── inscount2_fornoinline.cpp
│               │   ├── insert_if_then_call.cpp
│               │   ├── insert_if_then_call1.cpp
│               │   ├── insert_if_then_call2.cpp
│               │   ├── insert_if_then_call_app.cpp
│               │   ├── insertand.cpp
│               │   ├── insfetch_tool.cpp
│               │   ├── int3del.cpp
│               │   ├── int3test.c
│               │   ├── internal_exception_handler.cpp
│               │   ├── internal_exception_handler_app.cpp
│               │   ├── internal_exception_handler_app_lin.cpp
│               │   ├── internal_exception_handler_lin.cpp
│               │   ├── intrin.cpp
│               │   ├── iret_ia32.s
│               │   ├── iret_intel64.s
│               │   ├── iret_mic.s
│               │   ├── iretmain_ia32.c
│               │   ├── iretmain_intel64.c
│               │   ├── iretmain_mic.c
│               │   ├── jcx_addr16_app.c
│               │   ├── jcx_addr16_tool.cpp
│               │   ├── jcx_addr16_tool.reference
│               │   ├── jitmalloctrace.cpp
│               │   ├── knob_duplicate_name.cpp
│               │   ├── knob_writeonce.cpp
│               │   ├── kthread.c
│               │   ├── kthread.reference
│               │   ├── large.address
│               │   ├── leave.cpp
│               │   ├── line.cpp
│               │   ├── line.reference
│               │   ├── little_malloc.c
│               │   ├── lpd.c
│               │   ├── main_dll.cpp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── malmalloc.cpp
│               │   ├── malmalloc.reference
│               │   ├── memalign.cpp
│               │   ├── memory_displacement.cpp
│               │   ├── memory_displacement_app.cpp
│               │   ├── memory_displacement_app.s
│               │   ├── mmap.cpp
│               │   ├── move_then_test.cpp
│               │   ├── mt.cpp
│               │   ├── mt.reference
│               │   ├── mt_app.cpp
│               │   ├── mt_tool.cpp
│               │   ├── mtflush.cpp
│               │   ├── mtflush.reference
│               │   ├── mtflushapp_unix.cpp
│               │   ├── mtflushapp_win.cpp
│               │   ├── mtstatic.reference
│               │   ├── multimem.cpp
│               │   ├── mxcsr_ia32.asm
│               │   ├── mxcsr_ia32.s
│               │   ├── mxcsr_intel64.asm
│               │   ├── mxcsr_intel64.s
│               │   ├── mxcsr_mic.s
│               │   ├── nops.cpp
│               │   ├── one.c
│               │   ├── oneprog.c
│               │   ├── operandtool.cpp
│               │   ├── partialinline.cpp
│               │   ├── partialinline.reference
│               │   ├── passthru_context_xmm_regs_app.cpp
│               │   ├── passthru_context_xmm_regs_callapp.cpp
│               │   ├── passthru_context_xmm_regs_executeat.cpp
│               │   ├── pipeapp.c
│               │   ├── popea_verifier.cpp
│               │   ├── posix_memalign.cpp
│               │   ├── pusha_popa.cpp
│               │   ├── pusha_popa_asm.asm
│               │   ├── pusha_popa_asm.s
│               │   ├── pushtest.c
│               │   ├── pushw.s
│               │   ├── raise_exception.cpp
│               │   ├── raise_exception_app.cpp
│               │   ├── realloc.cpp
│               │   ├── rebase_dll.c
│               │   ├── rebase_dll_tool.cpp
│               │   ├── reg_context_fp_st.cpp
│               │   ├── reg_context_set_const_context.cpp
│               │   ├── reg_context_set_fp_st.cpp
│               │   ├── reg_context_set_x87.cpp
│               │   ├── reg_context_set_xmm.cpp
│               │   ├── reg_context_set_ymm.cpp
│               │   ├── reg_context_x87.cpp
│               │   ├── reg_context_xmm.cpp
│               │   ├── reg_context_ymm.cpp
│               │   ├── reg_inst_gx.cpp
│               │   ├── reg_inst_gx.reference
│               │   ├── reg_inst_gx.tool.reference
│               │   ├── reg_operands_test.reference
│               │   ├── reg_operands_test_app.c
│               │   ├── reg_operands_test_app_win.asm
│               │   ├── reg_operands_test_tool.cpp
│               │   ├── reg_ref_fp_st.cpp
│               │   ├── reg_ref_x87.cpp
│               │   ├── reg_ref_xmm.cpp
│               │   ├── reg_ref_ymm.cpp
│               │   ├── reg_value_fp_st.cpp
│               │   ├── reg_value_x87.cpp
│               │   ├── reg_value_xmm.cpp
│               │   ├── reg_value_ymm.cpp
│               │   ├── rep_ia32.s
│               │   ├── rep_intel64.s
│               │   ├── rep_mic.s
│               │   ├── repcmpsz.c
│               │   ├── repcmpsz.s
│               │   ├── repcmpsz_tool.cpp
│               │   ├── repcmpsz_tool.reference
│               │   ├── replace_free.cpp
│               │   ├── replace_malloc_inst.cpp
│               │   ├── replace_rtl_alloc_heap.cpp
│               │   ├── reppredicate_ia32.reference
│               │   ├── reppredicate_intel64.reference
│               │   ├── reptool.cpp
│               │   ├── reptool_ia32.reference
│               │   ├── reptool_intel64.reference
│               │   ├── reptool_mic.reference
│               │   ├── reserve_memory.c
│               │   ├── returnflags.cpp
│               │   ├── returnflags_and_ref.cpp
│               │   ├── returnreg.cpp
│               │   ├── rewritememop.cpp
│               │   ├── rewritememop1.cpp
│               │   ├── rtn_insert_call1.cpp
│               │   ├── rtn_insert_call2.cpp
│               │   ├── runnable.cpp
│               │   ├── runnable.h
│               │   ├── safecopy.cpp
│               │   ├── safecopy_mxcsr.cpp
│               │   ├── secname_app.cpp
│               │   ├── secname_tool.cpp
│               │   ├── secure_scl_test.cpp
│               │   ├── seg_override_app1.c
│               │   ├── seg_override_app1_win.asm
│               │   ├── segmented_ea_verifier.cpp
│               │   ├── segmented_ea_verifier_lin_ia32.s
│               │   ├── segmented_ea_verifier_lin_intel64.s
│               │   ├── segmented_ea_verifier_win1_ia32.asm
│               │   ├── segmented_ea_verifier_win1_intel64.asm
│               │   ├── set_fp_context_xmm_regs.cpp
│               │   ├── set_fp_context_xmm_regs_app.cpp
│               │   ├── set_fp_context_xmm_regs_ia32.reference
│               │   ├── set_fp_context_xmm_regs_intel64.reference
│               │   ├── set_xmm_scratches.cpp
│               │   ├── set_xmm_scratches_ia32.asm
│               │   ├── set_xmm_scratches_intel64.asm
│               │   ├── short_name.cpp
│               │   ├── sigmask-mac.reference
│               │   ├── sigmask.c
│               │   ├── sigmask.reference
│               │   ├── simple.c
│               │   ├── simplebar.c
│               │   ├── simplebar64.c
│               │   ├── simplefast10.c
│               │   ├── simplefoo.c
│               │   ├── simplefoo1.c
│               │   ├── simplefoo10.c
│               │   ├── simplefoo12.c
│               │   ├── simplefoo13.c
│               │   ├── simplefoo14.c
│               │   ├── simplefoo2.c
│               │   ├── simplefoo3.c
│               │   ├── simplefoo4.c
│               │   ├── simplefoo6.c
│               │   ├── simplefoo7.c
│               │   ├── simplefoo8.c
│               │   ├── simplefoo9.c
│               │   ├── simplesp.s
│               │   ├── simplestd10.c
│               │   ├── smallpush_ia32.s
│               │   ├── smallpush_intel64.s
│               │   ├── smallpush_mic.s
│               │   ├── smc_util.cpp
│               │   ├── smc_util.h
│               │   ├── smcapp_bbl.cpp
│               │   ├── smcapp_except.cpp
│               │   ├── smcapp_ia32.cpp
│               │   ├── smcapp_mt.cpp
│               │   ├── socket_app.cpp
│               │   ├── soload.cpp
│               │   ├── soload.reference
│               │   ├── soloadrange.cpp
│               │   ├── sp_argument.cpp
│               │   ├── sp_argument_app.c
│               │   ├── spalign.cpp
│               │   ├── spalign_asm_intel64_unix.s
│               │   ├── spalign_asm_intel64_win.asm
│               │   ├── spawntool.cpp
│               │   ├── spawntool_app.c
│               │   ├── sse-ref.cpp
│               │   ├── sse-ref.reference
│               │   ├── sse-ref_ia32.asm
│               │   ├── sse-ref_ia32.s
│               │   ├── sse-ref_intel64.asm
│               │   ├── sse-ref_intel64.s
│               │   ├── sse-ref_mic.s
│               │   ├── sse-unaligned-class.cpp
│               │   ├── sse-unaligned-class2.cpp
│               │   ├── sse.cpp
│               │   ├── stackalign.cpp
│               │   ├── static_secondary_dll.cpp
│               │   ├── statica_locktest.cpp
│               │   ├── str2flt.cpp
│               │   ├── str2int.cpp
│               │   ├── str2int64.cpp
│               │   ├── str2int64.reference
│               │   ├── strace_ia32.cpp
│               │   ├── stracewin_ia32.cpp
│               │   ├── stress_const_context.cpp
│               │   ├── stress_const_context2.cpp
│               │   ├── stress_const_context_app.cpp
│               │   ├── stringtest.c
│               │   ├── suspend-mxcsr-asm.asm
│               │   ├── suspend-mxcsr.cpp
│               │   ├── suspend_app_win.cpp
│               │   ├── suspend_context_app_win.cpp
│               │   ├── suspend_win.cpp
│               │   ├── sw_interrupt.cpp
│               │   ├── sw_interrupt_app.cpp
│               │   ├── swizzle2.cpp
│               │   ├── swizzle2.reference
│               │   ├── swizzle3.cpp
│               │   ├── swizzle5.cpp
│               │   ├── swizzle5.reference
│               │   ├── swizzle_seg.cpp
│               │   ├── swizzle_seg.reference
│               │   ├── swizzle_seg_app.cpp
│               │   ├── swizzle_seg_app.def
│               │   ├── swizzle_seg_app_ia32_unix.s
│               │   ├── swizzle_seg_app_ia32_win.asm
│               │   ├── swizzle_seg_app_intel64_unix.s
│               │   ├── swizzle_seg_app_mic_unix.s
│               │   ├── swizzle_util.h
│               │   ├── swizzlealloc.c
│               │   ├── symsize.c
│               │   ├── symsize_asm.s
│               │   ├── sys_memory.h
│               │   ├── sys_memory_unix.c
│               │   ├── sys_memory_win.c
│               │   ├── syscall.cpp
│               │   ├── syscall_std.cpp
│               │   ├── syscall_std.reference
│               │   ├── syscall_std_app.cpp
│               │   ├── tcreatehook.reference
│               │   ├── teb.cpp
│               │   ├── teb.reference
│               │   ├── teb_app.cpp
│               │   ├── test_iarg_partial_context.cpp
│               │   ├── test_iarg_partial_context_app.cpp
│               │   ├── test_iarg_preserve.cpp
│               │   ├── test_iarg_preserve2.cpp
│               │   ├── test_iarg_preserve_app.cpp
│               │   ├── test_iarg_preserve_app2.cpp
│               │   ├── test_iarg_preserve_ia32_unix.s
│               │   ├── test_iarg_preserve_ia32_win.asm
│               │   ├── test_iarg_preserve_intel64_unix.s
│               │   ├── test_iarg_preserve_intel64_win.asm
│               │   ├── test_iarg_preserve_mxcsr.cpp
│               │   ├── test_iarg_preserve_mxcsr1.cpp
│               │   ├── test_iarg_preserve_mxcsr_app.cpp
│               │   ├── test_iarg_preserve_probe.cpp
│               │   ├── test_iarg_preserve_probe_app.cpp
│               │   ├── test_inlined_consts.cpp
│               │   ├── test_inlined_consts_intel64.asm
│               │   ├── test_ip_access.cpp
│               │   ├── test_ip_access_app.cpp
│               │   ├── test_ip_access_app_intel64.asm
│               │   ├── test_lea_rip_app.cpp
│               │   ├── test_lea_rip_intel64.asm
│               │   ├── test_sysenter_win.cpp
│               │   ├── thenpredicated.cpp
│               │   ├── thread.c
│               │   ├── thread_callback.cpp
│               │   ├── thread_count.cpp
│               │   ├── thread_count.reference
│               │   ├── thread_count2.cpp
│               │   ├── thread_count2_debug_service.ia32.reference
│               │   ├── thread_count2_debug_service.intel64.reference
│               │   ├── thread_count2_divide_by_zero.reference
│               │   ├── thread_count_cpp_exception.ia32.reference
│               │   ├── thread_count_cpp_exception.intel64.reference
│               │   ├── thread_count_load_library.reference
│               │   ├── thread_count_queue_apc.reference
│               │   ├── thread_count_thread_creation.reference
│               │   ├── thread_ea_addr16.c
│               │   ├── thread_pool.cpp
│               │   ├── thread_pool.h
│               │   ├── thread_segmented_ea.c
│               │   ├── thread_usestack.c
│               │   ├── thread_wait.c
│               │   ├── threadtestwin.c
│               │   ├── tool_fetch_app.c
│               │   ├── tool_full_path.cpp
│               │   ├── tool_malloc.cpp
│               │   ├── toolfetch_sub.cpp
│               │   ├── toolfetch_sub.reference
│               │   ├── tstcmpxchg8b.c
│               │   ├── tstcmpxchg8b_with_explicit_ebx.c
│               │   ├── tstcmpxchg8b_with_explicit_ebx.reference
│               │   ├── two.c
│               │   ├── undecorate.cpp
│               │   ├── undecorateOperator_app.cpp
│               │   ├── undecorate_app.cpp
│               │   ├── unsup_syscall.s
│               │   ├── waitpidbug.c
│               │   ├── win_callback.cpp
│               │   ├── win_callback_app.cpp
│               │   ├── win_code_on_reused_memory.cpp
│               │   ├── win_code_on_reused_memory.reference
│               │   ├── win_cpp_exception.cpp
│               │   ├── win_cpp_exception.reference
│               │   ├── win_debug_service.cpp
│               │   ├── win_debug_service.reference
│               │   ├── win_divide_by_zero_exception.cpp
│               │   ├── win_divide_by_zero_exception.reference
│               │   ├── win_early_thread.cpp
│               │   ├── win_early_thread_dll.cpp
│               │   ├── win_exception_test.cpp
│               │   ├── win_hello_c_sharp_app.cs
│               │   ├── win_hello_c_sharp_app_bin
│               │   ├── win_load_library.cpp
│               │   ├── win_load_library.reference
│               │   ├── win_mxcsr_app.cpp
│               │   ├── win_no_dependencies.cpp
│               │   ├── win_queue_apc.cpp
│               │   ├── win_queue_apc.reference
│               │   ├── win_syscallenum.cpp
│               │   ├── win_thread_create_apc.cpp
│               │   ├── win_thread_create_apc.reference
│               │   ├── win_tls_dll.cpp
│               │   ├── winapp_exception_context.cpp
│               │   ├── write_debugger_error.cpp
│               │   ├── write_user_error.cpp
│               │   ├── x87_regs_in_context.cpp
│               │   ├── x87_regs_in_context_app.cpp
│               │   ├── xmmapp.cpp
│               │   └── xmmtest.cpp
│               ├── Utils
│               │   ├── and-launch.py
│               │   ├── andshell.py
│               │   ├── attachLauncher_unix.cpp
│               │   ├── avx2_check.c
│               │   ├── avx_check.c
│               │   ├── avx_check_ia32.asm
│               │   ├── avx_check_ia32.s
│               │   ├── avx_check_intel64.asm
│               │   ├── avx_check_intel64.s
│               │   ├── avx_check_mic.s
│               │   ├── compare.py
│               │   ├── cp-pin.cpp
│               │   ├── disable-aslr.c
│               │   ├── hello.c
│               │   ├── hello_win.exe-ia32
│               │   ├── hello_win.exe-intel64
│               │   ├── hello_win.pdb-ia32
│               │   ├── hello_win.pdb-intel64
│               │   ├── installer.py
│               │   ├── mac-cmp
│               │   ├── makefile
│               │   ├── makefile.rules
│               │   ├── micshell.py
│               │   ├── regvalue_utils.cpp
│               │   ├── regvalue_utils.h
│               │   ├── supports_avx2_ia32.asm
│               │   ├── supports_avx2_ia32.s
│               │   ├── supports_avx2_intel64.asm
│               │   ├── supports_avx2_intel64.s
│               │   ├── supports_avx2_mic.s
│               │   ├── supports_avx_ia32.asm
│               │   ├── supports_avx_ia32.s
│               │   ├── supports_avx_intel64.asm
│               │   ├── supports_avx_intel64.s
│               │   ├── supports_avx_mic.s
│               │   ├── testGccVersion
│               │   ├── testLibcVersion
│               │   ├── testReleaseVersion
│               │   ├── testReleaseVersionPython.py
│               │   ├── testsummary
│               │   ├── threadlib.h
│               │   ├── threadlib_unix.c
│               │   ├── threadlib_win.c
│               │   ├── tsx_check.c
│               │   ├── tsx_check_ia32.asm
│               │   ├── tsx_check_ia32.s
│               │   ├── tsx_check_intel64.asm
│               │   ├── tsx_check_intel64.s
│               │   └── tsx_check_mic.s
│               ├── makefile
│               └── pintool.tscons-extension
└── zsim
    ├── LICENSE
    ├── README.md
    ├── README.stats
    ├── SConstruct
    ├── SPECtestformatmodifier_z.txt
    ├── benchADM.par
    ├── build
    │   └── opt
    │       ├── SConscript
    │       ├── access_tracing.cpp
    │       ├── access_tracing.d
    │       ├── access_tracing.h
    │       ├── access_tracing.os
    │       ├── access_tracing.ot
    │       ├── barrier.h
    │       ├── bithacks.h
    │       ├── breakdown_stats.h
    │       ├── cache.cpp
    │       ├── cache.d
    │       ├── cache.h
    │       ├── cache.os
    │       ├── cache_arrays.cpp
    │       ├── cache_arrays.d
    │       ├── cache_arrays.h
    │       ├── cache_arrays.os
    │       ├── coherence_ctrls.cpp
    │       ├── coherence_ctrls.d
    │       ├── coherence_ctrls.h
    │       ├── coherence_ctrls.os
    │       ├── config.cpp
    │       ├── config.d
    │       ├── config.h
    │       ├── config.o
    │       ├── config.os
    │       ├── config.ot
    │       ├── constants.h
    │       ├── contention_sim.cpp
    │       ├── contention_sim.d
    │       ├── contention_sim.h
    │       ├── contention_sim.os
    │       ├── core.h
    │       ├── core_recorder.cpp
    │       ├── core_recorder.d
    │       ├── core_recorder.h
    │       ├── core_recorder.os
    │       ├── cpuenum.h
    │       ├── cpuid.h
    │       ├── ddr_mem.cpp
    │       ├── ddr_mem.d
    │       ├── ddr_mem.h
    │       ├── ddr_mem.os
    │       ├── debug.h
    │       ├── debug_harness.cpp
    │       ├── debug_harness.d
    │       ├── debug_harness.h
    │       ├── debug_harness.o
    │       ├── debug_zsim.cpp
    │       ├── debug_zsim.d
    │       ├── debug_zsim.h
    │       ├── debug_zsim.os
    │       ├── decoder.cpp
    │       ├── decoder.d
    │       ├── decoder.h
    │       ├── decoder.os
    │       ├── detailed_mem.cpp
    │       ├── detailed_mem.d
    │       ├── detailed_mem.h
    │       ├── detailed_mem.os
    │       ├── detailed_mem_params.cpp
    │       ├── detailed_mem_params.d
    │       ├── detailed_mem_params.h
    │       ├── detailed_mem_params.os
    │       ├── dramsim_mem_ctrl.cpp
    │       ├── dramsim_mem_ctrl.d
    │       ├── dramsim_mem_ctrl.h
    │       ├── dramsim_mem_ctrl.os
    │       ├── dumptrace
    │       ├── dumptrace.cpp
    │       ├── dumptrace.d
    │       ├── dumptrace.ot
    │       ├── event_queue.h
    │       ├── event_recorder.h
    │       ├── fftoggle
    │       ├── fftoggle.cpp
    │       ├── fftoggle.d
    │       ├── fftoggle.o
    │       ├── filter_cache.h
    │       ├── g_heap
    │       │   └── dlmalloc.h.c
    │       ├── g_std
    │       │   ├── g_multimap.h
    │       │   ├── g_string.h
    │       │   ├── g_unordered_map.h
    │       │   ├── g_unordered_set.h
    │       │   ├── g_vector.h
    │       │   └── stl_galloc.h
    │       ├── galloc.cpp
    │       ├── galloc.d
    │       ├── galloc.h
    │       ├── galloc.o
    │       ├── galloc.os
    │       ├── galloc.ot
    │       ├── hash.cpp
    │       ├── hash.d
    │       ├── hash.h
    │       ├── hash.os
    │       ├── hdf5_stats.cpp
    │       ├── hdf5_stats.d
    │       ├── hdf5_stats.os
    │       ├── ideal_arrays.h
    │       ├── init.cpp
    │       ├── init.d
    │       ├── init.h
    │       ├── init.os
    │       ├── intrusive_list.h
    │       ├── libzsim.so
    │       ├── locks.h
    │       ├── log.cpp
    │       ├── log.d
    │       ├── log.h
    │       ├── log.o
    │       ├── log.os
    │       ├── log.ot
    │       ├── lookahead.cpp
    │       ├── lookahead.d
    │       ├── lookahead.os
    │       ├── mem_ctrls.cpp
    │       ├── mem_ctrls.d
    │       ├── mem_ctrls.h
    │       ├── mem_ctrls.os
    │       ├── memory_hierarchy.cpp
    │       ├── memory_hierarchy.d
    │       ├── memory_hierarchy.h
    │       ├── memory_hierarchy.os
    │       ├── memory_hierarchy.ot
    │       ├── mockingjay_repl.h
    │       ├── mockingjay_repl_2.h
    │       ├── monitor.cpp
    │       ├── monitor.d
    │       ├── monitor.os
    │       ├── mtrand.h
    │       ├── mutex.h
    │       ├── network.cpp
    │       ├── network.d
    │       ├── network.h
    │       ├── network.os
    │       ├── null_core.cpp
    │       ├── null_core.d
    │       ├── null_core.h
    │       ├── null_core.os
    │       ├── ooo_core.cpp
    │       ├── ooo_core.d
    │       ├── ooo_core.h
    │       ├── ooo_core.os
    │       ├── ooo_core_recorder.cpp
    │       ├── ooo_core_recorder.d
    │       ├── ooo_core_recorder.h
    │       ├── ooo_core_recorder.os
    │       ├── pad.h
    │       ├── parse_vdso.cpp
    │       ├── parse_vdso.d
    │       ├── parse_vdso.os
    │       ├── part_repl_policies.h
    │       ├── partition_mapper.cpp
    │       ├── partition_mapper.d
    │       ├── partition_mapper.h
    │       ├── partition_mapper.os
    │       ├── partitioner.h
    │       ├── pin_cmd.cpp
    │       ├── pin_cmd.d
    │       ├── pin_cmd.h
    │       ├── pin_cmd.o
    │       ├── pin_cmd.os
    │       ├── pin_cmd.ot
    │       ├── prefetcher.cpp
    │       ├── prefetcher.d
    │       ├── prefetcher.h
    │       ├── prefetcher.os
    │       ├── prio_queue.h
    │       ├── proc_stats.cpp
    │       ├── proc_stats.d
    │       ├── proc_stats.h
    │       ├── proc_stats.os
    │       ├── process_stats.cpp
    │       ├── process_stats.d
    │       ├── process_stats.h
    │       ├── process_stats.os
    │       ├── process_tree.cpp
    │       ├── process_tree.d
    │       ├── process_tree.h
    │       ├── process_tree.os
    │       ├── profile_stats.h
    │       ├── rdtsc.h
    │       ├── repl_policies.h
    │       ├── rrip_repl.h
    │       ├── scheduler.cpp
    │       ├── scheduler.d
    │       ├── scheduler.h
    │       ├── scheduler.os
    │       ├── simple_core.cpp
    │       ├── simple_core.d
    │       ├── simple_core.h
    │       ├── simple_core.os
    │       ├── slab_alloc.h
    │       ├── sorttrace
    │       ├── sorttrace.cpp
    │       ├── sorttrace.d
    │       ├── sorttrace.ot
    │       ├── stats.h
    │       ├── stats_filter.cpp
    │       ├── stats_filter.d
    │       ├── stats_filter.h
    │       ├── stats_filter.os
    │       ├── str.h
    │       ├── text_stats.cpp
    │       ├── text_stats.d
    │       ├── text_stats.os
    │       ├── tick_event.h
    │       ├── timing_cache.cpp
    │       ├── timing_cache.d
    │       ├── timing_cache.h
    │       ├── timing_cache.os
    │       ├── timing_core.cpp
    │       ├── timing_core.d
    │       ├── timing_core.h
    │       ├── timing_core.os
    │       ├── timing_event.cpp
    │       ├── timing_event.d
    │       ├── timing_event.h
    │       ├── timing_event.os
    │       ├── trace_driver.cpp
    │       ├── trace_driver.d
    │       ├── trace_driver.h
    │       ├── trace_driver.os
    │       ├── tracing_cache.cpp
    │       ├── tracing_cache.d
    │       ├── tracing_cache.h
    │       ├── tracing_cache.os
    │       ├── utility_monitor.cpp
    │       ├── utility_monitor.d
    │       ├── utility_monitor.h
    │       ├── utility_monitor.os
    │       ├── version.h
    │       ├── virt
    │       │   ├── common.h
    │       │   ├── cpu.cpp
    │       │   ├── cpu.d
    │       │   ├── cpu.os
    │       │   ├── fs.cpp
    │       │   ├── fs.d
    │       │   ├── fs.os
    │       │   ├── patchdefs.h
    │       │   ├── port_virtualizer.h
    │       │   ├── ports.cpp
    │       │   ├── ports.d
    │       │   ├── ports.os
    │       │   ├── syscall_name.cpp
    │       │   ├── syscall_name.cpp.in
    │       │   ├── syscall_name.d
    │       │   ├── syscall_name.h
    │       │   ├── syscall_name.os
    │       │   ├── time.cpp
    │       │   ├── time.d
    │       │   ├── time.os
    │       │   ├── time_conv.h
    │       │   ├── timeout.cpp
    │       │   ├── timeout.d
    │       │   ├── timeout.os
    │       │   ├── virt.cpp
    │       │   ├── virt.d
    │       │   ├── virt.h
    │       │   └── virt.os
    │       ├── weave_md1_mem.h
    │       ├── zsim
    │       ├── zsim.cpp
    │       ├── zsim.d
    │       ├── zsim.h
    │       ├── zsim.os
    │       ├── zsim_harness.cpp
    │       ├── zsim_harness.d
    │       └── zsim_harness.o
    ├── configs
    │   ├── LFU
    │   │   ├── blackscholes_8c_simlarge.cfg
    │   │   ├── bodytrack_8c_simlarge.cfg
    │   │   ├── bzip2.cfg
    │   │   ├── cactusADM.cfg
    │   │   ├── calculix.cfg
    │   │   ├── canneal_8c_simlarge.cfg
    │   │   ├── dedup_8c_simlarge.cfg
    │   │   ├── fluidanimate_8c_simlarge.cfg
    │   │   ├── freqmine_8c_simlarge.cfg
    │   │   ├── gcc.cfg
    │   │   ├── hmmer.cfg
    │   │   ├── lbm.cfg
    │   │   ├── leslie3d.cfg
    │   │   ├── libquantum.cfg
    │   │   ├── mcf.cfg
    │   │   ├── milc.cfg
    │   │   ├── namd.cfg
    │   │   ├── sjeng.cfg
    │   │   ├── soplex.cfg
    │   │   ├── streamcluster_8c_simlarge.cfg
    │   │   ├── swaptions_8c_simlarge.cfg
    │   │   ├── x264_8c_simlarge.cfg
    │   │   └── xalan.cfg
    │   ├── LRU
    │   │   ├── blackscholes_8c_simlarge.cfg
    │   │   ├── bodytrack_8c_simlarge.cfg
    │   │   ├── bzip2.cfg
    │   │   ├── cactusADM.cfg
    │   │   ├── calculix.cfg
    │   │   ├── canneal_8c_simlarge.cfg
    │   │   ├── dedup_8c_simlarge.cfg
    │   │   ├── fluidanimate_8c_simlarge.cfg
    │   │   ├── freqmine_8c_simlarge.cfg
    │   │   ├── gcc.cfg
    │   │   ├── hmmer.cfg
    │   │   ├── lbm.cfg
    │   │   ├── leslie3d.cfg
    │   │   ├── libquantum.cfg
    │   │   ├── mcf.cfg
    │   │   ├── milc.cfg
    │   │   ├── namd.cfg
    │   │   ├── sjeng.cfg
    │   │   ├── soplex.cfg
    │   │   ├── streamcluster_8c_simlarge.cfg
    │   │   ├── swaptions_8c_simlarge.cfg
    │   │   ├── x264_8c_simlarge.cfg
    │   │   └── xalan.cfg
    │   ├── Mockingjay
    │   │   ├── blackscholes_8c_simlarge.cfg
    │   │   ├── bodytrack_8c_simlarge.cfg
    │   │   ├── bzip2.cfg
    │   │   ├── cactusADM.cfg
    │   │   ├── calculix.cfg
    │   │   ├── canneal_8c_simlarge.cfg
    │   │   ├── dedup_8c_simlarge.cfg
    │   │   ├── fluidanimate_8c_simlarge.cfg
    │   │   ├── freqmine_8c_simlarge.cfg
    │   │   ├── gcc.cfg
    │   │   ├── hmmer.cfg
    │   │   ├── lbm.cfg
    │   │   ├── leslie3d.cfg
    │   │   ├── libquantum.cfg
    │   │   ├── mcf.cfg
    │   │   ├── milc.cfg
    │   │   ├── namd.cfg
    │   │   ├── sjeng.cfg
    │   │   ├── soplex.cfg
    │   │   ├── streamcluster_8c_simlarge.cfg
    │   │   ├── swaptions_8c_simlarge.cfg
    │   │   ├── x264_8c_simlarge.cfg
    │   │   └── xalan.cfg
    │   └── SRRIP
    │       ├── blackscholes_8c_simlarge.cfg
    │       ├── bodytrack_8c_simlarge.cfg
    │       ├── bzip2.cfg
    │       ├── cactusADM.cfg
    │       ├── calculix.cfg
    │       ├── canneal_8c_simlarge.cfg
    │       ├── dedup_8c_simlarge.cfg
    │       ├── fluidanimate_8c_simlarge.cfg
    │       ├── freqmine_8c_simlarge.cfg
    │       ├── gcc.cfg
    │       ├── hmmer.cfg
    │       ├── lbm.cfg
    │       ├── leslie3d.cfg
    │       ├── libquantum.cfg
    │       ├── mcf.cfg
    │       ├── milc.cfg
    │       ├── namd.cfg
    │       ├── sjeng.cfg
    │       ├── soplex.cfg
    │       ├── streamcluster_8c_simlarge.cfg
    │       ├── swaptions_8c_simlarge.cfg
    │       ├── x264_8c_simlarge.cfg
    │       └── xalan.cfg
    ├── heartbeat
    ├── leslie3d.out
    ├── misc
    │   ├── Vagrantfile
    │   ├── cpplint.py
    │   ├── ffControl.py
    │   ├── fix_whitespace.sh
    │   ├── gitver.py
    │   ├── hooks
    │   │   ├── Makefile
    │   │   ├── README
    │   │   ├── fortran_hooks.c
    │   │   ├── test.c
    │   │   ├── test.cpp
    │   │   ├── test.f
    │   │   ├── test.java
    │   │   ├── zsim.java
    │   │   ├── zsim_hooks.h
    │   │   └── zsim_jni.cpp
    │   ├── lint_includes.py
    │   ├── list_syscalls.py
    │   └── patchRoot
    │       ├── cpuinfo.template
    │       ├── genPatchRoot.py
    │       ├── nodeFiles
    │       │   ├── distance
    │       │   ├── meminfo
    │       │   ├── numastat
    │       │   ├── scan_unevictable_pages
    │       │   └── vmstat
    │       └── stat.template
    ├── out.cfg
    ├── outputs
    │   ├── LRU
    │   │   ├── blackscholes_8c_simlarge
    │   │   │   ├── blackscholes.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── bzip2
    │   │   │   ├── bzip2.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── calculix
    │   │   │   ├── calculix.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── canneal_8c_simlarge
    │   │   │   ├── canneal.log
    │   │   │   ├── canneal_8c_simlarge.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── fluidanimate_8c_simlarge
    │   │   │   ├── fluidanimate.log
    │   │   │   ├── fluidanimate_8c_simlarge.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── gcc
    │   │   │   ├── gcc.log
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── hmmer
    │   │   │   ├── heartbeat
    │   │   │   ├── hmmer.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── lbm
    │   │   │   ├── heartbeat
    │   │   │   ├── lbm.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── leslie3d
    │   │   │   ├── heartbeat
    │   │   │   ├── leslie3d.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── libquantum
    │   │   │   ├── heartbeat
    │   │   │   ├── libquantum.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── milc
    │   │   │   ├── heartbeat
    │   │   │   ├── milc.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── namd
    │   │   │   ├── heartbeat
    │   │   │   ├── namd.log
    │   │   │   ├── out.cfg
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── sjeng
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── sjeng.log
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── soplex
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── soplex.log
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── swaptions_8c_simlarge
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── swaptions.log
    │   │   │   ├── swaptions_8c_simlarge.log
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   ├── x264_8c_simlarge
    │   │   │   ├── heartbeat
    │   │   │   ├── out.cfg
    │   │   │   ├── x264.log
    │   │   │   ├── x264_8c_simlarge.log
    │   │   │   ├── zsim-cmp.h5
    │   │   │   ├── zsim-ev.h5
    │   │   │   ├── zsim.h5
    │   │   │   └── zsim.out
    │   │   └── xalan
    │   │       ├── heartbeat
    │   │       ├── out.cfg
    │   │       ├── xalan.log
    │   │       ├── zsim-cmp.h5
    │   │       ├── zsim-ev.h5
    │   │       ├── zsim.h5
    │   │       └── zsim.out
    │   └── Mockingjay
    │       ├── blackscholes_8c_simlarge
    │       │   ├── blackscholes.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── bzip2
    │       │   ├── bzip2.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── calculix
    │       │   ├── calculix.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── canneal_8c_simlarge
    │       │   ├── canneal.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── fluidanimate_8c_simlarge
    │       │   ├── fluidanimate.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── gcc
    │       │   ├── gcc.log
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── hmmer
    │       │   ├── heartbeat
    │       │   ├── hmmer.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── lbm
    │       │   ├── heartbeat
    │       │   ├── lbm.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── leslie3d
    │       │   ├── heartbeat
    │       │   ├── leslie3d.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── libquantum
    │       │   ├── heartbeat
    │       │   ├── libquantum.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── milc
    │       │   ├── heartbeat
    │       │   ├── milc.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── namd
    │       │   ├── heartbeat
    │       │   ├── namd.log
    │       │   ├── out.cfg
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── sjeng
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── sjeng.log
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── soplex
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── soplex.log
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── swaptions_8c_simlarge
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── swaptions.log
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       ├── x264_8c_simlarge
    │       │   ├── heartbeat
    │       │   ├── out.cfg
    │       │   ├── x264.log
    │       │   ├── zsim-cmp.h5
    │       │   ├── zsim-ev.h5
    │       │   ├── zsim.h5
    │       │   └── zsim.out
    │       └── xalan
    │           ├── heartbeat
    │           ├── out.cfg
    │           ├── xalan.log
    │           ├── zsim-cmp.h5
    │           ├── zsim-ev.h5
    │           ├── zsim.h5
    │           └── zsim.out
    ├── pin.log
    ├── pintool.log
    ├── spooles.out
    ├── src
    │   ├── SConscript
    │   ├── access_tracing.cpp
    │   ├── access_tracing.h
    │   ├── barrier.h
    │   ├── bithacks.h
    │   ├── breakdown_stats.h
    │   ├── cache.cpp
    │   ├── cache.h
    │   ├── cache_arrays.cpp
    │   ├── cache_arrays.h
    │   ├── coherence_ctrls.cpp
    │   ├── coherence_ctrls.h
    │   ├── config.cpp
    │   ├── config.h
    │   ├── constants.h
    │   ├── contention_sim.cpp
    │   ├── contention_sim.h
    │   ├── core.h
    │   ├── core_recorder.cpp
    │   ├── core_recorder.h
    │   ├── cpuenum.h
    │   ├── cpuid.h
    │   ├── ddr_mem.cpp
    │   ├── ddr_mem.h
    │   ├── debug.h
    │   ├── debug_harness.cpp
    │   ├── debug_harness.h
    │   ├── debug_zsim.cpp
    │   ├── debug_zsim.h
    │   ├── decoder.cpp
    │   ├── decoder.h
    │   ├── detailed_mem.cpp
    │   ├── detailed_mem.h
    │   ├── detailed_mem_params.cpp
    │   ├── detailed_mem_params.h
    │   ├── dramsim_mem_ctrl.cpp
    │   ├── dramsim_mem_ctrl.h
    │   ├── dumptrace.cpp
    │   ├── event_queue.h
    │   ├── event_recorder.h
    │   ├── fftoggle.cpp
    │   ├── filter_cache.h
    │   ├── g_heap
    │   │   └── dlmalloc.h.c
    │   ├── g_std
    │   │   ├── README.txt
    │   │   ├── g_list.h
    │   │   ├── g_multimap.h
    │   │   ├── g_string.h
    │   │   ├── g_unordered_map.h
    │   │   ├── g_unordered_set.h
    │   │   ├── g_vector.h
    │   │   └── stl_galloc.h
    │   ├── galloc.cpp
    │   ├── galloc.h
    │   ├── hash.cpp
    │   ├── hash.h
    │   ├── hdf5_stats.cpp
    │   ├── ideal_arrays.h
    │   ├── init.cpp
    │   ├── init.h
    │   ├── intrusive_list.h
    │   ├── locks.h
    │   ├── log.cpp
    │   ├── log.h
    │   ├── lookahead.cpp
    │   ├── mem_ctrls.cpp
    │   ├── mem_ctrls.h
    │   ├── memory_hierarchy.cpp
    │   ├── memory_hierarchy.h
    │   ├── mockingjay_repl.h
    │   ├── monitor.cpp
    │   ├── mtrand.h
    │   ├── mutex.h
    │   ├── network.cpp
    │   ├── network.h
    │   ├── null_core.cpp
    │   ├── null_core.h
    │   ├── ooo_core.cpp
    │   ├── ooo_core.h
    │   ├── ooo_core_recorder.cpp
    │   ├── ooo_core_recorder.h
    │   ├── pad.h
    │   ├── parse_vdso.cpp
    │   ├── part_repl_policies.h
    │   ├── partition_mapper.cpp
    │   ├── partition_mapper.h
    │   ├── partitioner.h
    │   ├── pin_cmd.cpp
    │   ├── pin_cmd.h
    │   ├── prefetcher.cpp
    │   ├── prefetcher.h
    │   ├── prio_queue.h
    │   ├── proc_stats.cpp
    │   ├── proc_stats.h
    │   ├── process_stats.cpp
    │   ├── process_stats.h
    │   ├── process_tree.cpp
    │   ├── process_tree.h
    │   ├── profile_stats.h
    │   ├── rdtsc.h
    │   ├── repl_policies.h
    │   ├── rrip_repl.h
    │   ├── scheduler.cpp
    │   ├── scheduler.h
    │   ├── simple_core.cpp
    │   ├── simple_core.h
    │   ├── slab_alloc.h
    │   ├── sorttrace.cpp
    │   ├── stats.h
    │   ├── stats_filter.cpp
    │   ├── stats_filter.h
    │   ├── str.h
    │   ├── text_stats.cpp
    │   ├── tick_event.h
    │   ├── timing_cache.cpp
    │   ├── timing_cache.h
    │   ├── timing_core.cpp
    │   ├── timing_core.h
    │   ├── timing_event.cpp
    │   ├── timing_event.h
    │   ├── trace_driver.cpp
    │   ├── trace_driver.h
    │   ├── tracing_cache.cpp
    │   ├── tracing_cache.h
    │   ├── utility_monitor.cpp
    │   ├── utility_monitor.h
    │   ├── virt
    │   │   ├── common.h
    │   │   ├── cpu.cpp
    │   │   ├── fs.cpp
    │   │   ├── patchdefs.h
    │   │   ├── port_virtualizer.h
    │   │   ├── ports.cpp
    │   │   ├── syscall_name.cpp.in
    │   │   ├── syscall_name.h
    │   │   ├── time.cpp
    │   │   ├── time_conv.h
    │   │   ├── timeout.cpp
    │   │   ├── virt.cpp
    │   │   └── virt.h
    │   ├── weave_md1_mem.h
    │   ├── zsim.cpp
    │   ├── zsim.h
    │   └── zsim_harness.cpp
    ├── term_project_runscript
    ├── tests
    │   ├── het.cfg
    │   ├── hooks.cfg
    │   ├── pgo.cfg
    │   ├── ptree.cfg
    │   └── simple.cfg
    ├── zsim-cmp.h5
    ├── zsim-ev.h5
    ├── zsim.h5
    └── zsim.out

```
# Compilation and run process

##### 1. Apply a path file for cse server

```
$ git apply cse_server.patch
```

##### 2. Unzip benchmarks files

```
zip -F benchmarks.zip --out single-benchmark.zip && unzip single-benchmark.zip && mkdir benchmarks/parsec-2.1/inputs/streamcluster
```

### 3. Environment setup

Everytime you want to build or run zsim, you need to setup the environment variables first.

```
$ source setup_env
```

##### 4. Compile zsim

```
$ cd zsim
$ scons -j4
```

##### 5. Launch a test to run

```
$ ./term_project_runscript <suite> <benchmark> <repl_policy>
```
Go to zsim/outputs/term_project to view outputs
