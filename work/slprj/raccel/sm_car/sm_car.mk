# Copyright 1994-2024 The MathWorks, Inc.
#
# File    : ert_unix.tmf   
#
# Abstract:
#       Template makefile for building a UNIX-based stand-alone embedded 
#       real-time version of Simulink model using generated C code.
#
#       This makefile attempts to conform to the guidelines specified in the
#       IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization options. Default is -O.
#         CPP_OPTS       - C++ compiler options.	
#         OPTS           - User specific compile options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = /Applications/MATLAB_R2025b.app/bin/maca64/gmake -j 8 -l 10
HOST            = UNIX
BUILD           = yes
SYS_TARGET_FILE = any

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = ["Xcode with Clang | gmake (64-bit Mac)", \
             "GNU gcc/g++ | gmake (64-bit Linux)"]

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  MODELREFS           - List of referenced models
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                   = sm_car
MODULES                 = sm_car_5a10d5d5_1.c sm_car_5a10d5d5_1_create.c sm_car_5a10d5d5_1_setParameters.c sm_car_5a10d5d5_1_asserts.c sm_car_5a10d5d5_1_deriv.c sm_car_5a10d5d5_1_checkDynamics.c sm_car_5a10d5d5_1_compOutputsKin.c sm_car_5a10d5d5_1_compOutputsDyn.c sm_car_5a10d5d5_1_asm_delegate.c sm_car_5a10d5d5_1_sim_delegate.c sm_car_5a10d5d5_1_mode_zero_crossings.c sm_car_5a10d5d5_1_logging.c sm_car_5a10d5d5_1_geometries.c sm_car_5a10d5d5_1_gateway.c sm_car_5a10d5d5_2_ds.c sm_car_5a10d5d5_2_ds_log.c sm_car_5a10d5d5_2_ds_obs_act.c sm_car_5a10d5d5_2_ds_duf.c sm_car_5a10d5d5_2_ds_obs_il.c sm_car_5a10d5d5_2_ds_obs_all.c sm_car_5a10d5d5_2_ds_dxf.c sm_car_5a10d5d5_2_ds_qx_p.c sm_car_5a10d5d5_2_ds_obs_exp.c sm_car_5a10d5d5_2_ds_tdxy_p.c sm_car_5a10d5d5_2_ds_dxy_p.c sm_car_5a10d5d5_2_ds_f.c sm_car_5a10d5d5_2.c sm_car_5a10d5d5_2_gateway.c sm_car_5a10d5d5_6_ds.c sm_car_5a10d5d5_6_ds_log.c sm_car_5a10d5d5_6_ds_obs_act.c sm_car_5a10d5d5_6_ds_duf.c sm_car_5a10d5d5_6_ds_obs_il.c sm_car_5a10d5d5_6_ds_obs_all.c sm_car_5a10d5d5_6_ds_dxf.c sm_car_5a10d5d5_6_ds_qx_p.c sm_car_5a10d5d5_6_ds_obs_exp.c sm_car_5a10d5d5_6_ds_tdxy_p.c sm_car_5a10d5d5_6_ds_dxy_p.c sm_car_5a10d5d5_6_ds_f.c sm_car_5a10d5d5_6.c sm_car_5a10d5d5_6_gateway.c sm_car_5a10d5d5_4_ds.c sm_car_5a10d5d5_4_ds_log.c sm_car_5a10d5d5_4_ds_obs_act.c sm_car_5a10d5d5_4_ds_duf.c sm_car_5a10d5d5_4_ds_obs_il.c sm_car_5a10d5d5_4_ds_obs_all.c sm_car_5a10d5d5_4_ds_dxf.c sm_car_5a10d5d5_4_ds_qx_p.c sm_car_5a10d5d5_4_ds_obs_exp.c sm_car_5a10d5d5_4_ds_tdxy_p.c sm_car_5a10d5d5_4_ds_dxy_p.c sm_car_5a10d5d5_4_ds_f.c sm_car_5a10d5d5_4.c sm_car_5a10d5d5_4_gateway.c sm_car_5a10d5d5_8_ds.c sm_car_5a10d5d5_8_ds_log.c sm_car_5a10d5d5_8_ds_obs_act.c sm_car_5a10d5d5_8_ds_duf.c sm_car_5a10d5d5_8_ds_obs_il.c sm_car_5a10d5d5_8_ds_obs_all.c sm_car_5a10d5d5_8_ds_dxf.c sm_car_5a10d5d5_8_ds_qx_p.c sm_car_5a10d5d5_8_ds_obs_exp.c sm_car_5a10d5d5_8_ds_tdxy_p.c sm_car_5a10d5d5_8_ds_dxy_p.c sm_car_5a10d5d5_8_ds_f.c sm_car_5a10d5d5_8.c sm_car_5a10d5d5_8_gateway.c sm_car_5a10d5d5_7_ds.c sm_car_5a10d5d5_7_ds_log.c sm_car_5a10d5d5_7_ds_obs_act.c sm_car_5a10d5d5_7_ds_duf.c sm_car_5a10d5d5_7_ds_obs_il.c sm_car_5a10d5d5_7_ds_obs_all.c sm_car_5a10d5d5_7_ds_obs_exp.c sm_car_5a10d5d5_7.c sm_car_5a10d5d5_7_gateway.c sm_car_5a10d5d5_5_ds.c sm_car_5a10d5d5_5_ds_log.c sm_car_5a10d5d5_5_ds_obs_act.c sm_car_5a10d5d5_5_ds_duf.c sm_car_5a10d5d5_5_ds_obs_il.c sm_car_5a10d5d5_5_ds_obs_all.c sm_car_5a10d5d5_5_ds_obs_exp.c sm_car_5a10d5d5_5.c sm_car_5a10d5d5_5_gateway.c sm_car_5a10d5d5_3_ds.c sm_car_5a10d5d5_3_ds_y.c sm_car_5a10d5d5_3_ds_ic.c sm_car_5a10d5d5_3_ds_f.c sm_car_5a10d5d5_3_ds_dxy_p.c sm_car_5a10d5d5_3_ds_tduf_p.c sm_car_5a10d5d5_3_ds_mcon_p.c sm_car_5a10d5d5_3_ds_slv.c sm_car_5a10d5d5_3_ds_mode.c sm_car_5a10d5d5_3_ds_obs_exp.c sm_car_5a10d5d5_3_ds_zc.c sm_car_5a10d5d5_3_ds_duf.c sm_car_5a10d5d5_3_ds_duf_p.c sm_car_5a10d5d5_3_ds_lv.c sm_car_5a10d5d5_3_ds_acon_p.c sm_car_5a10d5d5_3_ds_imin.c sm_car_5a10d5d5_3_ds_vdf.c sm_car_5a10d5d5_3_ds_nldv.c sm_car_5a10d5d5_3_ds_dxf.c sm_car_5a10d5d5_3_ds_bcon_p.c sm_car_5a10d5d5_3_ds_tdxy_p.c sm_car_5a10d5d5_3_ds_obs_act.c sm_car_5a10d5d5_3_ds_dxy.c sm_car_5a10d5d5_3_ds_dnf_v_x.c sm_car_5a10d5d5_3_ds_tdxf_p.c sm_car_5a10d5d5_3_ds_log.c sm_car_5a10d5d5_3_ds_assert.c sm_car_5a10d5d5_3_ds_obs_all.c sm_car_5a10d5d5_3_ds_obs_il.c sm_car_5a10d5d5_3_ds_vmm.c sm_car_5a10d5d5_3_ds_vmf.c sm_car_5a10d5d5_3_ds_dxf_p.c sm_car_5a10d5d5_3_ds_mcon.c sm_car_5a10d5d5_3_ds_acon.c sm_car_5a10d5d5_3_ds_dnf_p.c sm_car_5a10d5d5_3.c sm_car_5a10d5d5_3_gateway.c sm_car_c7a98fc_1.c sm_car_c7a98fc_1_create.c sm_car_c7a98fc_1_setParameters.c sm_car_c7a98fc_1_asserts.c sm_car_c7a98fc_1_deriv.c sm_car_c7a98fc_1_checkDynamics.c sm_car_c7a98fc_1_asm_delegate.c sm_car_c7a98fc_1_sim_delegate.c sm_car_c7a98fc_1_mode_zero_crossings.c sm_car_c7a98fc_1_logging.c sm_car_c7a98fc_1_geometries.c sm_car_c7a98fc_1_gateway.c rt_backsubrr_dbl.c rt_forwardsubrr_dbl.c rt_lu_real.c rt_matrixlib_dbl.c rtGetInf.c rtGetNaN.c rt_nonfinite.c sm_car.c sm_car_capi.c sm_car_data.c sm_car_tgtconn.c raccel_main.c raccel_sup.c raccel_mat.c simulink_solver_api.c raccel_utils.c slsa_sim_common_utils.c main.c ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c rtiostream_utils.c
PRODUCT                 = sm_car
MAKEFILE                = sm_car.mk
MATLAB_ROOT             = /Applications/MATLAB_R2025b.app
ALT_MATLAB_ROOT         = /Applications/MATLAB_R2025b.app
START_DIR               = /Users/andrei/Desktop/FSAE/Vehicle\ Model/VehicleModel/work
S_FUNCTIONS_LIB         = 
NUMST                   = 3
NCSTATES                = 429
COMPUTER                = MACA64
BUILDARGS               =  RSIM_SOLVER_SELECTION=1 PCMATLABROOT="/Applications/MATLAB_R2025b.app" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 RSIM_PARAMETER_LOADING=1 OPTS="-DTGTCONN -DIS_SIM_TARGET -DENABLE_SLEXEC_SSBRIDGE=1 -DNRT -DRSIM_PARAMETER_LOADING -DRSIM_WITH_SL_SOLVER -DUSE_LOCALHOST -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=0" MACOSX_VERSION_MIN_FLAG="-mmacosx-version-min=12.0"
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 1
ALLOCATIONFCN           = 0
ONESTEPFCN              = 0
TERMFCN                 = 1
ENABLE_SLEXEC_SSBRIDGE  = 1
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 1
TGT_FCN_LIB             = ISO_C
MODELREFS               = 
GEN_SAMPLE_MAIN         = 0
TARGET_LANG_EXT         = c
SHRLIBTARGET            = 0
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = -O0
ADDITIONAL_LDFLAGS      =  -Wl,-rpath,/Applications/MATLAB_R2025b.app/bin/maca64 -Wl,-rpath,/Applications/MATLAB_R2025b.app/sys/os/maca64 -Wl,-rpath,@executable_path/../../.. -L/Applications/MATLAB_R2025b.app/sys/os/maca64
INTERLEAVED_COMPLEX_FLAGS = -R2018a
DEFINES_CUSTOM          = -DEXT_MODE -DIS_RAPID_ACCEL 
DEFINES_OTHER           = -DHAVESTDIO
COMPILE_FLAGS_OTHER     = 
SYSTEM_LIBS             = -L"/Applications/MATLAB_R2025b.app/bin/maca64" -lmwblas -lmwphysmod_common_logging2_core_rtw -lmwphysmod_common_logging2_sdi_stream_rtw -lut -lmx -lmex -lmat -lmwmathutil -lmwslsa_engine -lmwslexec_simbridge -lmwsl_fileio -lmwsigstream -lmwsl_AsyncioQueue -lmwsl_services -lmwsdi_raccel -lmwcoder_target_services -lmwcoder_ParamTuningTgtAppSvc -lmwslpointerutil -lmwfoundation_i18n_init_c_api -lmwsl_simtarget_instrumentation -lfixedpoint -lmwslexec_simlog -lmwstringutil -lm -lpthread -ldl
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE


