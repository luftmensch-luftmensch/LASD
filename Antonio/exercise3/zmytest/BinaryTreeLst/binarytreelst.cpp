#include "../../container/container.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../vector/vector.hpp"

#include "BinaryTreeLstInt/binarytreelstint.hpp"
#include "BinaryTreeLstFloat/binarytreelstfloat.hpp"
#include "BinaryTreeLstString/binarytreelststring.hpp"
#include "binarytreelst.hpp"

#include "../container/container.hpp"
#include "../test.hpp"


#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>




void BinaryTreeLst(){
    char scelta;
    std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
    std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
    std::cin >>scelta;

    switch(scelta){
        case '1':
          std::cout << "\033[2J\033[1;1H";
          BinaryTreeLstInt();
          break;

        case '2':
          std::cout << "\033[2J\033[1;1H";
          BinaryTreeLstFloat();
          break;
        case '3':
          std::cout << "\033[2J\033[1;1H";
          BinaryTreeLstString();
          break;
        case 'q':
            std::cout << "\033[2J\033[1;1H";
            mytest();
            break;

        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
          BinaryTreeLst();
    }

}
