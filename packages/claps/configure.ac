# ------------------------------------------------------------------------
# Process this file with autoconf to produce a configure script.
# ------------------------------------------------------------------------

# @HEADER
# ************************************************************************
# 
#        Claps: A Collection of Domain Decomposition Preconditioners
#               and Solvers
#        Copyright (2006) Sandia Corporation
# 
# Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
# license for use of this work by or on behalf of the U.S. Government.
# 
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#  
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#  
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
# USA
# Questions? Contact Clark R. Dohrmann (crdohrm@sandia.gov) 
# 
# ************************************************************************
# @HEADER

# ------------------------------------------------------------------------
# Initialization 
# ------------------------------------------------------------------------



# This must be the first line in configure.ac.
# Optional 3rd argument is email address for bugs.

#  #np# - package name, version number, and e-mail address below
AC_INIT(claps, 0.0, crdohrm@sandia.gov)

# Hello World!
#  #np# - package name below
echo "----------------------------------------"
echo "Running Claps Configure Script"
echo "----------------------------------------"

# This is to protect against accidentally specifying the wrong
# directory with --srcdir.  Any file in that directory will do,
# preferably one that is unlikely to be removed or renamed.

# #np# - file name below
AC_CONFIG_SRCDIR([src/preconditioners/CLOP_solver.cpp])

# Specify directory for auxillary build tools (e.g., install-sh,
# config.sub, config.guess) and M4 files.

#
# #np# This a subdirectory of Trilinos/packages/claps that contains
# #np# a number of useful m4 files.  Any package that uses these m4 files
# #np# will have to add them to the repository.  The m4 files perform various
# #np# common checks and set common variable values to minimize redundant work.
#
AC_CONFIG_AUX_DIR(config)
#  #np# - Change file names in next line 
# Configure should create src/New_Package_config.h from src/New_Package_config.h.in

AM_CONFIG_HEADER(src/Claps_config.h:src/Claps_config.h.in)

# Allow users to specify their own "install" command.  If none is specified,
# the default is install-sh found in the config subdirectory.
                                                                                
AC_ARG_WITH(install,
 [AC_HELP_STRING([--with-install=INSTALL_PROGRAM],
 [Use the installation program INSTALL_PROGRAM rather the default that is provided.  For example --with-install="/path/install -p"])],
 [
   INSTALL=$withval
   INSTALL_PROGRAM=$withval
   INSTALL_SCRIPT=$withval
   INSTALL_DATA="$withval -m 644"
 ],)
                                                                                
# AM_MAINTAINER_MODE turns off maintainer-only makefile targets by
# default, and changes configure to understand a
# --enable-maintainer-mode option. --enable-maintainer-mode turns the
# maintainer-only targets back on. The maintainer-only makefile
# targets permit end users to clean automatically-generated files such
# as configure, which means they have to have autoconf and automake
# installed to repair the damage. AM_MAINTAINER_MODE makes it a bit
# harder for users to shoot themselves in the foot.

AM_MAINTAINER_MODE

# Define $build, $host, $target, etc

AC_CANONICAL_TARGET

# Use automake

#  #np# - Required version of automake.
AM_INIT_AUTOMAKE(1.10 no-define tar-ustar)

# Specify required version of autoconf.

AC_PREREQ(2.61)

# ------------------------------------------------------------------------
# Check to see if MPI enabled and if any special configuration done
# ------------------------------------------------------------------------
                                                                                                                             
TAC_ARG_CONFIG_MPI

#  #np# - can eliminate compiler checks below if your package does not use the
#         language corresponding to the check.  Please note that if you use
#	  F77_FUNC to determine Fortran name mangling, you should not remove
#	  the Fortran compiler check or the check for Fortran flags.  Doing
#	  so will prevent the detection of the proper name mangling in some
#	  cases.
# ------------------------------------------------------------------------
# Checks for programs
# ------------------------------------------------------------------------