#-- For gcc, link model reference libraries as a group to resolve circular references ---
#   (NOTE: Clang does not recognize these switches but it already resolves circular references)
MODELREF_LINK_LIBS_GROUP = 
ifeq ($(COMPUTER),GLNXA64)
  MODELREF_LINK_LIBS_GROUP = -Wl,--start-group  -Wl,--end-group
endif

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Tool Specifications -------------------------------

include $(MATLAB_ROOT)/rtw/c/tools/unixtools.mk

#------------------------------ Include Path -----------------------------------

# Additional includes 
ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/slprj/raccel/sm_car \
	-I$(MATLAB_ROOT)/rtw/c/src/rapid \
	-I$(MATLAB_ROOT)/rtw/c/raccel \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/ex/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/mc/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/pd/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/pm/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/pm_log/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/pm_math/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/pm_st/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/sm/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/ssc_dae/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/ssc_ds/include \
	-I$(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/include \


INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(ADD_INCLUDES)

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif

# Defines
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DUNIX \
                  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		  -DALLOCATIONFCN=$(ALLOCATIONFCN)

ifeq ($(MODELREF_TARGET_TYPE),SIM)
ifneq ($(ENABLE_SLEXEC_SSBRIDGE), 0)
CPP_REQ_DEFINES += -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
endif
else
CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif

CPP_REQ_DEFINES += -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPTS) $(COMPILE_FLAGS_OTHER) $(OPT_OPTS)
endif

