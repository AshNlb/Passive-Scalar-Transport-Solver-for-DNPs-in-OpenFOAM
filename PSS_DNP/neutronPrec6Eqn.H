{
    

    fvScalarMatrix neutronPrec6Eqn
    (
        fvm::ddt(rhok, dnp6)
      + fvm::div(phi, dnp6)
      - rhok*fvm::laplacian(DT6,dnp6)
      + fvm::Sp(lambda6,dnp6)  
      
     == rhok*dnp6_s
      
    );

    neutronPrec6Eqn.relax();

    fvOptions.constrain(neutronPrec6Eqn);

    neutronPrec6Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp6);

    rhok = 1.0 - beta*(T - TRef);
}