AC_PROG_CC(cc gcc)
AC_PROG_CXX(CC g++ c++ cxx)
#AC_PROG_F77(f77 g77 gfortran f90 xlf90 f95)
AC_PROG_RANLIB

# ------------------------------------------------------------------------
# Checks for extra flags
# #np# - You can pull flag checks for languages not used in package.  Please 
#	  note that if you use F77_FUNC to determine Fortran name mangling, 
#	  you should not remove the Fortran compiler check or the check for 
#	  Fortran flags.  Doing so will prevent the detection of the proper 
#	  name mangling in some cases.
# ------------------------------------------------------------------------
# Check if --with-flags present, prepend any specs to FLAGS

TAC_ARG_WITH_FLAGS(ccflags, CCFLAGS)
TAC_ARG_WITH_FLAGS(cxxflags, CXXFLAGS)
TAC_ARG_WITH_FLAGS(cflags, CFLAGS)
#TAC_ARG_WITH_FLAGS(fflags, FFLAGS)
TAC_ARG_WITH_LIBS
TAC_ARG_WITH_FLAGS(ldflags, LDFLAGS)

# ------------------------------------------------------------------------
# Alternate archiver
# ------------------------------------------------------------------------

TAC_ARG_WITH_AR

# ------------------------------------------------------------------------
# MPI link check
# ------------------------------------------------------------------------
TAC_ARG_CHECK_MPI

#  #np# - Customize the checks for headers needed in package being added.
#NOTE: This section still needs to be updated for new_package, it is still 
# code from Epetra
# ------------------------------------------------------------------------
# Checks for header files - used in Epetra_ConfigDefs.h 
# ------------------------------------------------------------------------

AC_CHECK_HEADERS([cstdlib stdlib.h], [break],)
AC_CHECK_HEADERS([cstdio stdio.h], [break],)
AC_CHECK_HEADERS([cassert assert.h], [break],)
AC_CHECK_HEADERS([cmath math.h], [break],)
AC_CHECK_HEADERS([iomanip iomanip.h], [break],)
AC_CHECK_HEADERS([iostream iostream.h], [break],)
AC_CHECK_HEADERS([string string.h], [break],)
AC_CHECK_HEADERS([fstream climits algorithm],,)

if test "X$ac_cv_header_algorithm" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find algorithm.  Claps requires this header file.]])
fi

if test "X$ac_cv_header_fstream" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find fstream.  Claps requires this header file.]])
fi

if test "X$ac_cv_header_climits" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find climits.  Claps requires this header file.]])
fi

if test "X$ac_cv_header_cstdlib" != "Xyes" && test "X$ac_cv_header_stdlib_h" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find cstdlib or stdlib.h.  Claps requires at least one or the other.]])
fi

if test "X$ac_cv_header_cstdio" != "Xyes" && test "X$ac_cv_header_stdio_h" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find cstdio or stdio.h.  Claps requires at least one or the other.]])
fi

if test "X$ac_cv_header_cassert" != "Xyes" && test "X$ac_cv_header_assert_h" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find cassert or assert.h.  Claps requires at least one or the other.]])
fi

if test "X$ac_cv_header_string" != "Xyes" && test "X$ac_cv_header_string_h" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find string or string.h.  Claps requires at least one or the other.]])
fi

if test "X$ac_cv_header_iostream" != "Xyes" && test "X$ac_cv_header_iostream_h" != "Xyes"; then
  AC_MSG_ERROR([[Cannot find iostream or iostream.h.  Claps requires at least one or the other.]])
fi

if test "X${host}" != "Xtflop"; then
  if test "X$ac_cv_header_cmath" != "Xyes" && test "X$ac_cv_header_math_h" != "Xyes"; then
    AC_MSG_ERROR([[Cannot find cmath or math.h.  Claps requires at least one or the other.]])
  fi