DEFINES = $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(DEFINES_OTHER)
CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(DEFINES) $(INCLUDES)

#-------------------------- Additional Libraries ------------------------------

SYSTEM_LIBS += -lm

LIBS =

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/lib/ssc_sli_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/lib/ssc_sli_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/lib/ssc_sli_int_ert.a
endif
else
LIBS += ssc_sli.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/lib/sm_ssci_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/lib/sm_ssci_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/lib/sm_ssci_int_ert.a
endif
else
LIBS += sm_ssci.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/lib/ssc_core_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/lib/ssc_core_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/lib/ssc_core_int_ert.a
endif
else
LIBS += ssc_core.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm/lib/sm_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm/lib/sm_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/sm/lib/sm_int_ert.a
endif
else
LIBS += sm.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_math/lib/pm_math_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_math/lib/pm_math_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_math/lib/pm_math_int_ert.a
endif
else
LIBS += pm_math.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_st/lib/pm_st_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_st/lib/pm_st_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm_st/lib/pm_st_int_ert.a
endif
else
LIBS += pm_st.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/mc/lib/mc_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/mc/lib/mc_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/mc/lib/mc_int_ert.a
endif
else
LIBS += mc.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ex/lib/ex_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ex/lib/ex_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/ex/lib/ex_int_ert.a
endif
else
LIBS += ex.a
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm/lib/pm_rtwsfcn.a
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm/lib/pm_ert.a
endif
else
LIBS += $(MATLAB_ROOT)/extern/physmod/maca64/pm/lib/pm_int_ert.a
endif
else
LIBS += pm.a
endif
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------
ADD_SRCS =

