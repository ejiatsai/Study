#include<iostream>

class Device {
public:
    Device(int s,int a):
     screen_size(s), 
     battery(a){}
     int getBattery(){return battery;}
protected:
    int screen_size;
    int battery;
};

class Band{
    public:
        Band(int b):
            band(b){}
    protected:
        int band;
};

class Phone : public Device,public Band{
public:
    Phone(int s,int a,int b):
     Device(s,a), Band(b){}
};

class Os{
    public:
        Os(std::string o):
            os(o){}
    protected:
        std::string os;
};

class PDA : public Device,public Os{
public:
    PDA(int s,int a,std::string  o):
     Device(s,a), Os(o){}
};

class SmartPhone :
    public Device,
    public Band,
    public Os{
public:
    SmartPhone(int s,int a,int b,
               std::string  o):
     Device(s,a), Band(b),Os(o){}
};

int main(){
    SmartPhone p = SmartPhone(1,2,3,"iOS");
    std::cout << p.getBattery() << std::endl;
    return 0;
}