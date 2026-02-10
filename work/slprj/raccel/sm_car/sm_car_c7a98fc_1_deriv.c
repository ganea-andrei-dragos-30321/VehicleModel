#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "pm_default_allocator.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_car_c7a98fc_1_geometries.h"
PmfMessageId sm_car_c7a98fc_1_compDerivs ( const RuntimeDerivedValuesBundle *
rtdv , const int * eqnEnableFlags , const double * state , const int *
modeVector , const double * input , const double * inputDot , const double *
inputDdot , const double * discreteState , double * deriv , double *
errorResult , NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd =
rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; ( void ) state ; ( void ) modeVector ; ( void ) input ; ( void ) inputDot ; ( void ) inputDdot ; ( void ) discreteState ; ( void ) deriv ; ( void ) neDiagMgr ; errorResult [ 0 ] = 0.0 ; return NULL ; } PmfMessageId sm_car_c7a98fc_1_numJacPerturbLoBounds ( const RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const double * state , const int * modeVector , const double * input , const double * inputDot , const double * inputDdot , const double * discreteState , double * bounds , double * errorResult , NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd = rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; ( void ) state ; ( void ) modeVector ; ( void ) input ; ( void ) inputDot ; ( void ) inputDdot ; ( void ) discreteState ; ( void ) bounds ; ( void ) neDiagMgr ; errorResult [ 0 ] = 0.0 ; return NULL ; } PmfMessageId sm_car_c7a98fc_1_numJacPerturbHiBounds ( const RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const double * state , const int * modeVector , const double * input , const double * inputDot , const double * inputDdot , const double * discreteState , double * bounds , double * errorResult , NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd = rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; ( void ) state ; ( void ) modeVector ; ( void ) input ; ( void ) inputDot ; ( void ) inputDdot ; ( void ) discreteState ; ( void ) bounds ; ( void ) neDiagMgr ; errorResult [ 0 ] = 0.0 ; return NULL ; }