SRCS = $(ADD_SRCS) $(MODULES)

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

ADDITIONAL_LDFLAGS += $(ARCH_SPECIFIC_LDFLAGS)

#--------------------------------- Rules ---------------------------------------
BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT)
BUILD_PRODUCT_TYPE = "executable"
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  ifeq ($(SHRLIBTARGET), 1)
    BIN_SETTING        = $(LD) $(ADDITIONAL_LDFLAGS) $(SHRLIBLDFLAGS)$(MODEL).def -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "shared object"	
    ifeq ($(GEN_SAMPLE_MAIN), 1)
      PRODUCT := $(notdir $(PRODUCT))
$(MODEL) : $(PRODUCT) ert_main.o
	$(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(MODEL) ert_main.o $(PRODUCT) $(SYSTEM_LIBS)
	@mv $(PRODUCT) $(RELATIVE_PATH_TO_ANCHOR)/
	@mv $(MODEL) $(RELATIVE_PATH_TO_ANCHOR)/
	@echo "### Created executable: $@"
    endif
  endif
  ifeq ($(MAKEFILEBUILDER_TGT), 1)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELLIB) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS_GROUP) $(LIBS)  $(SYSTEM_LIBS)
	@echo "### Created executable: $@"
  else
    ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS) $(LIBS)
	@echo "### Created object modules: $@"
    else
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS_GROUP) $(LIBS)  $(SYSTEM_LIBS)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
    endif
  endif
else
  $(PRODUCT) : $(OBJS)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo "### Created $(MODELLIB)"
	@echo "### Created library: $@"
endif

#-------------------------- Support for building modules ----------------------

%.o : %.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ex/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/mc/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm_math/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm_st/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/sm/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

raccel_main.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c

raccel_sup.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c

raccel_mat.o : $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c

simulink_solver_api.o : $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c

raccel_utils.o : $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c

slsa_sim_common_utils.o : $(MATLAB_ROOT)/rtw/c/src/rapid/slsa_sim_common_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/rapid/slsa_sim_common_utils.c

main.o : $(MATLAB_ROOT)/rtw/c/raccel/main.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/raccel/main.c

ext_svr.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c

updown.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c

ext_work.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c

rtiostream_interface.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c

rtiostream_tcpip.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c

rtiostream_utils.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c



%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ex/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/mc/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm_math/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/pm_st/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/sm/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/sm_ssci/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ssc_core/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/extern/physmod/maca64/ssc_sli/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"



#------------------------------- Libraries -------------------------------------



