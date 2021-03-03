{
   

    fvScalarMatrix neutronPrec3Eqn
    (
        fvm::ddt(rhok, dnp3)
      + fvm::div(phi, dnp3)
      - rhok*fvm::laplacian(DT3, dnp3)
      + fvm::Sp(lambda3,dnp3)
      
     == rhok*dnp3_s
    );
    neutronPrec3Eqn.relax();

    fvOptions.constrain(neutronPrec3Eqn);

    neutronPrec3Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp3);

    rhok = 1.0 - beta*(T - TRef);
}
