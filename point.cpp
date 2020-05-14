#include "point.h"


Point::Point(const QStringList & list)
{
    freq = list[0];
    ReZ = list[1];
    ImZ = list[2];
    Z = list[3];
    Phase = list[4];
    time = list[5];
    Ewe = list[6];
    I = list[7];
    Cs = list[8];
    Cs_2 = list[9];
    Cp = list[10];
    Cp_2 = list[11];
    cycleNumber = list[12];
    IRange = list[13];
    EweMod = list[14];
    IMod = list[15];
    ReY = list[16];
    ImY = list[17];
    Y = list[18];
    PhaseY = list[19];
}

//Point::Point(Point && _point)
//{
//    freq = _point.freq;
//    ReZ = _point.ReZ;
//    ImZ = _point.ImZ;
//    Z = _point.Z;
//    Phase = _point.Phase;
//    time = _point.time;
//    Ewe = _point.Ewe;
//    I = _point.I;
//    Cs = _point.Cs;
//    Cs_2 = _point.Cs_2;
//    Cp = _point.Cp;
//    Cp_2 = _point.Cp_2;
//    cycleNumber = _point.cycleNumber;
//    IRange = _point.IRange;
//    EweMod = _point.EweMod;
//    IMod = _point.IMod;
//    ReY = _point.ReY;
//    ImY = _point.ImY;
//    Y = _point.Y;
//    PhaseY = _point.PhaseY;

//    freq = nullptr;
//    ReZ = nullptr;
//    ImZ = nullptr;
//    Z = nullptr;
//    Phase = nullptr;
//    time = nullptr;
//    Ewe = nullptr;
//    I = nullptr;
//    Cs = nullptr;
//    Cs_2 = nullptr;
//    Cp = nullptr;
//    Cp_2 = nullptr;
//    cycleNumber = nullptr;
//    IRange = nullptr;
//    EweMod = nullptr;
//    IMod = nullptr;
//    ReY = nullptr;
//    ImY = nullptr;
//    Y = nullptr;
//    PhaseY = nullptr;
//}