else
  # TFLOP
  if test "X$ac_cv_header_iomanip" != "Xyes" && test "X$ac_cv_header_iomanip_h" != "Xyes"; then
    AC_MSG_ERROR([[Cannot find iomanip or iomanip.h.  Claps requires at least one or the other.]])
  fi
fi  

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE

# ------------------------------------------------------------------------
# Checks for compiler characteristics - Epetra_ConfigDefs.h uses these, 
# so it makes sense to leave them in - see PORTABILITY in this directory
# ------------------------------------------------------------------------
AC_CXX_NAMESPACES
AC_CXX_HAVE_STL
AC_CXX_BOOL
AC_CXX_MUTABLE
# ---------------------------------------------------------------------
# These are pretty obscure
# ---------------------------------------------------------------------
AC_CXX_NEW_FOR_SCOPING
#AC_CXX_STD_IOS_BASE_FMTFLAGS
AC_CXX_STD_SPRINTF

# ------------------------------------------------------------------------
# Checks for Makefile.export related systems
# ------------------------------------------------------------------------
TAC_ARG_ENABLE_EXPORT_MAKEFILES(yes)

# ------------------------------------------------------------------------
# Checks for special package flags
# ------------------------------------------------------------------------

TAC_ARG_ENABLE_FEATURE_SUB( claps, sclaps, [enable Sandia Claps interface (requires Salinas header files)], CLAPS_SCLAPS, no)
AM_CONDITIONAL(HAVE_SCLAPS, [test "X$ac_cv_use_claps_sclaps" != "Xno"])


#
#  #np# - These options are specific to Epetra and are left only as examples.
#         If uncommented, the following lines would define HAVE_FATAL_MESSAGES
#         in the (package)_config.h file.  Developers should use a 
#         more specific name such as 'new_package-fatal_messages', rather
#         than 'fatal_messages'.
#TAC_ARG_ENABLE_OPTION(fatal_messages, [enable printing of fatal error messages], 
#                   FATAL_MESSAGES, yes)
#TAC_ARG_ENABLE_OPTION(warning_messages, [enable printing of warning error messages], 
#                   WARNING_MESSAGES, no)
#TAC_ARG_ENABLE_OPTION(format_io, [Use package-defined IO formatting for output], 
#                   FORMAT_IO, yes)

#  #np# - These are specific to Epetra and are left only as examples.
#         If uncommented, the following line would define HAVE_ZOLTAN in
#         the (package)_config.h file.  Developers should use a more
#         specific name such as 'new_package-zoltan', rather than 'zoltan'.
# TAC_ARG_WITH_PACKAGE(zoltan, [Enable Zoltan interface support], ZOLTAN, no)
# TAC_ARG_WITH_PACKAGE(rtop, [Enable RTOp interface support], RTOP, no)

# ------------------------------------------------------------------------
# Checks if tests and examples should be built
# ------------------------------------------------------------------------

#TAC_ARG_ENABLE_FEATURE(tests, [Make tests for all Trilinos packages buildable with 'make tests'], TESTS, yes)
#AM_CONDITIONAL(BUILD_TESTS, test "X$ac_cv_use_tests" != "Xno")

#TAC_ARG_ENABLE_FEATURE(examples, [Make examples for all Trilinos packages buildable with 'make examples'], EXAMPLES, yes)
#AM_CONDITIONAL(BUILD_EXAMPLES, test "X$ac_cv_use_examples" != "Xno")

#We now build tests and examples through separate make targets, rather than
#during "make".  We still need to conditionally include the test and example
#in SUBDIRS, even though SUB_TEST and SUB_EXAMPLE will never be
#defined, so that the tests and examples are included in the distribution
#tarball.
#AM_CONDITIONAL(SUB_TEST, test "X$ac_cv_use_sub_test" = "Xyes")
#AM_CONDITIONAL(SUB_EXAMPLE, test "X$ac_cv_use_sub_example" = "Xyes")

TAC_ARG_ENABLE_FEATURE(libcheck, [Check for some third-party libraries.  (Cannot be disabled unless tests and examples are also disabled.)], LIBCHECK, yes)

