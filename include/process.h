#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
    public:
        Process(int p);
        int Pid();
        std::string User();
        std::string Command();
        float Cpu();
        float Ram();
        std::string RamStr();
        long int UpTime();
        bool operator<(Process const& a) const;

    private:
        int pid_{0};
        std::string user_{};
        std::string command_{};
        float cpu_{};
        float ram_{};
        long int uptime_{};
};

#endif