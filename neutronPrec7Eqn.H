{
    

    fvScalarMatrix neutronPrec7Eqn
    (
        fvm::ddt(rhok, dnp7)
      + fvm::div(phi, dnp7)
      - rhok* fvm::laplacian(DT7, dnp7)
      + fvm::Sp(lambda7,dnp7)
      
     == rhok*dnp7_s
        
      
    );
    neutronPrec7Eqn.relax();

    fvOptions.constrain(neutronPrec7Eqn);

    neutronPrec7Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp7);

    rhok = 1.0 - beta*(T - TRef);
}
