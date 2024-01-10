#include "album.h"
class Song{
    public:
    std::string songtitel;
    Album album;
    std::string kuenstlername;
    int erscheinungsjahr;
    int songlaenge;
    std::string genre;
    std::string to_string_csv();
    std::string to_string_ausgabe();
};