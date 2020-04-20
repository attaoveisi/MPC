# =============================================================================
#  Make include file MPC_AVC_implementation_rti.mk:
#
#   RTI1005 6.2 (14-Nov-2008)
#   Wed Mar 02 15:01:05 2016
#
#   Copyright (c) 1999-2002 dSPACE GmbH, GERMANY
# =============================================================================

# Initialize variables used in blockset makefiles -----------------------------

BLOCKSET_LIBS     :=
BLOCKSET_SRCS     :=
BLOCKSET_INCLUDES :=

# Default rules for additional blocksets --------------------------------------

blockset_init  :
blockset_clean :
blockset_deps  :

# Includes for additional blocksets -------------------------------------------



# Model-specific options ------------------------------------------------------

# Additional C source files declared by the model
MDL_CUSTOM_C_SRCS = rti_assert.c rti_siggen_main.c rti_siggen_sin.c rti_siggen_sqr.c rti_siggen_saw.c rti_siggen_tri.c rti_siggen_nois.c

# Additional assembler source files declared by the model
MDL_CUSTOM_ASM_SRCS =

# Additional libraries declared by the model
MDL_CUSTOM_LIBS = \
  "$(DSPACE_ROOT)\DS1005\RTPython\dsrtt1005.lib"

# Additional objects declared by the model
MDL_CUSTOM_OBJS =

# Directories where additional C and assembler source files are stored
MDL_CUSTOM_SRCS_DIR =

# Directories where additional header files are stored
MDL_CUSTOM_INCLUDES_PATH = \
  "$(DSPACE_ROOT)\DS1005\RTPython"


# Define workingboard for download
WORKINGBOARD = ds1005

# EOF -------------------------------------------------------------------------
