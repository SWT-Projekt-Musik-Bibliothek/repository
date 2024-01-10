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
    std::string to_string_csv();
    std::string to_string_ausgabe();
};