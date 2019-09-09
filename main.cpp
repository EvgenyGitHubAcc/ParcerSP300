#include <iostream>
#include "file.h"
#include "timer.h"


int main()
{
    File fileWork;
    std::cout << "Impedance spectra converter for SP-300" << std::endl;
    std::cout << "Starting conversion..." << std::endl;
    Timer::startTimer();
    fileWork.readAllFiles();
    fileWork.writeNyquistFiles();
    fileWork.writeCVFile();
    std::cout << "Finished" << std::endl;
    std::cout << "This software was created by Evgeny Bondarenko (Minsk, 2019)" << std::endl;
    system("pause");
    return 0;
}
