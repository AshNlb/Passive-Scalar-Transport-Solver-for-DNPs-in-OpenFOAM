{
    alphat = turbulence->nut()/Prt;
    alphat.correctBoundaryConditions();

    volScalarField alphaEff("alphaEff", turbulence->nu()/Pr + alphat);

    fvScalarMatrix neutronPrec4Eqn
    (
        fvm::ddt(rhok, dnp4)
      + fvm::div(phi, dnp4)
      - rhok*fvm::laplacian(DT4,dnp4)
      + fvm::Sp(lambda4,dnp4)
      
      
     ==  rhok*dnp4_s
    );

    neutronPrec4Eqn.relax();

    fvOptions.constrain(neutronPrec4Eqn);

    neutronPrec4Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp4);

    rhok = 1.0 - beta*(T - TRef);
}
