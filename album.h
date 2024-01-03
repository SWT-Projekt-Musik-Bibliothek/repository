#include <string>
class Musik{};
class Song: public Musik{};
class Album: public Musik{
    public:
    std::string albumname;
    std::string kuenstlername;
    Song *songliste;
    int erscheinungsjahr;
    int songanzahl;
    int albumlaenge;
    std::string to_string(){
        return albumname+";"+kuenstlername+";"+std::to_string(erscheinungsjahr)+";"+std::to_string(songanzahl)+";"+std::to_string(albumlaenge);
    }
};