MODULES_ssc_sli = \
    ssc_sli_01dba599.o \
    ssc_sli_0267402d.o \
    ssc_sli_050be629.o \
    ssc_sli_06b10db7.o \
    ssc_sli_0763c151.o \
    ssc_sli_0bd269e6.o \
    ssc_sli_10d0a0c3.o \
    ssc_sli_1367f522.o \
    ssc_sli_136f97a1.o \
    ssc_sli_1e0f233a.o \
    ssc_sli_256cd57f.o \
    ssc_sli_27094491.o \
    ssc_sli_2f6ea1cd.o \
    ssc_sli_2f6ec032.o \
    ssc_sli_360cfd63.o \
    ssc_sli_37d957ac.o \
    ssc_sli_3b68442e.o \
    ssc_sli_3fb4607e.o \
    ssc_sli_40d3bd6c.o \
    ssc_sli_40d56d93.o \
    ssc_sli_40d5da0a.o \
    ssc_sli_43618287.o \
    ssc_sli_4363e48f.o \
    ssc_sli_466b08dd.o \
    ssc_sli_4e028390.o \
    ssc_sli_550a4805.o \
    ssc_sli_56b8ac8d.o \
    ssc_sli_59b886b8.o \
    ssc_sli_5a0cb974.o \
    ssc_sli_5d63155c.o \
    ssc_sli_5d65a733.o \
    ssc_sli_5d671b0e.o \
    ssc_sli_5f0de15a.o \
    ssc_sli_60b93a56.o \
    ssc_sli_62d81790.o \
    ssc_sli_65bed6fb.o \
    ssc_sli_66095472.o \
    ssc_sli_77063d8b.o \
    ssc_sli_7a618260.o \
    ssc_sli_7bb5f2e0.o \
    ssc_sli_89d0f30a.o \
    ssc_sli_8a64c4e2.o \
    ssc_sli_8d09009a.o \
    ssc_sli_9abcdb7f.o \
    ssc_sli_9b61793b.o \
    ssc_sli_9c030181.o \
    ssc_sli_9c0cb889.o \
    ssc_sli_9dd1cff8.o \
    ssc_sli_a1da431d.o \
    ssc_sli_a4dfa663.o \
    ssc_sli_a9bd7181.o \
    ssc_sli_af031838.o \
    ssc_sli_af04cdba.o \
    ssc_sli_b0d5246e.o \
    ssc_sli_b10f504c.o \
    ssc_sli_b2b1d316.o \
    ssc_sli_b5d8ca33.o \
    ssc_sli_b9610f5b.o \
    ssc_sli_bad3eeab.o \
    ssc_sli_c7dda239.o \
    ssc_sli_d06e19e0.o \
    ssc_sli_d3d59c3a.o \
    ssc_sli_d56e4e2b.o \
    ssc_sli_dcd66f69.o \
    ssc_sli_eb0a5702.o \
    ssc_sli_eb0f3853.o \
    ssc_sli_edb7e1b3.o \
    ssc_sli_f508a54a.o \
    ssc_sli_f76be39c.o \
    ssc_sli_fa09e530.o \
    ssc_sli_fa0ce53e.o \
    ssc_sli_fbdf29da.o \


ssc_sli.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_ssc_sli)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_ssc_sli)
	@echo "### $@ Created "

MODULES_sm_ssci = \
    sm_ssci_3dd14f0a.o \
    sm_ssci_646478c5.o \
    sm_ssci_b2b6b422.o \
    sm_ssci_c16a187b.o \


sm_ssci.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_sm_ssci)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_sm_ssci)
	@echo "### $@ Created "

