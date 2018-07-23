#pragma once

class Resource
{
    int i = 1;
    static int objectcount;

public:
    Resource(){objectcount++;}
    // copy constructor
    Resource(const Resource& r){
        i = r.i;
        objectcount++;
    }
    // copy operator
    Resource& operator=(const Resource& r){
        i = r.i;
        return *this;
    }
    ~Resource(){objectcount--;}

    void setValue(int ii){ i = ii;}
    int getValue() const {return this->i; }
    static int getCount() {return objectcount; }
};
int Resource::objectcount = 0;
