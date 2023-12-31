/********************************************************************************
 * Copyright (C) 2014-2022 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH  *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *              GNU Lesser General Public Licence (LGPL) version 3,             *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include <TStopwatch.h>
#include <TString.h>
#include <memory>

void run_digi(TString mcEngine = "TGeant3", Int_t fileId = 0)
{
    // Verbosity level (0=quiet, 1=event level, 2=track level, 3=debug)
    Int_t iVerbose = 0;   // just forget about it, for the moment

    // Input file (MC events)
    TString inFile = "pixel_";
    if (fileId == 0)
        inFile = inFile + mcEngine + ".mc.root";
    else
        inFile = Form("%s%s.mc.f%d.root", inFile.Data(), mcEngine.Data(), fileId);

    // Parameter file
    TString parFile = "pixel_";
    parFile = parFile + mcEngine + ".params.root";

    // Digitization parameter file
    TString dir = getenv("VMCWORKDIR");
    TString tutdir = dir + "/MQ/pixelDetector";
    TString digParFile = tutdir + "/param/pixel_digi.par";

    // Output file
    TString outFile = "pixel_";
    if (fileId == 0)
        outFile = outFile + mcEngine + ".digi.root";
    else
        outFile = Form("%s%s.digi.f%d.root", outFile.Data(), mcEngine.Data(), fileId);

    // -----   Timer   --------------------------------------------------------
    TStopwatch timer;

    // -----   Reconstruction run   -------------------------------------------
    FairRunAna* fRun = new FairRunAna();
    FairFileSource* fFileSource = new FairFileSource(inFile);
    fRun->SetSource(fFileSource);
    fRun->SetSink(std::make_unique<FairRootFileSink>(outFile));

    FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
    FairParRootFileIo* parInput1 = new FairParRootFileIo();
    parInput1->open(parFile.Data());

    FairParAsciiFileIo* parIo1 = new FairParAsciiFileIo();
    parIo1->open(digParFile.Data(), "in");

    rtdb->setFirstInput(parInput1);
    rtdb->setSecondInput(parIo1);

    // -----   TorinoDetector hit  producers   ---------------------------------
    PixelDigitize* digiTask = new PixelDigitize();
    fRun->AddTask(digiTask);

    fRun->Init();

    timer.Start();
    fRun->Run();

    // -----   Finish   -------------------------------------------------------

    cout << endl << endl;

    // Extract the maximal used memory an add is as Dart measurement
    // This line is filtered by CTest and the value send to CDash
    FairSystemInfo sysInfo;
    Float_t maxMemory = sysInfo.GetMaxMemory();
    cout << "<DartMeasurement name=\"MaxMemory\" type=\"numeric/double\">";
    cout << maxMemory;
    cout << "</DartMeasurement>" << endl;

    timer.Stop();
    Double_t rtime = timer.RealTime();
    Double_t ctime = timer.CpuTime();

    Float_t cpuUsage = ctime / rtime;
    cout << "<DartMeasurement name=\"CpuLoad\" type=\"numeric/double\">";
    cout << cpuUsage;
    cout << "</DartMeasurement>" << endl;

    cout << endl << endl;
    cout << "Output file is " << outFile << endl;
    cout << "Parameter file is " << parFile << endl;
    cout << "Real time " << rtime << " s, CPU time " << ctime << "s" << endl << endl;
    cout << "Macro finished successfully." << endl;

    // ------------------------------------------------------------------------
}
