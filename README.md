# Passive-Scalar-Transport-Solver-for-DNPs-in-OpenFOAM
This OpenFOAM solver solves for the convection and difusion of delayed neutron precursors in liquid fuel.
Main application: Modeling of Molten Salt Reactors.  
The equation solved for each DNP group: 
∂C_i/∂t=−∇(uci) +∇D∇C_i−λ_iC_i+β_iνΣ_fΦ
All relevant constants such as the DNP fractions, decay constants and intial distributions are extracted from Serpent Monte Carlo code developed at VTT.
An application case is provided together with the solver. The case is the standard buoyant cavity tutorial available in OpenFOAM. It is filled with liquid molten salt fuel with an internal heat source correspondin to 1 GW total power level. A lid velocity of 0.5m/s is considered. The example shows the distribution of DNP groups after being transported with the flow. 
