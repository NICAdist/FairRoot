/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *              GNU Lesser General Public Licence (LGPL) version 3,             *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
/* Generated by Together */

#include "FairMagnet.h"

#include "FairGeoMagnet.h"       // for FairGeoMagnet
#include "FairGeoPassivePar.h"   // for FairGeoPassivePar

#include <TString.h>   // for TString
#include <iostream>    // for operator<<, basic_ostream, etc

FairMagnet::~FairMagnet() {}

FairMagnet::FairMagnet()
    : FairModule("FairMagnet", "")
{}

FairMagnet::FairMagnet(const char* name, const char* Title)
    : FairModule(name, Title)
{}

FairMagnet::FairMagnet(const FairMagnet& rhs)
    : FairModule(rhs)
{}

void FairMagnet::ConstructGeometry()
{
    TString fileName = GetGeometryFileName();
    if (fileName.EndsWith(".geo")) {
        ConstructASCIIGeometry();
    } else if (fileName.EndsWith(".root")) {
        ConstructRootGeometry();
    } else {
        std::cout << "Geometry format not supported " << std::endl;
    }
}

Bool_t FairMagnet::IsSensitive(const std::string& /*name*/)
{
    // just to get rid of the warrning during run, not need this is a passive element!
    return kFALSE;
}

void FairMagnet::ConstructASCIIGeometry()
{
    FairGeoMagnet* MGeo = new FairGeoMagnet();

    FairModule::ConstructASCIIGeometry<FairGeoMagnet, FairGeoPassivePar>(MGeo, "FairGeoPassivePar");
}

FairModule* FairMagnet::CloneModule() const { return new FairMagnet(*this); }

ClassImp(FairMagnet);