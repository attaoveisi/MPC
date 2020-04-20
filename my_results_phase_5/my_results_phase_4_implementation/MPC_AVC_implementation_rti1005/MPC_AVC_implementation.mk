# =============================================================================
#  FILE:
#    MPC_AVC_implementation.mk
#
#  DESCRIPTION:
#    RTI Template Makefile:
#      Board   : DS1005
#      Version : bus/net
#      Make    : dsmake (OPUS MAKE 6.12)
#
#  REMARKS:
#
#  AUTHOR(S):
#    J. Hagendorf
#
#  (c) Copyright 2007, dSPACE GmbH. All rights reserved.
#
#  $RCSfile: MPC_AVC_implementation.mk $ $Revision: 2.29 $ $Date: 2008/07/29 14:46:45GMT+01:00 $
#  $ProjectName: e:/ARC/Products/ImplSW/RTISW/RTI/Distribution/MATLAB/RTI1005/M/project.pj $
# =============================================================================
# NEVER CHANGE THIS LINE:
# RTI_TEMPLATE_MAKEFILE_VERSION = 110
# =============================================================================

# -----------------------------------------------------------------------------
# Make configuration for whitespace support
# -----------------------------------------------------------------------------

.OPTIONS : MacroQuoted
.OPTIONS : TargetQuoted

WS_APPEND_SEMIKOLON   = W|_WS_OUTER_|, =|_WS_INNER_|,|_WS_OUTER_|= ,Q-,>;,|_WS_INNER_|= ,Q+

WS_PACK_TARGET_ARGS   = "=|_WS_DBL_QUOTE_|
WS_UNPACK_TARGET_ARGS = |_WS_DBL_QUOTE_|="

# Command to execute shell
EXEC_SHELL = -- call

# -----------------------------------------------------------------------------
# Evaluate VERBOSE mode
# -----------------------------------------------------------------------------

%ifdef VERBOSEFLAG
  .DEBUG_PRINT
  .DEBUG_RUN
% echo Windows: $(OS) Version: $(OSVERSION) Release: $(OSRELEASE)
% echo Windows: $(OS) Version: $(OSVERSION) Release: $(OSRELEASE) > CON
% exec $(MAKE) -V
% exec $(MAKE) -V >CON
% echo Running in VERBOSE mode for $(MAKEFILE) >CON
% echo Please wait ... >CON
% echo >CON
%endif

# -----------------------------------------------------------------------------
# NOTE:
#
# The user customization macros
#
#    SFCN_DIR, USER_SRCS, USER_SRCS_DIR, USER_INCLUDES_PATH, and USER_LIBS
#
# are now available from within the model-specific file model_usr.mk.
# RTI creates a template model_usr.mk file the first time a model is built.
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# RTW section: Host Environment Specifications and Customization Macros
# -----------------------------------------------------------------------------

# RTW specific environment specifications
# SECTION_DEFAULTS_RTW_BEGIN
MAKECMD                        = dsmake
HOST                           = PC
BUILD                          = yes
BUILD_SUCCESS                  = MAKE PROCESS SUCCEEDED
BUILD_ERROR                    = [sprintf('*** Make process failed while compiling, linking, or loading \n*** Detailed error messages are printed in the MATLAB Command Window\n*** Aborted RTI build procedure for model MPC_AVC_implementation')]
SYS_TARGET_FILE                = rti1005.tlc
PROJ_MARKER_FILE               = no
VERBOSE_BUILD_OFF_TREATMENT    = PRINT_OUTPUT_ALWAYS
# SECTION_DEFAULTS_RTW_END

# RTW specific customization macros
# SECTION_CUSTOMIZATION_RTW_BEGIN
MAKEFILE                       = MPC_AVC_implementation.mk
BUILDARGS                      =  GENERATE_REPORT=0 EXTMODE_STATIC_ALLOC=0 TMW_EXTMODE_TESTING=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0
MATLAB_ROOT                    = C:\Program Files\MATLAB\R2008a
MATLAB_BIN                     = C:\Program Files\MATLAB\R2008a\bin
MATLAB_ROOT_ALT                = C:\PROGRA~1\MATLAB\R2008a
MATLAB_BIN_ALT                 = C:\PROGRA~1\MATLAB\R2008a\bin
RELEASE_VERSION                = R2008a
RELEASE_VERSION               := $(RELEASE_VERSION,S'\.'_',W_,LC,S'^r'')
COMPUTER                       = PCWIN
MODEL                          = MPC_AVC_implementation
MODULES                        = MPC_AVC_implementation_data.c MPC_AVC_implementation_trc_ptr.c rt_matmultrr_dbl.c rt_nonfinite.c 
S_FUNCTIONS                    = 
S_FUNCTIONS_LIB                = 
SOLVER                         = ode5.c
NUMST                          = 2
TID01EQ                        = 1
NCSTATES                       = 5
EXT_MODE                       = 0
MULTITASKING                   = 0
# Shared library for utility code
RTW_SHARED_LIB_SRCS_WILD       = 
RTW_SHARED_LIB_SRCS_DIR        = 
RTW_SHARED_LIB_OBJS_DIR        = 
RTW_SHARED_LIB                 = 
RTW_MODELLIB                   = MPC_AVC_implementationlib.lib
RTW_MODELREF_LINK_LIBS         = 
RTW_MODELREF_TARGET_TYPE       = NONE
RTW_MODELREFS                  = 
RTW_MODELREF_INC_PATH          = 
RTW_RELATIVE_PATH_TO_ANCHOR    = ..
# SECTION_CUSTOMIZATION_RTW_END

# Deal with alternative MATLAB directory.
%if '$(MATLAB_ROOT)' != '$(MATLAB_ROOT_ALT)'
% set MATLAB_ROOT     = $(MATLAB_ROOT_ALT)
%endif
%if  '$(MATLAB_BIN)' != '$(MATLAB_BIN_ALT)'
% set MATLAB_BIN      = $(MATLAB_BIN_ALT)
%endif

# RTI specific customization macros. 
# Avoid quote characters (', ") in macro value.
# SECTION_CUSTOMIZATION_RTI_BEGIN

