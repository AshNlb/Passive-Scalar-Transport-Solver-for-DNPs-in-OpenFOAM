# Passive-Scalar-Transport-Solver-for-DNPs-in-OpenFOAM
This OpenFOAM solver solves for the convection and difusion of delayed neutron precursors in liquid fuel.
Main application: Modeling of Molten Salt Reactors.  
An application case is provided together with the solver. The case is the standard buoyant cavity tutorial available in OpenFOAM. It is filled with liquid molten salt fuel with an internal heat source correspondin to 1 GW total power level. A lid velocity of 0.5m/s is considered. The example shows the distribution of DNP groups after being transported with the flow. 
See the AppC.pdf file for more info on the solver. 
PSS_DNP folder contains all the solver files, already compiled. Example folder contains the 0, constant, system files for the OpenFOAM case and the 600 folder which is the latest time-step for this example. If you just want to see the results, download the Example folder and view it with paraView. If you want to run it yourself, download also the solver folder, copy it into your local OpenFOAM applications/solvers directory, navigate to the folder and run wclean then wmake commands. Then go to the Example folder and run PSS_DNP >log&
