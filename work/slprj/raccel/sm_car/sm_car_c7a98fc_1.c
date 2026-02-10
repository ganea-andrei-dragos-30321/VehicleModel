#include "ne_std.h"
#include "pm_default_allocator.h"
#include "ssc_dae.h"
#include "sm_ssci_NeDaePrivateData.h"
NeDae * sm_ssci_constructDae ( NeDaePrivateData * smData ) ; void
sm_car_c7a98fc_1_NeDaePrivateData_create ( NeDaePrivateData * smData ) ; void
sm_car_c7a98fc_1_dae ( NeDae * * dae , const NeModelParameters * modelParams
, const NeSolverParameters * solverParams ) { PmAllocator * alloc =
pm_default_allocator ( ) ; NeDaePrivateData * smData = ( NeDaePrivateData * )
alloc -> mCallocFcn ( alloc , sizeof ( NeDaePrivateData ) , 1 ) ; ( void )
modelParams ; ( void ) solverParams ;
sm_car_c7a98fc_1_NeDaePrivateData_create ( smData ) ; * dae =
sm_ssci_constructDae ( smData ) ; }
