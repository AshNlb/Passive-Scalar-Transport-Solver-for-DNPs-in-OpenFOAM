{
    

    fvScalarMatrix neutronPrec5Eqn
    (
        fvm::ddt(rhok, dnp5)
      + fvm::div(phi, dnp5)
      -rhok* fvm::laplacian(DT5,dnp5)
      + fvm::Sp(lambda5,dnp5)
      
      
     == rhok*dnp5_s
      
    );

    neutronPrec5Eqn.relax();

    fvOptions.constrain(neutronPrec5Eqn);

    neutronPrec5Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp5);

    rhok = 1.0 - beta*(T - TRef);
}
