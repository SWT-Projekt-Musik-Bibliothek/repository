#include <string>
class Song;
class Album{
    public:
    std::string albumname;
    std::string kuenstlername;
    Song *songliste;
    int erscheinungsjahr;
    int songanzahl;
    int albumlaenge;
};