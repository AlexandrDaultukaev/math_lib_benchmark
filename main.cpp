#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>

std::clock_t start;
double duration;
int N = 1000000;
double refSIN = 4.25e-08;
double refCOS = 3.818e-08;
double refTAN = 1.4694e-07;

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
    int num;
    num = rand() % 11;
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        sin(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    return duration;
}

double func_cos(int amount) {
    int num;
    num = rand() % 11;
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        cos(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    return duration;
}

double func_tan(int amount) {
    int num;
    num = rand() % 11;
    start = std::clock();
    for (int i = 0; i < amount; i++)
    {
        tan(num);
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    return duration;
}

void func_s(int num)
{
    sin(num);
}

int main(int argc, char* argv[]) {
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



    double AE_sin = abs(refSIN - time_sin/n_sin);
    double AE_cos = abs(refCOS - time_cos/n_cos);
    double AE_tan = abs(refTAN - time_tan/n_tan);

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
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,sin,double,O2,100000,std::clock()," << time_sin << "1," << time_sin/n_sin << "," << AE_sin << "," << (AE_sin/refSIN)*100 << "," << perf_sin << "\n";
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,cos,double,O2,100000,std::clock()," << time_cos << "1," << time_cos/n_cos << "," << AE_cos << "," << (AE_cos/refCOS)*100 << "," << perf_cos << "\n";
    file << "AMD_FX(tm)-4300_Quad-Core_Processor,tan,double,O2,100000,std::clock()," << time_tan << "1," << time_tan/n_tan << "," << AE_tan << "," << (AE_tan/refTAN)*100 << "," << perf_tan << "\n";

    // ПОИСК ЭТАЛОННОГО ВРЕМЕНИ ВЫПОЛНЕНИЯ
    //
    //
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