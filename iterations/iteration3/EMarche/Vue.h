#ifndef VUE_H
#define VUE_H

//!
//! \brief The Vue class - Permet la mise à jour des vues
//!
class Vue {

public:
    virtual ~Vue() {};
    //!
    //! \brief update - Mise à jour
    //!
    virtual void update() = 0;

};

#endif // VUE_H