# ------------------------------------------------------------------------
# Specify other directories 
# ------------------------------------------------------------------------

# enable use of --with-libdirs="-Llibdir1 -Llibdir2 ..." to prepend to LDFLAGS
TAC_ARG_WITH_LIBDIRS
# enable use of --with-incdirs="-Lincdir1 -Lincdir2 ..." to prepend to CPPFLAGS
TAC_ARG_WITH_INCDIRS

# #np# - Yet another opportunity to remove code if you aren't
# using Fortran
# Define F77_FUNC that will be used to link with Fortran subroutines.
#AC_F77_WRAPPERS

# ------------------------------------------------------------------------
# Checks for libraries
# ------------------------------------------------------------------------

# #np# - 
# To add any libraries that you want to check for, replace pow below 
# with the name of an entry point in that library.
# checks for libraries now

# If tests, examples, and libcheck are disabled, we don't have to check 
# for these libraries.
#if test "X$ac_cv_use_tests" != "Xno" || test "X$ac_cv_use_examples" != "Xno" || test "X$ac_cv_use_libcheck" != "Xno"; then
                                                                                
if test "X$ac_cv_use_libcheck" != "Xno"; then

dnl Replace `main' with a function in -lm:
#  #np# These lines can be removed if the math lib is not needed.
#AC_SEARCH_LIBS(pow,[m],,AC_MSG_ERROR(Cannot find math library))
AC_SEARCH_LIBS(sqrt,[m],,AC_MSG_ERROR(Cannot find math library))

fi 
# End of the list of libraries that don't need to be checked for if
# tests, examples, and libcheck are disabled.

# ------------------------------------------------------------------------
# Checks for compiler characteristics
# ------------------------------------------------------------------------

# ------------------------------------------------------------------------
# Checks for linker characteristics
# ------------------------------------------------------------------------

# Determine libraries needed for linking with Fortran
#AC_F77_LIBRARY_LDFLAGS


#  ----------------------------------------------------
#  Needs this because Dec handles templates differently
#  ----------------------------------------------------
#  #np# - Only uncomment the following lines if the package
#         creates a subdirectory called cxx_repository for
#         template object files on DEC.  (HINT: try to build on 
#         DEC/CPLANT and see if template-related errors occur)

# -- DEC CXX --
#if test "X$TRILINOS_TEMPLATE_OBJS" = "X"; then
#  case $target in
#    alpha*)
#      if test $CXX = cxx; then
#        TRILINOS_TEMPLATE_OBJS="cxx_repository/*.o"
#      fi
#    ;;
#  esac
#fi
                                                                  
#AC_MSG_CHECKING([for template-specific object files to be linked])if test "X$TRILINOS_TEMPLATE_OBJS" = "X"; then
# AC_MSG_RESULT(none)
#else
# AC_MSG_RESULT($TRILINOS_TEMPLATE_OBJS)
#fi
                                                                  
#AC_SUBST(TRILINOS_TEMPLATE_OBJS)

# ------------------------------------------------------------------------
# Checks for library functions
# ------------------------------------------------------------------------

# ------------------------------------------------------------------------
# Checks for system services
# ------------------------------------------------------------------------


# ------------------------------------------------------------------------
# Perform substitutions in output files
# ------------------------------------------------------------------------

AC_SUBST(ac_aux_dir)

# ------------------------------------------------------------------------
# Output files
# ------------------------------------------------------------------------
##
#  #np# - Most packages should have an example and a full suite 
#  of tests.  New package comes only with src and example.
#  You will need to change AC_CONFIG_FILES below and Makefile.am
#  to add a new directory.
AC_CONFIG_FILES([
		Makefile
		Makefile.export.claps
		src/Makefile
		])

AC_OUTPUT()

# Bye World!
#  #np# change package name
echo "----------------------------------------"
echo "Finished Running Claps Configure Script"
echo "----------------------------------------"
