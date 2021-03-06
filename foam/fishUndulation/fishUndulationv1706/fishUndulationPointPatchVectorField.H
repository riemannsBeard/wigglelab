/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2008 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::angularOscillatingVelocityPointPatchVectorField

Description
    Foam::angularOscillatingVelocityPointPatchVectorField

SourceFiles
    angularOscillatingVelocityPointPatchVectorField.C

\*---------------------------------------------------------------------------*/

#ifndef fishUndulationPointPatchVectorField_H
#define fishUndulationPointPatchVectorField_H

 #include "fixedValuePointPatchField.H" //This is used for OF-1.7.x instead.!!!!!!!!!!!!!!!!!!
//#include "fixedValuePointPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
        Class angularOscillatingVelocityPointPatchVectorField Declaration
\*---------------------------------------------------------------------------*/

class fishUndulationPointPatchVectorField
:
    public fixedValuePointPatchField<vector> //This is used in OF-1.7.x instead.!!!!!!!!!!!!
/*    public FixedValuePointPatchField	// This is needed for OF-1.6-ext
    <
        pointPatchField,
        pointMesh,
        pointPatch,
        DummyMatrix,
        vector
    >
*/
{
    // Private data

        pointField p0_;
	// Center line data.
	vector origin_;
	scalar dX_;
        scalar omega_;
        scalar length_;
        scalar waveLength_;
        scalar a_;
        scalar b_;
        scalar c_;

public:

    //- Runtime type information
    TypeName("fishUndulation");


    // Constructors

        //- Construct from patch and internal field
        fishUndulationPointPatchVectorField
        (
            const pointPatch&,
            const DimensionedField<vector, pointMesh>&
        );

        //- Construct from patch, internal field and dictionary
        fishUndulationPointPatchVectorField
        (
            const pointPatch&,
            const DimensionedField<vector, pointMesh>&,
            const dictionary&
        );

        //- Construct by mapping given patchField<vector> onto a new patch
        fishUndulationPointPatchVectorField
        (
            const fishUndulationPointPatchVectorField&,
            const pointPatch&,
            const DimensionedField<vector, pointMesh>&,
	  //const PointPatchFieldMapper& //For OF-1.7.x!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            const pointPatchFieldMapper&
        );

        //- Construct and return a clone
        virtual autoPtr<pointPatchField<vector> > clone() const
        {
            return autoPtr<pointPatchField<vector> >
            (
                new fishUndulationPointPatchVectorField
                (
                    *this
                )
            );
        }

        //- Construct as copy setting internal field reference
        fishUndulationPointPatchVectorField
        (
            const fishUndulationPointPatchVectorField&,
            const DimensionedField<vector, pointMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual autoPtr<pointPatchField<vector> > clone
        (
            const DimensionedField<vector, pointMesh>& iF
        ) const
        {
            return autoPtr<pointPatchField<vector> >
            (
                new fishUndulationPointPatchVectorField
                (
                    *this,
                    iF
                )
            );
        }


    // Member functions

        // Evaluation functions

            //- Update the coefficients associated with the patch field
            virtual void updateCoeffs();


        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