MODULES_ssc_core = \
    ssc_core_01dcc633.o \
    ssc_core_04da2c69.o \
    ssc_core_05058dd9.o \
    ssc_core_06ba68a6.o \
    ssc_core_09b5fa6e.o \
    ssc_core_0a03aa58.o \
    ssc_core_0bd666aa.o \
    ssc_core_0cb8a17f.o \
    ssc_core_0d65be6c.o \
    ssc_core_0f019bd9.o \
    ssc_core_0f0420a6.o \
    ssc_core_0f09282e.o \
    ssc_core_18bf4d77.o \
    ssc_core_1c6b0332.o \
    ssc_core_1fd25120.o \
    ssc_core_24b4cdee.o \
    ssc_core_280c0222.o \
    ssc_core_2cd54448.o \
    ssc_core_3169e4b7.o \
    ssc_core_32d8b307.o \
    ssc_core_3306c008.o \
    ssc_core_360a4baf.o \
    ssc_core_37d4ea84.o \
    ssc_core_3e6774ce.o \
    ssc_core_40db642d.o \
    ssc_core_40dfdbdc.o \
    ssc_core_41017299.o \
    ssc_core_42b6ffa6.o \
    ssc_core_4666b45b.o \
    ssc_core_48b1386a.o \
    ssc_core_4ad9135b.o \
    ssc_core_4db6bd68.o \
    ssc_core_4db86fcc.o \
    ssc_core_4e03e39d.o \
    ssc_core_4e04eecd.o \
    ssc_core_4e06e3bd.o \
    ssc_core_51d269ad.o \
    ssc_core_54d55ae9.o \
    ssc_core_5505224d.o \
    ssc_core_550b4c41.o \
    ssc_core_56b1a2bf.o \
    ssc_core_576cd129.o \
    ssc_core_59b034b8.o \
    ssc_core_5d6ba758.o \
    ssc_core_61629eca.o \
    ssc_core_6607ea62.o \
    ssc_core_67d1f118.o \
    ssc_core_68da074b.o \
    ssc_core_6b663a17.o \
    ssc_core_6b6b89d2.o \
    ssc_core_6dd833f3.o \
    ssc_core_7209d3a5.o \
    ssc_core_73d9c2b7.o \
    ssc_core_76d825be.o \
    ssc_core_770cead7.o \
    ssc_core_7a613edb.o \
    ssc_core_83db8762.o \
    ssc_core_856738f2.o \
    ssc_core_8569edc5.o \
    ssc_core_89d7fa79.o \
    ssc_core_8a6471dc.o \
    ssc_core_8cd9cb37.o \
    ssc_core_990fe1a4.o \
    ssc_core_9b607b15.o \
    ssc_core_9b671e57.o \
    ssc_core_9c016445.o \
    ssc_core_9c01d168.o \
    ssc_core_9dd110ad.o \
    ssc_core_9fb0e229.o \
    ssc_core_9fb25b4f.o \
    ssc_core_a269ab09.o \
    ssc_core_a4d4c45e.o \
    ssc_core_a4d6c217.o \
    ssc_core_a4da1d0a.o \
    ssc_core_a6b334b8.o \
    ssc_core_a6b58a33.o \
    ssc_core_a6b78ccc.o \
    ssc_core_a76299bc.o \
    ssc_core_a867d880.o \
    ssc_core_a9bf1ff2.o \
    ssc_core_aa09f23c.o \
    ssc_core_abd05c18.o \
    ssc_core_abd5e7b4.o \
    ssc_core_acb64294.o \
    ssc_core_acb6462e.o \
    ssc_core_b1038cbb.o \
    ssc_core_b10e34f4.o \
    ssc_core_b2b3b239.o \
    ssc_core_b369cd13.o \
    ssc_core_b402b40d.o \
    ssc_core_b5daad8d.o \
    ssc_core_b7b88213.o \
    ssc_core_b96ebc21.o \
    ssc_core_bad68669.o \
    ssc_core_bc648043.o \
    ssc_core_bfdb08db.o \
    ssc_core_c3003040.o \
    ssc_core_c5b050d7.o \
    ssc_core_c5b63cb2.o \
    ssc_core_c607b660.o \
    ssc_core_c8d83e88.o \
    ssc_core_c9039339.o \
    ssc_core_cab615c8.o \
    ssc_core_cabdc251.o \
    ssc_core_cabeaaaf.o \
    ssc_core_cc0bcab0.o \
    ssc_core_ce6a84bb.o \
    ssc_core_d06d763c.o \
    ssc_core_d3d34d7c.o \
    ssc_core_d4b9397b.o \
    ssc_core_d70a6a09.o \
    ssc_core_d807fa59.o \
    ssc_core_deb7fd8d.o \
    ssc_core_e0d0866d.o \
    ssc_core_e2b61d72.o \
    ssc_core_e400c1c2.o \
    ssc_core_ead8f455.o \
    ssc_core_edb836de.o \
    ssc_core_ee000fbe.o \
    ssc_core_ee01086d.o \
    ssc_core_f9b6dbed.o \
    ssc_core_fa09e9e6.o \
    ssc_core_fbd34e62.o \


ssc_core.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_ssc_core)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_ssc_core)
	@echo "### $@ Created "

MODULES_sm = \
    sm_01d3ac26.o \
    sm_04d045b9.o \
    sm_09b59221.o \
    sm_0cb6a5fa.o \
    sm_1dba7276.o \
    sm_1e022f29.o \
    sm_26df822b.o \
    sm_38d4abbe.o \
    sm_43618472.o \
    sm_440126a7.o \
    sm_45dc522c.o \
    sm_466cdd79.o \
    sm_4b066b5a.o \
    sm_4c61739a.o \
    sm_5763bdb7.o \
    sm_5cbc01c8.o \
    sm_6166f1eb.o \
    sm_62d41fb5.o \
    sm_630c0817.o \
    sm_67d72683.o \
    sm_6fbd150d.o \
    sm_73d210b9.o \
    sm_74b0064a.o \
    sm_916806b3.o \
    sm_95b82517.o \
    sm_9abcb56e.o \
    sm_a0028316.o \
    sm_a1d32671.o \
    sm_a3ba6de7.o \
    sm_a50cd7b1.o \
    sm_aa059a3a.o \
    sm_acba2496.o \
    sm_b40db855.o \
    sm_b66990f5.o \
    sm_badd8656.o \
    sm_bc63e36c.o \
    sm_bfda6e42.o \
    sm_c0ba649d.o \
    sm_c5b9546f.o \
    sm_c60bdc8d.o \
    sm_c7d3720c.o \
    sm_cabca465.o \
    sm_d3d79f0f.o \
    sm_d3d946fd.o \
    sm_d4bb3938.o \
    sm_d6dc1822.o \
    sm_da690167.o \
    sm_dbbace78.o \
    sm_df66e89b.o \
    sm_e8bab6d7.o \
    sm_ec6029c9.o \
    sm_efdfa66e.o \
    sm_f3b314ce.o \
    sm_f5077b36.o \


