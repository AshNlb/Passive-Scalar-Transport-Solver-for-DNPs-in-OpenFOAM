{
    
    fvScalarMatrix neutronPrec1Eqn
    (
        fvm::ddt(rhok,dnp1)
      + fvm::div(phi, dnp1)	
      - rhok*fvm::laplacian(DT, dnp1)
      + fvm::Sp(lambda1,dnp1)
      
     == rhok*dnp1_s
       
        
    );
   
    neutronPrec1Eqn.relax();

    fvOptions.constrain(neutronPrec1Eqn);

    neutronPrec1Eqn.solve();

    radiation->correct();

    fvOptions.correct(dnp1);

    rhok = 1.0 - beta*(T - TRef);
}
