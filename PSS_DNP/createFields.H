Info<< "Reading thermophysical properties\n" << endl;

Info<< "Reading field T\n" << endl;
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field p_rgh\n" << endl;
volScalarField p_rgh
(
    IOobject
    (
        "p_rgh",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    ),
    mesh
);

#include "createPhi.H"


singlePhaseTransportModel laminarTransport(U, phi);

// Thermal expansion coefficient [1/K]
dimensionedScalar beta
(
    "beta",
    dimless/dimTemperature,
    laminarTransport
);

// Reference temperature [K]
dimensionedScalar TRef("TRef", dimTemperature, laminarTransport);

// Laminar Prandtl number
dimensionedScalar Pr("Pr", dimless, laminarTransport);

// Turbulent Prandtl number
dimensionedScalar Prt("Prt", dimless, laminarTransport);


Info<< "Creating turbulence model\n" << endl;
autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

// Kinematic density for buoyancy force
volScalarField rhok
(
    IOobject
    (
        "rhok",
        runTime.timeName(),
        mesh
    ),
    1.0 - beta*(T - TRef)
);

// kinematic turbulent thermal thermal conductivity m2/s
Info<< "Reading field alphat\n" << endl;
volScalarField alphat
(
    IOobject
    (
        "alphat",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


#include "readGravitationalAcceleration.H"
#include "readhRef.H"
#include "gh.H"


volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    p_rgh + rhok*gh
);

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell
(
    p,
    p_rgh,
    pimple.dict(),
    pRefCell,
    pRefValue
);

if (p_rgh.needReference())
{
    p += dimensionedScalar
    (
        "p",
        p.dimensions(),
        pRefValue - getRefCellValue(p, pRefCell)
    );
}

mesh.setFluxRequired(p_rgh.name());

Info<< "Reading transportProperties\n" << endl;
 
    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );
Info<< "Reading diffusivity D\n" << endl;
 
    dimensionedScalar DT
    (
        transportProperties.lookup("DT")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT5
    (
        transportProperties.lookup("DT5")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT2
    (
        transportProperties.lookup("DT2")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT3
    (
        transportProperties.lookup("DT3")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT4
    (
        transportProperties.lookup("DT4")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT6
    (
        transportProperties.lookup("DT6")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT7
    (
        transportProperties.lookup("DT7")
    );

Info<< "Reading diffusivity D1\n" << endl;
 
    dimensionedScalar DT8
    (
        transportProperties.lookup("DT8")
    );


Info<< "Reading fraction beta1\n" << endl;
 
    dimensionedScalar beta1
    (
        transportProperties.lookup("beta1")
    );


Info<< "Reading decay constant lambda1\n" << endl;
 
    dimensionedScalar lambda1
    (
        transportProperties.lookup("lambda1")
    );

Info<< "Reading fraction beta2\n" << endl;
 
    dimensionedScalar beta2
    (
        transportProperties.lookup("beta2")
    );


Info<< "Reading decay constant lambda2\n" << endl;
 
    dimensionedScalar lambda2
    (
        transportProperties.lookup("lambda2")
    );

Info<< "Reading fraction beta3\n" << endl;
 
    dimensionedScalar beta3
    (
        transportProperties.lookup("beta3")
    );


Info<< "Reading decay constant lambda3\n" << endl;
 
    dimensionedScalar lambda3
    (
        transportProperties.lookup("lambda3")
    );

Info<< "Reading fraction beta4\n" << endl;
 
    dimensionedScalar beta4
    (
        transportProperties.lookup("beta4")
    );


Info<< "Reading decay constant lambda4\n" << endl;
 
    dimensionedScalar lambda4
    (
        transportProperties.lookup("lambda4")
    );

Info<< "Reading fraction beta5\n" << endl;
 
    dimensionedScalar beta5
    (
        transportProperties.lookup("beta5")
    );


Info<< "Reading decay constant lambda5\n" << endl;
 
    dimensionedScalar lambda5
    (
        transportProperties.lookup("lambda5")
    );


Info<< "Reading fraction beta6\n" << endl;
 
    dimensionedScalar beta6
    (
        transportProperties.lookup("beta6")
    );


Info<< "Reading decay constant lambda6\n" << endl;
 
    dimensionedScalar lambda6
    (
        transportProperties.lookup("lambda6")
    );



Info<< "Reading fraction beta7\n" << endl;
 
    dimensionedScalar beta7
    (
        transportProperties.lookup("beta7")
    );


Info<< "Reading decay constant lambda7\n" << endl;
 
    dimensionedScalar lambda7
    (
        transportProperties.lookup("lambda7")
    );

Info<< "Reading fraction beta8\n" << endl;
 
    dimensionedScalar beta8
    (
        transportProperties.lookup("beta8")
    );


Info<< "Reading decay constant lambda8\n" << endl;
 
    dimensionedScalar lambda8
    (
        transportProperties.lookup("lambda8")
    );





Info<< "Reading field dnp1\n" << endl;
volScalarField dnp1
(
    IOobject
    (
        "dnp1",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp1_s\n" << endl;
volScalarField dnp1_s
(
    IOobject
    (
        "dnp1_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp2_s\n" << endl;
volScalarField dnp2_s
(
    IOobject
    (
        "dnp2_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp3_s\n" << endl;
volScalarField dnp3_s
(
    IOobject
    (
        "dnp3_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp4_s\n" << endl;
volScalarField dnp4_s
(
    IOobject
    (
        "dnp4_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp5_s\n" << endl;
volScalarField dnp5_s
(
    IOobject
    (
        "dnp5_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp6_s\n" << endl;
volScalarField dnp6_s
(
    IOobject
    (
        "dnp6_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp7_s\n" << endl;
volScalarField dnp7_s
(
    IOobject
    (
        "dnp7_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp8_s\n" << endl;
volScalarField dnp8_s
(
    IOobject
    (
        "dnp8_s",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
Info<< "Reading field dnp2\n" << endl;
volScalarField dnp2
(
    IOobject
    (
        "dnp2",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp3\n" << endl;
volScalarField dnp3
(
    IOobject
    (
        "dnp3",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp4\n" << endl;
volScalarField dnp4
(
    IOobject
    (
        "dnp4",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp5\n" << endl;
volScalarField dnp5
(
    IOobject
    (
        "dnp5",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp6\n" << endl;
volScalarField dnp6
(
    IOobject
    (
        "dnp6",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp7\n" << endl;
volScalarField dnp7
(
    IOobject
    (
        "dnp7",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field dnp8\n" << endl;
volScalarField dnp8
(
    IOobject
    (
        "dnp8",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


#include "createMRF.H"
#include "createIncompressibleRadiationModel.H"
#include "createFvOptions.H"