_TMP_OPTION_NAME                 =   BOARD
$(_TMP_OPTION_NAME)              = OPTION_DISABLED
$(_TMP_OPTION_NAME)             := $($(_TMP_OPTION_NAME),'=,"=)
%if    '$($(_TMP_OPTION_NAME))' != ''
% if   '$($(_TMP_OPTION_NAME))' == 'OPTION_DISABLED'
%   undef $(_TMP_OPTION_NAME)
% endif
%endif
%undef _TMP_OPTION_NAME


_TMP_OPTION_NAME                 =   NCLIENT
$(_TMP_OPTION_NAME)              = OPTION_DISABLED
$(_TMP_OPTION_NAME)             := $($(_TMP_OPTION_NAME),'=,"=)
%if    '$($(_TMP_OPTION_NAME))' != ''
% if   '$($(_TMP_OPTION_NAME))' == 'OPTION_DISABLED'
%   undef $(_TMP_OPTION_NAME)
% endif
%endif
%undef _TMP_OPTION_NAME


_TMP_OPTION_NAME                 =   SSCALE
$(_TMP_OPTION_NAME)              = OPTION_DISABLED
$(_TMP_OPTION_NAME)             := $($(_TMP_OPTION_NAME),'=,"=)
%if    '$($(_TMP_OPTION_NAME))' != ''
% if   '$($(_TMP_OPTION_NAME))' == 'OPTION_DISABLED'
%   undef $(_TMP_OPTION_NAME)
% endif
%endif
%undef _TMP_OPTION_NAME


CC_OPTS                          = 
CC_OPTS                         := $(CC_OPTS,'=,"=)

CC_OPT_OPTS                      = USE_DEFAULT
CC_OPT_OPTS                     := $(CC_OPT_OPTS,'=,"=)

ENABLE_DATASET_STORAGE           = OFF
ENABLE_DATASET_STORAGE          := $(ENABLE_DATASET_STORAGE,'=,"=)

ENABLE_REAL_TIME_TESTING         = OFF
ENABLE_REAL_TIME_TESTING        := $(ENABLE_REAL_TIME_TESTING,'=,"=)

RTI_ASSERTION_MODE               = OFF
RTI_ASSERTION_MODE              := $(RTI_ASSERTION_MODE,'=,"=)

SSTATE                           = RUN
SSTATE                          := $(SSTATE,'=,"=)

SMODE                            = RTSIM
SMODE                           := $(SMODE,'=,"=)

LOAD                             = ON
LOAD                            := $(LOAD,'=,"=)
# SECTION_CUSTOMIZATION_RTI_END

# Define options which are not used for referenced models.
OPTS_UNUSED_FOR_REF_MODELS = \
	LOAD \
	SMODE \
	SSTATE \
	ENABLE_REAL_TIME_TESTING \
	ENABLE_DATASET_STORAGE \
	BOARD \
	NCLIENT \
	SSCALE
	
# -----------------------------------------------------------------------------
# RTI section: Macros referenced by RTI API functions.
# -----------------------------------------------------------------------------

# Evaluate Target Type for Model Referencing.
%if '$(RTW_MODELREF_TARGET_TYPE)' == 'NONE'
   # Root Model or no Model Referencing
%  set _IS_ROOT_MODEL = 1
%else
   # Referenced Model for Model Referencing
%  undef _IS_ROOT_MODEL
%  foreach ITEM in $(OPTS_UNUSED_FOR_REF_MODELS)
%    undef $(ITEM)
%  endfor
%  undef OPTS_UNUSED_FOR_REF_MODELS
%endif

# SECTION_DEFAULTS_RTI_BEGIN
LOAD_SUCCESS        = LOADING FINISHED
DEFAULT_CC_OPT_OPTS = -Ot -Oi -Or -Ox -D_INLINE
# SECTION_DEFAULTS_RTI_END

# CC debug option for optional linking of RT debug libraries 
CC_DBG_OPT = -g

# -----------------------------------------------------------------------------
# Specification of the dSPACE hardware and software
# -----------------------------------------------------------------------------

BOARD_TYPE     = 1005
RTI_BASE_DIR   = "$(DSPACE_ROOT)\MATLAB\RTI$(BOARD_TYPE)"
RTI_SFCN_DIR   = "$(DSPACE_ROOT)\MATLAB\RTI$(BOARD_TYPE)\SFcn"
RTI_C_DIR      =  $(RTI_BASE_DIR,>\C)
RTLIB_DIR      = "$(DSPACE_ROOT)\DS$(BOARD_TYPE)\RTLib"
RTLIB_ASM_PATH = "$(DSPACE_ROOT)\DS2210\SlaveDSP\Apps"
RTK_DIR        = "$(DSPACE_ROOT)\DS$(BOARD_TYPE)\RTKernel"

# -----------------------------------------------------------------------------
# Specify processor type, object and program extensions
# -----------------------------------------------------------------------------

PROCESSOR_FAMILY    = 750
PROCESSOR_TYPE      = 50

PRG_EXT             = ppc

CC_SRC_EXT          = c
CXX_SRC_EXT         = cpp
ASM_SRC_EXT         = asm

%if $(MULTITASKING) == 1
% set CC_OBJ_EXT    = m$(PROCESSOR_TYPE)
% set ASM_OBJ_EXT   = am$(PROCESSOR_TYPE)
% set CXX_OBJ_EXT   = cppm$(PROCESSOR_TYPE)
%else
% set CC_OBJ_EXT    = o$(PROCESSOR_TYPE)
% set CXX_OBJ_EXT   = cppo$(PROCESSOR_TYPE)
% set ASM_OBJ_EXT   = ao$(PROCESSOR_TYPE)
%endif
LIBOBJ_EXT          = lo$(PROCESSOR_TYPE)

# For backwards compatibility with blockset and user makefiles 
OBJ_EXT             = $(CC_OBJ_EXT)  

# -----------------------------------------------------------------------------
# Define macro NEWLINE which expands to a newline character
# -----------------------------------------------------------------------------

NEWLINE =^

# DO NOT DELETE THE PRECEDING EMPTY LINE !

# -----------------------------------------------------------------------------
# Set RTW build directory
# -----------------------------------------------------------------------------

WORKDIR_ABS := "$(MAKEDIR,"=)"
WORKDIR_ABS :=  $(WORKDIR_ABS,>\$(RTW_RELATIVE_PATH_TO_ANCHOR),A,S'\\$$'')
WORKDIR      = $(RTW_RELATIVE_PATH_TO_ANCHOR)\\
WORKDIR_PATH = $(RTW_RELATIVE_PATH_TO_ANCHOR)

# -----------------------------------------------------------------------------
# Define temporary files
# -----------------------------------------------------------------------------

TMP_AR_OUT = _tmp_$(MODEL)_ar.txt
TMP_CC_OUT = _tmp_$(MODEL)_cc.txt
TMP_CC_MSG = _tmp_$(MODEL)_cc_msg.txt
TMP_LK_OUT = _tmp_$(MODEL)_lk.txt

TMP_FILE_LIST = $(TMP_AR_OUT) $(TMP_CC_OUT) $(TMP_CC_MSG) $(TMP_LK_OUT)

# -----------------------------------------------------------------------------
# Define the start rule of the makefile
# -----------------------------------------------------------------------------

start : make_main

# -----------------------------------------------------------------------------
# Include RTI configuration makefile and user-specific makefile extension.
# -----------------------------------------------------------------------------

# Search path for makefiles to be included
%setenv INIT = .;$(WORKDIR_PATH);

# Path setting extended by RTI blockset makefiles
BLOCKSET_INCLUDES =
BLOCKSET_SRCS_DIR =
BLOCKSET_SRCS     =
BLOCKSET_ASM_SRCS =
BLOCKSET_OBJS     =
BLOCKSET_LIBS     =

%include $(WORKDIR)$(MODEL)_usr.mk
%ifdef _IS_ROOT_MODEL
%  include         $(MODEL)_rti.mk
%else
   # Predefine macros set by $(MODEL)_rti.mk.
%  set MDL_CUSTOM_C_SRCS        =
%  set MDL_CUSTOM_ASM_SRCS      =
%  set MDL_CUSTOM_LIBS          =
%  set MDL_CUSTOM_OBJS          =
%  set MDL_CUSTOM_SRCS_DIR      =
%  set MDL_CUSTOM_INCLUDES_PATH =

   # Empty targets defined by $(MODEL)_rti.mk. 
blockset_init  :
blockset_clean :
blockset_deps  :

%endif

%ifndef USER_MAKEFILE_VERSION
%  set  USER_MAKEFILE_VERSION = 0
%endif

# Define list of all user makefile macros
%set USER_MACROS_LIST = \
	SFCN_DIR \
	USER_SRCS \
	USER_ASM_SRCS \
	USER_SRCS_DIR \
	USER_INCLUDES_PATH \
	USER_OBJS USER_LIBS

# -----------------------------------------------------------------------------
# Application type definition.
# -----------------------------------------------------------------------------

%undef  _IS_CXX_APPL
%ifdef  USER_BUILD_CPP_APPL
% if "$(USER_BUILD_CPP_APPL, UC)" == "ON"
%   set _IS_CXX_APPL = 1
% endif
%endif

# -----------------------------------------------------------------------------
# Treat User Makefile macros allowing paths.
# Need to prepend "..\" to relative paths, if build directory is used.
# -----------------------------------------------------------------------------

%set USER_MACROS_ALLOWING_PATHS = \
	SFCN_DIR \
	USER_SRCS_DIR \
	USER_INCLUDES_PATH \
	USER_OBJS \
	USER_LIBS

%foreach USER_MACRO_IN in $(USER_MACROS_ALLOWING_PATHS)
%  set USER_MACRO_OUT
%  if '$($(USER_MACRO_IN))' != ''
%    foreach ITEM in $($(USER_MACRO_IN))
%      set TMP_RELPATH_ITEM = $(ITEM,<$(WORKDIR))
%      if exists($(TMP_RELPATH_ITEM)) # ... existing item with relative path
%        set USER_MACRO_OUT += $(TMP_RELPATH_ITEM)
%      elseif exists($(ITEM)) # ... existing item with absolute path
%        set USER_MACRO_OUT += $(ITEM)
%      else # ... missing item, do not add to output list
%        ifndef USER_MACRO_WARN
%          set USER_MACRO_WARN_MESSAGE =
%          set USER_MACRO_WARN_MESSAGE +=WARNING: One or more files/directories from the User Makefile do not exist:
%          set USER_MACRO_WARN
%        endif
%        set USER_MACRO_WARN_MESSAGE +=$(NEWLINE)  -\> $(ITEM)
%      endif # if exists()
%      undef TMP_RELPATH_ITEM
%    endfor
%  endif # if null()
%  set $(USER_MACRO_IN) = $(USER_MACRO_OUT)
%endfor

# -----------------------------------------------------------------------------
# Process command option
# -----------------------------------------------------------------------------

%undef  _COMMAND_LOAD
%ifdef   COMMAND
% if  "$(COMMAND, UC)" == "LOAD"
%   set _COMMAND_LOAD = 1
% endif
%endif

# -----------------------------------------------------------------------------
# Process download options
# -----------------------------------------------------------------------------

%ifdef BOARD
%  set BOARD_OPT  = /b $(BOARD)
%  set BOARD_NAME = $(BOARD,LC)
%else
%  ifdef WORKINGBOARD
%    set BOARD_OPT  = /b workingboard
%    set BOARD_NAME = $(WORKINGBOARD,LC)
%  else
%    set BOARD_OPT  = /b ds$(BOARD_TYPE)
%    set BOARD_NAME = ds$(BOARD_TYPE)
%  endif
%endif

# -----------------------------------------------------------------------------
# Tool Definitions
# -----------------------------------------------------------------------------

COMP_ROOT = "$(PPC_ROOT,"=)"

COMP_VS_DISP =
COMP_BIN = $(COMP_ROOT,>\BIN)
COMP_LIB = $(COMP_ROOT,>\LIB)
COMP_INC = $(COMP_ROOT,>\INC)

CC  = $(COMP_BIN,>\mccppc.exe)
CXX = $(COMP_BIN,>\mccppc.exe)
AS  = $(COMP_BIN,>\asmppc.exe)
AR  = $(COMP_BIN,>\libppc.exe)
LD  = $(COMP_BIN,>\lnkppc.exe)

INCPATH_OPT     = -J
ASM_INCPATH_OPT = -I

# -----------------------------------------------------------------------------
# Shared library for utility code
# -----------------------------------------------------------------------------

%undef HAS_RTW_SHARED_LIB
RTW_SHARED_INCLUDES =
RTW_SHARED_LIB_SRCS =
RTW_SHARED_LIB_OBJS =

%if '$(RTW_SHARED_LIB_SRCS_DIR)' != ''
%  set HAS_RTW_SHARED_LIB       = 1
%  set RTW_SHARED_INCLUDES      = $(RTW_SHARED_LIB_SRCS_DIR)
%  set RTW_SHARED_LIB_SRCS      = $(RTW_SHARED_LIB_SRCS_WILD,*F)
%  set RTW_SHARED_LIB_OBJS      = $(RTW_SHARED_LIB_SRCS,S'\.$(CC_SRC_EXT)$$'.$(LIBOBJ_EXT)')
%  set RTW_SHARED_LIB_OBJS_DIR := $(RTW_SHARED_LIB_OBJS_DIR,A,"=, =|_WS_INNER_|)
%  set RTW_SHARED_LIB_OBJS     := $(RTW_SHARED_LIB_OBJS,F,<$(RTW_SHARED_LIB_OBJS_DIR,>\))
%  set RTW_SHARED_LIB_OBJS     := $(RTW_SHARED_LIB_OBJS,<",Q-,>",|_WS_INNER_|= ,Q+)
%endif

# -----------------------------------------------------------------------------
# Source files and objects
# -----------------------------------------------------------------------------

# External simulation mode sources and options --------------------------------
%if $(EXT_MODE) == 1
%  set EXT_MODE_OPTS = -DEXT_MODE
%  set EXT_MODE_SRCS = rti_external_sim.c
%else
%  set EXT_MODE_OPTS =
%  set EXT_MODE_SRCS =
%endif

# Standard Source Files -------------------------------------------------------

SIMENGINE = rti_sim_engine

%ifndef _IS_CXX_APPL
% set RTI_INIT_SRC = rti_init_c.c
%else
% set RTI_INIT_SRC = rti_init_cpp.c
%endif # _IS_CXX_APPL

%ifdef _IS_ROOT_MODEL
   # Standard Sources for Root Model
STD_SRCS = \
	 $(MODEL).c \
	 $(MODULES) \
	 $(SIMENGINE).c \
	 $(RTI_INIT_SRC) \
	 rt_sim.c
%else
   # Standard Sources for Referenced Model
STD_SRCS = \
	 $(MODULES)
%endif

MODULES += \
	$(EXT_MODE_SRCS)

# Sources which dependent on compiler defines from the makefile ---------------

%ifdef _IS_ROOT_MODEL
%  set MAKEFILE_DEP_SRCS = rt_sim.c
%  set MAKEFILE_DEP_OBJS = $(MAKEFILE_DEP_SRCS,S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)')
%else
%  set MAKEFILE_DEP_OBJS =
%endif

# Sources and objects for RTW Custom Run-Time libraries -------------------

# List of RTW Custom Run-Time Libraries and related sources.

RTWCUST_LIBS             =
RTWCUST_LIB_SRCS         =
RTWCUST_LIB_OBJS         =
RTWCUST_PRECOMP_LIBS     =

RTWCUST_LIB_PLATFORM_EXT = _r$(RELEASE_VERSION)_ds$(BOARD_TYPE)

# RTW Custom Run-Time Libraries from rtwmakecfg.m (to be built).


# RTW Custom Run-Time Libraries from rtwmakecfg.m (pre-compiled).

# Assembler sources -----------------------------------------------------------

ASM_SRCS = $(BLOCKSET_ASM_SRCS) $(MDL_CUSTOM_ASM_SRCS) $(USER_ASM_SRCS)

# Define objects --------------------------------------------------------------

STD_OBJS           = $(STD_SRCS,         S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
MODULE_OBJS        = $(MODULES,          S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
BLOCKSET_C_OBJS    = $(BLOCKSET_SRCS,    S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
SFCN_OBJS          = $(S_FUNCTIONS,      S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
USER_SRCS_OBJS     = $(USER_SRCS,        S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
MDL_CUSTOM_C_OBJS  = $(MDL_CUSTOM_C_SRCS,S'\.$(CC_SRC_EXT)$$'.$(CC_OBJ_EXT)',S'\.$(CXX_SRC_EXT)$$'.$(CXX_OBJ_EXT)')
# RTWCUST_LIB_OBJS defined above
ASM_OBJS           = $(ASM_SRCS,         S'\.$(ASM_SRC_EXT)$$'.$(ASM_OBJ_EXT)')

# All objects to be built.
ALL_OBJS  = $(STD_OBJS) $(BLOCKSET_C_OBJS) $(BLOCKSET_OBJS) $(SFCN_OBJS) \
	    $(USER_SRCS_OBJS) $(RTWCUST_LIB_OBJS) \
	    $(MDL_CUSTOM_C_OBJS) $(MDL_CUSTOM_OBJS) $(ASM_OBJS)

# Define output files ---------------------------------------------------------

%ifdef _IS_ROOT_MODEL
%  set PROGRAM = $(WORKDIR)$(MODEL).$(PRG_EXT)
%  set SDFFILE = $(WORKDIR)$(MODEL).sdf
%  set MAPFILE = $(WORKDIR)$(MODEL).map
%else
%  set PRODUCT = $(RTW_MODELLIB)
%endif

# -----------------------------------------------------------------------------
# Libraries
# -----------------------------------------------------------------------------

# RTWCUST_LIBS and RTWCUST_PRECOMP_LIBS defined above

%ifdef _IS_ROOT_MODEL
%  set CC_OPT_TMP = $(CC_OPT_OPTS) $(CC_OPTS)
#  if compiler options contain the debug option, define the according debug library to be linked against  
%  if '$(CC_OPT_TMP,M^$(CC_DBG_OPT)$$)' == ''
%    set DSPACE_RTLIBS = $(RTLIB_DIR,>\ds$(BOARD_TYPE).lib)
%  else
%    set DSPACE_RTLIBS = $(RTLIB_DIR,>\ds$(BOARD_TYPE)dbg.lib)
%  endif
%  set DSPACE_LIBS = \
	$(BLOCKSET_LIBS) \
	$(MDL_CUSTOM_LIBS) \
	$(RTK_DIR,>\rtk$(BOARD_TYPE).lib) \
	$(DSPACE_RTLIBS)
	
%  undef DSPACE_RTLIBS
%  undef CC_OPT_TMP
%else
%  set DSPACE_LIBS = \
	$(MDL_CUSTOM_LIBS)
%endif

%ifdef _IS_ROOT_MODEL
%  set CC_LIBS = \
	$(COMP_LIB,>\mppc_b.lib) \
	$(COMP_LIB,>\mppchb.lib)

%  set CXX_LIBS = \
	$(COMP_LIB,>\cppcnhb.lib) \
	$(CC_LIBS)

%  ifndef _IS_CXX_APPL
%    set COMPILER_LIBS = $(CC_LIBS)
%  else
%    set COMPILER_LIBS = $(CXX_LIBS)
%  endif # _IS_CXX_APPL
%else
%  set COMPILER_LIBS =
%endif # _IS_ROOT_MODEL

%ifdef _IS_ROOT_MODEL
  # Define input files for application.
PROGRAM_LINK_OBJS  = \
	                $(USER_SRCS_OBJS) \
	                $(USER_OBJS) \
	                $(SFCN_OBJS) \
	                $(STD_OBJS) \
	                $(BLOCKSET_OBJS) \
	                $(BLOCKSET_C_OBJS) \
	                $(MDL_CUSTOM_OBJS) \
	                $(MDL_CUSTOM_C_OBJS) \
	                $(ASM_OBJS)

PROGRAM_LINK_LIBS  = \
	                $(USER_LIBS) \
	                $(DSPACE_LIBS) \
	                $(S_FUNCTIONS_LIB) \
	                $(RTW_SHARED_LIB) \
	                $(RTWCUST_LIBS) \
	                $(RTWCUST_PRECOMP_LIBS) \
	                $(RTW_MODELREF_LINK_LIBS) \
	                $(COMPILER_LIBS)

%else
  # Define contents of RTW model library.
PRODUCT_LIB_OBJS  = \
	                $(USER_SRCS_OBJS) \
	                $(USER_OBJS) \
	                $(SFCN_OBJS) \
	                $(STD_OBJS) \
	                $(BLOCKSET_OBJS) \
	                $(BLOCKSET_C_OBJS) \
	                $(MDL_CUSTOM_OBJS) \
	                $(MDL_CUSTOM_C_OBJS) \
	                $(ASM_OBJS)

PRODUCT_LIB_LIBS  = \
	                $(USER_LIBS) \
	                $(S_FUNCTIONS_LIB)
%endif

# -----------------------------------------------------------------------------
# Tool options
# -----------------------------------------------------------------------------

# Compiler options ------------------------------------------------------------

# C compiler options always required
CC_REQ_OPTS  = -KE  -nKu -nKv -nKia -p$(PROCESSOR_FAMILY) -o $(.TARGET)
CXX_REQ_OPTS = -KLi1  $(CC_REQ_OPTS)

# C compiler options
%ifndef CC_OPTS
%  set  CC_OPTS =
%endif

# C compiler optimization options
OPT_OPTS = $(DEFAULT_CC_OPT_OPTS)
%ifdef CC_OPT_OPTS
%  if '$(CC_OPT_OPTS)' == 'USE_NONE'
%    set OPT_OPTS = -nO
%  elseif '$(CC_OPT_OPTS)' != 'USE_DEFAULT' 
%    set OPT_OPTS = $(CC_OPT_OPTS)
%  endif
%endif

# Compiler message options (command line option precedes)
# C0001 (info) : last line of file ends without a newline
# C0111 (warn) : statement is unreachable
# C0177 (info) : function | variable | parameter "..." was declared but never referenced
# C0186 (info) : pointless comparison of unsigned integer with zero
# C0188 (warn) : enumerated type mixed with another type
# C0191 (info) : type qualifier is meaningless on cast type
# C0193 (info) : zero used for undefined preprocessing identifier
# C0223 (warn) : function declared implicitly
# C0233 (err)  : left operand is not a struct or union containing this field
# C0236 (info) : controlling expression is constant
# C0237 (info) : selector expression is constant
# C0260 (warn) : explicit type is missing ("int" assumed)
# C0340 (info) : value copied to temporary, reference to temporary used
# C0381 (info) : extra ";" ignored
# C0514 (info) : pointless comparison of unsigned integer with a negative constant
# C0550 (warn) : variable "..." was set but never used
# C0826 (info) : variable "..." was never referenced
# 
MSG_OPTS = -nQi -QmsC0001 -Qms0111 -QmsC0177 -QmsC0186 -QmsC0188 -QmsC0191 -QmsC0193 -QmwC0223 -QmeC0233 -QmsC0236 -QmsC0237 -QmwC0260 -QmsC0340 -QmsC0381 -QmsC0514 -Qms0550 -QmsC0826

# Debugging options (command line option precedes)
DBG_OPTS =

# Simulation mode options
%ifdef SSTATE
%  set SSTATE_OPT = -DSSTATE=$(SSTATE)
%else
%  set SSTATE_OPT =
%endif

%ifdef SMODE
%  set SMODE_OPT = -DSMODE=$(SMODE)
%else
%  set SMODE_OPT =
%endif
%ifdef SSCALE
%  set SSCALE_OPT = -DRTI_TIMER_TASK_TIME_SCALE=$(SSCALE)
%else
%  set SSCALE_OPT =
%endif

# RTI assertion mode options
ASSERTION_DEFINE_VALUE = RTI_ASSERTION_MODE_OFF
%ifdef RTI_ASSERTION_MODE
% if member($(RTI_ASSERTION_MODE,UC), OFF WARN STOP)
%   set ASSERTION_DEFINE_VALUE = RTI_ASSERTION_MODE_$(RTI_ASSERTION_MODE,UC)
% endif
%endif
ASSERTION_DEFINE = -DRTI_ASSERTION_MODE=$(ASSERTION_DEFINE_VALUE)

DEFINE_OPTS = \
	$(SSTATE_OPT) \
	$(SMODE_OPT) \
	$(SSCALE_OPT) \
	$(EXT_MODE_OPTS) \
	# For model-wide information use rtModel data-structure instead of simStruct. \
	-DUSE_RTMODEL \
	-DMODEL=$(MODEL) \
	-DMT=$(MULTITASKING) \
	-DRT \
	-DNUMST=$(NUMST) \
	-DNCSTATES=$(NCSTATES) \
	-DTID01EQ=$(TID01EQ) \
	-DNO_PRINTF \
	-D$(BOARD_NAME) \
	-D_DS$(BOARD_TYPE) \
	-DRTI_BUILD \
	$(ASSERTION_DEFINE)

%ifndef _IS_ROOT_MODEL 
%  ifdef _IS_CXX_APPL
%    set DEFINE_OPTS += -DRTI_CXX_ENABLED
%  endif
%endif

%ifdef _IS_ROOT_MODEL
%  if "$(ENABLE_DATASET_STORAGE,UC)" == "ON"
%    set DEFINE_OPTS += -DENABLE_DATASET_STORAGE
%  endif

%  if "$(ENABLE_REAL_TIME_TESTING,UC)" == "ON"
%    set DEFINE_OPTS += -DRTT_ENABLE
%  endif
%endif

# RTW Custom Include paths from rtwmakecfg.m.
RTWCUST_INCLUDES = \
	$(MATLAB_ROOT)\rtw\c\src\matrixmath \
	D:\Oveisi\Model_Predictive_Control\my_results_phase_4_implementation\MPC_AVC_implementation_rti1005 \
	D:\Oveisi\Model_Predictive_Control\my_results_phase_4_implementation \
	$(MATLAB_ROOT)\rtw\c\libsrc
# End: Custom Include paths.

MATLAB_INCLUDES = \
	$(MATLAB_ROOT,>\simulink\include) \
	$(MATLAB_ROOT,>\extern\include) \
	$(MATLAB_ROOT,>\rtw\c\src) \
	$(MATLAB_ROOT,>\rtw\c\src\ext_mode\common) \
	$(RTWCUST_INCLUDES) \
	$(RTW_SHARED_INCLUDES) \
	$(RTW_RELATIVE_PATH_TO_ANCHOR) \
	$(RTW_MODELREF_INC_PATH)

DSPACE_INCLUDES = \
	$(RTK_DIR) \
	$(RTLIB_DIR) \
	$(RTI_C_DIR) \
	$(RTI_SFCN_DIR)

INCLUDES = \
	. \
	$(WORKDIR_PATH) \
	$(MDL_CUSTOM_INCLUDES_PATH) \
	$(SFCN_DIR) \
	$(USER_INCLUDES_PATH) \
	$(COMP_INC) \
	$(DSPACE_INCLUDES) \
	$(BLOCKSET_INCLUDES) \
	$(MATLAB_INCLUDES)
	
INCLUDES := $(INCLUDES,S'\\$$'')

%foreach INCPATH in $(INCLUDES)
%  set INCLUDE_PATH += $(INCPATH_OPT)$(INCPATH)
%end

CC_FLAGS  = $(CC_REQ_OPTS)  $(MSG_OPTS) $(OPT_OPTS) $(CC_OPTS) $(DBG_OPTS) $(DEFINE_OPTS) $(INCLUDE_PATH)
CXX_FLAGS = $(CXX_REQ_OPTS) $(MSG_OPTS) $(OPT_OPTS) $(CC_OPTS) $(DBG_OPTS) $(DEFINE_OPTS) $(INCLUDE_PATH)

# Assembler options -----------------------------------------------------------

# Assembler options (command line option precedes)
ASM_OPTS        = 
ASM_INCLUDES = \
	. \
	$(WORKDIR_PATH) \
	$(RTLIB_ASM_PATH) \
	$(USER_INCLUDES_PATH)

%foreach ASMINCPATH in $(ASM_INCLUDES)
%  set ASM_INCLUDE_PATH += $(ASM_INCPATH_OPT)$(ASMINCPATH)
%end

ASM_REQ_OPTS    = -p$(PROCESSOR_FAMILY)
ASM_DEFINE_OPTS = -DDS_BOARD_TYPE=$(BOARD_TYPE)
AS_OPTS         = $(ASM_REQ_OPTS) $(ASM_OPTS) $(ASM_DEFINE_OPTS) \
                  $(ASM_INCLUDE_PATH)
ASM_CMD_LINE    = $(AS_OPTS) -o $(.TARGET) $(.SOURCE)

# Linker options --------------------------------------------------------------

# Debugging option for linker
LNK_DBG_OPTS =

# -----------------------------------------------------------------------------
# Search path for make utility
# -----------------------------------------------------------------------------

.PATH.h     := $(INCLUDES,$(WS_APPEND_SEMIKOLON))

TMP_PATH_CC  = .
TMP_PATH_CC += $(WORKDIR_PATH)
TMP_PATH_CC += $(MDL_CUSTOM_SRCS_DIR)
TMP_PATH_CC += $(SFCN_DIR)
TMP_PATH_CC += $(USER_SRCS_DIR)
TMP_PATH_CC += $(RTI_C_DIR)
TMP_PATH_CC += $(RTI_SFCN_DIR)
TMP_PATH_CC += $(BLOCKSET_SRCS_DIR)
TMP_PATH_CC += $(RTLIB_DIR)
TMP_PATH_CC += $(MATLAB_ROOT,>\rtw\c\src)
# RTW Custom Source paths from rtwmakecfg.m.
TMP_PATH_CC += $(MATLAB_ROOT)\rtw\c\src\matrixmath
TMP_PATH_CC += $(MATLAB_ROOT)\rtw\c\src
# End: Custom Source paths.
TMP_PATH_CC += $(MATLAB_ROOT,>\simulink\src)

.PATH.$(CC_SRC_EXT)  := $(TMP_PATH_CC,$(WS_APPEND_SEMIKOLON))
%undef TMP_PATH_CC

%ifdef _IS_CXX_APPL
.PATH.$(CXX_SRC_EXT) := $(.PATH.$(CC_SRC_EXT))
%endif # _IS_CXX_APPL

TMP_PATH_ASM = .
TMP_PATH_ASM += $(WORKDIR_PATH)
TMP_PATH_ASM += $(BLOCKSET_SRCS_DIR)
TMP_PATH_ASM += $(MDL_CUSTOM_SRCS_DIR)
TMP_PATH_ASM += $(RTLIB_ASM_PATH)
TMP_PATH_ASM += $(USER_SRCS_DIR)

.PATH.$(ASM_SRC_EXT) := $(TMP_PATH_ASM,$(WS_APPEND_SEMIKOLON))
%undef TMP_PATH_ASM

# =============================================================================
# Rules
# =============================================================================

# -----------------------------------------------------------------------------
# First rule of the makefile
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL
%  ifdef _COMMAND_LOAD
make_main : start_check                                            download make_success_quiet
%  else
make_main : start_check init compile_deps link             cleanup download make_success
%  endif
%else # _IS_ROOT_MODEL
make_main : start_check init compile_deps      mdl_ref_lib cleanup          make_success
%endif

# -----------------------------------------------------------------------------
# Standard message rules
# -----------------------------------------------------------------------------

make_success_quiet :
	%abort 0

make_abort_quiet :
	%abort

make_success :
	%echo
	%echo $(BUILD_SUCCESS)
	%ifdef VERBOSEFLAG
	  %echo $(BUILD_SUCCESS) > CON
	%endif
	%echo

make_abort :
	%echo
	%echo MAKE PROCESS ABORTED
	%ifdef VERBOSEFLAG
	  %echo MAKE PROCESS ABORTED  > CON
	%endif
	%echo
	%abort

# -----------------------------------------------------------------------------
# Start rule (messages and checks)
# -----------------------------------------------------------------------------

start_check :
	%ifndef _COMMAND_LOAD
	  %echo
	  %ifdef _IS_ROOT_MODEL
	    %if $(MULTITASKING) == 1
	      %echo BUILDING APPLICATION "$(MODEL)" (Multiple Timer Task Mode)
	    %else
	      %echo BUILDING APPLICATION "$(MODEL)" (Single Timer Task Mode)
	    %endif # MULTITASKING
	  %else
	    %echo BUILDING REFERENCED MODEL "$(MODEL)"
	  %endif # _IS_ROOT_MODEL
	  %echo
	  %echo WORK  DIRECTORY "$(WORKDIR_ABS,"=)"
	  %echo BUILD DIRECTORY "$(MAKEDIR,"=)"
	  %ifdef HAS_RTW_SHARED_LIB
	    %echo SHARED LOCATION "$(RTW_SHARED_LIB_SRCS_DIR,A,"=)"
	  %endif
	  %echo TARGET COMPILER "$(COMP_ROOT,"=)" $(COMP_VS_DISP)
	  %echo
	%endif # !_COMMAND_LOAD
	%if !(exists("$(CC,"=)") && exists("$(AS,"=)") && exists("$(LD,"=)") && exists("$(AR,"=)"))
	  %echo ERROR: Cannot find PPC compiler. Possible reasons are:
	  %echo        - Compiler not installed.
	  %echo        - Environment variable PPC_ROOT not defined.
	  %echo        - Environment variable PPC_ROOT points to wrong directory.
	  %do make_abort
	%endif
	%if !(dir($(MATLAB_BIN)))
	  %echo ERROR: MATLAB root directory not found.
	  %echo        The MATLAB root directory was supposed to be at
	  %echo          $(MATLAB_ROOT)
	  %echo        but no longer is available there. If this model was
	  %echo        generated on another environment rebuild the model.
	  %do make_abort
	%endif
	%if ($(USER_MAKEFILE_VERSION) != 1) && ($(USER_MAKEFILE_VERSION) != 2)
	  %echo ERROR: User makefile $(MODEL)_usr.mk has a version
	  %echo        incompatible to this makefile: $(USER_MAKEFILE_VERSION)
	  %echo        Please use a new template.
	  %do make_abort
	%endif
	%if $(USER_MAKEFILE_VERSION) < 2
	  %echo INFO: User makefile $(MODEL)_usr.mk comes from an older RTI version.
	  %echo       - Use a new template to get access to all available options.
	  %echo       - If you do not make use of the options of the user makefile,
	  %echo         you can delete $(MODEL)_usr.mk and rebuild the model to
	  %echo         suppress this message.
	  %echo
	%endif
	%ifdef BOARD
	  %if "$(BOARD)" == ""
	    %echo ERROR: Make option BOARD is set but its value is empty.
	    %do make_abort
	  %endif
	%endif
	%ifdef NCLIENT
	  %if "$(NCLIENT)" == ""
	    %echo ERROR: Make option NCLIENT is set but its value is empty.
	    %do make_abort
	  %endif
	%endif
	%ifdef NCLIENT
	  %ifndef BOARD
	    %echo ERROR: Missing board name. If you specify a network
	    %echo        client, you must specify a board name, too.
	    %echo        Example: NCLIENT=$(NCLIENT) BOARD=ds$(BOARD_TYPE).
	    %do make_abort
	  %endif
	%endif
	%ifdef LOAD
	  %if !member($(LOAD), ON OFF FLASH)
	    %echo ERROR: Invalid LOAD option '$(LOAD)' specified.
	    %echo        Select one of ON, OFF or FLASH.
	    %do make_abort
	  %endif
	%endif
	%ifdef SSTATE
	  %if !member($(SSTATE), STOP PAUSE RUN)
	    %echo ERROR: Invalid SSTATE option '$(SSTATE)' specified.
	    %echo        Select one of STOP, PAUSE or RUN.
	    %do make_abort
	  %endif
	%endif
	%ifdef SMODE
	  %if !member($(SMODE), RTSIM NRTSIM NRTSIM_SCALED)
	    %echo ERROR: Invalid SMODE option '$(SMODE)' specified.
	    %echo        Select one of RTSIM, NRTSIM or NRTSIM_SCALED.
	    %do make_abort
	  %endif
	%endif
	%ifdef SSCALE
	  %if (!defined(SMODE)) || ("$(SMODE)" != "NRTSIM_SCALED")
	    %echo ERROR: Missing or incorrect SMODE option. To use the SSCALE
	    %echo        option, you must set the option SMODE=NRTSIM_SCALED.
	    %do make_abort
	    %endif
	%endif
	%ifdef OPTS
	  %echo ERROR: Make argument OPTS is no longer supported.
	  %echo        Refer to the RTI and RTI-MP Implementation Reference about
	  %echo        specifying compiler options.
	  %do make_abort
	%endif
	%set USER_MK_MSG = DEFINITIONS FROM USER MAKEFILE "$(MODEL)_usr.mk" ...
	%foreach USER_MACRO in $(USER_MACROS_LIST)
	  %if '$($(USER_MACRO))' != ''
	    %set USER_MK_MSG_PRINT = 1
	    %set USER_MK_MSG +=$(NEWLINE)  $(USER_MACRO) = $($(USER_MACRO))
	  %endif
	%endfor
	%if defined(USER_MK_MSG_PRINT)
	  %echo $(USER_MK_MSG)
	  %echo
	%endif
	%if defined(USER_MACRO_WARN_MESSAGE)
	  %echo $(USER_MACRO_WARN_MESSAGE)
	  %echo
	%endif

# -----------------------------------------------------------------------------
# Initialization rules
# -----------------------------------------------------------------------------

init : make_init blockset_init

make_init :
	%ifdef _IS_ROOT_MODEL
	  %do delete_file FILE_LIST="$(PROGRAM,$(WS_PACK_TARGET_ARGS)) $(MAPFILE,$(WS_PACK_TARGET_ARGS))"
	%endif
	%ifdef COMPALL
	  %if '$(COMPALL, UC)' == 'ON'
	    %do delete_file FILE_LIST="$(ALL_OBJS,$(WS_PACK_TARGET_ARGS)) $(RTWCUST_LIBS,$(WS_PACK_TARGET_ARGS))"
	  %endif
	%endif

# -----------------------------------------------------------------------------
# Rules to build the program
# -----------------------------------------------------------------------------

compile_deps : \
	model_deps \
	simengine_deps \
	$(STD_OBJS) \
	blockset_deps \
	$(BLOCKSET_C_OBJS)  \
	$(SFCN_OBJS) \
	$(USER_SRCS_OBJS) \
	$(MDL_CUSTOM_C_OBJS) \
	$(ASM_OBJS) \
	$(RTW_SHARED_LIB_OBJS) \
	$(RTWCUST_LIB_OBJS) \
	$(RTW_SHARED_LIB) \
	$(RTWCUST_LIBS) \
	$(RTWCUST_PRECOMP_LIBS)

# -----------------------------------------------------------------------------
# Link rules
# -----------------------------------------------------------------------------

link :
	%echo
	%echo LINKING APPLICATION ...
	%set APL_LK = $(WORKDIR)$(MODEL).lk
	%set TMP_LK = _tmp_$(APL_LK,F)
	%do link_build_objectlist
	%if exists($(APL_LK))
	  %echo Using local linker command file "$(APL_LK,F)"
	  copy >NUL $(APL_LK) $(TMP_LK)
	%else
	  copy >NUL $(RTLIB_DIR,>\ds$(BOARD_TYPE).lk) $(TMP_LK)
	%endif
	%do link_program
	%echo LINKING FINISHED

link_build_objectlist :
	%set OBJ_PRE = LOAD
	%set LIB_PRE = LOAD
	%foreach OBJ in $(PROGRAM_LINK_OBJS)
	  %set LK_OBJS +=$(OBJ_PRE) $(OBJ)$(NEWLINE)
	%endfor
	%foreach LIB in $(PROGRAM_LINK_LIBS)
	  %set LK_OBJS +=$(LIB_PRE) $(LIB)$(NEWLINE)
	%endfor
	
link_program :
	%echo $(LK_OBJS) >> $(TMP_LK)
	%ifndef LNK_OPTS
	  %set LNK_OPTS =  -QmsA0314
	%endif
	%echo $(EXEC_SHELL) "$(LD,"=)" $(LNK_DBG_OPTS) $(LNK_OPTS) -m $(MAPFILE) -o $(PROGRAM) -c $(TMP_LK)\
	  > $(TMP_LK_OUT)
    $(EXEC_SHELL) "$(LD,"=)" $(LNK_DBG_OPTS) $(LNK_OPTS) -m>$(MAPFILE) -o $(PROGRAM) -c $(TMP_LK)
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_LK_OUT)
	  %echo LINKING FAILED $(LINKPRG_MSG)($(_STATUS))
	  %do make_abort
	%endif
# -----------------------------------------------------------------------------
# Clean up rules
# -----------------------------------------------------------------------------

cleanup : make_clean blockset_clean

make_clean :
	%undef CLEANUP_ON
	%ifdef CLEANUP
	  %if '$(CLEANUP)' == 'ON'
	    %set CLEANUP_ON
	  %endif
	%endif
	%ifdef CLEANUP_ON
	  %do delete_file FILE_LIST="$(TMP_LK,$(WS_PACK_TARGET_ARGS)) $(TMP_FILE_LIST,$(WS_PACK_TARGET_ARGS))"
	%endif

delete_file :
	%set FILE_LIST = $(FILE_LIST,$(WS_UNPACK_TARGET_ARGS))
	%foreach ITEM in $(FILE_LIST)
	  %if exists($(ITEM))
	    del $(ITEM) >NUL
	  %endif
	%endfor

# -----------------------------------------------------------------------------
# Download rule
# -----------------------------------------------------------------------------

download :
	%ifdef LOAD
	  %set LOAD_OPT = $(LOAD,UC)
	%else
	  %set LOAD_OPT = ON
	%endif
	%if ('$(LOAD_OPT)' == 'ON') || ('$(LOAD_OPT)' == 'FLASH')
	  %set LOAD_MSG =
	  # COMMAND LOAD
	  %ifdef _COMMAND_LOAD

	    %set LOAD_MSG := $(LOAD_MSG) ("$(WORKDIR_ABS,"=)")
	  %endif
	  # FLASH
	  %set FLASH_OPT =
	  %if '$(LOAD_OPT)' == 'FLASH'
	    %set FLASH_OPT = /fl
	    %set LOAD_MSG := $(LOAD_MSG) INTO FLASH MEMORY
	  %endif
	  # DOTDOTDOT
	  %set LOAD_MSG := $(LOAD_MSG) ...
	  # BOARD
	  %ifdef BOARD
	    %set LOAD_MSG := $(LOAD_MSG)$(NEWLINE)  BOARD:      $(BOARD_NAME)
	  %endif
	  # NCLIENT
	  %set NET_OPT =
	  %ifdef NCLIENT
	    %set NET_OPT = /c $(NCLIENT)
	    %set LOAD_MSG := $(LOAD_MSG)$(NEWLINE)  NCLIENT:    $(NCLIENT)
	  %endif
	  # SLAVE
	  %set SLAVE_OPT =
	  %echo
	  %echo LOADING APPLICATION "$(SDFFILE,F)" $(LOAD_MSG)
	  --scoutcmd /OL 2 $(FLASH_OPT) $(BOARD_OPT) $(SDFFILE) $(SLAVE_OPT) $(NET_OPT)
	  %if $(status)
	    %set LOADFAILED_MSG = 
	    %if $(status) == 1
	      %set LOADFAILED_MSG = : Error during download to the hardware.
	    %elseif $(status) == 2
	      %set LOADFAILED_MSG = : Program has set an error message.
	    %endif
	    %echo LOADING FAILED ($(status))$(LOADFAILED_MSG)
	    %ifdef _COMMAND_LOAD
	      %do make_abort_quiet
	    %else
	      %do make_abort
	    %endif
	  %endif
	  %echo $(LOAD_SUCCESS)
	%endif

# -----------------------------------------------------------------------------
# Rules for the simulation engine
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL

  # Root model.
simengine_deps : simengine_init $(SIMENGINE).$(CC_OBJ_EXT)

simengine_init :
	%if defined(SMODE) && exists($(SIMENGINE).$(CC_OBJ_EXT))
	  %do delete_file FILE_LIST=$(SIMENGINE).$(CC_OBJ_EXT)
	%endif
	%if defined(SSTATE) && exists($(SIMENGINE).$(CC_OBJ_EXT))
	  %do delete_file FILE_LIST=$(SIMENGINE).$(CC_OBJ_EXT)
	%endif

%if exists($(WORKDIR)$(MODEL).ddc)
$(SIMENGINE).$(CC_OBJ_EXT) : $(WORKDIR)$(MODEL).ddc
%endif

$(SIMENGINE).$(CC_OBJ_EXT) : $(SIMENGINE).c \
							 $(MODEL).h \
							 rtModel.h \
							 $(MODEL)_usr.c \
							 $(MODEL)_rti.c \
							 $(MODEL)_th.c \
							 rt_nonfinite.h \
							 $(MAKEFILE)

%else # _IS_ROOT_MODEL

  # Referenced model.
simengine_deps :

%endif # _IS_ROOT_MODEL

# -----------------------------------------------------------------------------
# Rules for the model
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL

  # Root model.
model_deps : $(MODEL).$(CC_OBJ_EXT) $(MODULE_OBJS)

$(MODEL).$(CC_OBJ_EXT) $(MODULE_OBJS) : $(MODEL).c \
										$(MODEL).h \
										rtModel.h \
										$(MAKEFILE)

%else # _IS_ROOT_MODEL

  # Referenced model.
model_deps :

%endif # _IS_ROOT_MODEL

# -----------------------------------------------------------------------------
# Rules for referenced models (ref. model library)
# -----------------------------------------------------------------------------

%ifdef _IS_ROOT_MODEL
%else # _IS_ROOT_MODEL
mdl_ref_lib : $(PRODUCT)

$(PRODUCT) : $(PRODUCT_LIB_OBJS) $(PRODUCT_LIB_LIBS)
  %do build_library  _LIB_NAME="$(.TARGET,$(WS_PACK_TARGET_ARGS))" _LIB_FILES="$(PRODUCT_LIB_LIBS,$(WS_PACK_TARGET_ARGS))"

%endif # _IS_ROOT_MODEL
# -----------------------------------------------------------------------------
# Rules for the model library
# -----------------------------------------------------------------------------

# Common library archiving roule
build_library :
	%set _LIB_NAME = $(_LIB_NAME,$(WS_UNPACK_TARGET_ARGS))
	%if defined(_LIB_FILES)
	  %set _LIB_FILES = $(_LIB_FILES,$(WS_UNPACK_TARGET_ARGS))
	%else
	  %set _LIB_FILES =
	%endif
	%ifndef BUILD_MSG_SEP_SPACE
	  # Additional newline to separate from COMPILING messages
	  %echo
	  %set BUILD_MSG_SEP_SPACE
	%endif

	# Create librarian/archiver command file
	%set LIB_CMD_LIST_FILE   = $(_LIB_NAME,B)_cmd.lst
	# Create library
	%set LIB_CREATE_CMD      = CREATE
	%if exists($(_LIB_NAME))
	  # make sure that the libs are always created
	  %do delete_file FILE_LIST="$(_LIB_NAME,$(WS_PACK_TARGET_ARGS))"
	%endif
	%echo $(LIB_CREATE_CMD) $(_LIB_NAME)       >  $(LIB_CMD_LIST_FILE)
	%foreach ITEM in $(.SOURCES)
	  %if member($(ITEM),$(_LIB_FILES))
	    %echo ADDLIB  $(ITEM)                  >> $(LIB_CMD_LIST_FILE)
	  %else
	    %echo REPLACE  $(ITEM)                 >> $(LIB_CMD_LIST_FILE)
	  %endif
	%endfor
	%echo SAVE                                 >> $(LIB_CMD_LIST_FILE)
	%echo QUIT                                 >> $(LIB_CMD_LIST_FILE)

	%echo
	%echo BUILDING LIBRARY "$(_LIB_NAME,F)" ...
	%set AR_CMD := "$(AR,"=)" -QmsA0107,A0201,A0211 < $(LIB_CMD_LIST_FILE)
	%echo $(AR_CMD,S'<'\\<')  >  $(TMP_AR_OUT)
	    $(EXEC_SHELL) $(AR_CMD)  >> $(TMP_AR_OUT) 2>>&1
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_AR_OUT)
	  %echo ARCHIVER FAILED ($(_STATUS))
	  %do delete_file FILE_LIST=$(_LIB_NAME)
	  %do make_abort
	%endif
	# Generate a table of contents.
	$(EXEC_SHELL) "$(AR,"=)" -f s $(_LIB_NAME) > $(_LIB_NAME,B)_lib_tbl.txt 2>>&1
	%echo BUILDING LIBRARY FINISHED



# -----------------------------------------------------------------------------
# Rules for shared library for utility code
# -----------------------------------------------------------------------------

%ifdef HAS_RTW_SHARED_LIB

$(RTW_SHARED_LIB_OBJS) : $(RTW_SHARED_LIB_SRCS_DIR,>\$(%,B).$(CC_SRC_EXT))
	%undef COMP_LIB_MSG_OUTPUT
	%do comp_lib_sources _LIB_NAME=$(RTW_SHARED_LIB)

$(RTW_SHARED_LIB) : $(RTW_SHARED_LIB_OBJS)
	%do build_library    _LIB_NAME=$(.TARGET)
%endif


# -----------------------------------------------------------------------------
# Rules for the additional RTW run-time libraries (dynamically expanded)
# -----------------------------------------------------------------------------

# RTW Custom Run-Time Libraries from rtwmakecfg.m (to be built).


# RTW Custom Run-Time Libraries from rtwmakecfg.m (pre-compiled).


# -----------------------------------------------------------------------------
# General compile rules
# -----------------------------------------------------------------------------

%.$(CC_OBJ_EXT) : %.$(CC_SRC_EXT)
	%do comp_rule

comp_rule :
	%echo > $(TMP_CC_MSG)
	%echo -n > $(TMP_CC_OUT)
	%ifndef CC_MSG
	  %set CC_MSG =
	%endif
    %set CC_CMD = "$(CC,"=)" -c $(CC_FLAGS) $(.SOURCE)
	%ifndef CC_MSG_QUIET
	  %echo COMPILING  "$(.SOURCE,"=)" $(CC_MSG)
	  $(EXEC_SHELL) $(CC_CMD)
	%else
	  %echo COMPILING  "$(.SOURCE,"=)" $(CC_MSG) >> $(TMP_CC_MSG)
	  %echo -n .
	  $(EXEC_SHELL) $(CC_CMD) > $(TMP_CC_OUT) 2>>&1
	%endif
	%if $(status)
	  %set _STATUS = $(status)
	  type $(TMP_CC_MSG)
	  type $(TMP_CC_OUT)
	  %echo COMPILING FAILED ($(_STATUS))
	  %do make_abort
	%elseif !empty($(TMP_CC_OUT))
	  type $(TMP_CC_MSG)
	  type $(TMP_CC_OUT)
	%endif

%ifdef _IS_CXX_APPL
%.$(CXX_OBJ_EXT) : %.$(CXX_SRC_EXT)
	%echo COMPILING  "$(.SOURCE,"=)"
	$(EXEC_SHELL) "$(CXX,"=)" -c $(CXX_FLAGS) $(.SOURCE)
	%if $(status)
	  %set _STATUS = $(status)
	  %echo COMPILING FAILED ($(_STATUS))
	  %do make_abort
	%endif
%endif # _IS_CXX_APPL

# -----------------------------------------------------------------------------
# Assembly rule
# -----------------------------------------------------------------------------

%.$(ASM_OBJ_EXT) : %.$(ASM_SRC_EXT)
	%echo ASSEMBLING "$(.SOURCE,"=)"
	$(EXEC_SHELL) "$(AS,"=)" $(ASM_CMD_LINE)
	%if $(status)
	  %echo ASSEMBLING FAILED ($(status))
	  %do make_abort
	%endif

# -----------------------------------------------------------------------------
# Special dependencies
# -----------------------------------------------------------------------------

# Common rules to compile library sources
comp_lib_sources :
	%do comp_lib_sources_msg
	%do comp_rule CC_MSG_QUIET=1 CC_OBJ_EXT=$(LIBOBJ_EXT)

comp_lib_sources_msg :
	%if '$(_LIB_NAME)' != '$(_LIB_NAME_MSG)'
	  %set _LIB_NAME_MSG = $(_LIB_NAME)
	  %set _COMP_DOT_COUNT =
	  %echo
	  %echo COMPILING  "$(_LIB_NAME,F)" library sources
	  %echo -n            .
	%endif
	%if %length(_COMP_DOT_COUNT) > 68
	  %set _COMP_DOT_COUNT =
	  %echo
	  %echo -n            .
	%endif
	%set _COMP_DOT_COUNT +=.


$(ALL_OBJS) : $(MODEL)_rti.prj

%ifdef _IS_ROOT_MODEL
$(MAKEFILE_DEP_OBJS) : $(MAKEFILE)
%endif

# EOF -------------------------------------------------------------------------
