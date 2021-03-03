{
    
    fvScalarMatrix neutronPrec2Eqn
    (
        fvm::ddt(rhok, dnp2)
      + fvm::div(phi, dnp2)
      - rhok*fvm::laplacian(DT2, dnp2)
      + fvm::Sp(lambda2,dnp2)
      
      
     == rhok*dnp2_s
    );

    neutronPrec2Eqn.relax();

    fvOptions.constrain(neutronPrec2Eqn);

    neutronPrec2Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp2);

    rhok = 1.0 - beta*(T - TRef);
}
