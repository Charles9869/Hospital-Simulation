// Fichier: DistributeurDeRang.hpp //
// Charles Bertrand et Jérémie Lacroix //
// Date de création: 23 octobre 2018 //

#ifndef DistributeurDeRang_hpp
#define DistributeurDeRang_hpp

#include <stdio.h>

class DistributeurDeRang
{
public:
    
    // Constructeur //
    DistributeurDeRang() {mRang++; }
    
    // Accesseurs //
    int GetRang() const { return mRang; }
private:
	static int mRang;
};


#endif 
