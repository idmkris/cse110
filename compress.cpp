#include<iostream>
#include<fstream>
#include<bitset>
#include<vector>
#include<bits/stdc++.h>
#include<list>
#include"Helper.hpp"
#include"HCTree.hpp"
using namespace std;

const int SIZE = 256;

int main(int argc, char* argv[]){

    //int headerlen = 0;
    FancyInputStream* in = new FancyInputStream(argv[1]);
    FancyOutputStream* out = new FancyOutputStream(argv[2]);
    int fsize = in->filesize();
    if (fsize != 0) {
    out->write_int(fsize);
    }
    if(!in->good()) {
        cout << argv[1] << " is an invalid file" <<endl;
    }
    else {
        vector<int> freqs = vector<int>(SIZE,0);

        int size = in->filesize();
        if (size == 0) {
            return 0;
        }
        for (int i = 0; i < size; ++i) {
            unsigned char sbl = in->read_byte();
            freqs[sbl]++;
        }
        for (unsigned long int i = 0; i < freqs.size(); i++) {
        out->write_int(freqs[i]);
        }
        HCTree* hct = new HCTree();
        hct->build(freqs);
        in->reset();
        for (int i = 0; i < size; ++i) {
            unsigned char sbl = in->read_byte();
            hct->encode(sbl, *out);
        }
        delete hct;
    }
    delete in;
    delete out;
    return 0;
}
