#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

ofstream grimLog("resurrection.log", ios::app);

void chant(const string& message) {
    cout << "[NECROMANCER] " << message << endl;
    grimLog << "[NECROMANCER] " << message << endl;
}


vector<string> graveyard = {
    "Th_s is a m_ss_ng t_xt f_le.",
    "D_ta f_agment rec_ver",
    "__come to the da__ side.",
    "He_lo worl_! Th__ is los_",
    "F_les d_let_d... but s_ill bre__hing."
};


vector<string> incantations = {
    "This is a missing text file.",
    "Data fragment recover",
    "Welcome to the dark side.",
    "Hello world! This is lost",
    "Files deleted... but still breathing."
};


string resurrect(const string& corrupted) {
    for (const string& original : incantations) {
        int match = 0;
        for (size_t i = 0; i < min(corrupted.size(), original.size()); ++i) {
            if (corrupted[i] == original[i])
                ++match;
        }
        float confidence = (float)match / original.size();
        if (confidence > 0.5f) {
            chant("A lost soul resonates... Reconstruction possible.");
            return original;
        }
    }
    chant("No echo found. Fragment lost to the void.");
    return "<irretrievable>";
}

void beginResurrection() {
    chant("The ritual begins... Calling the forgotten fragments...");

    for (const string& fragment : graveyard) {
        chant("Reading fragment: \"" + fragment + "\"");
        string revived = resurrect(fragment);

        if (revived != "<irretrievable>") {
            chant("Reconstructed: \"" + revived + "\"");
        } else {
            chant("The silence remains...");
        }

        chant("---------");
    }

    chant("The ritual ends. Some returned. Some remained buried.");
}

int main() {
    chant("Digital Necromancer awakens...");
    beginResurrection();
    chant("Closing the tomb...");
    grimLog.close();
    return 0;
}
