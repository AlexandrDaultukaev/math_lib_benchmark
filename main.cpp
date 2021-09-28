#include <ctime>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <math.h>

std::clock_t start;
typedef int type;

double duration;
double end;
int N = 100000;

int optimization = 3;
int numtype = 2;

double O3refSIN = 1e-10;
double O3refCOS = 7e-11;
double O3refTAN = 2e-11;

double O2refSIN = 2e-10;
double O2refCOS = 2e-11;
double O2refTAN = 2e-11;

double O1refSIN = 1.54e-09;
double O1refCOS = 1.29e-09;
double O1refTAN = 1.28e-09;

double O0refSIN = 4.52e-09;
double O0refCOS = 4.64e-09;
double O0refTAN = 4.34e-09;

double O0refSINf = 1.789e-08;
double O0refCOSf = 2.897e-08;
double O0refTANf = 4.789e-08;

double O1refSINf = 1.34e-08;
double O1refCOSf = 1.11e-08;
double O1refTANf = 1.35e-08;

double O2refSINf = 1.9e-10;
double O2refCOSf = 2e-10;
double O2refTANf = 6e-11;

double O3refSINf = 2e-10;
double O3refCOSf = 8e-11;
double O3refTANf = 2e-11;

double O0refSINi = 2.023e-08;
double O0refCOSi = 1.701e-08;
double O0refTANi = 2.314e-08;

double O1refSINi = 1.49e-09;
double O1refCOSi = 9.2e-10;
double O1refTANi = 1.44e-09;

double O2refSINi = 5.1e-10;
double O2refCOSi = 2e-10;
double O2refTANi = 2e-10;

double O3refSINi = 2e-11;
double O3refCOSi = 2e-10;
double O3refTANi = 2e-10;

double refSIN = 1;
double refCOS = 1;
double refTAN = 1;

void optimization_mode()
{
    if (numtype == 0)
    {
        if(optimization == 0)
        {
            refSIN = O0refSIN;
            refCOS = O0refCOS;
            refTAN = O0refTAN;
        } else if (optimization == 1)
        {
            refSIN = O1refSIN;
            refCOS = O1refCOS;
            refTAN = O1refTAN;
        }
        else if (optimization == 2)
        {
            refSIN = O2refSIN;
            refCOS = O2refCOS;
            refTAN = O2refTAN;
        }
        else if (optimization == 3)
        {
            refSIN = O3refSIN;
            refCOS = O3refCOS;
            refTAN = O3refTAN;
        }
    } else if (numtype == 1)
    {
        if(optimization == 0)
        {
            refSIN = O0refSINf;
            refCOS = O0refCOSf;
            refTAN = O0refTANf;
        } else if (optimization == 1)
        {
            refSIN = O1refSINf;
            refCOS = O1refCOSf;
            refTAN = O1refTANf;
        }
        else if (optimization == 2)
        {
            refSIN = O2refSINf;
            refCOS = O2refCOSf;
            refTAN = O2refTANf;
        }
        else if (optimization == 3)
        {
            refSIN = O3refSINf;
            refCOS = O3refCOSf;
            refTAN = O3refTANf;
        }
    } else if (numtype == 2)
    {
        if(optimization == 0)
        {
            refSIN = O0refSINi;
            refCOS = O0refCOSi;
            refTAN = O0refTANi;
        } else if (optimization == 1)
        {
            refSIN = O1refSINi;
            refCOS = O1refCOSi;
            refTAN = O1refTANi;
        }
        else if (optimization == 2)
        {
            refSIN = O2refSINi;
            refCOS = O2refCOSi;
            refTAN = O2refTANi;
        }
        else if (optimization == 3)
        {
            refSIN = O3refSINi;
            refCOS = O3refCOSi;
            refTAN = O3refTANi;
        }
    }
}

int empty_func()
{
    return 0;
}

double find_min(double* ar)
{
    double min = -1;
    for(int i = 0; i < 1000; i++)
    {
        if (min < ar[i])
            min = ar[i];
    }
    return min;
}

