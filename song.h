#include <string>
#include "album.h"

class Song:public Musik{
    public:
    std::string songtitel;
    Album album;
    std::string kuenstlername;
    int erscheinungsjahr;
    int songlaenge;
    std::string genre;
    std::string to_string(){
        return songtitel+";"+kuenstlername+";"+std::to_string(erscheinungsjahr)+";"+std::to_string(songlaenge)+";"+genre;
    }
};