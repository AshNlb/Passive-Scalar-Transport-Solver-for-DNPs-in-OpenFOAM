{
    

    fvScalarMatrix neutronPrec8Eqn
    (
        fvm::ddt(rhok, dnp8)
      + fvm::div(phi, dnp8)
      - rhok*fvm::laplacian(DT8,dnp8)
      + fvm::Sp(lambda8,dnp8)
      
     == rhok*dnp8_s
        
     
    );
    neutronPrec8Eqn.relax();

    fvOptions.constrain(neutronPrec8Eqn);

    neutronPrec8Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp8);

    rhok = 1.0 - beta*(T - TRef);
}