double func_sin(int amount) {
    type num;
    num = static_cast <type> (rand()) / static_cast <type> (RAND_MAX);
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        sin(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    //     start = std::clock();
    // for (int i = 0; i < amount; i++)
    // {
    //     empty_func();
    // }
    // end = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    // duration = duration - end;
    return duration;
}

double func_cos(int amount) {
    type num;
    num = static_cast <type> (rand()) / static_cast <type> (RAND_MAX);
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        cos(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    // start = std::clock();
    // for (int i = 0; i < amount; i++)
    // {
    //     empty_func();
    // }
    // end = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    // duration = duration - end;
    return duration;
}

double func_tan(int amount) {
    type num;
    //num = rand() % 11;
    num = static_cast <type> (rand()) / static_cast <type> (RAND_MAX);
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        tan(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    //     start = std::clock();
    // for (int i = 0; i < amount; i++)
    // {
    //     empty_func();
    // }
    // end = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    // duration = duration - end;
    return duration;
}

int main(int argc, char* argv[]) {
    optimization_mode();
    int n_cos, n_sin, n_tan;
    //double ar_sin[1001], ar_cos[1001], ar_tan[1001];
    srand(time(0));
    if (argc < 2)
        n_cos = n_sin = n_tan = N;
    else {
        n_cos = atoi(argv[1]);
        n_sin = atoi(argv[2]);
        n_tan = atoi(argv[3]);
    }


    double time_sin = func_sin(n_sin);
    double time_cos = func_cos(n_cos);
    double time_tan = func_tan(n_tan);

    std::cout << "sin: " << time_sin << std::endl;
    std::cout << "cos: " << time_cos << std::endl;
    std::cout << "tan: " << time_tan << std::endl;

    double AE_sin = abs(time_sin/n_sin - refSIN);
    double AE_cos = abs(time_cos/n_cos - refCOS);
    double AE_tan = abs(time_tan/n_tan - refTAN);

    std::cout << "Absolute error sin: " << AE_sin << "\n";
    std::cout << "Absolute error cos: " << AE_cos << "\n";
    std::cout << "Absolute error tan: " << AE_tan << "\n";

    std::cout << "Relative error sin: " << (AE_sin/refSIN)*100 << "%\n";
    std::cout << "Relative error cos: " << (AE_cos/refCOS)*100 << "%\n";
    std::cout << "Relative error tan: " << (AE_tan/refTAN)*100 << "%\n";


    // D = (SUM (Ri - Rref)^2)/n

    double D_sin = 0, D_cos = 0, D_tan = 0;
    for (int i = 0; i < n_sin; i++)
    {
        D_sin += pow((func_sin(1) - refSIN), 2);
    }
    D_sin = D_sin/n_sin;

    for (int i = 0; i < n_cos; i++)
    {
        D_cos += pow((func_cos(1) - refCOS), 2);
    }
    D_cos = D_cos/n_cos;

    for (int i = 0; i < n_tan; i++)
    {
        D_tan += pow((func_tan(1) - refTAN), 2);
    }
    D_tan = D_tan/n_tan;

    std::cout << "D sin: " << D_sin << "\n";
    std::cout << "D cos: " << D_cos << "\n";
    std::cout << "D tan: " << D_tan << "\n";

    std::cout << "SD sin: " << sqrt(D_sin) << "\n";
    std::cout << "SD cos: " << sqrt(D_cos) << "\n";
    std::cout << "SD tan: " << sqrt(D_tan) << "\n";

    double perf_sin = 0, perf_cos = 0, perf_tan = 0;
    double w = 0;
    for (int i = 0; i < n_sin; i++)
    {
        w += 1/(1/func_sin(1));
    }
    perf_sin = 1/w;

    for (int i = 0; i < n_cos; i++)
    {
        w += 1/(1/func_cos(1));
    }
    perf_cos = 1/w;

    for (int i = 0; i < n_tan; i++)
    {
        w += 1/(1/func_tan(1));
    }
    perf_tan = 1/w;

    std::ofstream file;
    file.open("data.csv", std::ios_base::app);
    //file << "PModel,Task,OpType,Opt,InsCount,Timer,LNum,AvTIme,AbsErr,RelErr,TaskPerf\n";
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,sin," << typeid(type).name() << ",O" << optimization << ",100000,std::clock()," << time_sin << ",1," << time_sin/n_sin << "," << AE_sin << "," << (AE_sin/refSIN)*100 << "," << perf_sin << "\n";
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,cos," << typeid(type).name() << ",O" << optimization << ",100000,std::clock()," << time_cos << ",1," << time_cos/n_cos << "," << AE_cos << "," << (AE_cos/refCOS)*100 << "," << perf_cos << "\n";
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,tan," << typeid(type).name() << ",O" << optimization << ",100000,std::clock()," << time_tan << ",1," << time_tan/n_tan << "," << AE_tan << "," << (AE_tan/refTAN)*100 << "," << perf_tan << "\n";

   // ПОИСК ЭТАЛОННОГО ВРЕМЕНИ ВЫПОЛНЕНИЯ
    
    
    // for (int i = 0; i < 1000; i++)
    // {
    //     ar_sin[i] = func_sin(n_sin);
    //     ar_cos[i] = func_cos(n_cos);
    //     ar_tan[i] = func_tan(n_tan);
    // }
    // double min_sin = find_min(ar_sin);
    // double min_cos = find_min(ar_cos);
    // double min_tan = find_min(ar_tan);

    // std::cout << "ref sin: " << min_sin/n_sin << "\n";
    // std::cout << "ref cos: " << min_cos/n_cos << "\n";
    // std::cout << "ref tan: " << min_tan/n_tan << "\n";


    return 0;
}