sm.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_sm)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_sm)
	@echo "### $@ Created "

MODULES_pm_math = \
    pm_math_01dec08e.o \
    pm_math_04d19358.o \
    pm_math_050e87e9.o \
    pm_math_1966ea7d.o \
    pm_math_1ad202b7.o \
    pm_math_1c69d5b2.o \
    pm_math_1c6b6a1b.o \
    pm_math_29dc7f63.o \
    pm_math_2a66252c.o \
    pm_math_2f607a02.o \
    pm_math_32d9636d.o \
    pm_math_3309726a.o \
    pm_math_3463da5d.o \
    pm_math_360e4b46.o \
    pm_math_3fbf046b.o \
    pm_math_48b75553.o \
    pm_math_48bd51fb.o \
    pm_math_5a01dda4.o \
    pm_math_646fa971.o \
    pm_math_6b69e06e.o \
    pm_math_7565727c.o \
    pm_math_7cd5543c.o \
    pm_math_89df260e.o \
    pm_math_8cd61cd6.o \
    pm_math_8d05b7c0.o \
    pm_math_93014cb0.o \
    pm_math_a001e9ec.o \
    pm_math_b7b980b1.o \
    pm_math_bad43c87.o \
    pm_math_c7d2cd09.o \
    pm_math_d1be0f30.o \
    pm_math_d80b9e3b.o \
    pm_math_da630bd2.o \
    pm_math_e8b06b42.o \
    pm_math_ee02b2b3.o \
    pm_math_f760e8f6.o \
    pm_math_f866cdd2.o \
    pm_math_fd679a52.o \


pm_math.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_pm_math)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_pm_math)
	@echo "### $@ Created "

MODULES_pm_st = \
    pm_st_12be8102.o \
    pm_st_43603aca.o \
    pm_st_59ba8c5e.o \
    pm_st_65b906f8.o \
    pm_st_7a6183ce.o \
    pm_st_7f64b2fa.o \
    pm_st_870f70cf.o \
    pm_st_a3b260e9.o \
    pm_st_a7639c45.o \
    pm_st_a868d115.o \
    pm_st_d56af4a2.o \
    pm_st_d56c266e.o \


pm_st.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_pm_st)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_pm_st)
	@echo "### $@ Created "

