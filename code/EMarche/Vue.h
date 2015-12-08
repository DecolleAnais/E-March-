#ifndef VUE_H
#define VUE_H

class Vue {

public:
    virtual ~Vue() {};

    virtual void update() = 0;

};

#endif // VUE_H
