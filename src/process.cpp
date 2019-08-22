#include <string>
#include <iomanip>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int p) : pid_(p) {
    if (pid_) {
        cpu_ = LinuxParser::CpuUtilization(pid_);
        command_ = LinuxParser::Command(pid_);
        ram_ = LinuxParser::Ram(pid_);
        user_ = LinuxParser::User(pid_);
        uptime_ = LinuxParser::UpTime(pid_);
    }
};

int Process::Pid() {
    return pid_;
}

float Process::Cpu() {
    return cpu_;
}

std::string Process::Command() {
    return command_;
}

float Process::Ram() {
    return ram_;
}

std::string Process::RamStr() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << ram_;
    return stream.str();
}

string Process::User() {
    return user_;
}

long int Process::UpTime() {
    return uptime_;
}

bool Process::operator<(Process const& a) const {
    return LinuxParser::CpuUtilization(pid_) < LinuxParser::CpuUtilization(a.pid_);
}