MODULES_mc = \
    mc_04d8264b.o \
    mc_050786f6.o \
    mc_050ee5c1.o \
    mc_06b4b0db.o \
    mc_0860ee8a.o \
    mc_0cb8196b.o \
    mc_0d63602b.o \
    mc_0d66ba95.o \
    mc_1361f5a5.o \
    mc_15d544b1.o \
    mc_1663c1db.o \
    mc_1669178c.o \
    mc_17b2b909.o \
    mc_17b70a99.o \
    mc_18be9741.o \
    mc_1fd05351.o \
    mc_256bba9e.o \
    mc_27064e3e.o \
    mc_2d0630db.o \
    mc_2f6ba92e.o \
    mc_30b92ba0.o \
    mc_316e8ecd.o \
    mc_410dc6dd.o \
    mc_42bcfe75.o \
    mc_4368e8e9.o \
    mc_436f3a90.o \
    mc_4401f9e5.o \
    mc_45d93f38.o \
    mc_47b2c4ec.o \
    mc_4c6caaa7.o \
    mc_4dbcdca5.o \
    mc_4e0fe18e.o \
    mc_56bcae38.o \
    mc_57680369.o \
    mc_586d9cad.o \
    mc_5a0a6cc3.o \
    mc_5d67a19c.o \
    mc_5ed62cca.o \
    mc_6464144a.o \
    mc_65b0d207.o \
    mc_65b2d0c8.o \
    mc_67dc4926.o \
    mc_68dddb4b.o \
    mc_690fc1bf.o \
    mc_6b605e19.o \
    mc_6ddde8f9.o \
    mc_720ad3c3.o \
    mc_720db216.o \
    mc_7563a9d1.o \
    mc_7803a56b.o \
    mc_79deb076.o \
    mc_7bb9909f.o \
    mc_84b8497c.o \
    mc_870c7565.o \
    mc_880b5c40.o \
    mc_8bbed717.o \
    mc_916e0629.o \
    mc_94605196.o \
    mc_9b601681.o \
    mc_9ddbabe4.o \
    mc_9ddca961.o \
    mc_9fbb8898.o \
    mc_a1d39e4d.o \
    mc_a1d627d1.o \
    mc_a1d99098.o \
    mc_a26aa4d4.o \
    mc_a3b30e18.o \
    mc_a5006377.o \
    mc_a50a0cbe.o \
    mc_aa099650.o \
    mc_abd38dd6.o \
    mc_aed8b9d2.o \
    mc_aedf6e5a.o \
    mc_af0477d5.o \
    mc_b0dc45ca.o \
    mc_b1035db7.o \
    mc_b4000713.o \
    mc_b7b18d60.o \
    mc_b968d32c.o \
    mc_bad68a7d.o \
    mc_bfdd02f5.o \
    mc_c16219bc.o \
    mc_c162c223.o \
    mc_c307e3dc.o \
    mc_c46a93be.o \
    mc_c90d9f89.o \
    mc_cdd0dd5f.o \
    mc_cdd8da52.o \
    mc_d1b8dd6f.o \
    mc_d204e67a.o \
    mc_d6d6168f.o \
    mc_d702d1e4.o \
    mc_d9d8e9f3.o \
    mc_dbb0a508.o \
    mc_dbb3aff1.o \
    mc_dbbfabc6.o \
    mc_dcd0078a.o \
    mc_e362bd71.o \
    mc_e662eca6.o \
    mc_e66336ff.o \
    mc_e7b62a38.o \
    mc_e8b1ba5c.o \
    mc_edbe8c94.o \
    mc_efd17762.o \
    mc_f0002806.o \
    mc_f1d0579f.o \
    mc_f1d0e311.o \
    mc_f1d15bd5.o \
    mc_f3b173fc.o \
    mc_f50bcfe0.o \
    mc_f86b1ebb.o \
    mc_f9b5db9f.o \


mc.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_mc)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_mc)
	@echo "### $@ Created "

MODULES_ex = \
    ex_04d5441d.o \
    ex_06bcd123.o \
    ex_0cbdc04a.o \
    ex_136645f8.o \
    ex_15d44e9b.o \
    ex_17bc61ac.o \
    ex_18b4440a.o \
    ex_1b0bcf19.o \
    ex_24b31d7b.o \
    ex_2ebcd5b2.o \
    ex_316a81de.o \
    ex_36012fa7.o \
    ex_40d5be33.o \
    ex_45d28653.o \
    ex_47b11894.o \
    ex_47bac61e.o \
    ex_57660158.o \
    ex_5f03eedb.o \
    ex_65b1deb8.o \
    ex_690b7cd0.o \
    ex_6dd531e9.o \
    ex_6dd8e72d.o \
    ex_6ddd54d3.o \
    ex_7804c67c.o \
    ex_79d100f1.o \
    ex_7cd25341.o \
    ex_8a6fc761.o \
    ex_8bb2d091.o \
    ex_8ebb89cc.o \
    ex_90b5a12a.o \
    ex_98d223a6.o \
    ex_abd23e11.o \
    ex_abd98332.o \
    ex_aed5de1e.o \
    ex_b2b40ad5.o \
    ex_bb0efd4b.o \
    ex_bc613780.o \
    ex_c9069dae.o \
    ex_cdd0b0e0.o \
    ex_d9d686a8.o \
    ex_debffef2.o \
    ex_e10a4cd8.o \
    ex_e40d74b8.o \
    ex_eb0d559b.o \
    ex_f26168b3.o \
    ex_f6bb4c2d.o \
    ex_f866102d.o \


ex.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_ex)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_ex)
	@echo "### $@ Created "

MODULES_pm = \
    pm_26dc3230.o \
    pm_3dd94032.o \
    pm_466768a4.o \
    pm_9dd7a82d.o \
    pm_b103e88f.o \
    pm_c60cb912.o \


pm.a : $(MAKEFILE) rtw_proj.tmw $(MODULES_pm)
	@echo "### Creating $@ "
	$(AR) rs $@ $(MODULES_pm)
	@echo "### $@ Created "



#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

